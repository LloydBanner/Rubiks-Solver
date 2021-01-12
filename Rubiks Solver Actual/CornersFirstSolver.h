#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class CornersFirstSolver
{
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	CornersFirstSolver();

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
	~CornersFirstSolver();
};

