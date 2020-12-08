// RubiksSolverActual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "RubiksCube.h"
#include "Scrambler.h"


int main() {
	std::cout << "Hello World! \n";
	RubiksCube cube; 
	Scrambler scrambler;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getFrontPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getBackPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getLeftSidePos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getRightSidePos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getTopPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getBottomPos(i, j), "\n";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
	scrambler.setCube(cube);
	//scrambler.scramble(3);
	cube = scrambler.getCube();
	cube.doFPrime(1);
	cube.doB(1);
	cube.doU(1);
	cube.rotateCubeRight(1);
	std::string sequence = scrambler.getSequence();
	std::cout << sequence; 
	std::cout << "\n";
	std::cout << "\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getFrontPos(i, j);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getBackPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getLeftSidePos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getRightSidePos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getTopPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getBottomPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
    return 0;
}

