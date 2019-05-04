#
# Created  by TRJW

INCLUDEDIR = ../headers/
CXXFLAGS   = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors
EXECUTABLES = integerConstuctor

vpath %.h $(INCLUDEDIR)

all: $(EXECUTABLES)


%Constuctor: %.cpp integer.o
	c++ $(CXXFLAGS) integer.o $@.cpp -o $@ -lboost_unit_test_framework

%.o : %.cpp %.h
	c++ $(CXXFLAGS) -c $^

clean:
	rm -f $(OUTPUTS) $(EXECUTABLES)
