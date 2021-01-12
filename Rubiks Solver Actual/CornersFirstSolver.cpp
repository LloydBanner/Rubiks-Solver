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
	cubeToSolve.rotateCubeUp(2);
}

void CornersFirstSolver::solveTopCorners() {
	bool cornersInCorrectLocations = false;
	bool lastPieceCorrect = false;
	bool pieceBeforeLastCorrect = false;
	bool otherPieceCorrect = false;
	int count = 0;
	while (!cornersInCorrectLocations) {
		bool correctPiece = false;
		if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(1, 1) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 0)) {
			if (cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 0)) {
				correctPiece = true;
			}
		}

		if (correctPiece) {
			cubeToSolve.rotateCubeRight(1);
			otherPieceCorrect = pieceBeforeLastCorrect;
			pieceBeforeLastCorrect = lastPieceCorrect;
			lastPieceCorrect = true;
		}
		else {
			if (!lastPieceCorrect) {
				cubeToSolve.doR(1);
				cubeToSolve.doU(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doFPrime(1);
				cubeToSolve.doUPrime(1);
				cubeToSolve.doF(1);
				count = 0;
			}
			bool correctPieceNow = false;
			if (cubeToSolve.front.getPos(1, 1) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.front.getPos(1, 1) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.front.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 0)) {
				if (cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.front.getPos(0, 2) || cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.top.getPos(2, 2) || cubeToSolve.rightSide.getPos(1, 1) == cubeToSolve.rightSide.getPos(0, 0)) {
					correctPieceNow = true;
				}
			}
			cubeToSolve.rotateCubeRight(1);
			otherPieceCorrect = pieceBeforeLastCorrect;
			pieceBeforeLastCorrect = lastPieceCorrect;
			lastPieceCorrect = correctPieceNow;
		}

		if (count == 4) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
		}
		count++;

		if (correctPiece && lastPieceCorrect && pieceBeforeLastCorrect && otherPieceCorrect) {
			cornersInCorrectLocations = true;
		}
	}

	bool cornersSolved = false;
	char colourTop = cubeToSolve.top.getPos(1, 1);
	count = 0;
	while (!cornersSolved) {
		if (colourTop == cubeToSolve.top.getPos(2, 2) && colourTop == cubeToSolve.top.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0) && colourTop == cubeToSolve.leftSide.getPos(0, 2)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		else if (colourTop == cubeToSolve.top.getPos(2, 2) && colourTop == cubeToSolve.top.getPos(0, 2) && colourTop == cubeToSolve.front.getPos(0, 0) && colourTop == cubeToSolve.back.getPos(0, 2)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		else if (colourTop == cubeToSolve.top.getPos(2, 0) && colourTop == cubeToSolve.top.getPos(0, 2) && colourTop == cubeToSolve.front.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		else if (colourTop == cubeToSolve.top.getPos(0, 2) && colourTop == cubeToSolve.rightSide.getPos(0, 0) && colourTop == cubeToSolve.front.getPos(0, 0) && colourTop == cubeToSolve.leftSide.getPos(0, 0)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		else if (colourTop == cubeToSolve.top.getPos(2, 2) && colourTop == cubeToSolve.rightSide.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 2) && colourTop == cubeToSolve.back.getPos(0, 2)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		else if (colourTop == cubeToSolve.rightSide.getPos(0, 0) && colourTop == cubeToSolve.rightSide.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0) && colourTop == cubeToSolve.leftSide.getPos(0, 2)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		else if (colourTop == cubeToSolve.front.getPos(0, 2) && colourTop == cubeToSolve.leftSide.getPos(0, 0) && colourTop == cubeToSolve.leftSide.getPos(0, 2) && colourTop == cubeToSolve.back.getPos(0, 0)) {
			cubeToSolve.doR(1);
			cubeToSolve.doU(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doF(1);
			cubeToSolve.rotateCubeRight(2);
			cubeToSolve.doLPrime(1);
			cubeToSolve.doUPrime(1);
			cubeToSolve.doL(1);
			cubeToSolve.doU(1);
			cubeToSolve.doF(1);
			cubeToSolve.doU(1);
			cubeToSolve.doFPrime(1);
			cubeToSolve.rotateCubeRight(3);
		}
		cubeToSolve.rotateCubeRight(1);
		
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
}

void CornersFirstSolver::solveThreeLedges() {
	//left edges

	bool ledgesSolved = false;
	int count = 0;
	while (!ledgesSolved) {
		if (cubeToSolve.front.getPos(2, 1) == cubeToSolve.top.getPos(0, 0) && cubeToSolve.bottom.getPos(0, 1) == cubeToSolve.leftSide.getPos(0, 0)) {
			cubeToSolve.doUPrime(1);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doU(1);
		}
		else if (cubeToSolve.front.getPos(2, 1) == cubeToSolve.leftSide.getPos(0, 0) && cubeToSolve.bottom.getPos(0, 1) == cubeToSolve.top.getPos(0, 0)) {
			cubeToSolve.doU(1);
			//M'*2
			cubeToSolve.doL(2);
			cubeToSolve.doRPrime(2);
			cubeToSolve.rotateCubeUp(2);
			//end M'*2
			cubeToSolve.doUPrime(1);
		}
		else if (cubeToSolve.rightSide.getPos(0, 1) == cubeToSolve.top.getPos(0, 0) && cubeToSolve.top.getPos(1, 2) == cubeToSolve.leftSide.getPos(0, 0)) {
			cubeToSolve.doUPrime(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doU(1);
		}
		else if (cubeToSolve.rightSide.getPos(0, 1) == cubeToSolve.leftSide.getPos(0, 0) && cubeToSolve.top.getPos(1, 2) == cubeToSolve.top.getPos(0, 0)) {
			cubeToSolve.doU(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doU(2);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doU(1);
		}
		else if (cubeToSolve.top.getPos(1, 0) == cubeToSolve.leftSide.getPos(0, 0) && cubeToSolve.leftSide.getPos(0, 1) == cubeToSolve.top.getPos(0, 0)) {
			cubeToSolve.doUPrime(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doU(2);
			//M'*2
			cubeToSolve.doL(2);
			cubeToSolve.doRPrime(2);
			cubeToSolve.rotateCubeUp(2);
			//end M'*2
			cubeToSolve.doUPrime(1);
		}
		else if (count == 15) {
			for (int i = 0; i < 4; i++) {
				cubeToSolve.doUPrime(1);
				//M'
				cubeToSolve.doL(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.rotateCubeUp(1);
				//end M'
				cubeToSolve.doU(1);
				cubeToSolve.rotateCubeUp(1);
			}
		}
		else if (count == 25) {
			for (int i = 0; i < 4; i++) {
				cubeToSolve.doU(1);
				//M'*2
				cubeToSolve.doL(2);
				cubeToSolve.doRPrime(2);
				cubeToSolve.rotateCubeUp(2);
				//end M'*2
				cubeToSolve.doUPrime(1);
				cubeToSolve.rotateCubeUp(1);
			}
		}
		else if (count == 35) {
			count = 0;
			for (int i = 0; i < 4; i++) {
				cubeToSolve.doUPrime(1);
				//M
				cubeToSolve.doLPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.rotateCubeUp(3);
				//end M
				cubeToSolve.doU(2);
				//M'*2
				cubeToSolve.doL(2);
				cubeToSolve.doRPrime(2);
				cubeToSolve.rotateCubeUp(2);
				//end M'*2
				cubeToSolve.doUPrime(1);
				cubeToSolve.rotateCubeUp(1);
			}
		}
		count++;
		cubeToSolve.rotateCubeUp(1);

		bool bottomLedgeSolved = false;
		bool backLedgeSolved = false;
		bool frontLedgeSolved = false;
		if (cubeToSolve.leftSide.getPos(2, 1) == cubeToSolve.leftSide.getPos(0, 0) && cubeToSolve.bottom.getPos(1, 0) == cubeToSolve.bottom.getPos(0, 0)) {
			bottomLedgeSolved = true;
		}
		if (cubeToSolve.leftSide.getPos(1, 0) == cubeToSolve.leftSide.getPos(0, 0) && cubeToSolve.back.getPos(1, 2) == cubeToSolve.back.getPos(0, 0)) {
			backLedgeSolved = true;
		}
		if (cubeToSolve.leftSide.getPos(1, 2) == cubeToSolve.leftSide.getPos(0, 0) && cubeToSolve.front.getPos(1, 0) == cubeToSolve.front.getPos(0, 0)) {
			frontLedgeSolved = true;
		}

		if (bottomLedgeSolved && backLedgeSolved && frontLedgeSolved) {
			ledgesSolved = true;
		}
	}
}

void CornersFirstSolver::solveRedges() {
	//Right edges

	char colourRight = cubeToSolve.rightSide.getPos(0, 0);
	bool redgesSolved = false;
	int count = 0;
	while (!redgesSolved) {
		if (colourRight == cubeToSolve.bottom.getPos(0, 1) && cubeToSolve.top.getPos(2, 2) == cubeToSolve.front.getPos(2, 1)) {
			cubeToSolve.doU(1);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doUPrime(1);
		}
		else if (cubeToSolve.top.getPos(2, 2) == cubeToSolve.bottom.getPos(0, 1) && colourRight == cubeToSolve.front.getPos(2, 1)) {
			cubeToSolve.doUPrime(1);
			//M'*2
			cubeToSolve.doL(2);
			cubeToSolve.doRPrime(2);
			cubeToSolve.rotateCubeUp(2);
			//end M'*2
			cubeToSolve.doU(1);
		}
		else if (cubeToSolve.top.getPos(2, 2) == cubeToSolve.leftSide.getPos(0, 1) && colourRight == cubeToSolve.top.getPos(1, 0)) {
			cubeToSolve.doU(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doUPrime(1);
		}
		else if (colourRight == cubeToSolve.leftSide.getPos(0, 1) && cubeToSolve.top.getPos(2, 2) == cubeToSolve.top.getPos(1, 0)) {
			cubeToSolve.doUPrime(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doU(2);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doUPrime(1);
		}
		else if (colourRight == cubeToSolve.top.getPos(1, 2) && cubeToSolve.top.getPos(2, 2) == cubeToSolve.rightSide.getPos(0, 1)) {
			cubeToSolve.doU(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doU(2);
			//M'*2
			cubeToSolve.doL(2);
			cubeToSolve.doRPrime(2);
			cubeToSolve.rotateCubeUp(2);
			//end M'*2
			cubeToSolve.doU(1);
		}
		if (count == 20) {
			cubeToSolve.doU(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doUPrime(1);
		}
		if (count == 40) {
			cubeToSolve.doU(1);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doUPrime(1);
		}
		if (count == 60) {
			count = 0;
			for (int i = 0; i < 4; i++) {
				cubeToSolve.doU(1);
				//M'
				cubeToSolve.doL(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.rotateCubeUp(1);
				//end M'
				cubeToSolve.doUPrime(1);
				cubeToSolve.rotateCubeUp(1);
			}
			cubeToSolve.rotateCubeUp(1);
		}
		cubeToSolve.rotateCubeUp(1); 
		cubeToSolve.doL(1);
		if (count % 4 == 0) {
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
		}
		count++;
		
		bool bottomRedgeSolved = false;
		bool backRedgeSolved = false;
		bool frontRedgeSolved = false;
		bool topRedgeSolved = false;
		if (cubeToSolve.rightSide.getPos(2, 1) == cubeToSolve.rightSide.getPos(0, 0) && cubeToSolve.bottom.getPos(1, 2) == cubeToSolve.bottom.getPos(0, 0)) {
			bottomRedgeSolved = true;
		}
		if (cubeToSolve.rightSide.getPos(1, 0) == cubeToSolve.rightSide.getPos(0, 0) && cubeToSolve.front.getPos(1, 2) == cubeToSolve.front.getPos(0, 0)) {
			backRedgeSolved = true;
		}
		if (cubeToSolve.rightSide.getPos(1, 2) == cubeToSolve.rightSide.getPos(0, 0) && cubeToSolve.back.getPos(1, 0) == cubeToSolve.back.getPos(0, 0)) {
			frontRedgeSolved = true;
		}
		if (cubeToSolve.rightSide.getPos(0, 1) == cubeToSolve.rightSide.getPos(0, 0) && cubeToSolve.top.getPos(1, 2) == cubeToSolve.top.getPos(0, 0)) {
			topRedgeSolved = true;
		}

		if (bottomRedgeSolved && backRedgeSolved && frontRedgeSolved && topRedgeSolved) {
			redgesSolved = true;
		}
	}

	//Realign Corners
	bool cornersAligned = false;
	while (!cornersAligned) {
		if (cubeToSolve.top.getPos(0, 0) == cubeToSolve.top.getPos(0, 2)) {
			cornersAligned = true;
		}
		else {
			cubeToSolve.doR(1);
		}
	}
}

void CornersFirstSolver::solveLastLedge() {
	//last left edge

	for (int i = 0; i < 4; i++) {
		if (cubeToSolve.leftSide.getPos(0, 0) == cubeToSolve.leftSide.getPos(0, 1)) {
			break;
		}
		if (cubeToSolve.leftSide.getPos(0, 0) == cubeToSolve.front.getPos(2, 1)) {
			cubeToSolve.doUPrime(1);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doU(2);
			//M
			cubeToSolve.doLPrime(1);
			cubeToSolve.doR(1);
			cubeToSolve.rotateCubeUp(3);
			//end M
			cubeToSolve.doUPrime(1);
		}
		else if (cubeToSolve.leftSide.getPos(0, 0) == cubeToSolve.back.getPos(2, 1)) {
			cubeToSolve.doU(1);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doU(2);
			//M'
			cubeToSolve.doL(1);
			cubeToSolve.doRPrime(1);
			cubeToSolve.rotateCubeUp(1);
			//end M'
			cubeToSolve.doU(1);
		}
		//M'
		cubeToSolve.doL(1);
		cubeToSolve.doRPrime(1);
		cubeToSolve.rotateCubeUp(1);
		//end M'
	}
}

void CornersFirstSolver::flipMidges() {
	//flip middle edges in to the correct orientation for the last step

	bool midgesFlippedCorrectly = false;
	while (!midgesFlippedCorrectly) {
		for (int i = 0; i < 4; i++) {
			if (cubeToSolve.front.getPos(0, 1) != cubeToSolve.front.getPos(1, 1) && cubeToSolve.front.getPos(0, 1) != cubeToSolve.back.getPos(1, 1)) {
				if (cubeToSolve.back.getPos(0, 1) != cubeToSolve.front.getPos(1, 1) && cubeToSolve.back.getPos(0, 1) != cubeToSolve.back.getPos(1, 1)) {
					//M'
					cubeToSolve.doL(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.rotateCubeUp(1);
					//end M'
					cubeToSolve.doU(1);
					//M'
					cubeToSolve.doL(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.rotateCubeUp(1);
					//end M'
					cubeToSolve.doU(1);
					//M'
					cubeToSolve.doL(1);
					cubeToSolve.doRPrime(1);
					cubeToSolve.rotateCubeUp(1);
					//end M'
					cubeToSolve.doU(2);
					//M
					cubeToSolve.doLPrime(1);
					cubeToSolve.doR(1);
					cubeToSolve.rotateCubeUp(3);
					//end M
					cubeToSolve.doU(1);
					//M
					cubeToSolve.doLPrime(1);
					cubeToSolve.doR(1);
					cubeToSolve.rotateCubeUp(3);
					//end M
					cubeToSolve.doU(1);
					//M
					cubeToSolve.doLPrime(1);
					cubeToSolve.doR(1);
					cubeToSolve.rotateCubeUp(3);
					//end M
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
				//M'
				cubeToSolve.doL(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.rotateCubeUp(1);
				//end M'
				cubeToSolve.doU(1);
				//M'
				cubeToSolve.doL(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.rotateCubeUp(1);
				//end M'
				cubeToSolve.doU(1);
				//M'
				cubeToSolve.doL(1);
				cubeToSolve.doRPrime(1);
				cubeToSolve.rotateCubeUp(1);
				//end M'
				cubeToSolve.doU(2);
				//M
				cubeToSolve.doLPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.rotateCubeUp(3);
				//end M
				cubeToSolve.doU(1);
				//M
				cubeToSolve.doLPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.rotateCubeUp(3);
				//end M
				cubeToSolve.doU(1);
				//M
				cubeToSolve.doLPrime(1);
				cubeToSolve.doR(1);
				cubeToSolve.rotateCubeUp(3);
				//end M
				cubeToSolve.doU(2);
				cubeToSolve.rotateCubeUp(1);
			}
		}
	}
}

void CornersFirstSolver::completeCube() {
	for (int i = 0; i < 8; i++) {
		if (cubeToSolve.front.getPos(0, 1) == cubeToSolve.back.getPos(1, 1)) {
			if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.top.getPos(1, 1)) {
				if (cubeToSolve.top.getPos(0, 1) == cubeToSolve.bottom.getPos(1, 1)) {
					if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
						cubeToSolve.doU(2);
						//M
						cubeToSolve.doLPrime(1);
						cubeToSolve.doR(1);
						cubeToSolve.rotateCubeUp(3);
						//end M
						cubeToSolve.doU(2);
						//M'
						cubeToSolve.doL(1);
						cubeToSolve.doRPrime(1);
						cubeToSolve.rotateCubeUp(1);
						//end M'
					}
				}
				else if (cubeToSolve.front.getPos(2, 1) == cubeToSolve.back.getPos(1, 1)) {
					cubeToSolve.doU(2);
					//M'*2
					cubeToSolve.doL(2);
					cubeToSolve.doRPrime(2);
					cubeToSolve.rotateCubeUp(2);
					//end M'*2
					cubeToSolve.doU(2);
					//M'*2
					cubeToSolve.doL(2);
					cubeToSolve.doRPrime(2);
					cubeToSolve.rotateCubeUp(2);
					//end M'*2
				}
			}
			else if (cubeToSolve.top.getPos(2, 1) == cubeToSolve.bottom.getPos(1, 1)) {
				if (cubeToSolve.back.getPos(0, 1) == cubeToSolve.front.getPos(1, 1)) {
					if (cubeToSolve.top.getPos(0, 1) == cubeToSolve.top.getPos(1, 1)) {
						cubeToSolve.doU(2);
						//M'
						cubeToSolve.doL(1);
						cubeToSolve.doRPrime(1);
						cubeToSolve.rotateCubeUp(1);
						//end M'
						cubeToSolve.doU(2);
						//M
						cubeToSolve.doLPrime(1);
						cubeToSolve.doR(1);
						cubeToSolve.rotateCubeUp(3);
						//end M
					}
					else {
						//E
						cubeToSolve.doUPrime(1);
						cubeToSolve.doD(1);
						cubeToSolve.rotateCubeRight(3);
						//end E
						//E
						cubeToSolve.doUPrime(1);
						cubeToSolve.doD(1);
						cubeToSolve.rotateCubeRight(3);
						//end E
						//M
						cubeToSolve.doLPrime(1);
						cubeToSolve.doR(1);
						cubeToSolve.rotateCubeUp(3);
						//end M
						//E
						cubeToSolve.doUPrime(1);
						cubeToSolve.doD(1);
						cubeToSolve.rotateCubeRight(3);
						//end E
						//E
						cubeToSolve.doUPrime(1);
						cubeToSolve.doD(1);
						cubeToSolve.rotateCubeRight(3);
						//end E
						//M
						cubeToSolve.doLPrime(1);
						cubeToSolve.doR(1);
						cubeToSolve.rotateCubeUp(3);
						//end M
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
