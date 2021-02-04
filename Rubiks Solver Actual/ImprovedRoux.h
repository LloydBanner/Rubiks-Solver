#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class ImprovedRoux {
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	ImprovedRoux();
	void solveBottomLeft();
	void solveBottomRight();
	void solveTopCorners();
	void solveLastRedgeandLedge();
	void flipMidges();
	void completeCube();
	bool isSolutionValid();
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~ImprovedRoux();
};
