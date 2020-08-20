#include<iostream>
#include<GLFW/glfw3.h>
#include<gl/GL.h>

void drawPoints(int xc, int yc, int x, int y) {
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - y, yc - x);		
}

void midPointCircle(int xCenter, int yCenter, int radius) {
	int x = 0;
	int y = radius;
	int p = 1 - radius;
	glBegin(GL_POINTS);
	drawPoints(xCenter, yCenter, x, y);
	while (x < y) {
		x++;
		if (p < 0) {
			p += 2 * x + 1;
		}
		else {
			y--;
			p += 2 * (x - y) + 1;
		}
		drawPoints(xCenter, yCenter, x, y);
	}
	glEnd();
	glFlush();
}