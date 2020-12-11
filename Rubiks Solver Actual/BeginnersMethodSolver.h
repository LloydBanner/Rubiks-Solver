#pragma once

#include <string>;
#include "RubiksCube.h"
#include "Face.h"

class BeginnersMethodSolver{
public:
	RubiksCube cubeToSolve;
	std::string sequence;

	BeginnersMethodSolver();
	void SolveCross(char colour);
	void setCube(RubiksCube cube);
	RubiksCube getCube();
	~BeginnersMethodSolver();
};

