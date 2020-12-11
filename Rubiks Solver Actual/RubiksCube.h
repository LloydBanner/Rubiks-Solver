#pragma once
#include "Face.h"
class RubiksCube {
public:
	int width = 3;
	int height = 3;
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
	void rotateCubeUp(int num);
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
};

