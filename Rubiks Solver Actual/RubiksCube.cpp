#include "stdafx.h"
#include "RubiksCube.h"
#include <iostream>


RubiksCube::RubiksCube() {
	for (int i = 0; i < width*height; i++) {
		front[i] = 'O';
		back[i] = 'R';
		leftSide[i] = 'B';
		rightSide[i] = 'G';
		top[i] = 'W';
		bottom[i] = 'Y';
		temp[i] = 'X';
	}
	top[0] = 'T';
	front[0] = 'T';
	back[0] = 'T';
	bottom[0] = 'T';
}

RubiksCube::~RubiksCube() {
}

void RubiksCube::rotateCubeRight(int num) {
	for (int n = 0; n < num; n++) {
		memcpy(temp, front, height * width);
		memcpy(front, leftSide, height * width);
		memcpy(leftSide, back, height * width);
		memcpy(back, rightSide, height * width);
		memcpy(rightSide, temp, height * width);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getTopPos(i, j));
			}
		}
		memcpy(top, temp, height * width);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getBottomPos(i, j));
			}
		}
		memcpy(bottom, temp, height * width);
	}
}

void RubiksCube::rotateCubeUp(int num) {
	for (int n = 0; n < num; n++) {
		memcpy(temp, front, height * width);
		memcpy(front, bottom, height * width);
		memcpy(bottom, back, height * width);
		memcpy(back, top, height * width);
		memcpy(top, temp, height * width);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getRightSidePos(i, j));
			}
		}
		memcpy(rightSide, temp, height * width);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getLeftSidePos(i, j));
			}
		}
		memcpy(leftSide, temp, height * height);
	}
}

void RubiksCube::doR(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(i, width - 1, getFrontPos(i, width - 1));
			setFrontPos(i, width - 1, getBottomPos(i, width - 1));
			setBottomPos(i, width - 1, getBackPos(i, width - 1));
			setBackPos(i, width - 1, getTopPos(i, width - 1));
			setTopPos(i, width - 1, getTempPos(i, width - 1));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getRightSidePos(i, j));
			}
		}
		memcpy(rightSide, temp, height * width);
	}
}

void RubiksCube::doRPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(i, width - 1, getFrontPos(i, width - 1));
			setFrontPos(i, width - 1, getTopPos(i, width - 1));
			setTopPos(i, width - 1, getBackPos(i, width - 1));
			setBackPos(i, width - 1, getBottomPos(i, width - 1));
			setBottomPos(i, width - 1, getTempPos(i, width - 1));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getRightSidePos(i, j));
			}
		}
		memcpy(rightSide, temp, height * width);
	}
}

void RubiksCube::doL(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(i, 0, getFrontPos(i, 0));
			setFrontPos(i, 0, getTopPos(i, 0));
			setTopPos(i, 0, getBackPos(i, 0));
			setBackPos(i, 0, getBottomPos(i, 0));
			setBottomPos(i, 0, getTempPos(i, 0));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getLeftSidePos(i, j));
			}
		}
		memcpy(leftSide, temp, height * width);
	}
}

void RubiksCube::doLPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(i, 0, getFrontPos(i, 0));
			setFrontPos(i, 0, getBottomPos(i, 0));
			setBottomPos(i, 0, getBackPos(i, 0));
			setBackPos(i, 0, getTopPos(i, 0));
			setTopPos(i, 0, getTempPos(i, 0));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getLeftSidePos(i, j));
			}
		}
		memcpy(leftSide, temp, height * width);
	}
}

void RubiksCube::doF(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(height - 1, width - 1 - i, getTopPos(height - 1, width -1 - i));
			setTopPos(height - 1, width - 1 - i, getLeftSidePos(i, width - 1));
			setLeftSidePos(i, width - 1, getBottomPos(0, i));
			setBottomPos(0, i, getRightSidePos(height - 1 - i, 0));
			setRightSidePos(height - 1 - i, 0, getTempPos(height - 1, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width -1 - i, getFrontPos(i, j));
			}
		}
		memcpy(front, temp, height * width);
	}
}

void RubiksCube::doFPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(height - 1, width - 1 - i, getTopPos(height - 1, width - 1 - i));
			setTopPos(height - 1, width - 1 - i, getRightSidePos(height - 1 - i, 0));
			setRightSidePos(height - 1 - i, 0, getBottomPos(0, i));
			setBottomPos(0, i, getLeftSidePos(i, width - 1));
			setLeftSidePos(i, width - 1, getTempPos(height - 1, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getFrontPos(i, j));
			}
		}
		memcpy(front, temp, height * width);
	}
}

void RubiksCube::doB(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(0, width - 1 - i, getTopPos(0, width - 1 - i));
			setTopPos(0, width - 1 - i, getRightSidePos(height - 1 - i, 2));
			setRightSidePos(height - 1 - i, 2, getBottomPos(height - 1, i));
			setBottomPos(height - 1, i, getLeftSidePos(i, 0));
			setLeftSidePos(i, 0, getTempPos(0, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getBackPos(i, j));
			}
		}
		memcpy(back, temp, height * width);
	}
}

void RubiksCube::doBPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(0, width - 1 - i, getTopPos(0, width - 1 - i));
			setTopPos(0, width - 1 - i, getLeftSidePos(i, 0));
			setLeftSidePos(i, 0, getBottomPos(height - 1, i));
			setBottomPos(height - 1, i, getRightSidePos(height - 1 - i, 2));
			setRightSidePos(height - 1 - i, 2, getTempPos(0, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getBackPos(i, j));
			}
		}
		memcpy(back, temp, height * width);
	}
}

void RubiksCube::doU(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(0, i, getFrontPos(0, i));
			setFrontPos(0, i, getRightSidePos(0, i));
			setRightSidePos(0, i, getBackPos(0, i));
			setBackPos(0, i, getLeftSidePos(0, i));
			setLeftSidePos(0, i, getTempPos(0, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getTopPos(i, j));
			}
		}
		memcpy(top, temp, height * width);
	}
}

void RubiksCube::doUPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(0, i, getFrontPos(0, i));
			setFrontPos(0, i, getLeftSidePos(0, i));
			setLeftSidePos(0, i, getBackPos(0, i));
			setBackPos(0, i, getRightSidePos(0, i));
			setRightSidePos(0, i, getTempPos(0, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getTopPos(i, j));
			}
		}
		memcpy(top, temp, height * width);
	}
}

void RubiksCube::doD(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(height - 1, i, getFrontPos(height - 1, i));
			setFrontPos(height - 1, i, getLeftSidePos(height - 1, i));
			setLeftSidePos(height - 1, i, getBackPos(height - 1, i));
			setBackPos(height - 1, i, getRightSidePos(height - 1, i));
			setRightSidePos(height - 1, i, getTempPos(height - 1, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(j, width - 1 - i, getBottomPos(i, j));
			}
		}
		memcpy(bottom, temp, height * width);
	}
}

void RubiksCube::doDPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			setTempPos(height - 1, i, getFrontPos(height - 1, i));
			setFrontPos(height - 1, i, getRightSidePos(height - 1, i));
			setRightSidePos(height - 1, i, getBackPos(height - 1, i));
			setBackPos(height - 1, i, getLeftSidePos(height - 1, i));
			setLeftSidePos(height - 1, i, getTempPos(height - 1, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				setTempPos(height - 1 - j, i, getBottomPos(i, j));
			}
		}
		memcpy(bottom, temp, height * width);
	}
}

char RubiksCube::getFrontPos(int i, int j) {
	return front[i + j * width];
}

void RubiksCube::setFrontPos(int i, int j, char v) {
	front[i + j * width] = v;
}

char RubiksCube::getBackPos(int i, int j) {
	return back[i + j * width];
}

void RubiksCube::setBackPos(int i, int j, char v) {
	back[i + j * width] = v;
}

char RubiksCube::getLeftSidePos(int i, int j) {
	return leftSide[i + j * width];
}

void RubiksCube::setLeftSidePos(int i, int j, char v) {
	leftSide[i + j * width] = v;
}

char RubiksCube::getRightSidePos(int i, int j) {
	return rightSide[i + j * width];
}

void RubiksCube::setRightSidePos(int i, int j, char v) {
	rightSide[i + j * width] = v;
}

char RubiksCube::getTopPos(int i, int j) {
	return top[i + j * width];
}

void RubiksCube::setTopPos(int i, int j, char v) {
	top[i + j * width] = v;
}

char RubiksCube::getBottomPos(int i, int j) {
	return bottom[i + j * width];
}

void RubiksCube::setBottomPos(int i, int j, char v) {
	bottom[i + j * width] = v;
}

char RubiksCube::getTempPos(int i, int j) {
	return temp[i + j * width];
}

void RubiksCube::setTempPos(int i, int j, char v) {
	temp[i + j * width] = v;
}
