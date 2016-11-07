# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2014-2015
# (C) FRANCISCO JAVIER FUENTES BARRAGÁN
#
# SESION6.mak
# Fichero makefile escreito para los archivos de la sesion 6 que se encarga de generar 
# un archivo ejecutable a partir de los ficheros .h y .cpp
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(BIN)/LeeYPinta $(BIN)/CambiosLista $(BIN)/Enlazar $(BIN)/CalculosLista $(BIN)/Ordena $(BIN)/Ordenada $(BIN)/Poligono

##################################################################################
#lee y pinta
##################################################################################


$(BIN)/LeeYPinta: $(OBJ)/LeeYPinta.o $(OBJ)/lista.o
	g++ -o $(BIN)/LeeYPinta $(OBJ)/LeeYPinta.o $(OBJ)/lista.o 


$(OBJ)/LeeYPinta.o: $(SRC)/LeeYPinta.cpp $(INCLUDE)/lista.h 
	g++ -c -g -o $(OBJ)/LeeYPinta.o $(SRC)/LeeYPinta.cpp -I$(INCLUDE)

##################################################################################
#cambios en la lista
##################################################################################

$(BIN)/CambiosLista: $(OBJ)/CambiosLista.o $(OBJ)/lista.o
	g++ -o $(BIN)/CambiosLista $(OBJ)/CambiosLista.o $(OBJ)/lista.o 


$(OBJ)/CambiosLista.o: $(SRC)/CambiosLista.cpp $(INCLUDE)/lista.h 
	g++ -c -g -o $(OBJ)/CambiosLista.o $(SRC)/CambiosLista.cpp -I$(INCLUDE)

##################################################################################
#enlazar
##################################################################################

$(BIN)/Enlazar: $(OBJ)/enlazar.o $(OBJ)/lista.o
	g++ -o $(BIN)/Enlazar $(OBJ)/enlazar.o $(OBJ)/lista.o 


$(OBJ)/enlazar.o: $(SRC)/enlazar.cpp $(INCLUDE)/lista.h 
	g++ -c -g -o $(OBJ)/enlazar.o $(SRC)/enlazar.cpp -I$(INCLUDE)

##################################################################################
#calculos
##################################################################################

$(BIN)/CalculosLista: $(OBJ)/CalculosLista.o $(OBJ)/lista.o
	g++ -o $(BIN)/CalculosLista $(OBJ)/CalculosLista.o $(OBJ)/lista.o 


$(OBJ)/CalculosLista.o: $(SRC)/CalculosLista.cpp $(INCLUDE)/lista.h 
	g++ -c -g -o $(OBJ)/CalculosLista.o $(SRC)/CalculosLista.cpp -I$(INCLUDE)

##################################################################################
#ordenar
##################################################################################

$(BIN)/Ordena: $(OBJ)/ordena.o $(OBJ)/lista.o
	g++ -o $(BIN)/Ordena $(OBJ)/ordena.o $(OBJ)/lista.o 


$(OBJ)/ordena.o: $(SRC)/ordena.cpp $(INCLUDE)/lista.h 
	g++ -c -g -o $(OBJ)/ordena.o $(SRC)/ordena.cpp -I$(INCLUDE)

##################################################################################
#esta ordenada
##################################################################################

$(BIN)/Ordenada: $(OBJ)/Ordenada.o $(OBJ)/lista.o
	g++ -o $(BIN)/Ordenada $(OBJ)/Ordenada.o $(OBJ)/lista.o 


$(OBJ)/Ordenada.o: $(SRC)/Ordenada.cpp $(INCLUDE)/lista.h 
	g++ -c -g -o $(OBJ)/Ordenada.o $(SRC)/Ordenada.cpp -I$(INCLUDE)

##################################################################################
#lista.o
##################################################################################

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INCLUDE)/lista.h
	g++ -c -g -o $(OBJ)/lista.o $(SRC)/lista.cpp -I$(INCLUDE)


##################################################################################
##################################################################################
##################################################################################
#Poligono
##################################################################################
##################################################################################
##################################################################################

$(BIN)/Poligono: $(OBJ)/PoligonoMain.o $(OBJ)/Poligono.o
	g++ -o $(BIN)/Poligono $(OBJ)/PoligonoMain.o $(OBJ)/Poligono.o 


$(OBJ)/PoligonoMain.o: $(SRC)/PoligonoMain.cpp $(INCLUDE)/Poligono.h 
	g++ -c -g -o $(OBJ)/PoligonoMain.o $(SRC)/PoligonoMain.cpp -I$(INCLUDE)


$(OBJ)/Poligono.o: $(SRC)/Poligono.cpp $(INCLUDE)/Poligono.h
	g++ -c -g -o $(OBJ)/Poligono.o $(SRC)/Poligono.cpp -I$(INCLUDE)



# LIMPEZA

clean: 
	-rm $(OBJ)/*

mrproper: clean
	-rm $(BIN)/*