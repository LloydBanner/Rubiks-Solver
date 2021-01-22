#include "stdafx.h"
#include "RouxMethodSolver.h"


RouxMethodSolver::RouxMethodSolver()
{
}

void RouxMethodSolver::solveBottomLeft() {
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
			cubeToSolve.rotateCubeRight(3);
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

void RouxMethodSolver::solveBottomRight() {
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
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
		}
		else if (count <= 7) {
			cubeToSolve.doU(1);
			cubeToSolve.doR(1);
			cubeToSolve.doUPrime(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
		}
		else if (count == 8) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
		}
		else {
			cubeToSolve.doU(1);
			//M'*2
			cubeToSolve.doL(2);
			cubeToSolve.doRPrime(2);
			cubeToSolve.rotateCubeUp(2);
			//end M'*2
			cubeToSolve.doUPrime(1);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
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
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
		cubeToSolve.doUPrime(1);
		//M'*2
		cubeToSolve.doL(2);
		cubeToSolve.doRPrime(2);
		cubeToSolve.rotateCubeUp(2);
		//end M'*2
		cubeToSolve.doLPrime(1);
		cubeToSolve.doBPrime(1);
		cubeToSolve.doL(1);
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		cubeToSolve.doUPrime(1);
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
	}

	//make 2x2
	if (cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.top.getPos(1, 0) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
		cubeToSolve.doU(1);
		cubeToSolve.doR(2);
		cubeToSolve.doU(2);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.top.getPos(1, 0) == cubeToSolve.rightSide.getPos(1, 1)) {
		cubeToSolve.doRPrime(1);
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(2);
		//M'*2
		cubeToSolve.doL(2);
		cubeToSolve.doRPrime(2);
		cubeToSolve.rotateCubeUp(2);
		//end M'*2
		cubeToSolve.doU(1);
		cubeToSolve.doRPrime(1);
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
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
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(0, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.front.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doR(1);
		//M'
		cubeToSolve.doL(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.rotateCubeUp(1);
		//end M'
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
		//M'*2
		cubeToSolve.doL(2);
		cubeToSolve.doRPrime(2);
		cubeToSolve.rotateCubeUp(2);
		//end M'*2
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		//M'
		cubeToSolve.doL(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.rotateCubeUp(1);
		//end M'
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1) && cubeToSolve.back.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0)) {
		cubeToSolve.doU(2);
		cubeToSolve.doRPrime(1);
		//M
		cubeToSolve.doLPrime(1);
		cubeToSolve.doR(1);
		cubeToSolve.rotateCubeUp(3);
		//end M
		cubeToSolve.doU(1);
		cubeToSolve.doR(1);
		cubeToSolve.doU(2);
		cubeToSolve.doR(1);
	}
	else if (cubeToSolve.bottom.getPos(2, 1) == cubeToSolve.bottom.getPos(0, 0) && cubeToSolve.back.getPos(2, 1) == cubeToSolve.rightSide.getPos(1, 1)) {
		cubeToSolve.doU(2);
		cubeToSolve.doR(2);
		//M'*2
		cubeToSolve.doL(2);
		cubeToSolve.doRPrime(2);
		cubeToSolve.rotateCubeUp(2);
		//end M'*2
		cubeToSolve.doUPrime(1);
		cubeToSolve.doR(1);
		//M'
		cubeToSolve.doL(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.rotateCubeUp(1);
		//end M'
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
				//M
				cubeToSolve.doLPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.rotateCubeUp(3);
				//end M
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
}

bool RouxMethodSolver::isSolutionValid() {
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

void RouxMethodSolver::setCube(RubiksCube cube) {
	cubeToSolve = cube;
}

RubiksCube RouxMethodSolver::getCube() {
	return cubeToSolve;
}

RouxMethodSolver::~RouxMethodSolver()
{
}
