#pragma once
class Face {
public:
	int width = 3;
	int height = 3;
	char* face = new char[width*height];

	Face();
	char * getFace();
	void setFace(char * newFace);
	char getPos(int i, int j);
	void setPos(int i, int j, char v);
	~Face();
};

