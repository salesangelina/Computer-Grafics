#include "main.h"

void MyGlDraw(void){

  point p1 = {400, 200};
	point p2 = {100, 70};
	point p3 = {270, 90};
  DrawTriangle(p1, p2, p3);

}

int main(int argc, char **argv){
	// InicializaÃ§Ãµes.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

