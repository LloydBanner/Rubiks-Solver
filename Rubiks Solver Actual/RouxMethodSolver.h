#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class RouxMethodSolver
{
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	RouxMethodSolver();
	void solveBottomLeft();
	void solveBottomRight();
	bool isSolutionValid();
	void setCube(RubiksCube cube);
	void solveTopCorners();
	RubiksCube getCube();
	~RouxMethodSolver();
};

