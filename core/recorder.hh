/* recorder.hh
 * Cube operation recorder
 * Create by	@laekov	at	10.21/2016
 * Under GPLv3
 */
#ifndef RECORDER_HH
#define RECORDER_HH

#include <cstdio>

class StepRecorder {
	private:
		FILE* outf;

	public:
		int faces[6], flag;
		StepRecorder();
		~StepRecorder();
		StepRecorder(const char*);
		void push(const char);
};
#endif

