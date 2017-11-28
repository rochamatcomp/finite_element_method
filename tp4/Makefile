CXX=g++
CXXFLAGS=-c -Wall

SOURCES=tp4_1.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=tp4

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^

1.1: tp4_1.o
	$(CXX) $^ -o $(EXECUTABLE)

R1: R1.cpp
	$(CXX) $(CXXFLAGS) $^

run: ./$(EXECUTABLE)
	./$(EXECUTABLE)	${ARGS}

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *~
