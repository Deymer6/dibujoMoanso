#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>

using namespace std;
float camaraX = -60;

float camaraY = 20;

float camaraZ = 60;

float angulo = 0;



void iniciarVentana(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (float)w / (float)h, 1, 200);

}



void inicializarLuces() {

	GLfloat luzAmbiente[] = { 0.35,0.35,0.35 ,1 };
	GLfloat luzDifusa[] = { 0.5,0.5,0.5 ,1 };
	GLfloat luzEspecular[] = { 0.3,0.3,0.3 ,1 };

	float posicionLuz[] = { 0,70,60,1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0,GL_AMBIENT,luzDifusa);
	glLightfv(GL_LIGHT0, GL_AMBIENT , luzEspecular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

}



void piso() {
	glPushMatrix();
	glTranslated(0, -1, 0);
	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 230);
	glVertex3d(-50, 0, -50);
	glVertex3d(50, 0, -50);
	glVertex3d(50, 0, 50);
	glVertex3d(-50, 0, 50);
	glEnd();
	glPopMatrix();

}

void ejes() {

	glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex3d(0, 0, 0);
		glVertex3d(50, 0, 0);
		glColor3ub(0, 255, 0);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 50, 0);
		glColor3ub(0, 0, 255);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 50);
	glEnd();
}

void tronco() {
	glPushMatrix();
	glColor3ub(140, 83, 62); 
	   glRotated(-90, 1, 0,0); 
	   glTranslated(15, 0, 0); 
	   gluCylinder(gluNewQuadric(),3,2,10,50,50);
	glPopMatrix();

}
void ramas() {
	glPushMatrix();
	glColor3ub(0, 200, 0);
	glTranslated(0, 8, 0);
	glRotated(-90, 1, 0, 0);
	glTranslated(15, 0, 0);
	glutSolidCone(5, 10, 6, 58);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 200, 0);
	glTranslated(0, 10, 0);
	glRotated(-90, 1, 0, 0);
	glTranslated(15, 0, 0);
	glutSolidCone(5, 10, 6, 58);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 200, 0);
	glTranslated(0, 12, 0);
	glRotated(-90, 1, 0, 0);
	glTranslated(15, 0, 0);
	glutSolidCone(5, 10, 6, 58);
	glPopMatrix();
}

void pared() {

	glBegin(GL_QUADS);

	glVertex3d(-10, 0, 0);

	glVertex3d(10, 0, 0);

	glVertex3d(10, 20, 0);

	glVertex3d(-10, 20, 0);

	glEnd();

}



void cubo() {
	glPushMatrix();
		glColor3ub(200, 0, 0);
		glTranslated(0, 0, 10);
		pared();

	glPopMatrix();
		glPushMatrix();
		glColor3ub(200, 0, 0);
		glTranslated(0, 0, -10);
		pared();
	glPopMatrix();

	glPushMatrix();
		glColor3ub(0, 200, 0);
		glTranslated(-10, 0, 0);
		glRotated(90, 0, 1, 0);
		pared();
	glPopMatrix();



	glPushMatrix();
		glTranslated(10, 0, 0);
		glRotated(-90, 0, 1, 0);
		glColor3ub(0, 200, 0);
		pared();
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 20, 10);
		glRotated(-90, 1, 0, 0);
		glColor3ub(0, 0, 200);
		pared();
	glPopMatrix();

}

/// <summary>
///  falta completar
/// </summary>
void grupoCubos() 
{
	glPushMatrix();;
		cubo();
	glPopMatrix();

	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(20, 0, 0);
		cubo();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(-20, 0, 0);
	cubo();
	glPopMatrix();

	glPushMatrix();
		glTranslated(20, 20, 0);
		cubo();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-20, 20, 0);
	cubo();
	glPopMatrix();


}


 ///

void circulo() {

}
void dibujar() {
	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);
		glPushMatrix();
		glRotated(angulo, 0, 1, 0);
		piso();
		ejes();
	glPopMatrix(); 

	tronco();
	ramas();

	grupoCubos();
	glutSwapBuffers();
}

void timer(int t) {

	glutPostRedisplay();

	glutTimerFunc(20, timer, 0);

}

void teclado(int tecla, int x, int y) {

	switch (tecla)

	{

	case 101:

		camaraY += 0.2;

		break;

	case 103:

		camaraY -= 0.2;

		break;

	case 100:

		angulo -= 1;

		break;

	case 102:

		angulo += 1;

		break;

	}

}





int main(int argc, char* argv[]) {



	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(1100, 750);

	glutInitWindowPosition(50, 50);

	glutCreateWindow("Bienvenidos a computacion grafica");

	glutReshapeFunc(iniciarVentana);

	glutDisplayFunc(dibujar);

	glutSpecialFunc(teclado);

	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	return 0;



}