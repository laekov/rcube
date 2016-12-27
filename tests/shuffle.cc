#include <cstdio>
#include "../core/cube.hh"

char colorsl[] = "RGBOWY";

void printPDSingle(RubikCube c, int x, FILE* fou) {
	for (int i = x; i < x + 9; ++ i) {
		fputc(colorsl[c.get(i)], fou);
		if (i % 3 == 2) {
			fputc(10, fou);
		}
	}
}

void printPD(RubikCube c, FILE* fou) {
	static const int seq[] = { 18, 36, 27, 9, 0, 45 };
	for (int i = 0; i < 6; ++ i) {
		printPDSingle(c, seq[i], fou);
	}
}

int main() {
	RubikCube c;
	FILE* fou(fopen("cube.in", "w"));
	c = c.shuffle(90);
	printPD(c, fou);
	fclose(fou);
}
