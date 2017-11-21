CXX=g++
CXXFLAGS=-c -Wall

SOURCES=point.cpp tp2_1.cpp tp2_1_4.cpp tp2_2.cpp tp2_3_1.cpp tp2_3_2.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=tp2

all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^

1: point.o tp2_1.o
	$(CXX) $^ -o $(EXECUTABLE)

1.4: point.o tp2_1_4.o
	$(CXX) $^ -o $(EXECUTABLE)

2.1: point.o tp2_1.o
	$(CXX) $^ -o $(EXECUTABLE)

3.1: point.o tp2_3_1.o
	$(CXX) $^ -o $(EXECUTABLE)

3.2: point.o tp2_3_2.o
	$(CXX) $^ -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *~
