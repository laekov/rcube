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
			switch (*i) {
				case 'p': 
					break;
				case 'q':
					*c = c->vRotLU();
					break;
				case 'a':
					*c = c->vRotLD();
					break;
				case 'r':
					*c = c->vRotRU();
					break;
				case 'f':
					*c = c->vRotRD();
					break;
				case '2':
					*c = c->hRotTL();
					break;
				case '4':
					*c = c->hRotTR();
					break;
				case 'z':
					*c = c->hRotBL();
					break;
				case 'c':
					*c = c->hRotBR();
					break;
				case 'i':
					*c = c->turnUp();
					break;
				case 'k':
					*c = c->turnDown();
					break;
				case 'u':
					*c = c->turnLeft();
					break;
				case 'o':
					*c = c->turnRight();
					break;
				case 'j':
					*c = c->turnAntiClock();
					break;
				case 'l':
					*c = c->turnClock();
					break;
			}
		}
	} while (1);
}
