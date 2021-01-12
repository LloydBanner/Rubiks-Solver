// RubiksSolverActual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>

#include "RubiksCube.h"
#include "Scrambler.h"
#include "BeginnersMethodSolver.h"
#include "CornersFirstSolver.h"

void printCube(RubiksCube cube) {
	std::cout << "front" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.front.getPos(i, j);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "back" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.back.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "left" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.leftSide.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "right" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.rightSide.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "top" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.top.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "bottom" << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cube.bottom.getPos(i, j), "\n";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void testBeginnersMethod() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	for (int i = 0; i < numberToTest; i++) {
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
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.solveCross();
		solver.solverTopCorners();
		solver.solveMiddleLayer();
		solver.solveFinalface();
		solver.completeCorners();
		solver.completeEdges();
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

		if (solver.isSolutionValid()) {
			numberValid += 1;
		}
		cube = solver.getCube();
		//std::cout << "Solved in " << cube.getNumMoves() << " moves" << "\n";
		//std::cout << cube.getMoves() << "\n";

		std::chrono::duration<double, std::milli> duration = end - start;

		std::cout << "Final cube: took " << duration.count() << "ms to solve" << "\n";
		printCube(cube);

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();
	}

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testCornersFirst() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

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

	CornersFirstSolver solver;

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	solver.setCube(cube);
	solver.solveBottomCorners();
	solver.solveTopCorners();
	solver.solveThreeLedges();
	solver.solveRedges();
	std::cout << "Before last ledge" << "\n";
	solver.solveLastLedge();
	std::cout << "Before midges" << "\n";
	printCube(solver.getCube());
	solver.flipMidges();
	std::cout << "After midges" << "\n";
	printCube(solver.getCube());
	solver.completeCube();
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	cube = solver.getCube();

	std::chrono::duration<double, std::milli> duration = end - start;

	std::cout << "Current Solution cube took " << duration.count() << "ms" << "\n";
	printCube(cube);
}

int main() {
	std::cout << "Hello World! \n";

	testCornersFirst();

    return 0;
}



