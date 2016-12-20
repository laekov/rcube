cc=g++ -g
allo=bin/recorder.o bin/edge.o bin/corner.o bin/cube.o bin/ai.o

all : $(allo)
	echo done

recover : all tests/recover.cc 
	$(cc) $(allo) tests/recover.cc -o bin/recover.exe

shuffle : all tests/shuffle.cc
	$(cc) $(allo) tests/shuffle.cc -o bin/shuffle.exe

rot : all tests/rot.cc 
	$(cc) $(allo) tests/rot.cc -o bin/rot.exe 

bin/ai.o : bin/cube.o bin/corner.o bin/edge.o bin/recorder.o ai/ai.hh ai/ai.cc 
	$(cc) ai/ai.cc -c -o bin/ai.o

bin/cube.o : core/recorder.hh core/cube.hh core/corner.hh core/edge.hh core/cube.cc 
	$(cc) core/cube.cc -c -o bin/cube.o

bin/corner.o : core/corner.hh core/corner.cc 
	$(cc) core/corner.cc -c -o bin/corner.o

bin/edge.o : core/edge.hh core/edge.cc 
	$(cc) core/edge.cc -c -o bin/edge.o

bin/recorder.o : core/recorder.hh core/recorder.cc 
	$(cc) core/recorder.cc -c -o bin/recorder.o

bin/logger.o : core/recorder.hh core/logger.cc 
	$(cc) core/logger.cc -c -o bin/logger.o

clean :
	rm -rf bin/*.exe bin/*.o bin/*.dSYM
