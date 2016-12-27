/* pd/recorder.cc
 * Cube recorder in formal format
 * Created by	@laekov at 12.20/2016
 * Under GPLv3
 */
#include "./recorder.hh"
#include <cstdio>
#include <cstring>
#include <algorithm>

StepRecorder::StepRecorder() {
	this->flag = 0;
	for (int i = 0; i < 6; ++ i) {
		this->faces[i] = i;
	}
	this->outf = 0;
}

StepRecorder::~StepRecorder() {
	if (this->outf) {
		fputc(10, this->outf);
		fclose(this->outf);
	}
}

StepRecorder::StepRecorder(const char* fileName) {
	for (int i = 0; i < 6; ++ i) {
		faces[i] = i;
	}
	if (!strcmp(fileName, "pipe")) {
		this->outf = stdout;
	} else {
		this->outf = fopen(fileName, "w");
	}
}

void lLoopArr4(int* a, const int* o) {
	int tmp(a[o[0]]);
	for (int i = 0; i < 3; ++ i) {
		a[o[i]] = a[o[i + 1]];
	}
	a[o[3]] = tmp;
}

const int loopOrder[6][4] = {
	{ 1, 2, 3, 4 }, // 0 -> u
	{ 0, 2, 5, 4 }, // 1 -> i
	{ 4, 3, 2, 1 }, // 2 -> o
	{ 3, 5, 1, 0 }, // 3 -> j
	{ 2, 0, 4, 5 }, // 4 -> k
	{ 3, 0, 1, 5 }  // 5 -> l
};
const char orderMap[] = "uiojkl";

const char faceCenters[] = "ULFRBD";

void rc2pd(const char x, int* faces, char* res) {
	res[0] = res[1] = res[2] = 0;
	switch (x) {
		case 'q':
			res[1] = 'i';
		case 'a':
			res[0] = faceCenters[faces[1]];
			return;
		case '4':
			res[1] = 'i';
		case '2':
			res[0] = faceCenters[faces[0]];
			return;
		case 'f':
			res[1] = 'i';
		case 'r':
			res[0] = faceCenters[faces[3]];
			return;
		case 'z':
			res[1] = 'i';
		case 'c':
			res[0] = faceCenters[faces[5]];
			return;
	}
}

void StepRecorder::push(const char x) {
	int loopI(std::find(orderMap, orderMap + 6, x) - orderMap);
	if (loopI < 6) {
		lLoopArr4(this->faces, loopOrder[loopI]);
	} else {
		if (!this->outf) {
			return;
		}
		char res[5]("");
		rc2pd(x, this->faces, res);
		if (res[0] && this->outf) {
			fprintf(outf, "%s ", res);
		}
	}
}

