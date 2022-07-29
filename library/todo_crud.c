/**
 * @file todo_crud.c
 * @brief to-do list CRUD using the library functions and methods.
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 17/07/2022
 * Last updated: 17/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/lib.h"
#include <time.h>

#define COMPLETED true
#define NOT_COMPLETED false
#define COMPLETE_DATEFORMAT "dd/MM/yyyy h:m:s"
#define PARTIAL_DATEFORMAT "dd/MM/yyyy"

const time_t monthInSeconds = 2628288; // How many seconds are in a month - (avg)
int maxTodos = 256;
int todos = 0;
int lastID = 0;

typedef struct datetime {
    int year; /*  any */
    int mon;  /* 1-12 */
    int day;  /* 1-31 */
    int hour; /* 0-23 */
    int min;  /* 0-59 */
    int sec;  /* 0-59 */
} datetime;

/* op = 1 "dd/MM/yyyy h:m:s"; ops = 2 "dd/MM/yyyy" */
datetime *setsDate(int op, char *data) {
    datetime *new = (datetime *) malloc(sizeof(datetime));
    if(new == NULL) {
        fputs("ERROR: Not enough memory.", stderr);
    } else if(op == 1){
        sscanf(data, "%d/%d/%d %d:%d:%d", &new->day, &new->mon, &new->year,
               &new->hour, &new->min, &new->sec);
    } else if(op == 2){
        sscanf(data, "%d/%d/%d", &new->day, &new->mon, &new->year);
        new->hour = new->min = new->sec = 0;
    } else {
        fputs("ERROR: Invalid option.", stderr);
    }
    return new;
}

datetime *settDate(time_t *t) {
    datetime *new = (datetime *) malloc(sizeof(datetime));
    struct tm *tmp = localtime(t);

    new->year = tmp->tm_year + 1900;
    new->mon = tmp->tm_mon + 1;
    new->day = tmp->tm_mday;
    new->hour = tmp->tm_hour;
    new->min = tmp->tm_min;
    new->sec = tmp->tm_sec;

    return new;
}

typedef struct todoCell {
    int id;
    char *todoText;
    datetime *pubDate, *expectedCompletionDate, *completionDate, *lastUpdatedDate;
    bool completed;
    double priorityValue;
} todoCell;

todoCell *buildTodo(int op, char *todoText, ...)
{
    todoCell *new = (todoCell *)malloc(sizeof(todoCell));
    new->id = (todos++, ++lastID);
    new->pubDate = (datetime *)malloc(sizeof(datetime));
    new->expectedCompletionDate = (datetime *)malloc(sizeof(datetime));
    new->completionDate = (datetime *)malloc(sizeof(datetime));
    new->lastUpdatedDate = (datetime *) malloc(sizeof(datetime));

    new->todoText = l_snnewStr();
    strcpy(new->todoText, todoText);

    new->completed = NOT_COMPLETED;
    new->completionDate = NULL;
    new->lastUpdatedDate = NULL;

    time_t t = time(NULL);
    new->pubDate = settDate(&t);

    if(op == 1) {
        time_t expectedT = t + monthInSeconds;
        new->expectedCompletionDate = settDate(&expectedT);

        new->priorityValue = 1.0;
    }else if(op == 2) {
        va_list ap;
        va_start(ap, todoText);

        new->expectedCompletionDate = va_arg(ap, datetime *);

        new->priorityValue = 1.0;
    }else if(op == 3) {
        va_list ap;
        va_start(ap, todoText);

        new->expectedCompletionDate = va_arg(ap, datetime *);

        double pValue = va_arg(ap, double);
        new->priorityValue = pValue;
    }else if(op == 4) {
        va_list ap;
        va_start(ap, todoText);

        time_t expectedT = t + monthInSeconds;
        new->expectedCompletionDate = settDate(&expectedT);

        double pValue = va_arg(ap, double);
        new->priorityValue = pValue;
    }else {
        fputs("ERROR: Option value must be between 1 and 4.", stderr);
    }
    return new;
}

bool isSmaller(datetime *time1, datetime *time2) {
    bool result;

    if(time1->year > time2->year) result = false;
    else if(time1->year < time2->year) result = true;
    else if(time1->mon > time2->mon) result = false;
    else if(time1->mon < time2->mon) result = true;
    else if(time1->day > time2->day) result = false;
    else if(time1->day < time2->day) result = true;
    else if(time1->hour > time2->hour) result = false;
    else if(time1->hour < time2->hour) result = true;
    else if(time1->min > time2->min) result = false;
    else if(time1->min < time2->min) result = true;
    else if(time1->sec > time2->sec) result = false;
    else if(time1->sec < time2->sec) result = true;
    else result = false;

    return result;
}

bool completedInTime(todoCell *todo) {
    bool result = false;
    if(todo->completed) {
        result = !isSmaller(todo->expectedCompletionDate, todo->completionDate);
    }else {
        fputs("To-do yet to be completed.", stderr);
    }
    return result;
}

void setCompleted(todoCell *todo) {
    if(todo->completed) {
        fputs("ERROR: To-do is already set as completed.", stderr);
    } else {
        todo->completed = COMPLETED;
        time_t t = time(NULL);
        todo->completionDate = settDate(&t);
    }
}

void updateTodo(int op, todoCell *todo, ...) {
    if(todo->completed) {
        fputs("ERROR: Completed to-do cells cannot be updated.", stderr);
    } else if(0 < op && op < 4){
        va_list ap;
        va_start(ap, todo);

        time_t t = time(NULL);
        todo->lastUpdatedDate = settDate(&t);
        if(op == 1) {
            char *text = va_arg(ap, char *);
            strcpy(todo->todoText, text);
        } else if(op == 2) {
            char *text = va_arg(ap, char *);
            double pValue = va_arg(ap, double);
            strcpy(todo->todoText, text);
            todo->priorityValue = pValue;
        } else if(op == 3) {
            double pValue = va_arg(ap, double);
            todo->priorityValue = pValue;
        }
        va_end(ap);
    } else {
        fputs("ERROR: Option value must be between 1 and 3.", stderr);
    }
}

void printTodo(todoCell *todo) {
    char *output = l_snnewStr();
    if(output == NULL) {
        fputs("ERROR: Not enough memory.", stderr);
    }else {
        char *format = l_snnewStr();
        if(todo->lastUpdatedDate == NULL) {
            strcpy(format, "Created at %02d-%02d-%04d - ID: %i\nTo-do text: %s;\n"
                           "Priority (1: low - 10: high): %g\n");
        } else {
            strcpy(format, "Last updated at %02d-%02d-%04d - ID: %i\nTo-do text: %s;\n"
                           "Priority (1: low - 10: high): %g\n");
        }

        if(todo->completed) {
            if(completedInTime(todo)) {
                strcat(format, "Completed, IN TIME, at %02d-%02d-%04d.\n");
                sprintf(output, format,
                                todo->pubDate->day, todo->pubDate->mon, todo->pubDate->year,
                                todo->id, todo->todoText, todo->priorityValue, todo->completionDate->day,
                                todo->completionDate->mon, todo->completionDate->year);
            }else {
                strcat(format, "Not completed in time, but at %02d-%02d-%04d."
                               "Expected time was %02d-%02d-%04d.\n");
                sprintf(output, format,
                                todo->pubDate->day, todo->pubDate->mon, todo->pubDate->year,
                                todo->id, todo->todoText, todo->priorityValue, todo->completionDate->day,
                                todo->completionDate->mon, todo->completionDate->year,
                                todo->expectedCompletionDate->day, todo->expectedCompletionDate->mon,
                                todo->expectedCompletionDate->year);
            }
        }else {
            time_t t = time(NULL);
            datetime *now = settDate(&t);
            if(isSmaller(todo->expectedCompletionDate, now)) {
                strcat(format, "Cannot be completed in time. The deadline was %02d-%02d-%04d and "
                               "today is %02d-%02d-%04d.\n");
                sprintf(output, format,
                        todo->pubDate->day, todo->pubDate->mon, todo->pubDate->year,
                        todo->id, todo->todoText, todo->priorityValue, todo->expectedCompletionDate->day,
                        todo->expectedCompletionDate->mon, todo->expectedCompletionDate->year,
                        now->day, now->mon, now->year);
            } else {
                strcat(format, "Still can be completed in time. The deadline is %02d-%02d-%04d.\n");
                sprintf(output, format,
                        todo->pubDate->day, todo->pubDate->mon, todo->pubDate->year,
                        todo->id, todo->todoText, todo->priorityValue, todo->expectedCompletionDate->day,
                        todo->expectedCompletionDate->mon, todo->expectedCompletionDate->year);
            }
        }
        printf("%s", output);
    }
}
void printTodoList(todoCell **todoList) {
    for(register int i = 0; i < todos; i++) {
        printf("---------------- To-do number %i ----------------\n", (i+1));
        printTodo(todoList[i]);
    }
}

void listTodoList(todoCell **todoList) {
    printf("%4s - todoText", "ID");
    for(register int i = 0; i < todos; i++) {
        printf("%i - %s", todoList[0]->id, todoList[0]->todoText);
    }
}

void printDateTime(datetime *dt)
{
    printf("%02d-%02d-%02d %02d:%02d:%02d\n", dt->day,
           dt->mon + 1, dt->year + 1900,
           dt->hour, dt->min, dt->sec);
}

void printDate(datetime *dt)
{
    printf("%02d-%02d-%02d\n", dt->day, dt->mon + 1, dt->year + 1900);
}

void removeCompleted(todoCell **todoList) {
    int n = 0;
    for(register int i = 0; i < todos - 1; i++) {
        if(todoList[i]->completed) {
            for(register int j = i; j < todos - 1; j++) {
                todoList[j] = todoList[j + 1];
            }
            n++;
        }
    }
    if(todoList[todos-1]->completed) todos--;
    todos -= n;
}

int main(void)
{
    maxlen *= 4;
    todoCell **todoList = (todoCell **)malloc(maxTodos * sizeof(todoCell *));

    /* time_t t = time(NULL);
    datetime * dt1 = settDate(&t);
    datetime * dt2 = setsDate(1, "05/10/2021 22:54:12");
    todoList[0] = buildTodo(2, "Do laundry.", setsDate(2, "20/10/2022 10:00:00"));
    printTodo(todoList[0]);
    printTodoList(todoList);
    printf("D1\n%d/%d/%d %d:%d:%d\n\n", dt1->day, dt1->mon, dt1->year, dt1->hour, dt1->min, dt1->sec);
    printf("D2\n%d/%d/%d %d:%d:%d\n\n", dt2->day, dt2->mon, dt2->year, dt2->hour, dt2->min, dt2->sec);
    printTodo(todoList[0]); */
    char *instr = l_snnewStr();
    int op;
    puts("------------ To-do APP using the \"lib\" library ------------\n\n"
           "The to-do node has:\nText;\n Four different dates (dd/mm/yyyy h:m:s), being: "
           "Publication Date, Expected Completion Date, Completion Date and Last Updated Date.\n"
           "Priority level (1.0-10.0), 10.0 being the biggest priority.\n\n"
           "The to-do \"constructor\" will define default values if you only want to "
           "define the \"text\", being:\n Default Expected Completion Date is 1 month after "
           "the Publication Date;\nLast Updated and Completion Date by default is always NULL;\n"
           "Priority is, by default, 1.");
    do{
        puts("0 - Finish app;\n"
             "1 - Add to-do;\n"
             "2 - Update to-do(s);\n"
             "3 - Remove to-do(s);\n"
             "4 - List to-do(s).");
        op = l_fsnreadInt(stdin);
        switch (op) {
            case 0:
                break;
            case 1:
            {
                do{
                    puts("0 - Cancel operation;\n"
                         "1 - Add only text;\n"
                         "2 - Add text and expected completion date;\n"
                         "3 - Add text, expected completion date and priority value;\n"
                         "4 - Add text and priority value.");
                    op = l_fsnreadInt(stdin);
                    switch (op) {
                        case 0:
                            break;
                        case 1:
                        {
                            printf("Text: ");
                            l_fsreadLine(instr, stdin);
                            todoList[todos] = buildTodo(1, instr);
                            break;
                        }
                        case 2:
                        {
                            char *tmp;
                            printf("Text: ");
                            l_fsreadLine(instr, stdin);
                            tmp = l_snnewStr();
                            puts("Which date format for expected completion date?\n"
                                 "1 - dd/MM/yyyy h:m:s;\n"
                                 "2 - dd/MM/yyyy.");
                            do{
                                op = l_fsnreadInt(stdin);
                            }while(op < 1 || op > 2);
                            printf("Date: ");
                            l_fsreadLine(tmp, stdin);
                            todoList[todos] = buildTodo(2, instr, setsDate(op, tmp));
                            free(tmp);
                            break;
                        }
                        case 3:
                        {
                            char *tmp;
                            double pValue;
                            printf("Text: ");
                            l_fsreadLine(instr, stdin);
                            tmp = l_snnewStr();
                            puts("Which date format for expected completion date?\n"
                                 "1 - dd/MM/yyyy h:m:s;\n"
                                 "2 - dd/MM/yyyy.");
                            do{
                                op = l_fsnreadInt(stdin);
                            }while(op < 1 || op > 2);
                            printf("Date: ");
                            l_fsreadLine(tmp, stdin);
                            do{
                                printf("Priority value (1-10): ");
                                pValue = l_fsnreadDouble(stdin);
                            }while(pValue < 1.0 || pValue > 10.0);
                            todoList[todos] = buildTodo(3, instr, setsDate(op, tmp), pValue);
                            free(tmp);
                            break;
                        }
                        case 4:
                        {
                            double pValue;
                            printf("Text: ");
                            l_fsreadLine(instr, stdin);
                            do{
                                printf("Priority value (1-10): ");
                                pValue = l_fsnreadDouble(stdin);
                            }while(pValue < 1.0 || pValue > 10.0);
                            todoList[todos] = buildTodo(4, instr, pValue);
                            break;
                        }
                        default:
                            puts("Invalid input.");
                    }
                }while(op < 0 || op > 4);
                break;
            }
            case 2:
            {
                puts("0 - Cancel operation;\n"
                     "1 - Update by ID;\n");
                do{
                    op = l_fsnreadInt(stdin);

                }while(op < 0 || op > 1);

                break;
            }
            default:
                puts("Invalid input.");
        }
    }while(op != 0);
    printTodoList(todoList);
    /* op = l_fsnreadInt(stdin);
    switch (op) {
        case 0:
            break;
        case 1:
        {
            printTodo(todoList[todos-1]);
            break;
        }
        default:
            printf("ERROR\n");
    } */
    return EXIT_SUCCESS;
}
