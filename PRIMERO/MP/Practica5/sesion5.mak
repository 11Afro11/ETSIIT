# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2014-2015
# (C) FRANCISCO JAVIER FUENTES BARRAGÁN
#
# SESION5.mak
# Fichero makefile escreito para los archivos de la sesion 5 que se encarga de generar 
# un archivo ejecutable a partir de los ficheros .h y .cpp
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(BIN)/RedimensionarVectorDinamico $(BIN)/Calificaciones

##################################################################################
#Ejercicio 1
##################################################################################


$(BIN)/RedimensionarVectorDinamico: $(OBJ)/RedimensionarVectorDinamicoMain.o $(OBJ)/RedimensionarVectorDinamico.o
	g++ -o $(BIN)/RedimensionarVectorDinamico $(OBJ)/RedimensionarVectorDinamicoMain.o $(OBJ)/RedimensionarVectorDinamico.o 


$(OBJ)/RedimensionarVectorDinamicoMain.o: $(SRC)/RedimensionarVectorDinamicoMain.cpp $(INCLUDE)/RedimensionarVectorDinamico.h 
	g++ -c -g -o $(OBJ)/RedimensionarVectorDinamicoMain.o $(SRC)/RedimensionarVectorDinamicoMain.cpp -I$(INCLUDE)


$(OBJ)/RedimensionarVectorDinamico.o: $(SRC)/RedimensionarVectorDinamico.cpp $(INCLUDE)/RedimensionarVectorDinamico.h
	g++ -c -g -o $(OBJ)/RedimensionarVectorDinamico.o $(SRC)/RedimensionarVectorDinamico.cpp -I$(INCLUDE)

##################################################################################
#Ejercicio 2
##################################################################################

$(BIN)/Calificaciones: $(OBJ)/CalificacionesMain.o $(OBJ)/Calificaciones.o
	g++ -o $(BIN)/Calificaciones $(OBJ)/CalificacionesMain.o $(OBJ)/Calificaciones.o


$(OBJ)/CalificacionesMain.o: $(SRC)/CalificacionesMain.cpp $(INCLUDE)/Calificaciones.h 
	g++ -c -g -o $(OBJ)/CalificacionesMain.o $(SRC)/CalificacionesMain.cpp -I$(INCLUDE)


$(OBJ)/Calificaciones.o: $(SRC)/Calificaciones.cpp $(INCLUDE)/Calificaciones.h 
	g++ -c -g -o $(OBJ)/Calificaciones.o $(SRC)/Calificaciones.cpp -I$(INCLUDE)




# LIMPEZA

clean: 
	-rm $(OBJ)/*

mrproper: clean
	-rm $(BIN)/*