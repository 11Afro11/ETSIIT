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
INC = include
 
CXX = g++
CXXFLAGS = -w -I$(INC) -Wall -g


 
HEADERS = $(addprefix $(INC)/, ejemplo1.h ejemplo2.h)
OBJECTS = $(addprefix $(OBJ)/, ejemplo1.o ejemplo2.o)
 
 
BINS = $(addprefix $(BIN)/, ejemplo1Main ejemplo2Main)
 
all: clean preambulo ejecutables $(BINS) fin-ejecutables
 
 
$(BIN)/%: $(OBJ)/%.o $(OBJECTS)
	$(CXX) $^ -o $@
 
$(OBJ)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
 
#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relacion de Problemas <<X>>
	@echo Sesion <<X<< de Practicas
	@echo
	@echo METODOLOGIA DE LA PROGRAMACIÓN
	@echo Grado en Ingenieria Informatica - Grupo <<X>>
	@echo
	@echo "("c")" <<Insert Name Here>>
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