#include "stdafx.h"
#include "Scrambler.h"


Scrambler::Scrambler()
{
}

void Scrambler::setCube(RubiksCube cube) {
	cubeToScramble = cube;
}


void Scrambler::scramble(int num) {
	sequence = "";
	srand((unsigned)time(0));
	for (int i = 0; i < num; i++) {
		int ran = rand() % 12;
		switch (ran) {
		case 0:
			cubeToScramble.doR(1);
			sequence += "R,";
			break;
		case 1:
			cubeToScramble.doRPrime(1);
			sequence += "R',";
			break;
		case 2:
			cubeToScramble.doL(1);
			sequence += "L,";
			break;
		case 3:
			cubeToScramble.doLPrime(1);
			sequence += "L',";
			break;
		case 4:
			cubeToScramble.doF(1);
			sequence += "F,";
			break;
		case 5:
			cubeToScramble.doFPrime(1);
			sequence += "F',";
			break;
		case 6:
			cubeToScramble.doB(1);
			sequence += "B,";
			break;
		case 7:
			cubeToScramble.doBPrime(1);
			sequence += "B',";
			break;
		case 8:
			cubeToScramble.doU(1);
			sequence += "U,";
			break;
		case 9:
			cubeToScramble.doUPrime(1);
			sequence += "U',";
			break;
		case 10:
			cubeToScramble.doD(1);
			sequence += "D,";
			break;
		case 11:
			cubeToScramble.doDPrime(1);
			sequence += "D',";
			break;
		}
	}
}

RubiksCube Scrambler::getCube() {
	return cubeToScramble;
}

std::string Scrambler::getSequence() {
	return sequence;
}

Scrambler::~Scrambler()
{
}
