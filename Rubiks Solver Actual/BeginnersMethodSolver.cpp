#include "stdafx.h"
#include "BeginnersMethodSolver.h"


BeginnersMethodSolver::BeginnersMethodSolver(){
	char colourTop = cubeToSolve.top.getPos(1, 1);
}

void BeginnersMethodSolver::SolveCross(char colour) {
	char colourTop = cubeToSolve.top.getPos(1, 1);

	//remove incorrect whites from top
	if (colourTop == cubeToSolve.top.getPos(0, 1)) {
		if (!(cubeToSolve.back.getPos(1, 1) == cubeToSolve.back.getPos(0, 1))) {
			cubeToSolve.doBPrime(2);
		}
	}
	if (colourTop == cubeToSolve.top.getPos(1, 0)) {
		if (!(cubeToSolve.leftSide.getPos(1, 1) == cubeToSolve.leftSide.getPos(0, 1))) {
			cubeToSolve.doLPrime(2);
		}
	}
	if (colourTop == cubeToSolve.top.getPos(2, 1)) {
		if (!(cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(0, 1))) {
			cubeToSolve.doFPrime(2);
		}
	}
	if (colourTop == cubeToSolve.top.getPos(1, 2)) {
		if (!(cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 1))) {
			cubeToSolve.doRPrime(2);
		}
	}

	bool cross = false;
	while (!cross) {
		bool frontEdge = false;
		bool backEdge = false;
		bool rightEdge = false;
		bool leftEdge = false;

		//Sides
		bool topEdgesOnFront = true;
		while (topEdgesOnFront) {
			bool edge01 = true;
			bool edge10 = true;
			bool edge12 = true;
			bool edge21 = true;
			char colourEdge;

			colourEdge = cubeToSolve.front.getPos(0, 1);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.top.getPos(2, 1);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doF(2);
					cubeToSolve.doD(1);
					cubeToSolve.doR(1);
					cubeToSolve.doFPrime(1);
					cubeToSolve.doRPrime(1);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doF(1);
					cubeToSolve.doR(1);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doFPrime(1);
					cubeToSolve.doLPrime(1);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doF(2);
					cubeToSolve.doD(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.doB(1);
					cubeToSolve.doR(1);
				}
			} 
			else {
				edge01 = false;
			}
			colourEdge = cubeToSolve.front.getPos(1, 0);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.leftSide.getPos(1, 2);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doL(1);
					cubeToSolve.doD(1);
					cubeToSolve.doLPrime(1);
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doFPrime(2);
					cubeToSolve.doR(1);
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doLPrime(1);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doL(1);
					cubeToSolve.doDPrime(1);
					cubeToSolve.doLPrime(1);
					cubeToSolve.doB(2);
				}
			} 
			else {
				edge10 = false;
			}
			colourEdge = cubeToSolve.front.getPos(1, 2);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.rightSide.getPos(1, 0);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doRPrime(1);
					cubeToSolve.doDPrime(1);
					cubeToSolve.doR(1);
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doR(1);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doF(2);
					cubeToSolve.doLPrime(1);
					cubeToSolve.doFPrime(2);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doRPrime(1);
					cubeToSolve.doD(1);
					cubeToSolve.doR(1);
					cubeToSolve.doB(2);
				}
			}
			else {
				edge12 = false;
			}
			colourEdge = cubeToSolve.front.getPos(2, 1);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.bottom.getPos(0, 1);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doD(1);
					cubeToSolve.doR(1);
					cubeToSolve.doFPrime(1);
					cubeToSolve.doRPrime(1);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doFPrime(1);
					cubeToSolve.doR(1);
					cubeToSolve.doF(1);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doF(1);
					cubeToSolve.doLPrime(1);
					cubeToSolve.doFPrime(1);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doD(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.doB(1);
					cubeToSolve.doR(1);
				}
			}
			else {
				edge21 = false;
			}
			if (!edge01 && !edge10 && !edge12 && !edge21) {
				topEdgesOnFront = false;
			}
		}

		//bottom
		bool topEdgesOnBottom = true;
		while (topEdgesOnBottom) {
			bool edge01 = true;
			bool edge10 = true;
			bool edge12 = true;
			bool edge21 = true;
			char colourEdge;

			colourEdge = cubeToSolve.bottom.getPos(0, 1);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.front.getPos(2, 1);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doD(1);
					cubeToSolve.doR(2);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doDPrime(1);
					cubeToSolve.doLPrime(2);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doD(2);
					cubeToSolve.doB(1);
				}
			}
			else {
				edge01 = false;
			}
			colourEdge = cubeToSolve.bottom.getPos(1, 0);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.leftSide.getPos(2, 1);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doD(1);
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doD(2);
					cubeToSolve.doR(2);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doL(2);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doDPrime(1);
					cubeToSolve.doB(2);
				}
			}
			else {
				edge10 = false;
			}
			colourEdge = cubeToSolve.bottom.getPos(1, 2);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.rightSide.getPos(2, 1);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doDPrime(1);
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doR(2);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doD(2);
					cubeToSolve.doL(2);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doD(1);
					cubeToSolve.doB(2);
				}
			}
			else {
				edge12 = false;
			}
			colourEdge = cubeToSolve.bottom.getPos(2, 1);
			if (colourEdge == colourTop) {
				char otherColour = cubeToSolve.back.getPos(2, 1);
				if (otherColour == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doD(2);
					cubeToSolve.doF(2);
				}
				else if (otherColour == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doDPrime(1);
					cubeToSolve.doR(2);
				}
				else if (otherColour == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doD(1);
					cubeToSolve.doL(2);
				}
				else if (otherColour == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doB(2);
				}
			}
			else {
				edge21 = false;
			}
			if (!edge01 && !edge10 && !edge12 && !edge21) {
				topEdgesOnBottom = false;
			}
		}

		if (!frontEdge) {
			if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(0, 1)) {
				if (colourTop == cubeToSolve.top.getPos(2, 1)) {
					frontEdge = true;
				}
			}
		}

		if (!backEdge) {
			if (cubeToSolve.back.getPos(1, 1) == cubeToSolve.back.getPos(0, 1)) {
				if (colourTop == cubeToSolve.top.getPos(0, 1)) {
					backEdge = true;
				}
			}
		}

		if (!rightEdge) {
			if (cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 1)) {
				if (colourTop == cubeToSolve.top.getPos(1, 2)) {
					rightEdge = true;
				}
			}
		}

		if (!leftEdge) {
			if (cubeToSolve.leftSide.getPos(1, 1) == cubeToSolve.leftSide.getPos(0, 1)) {
				if (colourTop == cubeToSolve.top.getPos(1, 0)) {
					leftEdge = true;
				}
			}
		}

		if (frontEdge && backEdge && rightEdge && leftEdge) {
			cross = true;
		}
		cubeToSolve.rotateCubeRight(1);
	}
}

void BeginnersMethodSolver::setCube(RubiksCube cube) {
	cubeToSolve = cube;
}

RubiksCube BeginnersMethodSolver::getCube() {
	return cubeToSolve;
}

BeginnersMethodSolver::~BeginnersMethodSolver(){
}
