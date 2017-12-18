PROGS = Lapl-EF2d

all:$(PROGS)
	
Lapl-EF2d:Lapl-EF2d.o EF2d-base.o GC.o 
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS) $(LIBS) 
#	$(CXX) Lapl-EF2d.o EF2d-base.o -o Lapl-EF2d 
clean:
		-rm -r $(PROGS) *.o *.dDSYM toto.gp 
# les dependances 
Lapl-EF2d.o: EF2d-base.hpp R2.hpp GC.h 
EF2d-base.o: EF2d-base.hpp R2.hpp GC.h
GC.o:GC.h

run: $(PROGS)
	./$(PROGS)
