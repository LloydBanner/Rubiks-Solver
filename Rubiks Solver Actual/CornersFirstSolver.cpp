#include "stdafx.h"
#include "CornersFirstSolver.h"


CornersFirstSolver::CornersFirstSolver(){
}

void CornersFirstSolver::solveBottomCorners() {
	char colourTop = cubeToSolve.top.getPos(1, 1);

	bool topCornersCorrect = false;
	while (!topCornersCorrect) {
		char colour1;
		char colour2;
		char colour3;

		//bottom front right
		colour1 = cubeToSolve.front.getPos(2, 2);
		colour2 = cubeToSolve.rightSide.getPos(2, 0);
		colour3 = cubeToSolve.bottom.getPos(0, 2);

		bool hasTopPiece = false;
		char colourToCheck1;
		char colourToCheck2;

		//Count stops infinte loops in the while sections. I'm not 100% sure what's causing them at the moment
		int count = 6;
		if (colourTop == colour1) {
			colourToCheck1 = colour2;
			colourToCheck2 = colour3;
			hasTopPiece = true;
		}
		else if (colourTop == colour2) {
			colourToCheck1 = colour1;
			colourToCheck2 = colour3;
			hasTopPiece = true;
		}
		else if (colourTop == colour3) {
			colourToCheck1 = colour1;
			colourToCheck2 = colour2;
			hasTopPiece = true;
		}
		if (hasTopPiece) {
			if (colourToCheck1 == cubeToSolve.front.getPos(1, 1)) {
				if (colourToCheck2 == cubeToSolve.rightSide.getPos(1, 1)) {
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doRPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doR(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
				else {
					cubeToSolve.doDPrime(1);
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doFPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doF(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
			}
			else if (colourToCheck1 == cubeToSolve.rightSide.getPos(1, 1)) {
				if (colourToCheck2 == cubeToSolve.front.getPos(1, 1)) {
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doRPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doR(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
				else {
					cubeToSolve.doD(1);
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doBPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doB(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
			}
			else if (colourToCheck1 == cubeToSolve.leftSide.getPos(1, 1)) {
				if (colourToCheck2 == cubeToSolve.front.getPos(1, 1)) {
					cubeToSolve.doDPrime(1);
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doFPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doF(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
				else {
					cubeToSolve.doD(2);
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doLPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doL(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
			}
			else if (colourToCheck1 == cubeToSolve.back.getPos(1, 1)) {
				if (colourToCheck2 == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doD(2);
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doLPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doL(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
				else {
					cubeToSolve.doD(1);
					while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
						cubeToSolve.doBPrime(1);
						cubeToSolve.doDPrime(1);
						cubeToSolve.doB(1);
						cubeToSolve.doD(1);
						count--;
					}
				}
			}
		}

		//top front right
		colour1 = cubeToSolve.front.getPos(0, 2);
		colour2 = cubeToSolve.rightSide.getPos(0, 0);
		colour3 = cubeToSolve.top.getPos(2, 2);
		if (colourTop == colour1 || colourTop == colour2) {
			cubeToSolve.doRPrime(1);
			cubeToSolve.doDPrime(1);
			cubeToSolve.doR(1);
		}
		else if (colourTop == colour3) {
			bool dontMove = (colour1 == cubeToSolve.front.getPos(1, 1) && colour2 == cubeToSolve.rightSide.getPos(1, 1));
			if (!dontMove) {
				cubeToSolve.doRPrime(1);
				cubeToSolve.doDPrime(1);
				cubeToSolve.doR(1);
			}
		}

		//Are corners in the right positions?
		bool backLeftCorrect = false;
		bool backRightCorrect = false;
		bool frontLeftCorrect = false;
		bool frontRightCorrect = false;
		if (colourTop == cubeToSolve.top.getPos(0, 0)) {
			if (cubeToSolve.leftSide.getPos(0, 0) == cubeToSolve.leftSide.getPos(1, 1)) {
				if (cubeToSolve.back.getPos(0, 2) == cubeToSolve.back.getPos(1, 1)) {
					backLeftCorrect = true;
				}
			}
		}
		if (colourTop == cubeToSolve.top.getPos(0, 2)) {
			if (cubeToSolve.rightSide.getPos(0, 2) == cubeToSolve.rightSide.getPos(1, 1)) {
				if (cubeToSolve.back.getPos(0, 0) == cubeToSolve.back.getPos(1, 1)) {
					backRightCorrect = true;
				}
			}
		}
		if (colourTop == cubeToSolve.top.getPos(2, 0)) {
			if (cubeToSolve.leftSide.getPos(0, 2) == cubeToSolve.leftSide.getPos(1, 1)) {
				if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.front.getPos(1, 1)) {
					frontLeftCorrect = true;
				}
			}
		}
		if (colourTop == cubeToSolve.top.getPos(2, 2)) {
			if (cubeToSolve.rightSide.getPos(0, 0) == cubeToSolve.rightSide.getPos(1, 1)) {
				if (cubeToSolve.front.getPos(0, 2) == cubeToSolve.front.getPos(1, 1)) {
					frontRightCorrect = true;
				}
			}
		}
		if (backLeftCorrect && backRightCorrect && frontLeftCorrect && frontRightCorrect) {
			topCornersCorrect = true;
		}
		cubeToSolve.rotateCubeRight(1);
	}
	// May not need to rotate
	cubeToSolve.rotateCubeUp(2);
}

bool CornersFirstSolver::isSolutionValid() {
	bool valid = true;

	char colourFront = cubeToSolve.front.getPos(1, 1);
	for (int i = 0; i < cubeToSolve.height; i++) {
		for (int j = 0; j < cubeToSolve.width; j++) {
			if (colourFront != cubeToSolve.front.getPos(i, j)) {
				valid = false;
			}
		}
	}
	char colourBack = cubeToSolve.back.getPos(1, 1);
	for (int i = 0; i < cubeToSolve.height; i++) {
		for (int j = 0; j < cubeToSolve.width; j++) {
			if (colourBack != cubeToSolve.back.getPos(i, j)) {
				valid = false;
			}
		}
	}
	char colourLeft = cubeToSolve.leftSide.getPos(1, 1);
	for (int i = 0; i < cubeToSolve.height; i++) {
		for (int j = 0; j < cubeToSolve.width; j++) {
			if (colourLeft != cubeToSolve.leftSide.getPos(i, j)) {
				valid = false;
			}
		}
	}
	char colourRight = cubeToSolve.rightSide.getPos(1, 1);
	for (int i = 0; i < cubeToSolve.height; i++) {
		for (int j = 0; j < cubeToSolve.width; j++) {
			if (colourRight != cubeToSolve.rightSide.getPos(i, j)) {
				valid = false;
			}
		}
	}
	char colourTop = cubeToSolve.top.getPos(1, 1);
	for (int i = 0; i < cubeToSolve.height; i++) {
		for (int j = 0; j < cubeToSolve.width; j++) {
			if (colourTop != cubeToSolve.top.getPos(i, j)) {
				valid = false;
			}
		}
	}
	char colourBottom = cubeToSolve.bottom.getPos(1, 1);
	for (int i = 0; i < cubeToSolve.height; i++) {
		for (int j = 0; j < cubeToSolve.width; j++) {
			if (colourBottom != cubeToSolve.bottom.getPos(i, j)) {
				valid = false;
			}
		}
	}

	return valid;
}

void CornersFirstSolver::setCube(RubiksCube cube) {
	cubeToSolve = cube;
}

RubiksCube CornersFirstSolver::getCube() {
	return cubeToSolve;
}

CornersFirstSolver::~CornersFirstSolver(){
}
