#include <cstdio>

#include "../core/cube.hh"
#include "../core/recorder.hh"
#include "../ai/ai.hh"

int main() {
	RubikCube c;
	StepRecorder r("cube.out");
	c.init();
	c.read(fopen("cube.in", "r"));
	c.setRecorder(&r);
	c = aiRecover(c);
}
