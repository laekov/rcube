cc=g++ -g
allo=bin/recorder.o bin/edge.o bin/corner.o bin/cube.o bin/ai.o

all : recorder.o edge.o corner.o cube.o ai.o 
	echo done

fin : all tests/fin.cc 
	$(cc) $(allo) tests/fin.cc -o bin/fin.exe

ai : all tests/recover.cc 
	$(cc) $(allo) tests/recover.cc -o bin/ai.exe

rot : all tests/rot.cc 
	$(cc) $(allo) tests/rot.cc -o bin/rot.exe 

ai.o : cube.o corner.o edge.o recorder.o ai/ai.hh ai/ai.cc 
	$(cc) ai/ai.cc -c -o bin/ai.o

cube.o : core/recorder.hh core/cube.hh core/corner.hh core/edge.hh core/cube.cc 
	$(cc) core/cube.cc -c -o bin/cube.o

corner.o : core/corner.hh core/corner.cc 
	$(cc) core/corner.cc -c -o bin/corner.o

edge.o : core/edge.hh core/edge.cc 
	$(cc) core/edge.cc -c -o bin/edge.o

recorder.o : core/recorder.hh core/recorder.cc 
	$(cc) core/recorder.cc -c -o bin/recorder.o

clean :
	rm -rf bin *.exe *.o *.dSYM
