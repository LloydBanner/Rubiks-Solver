#include "stdafx.h"
#include "RubiksCube.h"


RubiksCube::RubiksCube() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			front.setPos(i, j, 'O');
			back.setPos(i, j, 'R');
			leftSide.setPos(i, j, 'B');
			rightSide.setPos(i, j, 'G');
			top.setPos(i, j, 'W');
			bottom.setPos(i, j, 'Y');
			temp.setPos(i, j, 'X');
		}
	}
}

RubiksCube::~RubiksCube() {
}

void RubiksCube::rotateCubeRight(int num) {
	for (int n = 0; n < num; n++) {
		temp.setFace(front.getFace());
		front.setFace(leftSide.getFace());
		leftSide.setFace(back.getFace());
		back.setFace(rightSide.getFace());
		rightSide.setFace(temp.getFace());
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, top.getPos(i, j));
			}
		}
		top.setFace(temp.getFace());
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, bottom.getPos(i, j));
			}
		}
		bottom.setFace(temp.getFace());
	}
}

void RubiksCube::rotateCubeUp(int num) {
	for (int n = 0; n < num; n++) {
		temp.setFace(front.getFace());
		front.setFace(bottom.getFace());
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				bottom.setPos(i, j, back.getPos(height - 1 - i, width - 1 - j));
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				back.setPos(height - 1 - i, width - 1 - j, top.getPos(i, j));
			}
		}
		top.setFace(temp.getFace());
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, rightSide.getPos(i, j));
			}
		}
		rightSide.setFace(temp.getFace());
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, leftSide.getPos(i, j));
			}
		}
		leftSide.setFace(temp.getFace());
	}
}

void RubiksCube::doR(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(i, width - 1, front.getPos(i, width - 1));
			front.setPos(i, width - 1, bottom.getPos(i, width - 1));
			bottom.setPos(i, width - 1, back.getPos(height - 1 - i, 0));
			back.setPos(height - 1 - i, 0, top.getPos(i, width - 1));
			top.setPos(i, width - 1, temp.getPos(i, width - 1));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, rightSide.getPos(i, j));
			}
		}
		rightSide.setFace(temp.getFace());
	}
}

void RubiksCube::doRPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(i, width - 1, front.getPos(i, width - 1));
			front.setPos(i, width - 1, top.getPos(i, width - 1));
			top.setPos(i, width - 1, back.getPos(height - 1 - i, 0));
			back.setPos(height -1 - i, 0, bottom.getPos(i, width - 1));
			bottom.setPos(i, width - 1, temp.getPos(i, width - 1));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, rightSide.getPos(i, j));
			}
		}
		rightSide.setFace(temp.getFace());
	}
}

void RubiksCube::doL(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(i, 0, front.getPos(i, 0));
			front.setPos(i, 0, top.getPos(i, 0));
			top.setPos(i, 0, back.getPos(height - 1 - i, width - 1));
			back.setPos(height - 1 - i, width - 1, bottom.getPos(i, 0));
			bottom.setPos(i, 0, temp.getPos(i, 0));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, leftSide.getPos(i, j));
			}
		}
		leftSide.setFace(temp.getFace());
	}
}

void RubiksCube::doLPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(i, 0, front.getPos(i, 0));
			front.setPos(i, 0, bottom.getPos(i, 0));
			bottom.setPos(i, 0, back.getPos(height - 1 - i, width - 1));
			back.setPos(height - 1 - i, width - 1, top.getPos(i, 0));
			top.setPos(i, 0, temp.getPos(i, 0));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, leftSide.getPos(i, j));
			}
		}
		leftSide.setFace(temp.getFace());
	}
}

void RubiksCube::doF(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(height - 1, width - 1 - i, top.getPos(height - 1, width -1 - i));
			top.setPos(height - 1, width - 1 - i, leftSide.getPos(i, width - 1));
			leftSide.setPos(i, width - 1, bottom.getPos(0, i));
			bottom.setPos(0, i, rightSide.getPos(height - 1 - i, 0));
			rightSide.setPos(height - 1 - i, 0, temp.getPos(height - 1, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width -1 - i, front.getPos(i, j));
			}
		}
		front.setFace(temp.getFace());
	}
}

void RubiksCube::doFPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(height - 1, width - 1 - i, top.getPos(height - 1, width - 1 - i));
			top.setPos(height - 1, width - 1 - i, rightSide.getPos(height - 1 - i, 0));
			rightSide.setPos(height - 1 - i, 0, bottom.getPos(0, i));
			bottom.setPos(0, i, leftSide.getPos(i, width - 1));
			leftSide.setPos(i, width - 1, temp.getPos(height - 1, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, front.getPos(i, j));
			}
		}
		front.setFace(temp.getFace());
	}
}

void RubiksCube::doB(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(0, width - 1 - i, top.getPos(0, width - 1 - i));
			top.setPos(0, width - 1 - i, rightSide.getPos(height - 1 - i, 2));
			rightSide.setPos(height - 1 - i, 2, bottom.getPos(height - 1, i));
			bottom.setPos(height - 1, i, leftSide.getPos(i, 0));
			leftSide.setPos(i, 0, temp.getPos(0, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, back.getPos(i, j));
			}
		}
		back.setFace(temp.getFace());
	}
}

void RubiksCube::doBPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(0, width - 1 - i, top.getPos(0, width - 1 - i));
			top.setPos(0, width - 1 - i, leftSide.getPos(i, 0));
			leftSide.setPos(i, 0, bottom.getPos(height - 1, i));
			bottom.setPos(height - 1, i, rightSide.getPos(height - 1 - i, 2));
			rightSide.setPos(height - 1 - i, 2, temp.getPos(0, width - 1 - i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, back.getPos(i, j));
			}
		}
		back.setFace(temp.getFace());
	}
}

void RubiksCube::doU(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(0, i, front.getPos(0, i));
			front.setPos(0, i, rightSide.getPos(0, i));
			rightSide.setPos(0, i, back.getPos(0, i));
			back.setPos(0, i, leftSide.getPos(0, i));
			leftSide.setPos(0, i, temp.getPos(0, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, top.getPos(i, j));
			}
		}
		top.setFace(temp.getFace());
	}
}

void RubiksCube::doUPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(0, i, front.getPos(0, i));
			front.setPos(0, i, leftSide.getPos(0, i));
			leftSide.setPos(0, i, back.getPos(0, i));
			back.setPos(0, i, rightSide.getPos(0, i));
			rightSide.setPos(0, i, temp.getPos(0, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, top.getPos(i, j));
			}
		}
		top.setFace(temp.getFace());
	}
}

void RubiksCube::doD(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(height - 1, i, front.getPos(height - 1, i));
			front.setPos(height - 1, i, leftSide.getPos(height - 1, i));
			leftSide.setPos(height - 1, i, back.getPos(height - 1, i));
			back.setPos(height - 1, i, rightSide.getPos(height - 1, i));
			rightSide.setPos(height - 1, i, temp.getPos(height - 1, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(j, width - 1 - i, bottom.getPos(i, j));
			}
		}
		bottom.setFace(temp.getFace());
	}
}

void RubiksCube::doDPrime(int num) {
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < height; i++) {
			temp.setPos(height - 1, i, front.getPos(height - 1, i));
			front.setPos(height - 1, i, rightSide.getPos(height - 1, i));
			rightSide.setPos(height - 1, i, back.getPos(height - 1, i));
			back.setPos(height - 1, i, leftSide.getPos(height - 1, i));
			leftSide.setPos(height - 1, i, temp.getPos(height - 1, i));
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				temp.setPos(height - 1 - j, i, bottom.getPos(i, j));
			}
		}
		bottom.setFace(temp.getFace());
	}
}
