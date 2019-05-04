
INCLUDEDIR = ../headers/
CXXFLAGS   = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors
OUTPUTS = integer.o
EXECUTABLES = integer

vpath %.h $(INCLUDEDIR)


all: $(EXECUTABLES)

%integer: %integer.cpp integer.o
	g++ $(CXXFLAGS) $@.cpp integer.o -o $@

%.o : %.cpp %.h
	g++ $(CXXFLAGS) -c $^

clean:
	rm -f $(OUTPUTS) $(EXECUTABLES)
