VPATH= src include
CPPFLAGS= -Iinclude


sudoku:sudoku.o candidates.o singles_candidature.o
	g++ $^ -o $@
sudoku.o:sudoku.cpp candidates.h
	g++ -c $< $(CPPFLAGS)
candidates.o:candidates.cpp candidates.h
	g++ -c $< $(CPPFLAGS) 
singles_candidature.o:singles_candidature.cpp candidates.h
	g++ -c $< $(CPPFLAGS)




clean:
	rm -f *.o
