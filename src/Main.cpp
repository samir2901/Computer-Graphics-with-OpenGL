#include<iostream>
#include<math.h>
#include<GLFW/glfw3.h>
#include<gl/GL.h>
#include"drawgraphics.h"


void Init(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, 0.0, height, 0.0, 1.0);
}

int main() {
	int width, height;
	width = 640;
	height = 480;

	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}
	window = glfwCreateWindow(width, height, "Computer Graphics", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	Init(width, height);

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		//Draw here
		
		//DDA((float)startX, (float)startY, (float)endX, (float)endY);
		BresenhamLine(300, 300, 100, 300);
		BresenhamLine(100, 300, 100, 100);
		BresenhamLine(100, 100, 300, 100);
		BresenhamLine(300, 100, 300, 300);
		BresenhamLine(300, 100, 100, 300);
		BresenhamLine(100, 100, 300, 300);

		//midPointCircle(width/2, height/2, 100);		

		//
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}