#include "stdafx.h"
#include "ImprovedRoux.h"


ImprovedRoux::ImprovedRoux()
{
}

void ImprovedRoux::solveBottomLeft() {
	// Solve top cross from beginner method start
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
	// solve top cross from beginner method end

	//Modified Corner solver from Beginner's Method to only solve 2 corners

	bool topCornerPair = false;
	int oneOrTwo = 1;
	while (!topCornerPair) {
		if (oneOrTwo == 2) {
			cubeToSolve.rotateCubeLeft(1);
			oneOrTwo = 1;
		}
		else {
			cubeToSolve.rotateCubeRight(1);
			oneOrTwo = 2;
		}

		char colour1;
		char colour2;
		char colour3;

		for (int i = 0; i < 4; i++) {
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
				}
				if (colourToCheck2 == cubeToSolve.front.getPos(1, 1)) {
					if (colourToCheck1 == cubeToSolve.rightSide.getPos(1, 1)) {
						while (cubeToSolve.top.getPos(1, 1) != cubeToSolve.top.getPos(2, 2) && count != 0) {
							cubeToSolve.doRPrime(1);
							cubeToSolve.doDPrime(1);
							cubeToSolve.doR(1);
							cubeToSolve.doD(1);
							count--;
						}
					}
				}
			}
			cubeToSolve.doD(1);
		}


		//Move top colour out of incorrect corners
		for (int i = 0; i < 4; i++) {
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
			cubeToSolve.rotateCubeRight(1);
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
		if (backRightCorrect && frontRightCorrect) {
			cubeToSolve.rotateCubeRight(1);
			cubeToSolve.rotateCubeUp(1);
			cubeToSolve.rotateCubeRight(1);
			topCornerPair = true;
		}
		else if (frontRightCorrect && frontLeftCorrect) {
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.rotateCubeUp(1);
			cubeToSolve.rotateCubeRight(1);
			topCornerPair = true;
		}
	}
	//End of modified Corner solver from Beginner's Method to only solve 2 corners
}

void ImprovedRoux::solveBottomRight() {
	bool corner = false;
	int count = 0;

	//Position the corner to start the block
	while (!corner) {
		count++;
		cubeToSolve.doR(1);
		if (count == 5) {
			count = 0;
			cubeToSolve.doR(1);
		}
		cubeToSolve.doU(1);

		if (cubeToSolve.front.getPos(0, 0) == cubeToSolve.back.getPos(2, 2)) {
			if (cubeToSolve.leftSide.getPos(0, 2) == cubeToSolve.bottom.getPos(2, 0)) {
				if (cubeToSolve.top.getPos(2, 0) == cubeToSolve.rightSide.getPos(1, 1)) {
					corner = true;
				}
			}
		}
	}

	bool edge = false;
	bool orientationNeeded = false;
	count = 0;
	//Find edge
	while (!edge) {
		count++;
		if (count <= 4) {
			cubeToSolve.doM(1);
		}
		else if (count <= 7) {
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doM(1);
		}
		else if (count == 8) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doM(1);
		}
		else {
			cubeToSolve.doU(1);
			cubeToSolve.doM(2);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doMPrime(1);
		}

		if (cubeToSolve.front.getPos(0, 1) == cubeToSolve.front.getPos(0, 0)) {
			if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.top.getPos(2, 0)) {
				edge = true;
			}
		}
		if (cubeToSolve.front.getPos(0, 1) == cubeToSolve.top.getPos(2, 0)) {
			if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.front.getPos(0, 0)) {
				edge = true;
				orientationNeeded = true;
			}
		}
	}

	//Makes 2x1 block if it is not already made
	if (orientationNeeded) {
		cubeToSolve.doM(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doM(2);
		cubeToSolve.doLPrime(1);
		cubeToSolve.doBPrime(1);
		cubeToSolve.doL(1);
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doM(1);
	}

	//make 2x2
	if (cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.top.getPos(1, 0) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doM(1);
		cubeToSolve.doU(1);
		cubeToSolve.doR(2);
		cubeToSolve.doU(2);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.top.getPos(1, 0) == cubeToSolve.rightSide.getPos(1, 1)) {
		cubeToSolve.doRPrime(1);
		cubeToSolve.doM(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(2);
		cubeToSolve.doM(2);
		cubeToSolve.doU(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doM(1);
		cubeToSolve.doU(1);
		cubeToSolve.doR(2);
	}
	else if (cubeToSolve.top.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.back.getPos(0, 1) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doU(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doFPrime(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doF(1);
		cubeToSolve.doR(2);
	}
	else if (cubeToSolve.top.getPos(0, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.back.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
		cubeToSolve.doU(1);
		cubeToSolve.doR(2);
		cubeToSolve.doU(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doM(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.front.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doR(1);
		cubeToSolve.doMPrime(1);
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		cubeToSolve.doU(2);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(0, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.front.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
		cubeToSolve.doU(2);
		cubeToSolve.doR(2);
		cubeToSolve.doM(2);
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		cubeToSolve.doMPrime(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.back.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doM(1);
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		cubeToSolve.doU(2);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.back.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
		cubeToSolve.doU(2);
		cubeToSolve.doR(2);
		cubeToSolve.doM(2);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.doMPrime(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
	}
	else {
		bool missingPieceFound = false;
		while (!missingPieceFound) {
			cubeToSolve.doR(1);
			if (cubeToSolve.rightSide.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.bottom.getPos(1, 2) == cubeToSolve.bottom.getPos(0, 0)) {
				cubeToSolve.doU(2);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doM(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doR(1);
				missingPieceFound = true;
			}
			else if (cubeToSolve.rightSide.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.bottom.getPos(1, 2) == cubeToSolve.rightSide.getPos(1, 1)) {
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doFPrime(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doF(1);
				cubeToSolve.doR(2);
				missingPieceFound = true;
			}
		}
	}

	//Do corner and last edge
	bool wrongCorner = true;
	//right side colour not in front bottom right corner
	if ((cubeToSolve.front.getPos(2, 2) == cubeToSolve.rightSide.getPos(1, 1)) || (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(1, 1)) || (cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.rightSide.getPos(1, 1))) {
		//bottom colour not in front bottom right corner
		if ((cubeToSolve.front.getPos(2, 2) == cubeToSolve.bottom.getPos(0, 0)) || (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.bottom.getPos(0, 0)) || (cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.bottom.getPos(0, 0))) {
			//front colour not in front bottom right corner
			if ((cubeToSolve.front.getPos(2, 2) == cubeToSolve.front.getPos(1, 0)) || (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(1, 0)) || (cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.front.getPos(1, 0))) {
				wrongCorner = false;
			}
		}
	}

	count = 0;
	while (wrongCorner) {
		if (count == 4) {
			count = 0;
			cubeToSolve.doUPrime(2);
		}
		cubeToSolve.doR(1);
		cubeToSolve.doUPrime(1);
		cubeToSolve.doRPrime(1);
		count++;

		//right side colour not in front bottom right corner
		if ((cubeToSolve.front.getPos(2, 2) == cubeToSolve.rightSide.getPos(1, 1)) || (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(1, 1)) || (cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.rightSide.getPos(1, 1))) {
			//bottom colour not in front bottom right corner
			if ((cubeToSolve.front.getPos(2, 2) == cubeToSolve.bottom.getPos(0, 0)) || (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.bottom.getPos(0, 0)) || (cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.bottom.getPos(0, 0))) {
				//front colour not in front bottom right corner
				if ((cubeToSolve.front.getPos(2, 2) == cubeToSolve.front.getPos(1, 0)) || (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(1, 0)) || (cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.front.getPos(1, 0))) {
					wrongCorner = false;
				}
			}
		}
	}

	bool edgeDone = false;
	if (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.bottom.getPos(0, 0)) {
		if (cubeToSolve.rightSide.getPos(1, 0) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.front.getPos(1, 2) == cubeToSolve.rightSide.getPos(1, 1)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doM(1);
			cubeToSolve.doU(2);
			cubeToSolve.doM(2);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			edgeDone = true;
		}

		count = 0;
		while (!edgeDone && count < 8) {
			if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.top.getPos(0, 1) == cubeToSolve.front.getPos(1, 0)) {
				//r
				cubeToSolve.doR(1);
				cubeToSolve.doMPrime(1);
				//end r
				cubeToSolve.doUPrime(1);
				cubeToSolve.doM(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				edgeDone = true;
			}
			else if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.top.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
				cubeToSolve.doUPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doMPrime(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				edgeDone = true;
			}
			cubeToSolve.doU(1);
			if (count == 4) {
				cubeToSolve.doM(2);
			}
			count++;
		}
	}
	else if (cubeToSolve.front.getPos(2, 2) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.bottom.getPos(0, 2) == cubeToSolve.rightSide.getPos(1, 1)) {
		if (cubeToSolve.rightSide.getPos(1, 0) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.front.getPos(1, 2) == cubeToSolve.rightSide.getPos(1, 1)) {
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			//r'
			cubeToSolve.doRPrime(1);
			cubeToSolve.doM(1);
			//end r'
			cubeToSolve.doM(1);
			cubeToSolve.doU(1);
			//r
			cubeToSolve.doR(1);
			cubeToSolve.doMPrime(1);
			//end r
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			edgeDone = true;
		}
		else if (cubeToSolve.rightSide.getPos(1, 0) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.front.getPos(1, 2) == cubeToSolve.front.getPos(1, 0)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			edgeDone = true;
		}

		count = 0;
		while (!edgeDone && count < 8) {
			if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.top.getPos(0, 1) == cubeToSolve.front.getPos(1, 0)) {
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				edgeDone = true;
			}
			else if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.top.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doU(1);
				cubeToSolve.doM(1);
				cubeToSolve.doR(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doRPrime(1);
				edgeDone = true;
			}
			cubeToSolve.doU(1);
			if (count == 4) {
				cubeToSolve.doM(2);
			}
			count++;
		}
	}
	else if (cubeToSolve.front.getPos(2, 2) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.bottom.getPos(0, 0)) {
		if (cubeToSolve.rightSide.getPos(1, 0) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.front.getPos(1, 2) == cubeToSolve.rightSide.getPos(1, 1)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			//r'
			cubeToSolve.doRPrime(1);
			cubeToSolve.doM(1);
			//end r'
			cubeToSolve.doUPrime(1);
			cubeToSolve.doMPrime(1);
			//r
			cubeToSolve.doR(1);
			cubeToSolve.doMPrime(1);
			//end r
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			edgeDone = true;
		}
		else if (cubeToSolve.rightSide.getPos(1, 0) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.front.getPos(1, 2) == cubeToSolve.front.getPos(1, 0)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			//r'
			cubeToSolve.doRPrime(1);
			cubeToSolve.doM(1);
			//end r'
			cubeToSolve.doU(1);
			//r*2
			cubeToSolve.doR(2);
			cubeToSolve.doM(2);
			//end r*2
			cubeToSolve.doBPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doB(1);
			cubeToSolve.doRPrime(1);
			edgeDone = true;
		}

		count = 0;
		while (!edgeDone && count < 9) {
			if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.top.getPos(0, 1) == cubeToSolve.front.getPos(1, 0)) {
				cubeToSolve.doU(1);
				cubeToSolve.doR(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				edgeDone = true;
			}
			else if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 0) && cubeToSolve.top.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
				//r
				cubeToSolve.doR(1);
				cubeToSolve.doMPrime(1);
				//end r
				cubeToSolve.doU(2);
				//r'
				cubeToSolve.doRPrime(1);
				cubeToSolve.doM(1);
				//end r'
				cubeToSolve.doU(2);
				//r
				cubeToSolve.doR(1);
				cubeToSolve.doMPrime(1);
				//end r
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				edgeDone = true;
			}
			cubeToSolve.doU(1);
			if (count == 4) {
				cubeToSolve.doM(2);
			}
			count++;
		}
	}
}

void ImprovedRoux::solveTopCorners() {
	bool cornersInCorrectLocations = false;
	bool moveOneJustDone = false;
	bool moveTwoJustDone = false;
	bool moveThreeJustDone = false;
	bool moveFourJustDone = false;
	int count = 0;
	int resets = 0;
	while (!cornersInCorrectLocations) {
		bool frontRightCorrect = false;
		bool frontLeftCorrect = false;
		bool backLeftCorrect = false;
		bool backRightCorrect = false;
		for (int i = 0; i < 4; i++) {
			bool correct = false;
			if (cubeToSolve.front.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
				if (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
					correct = true;
				}
			}
			if (correct) {
				switch (i) {
				case 0:
					frontRightCorrect = true;
					break;
				case 1:
					frontLeftCorrect = true;
					break;
				case 2:
					backLeftCorrect = true;
					break;
				case 3:
					backRightCorrect = true;
					break;
				}
			}

			cubeToSolve.rotateCubeRight(1);
		}

		if (!frontRightCorrect && !backRightCorrect && !moveFourJustDone) {
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			moveFourJustDone = true;
			moveOneJustDone = false;
			moveTwoJustDone = false;
			moveThreeJustDone = false;
			count = 0;
			for (int i = 0; i < 4; i++) {
				bool correct = false;
				if (cubeToSolve.front.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
					if (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
						correct = true;
					}
				}
				if (correct) {
					switch (i) {
					case 0:
						frontRightCorrect = true;
						break;
					case 1:
						frontLeftCorrect = true;
						break;
					case 2:
						backLeftCorrect = true;
						break;
					case 3:
						backRightCorrect = true;
						break;
					}
				}

				cubeToSolve.rotateCubeRight(1);
			}
		}
		if (!backRightCorrect && !backLeftCorrect && !moveOneJustDone) {
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			cubeToSolve.doUPrime(1);
			moveOneJustDone = true;
			moveFourJustDone = false;
			moveTwoJustDone = false;
			moveThreeJustDone = false;
			count = 0;
			for (int i = 0; i < 4; i++) {
				bool correct = false;
				if (cubeToSolve.front.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
					if (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
						correct = true;
					}
				}
				if (correct) {
					switch (i) {
					case 0:
						frontRightCorrect = true;
						break;
					case 1:
						frontLeftCorrect = true;
						break;
					case 2:
						backLeftCorrect = true;
						break;
					case 3:
						backRightCorrect = true;
						break;
					}
				}

				cubeToSolve.rotateCubeRight(1);
			}
		}
		if (!backLeftCorrect && !frontLeftCorrect && !moveTwoJustDone) {
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			cubeToSolve.doUPrime(2);
			moveTwoJustDone = true;
			moveOneJustDone = false;
			moveFourJustDone = false;
			moveThreeJustDone = false;
			count = 0;
			for (int i = 0; i < 4; i++) {
				bool correct = false;
				if (cubeToSolve.front.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
					if (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
						correct = true;
					}
				}
				if (correct) {
					switch (i) {
					case 0:
						frontRightCorrect = true;
						break;
					case 1:
						frontLeftCorrect = true;
						break;
					case 2:
						backLeftCorrect = true;
						break;
					case 3:
						backRightCorrect = true;
						break;
					}
				}

				cubeToSolve.rotateCubeRight(1);
			}
		}
		if (!frontLeftCorrect && !frontRightCorrect && !moveThreeJustDone) {
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			cubeToSolve.doU(1);
			moveThreeJustDone = true;
			moveOneJustDone = false;
			moveTwoJustDone = false;
			moveFourJustDone = false;
			count = 0;
			for (int i = 0; i < 4; i++) {
				bool correct = false;
				if (cubeToSolve.front.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
					if (cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(2, 0) == cubeToSolve.rightSide.getPos(0, 0)) {
						correct = true;
					}
				}
				if (correct) {
					switch (i) {
					case 0:
						frontRightCorrect = true;
						break;
					case 1:
						frontLeftCorrect = true;
						break;
					case 2:
						backLeftCorrect = true;
						break;
					case 3:
						backRightCorrect = true;
						break;
					}
				}

				cubeToSolve.rotateCubeRight(1);
			}
		}

		if (count == 2 && resets == 0) {
			resets++;
			count = 0;
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
		}
		else if (count == 2 && resets == 1) {
			resets++;
			count = 0;
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			cubeToSolve.doU(1);
		}
		else if (count == 2 && resets == 2) {
			resets++;
			count = 0;
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			cubeToSolve.doUPrime(2);
		}
		else if (count == 2 && resets == 3) {
			resets = 0;
			count = 0;
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(2);
			cubeToSolve.rotateCubeDown(1);
			cubeToSolve.doUPrime(1);
		}
		count++;

		if (frontRightCorrect && backRightCorrect && backLeftCorrect && frontLeftCorrect) {
			cornersInCorrectLocations = true;
		}
	}


	bool middleOrientated = false;
	while (!middleOrientated) {
		cubeToSolve.doM(1);

		if (cubeToSolve.bottom.getPos(1, 1) == cubeToSolve.bottom.getPos(0, 0)) {
			middleOrientated = true;
		}
	}

	bool cornersSolved = false;
	char colourTop = cubeToSolve.top.getPos(1, 1);
	count = 0;
	while (!cornersSolved) {
		if (colourTop == cubeToSolve.top.getPos(2, 0) && colourTop == cubeToSolve.top.getPos(2, 2) && colourTop == cubeToSolve.back.getPos(0, 0) && colourTop == cubeToSolve.back.getPos(0, 2)) {
			//E
			cubeToSolve.doR(2);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doR(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
		}
		else if (colourTop == cubeToSolve.top.getPos(2, 0) && colourTop == cubeToSolve.top.getPos(2, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0) && colourTop == cubeToSolve.rightSide.getPos(0, 2)) {
			//F
			cubeToSolve.doR(2);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doR(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(2);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(2);
			cubeToSolve.doR(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
		}
		else if (colourTop == cubeToSolve.top.getPos(0, 0) && colourTop == cubeToSolve.front.getPos(0, 0) && colourTop == cubeToSolve.rightSide.getPos(0, 0) && colourTop == cubeToSolve.back.getPos(0, 0)) {
			//B
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
		}
		else if (colourTop == cubeToSolve.top.getPos(2, 0) && colourTop == cubeToSolve.rightSide.getPos(0, 2) && colourTop == cubeToSolve.front.getPos(0, 2) && colourTop == cubeToSolve.back.getPos(0, 2)) {
			//C
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(2);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(2);
		}
		else if (colourTop == cubeToSolve.top.getPos(2, 0) && colourTop == cubeToSolve.top.getPos(0, 2) && colourTop == cubeToSolve.front.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0)) {
			//D 
			cubeToSolve.doRPrime(1);
			cubeToSolve.doD(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doD(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doDPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doDPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
		}
		else if (colourTop == cubeToSolve.rightSide.getPos(0, 0) && colourTop == cubeToSolve.rightSide.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0) && colourTop == cubeToSolve.leftSide.getPos(0, 2)) {
			//H Alt
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doR(1);
		}
		else if (colourTop == cubeToSolve.front.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0) && colourTop == cubeToSolve.leftSide.getPos(0, 2) && colourTop == cubeToSolve.back.getPos(0, 0)) {
			//G
			cubeToSolve.doF(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
		}
		cubeToSolve.doU(1);

		bool backRightCorrect = false;
		bool backLeftCorrect = false;
		bool frontRightCorrect = false;
		bool frontLeftCorrect = false;
		if (colourTop == cubeToSolve.top.getPos(0, 0)) {
			backLeftCorrect = true;
		}
		if (colourTop == cubeToSolve.top.getPos(0, 2)) {
			backRightCorrect = true;
		}
		if (colourTop == cubeToSolve.top.getPos(2, 0)) {
			frontLeftCorrect = true;
		}
		if (colourTop == cubeToSolve.top.getPos(2, 2)) {
			frontRightCorrect = true;
		}

		if (frontLeftCorrect&& frontRightCorrect && backLeftCorrect && backRightCorrect) {
			cornersSolved = true;
		}
	}

	bool topOrientated = false;
	while (!topOrientated) {
		cubeToSolve.doU(1);

		if (cubeToSolve.rightSide.getPos(0, 0) == cubeToSolve.rightSide.getPos(1, 1)) {
			topOrientated = true;
		}
	}
}

void ImprovedRoux::solveLastRedgeandLedge() {
	//last redge
	bool redgeDone = false;
	char colourRight = cubeToSolve.rightSide.getPos(0, 0);
	if (colourRight == cubeToSolve.rightSide.getPos(0, 1)) {
		redgeDone = true;
	}
	while (!redgeDone) {
		if (colourRight == cubeToSolve.bottom.getPos(0, 1)) {
			cubeToSolve.doU(1);
			cubeToSolve.doMPrime(1);
			cubeToSolve.doUPrime(1);
			redgeDone = true;
		}
		else if (colourRight == cubeToSolve.front.getPos(2, 1)) {
			cubeToSolve.doUPrime(1);
			cubeToSolve.doM(2);
			cubeToSolve.doU(1);
			redgeDone = true;
		}
		else if (colourRight == cubeToSolve.top.getPos(1, 0)) {
			cubeToSolve.doU(1);
			cubeToSolve.doM(1);
			cubeToSolve.doUPrime(1);
			redgeDone = true;
		}
		else if (colourRight == cubeToSolve.leftSide.getPos(0, 1)) {
			cubeToSolve.doUPrime(1);
			cubeToSolve.doM(1);
			cubeToSolve.doU(2);
			cubeToSolve.doMPrime(1);
			cubeToSolve.doUPrime(1);
			redgeDone = true;
		}
		else if (colourRight == cubeToSolve.top.getPos(1, 2)) {
			cubeToSolve.doU(1);
			cubeToSolve.doM(1);
			cubeToSolve.doU(2);
			cubeToSolve.doM(2);
			cubeToSolve.doU(1);
			redgeDone = true;
		}
		cubeToSolve.doM(1);
	}

	//last ledge
	bool ledgeDone = false;
	char leftSideColour = cubeToSolve.leftSide.getPos(0, 0);
	if (cubeToSolve.leftSide.getPos(0, 1) == leftSideColour) {
		ledgeDone = true;
	}
	while (!ledgeDone) {
		if (leftSideColour == cubeToSolve.front.getPos(2, 1)) {
			cubeToSolve.doUPrime(1);
			cubeToSolve.doM(1);
			cubeToSolve.doU(2);
			cubeToSolve.doM(1);
			cubeToSolve.doUPrime(1);
		}
		else if (leftSideColour == cubeToSolve.back.getPos(2, 1)) {
			cubeToSolve.doU(1);
			cubeToSolve.doMPrime(1);
			cubeToSolve.doU(2);
			cubeToSolve.doMPrime(1);
			cubeToSolve.doU(1);
		}
		cubeToSolve.doMPrime(1);

		if (cubeToSolve.leftSide.getPos(0, 1) == leftSideColour) {
			ledgeDone = true;
		}
		else {
			cubeToSolve.doUPrime(1);
			cubeToSolve.doM(1);
			cubeToSolve.doU(2);
			cubeToSolve.doM(1);
			cubeToSolve.doUPrime(1);
		}
	}
}

void ImprovedRoux::flipMidges() {
	//flip middle edges in to the correct orientation for the last step

	bool midgesFlippedCorrectly = false;
	while (!midgesFlippedCorrectly) {
		for (int i = 0; i < 4; i++) {
			if (cubeToSolve.front.getPos(0, 1) != cubeToSolve.front.getPos(1, 1) && cubeToSolve.front.getPos(0, 1) != cubeToSolve.back.getPos(1, 1)) {
				if (cubeToSolve.back.getPos(0, 1) != cubeToSolve.front.getPos(1, 1) && cubeToSolve.back.getPos(0, 1) != cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doMPrime(1);
					cubeToSolve.doU(1);
					cubeToSolve.doMPrime(1);
					cubeToSolve.doU(1);
					cubeToSolve.doMPrime(1);
					cubeToSolve.doU(2);
					cubeToSolve.doM(1);
					cubeToSolve.doU(1);
					cubeToSolve.doM(1);
					cubeToSolve.doU(1);
					cubeToSolve.doM(1);
					cubeToSolve.doU(2);
				}
			}
			cubeToSolve.rotateCubeUp(1);
		}

		bool frontTopCorrect = false;
		bool frontBottomCorrect = false;
		bool backTopCorrect = false;
		bool backBottomCorrect = false;

		if (cubeToSolve.front.getPos(0, 1) == cubeToSolve.front.getPos(1, 1) || cubeToSolve.front.getPos(0, 1) == cubeToSolve.back.getPos(1, 1)) {
			frontTopCorrect = true;
		}
		if (cubeToSolve.front.getPos(2, 1) == cubeToSolve.front.getPos(1, 1) || cubeToSolve.front.getPos(2, 1) == cubeToSolve.back.getPos(1, 1)) {
			frontBottomCorrect = true;
		}
		if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 1) || cubeToSolve.back.getPos(0, 1) == cubeToSolve.back.getPos(1, 1)) {
			backTopCorrect = true;
		}
		if (cubeToSolve.back.getPos(2, 1) == cubeToSolve.front.getPos(1, 1) || cubeToSolve.back.getPos(2, 1) == cubeToSolve.back.getPos(1, 1)) {
			backBottomCorrect = true;
		}

		if (frontTopCorrect && frontBottomCorrect && backTopCorrect && backBottomCorrect) {
			midgesFlippedCorrectly = true;
		}
		else {
			for (int i = 0; i < 2; i++) {
				cubeToSolve.doMPrime(1);
				cubeToSolve.doU(1);
				cubeToSolve.doMPrime(1);
				cubeToSolve.doU(1);
				cubeToSolve.doMPrime(1);
				cubeToSolve.doU(2);
				cubeToSolve.doM(1);
				cubeToSolve.doU(1);
				cubeToSolve.doM(1);
				cubeToSolve.doU(1);
				cubeToSolve.doM(1);
				cubeToSolve.doU(2);
				cubeToSolve.rotateCubeUp(1);
			}
		}
	}
}

void ImprovedRoux::completeCube() {
	for (int i = 0; i < 8; i++) {
		if (cubeToSolve.front.getPos(0, 1) == cubeToSolve.back.getPos(1, 1)) {
			if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.top.getPos(1, 1)) {
				if (cubeToSolve.top.getPos(0, 1) == cubeToSolve.bottom.getPos(1, 1)) {
					if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
						cubeToSolve.doU(2);
						cubeToSolve.doM(1);
						cubeToSolve.doU(2);
						cubeToSolve.doMPrime(1);
					}
				}
				else if (cubeToSolve.front.getPos(2, 1) == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doU(2);
					cubeToSolve.doM(2);
					cubeToSolve.doU(2);
					cubeToSolve.doM(2);
				}
			}
			else if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.bottom.getPos(1, 1)) {
				if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
					if (cubeToSolve.top.getPos(0, 1) == cubeToSolve.top.getPos(1, 1)) {
						cubeToSolve.doU(2);
						cubeToSolve.doMPrime(1);
						cubeToSolve.doU(2);
						cubeToSolve.doM(1);
					}
					else {
						cubeToSolve.doE(2);
						cubeToSolve.doM(1);
						cubeToSolve.doE(2);
						cubeToSolve.doM(1);
					}
				}
			}
		}
		cubeToSolve.rotateCubeUp(1);
	}

	//Orient left and right with middle
	bool solved = false;
	if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(1, 0)) {
		solved = true;
	}
	while (!solved) {
		cubeToSolve.doR(1);
		cubeToSolve.doLPrime(1);
		if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(1, 0)) {
			solved = true;
		}
	}
}

bool ImprovedRoux::isSolutionValid() {
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

void ImprovedRoux::setCube(RubiksCube cube) {
	cubeToSolve = cube;
}

RubiksCube ImprovedRoux::getCube() {
	return cubeToSolve;
}

ImprovedRoux::~ImprovedRoux()
{
}