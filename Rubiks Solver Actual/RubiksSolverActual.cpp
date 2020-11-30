// RubiksSolverActual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "RubiksCube.h"


int main() {
	std::cout << "Hello World! \n";
	RubiksCube cube; 
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
	cube.doLPrime(1);
	cube.doR(1);
	cube.doDPrime(1);
	cube.doD(1);
	cube.doFPrime(1);
	//std::cout << cube.getFrontPos(0, 2), "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.getFrontPos(i,j), "\n";
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

