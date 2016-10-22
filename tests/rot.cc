#include <cstdio>

#include "../core/recorder.hh"
#include "../core/cube.hh"

int main() {
	RubikCube* c(new RubikCube);
	c->init();
	do {
		c->print(stdout);
		char tmp[111];
		scanf("%s", tmp);
		for (char* i = tmp; *i; ++ i) {
			*c = c->rot(*i);
			c->print(stdout);
		}
	} while (1);
}
