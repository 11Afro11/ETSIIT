###############################################################################################
#
#MAKEFILE GENERICO
#
#Francisco javier Fuentes Barragan.
#
#ETSIIT
#
###############################################################################################
#
#INSTUCCIONES:
#
#Sustituir en el apartado HEADERS los nombres de las cabeceras con la extension.h
#
#Sustituir en el apartado OBJECTS los nombres de los .o ojo: SOLO los desarrollos de las
#funciones. no incluir los .o del main
#
#Para finalizar en el apartado BINS sustituir los ejemplos por los nombres de los ejecutables 
#los cuales deben de tener el msmo nombre que el archivo Main.
#
#
###############################################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all: clean preambulo ejecutables $(BIN)/Lista-Alumnos fin-ejecutables

$(BIN)/Lista-Alumnos: $(OBJ)/Clase-Clase-Alumnos.o $(OBJ)/Clase-Clase-AlumnosMain.o $(OBJ)/Clase-Alumnos.o
	g++ -o $(BIN)/Lista-Alumnos $(OBJ)/Clase-Clase-Alumnos.o $(OBJ)/Clase-Alumnos.o $(OBJ)/Clase-Clase-AlumnosMain.o

$(OBJ)/Clase-Clase-AlumnosMain.o: $(SRC)/Clase-Clase-AlumnosMain.cpp $(INCLUDE)/Clase-Clase-Alumnos.h 
	g++ -c -g -o $(OBJ)/Clase-Clase-AlumnosMain.o $(SRC)/Clase-Clase-AlumnosMain.cpp -I$(INCLUDE)

$(OBJ)/Clase-Clase-Alumnos.o: $(SRC)/Clase-Clase-Alumnos.cpp $(INCLUDE)/Clase-Clase-Alumnos.h 
	g++ -c -g -o $(OBJ)/Clase-Clase-Alumnos.o $(SRC)/Clase-Clase-Alumnos.cpp -I$(INCLUDE)

##################################################################################
#lista.o
##################################################################################

$(OBJ)/Clase-Alumnos.o: $(SRC)/Clase-Alumnos.cpp $(INCLUDE)/Clase-Alumnos.h
	g++ -c -g -o $(OBJ)/Clase-Alumnos.o $(SRC)/Clase-Alumnos.cpp -I$(INCLUDE)
 
#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relacion de Problemas 4
	@echo Sesion 10 de Practicas
	@echo
	@echo METODOLOGIA DE LA PROGRAMACIÓN
	@echo Grado en Ingenieria Informatica - Grupo C
	@echo
	@echo "("c")" Francisco Javier Fuentes Barragan
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



.PHONY: clean
clean:
	-rm -f $(OBJ)/* $(BIN)/*