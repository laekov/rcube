cc=g++

rotTest.exe : cube.o recorder.o recorder.hh cube.hh tests/rotTest.cc
	$(cc) -g cube.o recorder.o tests/rotTest.cc -o rotTest.exe

cube.o : recorder.hh cube.hh cube.cc
	$(cc) -g cube.cc -c

recorder.o : recorder.hh recorder.cc
	$(cc) -g recorder.cc -c

clean :
	rm -rf *.exe *.o *.dSYM
