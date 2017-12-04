CXX=g++
CXXFLAGS=-c -Wall

SOURCES=mesh.cpp R1.cpp EF1d-base.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=tp4

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

#$(OBJECTS): $(SOURCES)
#	$(CXX) $(CXXFLAGS) $^

1.1: mesh.o
	$(CXX) $^ -o $(EXECUTABLE)

R1.o: R1.cpp
	$(CXX) $(CXXFLAGS) $^

#EF1d-base.o: R1.o EF1d-base.cpp
#	$(CXX) $(CXXFLAGS) $^

test: test.cpp
	$(CXX) $^ -o $@

run: ./$(EXECUTABLE)
	./$(EXECUTABLE)	${ARGS}

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *~
