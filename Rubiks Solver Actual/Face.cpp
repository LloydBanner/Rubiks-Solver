#include "stdafx.h"
#include "Face.h"


Face::Face(){
}

char* Face::getFace() {
	return face;
}

void Face::setFace(char* newFace) {
	memcpy(face, newFace, height * width);
}

char Face::getPos(int i, int j) {
	return face[i + j * width];
}

void Face::setPos(int i, int j, char v) {
	face[i + j * width] = v;
}

Face::~Face(){
}
