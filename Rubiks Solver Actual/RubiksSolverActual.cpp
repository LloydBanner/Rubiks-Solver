// RubiksSolverActual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <Windows.h> // for sleep
#include <thread>

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

std::chrono::duration<double, std::milli> durationThread1;
int movesThread1;
std::chrono::duration<double, std::milli> durationThread2;
int movesThread2;
std::chrono::duration<double, std::milli> durationThread3;
int movesThread3;
std::chrono::duration<double, std::milli> durationThread4;
int movesThread4;
std::chrono::duration<double, std::milli> durationThread5;
int movesThread5;
std::chrono::duration<double, std::milli> durationThread6;
int movesThread6;

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

void beginnerThread1(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

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
	cube = solver.getCube();
	durationThread1 = end - start;
	movesThread1 = cube.getNumMoves();
}

void beginnerThread2(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesBeginner solver;
	cube.rotateCubeUp(1);
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
	cube = solver.getCube();
	durationThread2 = end - start;
	movesThread2 = cube.getNumMoves();
}

void beginnerThread3(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesBeginner solver;
	cube.rotateCubeUp(2);
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
	cube = solver.getCube();
	durationThread3 = end - start;
	movesThread3 = cube.getNumMoves();
}

void beginnerThread4(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesBeginner solver;
	cube.rotateCubeDown(1);
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
	cube = solver.getCube();
	durationThread4 = end - start;
	movesThread4 = cube.getNumMoves();
}

void beginnerThread5(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesBeginner solver;
	cube.rotateCubeRight(1);
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
	cube = solver.getCube();
	durationThread5 = end - start;
	movesThread5 = cube.getNumMoves();
}

void beginnerThread6(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesBeginner solver;
	cube.rotateCubeLeft(1);
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
	cube = solver.getCube();
	durationThread6 = end - start;
	movesThread6 = cube.getNumMoves();
}

void multithreadBeginner() {
	int numberToTest = 1000;
	int totalMoves = 0;
	float totalDuration = 0;

	std::fstream fout;
	fout.open("threadedBeginner.csv", std::ios::out);
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

		std::thread t1(beginnerThread1, sequence);
		std::thread t2(beginnerThread2, sequence);
		std::thread t3(beginnerThread3, sequence);
		std::thread t4(beginnerThread4, sequence);
		std::thread t5(beginnerThread5, sequence);
		std::thread t6(beginnerThread6, sequence);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();

		double durationThread[6];
		durationThread[0] = durationThread1.count();
		durationThread[1] = durationThread2.count();
		durationThread[2] = durationThread3.count();
		durationThread[3] = durationThread4.count();
		durationThread[4] = durationThread5.count();
		durationThread[5] = durationThread6.count();

		int movesThread[6];
		movesThread[0] = movesThread1;
		movesThread[1] = movesThread2;
		movesThread[2] = movesThread3;
		movesThread[3] = movesThread4;
		movesThread[4] = movesThread5;
		movesThread[5] = movesThread6;

		double lowestDuration = 1000000;
		int moves = 100000;
		for (int i = 0; i < 6; i++) {
			if (durationThread[i] < lowestDuration) {
				lowestDuration = durationThread[i];
				moves = movesThread[i];
			}
		}

		fout << i << "," << lowestDuration << "," << moves << "\n";

		std::cout << "Final cube: took " << lowestDuration << "ms to solve" << " Moves: " << moves << "\n";
		printCube(cube);

		totalMoves += moves;
		totalDuration += lowestDuration;

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Solved Cubes: " << numberToTest << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void cornerThread1(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

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
	cube = solver.getCube();
	durationThread1 = end - start;
	movesThread1 = cube.getNumMoves();
}

void cornerThread2(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesCorners solver;
	cube.rotateCubeUp(1);
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
	cube = solver.getCube();
	durationThread2 = end - start;
	movesThread2 = cube.getNumMoves();
}

void cornerThread3(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesCorners solver;
	cube.rotateCubeUp(2);
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
	cube = solver.getCube();
	durationThread3 = end - start;
	movesThread3 = cube.getNumMoves();
}

void cornerThread4(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesCorners solver;
	cube.rotateCubeDown(1);
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
	cube = solver.getCube();
	durationThread4 = end - start;
	movesThread4 = cube.getNumMoves();
}

void cornerThread5(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesCorners solver;
	cube.rotateCubeRight(1);
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
	cube = solver.getCube();
	durationThread5 = end - start;
	movesThread5 = cube.getNumMoves();
}

void cornerThread6(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

	LowMovesCorners solver;
	cube.rotateCubeLeft(1);
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
	cube = solver.getCube();
	durationThread6 = end - start;
	movesThread6 = cube.getNumMoves();
}

void multithreadCorners() {
	int numberToTest = 1000;
	int totalMoves = 0;
	float totalDuration = 0;

	std::fstream fout;
	fout.open("threadedCorners.csv", std::ios::out);
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

		std::thread t1(cornerThread1, sequence);
		std::thread t2(cornerThread2, sequence);
		std::thread t3(cornerThread3, sequence);
		std::thread t4(cornerThread4, sequence);
		std::thread t5(cornerThread5, sequence);
		std::thread t6(cornerThread6, sequence);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();

		double durationThread[6];
		durationThread[0] = durationThread1.count();
		durationThread[1] = durationThread2.count();
		durationThread[2] = durationThread3.count();
		durationThread[3] = durationThread4.count();
		durationThread[4] = durationThread5.count();
		durationThread[5] = durationThread6.count();

		int movesThread[6];
		movesThread[0] = movesThread1;
		movesThread[1] = movesThread2;
		movesThread[2] = movesThread3;
		movesThread[3] = movesThread4;
		movesThread[4] = movesThread5;
		movesThread[5] = movesThread6;

		double lowestDuration = 1000000;
		int moves = 100000;
		for (int i = 0; i < 6; i++) {
			if (durationThread[i] < lowestDuration) {
				lowestDuration = durationThread[i];
				moves = movesThread[i];
			}
		}

		fout << i << "," << lowestDuration << "," << moves << "\n";

		std::cout << "Final cube: took " << lowestDuration << "ms to solve" << " Moves: " << moves << "\n";
		printCube(cube);

		totalMoves += moves;
		totalDuration += lowestDuration;

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Solved Cubes: " << numberToTest << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void rouxThread1(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	cube = scrambler.getCube();

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
	cube = solver.getCube();
	durationThread1 = end - start;
	movesThread1 = cube.getNumMoves();
}

void rouxThread2(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	LowMovesRoux solver;
	cube.rotateCubeUp(1);
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
	cube = solver.getCube();
	durationThread2 = end - start;
	movesThread2 = cube.getNumMoves();
}

void rouxThread3(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	LowMovesRoux solver;
	cube.rotateCubeUp(2);
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
	cube = solver.getCube();
	durationThread3 = end - start;
	movesThread3 = cube.getNumMoves();
}

void rouxThread4(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	LowMovesRoux solver;
	cube.rotateCubeDown(1);
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
	cube = solver.getCube();
	durationThread4 = end - start;
	movesThread4 = cube.getNumMoves();
}

void rouxThread5(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	LowMovesRoux solver;
	cube.rotateCubeRight(1);
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
	cube = solver.getCube();
	durationThread5 = end - start;
	movesThread5 = cube.getNumMoves();
}

void rouxThread6(std::string sequence) {
	RubiksCube cube;
	Scrambler scrambler;

	scrambler.setCube(cube);
	scrambler.useSequence(sequence);

	LowMovesRoux solver;
	cube.rotateCubeLeft(1);
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
	cube = solver.getCube();
	durationThread6 = end - start;
	movesThread6 = cube.getNumMoves();
}

void multithreadRoux() {
	int numberToTest = 1000;
	int totalMoves = 0;
	float totalDuration = 0;

	std::fstream fout;
	fout.open("threadedRoux.csv", std::ios::out);
	fout << "Cube Number" << "," << "Solve Time (ms)" << "," << "Number of Moves" << "\n";

	for (int i = 0; i < numberToTest;  i++) {
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

		std::thread t1(rouxThread1, sequence);
		std::thread t2(rouxThread2, sequence);
		std::thread t3(rouxThread3, sequence);
		std::thread t4(rouxThread4, sequence);
		std::thread t5(rouxThread5, sequence);
		std::thread t6(rouxThread6, sequence);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();

		double durationThread[6];
		durationThread[0] = durationThread1.count();
		durationThread[1] = durationThread2.count();
		durationThread[2] = durationThread3.count();
		durationThread[3] = durationThread4.count();
		durationThread[4] = durationThread5.count();
		durationThread[5] = durationThread6.count();

		int movesThread[6];
		movesThread[0] = movesThread1;
		movesThread[1] = movesThread2;
		movesThread[2] = movesThread3;
		movesThread[3] = movesThread4;
		movesThread[4] = movesThread5;
		movesThread[5] = movesThread6;

		double lowestDuration = 1000000;
		int moves = 100000;
		for (int i = 0; i < 6; i++) {
			if (durationThread[i] < lowestDuration) {
				lowestDuration = durationThread[i];
				moves = movesThread[i];
			}
		}

		fout << i << "," << lowestDuration << "," << moves << "\n";

		std::cout << "Final cube: took " << lowestDuration << "ms to solve" << " Moves: " << moves << "\n";
		printCube(cube);

		totalMoves += moves;
		totalDuration += lowestDuration;

		Sleep(1000); //Delay to allow for random cube seed change
	}

	fout.close();

	float averageDuration = totalDuration / numberToTest;
	std::cout << "Solved Cubes: " << numberToTest << "\n";
	std::cout << "Average number of moves was " << totalMoves / numberToTest << "\n";
	std::cout << "Average time to solve was " << averageDuration << "ms" << "\n";
}

void testStepsLowBeginnersMethod() {
	int numberToTest = 1000;
	float totalDurationCross = 0;
	float totalDurationTopCorners = 0;
	float totalDurationMiddleLayer = 0;
	float totalDurationFinalface = 0;
	float totalDurationCompleteCorners = 0;
	float totalDurationCompleteEdges = 0;

	int totalMovesCross = 0;
	int totalMovesTopCorners = 0;
	int totalMovesMiddleLayer = 0;
	int totalMovesFinalface = 0;
	int totalMovesCompleteCorners = 0;
	int totalMovesCompleteEdges = 0;

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
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationCross = end - start;
		int movesCross = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solverTopCorners();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationTopCorners = end - start;
		int movesTopCorners = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveMiddleLayer();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationMiddleLayer = end - start;
		int movesMiddleLayer = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveFinalface();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationFinalface = end - start;
		int movesFinalface = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.completeCorners();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationCompleteCorners = end - start;
		int movesCompleteCorners = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.completeEdges();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationCompleteEdges = end - start;
		int movesCompleteEdges = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);

		cube = solver.getCube();

		std::cout << "Final cube: \n";
		printCube(cube);

		totalDurationCross += durationCross.count();
		totalDurationTopCorners += durationTopCorners.count();
		totalDurationMiddleLayer += durationMiddleLayer.count();
		totalDurationFinalface += durationFinalface.count();
		totalDurationCompleteCorners += durationCompleteCorners.count();
		totalDurationCompleteEdges += durationCompleteEdges.count();

		totalMovesCross += movesCross;
		totalMovesTopCorners += movesTopCorners;
		totalMovesMiddleLayer += movesMiddleLayer;
		totalMovesFinalface += movesFinalface;
		totalMovesCompleteCorners += movesCompleteCorners;
		totalMovesCompleteEdges += movesCompleteEdges;

		Sleep(1000); //Delay to allow for random cube seed change
	}

	float averageDurationCross = totalDurationCross / numberToTest;
	float averageDurationTopCorners = totalDurationTopCorners / numberToTest;
	float averageDurationMiddleLayer = totalDurationMiddleLayer / numberToTest;
	float averageDurationFinalface = totalDurationFinalface / numberToTest;
	float averageDurationCompleteCorners = totalDurationCompleteCorners / numberToTest;
	float averageDurationCompleteEdges = totalDurationCompleteEdges / numberToTest;

	float averageMovesCross = totalMovesCross / numberToTest;
	float averageMovesTopCorners = totalMovesTopCorners / numberToTest;
	float averageMovesMiddleLayer = totalMovesMiddleLayer / numberToTest;
	float averageMovesFinalface = totalMovesFinalface / numberToTest;
	float averageMovesCompleteCorners = totalMovesCompleteCorners / numberToTest;
	float averageMovesCompleteEdges = totalMovesCompleteEdges / numberToTest;

	std::cout << "Out of " << numberToTest << " there were " << numberToTest << " cubes solved" << "\n";
	std::cout << "Average number of moves for the bottom corners step was " << averageMovesCross << "\n";
	std::cout << "Average time to solve for the bottom corners step was " << averageDurationCross << "ms" << "\n";
	std::cout << "Average number of moves for the top corners step was " << averageMovesTopCorners << "\n";
	std::cout << "Average time to solve for the top corners step was " << averageDurationTopCorners << "ms" << "\n";
	std::cout << "Average number of moves for the three ledges step was " << averageMovesMiddleLayer << "\n";
	std::cout << "Average time to solve for the three ledges step was " << averageDurationMiddleLayer << "ms" << "\n";
	std::cout << "Average number of moves for the redges step was " << averageMovesFinalface << "\n";
	std::cout << "Average time to solve for the redges step was " << averageDurationFinalface << "ms" << "\n";
	std::cout << "Average number of moves for the last ledge step was " << averageMovesCompleteCorners << "\n";
	std::cout << "Average time to solve for the last ledge step was " << averageDurationCompleteCorners << "ms" << "\n";
	std::cout << "Average number of moves for the midges step was " << averageMovesCompleteEdges << "\n";
	std::cout << "Average time to solve for the midges step was " << averageDurationCompleteEdges << "ms" << "\n";
}

void testStepsLowCornersFirstMethod() {
	int numberToTest = 1000;
	float totalDurationBottomCorners = 0;
	float totalDurationTopCorners = 0;
	float totalDurationThreeLedges = 0;
	float totalDurationRedges = 0;
	float totalDurationLastLedge = 0;
	float totalDurationMidges = 0;
	float totalDurationEnd = 0;

	int totalMovesBottomCorners = 0;
	int totalMovesTopCorners = 0;
	int totalMovesThreeLedges = 0;
	int totalMovesRedges = 0;
	int totalMovesLastLedge = 0;
	int totalMovesMidges = 0;
	int totalMovesEnd = 0;

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
		solver.solveBottomCorners();
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationBottomCorners = end - start;
		int movesBottomCorners = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveTopCorners();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationTopCorners = end - start;
		int movesTopCorners = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveThreeLedges();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationThreeLedges = end - start;
		int movesThreeLedges = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveRedges();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationRedges = end - start;
		int movesRedges = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveLastLedge();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationLastLedge = end - start;
		int movesLastLedge = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.flipMidges();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationMidges = end - start;
		int movesMidges = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.completeCube();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationEnd = end - start;
		int movesEnd = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);

		cube = solver.getCube();

		std::cout << "Final cube: \n";
		printCube(cube);

		totalDurationBottomCorners += durationBottomCorners.count();
		totalDurationTopCorners += durationTopCorners.count();
		totalDurationThreeLedges += durationThreeLedges.count();
		totalDurationRedges += durationRedges.count();
		totalDurationLastLedge += durationLastLedge.count();
		totalDurationMidges += durationMidges.count();
		totalDurationEnd += durationEnd.count();

		totalMovesBottomCorners += movesBottomCorners;
		totalMovesTopCorners += movesTopCorners;
		totalMovesThreeLedges += movesThreeLedges;
		totalMovesRedges += movesRedges;
		totalMovesLastLedge += movesLastLedge;
		totalMovesMidges += movesMidges;
		totalMovesEnd += movesEnd;

		Sleep(1000); //Delay to allow for random cube seed change
	}

	float averageDurationBottomCorners = totalDurationBottomCorners / numberToTest;
	float averageDurationTopCorners = totalDurationTopCorners / numberToTest;
	float averageDurationThreeLedges = totalDurationThreeLedges / numberToTest;
	float averageDurationRedges = totalDurationRedges / numberToTest;
	float averageDurationLastLedge = totalDurationLastLedge / numberToTest;
	float averageDurationMidges = totalDurationMidges / numberToTest;
	float averageDurationEnd = totalDurationEnd / numberToTest;

	float averageMovesBottomCorners = totalMovesBottomCorners / numberToTest;
	float averageMovesTopCorners = totalMovesTopCorners / numberToTest;
	float averageMovesThreeLedges = totalMovesThreeLedges / numberToTest;
	float averageMovesRedges = totalMovesRedges / numberToTest;
	float averageMovesLastLedge = totalMovesLastLedge / numberToTest;
	float averageMovesMidges = totalMovesMidges / numberToTest;
	float averageMovesEnd = totalMovesEnd / numberToTest;

	std::cout << "Out of " << numberToTest << " there were " << numberToTest << " cubes solved" << "\n";
	std::cout << "Average number of moves for the bottom corners step was " << averageMovesBottomCorners << "\n";
	std::cout << "Average time to solve for the bottom corners step was " << averageDurationBottomCorners << "ms" << "\n";
	std::cout << "Average number of moves for the top corners step was " << averageMovesTopCorners << "\n";
	std::cout << "Average time to solve for the top corners step was " << averageDurationTopCorners << "ms" << "\n";
	std::cout << "Average number of moves for the three ledges step was " << averageMovesThreeLedges << "\n";
	std::cout << "Average time to solve for the three ledges step was " << averageDurationThreeLedges << "ms" << "\n";
	std::cout << "Average number of moves for the redges step was " << averageMovesRedges << "\n";
	std::cout << "Average time to solve for the redges step was " << averageDurationRedges << "ms" << "\n";
	std::cout << "Average number of moves for the last ledge step was " << averageMovesLastLedge << "\n";
	std::cout << "Average time to solve for the last ledge step was " << averageDurationLastLedge << "ms" << "\n";
	std::cout << "Average number of moves for the midges step was " << averageMovesMidges << "\n";
	std::cout << "Average time to solve for the midges step was " << averageDurationMidges << "ms" << "\n";
	std::cout << "Average number of moves for the end step was " << averageMovesEnd << "\n";
	std::cout << "Average time to solve for the end step was " << averageDurationEnd << "ms" << "\n";
}

void testStepsLowMovesRoux() {
	int numberToTest = 1000;
	float totalDurationBottomLeft = 0;
	float totalDurationBottomRight = 0;
	float totalDurationTopCorners = 0;
	float totalDurationRedgeandLedge = 0;
	float totalDurationMidges = 0;
	float totalDurationEnd = 0;

	int totalMovesBottomLeft = 0;
	int totalMovesBottomRight = 0;
	int totalMovesTopCorners = 0;
	int totalMovesRedgeandLedge = 0;
	int totalMovesMidges = 0;
	int totalMovesEnd = 0;

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
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationBottomLeft = end - start;
		int movesBottomLeft = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveBottomRight();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationBottomRight = end - start;
		int movesBottomRight = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveTopCorners();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationTopCorners = end - start;
		int movesTopCorners = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.solveLastRedgeandLedge();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationRedgeandLedge = end - start;
		int movesRedgeandLedge = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.flipMidges();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationMidges = end - start;
		int movesMidges = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);
		start = std::chrono::high_resolution_clock::now();
		solver.completeCube();
		end = std::chrono::high_resolution_clock::now();
		cube = solver.getCube();
		std::chrono::duration<double, std::milli> durationEnd = end - start;
		int movesEnd = cube.getNumMoves();
		cube.resetMoves();
		solver.setCube(cube);

		cube = solver.getCube();

		std::cout << "Final cube: \n";
		printCube(cube);

		totalDurationBottomLeft += durationBottomLeft.count();
		totalDurationBottomRight += durationBottomRight.count();
		totalDurationTopCorners += durationTopCorners.count();
		totalDurationRedgeandLedge += durationRedgeandLedge.count();
		totalDurationMidges += durationMidges.count();
		totalDurationEnd += durationEnd.count();

		totalMovesBottomLeft += movesBottomLeft;
		totalMovesBottomRight += movesBottomRight;
		totalMovesTopCorners += movesTopCorners;
		totalMovesRedgeandLedge += movesRedgeandLedge;
		totalMovesMidges += movesMidges;
		totalMovesEnd += movesEnd;

		Sleep(1000); //Delay to allow for random cube seed change
	}

	float averageDurationBottomLeft = totalDurationBottomLeft / numberToTest;
	float averageDurationBottomRight = totalDurationBottomRight / numberToTest;
	float averageDurationTopCorners = totalDurationTopCorners / numberToTest;
	float averageDurationRedgeandLedge = totalDurationRedgeandLedge / numberToTest;
	float averageDurationMidges = totalDurationMidges / numberToTest;
	float averageDurationEnd = totalDurationEnd / numberToTest;

	float averageMovesBottomLeft = totalMovesBottomLeft / numberToTest;
	float averageMovesBottomRight = totalMovesBottomRight / numberToTest;
	float averageMovesTopCorners = totalMovesTopCorners / numberToTest;
	float averageMovesRedgeandLedge = totalMovesRedgeandLedge / numberToTest;
	float averageMovesMidges = totalMovesMidges / numberToTest;
	float averageMovesEnd = totalMovesEnd / numberToTest;

	std::cout << "Out of " << numberToTest << " there were " << numberToTest << " cubes solved" << "\n";
	std::cout << "Average number of moves for the bottom left step was " << averageMovesBottomLeft << "\n";
	std::cout << "Average time to solve for the bottom left step was " << averageDurationBottomLeft << "ms" << "\n";
	std::cout << "Average number of moves for the bottom right step was " << averageMovesBottomRight << "\n";
	std::cout << "Average time to solve for the bottom right step was " << averageDurationBottomRight << "ms" << "\n";
	std::cout << "Average number of moves for the top corners step was " << averageMovesTopCorners << "\n";
	std::cout << "Average time to solve for the top corners step was " << averageDurationTopCorners << "ms" << "\n";
	std::cout << "Average number of moves for the redge and ledge step was " << averageMovesRedgeandLedge << "\n";
	std::cout << "Average time to solve for the redge and ledge step was " << averageDurationRedgeandLedge << "ms" << "\n";
	std::cout << "Average number of moves for the midges step was " << averageMovesMidges << "\n";
	std::cout << "Average time to solve for the midges step was " << averageDurationMidges << "ms" << "\n";
	std::cout << "Average number of moves for the end step was " << averageMovesEnd << "\n";
	std::cout << "Average time to solve for the end step was " << averageDurationEnd << "ms" << "\n";
}

int main() {
	std::cout << "Hello World! \n";

	//testBeginnersMethod();
	//testBeginnersCornersFirstMethod();
	//testRoux();

	//testImprovedBeginnersMethod();
	//testImprovedCornersFirstMethod();
	//testImprovedRoux();

	//testLowMovesBeginnerMethod();
	//testLowMovesCornersFirstMethod();
	//testLowMovesRoux();

	//multithreadBeginner();
	//multithreadCorners();
	//multithreadRoux();

	testStepsLowBeginnersMethod();
	//testStepsLowCornersFirstMethod();
	//testStepsLowMovesRoux();

    return 0;
}



