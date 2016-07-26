VPATH= src include
CPPFLAGS= -Iinclude


sudoku:sudoku.o candidates.o singles_candidature.o hidden_singles_candidature.o check_sudoku.o \
       single_sector_candidates.o
	g++ $^ -o $@
sudoku.o:sudoku.cpp candidates.h
	g++ -c $< $(CPPFLAGS)
check_sudoku.o:check_sudoku.cpp candidates.h
	g++ -c $< $(CPPFLAGS)
candidates.o:candidates.cpp candidates.h
	g++ -c $< $(CPPFLAGS) 
singles_candidature.o:singles_candidature.cpp candidates.h
	g++ -c $< $(CPPFLAGS)
hidden_singles_candidature.o:hidden_singles_candidature.cpp candidates.h
	g++ -c $< $(CPPFLAGS)
single_sector_candidates.o:single_sector_candidates.cpp candidates.h
	g++ -c $< $(CPPFLAGS)


clean:
	rm -f *.o
