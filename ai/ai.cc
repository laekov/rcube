/* ai.cc
 * AI functions
 * Create by	@laekov	at	10.22/2016
 * Under GPLv3
 */
#include <string>

#include "../core/cube.hh"

RubikCube bottomEdge(RubikCube a) {
	int tc(a[4]);
	EdgeCube need(a[4], a[22]);
	if (a.edge(0) == need && a[7] == tc) {
		return a;
	}
	if (a.edge(0) == need) {
		a = a.rot("offu");
	}
	if (a.edge(1) == need) {
		a = a.rot("ff");
	}
	if (a.edge(2) == need) {
		a = a.rot("uffo");
	}
	if (a.edge(3) == need) {
		a = a.rot("aa");
	}
	if (a.edge(4) == need) {
		a = a.rot("acq");
	}
	if (a.edge(5) == need) {
		a = a.rot("fcr");
	}
	if (a.edge(6) == need) {
		a = a.rot("rcf");
	}
	if (a.edge(7) == need) {
		a = a.rot("qza");
	}
	if (a.edge(8) == need) {
		a = a.rot('z');
	}
	if (a.edge(9) == need) {
		a = a.rot("zz");
	}
	if (a.edge(10) == need) {
		a = a.rot('c');
	}
	if (a.edge(11) == need) {
		if (a[16] == tc) {
			a = a.rot("qorua");
		} else if (a[48] == tc) {
			a = a.rot("cuqqo");
		}
	}
	return a;
}
RubikCube bottomCross(RubikCube a) {
	for (int i = 0; i < 4; ++ i) {
		a = bottomEdge(a).rot('u');
	}
	return a;
}

RubikCube bottomCornerSgl(RubikCube a) {
	int tc(a[4]);
	CornerCube need(a[4], a[13], a[22]);
	if (a.corner(0) == need && a[6] == tc) {
		return a;
	}
	if (a.corner(0) == need) {
		a = a.rot("acq");
	}
	if (a.corner(1) == need) {
		a = a.rot("fzr");
	}
	if (a.corner(2) == need) {
		a = a.rot("rcf");
	}
	if (a.corner(3) == need) {
		a = a.rot("qza");
	}
	if (a.corner(5) == need) {
		a = a.rot('z');
	}
	if (a.corner(6) == need) {
		a = a.rot("zz");
	}
	if (a.corner(7) == need) {
		a = a.rot("c");
	}
	if (a.corner(4) == need) {
		if (a[45] == tc) {
			a = a.rot("azqzz");
		}
		if (a[17] == tc) {
			return a = a.rot("ozfcru");
		}
		if (a[24] == tc) {
			return a = a.rot("cazq");
		}
	}
	return a;
}
RubikCube bottomCorner(RubikCube a) {
	for (int i = 0; i < 4; ++ i) {
		a = bottomCornerSgl(a).rot('u');
	}
	return a;
}

RubikCube middleEdgeSgl(RubikCube a) {
	std::string ld("2or4f4uq2a");
	std::string rd("4q2a2or4fu");
	EdgeCube need(a.edge(4));
	if (a.edge(4) == need && a[21] == a[22]) {
		return a;
	}
	if (a.edge(4) == need) {
		a = a.rot(ld);
	}
	if (a.edge(5) == need) {
		a = a.rot('u').rot(ld).rot('o');
	}
	if (a.edge(6) == need) {
		a = a.rot("uu").rot(ld).rot("uu");
	}
	if (a.edge(7) == need) {
		a = a.rot('o').rot(ld).rot('u');
	}
	for (int i = 0; i < 4; ++ i) {
		if (a.edge(3) == need && a[3] == a[22]) {
			return a = a.rot(ld);
		} else if (a.edge(0) == need && a[19] == a[22]) {
			return a = a.rot(rd);
		}
		a = a.rot('4');
	}
	return a;
}
RubikCube middleEdge(RubikCube a) {
	for (int i = 0; i < 4; ++ i) {
		a = middleEdgeSgl(a).rot('u');
	}
	return a;
}

RubikCube topCross(RubikCube a) {
	std::string formula("f4uq2aof");
	return a;
}
RubikCube topPos(RubikCube a) {
	return a;
}
RubikCube topDir(RubikCube a) {
	return a;
}
RubikCube topEdge(RubikCube a) {
	return a;
}

RubikCube aiRecover(RubikCube a) {
	a = bottomCross(a);
	a = bottomCorner(a).rot("jj");
	a = middleEdge(a);
	a = topCross(a);
	a = topPos(a);
	a = topDir(a);
	a = topEdge(a);
	return a;
}

