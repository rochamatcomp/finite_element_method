CXX=g++
CXXFLAGS=-c -Wall

SOURCES=matR2.cpp R2.cpp tp3_1_1.cpp tp3_1_3.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=tp3

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^

1.1: R2.o tp3_1_1.o
	$(CXX) $^ -o $(EXECUTABLE)

1.3: R2.o matR2.o tp3_1_3.o
	$(CXX) $^ -o $(EXECUTABLE)

#2.3:
#	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) 

run:
	./$(EXECUTABLE)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *~
