/* cube.hh
 * Cube class definations
 * Create by	@laekov	at	10.21/2016
 * Under GPLv3
 */
#ifndef CUBE_HH
#define CUBE_HH

#include <cstdio>

#ifndef _l
#	define _l (long long int)
#endif

#include "recorder.hh"

class RubikCube {
	private: 
		int a[54];
		StepRecorder* rec;

	public:
		/* constructors */
		RubikCube();
		RubikCube(int x);
		RubikCube(const RubikCube&);
		RubikCube operator =(const RubikCube&);

		/* basic */
		void init();
		void setRecorder(StepRecorder* x);
		StepRecorder* getRecorder() const;
		void addRecord(char x);
		int get(int) const;
		void set(int, int);

		/* hash */
		int hash() const;

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

		/* debugs */
		void print(FILE*);
};
#endif
