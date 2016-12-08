#include <cstdio>

#include "../core/cube.hh"
#include "../core/recorder.hh"
#include "../ai/ai.hh"

int main() {
	freopen("a.in", "r", stdin);
	RubikCube c;
	// StepRecorder r("steps.out");
	c.init();
	c.read(stdin);
	// c.setRecorder(&r);
	c.print(stdout);
	c = aiRecover(c);
	c.print(stdout);
}
