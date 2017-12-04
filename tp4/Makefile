PROGS = Lapl-EF1d

all:$(PROGS)
	
Lapl-EF1d:Lapl-EF1d.o EF1d-base.o GC.o 
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS) $(LIBS) 
#	$(CXX) Lapl-EF1d.o EF1d-base.o -o Lapl-EF1d 
clean:
	-rm -r $(PROGS) *.o *.dDSYM toto.gp 

run:
	./$(PROGS) mesh4.msh

# les dependances 
Lapl-EF1d.o: EF1d-base.hpp R1.hpp GC.h 
EF1d-base.o: EF1d-base.hpp R1.hpp GC.h
GC.o:GC.h		
