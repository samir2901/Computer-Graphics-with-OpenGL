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
	steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy  );
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
	window = glfwCreateWindow(width, height, "DDA-Line-Algorithm", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);	
	//glfwSwapInterval(1);

	Init(width, height);
	
	while (!glfwWindowShouldClose(window)) {
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		//Draw here
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);		
		DDA(startX, startY, endX, endY);
		
		//
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}