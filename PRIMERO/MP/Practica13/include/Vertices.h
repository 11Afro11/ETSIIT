#ifndef VERTICES_
#define VERTICES_

#include <GL/glut.h>
#include <vector>


class Vertices{
private:
	vector<GLfloat> vertice;

	void Copia(vector<GLfloat> otro);

public:
	Vertices();
	Vertices(vector<GLfloat> otro);
	GLfloat & operator [](const int pos);
};