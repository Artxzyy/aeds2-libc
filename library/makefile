EXECUTABLE = exec
MAIN_FILE_NAME = tests
SRCS = bin/$(MAIN_FILE_NAME).o bin/l_globals.o bin/l_pause.o \
			bin/l_newStr.o bin/l_sNewStr.o \
			bin/l_rbreak.o bin/l_readLine.o bin/l_sReadLine.o \
			bin/l_readStr.o bin/l_sReadStr.o \
			bin/l_readDouble.o bin/l_sReadDouble.o \
			bin/l_readFloat.o bin/l_sReadFloat.o \
			bin/l_readInt.o bin/l_sReadInt.o \
			bin/l_readBool.o bin/l_sReadBool.o \
			bin/l_readNStr.o bin/l_sReadNStr.o \
			bin/l_readNInt.o bin/l_sReadNInt.o \
			bin/l_formatPrintVector.o bin/l_formatStrVector.o
CFLAGS = -c -W -Wall -pedantic
SRC_DIR = src/lib_src

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
		gcc -o $(EXECUTABLE) $(SRCS)

bin/$(MAIN_FILE_NAME).o: $(MAIN_FILE_NAME).c
		gcc -o bin/$(MAIN_FILE_NAME).o $(MAIN_FILE_NAME).c $(CFLAGS)

bin/l_globals.o: src
		gcc -o bin/l_globals.o $(SRC_DIR)/l_globals.c $(CFLAGS)

bin/l_newStr.o: src
		gcc -o bin/l_newStr.o $(SRC_DIR)/l_newStr.c $(CFLAGS)

bin/l_sNewStr.o: src
		gcc -o bin/l_sNewStr.o $(SRC_DIR)/l_sNewStr.c $(CFLAGS)

bin/l_rbreak.o: src
		gcc -o bin/l_rbreak.o $(SRC_DIR)/l_rbreak.c $(CFLAGS)

bin/l_readLine.o: src
		gcc -o bin/l_readLine.o $(SRC_DIR)/l_readLine.c $(CFLAGS)

bin/l_sReadLine.o: src
		gcc -o bin/l_sReadLine.o $(SRC_DIR)/l_sReadLine.c $(CFLAGS)

bin/l_readStr.o: src
		gcc -o bin/l_readStr.o $(SRC_DIR)/l_readStr.c $(CFLAGS)

bin/l_sReadStr.o: src
		gcc -o bin/l_sReadStr.o $(SRC_DIR)/l_sReadStr.c $(CFLAGS)

bin/l_readDouble.o: src
		gcc -o bin/l_readDouble.o $(SRC_DIR)/l_readDouble.c $(CFLAGS)

bin/l_sReadDouble.o: src
		gcc -o bin/l_sReadDouble.o $(SRC_DIR)/l_sReadDouble.c $(CFLAGS)

bin/l_readFloat.o: src
		gcc -o bin/l_readFloat.o $(SRC_DIR)/l_readFloat.c $(CFLAGS)

bin/l_sReadFloat.o: src
		gcc -o bin/l_sReadFloat.o $(SRC_DIR)/l_sReadFloat.c $(CFLAGS)

bin/l_readInt.o: src
		gcc -o bin/l_readInt.o $(SRC_DIR)/l_readInt.c $(CFLAGS)

bin/l_sReadInt.o: src
		gcc -o bin/l_sReadInt.o $(SRC_DIR)/l_sReadInt.c $(CFLAGS)

bin/l_readBool.o: src
		gcc -o bin/l_readBool.o $(SRC_DIR)/l_readBool.c $(CFLAGS)

bin/l_sReadBool.o: src
		gcc -o bin/l_sReadBool.o $(SRC_DIR)/l_sReadBool.c $(CFLAGS)

bin/l_readNStr.o: src
		gcc -o bin/l_readNStr.o $(SRC_DIR)/l_readNStr.c $(CFLAGS)

bin/l_sReadNStr.o: src
		gcc -o bin/l_sReadNStr.o $(SRC_DIR)/l_sReadNStr.c $(CFLAGS)

bin/l_readNInt.o: src
		gcc -o bin/l_readNInt.o $(SRC_DIR)/l_readNInt.c $(CFLAGS)

bin/l_sReadNInt.o: src
		gcc -o bin/l_sReadNInt.o $(SRC_DIR)/l_sReadNInt.c $(CFLAGS)

bin/l_pause.o: src
		gcc -o bin/l_pause.o $(SRC_DIR)/l_pause.c $(CFLAGS)

bin/l_formatPrintVector.o: src
		gcc -o bin/l_formatPrintVector.o $(SRC_DIR)/l_formatPrintVector.c $(CFLAGS)

bin/l_formatStrVector.o: src
		gcc -o bin/l_formatStrVector.o $(SRC_DIR)/l_formatStrVector.c $(CFLAGS)

clean:
		rm bin/*.o $(EXECUTABLE)
