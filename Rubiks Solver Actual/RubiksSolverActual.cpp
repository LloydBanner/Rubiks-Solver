// RubiksSolverActual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "RubiksCube.h"
#include "Scrambler.h"
#include "BeginnersMethodSolver.h"

void printCube(RubiksCube cube) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.front.getPos(i, j);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.back.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.leftSide.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.rightSide.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.top.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.bottom.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main() {
	std::cout << "Hello World! \n";
	RubiksCube cube; 
	Scrambler scrambler;

	std::cout << "initial cube" << "\n";
	printCube(cube);

	std::cout << "\n";
	scrambler.setCube(cube);
	scrambler.scramble(20);
	std::string sequence = scrambler.getSequence();
	std::cout << sequence;
	std::cout << "\n";
	std::cout << "\n";

	cube = scrambler.getCube(); 


	std::cout << "Scrambled cube" << "\n";
	printCube(cube);

	BeginnersMethodSolver solver;
	solver.setCube(cube);
	solver.solveCross();
	solver.solverTopCorners();
	solver.solveMiddleLayer();
	cube = solver.getCube();

	std::cout << "Final cube" << "\n";
	printCube(cube);
	
    return 0;
}



