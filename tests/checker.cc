#include <iostream>

/* cube.hh
 * Cube class definations
 * Create by	@laekov	at	10.21/2016
 * Under GPLv3
 */
#ifndef CUBE_HH
#define CUBE_HH

#include <cstdio>
#include <string>

#ifndef _l
#	define _l (long long int)
#endif

class RubikCube {
	private: 
		int a[54];

		/* turns
		 * change view sides */
		RubikCube turnUp(int = 0);
		RubikCube turnDown(int = 0);
		RubikCube turnLeft(int = 0);
		RubikCube turnRight(int = 0);
		RubikCube turnClock(int = 0);
		RubikCube turnAntiClock(int = 0);

		/* vertical rotations
		 * front view
		 * rotate the left / right column up or down */
		RubikCube vRotRU(int = 0);
		RubikCube vRotRD(int = 0);
		RubikCube vRotLU(int = 0);
		RubikCube vRotLD(int = 0);

		/* horizon rotations
		 * front view
		 * rotate the top / button row left or right */
		RubikCube hRotTL(int = 0);
		RubikCube hRotTR(int = 0);
		RubikCube hRotBL(int = 0);
		RubikCube hRotBR(int = 0);

	public:
		/* constructors */
		RubikCube();
		RubikCube(int x);
		RubikCube(const RubikCube&);
		RubikCube operator =(const RubikCube&);

		/* basic */
		void init();
		int get(int) const;
		int operator [](int) const;
		void set(int, int);
		void read(FILE*);

		/* operation shell */
		RubikCube rot(const char, int = 0);
		RubikCube rot(std::string, int = 0);

		/* debugs */
		void print(FILE*);
		void workPrint(FILE*);
};
#endif
/* cube.cc
 * Cube class functions
 * Create by	@laekov	at	10.21/2016
 * Under GPLv3
 */
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <string>

RubikCube::RubikCube(int v) {
	memset(this->a, v, sizeof(this->a));
}
RubikCube::RubikCube() {
	this->init();
}
RubikCube::RubikCube(const RubikCube& x) {
	for (int i = 0; i < 54; ++ i) {
		this->a[i] = x.get(i);
	}
}
RubikCube RubikCube::operator =(const RubikCube& x) {
	for (int i = 0; i < 54; ++ i) {
		this->a[i] = x.get(i);
	}
	return *this;
}

void RubikCube::init() {
	for (int i = 0; i < 54; ++ i) {
		a[i] = i / 9;
	}
}

int RubikCube::get(int x) const {
	return (x >= 0 && x < 54) ? a[x] : -1;
} 
int RubikCube::operator [](int x) const {
	return this->get(x);
}
void RubikCube::set(int x, int v) { if (x >= 0 && x < 54 && v >= 0 && v < 6) {
		a[x] = v;
	}
}

/* map for a 3*3 matrix rotation */
/* rotate clockwise */
const int kMatRotC[9] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
int matRotC(int x) {
	return kMatRotC[x % 9] + 9 * (x / 9);
}
/* rotate counter-clockwise */
const int kMatRotA[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
int matRotA(int x) {
	return kMatRotA[x % 9] + 9 * (x / 9);
}
int mapTransUp(int x) {
	switch (x / 9) {
		case 0:
			return 44 - x;
		case 1:
			return matRotA(x);
		case 2:
			return x - 18;
		case 3:
			return matRotC(x);
		case 4: 
			return 89 - x;
		case 5: 
			return x - 27;
		default:
			return -1;
	};
}
int mapTransLeft(int x) {
	switch (x / 9) {
		case 0:
			return matRotC(x);
		case 1:
			return x + 27;
		case 2: case 3: case 4:
			return x - 9;
		case 5:
			return matRotA(x);
		default:
			return -1;
	};
}
int mapHRotTL(int x) {
	switch (x / 9) {
		case 0:
			return matRotC(x);
		case 1:
			return (x % 9 < 3) ? x + 27 : x;
		case 2: case 3: case 4:
			return (x % 9 < 3) ? x - 9 : x;
		case 5:
			return x;
		default:
			return -1;
	};
}

RubikCube RubikCube::turnUp(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(i), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnDown(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(mapTransUp(mapTransUp(i))), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnLeft(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransLeft(i), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnRight(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransLeft(mapTransLeft(mapTransLeft(i))), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnClock(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(mapTransUp(mapTransUp(mapTransLeft(mapTransUp(i))))), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnAntiClock(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(mapTransUp(mapTransUp(mapTransLeft(mapTransLeft(mapTransLeft(mapTransUp(i))))))), this->a[i]);
	}
	return res;
}

RubikCube RubikCube::vRotRU(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	res = res.turnAntiClock();
	res = res.hRotTL();
	res = res.turnClock();
	return res;
}
RubikCube RubikCube::vRotRD(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	res = res.turnAntiClock();
	res = res.hRotTR();
	res = res.turnClock();
	return res;
}
RubikCube RubikCube::vRotLU(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	res = res.turnClock();
	res = res.hRotTR();
	res = res.turnAntiClock();
	return res;
}
RubikCube RubikCube::vRotLD(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	res = res.turnClock();
	res = res.hRotTL();
	res = res.turnAntiClock();
	return res;
}

RubikCube RubikCube::hRotTL(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapHRotTL(i), a[i]);
	}
	return res;
}
RubikCube RubikCube::hRotTR(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapHRotTL(mapHRotTL(mapHRotTL(i))), a[i]);
	}
	return res;
}
RubikCube RubikCube::hRotBL(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	res = res.turnClock().turnClock();
	res = res.hRotTR();
	res = res.turnClock().turnClock();
	return res;
}
RubikCube RubikCube::hRotBR(int needRecord) {
	if (needRecord) {
	}
	RubikCube res(*this);
	res = res.turnClock().turnClock();
	res = res.hRotTL();
	res = res.turnClock().turnClock();
	return res;
}

void inColor(FILE* fileO, int x = -1) {
	if (x > -1) {
		fprintf(fileO, "\33[%dm%c", x + 31, x + 48);
	} else {
		fprintf(fileO, "\33[%dm", x + 31);
	}
}
char num2char(int x) {
	static const char map[] = "RGBOWY";
	return map[x];
}
void RubikCube::print(FILE* fou) {
	for (int i = 0; i < 54; ++ i) {
		fprintf(fou, "%c", num2char(this->get(i)));
		if (i % 9 == 8) {
			fputc(10, fou);
		}
	}
}

RubikCube RubikCube::rot(const char cmdc, int noPrint) {
	switch (cmdc) {
		case 'q':
			return this->vRotLU(!noPrint);
		case 'a':
			return this->vRotLD(!noPrint);
		case 'r':
			return this->vRotRU(!noPrint);
		case 'f':
			return this->vRotRD(!noPrint);
		case '2':
			return this->hRotTL(!noPrint);
		case '4':
			return this->hRotTR(!noPrint);
		case 'z':
			return this->hRotBL(!noPrint);
		case 'c':
			return this->hRotBR(!noPrint);
		case 'i':
			return this->turnUp(!noPrint);
		case 'k':
			return this->turnDown(!noPrint);
		case 'u':
			return this->turnLeft(!noPrint);
		case 'o':
			return this->turnRight(!noPrint);
		case 'j':
			return this->turnAntiClock(!noPrint);
		case 'l':
			return this->turnClock(!noPrint);
		default:
			return *this;
	}
}
RubikCube RubikCube::rot(std::string a, int noPrint) {
	RubikCube res(*this);
	for (int i = 0, len = a.length(); i < len; ++ i) {
		res = res.rot(a[i], noPrint);
	}
	return res;
}

int char2num(char x) {
	switch (x) {
		case 'R':
		   	return 0;
		case 'G':
			return 1;
		case 'B':
			return 2;
		case 'O':
			return 3;
		case 'W':
			return 4;
		case 'Y':
			return 5;
		default: 
			return x - 48;
	}
}

char* nextChar(char* p) {
	for (++ p; *p && !isupper(*p) && !isdigit(*p); ++ p);
	return p;
}

void RubikCube::read(FILE* fin) {
	char buf[233], *bp;
	fread(buf, sizeof(char), sizeof(buf), fin);
	bp = buf;
	for (int i = 18; i < 27; ++ i, bp = nextChar(bp)) {
		this->a[i] = char2num(*bp);
	}
	for (int i = 36; i < 45; ++ i, bp = nextChar(bp)) {
		this->a[i] = char2num(*bp);
	}
	for (int i = 27; i < 36; ++ i, bp = nextChar(bp)) {
		this->a[i] = char2num(*bp);
	}
	for (int i = 9; i < 18; ++ i, bp = nextChar(bp)) {
		this->a[i] = char2num(*bp);
	}
	for (int i = 0; i < 9; ++ i, bp = nextChar(bp)) {
		this->a[i] = char2num(*bp);
	}
	for (int i = 45; i < 54; ++ i, bp = nextChar(bp)) {
		this->a[i] = char2num(*bp);
	}
}

RubikCube readCubeFromFile() {
	char fileName[123]("cube.in");
	FILE* fin(fopen(fileName, "r"));
	RubikCube res;
	if (fin) {
		res.read(fin);
		fclose(fin);
	} else {
		std::cout << "Wrong file name\n";
	}
	return res;
}

std::string getCmd() {
	std::string buf;
	if (!(std::cin >> buf)) {
		return "";
	}
	if (buf == "R") {
		return "r";
	} else if (buf == "Ri") {
		return "f";
	} else if (buf == "L") {
		return "a";
	} else if (buf == "Li") {
		return "q";
	} else if (buf == "B") {
		return "uro";
	} else if (buf == "Bi") {
		return "ufo";
	} else if (buf == "D") {
		return "c";
	} else if (buf == "Di") {
		return "z";
	} else if (buf == "F") {
		return "oru";
	} else if (buf == "Fi") {
		return "ofu";
	} else if (buf == "U") {
		return "2";
	} else if (buf == "Ui") {
		return "4";
	} else {
		return "";
	}
}

std::string colors[6] = {
	"Red", "Green", "Blue", "Orange", "White", "Yellow"	
};
char colorsl[] = "RGBOWY";

void printPDSingle(RubikCube c, int x) {
	std::cout << colors[c.get(x + 4)] << std::endl;
	for (int i = x; i < x + 9; ++ i) {
		std::cout.put(colorsl[c.get(i)]);
		if (i % 3 == 2) {
			std::cout.put(10);
		}
	}
}

void printPD(RubikCube c) {
	static const int seq[] = { 18, 36, 27, 9, 0, 45 };
	for (int i = 0; i < 6; ++ i) {
		printPDSingle(c, seq[i]);
	}
}

int main() {
	RubikCube c;
	c = readCubeFromFile();
	printPD(c);
	std::string rotCmd;
	freopen("cube.out", "r", stdin);
	while ((rotCmd = getCmd()), rotCmd.length()) {
		c.print(stderr);
		c = c.rot(rotCmd);
		printPD(c);
	}
}

