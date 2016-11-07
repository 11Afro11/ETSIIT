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
CXXFLAGS = -w -Wall -g
 
 
BINS = $(addprefix $(BIN)/,  CopiaTodo CopiaExceptoVocales CuentaCaracteres CuentaLineasNoVacias MuestraLineasNoVacias ComprimeLineas CopiaLineasSinAlmohadilla CopiaEnteros CopiaEnterosSeparados SumaEnteros CuentaCaracteresConcretos CuentaPalabrasLongitudConcreta CopiaEnteros-OrdenInverso)
 
all: clean preambulo ejecutables $(BINS) fin-ejecutables
 
 
$(BIN)/%: $(SRC)/%.cpp $(OBJECTS)
	$(CXX) $^ -o $@

 
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
	-rm -f $(OBJ)/* $(BIN)/*