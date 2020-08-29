#include<iostream>
#include<GLFW/glfw3.h>
#include<gl/GL.h>

int min(int x, int y) {
	return (x > y) ? y : x;
}

int max(int x, int y) {
	return (x < y) ? y : x;
}

void drawLineLess(int x1, int y1, int x2, int y2) { //for m < 1
	int x, y, dx, dy, p;	
	dx = x2 - x1;
	dy = y2 - y1;	
	if (x1 > x2) {
		x = x2; y = y2;
		x2 = x1; y2 = y1;
		x1 = x; y1 = y;
	}	
	x = x1;
	y = y1;
	p = 2 * dy - dx;	
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	while (x <= x2) {			
		x++;
		if (p < 0) {
			p = p + 2 * dy;
		}
		else {
			if (dy / dx > 0) {
				y++;
			}
			else {
				y--;
			}
			p = p + 2 * (dy - dx);			
		}		
		glVertex2i(x, y);
	}
	glEnd();	
	glFlush();
}


void drawLineGreater(int x1, int y1, int x2, int y2) { //for m > 1
	int x, y, dx, dy, p;	
	dx = x2 - x1;
	dy = y2 - y1;
	if (y1 > y2) {
		y = y2; x = x2;
		y2 = y1; x2 = x1;
		y1 = y; x1 = x;
	}	
	x = x1; y = y1;
	p = 2 * dx - dy;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	while (y <= y2) {		
		y++;
		if (p < 0) {
			p = p + 2 * dy;
		}
		else {
			if (dy / dx > 0) {
				x++;
			}
			else {
				x--;				
			}
			p = p + (2 * dy - 2 * dx);
		}
		glVertex2i(x, y);
	}
	glEnd();	
	glFlush();
}


void BresenhamLine(int startX, int startY, int endX, int endY) {
	int x, y;
	if (abs(endY - startY) == 0) {
		x = min(startX, endX);
		glBegin(GL_POINTS);
		while (x < max(startX,endX))
		{
			x++;
			glVertex2i(x, startY);
		}
		glEnd();
		glFlush();
	}
	else if (abs(endX - startX) == 0) {
		y = min(startY, endY);
		glBegin(GL_POINTS);
		while (y < max(startY, endY))
		{
			y++;
			glVertex2i(startX, y);
		}
		glEnd();
		glFlush();
	}
	else if (abs(endX - startX) >= abs(endY - startY)) {
		drawLineLess(startX, startY, endX, endY);
	}
	else {
		drawLineGreater(startX, startY, endX, endY);
	}
}


