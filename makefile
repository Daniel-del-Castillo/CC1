CXX = g++
CXXFLAGS = -I . -Wall -Werror -Wextra -pedantic 

bin/automaton_simulator: src/main.cpp bin/pda_reader.o bin/pda.o bin/alphabet.o bin/state.o bin/transition.o
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/pda_reader.o: src/pda_reader.cpp headers/pda_reader.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/pda_reader.cpp

bin/pda.o: src/pda.cpp headers/pda.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/pda.cpp

bin/alphabet.o: src/alphabet.cpp headers/alphabet.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/pda.cpp

bin/state.o: src/state.cpp headers/state.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/state.cpp

bin/transition.o: src/transition.cpp headers/transition.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/transition.cpp 

clean:
	rm bin/*