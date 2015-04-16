CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11

IDIR=../include
ODIR=../obj

_HEAD = Edge.h Point.h tetra.h Triangle.h
HEAD = $(patsubst %,$(IDIR)/%,$(_HEAD))

_OBJ1 = challenge_1_2.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = challenge_3.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

EXEC1 = challenge_1
EXEC2 = challenge_3

all: challenge_1  challenge_3

$(ODIR)/%.o : %.cpp $(HEAD)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXEC1) : $(OBJ1)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(EXEC2) : $(OBJ2)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
.PHONY: clean distclean all

clean :
	$(RM) $(ODIR)/*.o *~ core $(INCDIR)/*~
	
distclean: clean
	$(RM) main



