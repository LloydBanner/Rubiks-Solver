#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class ImprovedCornersFirst {
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	ImprovedCornersFirst();

	void solveBottomCorners();
	void solveTopCorners();
	void solveThreeLedges();
	void solveRedges();
	void solveLastLedge();
	void flipMidges();
	void completeCube();
	bool isSolutionValid();
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~ImprovedCornersFirst();
};


