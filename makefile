#!make -f

CXX=g++
CXXFLAGS := -Wall -Wextra -std=c++11
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES= Demo.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: tree
	./$^

tree: Demo.o $(filter-out TestCounter.o Test.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o tree

test: TestCounter.o Test.o $(filter-out Demo.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: tree 
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./tree 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o tree test