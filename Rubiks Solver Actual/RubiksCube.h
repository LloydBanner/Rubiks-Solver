#pragma once
#include "Face.h"
#include <string>

class RubiksCube {
public:
	int width = 3;
	int height = 3;
	std::string moves = "";
	int numMoves = 0;
	Face front = Face("front");
	Face back = Face("back");
	Face leftSide = Face("leftSide");
	Face rightSide = Face("rightSide");
	Face top = Face("top");
	Face bottom = Face("bottom");
	Face temp = Face("temp");
	Face faces[7] = { front, back, leftSide, rightSide, top, bottom, temp };

	RubiksCube();
	~RubiksCube();
	void rotateCubeRight(int num);
	void rotateCubeLeft(int num);
	void rotateCubeUp(int num);
	void rotateCubeDown(int num);
	void doR(int num);
	void doRPrime(int num);
	void doL(int num);
	void doLPrime(int num);
	void doF(int num);
	void doFPrime(int num);
	void doB(int num);
	void doBPrime(int num);
	void doU(int num);
	void doUPrime(int num);
	void doD(int num);
	void doDPrime(int num);
	void doM(int num);
	void doMPrime(int num);
	void doE(int num);
	void doEPrime(int num);
	std::string getMoves();
	int getNumMoves();
	void resetMoves();
};

