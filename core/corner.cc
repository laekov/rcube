/* corner.hh
 * Cube corner class functions
 * Create by	@laekov	at	10.22/2016
 * Under GPLv3
 */
#include <algorithm>

#include "corner.hh"

CornerCube::CornerCube() {
	this->a[0] = this->a[1] = this->a[2] = -1;
}
CornerCube::CornerCube(int x, int y, int z) {
	this->a[0] = x;
	this->a[1] = y;
	this->a[2] = z;
	std::sort(this->a, this->a + 3);
}
bool CornerCube::operator ==(const CornerCube& x) const {
	for (int i = 0; i < 3; ++ i) {
		if (this->a[i] != x.a[i]) {
			return 0;
		}
	}
	return 1;
}
