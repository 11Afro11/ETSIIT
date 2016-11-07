#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2014-2015
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# sesion8.mak
#
#############################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

#................................................
all:  preambulo \
      clean\
      bibliotecas\
      $(OBJ)/VectorDinamico_ConstructorCopia.o \
      $(LIB)/libVectorDinamico_ConstructorCopia.a \
      $(OBJ)/Matriz2D_1_ConstructorCopia.o \
      $(LIB)/libMatriz2D_1_ConstructorCopia.a \
      $(OBJ)/Matriz2D_2_ConstructorCopia.o \
      $(LIB)/libMatriz2D_2_ConstructorCopia.a \
      $(OBJ)/Lista_ConstructorCopia.o \
      $(LIB)/libLista_ConstructorCopia.a \
      fin-bibliotecas \
	  ejecutables \
      $(BIN)/Demo-VectorDinamico_ConstructorCopia \
      $(BIN)/Demo-Matriz2D_1_ConstructorCopia \
      $(BIN)/Demo-Matriz2D_2_ConstructorCopia \
      $(BIN)/Demo-Lista_ConstructorCopia \
	  fin-ejecutables

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
	@echo "("c")" Francisco Jose CORTIJO BON
	@echo Depto. Ciencias de la Computacion e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo
#................................................

ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados
	@echo 	

bibliotecas:
	@echo Creando modulos objeto y bibliotecas...

fin-bibliotecas:
	@echo ...Creados
	@echo 	
#................................................
# EJECUTABLES

$(BIN)/Demo-VectorDinamico_ConstructorCopia : $(OBJ)/Demo-VectorDinamico_ConstructorCopia.o $(LIB)/libVectorDinamico_ConstructorCopia.a
	g++ -o $@ $(OBJ)/Demo-VectorDinamico_ConstructorCopia.o -lVectorDinamico_ConstructorCopia -L$(LIB)

$(BIN)/Demo-Matriz2D_1_ConstructorCopia : $(OBJ)/Demo-Matriz2D_1_ConstructorCopia.o $(LIB)/libMatriz2D_1_ConstructorCopia.a
	g++ -o $@ $(OBJ)/Demo-Matriz2D_1_ConstructorCopia.o -lMatriz2D_1_ConstructorCopia -L$(LIB)

$(BIN)/Demo-Matriz2D_2_ConstructorCopia : $(OBJ)/Demo-Matriz2D_2_ConstructorCopia.o $(LIB)/libMatriz2D_2_ConstructorCopia.a
	g++ -o $@ $(OBJ)/Demo-Matriz2D_2_ConstructorCopia.o -lMatriz2D_2_ConstructorCopia -L$(LIB)

$(BIN)/Demo-Lista_ConstructorCopia : $(OBJ)/Demo-Lista_ConstructorCopia.o $(LIB)/libLista_ConstructorCopia.a
	g++ -o $@ $(OBJ)/Demo-Lista_ConstructorCopia.o -lLista_ConstructorCopia -L$(LIB)

$(BIN)/Demo-Conjunto_ConstructorCopia : $(OBJ)/Demo-Conjunto_ConstructorCopia.o $(LIB)/libConjunto_ConstructorCopia.a
	g++ -o $@ $(OBJ)/Demo-Conjunto_ConstructorCopia.o -lConjunto_ConstructorCopia -L$(LIB)


#................................................
# OBJETOS

$(OBJ)/Demo-VectorDinamico_ConstructorCopia.o : $(SRC)/Demo-VectorDinamico_ConstructorCopia.cpp $(INCLUDE)/VectorDinamico_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)

$(OBJ)/Demo-Matriz2D_1_ConstructorCopia.o : $(SRC)/Demo-Matriz2D_1_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)

$(OBJ)/Demo-Matriz2D_2_ConstructorCopia.o : $(SRC)/Demo-Matriz2D_2_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_2_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)

$(OBJ)/Demo-Lista_ConstructorCopia.o : $(SRC)/Demo-Lista_ConstructorCopia.cpp $(INCLUDE)/Lista_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)

$(OBJ)/Demo-Conjunto_ConstructorCopia.o : $(SRC)/Demo-Conjunto_ConstructorCopia.cpp $(INCLUDE)/Conjunto.h
	g++ -c -o $@ $< -I$(INCLUDE)

#................................................
# BIBLIOTECAS

$(OBJ)/VectorDinamico_ConstructorCopia.o : $(SRC)/VectorDinamico_ConstructorCopia.cpp $(INCLUDE)/VectorDinamico_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)
$(LIB)/libVectorDinamico_ConstructorCopia.a : $(OBJ)/VectorDinamico_ConstructorCopia.o 
	ar -rvs $(LIB)/libVectorDinamico_ConstructorCopia.a $(OBJ)/VectorDinamico_ConstructorCopia.o 

$(OBJ)/Matriz2D_1_ConstructorCopia.o : $(SRC)/Matriz2D_1_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)
$(LIB)/libMatriz2D_1_ConstructorCopia.a : $(OBJ)/Matriz2D_1_ConstructorCopia.o 
	ar -rvs $(LIB)/libMatriz2D_1_ConstructorCopia.a $(OBJ)/Matriz2D_1_ConstructorCopia.o 

$(OBJ)/Matriz2D_2_ConstructorCopia.o : $(SRC)/Matriz2D_2_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_2_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)
$(LIB)/libMatriz2D_2_ConstructorCopia.a : $(OBJ)/Matriz2D_2_ConstructorCopia.o 
	ar -rvs $(LIB)/libMatriz2D_2_ConstructorCopia.a $(OBJ)/Matriz2D_2_ConstructorCopia.o 

$(OBJ)/Lista_ConstructorCopia.o : $(SRC)/Lista_ConstructorCopia.cpp $(INCLUDE)/Lista_ConstructorCopia.h
	g++ -c -o $@ $< -I$(INCLUDE)
$(LIB)/libLista_ConstructorCopia.a : $(OBJ)/Lista_ConstructorCopia.o 
	ar -rvs $(LIB)/libLista_ConstructorCopia.a $(OBJ)/Lista_ConstructorCopia.o 

$(OBJ)/Conjunto.o : $(SRC)/Conjunto.cpp $(INCLUDE)/Conjunto.h
	g++ -c -o $@ $< -I$(INCLUDE)
$(LIB)/libConjunto_ConstructorCopia.a : $(OBJ)/Conjunto.o 
	ar -rvs $(LIB)/libConjunto_ConstructorCopia.a $(OBJ)/Conjunto.o 

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos...

	-rm $(OBJ)/Demo-VectorDinamico_ConstructorCopia.o
	-rm $(OBJ)/Demo-Matriz2D_1_ConstructorCopia.o
	-rm $(OBJ)/Demo-Matriz2D_2_ConstructorCopia.o
	-rm $(OBJ)/Demo-Lista_ConstructorCopia.o

	@echo ...Borrados
	@echo 

clean-libs: 
	@echo Borrando modulos objeto y bibliotecas...

	-rm $(OBJ)/VectorDinamico_ConstructorCopia.o
	-rm $(LIB)/libVectorDinamico_ConstructorCopia.a

	-rm $(OBJ)/Matriz2D_1_ConstructorCopia.o
	-rm $(LIB)/libMatriz2D_1_ConstructorCopia.a

	-rm $(OBJ)/Matriz2D_2_ConstructorCopia.o
	-rm $(LIB)/libMatriz2D_2_ConstructorCopia.a

	-rm $(OBJ)/Lista_ConstructorCopia.o
	-rm $(LIB)/libLista_ConstructorCopia.a

	@echo ...Borrado
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/Demo-VectorDinamico_ConstructorCopia
	-rm $(BIN)/Demo-Matriz2D_1_ConstructorCopia
	-rm $(BIN)/Demo-Lista_ConstructorCopia

	@echo ...Borrados
	@echo 	

mr.proper:  clean clean-bins

