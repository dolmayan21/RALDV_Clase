//Semestre 2018 - 2
//************************************************************//
//*************************************************************//
//************** Alumno (s): León del Villar Rubén Alejandro***//
//************	Visual Studio 2015		************************//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;


int nucleo = 0;
int proton1 = 0;
int proton2 = 0;
int proton3 = 0;
int proton4 = 0;



float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat MercurioDiffuse[] = { 0.7f, 0.5f, 0.999f, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.0123f, 0.789f, 1.0f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };



void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	
	glLightfv(GL_LIGHT1,GL_DIFFUSE,SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,horizontal,vertical);
	glEnable(GL_LIGHTING);							   //glutSolidSphere(2, 12, 12);  //Draw Sun (radio,H,V);   vista de lineas
	glPopMatrix();

	glPushMatrix();
		glRotatef(135, 1.0, 0.0, 0.0);
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//Mercurio gira sobre el eje del sol
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
		glTranslatef(2.5, 0.2, 0.2);
		glPushMatrix();
			glRotatef(mercurio, 0.0, 1.0, 0.0); //gira sobre su propio eje
			glColor3f(0.545, 0.251, 0.075);
			glutSolidSphere(0.3, 10, 10);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(175, 1.0, 0.0, 0.0);
	glRotatef(venus, 0.0, 1.0, 0.0);	   //Venus gira sobre el eje del sol
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
	glTranslatef(3.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(venus, 0.0, 1.0, 0.0);	//Venus gira sobre su eje
	glColor3f(0.957, 0.643, 0.376);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glRotatef(215, 1.0, 0.0, 0.0);
		glRotatef(tierra, 0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
		glTranslatef(4.8, 0.2, 0.2);
		glPushMatrix();
		glRotatef(tierra, 0.0, 0.0, 1.0);	//tierra gira sobre su eje
		glColor3f(0.0, 0.0, 1.0);
		glutSolidSphere(0.5, 10, 10);
	glPopMatrix();
	//luna
	glColor3f(0.2, 0.643, 0.376);
	glRotatef(luna, 0.0, 0.0, 1.0);	        //luna gira sobre su eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glTranslatef(0.8, 0.0, 0.0);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	//Marte
	glPushMatrix();
	glRotatef(255, 1.0, 0.0, 0.0);
	glRotatef(marte, 0.0, 1.0, 0.0);	//Marte gira sobre su eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glTranslatef(6.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(marte, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	glPopMatrix();


	//Jupiter
	glPushMatrix();
	glPushMatrix();
	glRotatef(295, 1.0, 0.0, 0.0);
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glTranslatef(8.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidSphere(0.6, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.2, 0.6, 0.6);            //luna 1
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(0.8, 0.0, 0.0);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();
	//luna 2
	glColor3f(0.5, 0.2, 0.1);
	glRotatef(-luna - 1, 0.0, 0.0, 1.0);
	glTranslatef(1.3, 0.0, 0.0);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//saturn
	glRotatef(-120.0, 1.0, 0.0, 0.0);
	glColor3f(0.9, 0.5, 0.7);
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glTranslatef(12, 0.2, 0.2);
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glutSolidSphere(0.7, 10.0, 10.0);
	glColor3f(1.0, 0.0, 0.0);
	glScalef(0.4, 0.4, 0.25);
	glutWireTorus(1, 3, 10, 10);
	glPushMatrix();//luna1
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(4.5, 0.2, 0.2);
	glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	glPushMatrix();//luna2
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(luna, 1.0, 0.0, 0.0);
	glTranslatef(0.2, 4.2, 0.2);
	glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	glPopMatrix();

	//URANO
	glPushMatrix();
	glRotatef(20, 1.0, 0.0, 0.0);
	glRotatef(-urano, 0.0, 1.0, 0.0);
	glTranslatef(15, 0.0, 0.0);
	glPushMatrix();
	glRotatef(-urano, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.3, 0.9);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//NEPTUNO
	glPushMatrix();
	glRotatef(-89, 1.0, 0.0, 0.0);
	glRotatef(neptuno, 0.0, 1.0, 0.0);
	glTranslatef(17, 0.0, 0.0);
	glPushMatrix();
	glRotatef(neptuno, 0.0, 1.0, 0.0);
	glColor3f(0.0, 0.7, .6);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	glPopMatrix();

	/*
	//	           ATOMO

	// NUCLEO

	glPushMatrix();
	glRotatef(nucleo, 0.0, 1.0, 0.0);	//El nucleo gira sobre su eje
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(2, 12, 12);
	glPushMatrix();
	glTranslatef(-5.0, 0.0, 0.0);
	glRotatef(proton1 + 40, 0.0, 1.0, 0.0);	//El nucleo gira sobre su eje
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(225.0, 0.0, 0.0, 1.0);
	glRotatef(proton2, 1.0, 0.0, 0.0);	//El nucleo gira sobre su eje
	glTranslatef(0.0, 5.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(135.0, 0.0, 0.0, 1.0);
	glRotatef(proton3 + 40, 1.0, 0.0, 0.0);	//El nucleo gira sobre su eje
	glTranslatef(0.0, 5.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(proton4, 1.0, 0.0, 0.0);	//El nucleo gira sobre su eje
	glTranslatef(0.0, 5.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(1, 12, 12);
	glPopMatrix();
	*/

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol + 1) % 360;
		mercurio = (mercurio + 2) % 360;
		venus = (venus + 1) % 360;
		tierra = (tierra - 1) % 360;
		luna = (luna + 1) % 360;
		marte = (marte - 2) % 360;
		jupiter = (jupiter - 1) % 360;
		saturno = (saturno + 1) % 360;
		urano = (urano + 5) % 360;
		neptuno = (neptuno + 1) % 360;

		nucleo = (nucleo + 1) % 360;
		proton1 = (proton1 + 10) % 360;
		proton2 = (proton2 + 10) % 360;
		proton3 = (proton3 + 10) % 360;
		proton4 = (proton4 + 5) % 360;

		dwLastUpdateTime = dwCurrentTime;

	}

	glutPostRedisplay();   ///que vuelva a dibujar
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

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
	glutInitWindowSize(500, 500);	// Tama?o de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci?n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci?n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci?n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);  //encender la animacion desde un principio--------------------
	glutMainLoop();          // 

	return 0;
}