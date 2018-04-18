#makefile - file name

CC = gcc
FILE_1 = prog1.c
FILE_2 = prog2.c 
OUT_EXE_1 = prog1out.o
OUT_EXE_2 = prog2out.o
OUT_EXE = OUT_EXE_1 OUT_EXE_2

build: file_1 file_2

file_1: $(FILE_1)
	$(CC) $(FILE_1) -o $(OUT_EXE_1)

file_2: $(FILE_2)
	$(CC) $(FILE_2) -o $(OUT_EXE_2)

clean: 
	rm -rf *o $(OUT_EXE)

rebuild: clean build 
