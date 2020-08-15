#include<iostream>
#include<GLFW/glfw3.h>
#include<gl/GL.h>


//only for m < 1 ie slope < 1
void BresenhamLine(int x1, int y1, int x2, int y2) {
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

