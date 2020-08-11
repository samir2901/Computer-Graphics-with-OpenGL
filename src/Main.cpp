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
	width = 400;
	height = 400;

	int startX, startY, endX, endY;

	std::cout << "Enter startX: ";
	std::cin >> startX;
	std::cout << "Enter startY: ";
	std::cin >> startY;
	std::cout << "Enter endX: ";
	std::cin >> endX;
	std::cout << "Enter endY: ";
	std::cin >> endY;

	std::cout << "The points are: " << "(" << startX << ", " << startY << ") and (" << endX << ", " << endY << ")" << std::endl;

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
		BresenhamLine(startX, startY, endX, endY);		

		//
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}