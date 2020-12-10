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
			std::cout << cube.front.getPos(i, j), "\n";
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
	scrambler.setCube(cube);
	//scrambler.scramble(3);
	cube = scrambler.getCube();
	cube.doFPrime(1);
	cube.doB(1);
	cube.doU(1);
	//cube.faces[0].setPos(1,1,'T');
	cube.rotateCubeRight(1);
	std::string sequence = scrambler.getSequence();
	std::cout << sequence; 
	std::cout << "\n";
	std::cout << "\n";

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
    return 0;
}

