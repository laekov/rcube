/* edge.hh
 * Cube edge class definations
 * Create by	@laekov	at	10.22/2016
 * Under GPLv3
 */
#ifndef EDGE_HH
#define EDGE_HH
class EdgeCube {
	public:
		int a[3];
		EdgeCube();
		EdgeCube(int, int);
		bool operator ==(const EdgeCube&) const;
};
#endif

