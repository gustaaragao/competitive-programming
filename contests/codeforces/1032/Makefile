CXX = g++ 

CXXFLAGS =  g++ -g -O2 -std=gnu++20 -static

SOURCES := $(wildcard *.cpp)
BINARIES := $(SOURCES:.cpp=)

all: $(BINARIES) 

%: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $< 

clean: 
	rm -f $(BINARIES)