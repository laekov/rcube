cc=g++ -g

all : recorder.o edge.o corner.o cube.o ai.o
	echo done

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
