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

#include "cube.hh"

const int kCubeHashMod = 998244353;

RubikCube::RubikCube(int v) {
	memset(this->a, v, sizeof(this->a));
	this->rec = 0;
}
RubikCube::RubikCube() {
	this->init();
	this->rec = 0;
}
RubikCube::RubikCube(const RubikCube& x) {
	for (int i = 0; i < 54; ++ i) {
		this->a[i] = x.get(i);
	}
	this->rec = x.getRecorder();
}
RubikCube RubikCube::operator =(const RubikCube& x) {
	for (int i = 0; i < 54; ++ i) {
		this->a[i] = x.get(i);
	}
	this->rec = x.getRecorder();
	return *this;
}

void RubikCube::init() {
	for (int i = 0; i < 54; ++ i) {
		a[i] = i / 9;
	}
}
void RubikCube::setRecorder(StepRecorder* x) {
	this->rec = x;
}
StepRecorder* RubikCube::getRecorder() const {
	return this->rec;
}
void RubikCube::addRecord(char x) {
	if (this->rec) {
		this->rec->push(x);
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

int RubikCube::hash() const {
	int s(0);
	for (int i = 0; i < 54; ++ i) {
		s = (_l s * 7 + a[i])% kCubeHashMod;
	}
	return s;
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
	};
}

RubikCube RubikCube::turnUp(int needRecord) {
	if (needRecord) {
		this->addRecord('u');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(i), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnDown(int needRecord) {
	if (needRecord) {
		this->addRecord('d');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(mapTransUp(mapTransUp(i))), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnLeft(int needRecord) {
	if (needRecord) {
		this->addRecord('l');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransLeft(i), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnRight(int needRecord) {
	if (needRecord) {
		this->addRecord('r');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransLeft(mapTransLeft(mapTransLeft(i))), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnClock(int needRecord) {
	if (needRecord) {
		this->addRecord('c');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(mapTransUp(mapTransUp(mapTransLeft(mapTransUp(i))))), this->a[i]);
	}
	return res;
}
RubikCube RubikCube::turnAntiClock(int needRecord) {
	if (needRecord) {
		this->addRecord('a');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapTransUp(mapTransUp(mapTransUp(mapTransLeft(mapTransLeft(mapTransLeft(mapTransUp(i))))))), this->a[i]);
	}
	return res;
}

RubikCube RubikCube::vRotRU(int needRecord) {
	if (needRecord) {
		this->addRecord('R');
	}
	RubikCube res(*this);
	res = res.turnAntiClock();
	res = res.hRotTL();
	res = res.turnClock();
	return res;
}
RubikCube RubikCube::vRotRD(int needRecord) {
	if (needRecord) {
		this->addRecord('F');
	}
	RubikCube res(*this);
	res = res.turnAntiClock();
	res = res.hRotTR();
	res = res.turnClock();
	return res;
}
RubikCube RubikCube::vRotLU(int needRecord) {
	if (needRecord) {
		this->addRecord('Q');
	}
	RubikCube res(*this);
	res = res.turnClock();
	res = res.hRotTR();
	res = res.turnAntiClock();
	return res;
}
RubikCube RubikCube::vRotLD(int needRecord) {
	if (needRecord) {
		this->addRecord('A');
	}
	RubikCube res(*this);
	res = res.turnClock();
	res = res.hRotTL();
	res = res.turnAntiClock();
	return res;
}

RubikCube RubikCube::hRotTL(int needRecord) {
	if (needRecord) {
		this->addRecord('2');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapHRotTL(i), a[i]);
	}
	return res;
}
RubikCube RubikCube::hRotTR(int needRecord) {
	if (needRecord) {
		this->addRecord('4');
	}
	RubikCube res(*this);
	for (int i = 0; i < 54; ++ i) {
		res.set(mapHRotTL(mapHRotTL(mapHRotTL(i))), a[i]);
	}
	return res;
}
RubikCube RubikCube::hRotBL(int needRecord) {
	if (needRecord) {
		this->addRecord('Z');
	}
	RubikCube res(*this);
	res = res.turnClock().turnClock();
	res = res.hRotTR();
	res = res.turnClock().turnClock();
	return res;
}
RubikCube RubikCube::hRotBR(int needRecord) {
	if (needRecord) {
		this->addRecord('C');
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
void RubikCube::print(FILE* fileO) {
	for (int i = 0; i < 3; ++ i) {
		for (int j = 0; j < 3; ++ j) {
			fputc(32, fileO);
		}
		for (int j = 0; j < 3; ++ j) {
			inColor(fileO, this->a[i * 3 + j]);
		}
		fputc(10, fileO);
	}
	for (int i = 0; i < 3; ++ i) {
		for (int j = 0; j < 4; ++ j) {
			for (int k = 0; k < 3; ++ k) {
				inColor(fileO, this->a[(j + 1) * 9 + i * 3 + k]);
			}
		}
		fputc(10, fileO);
	}
	for (int i = 0; i < 3; ++ i) {
		for (int j = 0; j < 3; ++ j) {
			fputc(32, fileO);
		}
		for (int j = 0; j < 3; ++ j) {
			inColor(fileO, this->a[45 + i * 3 + j]);
		}
		fputc(10, fileO);
	}
	inColor(fileO, -31);
}

RubikCube RubikCube::rot(const char cmdc) {
	switch (cmdc) {
		case 'q':
			return this->vRotLU(1);
		case 'a':
			return this->vRotLD(1);
		case 'r':
			return this->vRotRU(1);
		case 'f':
			return this->vRotRD(1);
		case '2':
			return this->hRotTL(1);
		case '4':
			return this->hRotTR(1);
		case 'z':
			return this->hRotBL(1);
		case 'c':
			return this->hRotBR(1);
		case 'i':
			return this->turnUp(1);
		case 'k':
			return this->turnDown(1);
		case 'u':
			return this->turnLeft(1);
		case 'o':
			return this->turnRight(1);
		case 'j':
			return this->turnAntiClock(1);
		case 'l':
			return this->turnClock(1);
		default:
			return *this;
	}
}
RubikCube RubikCube::rot(std::string a) {
	RubikCube res(*this);
	for (int i = 0, len = a.length(); i < len; ++ i) {
		res.rot(a[i]);
	}
	return res;
}

RubikCube RubikCube::shuffle() {
	const char opList[15] = "24qarfzcjl";
	const int step = 128;
	srand(time(0));
	RubikCube res(*this);
	for (int i = 0; i < step; ++ i) {
		res = res.rot(opList[rand() % 10]);
	}
	return res;
}

CornerCube RubikCube::corner(int x) const {
	const int map[8][3] = {
		{6, 11, 18}, {8, 20, 27}, {2, 29, 36}, {0, 9, 38},
		{17, 24, 45}, {26, 33, 47}, {35, 42, 53}, {15, 44, 51}
	};
	return CornerCube(a[map[x][0]], a[map[x][1]], a[map[x][2]]);
}
EdgeCube RubikCube::edge(int x) const {
	const int map[12][2] = {
		{7, 19}, {5, 28}, {1, 37}, {3, 10},
		{14, 21}, {23, 30}, {32, 39}, {41, 12},
		{25, 46}, {34, 50}, {43, 52}, {16, 48}
	};
	return EdgeCube(a[map[x][0]], a[map[x][1]]);
}

