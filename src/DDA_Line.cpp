#include<iostream>
#include<math.h>
#include<GLFW/glfw3.h>
#include<gl/GL.h>

float round_value(float value) {
	return floor(value + 0.5);
}


void DDA(float x1, float y1, float x2, float y2) {
	float x, y, dx, dy, xinc, yinc;
	int steps;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	steps = (int)((abs(dx) > abs(dy)) ? abs(dx) : abs(dy));
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	for (int i = 0; i < steps; i++){
		x += xinc;
		y += yinc;		
		glVertex2f(round_value(x),round_value(y));
	}
	glEnd();	
	glFlush();
}