#pragma once
#include <string>;
#include <ctime>
#include "RubiksCube.h"
#include <vector>

class Scrambler{
public:
	RubiksCube cubeToScramble;
	std::string sequence;

	Scrambler();
	void setCube(RubiksCube cube);
	void scramble(int num);
	RubiksCube getCube();
	std::string getSequence();
	void useSequence(std::string sequence);
	~Scrambler();
};

