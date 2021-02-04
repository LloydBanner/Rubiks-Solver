#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class RouxMethodSolver {
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	RouxMethodSolver();
	void solveBottomLeft();
	void solveBottomRight();
	void solveTopCorners();
	void solveLastRedgeandLedge();
	void flipMidges();
	void completeCube();
	bool isSolutionValid();
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~RouxMethodSolver();
};

