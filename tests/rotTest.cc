#include <cstdio>

#include "../recorder.hh"
#include "../cube.hh"

int main() {
	RubikCube* c(new RubikCube);
	c->init();
	do {
		c->print(stdout);
		char tmp[111];
		scanf("%s", tmp);
		for (char* i = tmp; *i; ++ i) {
			c = c->rot(*i);
		}
	} while (1);
}
