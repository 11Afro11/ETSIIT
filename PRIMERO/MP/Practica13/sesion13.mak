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

NAME = sesion13


 
CXX = g++
CXXFLAGS = -w -std=c++11 -Wall -g
 
 
BINS = $(addprefix $(BIN)/, NumeraLineas Diferencias MezclaFicheros Codifica SumasPorGrupos ParteFicheroPorNumLineas Busca Cabecera Final)
 
all: clean preambulo ejecutables $(BIN)/Constructores $(BINS) fin-ejecutables
 
 
$(BIN)/%: $(SRC)/%.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#.............................................................................

$(BIN)/Constructores: $(OBJ)/Constructores.o $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o
	g++ -o $(BIN)/Constructores $(OBJ)/Constructores.o $(OBJ)/Matriz2D_1.o $(OBJ)/Matriz2D_2.o


$(OBJ)/Constructores.o: $(SRC)/Constructores.cpp $(INC)/Matriz2D_1.h $(INC)/Matriz2D_2.h
	g++ -c -g -o $(OBJ)/Constructores.o $(SRC)/Constructores.cpp -I$(INC)


$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp $(INC)/Matriz2D_1.h
	g++ -c -g -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INC)

$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp $(INC)/Matriz2D_2.h
	g++ -c -g -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INC)
 
#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relacion de Problemas
	@echo Sesion 12 de Practicas
	@echo
	@echo METODOLOGIA DE LA PROGRAMACIÓN
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
	@echo 



.PHONY: clean
clean:
	-rm -f $(OBJ)/* $(BIN)/* ./*.zip

zip:
	zip -l $(NAME).zip  ./* src/*.cpp include/*.h ./$(NAME).mak