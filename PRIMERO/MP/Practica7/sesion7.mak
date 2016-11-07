# SESION7.mak
# Fichero makefile escreito para los archivos de la sesion 5 que se encarga de generar 
# un archivo ejecutable a partir de los ficheros .h y .cpp
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(BIN)/Matriz2D_1 $(BIN)/Matriz2D_2 $(BIN)/CopiaMatrices

##################################################################################
#Ejercicio 1
##################################################################################


$(BIN)/Matriz2D_1: $(OBJ)/MatrizMain.o $(OBJ)/Matriz2D_1.o
	g++ -o $(BIN)/Matriz2D_1 $(OBJ)/MatrizMain.o $(OBJ)/Matriz2D_1.o 


$(OBJ)/MatrizMain.o: $(SRC)/MatrizMain.cpp $(INCLUDE)/Matriz2D_1.h 
	g++ -c -g -o $(OBJ)/MatrizMain.o $(SRC)/MatrizMain.cpp -I$(INCLUDE)


$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h
	g++ -c -g -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)


##################################################################################
#Ejercicio 2
##################################################################################


$(BIN)/Matriz2D_2: $(OBJ)/Matriz2Main.o $(OBJ)/Matriz2D_2.o
	g++ -o $(BIN)/Matriz2D_2 $(OBJ)/Matriz2Main.o $(OBJ)/Matriz2D_2.o 


$(OBJ)/Matriz2Main.o: $(SRC)/Matriz2Main.cpp $(INCLUDE)/Matriz2D_2.h 
	g++ -c -g -o $(OBJ)/Matriz2Main.o $(SRC)/Matriz2Main.cpp -I$(INCLUDE)


$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp $(INCLUDE)/Matriz2D_2.h
	g++ -c -g -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE)


##################################################################################
#Ejercicio3
##################################################################################


$(BIN)/ConvierteMatrices: $(OBJ)/ConvierteMatricesMain.o $(OBJ)/ConvierteMatrices.o
	g++ -o $(BIN)/ConvierteMatrices $(OBJ)/ConvierteMatricesMain.o $(OBJ)/ConvierteMatrices.o 


$(OBJ)/ConvierteMatricesMain.o: $(SRC)/ConvierteMatricesMain.cpp $(INCLUDE)/ConvierteMatrices.h 
	g++ -c -g -o $(OBJ)/ConvierteMatricesMain.o $(SRC)/ConvierteMatricesMain.cpp -I$(INCLUDE)


$(OBJ)/ConvierteMatrices.o: $(SRC)/ConvierteMatrices.cpp $(INCLUDE)/ConvierteMatrices.h
	g++ -c -g -o $(OBJ)/ConvierteMatrices.o $(SRC)/ConvierteMatrices.cpp -I$(INCLUDE)



# LIMPEZA

clean: 
	-rm $(OBJ)/*

mrproper: clean
	-rm $(BIN)/*