#include <cstdio>

#include "../core/cube.hh"
#include "../core/recorder.hh"
#include "../ai/ai.hh"

int main() {
	RubikCube c;
	StepRecorder r("steps.out");
	c.init();
	c.setRecorder(&r);
	c = c.shuffle();
	c.print(stdout);
	c = aiRecover(c);
	c.print(stdout);
}
