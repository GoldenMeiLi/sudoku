VPATH= src include
CPPFLAGS= -Iinclude


sudoku:sudoku.o
	g++ $^ -o $@
sudoku.o:sudoku.cpp candidates.h
	g++ -c $< $(CPPFLAGS)








clean:
	rm -f *.o
