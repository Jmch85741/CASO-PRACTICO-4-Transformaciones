#include<gl/glut.h>
#include<GL/freeglut.h>
#include<Windows.h>
#include<Math.h>
#include<stdlib.h>

void reshape(int, int);
void time(int);

float a_pos= 1.0;
float angle = 45.0f;

void Figura()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-a_pos, -a_pos);
	glVertex2f(-a_pos, a_pos);
	glVertex2f(a_pos, a_pos);
	glVertex2f(a_pos, -a_pos);
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) /*TECLADO*/
{
	if (key == 'w' or key == 'W') /*ARRIBA*/
	{
		glTranslatef(0.0, 1.0, 0.0);
	}
	else if (key == 'e' or key == 'E') /*ROTAR DERECHA*/
	{
		glRotatef(angle, 0.0f, 0.0f, 1.0);
	}
	else if (key == 'a' or key == 'A') /*IZQUIERDA*/
	{
		glTranslatef(-1.0, 0.0, 0.0);
	}
	else if (key == 'd' or key == 'D') /*DERECHA*/
	{
		glTranslatef(1.0, 0.0, 0.0);
	}
	else if (key == 'q' or key == 'Q') /*ROTAR IZQUIERDA*/
	{
		glRotatef(-angle, 0.0f, 0.0f, 1.0);
	}
	else if (key == 's' or key == 'S') /*ABAJO*/
	{
		glTranslatef(0.0, -1.0, 0.0);
	}
}

void mouse(int button, int state, int x, int y)
{
	switch (button)   /*Escala*/
	{
	case GLUT_LEFT_BUTTON: /*CLICK IZQUIERDO*/
		a_pos += 0.15;
		break;

	case GLUT_RIGHT_BUTTON: /*CLICK DERECHO*/
		a_pos -= 0.15;
		break;
	default:
		break;
	}
}



void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600,600);
	glutCreateWindow("Practica 4");
	glutReshapeFunc(reshape);
	glutDisplayFunc(Figura);
	glutTimerFunc(0, time, 0);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void time(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, time, 0);
}