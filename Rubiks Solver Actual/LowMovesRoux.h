#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class LowMovesRoux {
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	LowMovesRoux();
	void solveBottomLeft();
	void solveBottomRight();
	void solveTopCorners();
	void solveLastRedgeandLedge();
	void flipMidges();
	void completeCube();
	bool isSolutionValid();
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~LowMovesRoux();
};

