EXECUTABLE = exec
MAIN_FILE_NAME = tests
SRCS = bin/$(MAIN_FILE_NAME).o bin/l_globals.o bin/l_nnewStr.o bin/l_snnewStr.o bin/l_newStr.o \
			bin/l_rbreak.o bin/l_freadLine.o bin/l_readLine.o bin/l_fsreadLine.o bin/l_fnreadStr.o \
			bin/l_fsnreadStr.o bin/l_nreadStr.o bin/l_fnreadDouble.o bin/l_fsnreadDouble.o bin/l_nreadDouble.o \
			bin/l_freadDouble.o bin/l_readDouble.o bin/l_fnreadFloat.o bin/l_fsnreadFloat.o bin/l_nreadFloat.o \
			bin/l_freadFloat.o bin/l_readFloat.o bin/l_fnreadInt.o bin/l_fsnreadInt.o bin/l_nreadInt.o \
			bin/l_freadInt.o bin/l_readInt.o bin/l_fnreadBool.o bin/l_nreadBool.o bin/l_fsnreadBool.o \
			bin/l_readBool.o bin/l_fnreadnStr.o bin/l_fsnreadnStr.o bin/l_nreadnStr.o bin/l_freadnStr.o \
			bin/l_fnreadnInt.o bin/l_fsnreadnInt.o bin/l_nreadnInt.o bin/l_freadnInt.o bin/l_pause.o \
			bin/l_formatPrint.o
CFLAGS = -c -W -Wall -pedantic
SRC_DIR = src/lib_src

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
		gcc -o $(EXECUTABLE) $(SRCS)

bin/$(MAIN_FILE_NAME).o: $(MAIN_FILE_NAME).c
		gcc -o bin/$(MAIN_FILE_NAME).o $(MAIN_FILE_NAME).c $(CFLAGS)

bin/l_globals.o: src
		gcc -o bin/l_globals.o $(SRC_DIR)/l_globals.c $(CFLAGS)

bin/l_nnewStr.o: src
		gcc -o bin/l_nnewStr.o $(SRC_DIR)/l_nnewStr.c $(CFLAGS)

bin/l_snnewStr.o: src
		gcc -o bin/l_snnewStr.o $(SRC_DIR)/l_snnewStr.c $(CFLAGS)

bin/l_newStr.o: src
		gcc -o bin/l_newStr.o $(SRC_DIR)/l_newStr.c $(CFLAGS)

bin/l_rbreak.o: src
		gcc -o bin/l_rbreak.o $(SRC_DIR)/l_rbreak.c $(CFLAGS)

bin/l_freadLine.o: src
		gcc -o bin/l_freadLine.o $(SRC_DIR)/l_freadLine.c $(CFLAGS)

bin/l_readLine.o: src
		gcc -o bin/l_readLine.o $(SRC_DIR)/l_readLine.c $(CFLAGS)

bin/l_fsreadLine.o: src
		gcc -o bin/l_fsreadLine.o $(SRC_DIR)/l_fsreadLine.c $(CFLAGS)

bin/l_fnreadStr.o: src
		gcc -o bin/l_fnreadStr.o $(SRC_DIR)/l_fnreadStr.c $(CFLAGS)

bin/l_fsnreadStr.o: src
		gcc -o bin/l_fsnreadStr.o $(SRC_DIR)/l_fsnreadStr.c $(CFLAGS)

bin/l_nreadStr.o: src
		gcc -o bin/l_nreadStr.o $(SRC_DIR)/l_nreadStr.c $(CFLAGS)

bin/l_fnreadDouble.o: src
		gcc -o bin/l_fnreadDouble.o $(SRC_DIR)/l_fnreadDouble.c $(CFLAGS)

bin/l_fsnreadDouble.o: src
		gcc -o bin/l_fsnreadDouble.o $(SRC_DIR)/l_fsnreadDouble.c $(CFLAGS)

bin/l_nreadDouble.o: src
		gcc -o bin/l_nreadDouble.o $(SRC_DIR)/l_nreadDouble.c $(CFLAGS)

bin/l_freadDouble.o: src
		gcc -o bin/l_freadDouble.o $(SRC_DIR)/l_freadDouble.c $(CFLAGS)

bin/l_readDouble.o: src
		gcc -o bin/l_readDouble.o $(SRC_DIR)/l_readDouble.c $(CFLAGS)

bin/l_fnreadFloat.o: src
		gcc -o bin/l_fnreadFloat.o $(SRC_DIR)/l_fnreadFloat.c $(CFLAGS)

bin/l_fsnreadFloat.o: src
		gcc -o bin/l_fsnreadFloat.o $(SRC_DIR)/l_fsnreadFloat.c $(CFLAGS)

bin/l_nreadFloat.o: src
		gcc -o bin/l_nreadFloat.o $(SRC_DIR)/l_nreadFloat.c $(CFLAGS)

bin/l_freadFloat.o: src
		gcc -o bin/l_freadFloat.o $(SRC_DIR)/l_freadFloat.c $(CFLAGS)

bin/l_readFloat.o: src
		gcc -o bin/l_readFloat.o $(SRC_DIR)/l_readFloat.c $(CFLAGS)

bin/l_fnreadInt.o: src
		gcc -o bin/l_fnreadInt.o $(SRC_DIR)/l_fnreadInt.c $(CFLAGS)

bin/l_fsnreadInt.o: src
		gcc -o bin/l_fsnreadInt.o $(SRC_DIR)/l_fsnreadInt.c $(CFLAGS)

bin/l_nreadInt.o: src
		gcc -o bin/l_nreadInt.o $(SRC_DIR)/l_nreadInt.c $(CFLAGS)

bin/l_freadInt.o: src
		gcc -o bin/l_freadInt.o $(SRC_DIR)/l_freadInt.c $(CFLAGS)

bin/l_readInt.o: src
		gcc -o bin/l_readInt.o $(SRC_DIR)/l_readInt.c $(CFLAGS)

bin/l_fnreadBool.o: src
		gcc -o bin/l_fnreadBool.o $(SRC_DIR)/l_fnreadBool.c $(CFLAGS)

bin/l_nreadBool.o: src
		gcc -o bin/l_nreadBool.o $(SRC_DIR)/l_nreadBool.c $(CFLAGS)

bin/l_fsnreadBool.o: src
		gcc -o bin/l_fsnreadBool.o $(SRC_DIR)/l_fsnreadBool.c $(CFLAGS)

bin/l_readBool.o: src
		gcc -o bin/l_readBool.o $(SRC_DIR)/l_readBool.c $(CFLAGS)

bin/l_fnreadnStr.o: src
		gcc -o bin/l_fnreadnStr.o $(SRC_DIR)/l_fnreadnStr.c $(CFLAGS)

bin/l_fsnreadnStr.o: src
		gcc -o bin/l_fsnreadnStr.o $(SRC_DIR)/l_fsnreadnStr.c $(CFLAGS)

bin/l_nreadnStr.o: src
		gcc -o bin/l_nreadnStr.o $(SRC_DIR)/l_nreadnStr.c $(CFLAGS)

bin/l_freadnStr.o: src
		gcc -o bin/l_freadnStr.o $(SRC_DIR)/l_freadnStr.c $(CFLAGS)

bin/l_fnreadnInt.o: src
		gcc -o bin/l_fnreadnInt.o $(SRC_DIR)/l_fnreadnInt.c $(CFLAGS)

bin/l_fsnreadnInt.o: src
		gcc -o bin/l_fsnreadnInt.o $(SRC_DIR)/l_fsnreadnInt.c $(CFLAGS)

bin/l_nreadnInt.o: src
		gcc -o bin/l_nreadnInt.o $(SRC_DIR)/l_nreadnInt.c $(CFLAGS)

bin/l_freadnInt.o: src
		gcc -o bin/l_freadnInt.o $(SRC_DIR)/l_freadnInt.c $(CFLAGS)

bin/l_pause.o: src
		gcc -o bin/l_pause.o $(SRC_DIR)/l_pause.c $(CFLAGS)

bin/l_formatPrint.o: src
		gcc -o bin/l_formatPrint.o $(SRC_DIR)/l_formatPrint.c $(CFLAGS)

clean:
		rm bin/*.o $(EXECUTABLE)
