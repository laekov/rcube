/* recorder.cc
 * Cube operation recorder functions
 * Create by	@laekov	at	10.21/2016
 * Under GPLv3
 */
#include "recorder.hh"

#include <cstdio>

StepRecorder::StepRecorder() {
	this->outf = 0;
}
StepRecorder::StepRecorder(char* fileName) {
	this->outf = fopen(fileName, "w");
}

void StepRecorder::push(char x) {
	fprintf(stderr, "%c", x);
}

