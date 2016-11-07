

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

NAME = sesion13

all: clean preambulo ejecutables $(BIN)/pruebagen_test fin-ejecutables

##################################################################################
#Ejercicio 1
##################################################################################


$(BIN)/pruebagen_test: $(OBJ)/pruebagen_test.o $(OBJ)/Test.o $(OBJ)/ConjuntoPreguntas.o $(OBJ)/Pregunta.o
	g++ -o $(BIN)/pruebagen_test $(OBJ)/pruebagen_test.o $(OBJ)/Test.o $(OBJ)/ConjuntoPreguntas.o $(OBJ)/Pregunta.o 


$(OBJ)/pruebagen_test.o: $(SRC)/pruebagen_test.cpp $(INCLUDE)/ConjuntoPreguntas.h $(INCLUDE)/Test.h
	g++ -c -g -o $(OBJ)/pruebagen_test.o $(SRC)/pruebagen_test.cpp -I$(INCLUDE)


$(OBJ)/Pregunta.o: $(SRC)/Pregunta.cpp $(INCLUDE)/Pregunta.h
	g++ -c -g -o $(OBJ)/Pregunta.o $(SRC)/Pregunta.cpp -I$(INCLUDE)


$(OBJ)/ConjuntoPreguntas.o: $(SRC)/ConjuntoPreguntas.cpp $(INCLUDE)/ConjuntoPreguntas.h
	g++ -c -g -o $(OBJ)/ConjuntoPreguntas.o $(SRC)/ConjuntoPreguntas.cpp -I$(INCLUDE)


$(OBJ)/Test.o: $(SRC)/Test.cpp $(INCLUDE)/Test.h
	g++ -c -g -o $(OBJ)/Test.o $(SRC)/Test.cpp -I$(INCLUDE)

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

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

zip:
	zip -l $(NAME).zip  ./* src/*.cpp include/*.h ./$(NAME).mak