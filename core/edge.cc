/* edge.hh
 * Cube edge class functions
 * Create by	@laekov	at	10.22/2016
 * Under GPLv3
 */
#include <algorithm>

#include "edge.hh"

EdgeCube::EdgeCube() {
	this->a[0] = this->a[1] = -1;
}
EdgeCube::EdgeCube(int x, int y) {
	this->a[0] = x;
	this->a[1] = y;
	std::sort(this->a, this->a + 2);
}
bool EdgeCube::operator ==(const EdgeCube& x) const {
	for (int i = 0; i < 2; ++ i) {
		if (this->a[i] != x.a[i]) {
			return 0;
		}
	}
	return 1;
}
bool EdgeCube::operator !=(const EdgeCube& x) const {
	return !(*this == x);
}
