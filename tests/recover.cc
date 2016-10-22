#include <cstdio>

#include "../core/cube.hh"
#include "../ai/ai.hh"

int main() {
	RubikCube c;
	c.init();
	c = c.shuffle();
	c.print(stdout);
	c = aiRecover(c);
	c.print(stdout);
}
