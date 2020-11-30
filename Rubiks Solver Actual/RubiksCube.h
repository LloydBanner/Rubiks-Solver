#pragma once
class RubiksCube {
public:
	int width = 3;
	int height = 3;
	char* front = new char[width*height];
	char* back = new char[width*height];
	char* leftSide = new char[width*height];
	char* rightSide = new char[width*height];
	char* top = new char[width*height];
	char* bottom = new char[width*height];
	char* temp = new char[width*height];

	RubiksCube();
	~RubiksCube();
	void rotateCubeRight(int num);
	void rotateCubeUp(int num);
	void doR(int num);
	void doRPrime(int num);
	void doL(int num);
	void doLPrime(int num);
	void doF(int num);
	void doFPrime(int num);
	void doB(int num);
	void doBPrime(int num);
	void doU(int num);
	void doUPrime(int num);
	void doD(int num);
	void doDPrime(int num);
	char getFrontPos(int i, int j);
	void setFrontPos(int i, int j, char v);
	char getBackPos(int i, int j);
	void setBackPos(int i, int j, char v);
	char getLeftSidePos(int i, int j);
	void setLeftSidePos(int i, int j, char v);
	char getRightSidePos(int i, int j);
	void setRightSidePos(int i, int j, char v);
	char getTopPos(int i, int j);
	void setTopPos(int i, int j, char v);
	char getBottomPos(int i, int j);
	void setBottomPos(int i, int j, char v);
	char getTempPos(int i, int j);
	void setTempPos(int i, int j, char v);
};

