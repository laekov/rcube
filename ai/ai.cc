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
	if (a.corner(5) == need) { a = a.rot('z');
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
	EdgeCube need(a[13], a[22]);
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
	std::string formula("f4uq2aor");
	int tc(a[4]);
	int eqc((a[7] == tc) + (a[5] == tc) + (a[1] == tc) + (a[3] == tc));
	if (eqc == 4) {
		return a;
	}
	if (eqc == 0) {
		a = a.rot(formula);
	}
	if (a[3] == tc && a[5] == tc) {
		a = a.rot('u');
	}
	if (a[5] != tc && a[3] != tc) {
		a = a.rot(formula);
	}
	for (int i = 0; i < 4; ++ i) {
		if (a[3] == tc && a[1] == tc && a[5] != tc && a[7] != tc) {
			a = a.rot(formula);
			break;
		}
		a = a.rot('u');
	}
	return a;
}
RubikCube topPos(RubikCube a) {
	std::string formulaL("af2q4r2a4q");
	/* to recover 0, 1, 2
	 * 0-> 2-> 1-> 0 */
	std::string formulaR("fa4r2q4f2r");
	/* to recover 0, 1, 3 
	 * 0-> 1-> 3-> 0 */
	for (int i = 0; i < 4; ++ i) {
		CornerCube need[4] = {
			CornerCube(a[4], a[13], a[22]),
			CornerCube(a[4], a[22], a[31]),
			CornerCube(a[4], a[31], a[40]),
			CornerCube(a[4], a[40], a[13])
		};
		int cnt((need[0] == a.corner(0)) + (need[1] == a.corner(1)) + (need[2] == a.corner(2)) + (need[3] == a.corner(3)));
		if (cnt == 4) {
			return a;
		}
		if (cnt == 1) {
			for (int j = 0; j < 4; ++ j) {
				CornerCube need[4] = {
					CornerCube(a[4], a[13], a[22]),
					CornerCube(a[4], a[22], a[31]),
					CornerCube(a[4], a[31], a[40]),
					CornerCube(a[4], a[40], a[13])
				};
				if (need[3] == a.corner(3) && need[2] == a.corner(0)) {
					return a = a.rot(formulaL);
				}
				if (need[2] == a.corner(2) && need[3] == a.corner(1)) {
					return a = a.rot(formulaR);
				}
				a = a.rot('u');
			}
		}
		if (cnt == 2) {
			for (int j = 0; j < 4; ++ j) {
				CornerCube need[4] = {
					CornerCube(a[4], a[13], a[22]),
					CornerCube(a[4], a[22], a[31]),
					CornerCube(a[4], a[31], a[40]),
					CornerCube(a[4], a[40], a[13])
				};
				if (need[0] != a.corner(0) && need[2] != a.corner(2)) {
					return a = a.rot(formulaL).rot('4').rot(formulaR).rot("44");
				}
				a = a.rot('u');
			}
		}
		a = a.rot('2');
	}
	return a;
}

RubikCube topDir(RubikCube a) {
	std::string formulaL("a2q2a22q22");
	/* recover top corner direction
	 * rotate 0, 1, 3 clockwise */
	std::string formulaR("f4r4f44r44");
	/* recover top corner direction
	 * rotate 0, 1, 2 counter-clockwise */
	int tc(a[4]);
	if (a[6] == tc && a[8] == tc && a[2] == tc && a[0] == tc) {
		return a;
	}
	if (a[11] == tc) {
		a = a.rot(formulaL);
	}
	if (a[18] == tc) {
		a = a.rot(formulaR);
	}
	int cntD((a[8] != tc) + (a[2] != tc) + (a[0] != tc));
	if (cntD == 0) {
		return a;
	}
	if (cntD == 2) {
		if (a[8] != tc && a[0] != tc) {
			if (a[20] == tc) {
				a = a.rot('u').rot(formulaL);
			} else if (a[27] == tc) {
				a = a.rot(formulaR).rot('u');
			}
		} else {
			if (a[0] != tc) {
				a = a.rot('u');
			}
			if (a[20] == tc) {
				a = a.rot(formulaL).rot('u');
			} else if (a[27] == tc) {
				a = a.rot('o').rot(formulaR).rot("uu");
			}
		}
	}
	if (a[29] == tc) {
		return a = a.rot("uu").rot(formulaL);
	}
	if (a[36] == tc) {
		return a = a.rot('u').rot(formulaR);
	}
	return a;
}
RubikCube topEdge(RubikCube a) {
	std::string formulaL("a2q2a22q22");
	/* recover top corner direction
	 * rotate 0, 1, 3 clockwise */
	std::string formulaR("f4r4f44r44");
	/* recover top corner direction
	 * rotate 0, 1, 2 counter-clockwise */
	int cnt((a[19] == a[22]) + (a[28]  == a[31]) + (a[37] == a[40]) + (a[10] == a[13]));
	if (cnt == 4) {
		return a;
	}
	if (cnt == 0) {
		a = a.rot(formulaL).rot('o').rot(formulaR);
	}
	for (int i = 0; i < 4; ++ i) {
		if (a[19] == a[22]) {
			break;
		}
		a = a.rot('o');
	}
	if (a[28] == a[13]) {
		a = a.rot(formulaL).rot('o').rot(formulaR);
	} else if (a[10] == a[31]) {
		a = a.rot(formulaR).rot('u').rot(formulaL);
	}
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

