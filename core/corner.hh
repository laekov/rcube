/* corner.hh
 * Cube corner class definations
 * Create by	@laekov	at	10.22/2016
 * Under GPLv3
 */
#ifndef CORNER_HH
#define CORNER_HH
class CornerCube {
	public:
		int a[3];
		CornerCube();
		CornerCube(int, int, int);
		bool operator ==(const CornerCube&) const;
		bool operator !=(const CornerCube&) const;
};
#endif
