# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2014-2015
# (C) FRANCISCO JAVIER FUENTES BARRAGÁN
#
# SESION4.mak
# Fichero makefile escreito para los archivos de la sesion 4 que se encarga de generar 
# un archivo ejecutable a partir de DemosCadenasClasicas.cpp, MiCadenaClasica.h y MiCadenaClasica.cpp
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all: clean $(BIN)/DemosCadenasClasicas $(BIN)/PosicionPrimerBlanco $(BIN)/SaltaPrimeraPalabra

##################################################################################
#Ejercicios del 8 al 14
##################################################################################


$(BIN)/DemosCadenasClasicas: $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	g++ -o $(BIN)/DemosCadenasClasicas $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o 


$(OBJ)/DemosCadenasClasicas.o: $(SRC)/DemosCadenasClasicas.cpp $(INCLUDE)/MiCadenaClasica.h 
	g++ -c -o $(OBJ)/DemosCadenasClasicas.o $(SRC)/DemosCadenasClasicas.cpp -I$(INCLUDE)


$(OBJ)/MiCadenaClasica.o: $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE)

##################################################################################
#Ejercicios 6 y 7
##################################################################################

$(BIN)/PosicionPrimerBlanco: $(OBJ)/PosicionPrimerBlanco.o
	g++ -o $(BIN)/PosicionPrimerBlanco $(OBJ)/PosicionPrimerBlanco.o

$(OBJ)/PosicionPrimerBlanco.o: $(SRC)/PosicionPrimerBlanco.cpp
	g++ -c -o $(OBJ)/PosicionPrimerBlanco.o $(SRC)/PosicionPrimerBlanco.cpp

$(BIN)/SaltaPrimeraPalabra: $(OBJ)/SaltaPrimeraPalabra.o
	g++ -o $(BIN)/SaltaPrimeraPalabra $(OBJ)/SaltaPrimeraPalabra.o

$(OBJ)/SaltaPrimeraPalabra.o: $(SRC)/SaltaPrimeraPalabra.cpp
	g++ -c -o $(OBJ)/SaltaPrimeraPalabra.o $(SRC)/SaltaPrimeraPalabra.cpp


 

# LIMPEZA

clean: 
	-rm $(OBJ)/*

mrproper: clean
	-rm $(BIN)/*