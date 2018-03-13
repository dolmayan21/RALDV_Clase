//Semestre 2018 - 2

//************************************************************//

//************************************************************//

//************** Alumno (s): Leon Del Villar Rub�n Alejandro**//

//************************************************************//

/***********	Visual Studio 2017			*******************/

//************************************************************//

#include "Main.h"



float transZ = -5.0f;

float transX = 0.0f;

float angleX = 0.0f;

float angleY = 0.0f;

int screenW = 0.0;

int screenH = 0.0;


///		BRAZO


float angHombro = 0.0f;
float angCodo = 0.0f;
float angMano = 0.0f;

float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;

float angIndice1 = 0.0f;
float angIndice2 = 0.0f;
float angIndice3 = 0.0f;

float angMedio1 = 0.0f;
float angMedio2 = 0.0f;
float angMedio3 = 0.0f;

float angAnular1 = 0.0f;
float angAnular2 = 0.0f;
float angAnular3 = 0.0f;

float angMenique1 = 0.0f;
float angMenique2 = 0.0f;
float angMenique3 = 0.0f;







GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position

GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position



void InitGL(void)     // Inicializamos parametros

{



	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer

	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing



														//Configuracion luz

	glLightfv(GL_LIGHT0, GL_POSITION, Position);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);





	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar

	glEnable(GL_COLOR_MATERIAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}



void prisma(void)

{

	GLfloat vertice[8][3] = {

		{ 0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 0 V0

	{ -0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 1 V1

	{ -0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 2 V2

	{ 0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 3 V3

	{ 0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 4 V4

	{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 5 V5

	{ -0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 6 V6

	{ -0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 7 V7

	};



	glBegin(GL_POLYGON);	//Front

	glNormal3f(0.0f, 0.0f, 1.0f);

	glVertex3fv(vertice[0]);

	glVertex3fv(vertice[4]);

	glVertex3fv(vertice[7]);

	glVertex3fv(vertice[1]);

	glEnd();



	glBegin(GL_POLYGON);	//Right

	glNormal3f(1.0f, 0.0f, 0.0f);

	glVertex3fv(vertice[0]);

	glVertex3fv(vertice[3]);

	glVertex3fv(vertice[5]);

	glVertex3fv(vertice[4]);

	glEnd();



	glBegin(GL_POLYGON);	//Back

	glNormal3f(0.0f, 0.0f, -1.0f);

	glVertex3fv(vertice[6]);

	glVertex3fv(vertice[5]);

	glVertex3fv(vertice[3]);

	glVertex3fv(vertice[2]);

	glEnd();



	glBegin(GL_POLYGON);  //Left

	glNormal3f(-1.0f, 0.0f, 0.0f);

	glVertex3fv(vertice[1]);

	glVertex3fv(vertice[7]);

	glVertex3fv(vertice[6]);

	glVertex3fv(vertice[2]);

	glEnd();



	glBegin(GL_POLYGON);  //Bottom

	glNormal3f(0.0f, -1.0f, 0.0f);

	glVertex3fv(vertice[0]);

	glVertex3fv(vertice[1]);

	glVertex3fv(vertice[2]);

	glVertex3fv(vertice[3]);

	glEnd();



	glBegin(GL_POLYGON);  //Top

	glNormal3f(0.0f, 1.0f, 0.0f);

	glVertex3fv(vertice[4]);

	glVertex3fv(vertice[5]);

	glVertex3fv(vertice[6]);

	glVertex3fv(vertice[7]);

	glEnd();

}



void display(void)   // Creamos la funcion donde se dibuja

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer

														//glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glColor3f(0.0, 0.5, 0.0);


	glTranslatef(transX, 0.0f, transZ);

	glRotatef(angleY, 0.0, 1.0, 0.0);

	glRotatef(angleX, 1.0, 0.0, 0.0);

	//Poner C�digo Aqu�.
	glPushMatrix();

	///	HOMBRO
	glRotatef(angHombro, 0.0, 0.0, 1.0);
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.0);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();
	///	BICEP

	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();

	///	CODO
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef(angCodo, 0.0, 0.0, 1.0);		///		LOS ROTATEF DESPUES!!!!! DE UN TRANSLADO		!!!!!
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();

	///	ANTEBRAZO
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.5, 1.0, 1.0);
	prisma();
	glPopMatrix();

	///		MANO
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef(angMano, 0.0, 0.0, 1.0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.4);
	glScalef(0.5, 0.5, 1.0);
	prisma();
	glPopMatrix();

	///		DEDO PULGAR


	glPushMatrix();
	glTranslatef(0.25, 0.0, 0.1);
	glRotatef(angPulgar1, 0.0, 0.0, 1.0);
	glTranslatef(0.1, 0.0, 0.1);

	glColor3f(0.3, 0.5, 0.0);

	glPushMatrix();
	glScalef(0.2, 0.1, 0.1);
	prisma();
	glPopMatrix();

	glTranslatef(0.2, 0.0, 0.0);
	glRotatef(angPulgar2, 0.0, 0.0, 1.0);
	glScalef(0.2, 0.1, 0.1);
	prisma();
	glPopMatrix();

	///		DEDO INDICE

	///		FALANGE 1

	glPushMatrix();
	glTranslatef(0.1, -0.25, 0.1);
	glRotatef(angIndice1, 0.1, 0.0, 0.0);
	glTranslatef(0.1, -0.1, 0.1);

	glColor3f(0.3, 0.5, 0.0);

	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);
	prisma();
	glPopMatrix();


	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angIndice2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);
	prisma();
	glPopMatrix();

	///
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angIndice3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);
	prisma();
	glPopMatrix();

	glPopMatrix();


	///		DEDO MEDIO

	///		FALANGE 1
	glTranslatef(0.1, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-0.01, -0.25, 0.1);
	glRotatef(angMedio1, 0.1, 0.0, 0.0);
	glTranslatef(-0.01, -0.1, 0.1);

	glColor3f(0.3, 0.5, 0.0);

	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	prisma();
	glPopMatrix();


	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angMedio2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	prisma();
	glPopMatrix();

	///
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angMedio3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	prisma();
	glPopMatrix();

	glPopMatrix();

	///		DEDO ANULAR

	///		FALANGE 1
	glTranslatef(-0.15, 0.0, 0.0);
	glPushMatrix();

	glTranslatef(-0.1, -0.25, 0.1);
	glRotatef(angAnular1, 0.1, 0.0, 0.0);
	glTranslatef(0.1, -0.1, 0.1);

	glColor3f(0.3, 0.5, 0.0);

	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);
	prisma();
	glPopMatrix();


	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angAnular2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);
	prisma();
	glPopMatrix();

	///
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(angAnular3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.2, 0.1);
	prisma();
	glPopMatrix();

	glPopMatrix();


	///		DEDO MENIQUE

	///		FALANGE 1
	glTranslatef(-0.16, 0.0, 0.0);
	glPushMatrix();

	glTranslatef(-0.1, -0.25, 0.1);
	glRotatef(angMenique1, 0.1, 0.0, 0.0);
	glTranslatef(0.1, -0.05, 0.1);

	glColor3f(0.3, 0.5, 0.0);

	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	prisma();
	glPopMatrix();


	glTranslatef(0.0, -0.05, 0.0);
	glRotatef(angMenique2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	prisma();
	glPopMatrix();

	///
	glTranslatef(0.0, -0.05, 0.0);
	glRotatef(angMenique3, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	prisma();
	glPopMatrix();

	glPopMatrix();
























	glPopMatrix();







	glutSwapBuffers();

	// Swap The Buffers

}



void reshape(int width, int height)   // Creamos funcion Reshape

{

	if (height == 0)										// Prevenir division entre cero

	{

		height = 1;

	}



	glViewport(0, 0, width, height);



	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix

	glLoadIdentity();



	// Tipo de Vista

	//glOrtho(-5,5,-5,5,0.2,20);	

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);



	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix

														//glLoadIdentity();									

}



void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function

{

	switch (key) {

		///	Manipulacion de Hombro

	case 'h':

		angHombro += 0.5f;

		break;

	case 'H':

		angHombro -= 0.5f;

		break;
		///	Manipulacion de Codo

	case 'c':

		angCodo += 0.5f;

		break;

	case 'C':

		angCodo -= 0.5f;

		break;

		///	Manipulacion de Mano

	case 'm':

		angMano += 0.5f;

		break;

	case 'M':

		angMano -= 0.5f;

		break;


		///	Manipulacion de Pulgar	1

	case 'a':

		angPulgar1 += 0.5f;

		break;

	case 'A':


		angPulgar1 -= 0.5f;

		break;

		///	Manipulacion de Pulgar	2

	case 'b':

		angPulgar2 += 0.5f;

		break;

	case 'B':


		angPulgar2 -= 0.5f;

		break;

		///	Manipulacion de Indice	1

	case 'd':

		angIndice1 += 0.5f;

		break;

	case 'D':


		angIndice1 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de Indice	2

	case 'e':

		angIndice2 += 0.5f;

		break;

	case 'E':


		angIndice2 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de Indice	3

	case 'f':

		angIndice3 += 0.5f;

		break;

	case 'F':


		angIndice3 -= 0.5f;

		break;

		////		TERMINO


		///		DEDO MEDIO

		///	Manipulacion de MEDIO	1

	case 'g':

		angMedio1 += 0.5f;

		break;

	case 'G':


		angMedio1 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de Medio	2

	case 'i':

		angMedio2 += 0.5f;

		break;

	case 'I':


		angMedio2 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de Medio	3

	case 'j':

		angMedio3 += 0.5f;

		break;

	case 'J':


		angMedio3 -= 0.5f;

		break;

		////		TERMINO

		///    DEDO ANULAR



		///	Manipulacion de ANULAR	1

	case 'k':

		angAnular1 += 0.5f;

		break;

	case 'K':


		angAnular1 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de ANULAR	2

	case 'l':

		angAnular2 += 0.5f;

		break;

	case 'L':


		angAnular2 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de ANULAR	3

	case 'n':

		angAnular3 += 0.5f;

		break;

	case 'N':


		angAnular3 -= 0.5f;

		break;

		////		TERMINO

		///			DEDO ME�IQUE



		///	Manipulacion de ME�IQUE	1

	case 'o':

		angMenique1 += 0.5f;

		break;

	case 'O':


		angMenique1 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de ME�IQUE	2

	case 'p':

		angMenique2 += 0.5f;

		break;

	case 'P':


		angMenique2 -= 0.5f;

		break;

		////		TERMINO

		///	Manipulacion de ME�IQUE	3

	case 'q':

		angMenique3 += 0.5f;

		break;

	case 'Q':


		angMenique3 -= 0.5f;

		break;

		////		TERMINO

	case 'w':

	case 'W':

		transZ += 0.2f;

		break;

	case 's':

	case 'S':

		transZ -= 0.2f;

		break;

	case 'y':




		transX += 0.2f;

		break;

	case 'Y':

		transX -= 0.2f;

		break;

	case 27:        // Cuando Esc es presionado...

		exit(0);   // Salimos del programa

		break;

	default:        // Cualquier otra

		break;

	}

	glutPostRedisplay();

}



void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)

{

	switch (a_keys) {

	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...

		angleX += 2.0f;

		break;

	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...

		angleX -= 2.0f;

		break;

	case GLUT_KEY_LEFT:

		angleY += 2.0f;

		break;

	case GLUT_KEY_RIGHT:

		angleY -= 2.0f;

		break;

	default:

		break;

	}

	glutPostRedisplay();

}





int main(int argc, char** argv)   // Main Function

{

	glutInit(&argc, argv); // Inicializamos OpenGL

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )

	screenW = glutGet(GLUT_SCREEN_WIDTH);

	screenH = glutGet(GLUT_SCREEN_HEIGHT);

	glutInitWindowSize(500, 500);	// Tama�o de la Ventana

	glutInitWindowPosition(0, 0);	//Posicion de la Ventana

	glutCreateWindow("Practica 5"); // Nombre de la Ventana

	printf("Resolution H: %i \n", screenW);

	printf("Resolution V: %i \n", screenH);

	InitGL();						// Parametros iniciales de la aplicacion

	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo

	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano

	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado

	glutSpecialFunc(arrow_keys);	//Otras

	glutMainLoop();          // 



	return 0;
}