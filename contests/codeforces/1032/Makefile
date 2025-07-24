CXX = g++ 

CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++20 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold 

SOURCES := $(wildcard *.cpp)
BINARIES := $(SOURCES:.cpp=)

all: $(BINARIES) 

%: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $< 

clean: 
	rm -f $(BINARIES)