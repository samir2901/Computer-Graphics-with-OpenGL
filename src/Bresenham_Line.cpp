#include<iostream>
#include<GLFW/glfw3.h>
#include<gl/GL.h>


void drawLineLess(int x1, int y1, int x2, int y2) { //for m < 1
	int x, y, dx, dy, p;
	x = x1; 
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;	
	p = 2 * dy - dx;	
	glBegin(GL_POINTS);
	while (x <= x2) {	
		glVertex2i(x, y);
		x++;
		if (p < 0) {
			p = p + 2 * dy;
		}
		else {
			p = p + 2 * (dy - dx);
			y++;
		}		
	}
	glEnd();
	glFlush();
}

void drawLineEqual(int x1, int y1, int x2, int y2) { //for m = 1
	int x, y;
	x = x1;
	y = y1;	
	glBegin(GL_POINTS);
	while (x <= x2) {
		//std::cout << "(" << x << "," << y << ")" << std::endl;
		glVertex2i(x, y);
		x++;		
		y++;		
	}
	glEnd();
	glFlush();
}

void drawLineGreater(int x1, int y1, int x2, int y2) { //for m > 1
	int x, y, dx, dy, p;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0) {
		x = -1;
		dx = -dx;
	}
	p = 2 * dx - dy;
	glBegin(GL_POINTS);
	while (y <= y2) {
		glVertex2i(x, y);
		y++;
		if (p < 0) {
			p = p + 2 * dx;
		}
		else {
			p = p - 2 * dy;
			x++;
		}
	}
	glEnd();
	glFlush();
}


void BresenhamLine(int startX, int startY, int endX, int endY) {
	if (abs(endY - startY) < abs(endX - startX)) {
		drawLineLess(startX, startY, endX, endY);
	}
	else if (abs(endY - startY) == abs(endX - startX)) {
		drawLineEqual(startX, startY, endX, endY);
	}
	else {
		drawLineGreater(startX, startY, endX, endY);
	}
	
}


