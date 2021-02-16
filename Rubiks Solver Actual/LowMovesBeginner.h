#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class LowMovesBeginner {
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	LowMovesBeginner();
	void solveCross();
	void solverTopCorners();
	void solveMiddleLayer();
	void solveFinalface();
	void completeCorners();
	void completeEdges();
	bool isSolutionValid();
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~LowMovesBeginner();
};
