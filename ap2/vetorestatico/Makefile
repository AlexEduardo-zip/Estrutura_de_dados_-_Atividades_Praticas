#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-01 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/vetop.o $(OBJ)/vet.o $(OBJ)/memlog.o
HDRS = $(INC)/vet.h $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -pg -Wall -c -I$(INC)
ANALISAMEM = ../analisamem/bin/analisamem

EXE = $(BIN)/vetop

all:  mem perf gprof

mem: $(EXE)
	$(EXE) -d 20 -s -p /tmp/somalog.out -l 
	rm -rf /tmp/somaest
	mkdir /tmp/somaest
	$(ANALISAMEM) -i /tmp/somalog.out -p /tmp/somaest/somaest
	$(EXE) -d 20 -i -p /tmp/internolog.out -l 
	rm -rf /tmp/internoest
	mkdir /tmp/internoest
	$(ANALISAMEM) -i /tmp/internolog.out -p /tmp/internoest/internoest
	$(EXE) -d 20 -n -p /tmp/normalog.out -l 
	rm -rf /tmp/normaest
	mkdir /tmp/normaest
	$(ANALISAMEM) -i /tmp/normalog.out -p /tmp/normaest/normaest

perf: $(EXE)
	$(EXE) -d 10000 -s -p /tmp/soma10K.out
	$(EXE) -d 10000 -i -p /tmp/interno10K.out
	$(EXE) -d 10000 -n -p /tmp/norma10K.out
	$(EXE) -d 20000 -s -p /tmp/soma20K.out
	$(EXE) -d 20000 -i -p /tmp/interno20K.out
	$(EXE) -d 20000 -n -p /tmp/norma20K.out
	$(EXE) -d 30000 -s -p /tmp/soma30K.out
	$(EXE) -d 30000 -i -p /tmp/interno30K.out
	$(EXE) -d 30000 -n -p /tmp/norma30K.out
	$(EXE) -d 40000 -s -p /tmp/soma40K.out
	$(EXE) -d 40000 -i -p /tmp/interno40K.out
	$(EXE) -d 40000 -n -p /tmp/norma40K.out
	$(EXE) -d 50000 -s -p /tmp/soma50K.out
	$(EXE) -d 50000 -i -p /tmp/interno50K.out
	$(EXE) -d 50000 -n -p /tmp/norma50K.out

gprof: $(BIN)/vetop
	$(EXE) -d 50000 -s -p /tmp/soma50Kgprof.out 
	gprof $(EXE) gmon.out > /tmp/soma50Kgprof.txt
	$(EXE) -d 50000 -i -p /tmp/interno50Kgprof.out 
	gprof $(EXE) gmon.out > /tmp/interno50Kgprof.txt
	$(EXE) -d 50000 -n -p /tmp/norma50Kgprof.out 
	gprof $(EXE) gmon.out > /tmp/norma50Kgprof.txt
	

$(BIN)/vetop: $(OBJS)
	$(CC) -pg -o $(BIN)/vetop $(OBJS) $(LIBS)

$(OBJ)/vetop.o: $(HDRS) $(SRC)/vetop.c
	$(CC) $(CFLAGS) -o $(OBJ)/vetop.o $(SRC)/vetop.c 

$(OBJ)/vet.o: $(HDRS) $(SRC)/vet.c
	$(CC) $(CFLAGS) -o $(OBJ)/vet.o $(SRC)/vet.c 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
