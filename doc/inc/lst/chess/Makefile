CC = g++ 
CFLAGS = -c -Wall 
LDFLAGS = 
INCLUDE = include 
INCLUDE_MATRIX = ../matrix/include 

SRC = main map chess_piece \
	chess_rule_for_king \
	chess_rule_for_pawn \
	chess_rule_for_rook \
	chess_rule_for_bishop \
	chess_rule_for_knight \
	chess_rule_for_queen 
SOURCES = $(addsuffix .cpp, $(addprefix src/, $(SRC))) $(STATIC_LIBS)
OBJECTS = $(SOURCES:.cpp=.o) 
EXECUTABLE = chess.out

main: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS) 	
	$(CC) $(OBJECTS) -o $@ -DSFML_STATIC \
		-Iinclude

%.o: %.cpp 	
	g++ -c -o $@ $< -I$(INCLUDE) -I$(INCLUDE_MATRIX)


clear: 	
	rm -f src/*.o $(EXECUTABLE) 
