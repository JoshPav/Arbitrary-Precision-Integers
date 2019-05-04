#
# Created  by TRJW

INCLUDEDIR = ../headers/
CXXFLAGS   = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors -lboost_unit_test_framework
OUTPUTS = integer.o
EXECUTABLES = integerConstuctor

vpath %.h $(INCLUDEDIR)

all: $(EXECUTABLES)


%Constuctor: %.cpp integer.o
	c++ $(CXXFLAGS) integer.o $@.cpp -o $@

%.o : %.cpp %.h
	c++ $(CXXFLAGS) -c $^

clean:
	rm -f $(OUTPUTS) $(EXECUTABLES)
