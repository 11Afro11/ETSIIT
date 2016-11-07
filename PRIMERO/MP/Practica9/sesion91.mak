



BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

CXX = g++

CXXFLAGS = -g -I$(INCLUDE)

HEADERS = $(addprefix $(INCLUDE)/, Matriz2D_1.h Matriz2D_2.h Lista.h VectorDimamico.h Conjunto.h)
OBJECTS = $(addprefix $(OBJ)/, Matriz2D_1.o Matriz2D_2.o Lista.o VectorDimamico.o Conjunto.o)


BINS = $(addprefix $(BIN)/, Matriz2D_1Main Matriz2D_2Main ListaMain VectorDimamicoMain ConjuntoMain)

all: preambulo ejecutables $(BINS) fin-ejecutables lista-ejecutables


$(BIN)/%: $(OBJ)/%.o $(OBJECTS)
	$(CXX) $^ -o $@
$(OBJ)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<


#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relacion de Problemas III
	@echo Sesion 8 de Practicas
	@echo
	@echo METODOLOGIA DE LA PROGRAMACIÓN
	@echo Grado en Ingenieria Informatica - Grupo C
	@echo
	@echo "("c")" Francisco Javier Fuentes Barragán
	@echo Escuela Tecnica Superior de Ingenieria Informatica Y Telecomunicaciones
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo
#................................................


ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados
	@echo 	

lista-ejecutables:
	@echo Los ejecutables creados son:
	@echo
	@echo Matriz2D_1Main 
	@echo Matriz2D_2Main 
	@echo ListaMain 
	@echo VectorDimamicoMain 
	@echo ConjuntoMain



.PHONY: clean
clean:
	rm -f $(OBJ)/* $(BIN)/*



