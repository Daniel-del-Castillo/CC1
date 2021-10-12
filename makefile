CXX = g++
CXXFLAGS = -I . -Wall -Werror -Wextra -pedantic 

bin/automaton_simulator: src/main.cpp bin/pushdown_automaton_reader.o bin/pushdown_automaton.o bin/alphabet.o bin/state.o bin/transition.o
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/pushdown_automaton_reader.o: src/pushdown_automaton_reader.cpp headers/pushdown_automaton_reader.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/pushdown_automaton_reader.cpp

bin/pushdown_automaton.o: src/pushdown_automaton.cpp headers/pushdown_automaton.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/pushdown_automaton.cpp

bin/alphabet.o: src/alphabet.cpp headers/alphabet.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/pushdown_automaton.cpp

bin/state.o: src/state.cpp headers/state.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/state.cpp

bin/transition.o: src/transition.cpp headers/transition.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ src/transition.cpp 

clean:
	rm bin/*
