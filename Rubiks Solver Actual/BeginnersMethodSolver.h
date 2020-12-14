#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class BeginnersMethodSolver{
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	BeginnersMethodSolver();
	void solveCross();
	void solverTopCorners();
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~BeginnersMethodSolver();
};

