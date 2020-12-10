#include "stdafx.h"
#include "BeginnersMethodSolver.h"


BeginnersMethodSolver::BeginnersMethodSolver(){
}

void BeginnersMethodSolver::SolveCross(char colour) {
	//char colour = cubeToSolve.top.getPos(1, 1);
	int edges[4][2] = { {0,1}, {1,0}, {1,2}, {2,1} };

	//for (auto face : faces) {
		//for (auto edge : edges) {

		//}
	//}
}

void BeginnersMethodSolver::setCube(RubiksCube cube) {
	cubeToSolve = cube;
}

RubiksCube BeginnersMethodSolver::getCube() {
	return cubeToSolve;
}

BeginnersMethodSolver::~BeginnersMethodSolver(){
}
