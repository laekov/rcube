cc=g++ -g
allo=recorder.o edge.o corner.o cube.o ai.o

all : recorder.o edge.o corner.o cube.o ai.o
	echo done

ai : all tests/recover.cc
	$(cc) $(allo) tests/recover.cc -o ai.exe

rot : all tests/rot.cc
	$(cc) $(allo) tests/rot.cc -o rot.exe

ai.o : cube.o corner.o edge.o recorder.o ai/ai.hh ai/ai.cc
	$(cc) ai/ai.cc -c

cube.o : core/recorder.hh core/cube.hh core/corner.hh core/edge.hh core/cube.cc
	$(cc) core/cube.cc -c

corner.o : core/corner.hh core/corner.cc
	$(cc) core/corner.cc -c

edge.o : core/edge.hh core/edge.cc
	$(cc) core/edge.cc -c

recorder.o : core/recorder.hh core/recorder.cc
	$(cc) core/recorder.cc -c

clean :
	rm -rf *.exe *.o *.dSYM
