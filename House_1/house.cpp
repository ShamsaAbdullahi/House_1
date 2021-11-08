#include<GL\glut.h>
#include <math.h>
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	
	
}

void buildHouse(void)
{

	float theta;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.1f, 0.1f);//Dark blue
	glPointSize(4);

	glBegin(GL_LINE_LOOP);//dome shape top
	for (int i = 0; i < 180; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2i(125+50*cos(theta),125+50*sin(theta));
	}
	glEnd();
	
    glBegin(GL_LINE_LOOP);  // start house
	glVertex2f(50.0f, 10.0f);
	glVertex2f(50.0f, 100.0f);
	glVertex2f(35.0f, 100.0f);
	glVertex2f(35.0f, 125.0f);
	glVertex2f(215.0f, 125.0f);
	glVertex2f(215.0f, 100.0f);
	glVertex2f(200.0f, 100.0f);
	glVertex2f(200.0f, 10.0f);

    glEnd();   //end house

	glBegin(GL_LINE_LOOP);//start door
	glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
    glVertex2f(110.0f, 10.0f);
	glVertex2f(110.0f, 80.0f);
	glVertex2f(140.0f, 80.0f);
	glVertex2f(140.0f, 10.0f);
    glEnd();//end door section

	glBegin(GL_LINE_LOOP);//windows
	glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
	glVertex2f(60.0f, 50.0f);//right 
	glVertex2f(60.0f, 75.0f);
	glVertex2f(80.0f, 75.0f);
	glVertex2f(80.0f, 50.0f);
	glEnd();//end window right
   
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
	glVertex2f(170.0f, 50.0f);//left
	glVertex2f(170.0f, 75.0f);
	glVertex2f(190.0f, 75.0f);
	glVertex2f(190.0f, 50.0f);
	glEnd();//end windows left

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.1f, 0.1f);//Dark blue
	glVertex2f(70.0f,50.0f);//vertical lines left
	glVertex2f(70.0f, 75.0f);
	glVertex2f(60.0f, 63.5f);//horizontal
	glVertex2f(80.0f, 63.5f);//end lines left

	glVertex2f(180.0f, 50.0f);//vertical lines right
	glColor3f(0.0f, 0.1f, 0.1f);//Dark blue
	glVertex2f(180.0f, 75.0f);
	glVertex2f(170.0f, 63.5f);//horizontal
	glVertex2f(190.0f, 63.5f);
	glEnd();//end lines right

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_NOTEQUAL, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_POINTS);//doorknob
	glColor3f(0.0f, 0.0f, 1.0f);//Blue
	glVertex2f(134.0f, 45.0f);
	glEnd();//end doorknob
	glDisable(GL_POINT_SMOOTH);
	glBlendFunc(GL_NONE, GL_NONE);
	glDisable(GL_BLEND);
	

	glBegin(GL_POLYGON);//start crescent
	glColor3f(1.0f, 0.5f, 0.0f);//Orange
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2i(220 + 30 * cos(theta), 250 + 30 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);//circle 2 in white
	glColor4f(1, 1, 1,1);
	for (int i = 0; i < 360; i++)
	{
		theta = i * 3.142 / 180;

		glVertex2i(240 + 35 * cos(theta), 255 + 35 * sin(theta));
	}
	glEnd();//end crescent

    glFlush();
    glutSwapBuffers();

}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(600, 500);
	glutCreateWindow("House Model OpenGL");
	init();
	glutDisplayFunc(buildHouse);

	
	glutMainLoop();
}
