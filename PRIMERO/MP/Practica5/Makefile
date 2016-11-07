



BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

CXX = g++

CXXFLAGS = -g -I$(INCLUDE)

HEADERS = $(addprefix $(INCLUDE)/, Calificaciones.h)
OBJECTS = $(addprefix $(OBJ)/, Calificaciones.o CalificacionesMain.o)
BINS = $(addprefix $(BIN)/, CalificacionesMain)

all: $(BINS)


$(BIN)/%: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@
$(OBJ)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<


.PHONY: clean
clean:
	rm -f $(OBJ) $(BIN)



