// RubiksSolverActual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <Windows.h> // for sleep

#include "RubiksCube.h"
#include "Scrambler.h"
#include "BeginnersMethodSolver.h"
#include "CornersFirstSolver.h"
#include "RouxMethodSolver.h"
#include "ImprovedBeginners.h"
#include "ImprovedCornersFirst.h"
#include "ImprovedRoux.h"
#include "LowMovesBeginner.h"
#include "LowMovesCorners.h"
#include "LowMovesRoux.h"

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

	std::fstream fout;
	fout.open("Beginner.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";
		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testImprovedBeginnersMethod() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("BeginnerImproved.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		ImprovedBeginners solver;
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";
		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testLowMovesBeginnerMethod() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("LowMovesBeginner.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		LowMovesBeginner solver;
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";
		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testBeginnersCornersFirstMethod() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("Corners.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		CornersFirstSolver solver;
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.setCube(cube);
		solver.solveBottomCorners();
		solver.solveTopCorners();
		solver.solveThreeLedges();
		solver.solveRedges();
		solver.solveLastLedge();
		solver.flipMidges();
		solver.completeCube();
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testImprovedCornersFirstMethod() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("CornersImproved.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		ImprovedCornersFirst solver;
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.setCube(cube);
		solver.solveBottomCorners();
		solver.solveTopCorners();
		solver.solveThreeLedges();
		solver.solveRedges();
		solver.solveLastLedge();
		solver.flipMidges();
		solver.completeCube();
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testLowMovesCornersFirstMethod() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("LowMovesCorners.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		LowMovesCorners solver;
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.setCube(cube);
		solver.solveBottomCorners();
		solver.solveTopCorners();
		solver.solveThreeLedges();
		solver.solveRedges();
		solver.solveLastLedge();
		solver.flipMidges();
		solver.completeCube();
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testRoux() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("Roux.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		RouxMethodSolver solver;
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.solveBottomLeft();
		solver.solveBottomRight();
		solver.solveTopCorners();
		solver.solveTopCorners();
		solver.solveLastRedgeandLedge();
		solver.flipMidges();
		solver.completeCube();
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testImprovedRoux() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("RouxImproved.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		ImprovedRoux solver;
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.solveBottomLeft();
		solver.solveBottomRight();
		solver.solveTopCorners();
		solver.solveTopCorners();
		solver.solveLastRedgeandLedge();
		solver.flipMidges();
		solver.completeCube();
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testLowMovesRoux() {
	int numberValid = 0;
	int totalMoves = 0;
	float totalDuration = 0;
	int numberToTest = 1000;

	std::fstream fout;
	fout.open("LowMovesRoux.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

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

		LowMovesRoux solver;
		cube.resetMoves();
		solver.setCube(cube);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		solver.solveBottomLeft();
		solver.solveBottomRight();
		solver.solveTopCorners();
		solver.solveTopCorners();
		solver.solveLastRedgeandLedge();
		solver.flipMidges();
		solver.completeCube();
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

		fout << i << "," << duration.count() << "," << cube.getNumMoves() << "\n";

		totalMoves += cube.getNumMoves();
		totalDuration += duration.count();

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Out of " << numberToTest << " there were " << numberValid << " valid cubes" << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

int main() {
	std::cout << "Hello World! \n";

	//testBeginnersMethod();
	//testBeginnersCornersFirstMethod();
	//testRoux();

	//testImprovedBeginnersMethod();
	//testImprovedCornersFirstMethod();
	//testImprovedRoux();

	testLowMovesBeginnerMethod();
	//testLowMovesCornersFirstMethod();
	//testLowMovesRoux();

    return 0;
}



