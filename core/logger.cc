/* pd/recorder.cc
 * Cube recorder in operation log format
 * Created by	@laekov at 12.20/2016
 * Under GPLv3
 */
#include "./recorder.hh"
#include <cstdio>
#include <cstring>
#include <algorithm>

StepRecorder::StepRecorder() {
}

StepRecorder::StepRecorder(const char*) {
}

StepRecorder::~StepRecorder() {
}

void StepRecorder::push(const char x) {
	fprintf(stderr, "%c\n", x);
}

