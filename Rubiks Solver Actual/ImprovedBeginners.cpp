#include "stdafx.h"
#include "ImprovedBeginners.h"

//Only one rotate cube right x3 swapped for rotate cube left

ImprovedBeginners::ImprovedBeginners() {
	char colourTop = cubeToSolve.top.getPos(1, 1);
}

void ImprovedBeginners::solveCross() {
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

void ImprovedBeginners::solverTopCorners() {
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

}

void ImprovedBeginners::solveMiddleLayer() {
	cubeToSolve.rotateCubeUp(2);

	int when4Stuck = 0;
	for (int i = 0; i < 4; i++) {
		if (cubeToSolve.top.getPos(0, 0) == cubeToSolve.front.getPos(0, 1) || cubeToSolve.top.getPos(0, 0) == cubeToSolve.top.getPos(2, 1)) {
			when4Stuck++;
		}
		cubeToSolve.doU(1);
	}
	if (when4Stuck == 4) {
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doFPrime(1);
		cubeToSolve.doU(1);
		cubeToSolve.doF(1);
	}

	bool middleLayerSolved = false;
	int fails = 0;
	while (!middleLayerSolved) {
		for (int i = 0; i < 4; i++) {
			if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(0, 1)) {
				if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
					cubeToSolve.doU(1);
					cubeToSolve.doR(1);
					cubeToSolve.doUPrime(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.doUPrime(1);
					cubeToSolve.doFPrime(1);
					cubeToSolve.doU(1);
					cubeToSolve.doF(1);
				}
				else if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.leftSide.getPos(1, 1)) {
					cubeToSolve.doUPrime(1);
					cubeToSolve.doLPrime(1);
					cubeToSolve.doU(1);
					cubeToSolve.doL(1);
					cubeToSolve.doU(1);
					cubeToSolve.doF(1);
					cubeToSolve.doUPrime(1);
					cubeToSolve.doFPrime(1);

				}
			}
			else {
				fails += 1;
				if (fails == 16) {
					fails = 0;
					cubeToSolve.doU(2);
					cubeToSolve.doR(1);
					cubeToSolve.doUPrime(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.doUPrime(1);
					cubeToSolve.doFPrime(1);
					cubeToSolve.doU(1);
					cubeToSolve.doF(1);
				}
			}
			cubeToSolve.doU(1);
		}
		cubeToSolve.rotateCubeRight(1);

		bool frontSolved = false;
		bool backSolved = false;
		bool rightSolved = false;
		bool leftSolved = false;
		if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(1, 2)) {
			frontSolved = true;
		}
		if (cubeToSolve.back.getPos(1, 1) == cubeToSolve.back.getPos(1, 0) && cubeToSolve.back.getPos(1, 1) == cubeToSolve.back.getPos(1, 2)) {
			backSolved = true;
		}
		if (cubeToSolve.leftSide.getPos(1, 1) == cubeToSolve.leftSide.getPos(1, 0) && cubeToSolve.leftSide.getPos(1, 1) == cubeToSolve.leftSide.getPos(1, 2)) {
			leftSolved = true;
		}
		if (cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(1, 0) && cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(1, 2)) {
			rightSolved = true;
		}
		if (frontSolved && backSolved && rightSolved && leftSolved) {
			middleLayerSolved = true;
		}
	}
}

void ImprovedBeginners::solveFinalface() {
	char colourFace = cubeToSolve.top.getPos(1, 1);
	int numEdges = 0;

	if (colourFace == cubeToSolve.top.getPos(0, 1)) {
		numEdges++;
	}
	if (colourFace == cubeToSolve.top.getPos(1, 0)) {
		numEdges++;
	}
	if (colourFace == cubeToSolve.top.getPos(1, 2)) {
		numEdges++;
	}
	if (colourFace == cubeToSolve.top.getPos(2, 1)) {
		numEdges++;
	}

	while (numEdges < 2) {
		cubeToSolve.doF(1);
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doFPrime(1);

		if (colourFace == cubeToSolve.top.getPos(0, 1)) {
			numEdges++;
		}
		if (colourFace == cubeToSolve.top.getPos(1, 0)) {
			numEdges++;
		}
		if (colourFace == cubeToSolve.top.getPos(1, 2)) {
			numEdges++;
		}
		if (colourFace == cubeToSolve.top.getPos(2, 1)) {
			numEdges++;
		}

		if (numEdges == 0) {
			cubeToSolve.doU(1);
		}
	}

	if (numEdges == 2) {
		if (colourFace == cubeToSolve.top.getPos(0, 1)) {
			if (colourFace == cubeToSolve.top.getPos(1, 0)) {
				cubeToSolve.doF(1);
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doFPrime(1);
			}
			else if (colourFace == cubeToSolve.top.getPos(1, 2)) {
				cubeToSolve.doUPrime(1);
				cubeToSolve.doF(1);
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doFPrime(1);
			}
			else {
				cubeToSolve.doUPrime(1);
				cubeToSolve.doF(1);
				cubeToSolve.doR(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doFPrime(1);
			}
		}
		else if (colourFace == cubeToSolve.top.getPos(1, 0)) {
			if (colourFace == cubeToSolve.top.getPos(1, 2)) {
				cubeToSolve.doF(1);
				cubeToSolve.doR(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doFPrime(1);
			}
			else {
				cubeToSolve.doU(1);
				cubeToSolve.doF(1);
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doFPrime(1);
			}
		}
		else {
			cubeToSolve.doU(2);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doFPrime(1);
		}

		numEdges = 0;
		if (colourFace == cubeToSolve.top.getPos(0, 1)) {
			numEdges++;
		}
		if (colourFace == cubeToSolve.top.getPos(1, 0)) {
			numEdges++;
		}
		if (colourFace == cubeToSolve.top.getPos(1, 2)) {
			numEdges++;
		}
		if (colourFace == cubeToSolve.top.getPos(2, 1)) {
			numEdges++;
		}
	}

	//Top cross should be solved
	bool cornersSolved = false;
	int repeat = 6;
	while (!cornersSolved) {
		if (colourFace == cubeToSolve.top.getPos(2, 0)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
		}
		else if (colourFace == cubeToSolve.top.getPos(2, 2)) {
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
		}
		else if (colourFace == cubeToSolve.top.getPos(0, 0)) {
			cubeToSolve.doUPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
		}
		else if (colourFace == cubeToSolve.top.getPos(0, 2)) {
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
		}
		else {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
		}

		repeat--;
		if (repeat == 3) {
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
			repeat = 3;
		}
		else if (repeat == 0) {
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
			repeat = 6;
		}

		if (colourFace == cubeToSolve.top.getPos(0, 0) && colourFace == cubeToSolve.top.getPos(0, 2) && colourFace == cubeToSolve.top.getPos(2, 0) && colourFace == cubeToSolve.top.getPos(2, 2)) {
			cornersSolved = true;
		}
	}
}

void ImprovedBeginners::completeCorners() {
	bool backCornersSolved = false;
	for (int i = 0; i < 4; i++) {
		if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.front.getPos(0, 2)) {
			if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.front.getPos(1, 1)) {
				cubeToSolve.rotateCubeRight(2);
				backCornersSolved = true;
				break;
			}
			else if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.rightSide.getPos(1, 1)) {
				cubeToSolve.doUPrime(1);
				cubeToSolve.rotateCubeRight(1);
				backCornersSolved = true;
				break;
			}
			else if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.leftSide.getPos(1, 1)) {
				cubeToSolve.doU(1);
				cubeToSolve.rotateCubeLeft(1);
				backCornersSolved = true;
				break;
			}
			else if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.back.getPos(1, 1)) {
				cubeToSolve.doUPrime(2);
				backCornersSolved = true;
				break;
			}
		}
		cubeToSolve.doUPrime(1);
	}

	bool allCornersSolved = false;
	if (backCornersSolved) {
		if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.front.getPos(0, 2)) {
			if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.front.getPos(1, 1)) {
				allCornersSolved = true;
			}
		}
		else {
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doB(2);
			cubeToSolve.doR(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doB(2);
			cubeToSolve.doR(2);
			cubeToSolve.doUPrime(1);
		}
	}
	else {
		cubeToSolve.doRPrime(1);
		cubeToSolve.doF(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doB(2);
		cubeToSolve.doR(1);
		cubeToSolve.doFPrime(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doB(2);
		cubeToSolve.doR(2);
		cubeToSolve.doUPrime(1);

		completeCorners();
	}
}

void ImprovedBeginners::completeEdges() {
	bool edgesCompleted = false;
	while (!edgesCompleted) {
		if (cubeToSolve.front.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
			cubeToSolve.rotateCubeRight(2);
		}
		else if (cubeToSolve.rightSide.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
			cubeToSolve.doF(2);
			cubeToSolve.doU(1);
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(2);
			cubeToSolve.rotateCubeRight(2);
		}
		else if (cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
			cubeToSolve.doF(2);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.rotateCubeRight(2);
		}
		else {
			cubeToSolve.rotateCubeRight(1);
			cubeToSolve.doF(2);
			cubeToSolve.doU(1);
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(2);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.rotateCubeRight(1);
		}


		if (cubeToSolve.rightSide.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
			cubeToSolve.doF(2);
			cubeToSolve.doU(1);
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(2);
		}
		else if (cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
			cubeToSolve.doF(2);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(2);
		}

		//check edges
		bool frontEdgeDone = false;
		bool backEdgeDone = false;
		bool leftEdgeDone = false;
		bool rightEdgeDone = false;
		if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(0, 1)) {
			frontEdgeDone = true;
		}
		if (cubeToSolve.back.getPos(1, 1) == cubeToSolve.back.getPos(0, 1)) {
			backEdgeDone = true;
		}
		if (cubeToSolve.leftSide.getPos(1, 1) == cubeToSolve.leftSide.getPos(0, 1)) {
			leftEdgeDone = true;
		}
		if (cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 1)) {
			rightEdgeDone = true;
		}
		if (frontEdgeDone && backEdgeDone && leftEdgeDone && rightEdgeDone) {
			edgesCompleted = true;
		}
	}
}

bool ImprovedBeginners::isSolutionValid() {
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

void ImprovedBeginners::setCube(RubiksCube cube) {
	cubeToSolve = cube;
}

RubiksCube ImprovedBeginners::getCube() {
	return cubeToSolve;
}

ImprovedBeginners::~ImprovedBeginners() {
}
