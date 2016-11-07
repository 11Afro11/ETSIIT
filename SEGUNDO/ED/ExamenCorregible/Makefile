

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include
DATOS = datos
DOC = doc

NAME = pasa_test

all: clean preambulo ejecutables doxygen $(BIN)/pruebagen_test fin-ejecutables readme  

##################################################################################
#Ejercicio 1
##################################################################################


$(BIN)/pruebagen_test: $(OBJ)/pruebagen_test.o $(OBJ)/Test.o $(OBJ)/ConjuntoPreguntas.o $(OBJ)/Pregunta.o $(OBJ)/Soluciones.o
	g++ -std=c++11 -o $(BIN)/pruebagen_test $(OBJ)/pruebagen_test.o $(OBJ)/Test.o $(OBJ)/ConjuntoPreguntas.o $(OBJ)/Pregunta.o $(OBJ)/Soluciones.o


$(OBJ)/pruebagen_test.o: $(SRC)/pruebagen_test.cpp $(INCLUDE)/ConjuntoPreguntas.h $(INCLUDE)/Test.h
	g++ -std=c++11 -c -g -o $(OBJ)/pruebagen_test.o $(SRC)/pruebagen_test.cpp -I$(INCLUDE)


$(OBJ)/Pregunta.o: $(SRC)/Pregunta.cpp $(INCLUDE)/Pregunta.h
	g++ -std=c++11 -c -g -o $(OBJ)/Pregunta.o $(SRC)/Pregunta.cpp -I$(INCLUDE)


$(OBJ)/ConjuntoPreguntas.o: $(SRC)/ConjuntoPreguntas.cpp $(INCLUDE)/ConjuntoPreguntas.h
	g++ -std=c++11 -c -g -o $(OBJ)/ConjuntoPreguntas.o $(SRC)/ConjuntoPreguntas.cpp -I$(INCLUDE)

$(OBJ)/Soluciones.o: $(SRC)/Soluciones.cpp $(INCLUDE)/Soluciones.h
	g++ -std=c++11 -c -g -o $(OBJ)/Soluciones.o $(SRC)/Soluciones.cpp -I$(INCLUDE)


$(OBJ)/Test.o: $(SRC)/Test.cpp $(INCLUDE)/Test.h
	g++ -std=c++11 -c -g -o $(OBJ)/Test.o $(SRC)/Test.cpp -I$(INCLUDE)


#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo PRACTICA 2
	@echo
	@echo ESTRUCTURA DE DATOS
	@echo Grado en Ingenieria Informatica - Grupo C
	@echo
	@echo "("c")" FRANCISCO JAVIER FUENTES BARRAGAN
	@echo Escuela Tecnica Superior de Ingenieria Informatica y Telecomunicaciones
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo
#................................................

ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados:
	@echo
	@ls $(BIN)/

readme:
	@clear
	@echo
	@echo ------------------------------------------------------------
	@echo Compilacion Terminada
	@echo
	@echo Ejecutable Creado En /bin
	@echo 
	@echo Documentacion Creada en /doc en html y en Latex,
	@echo se solicitan solo 2 parametros. PreguntasConstitucion.txt y Soluciones.txt
	@echo ------------------------------------------------------------
	@echo Instrucciones:
	@echo
	@echo make open_doc : Para ver la documentacion
	@echo 
	@echo make exe : para ejecutar el Ejercicio
	@echo
	@echo make zip : para comprimir el proyecto
	@echo

# ************ Limpieza ************
clean:
	@-rm $(BIN)/* $(OBJ)/*
	@-rm -rf $(DOC)/*
	@echo 
	@echo
	@echo Limpieza Terminada.
	@echo 

zip:
	zip -l $(NAME).zip  ./* src/*.cpp include/*.h datos/*.txt datos/*.jpg datos/* ./$(NAME).mak

exe:
	@./bin/pruebagen_test ./datos/PreguntasConstitucion.txt ./datos/Soluciones.txt

latex:
	make -C ./datos

open:
	xdg-open Examen.pdf	

documentacion:
	doxygen doc/doxys/Doxyfile

doxygen:
	doxygen
	make -C ./doc/latex
open_doc:
	xdg-open ./doc/html/files.html