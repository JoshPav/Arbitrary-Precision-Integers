#
# Created  by TRJW

INCLUDEDIR = ../headers/
CXXFLAGS   = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors
EXECUTABLES = constTests compTests

vpath %.h $(INCLUDEDIR)

all: $(EXECUTABLES)

%Tests: %Tests.cpp integer.o
	c++ $(CXXFLAGS) integer.o $@.cpp -o $@ -lboost_unit_test_framework

%.o : %.cpp %.h
	c++ $(CXXFLAGS) -c $^

clean:
	rm -f $(OUTPUTS) $(EXECUTABLES)
