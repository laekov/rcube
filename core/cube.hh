/* cube.hh
 * Cube class definations
 * Create by	@laekov	at	10.21/2016
 * Under GPLv3
 */
#ifndef CUBE_HH
#define CUBE_HH

class RubikCube {
	private: 
		int a[54];
	public:
		/* IO
		 */
		void init();
		void read();

		/* Hash
		 */
		int hash();

		/* turns
		 * change view sides
		 */
		RubikCube turnUp();
		RubikCube turnDown();
		RubikCube turnLeft();
		RubikCube turnRight();
		RubikCube turnClock();
		RubikCube turnAntiClock();

		/* vertical rotations
		 * front view
		 * rotate the left / right column up or down
		 */
		RubikCube vRotRU();
		RubikCube vRotRD();
		RubikCube vRotLU();
		RubikCube vRotLD();

		/* horizon rotations
		 * front view
		 * rotate the top / button row left or right
		 */
		RubikCube hRotTL();
		RubikCube hRotTR();
		RubikCube hRotBL();
		RubikCube hRotBR();
};
#endif

