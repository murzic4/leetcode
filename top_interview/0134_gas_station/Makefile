CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -O2

test: test.cpp solution.h
	$(CXX) $(CXXFLAGS) test.cpp -o test
	./test

clean:
	rm -f test

.PHONY: test clean
