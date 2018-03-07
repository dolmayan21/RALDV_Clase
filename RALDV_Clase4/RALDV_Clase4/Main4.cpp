//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//*********** Alumno (s): Leon Del Villar Rubén Alejandro*****//
//*************											******//
//*************		Visual Studio 2015					*****//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = -5.0f;
int screenW = 0.0;
int screenH = 0.0; 
float rotY = 0.0;
float rotX = 0.0;

void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(0.0f, 0.0f, transZ);
		glRotatef(rotY, 0, 1, 0);
		glRotatef(rotX, 1, 0, 0);
		glTranslatef(transX, 0.0f, 0.0f);
		
		//Poner Código Aquí.

		//cabeza 
		glPushMatrix();

			glScalef(4,4,4);
			glColor3f(0,0,1);
			prisma();

		glPopMatrix();

		//Cuello

		glTranslatef(0, -3, 0);

			glPushMatrix();
			glScalef(3,2,3);
			glColor3f(1,0,0);
			prisma();

		glPopMatrix();
		// TRONCO
		glTranslatef(0,-6, 0);

		glPushMatrix();
			glScalef(10, 10, 3);
			glColor3f(0,1,0);
			prisma();
		glPopMatrix();

		//Pierna Izquierda
			glTranslatef(2.5,-7.5, 0);
		glPushMatrix();
			glScalef(2,5,3);
			glColor3f(0,1,0);
			prisma();
		glPopMatrix();

				//rodilla
		glTranslatef(0, -3, 0);

		glPushMatrix();
			glScalef(2,1,3);
			glColor3f(1,1,0);
			prisma();
		glPopMatrix();
				//tobillo
		glTranslatef(0, -3, 0);

		glPushMatrix();
			glScalef(2, 5, 3);
			glColor3f(0, 1, 0);
			prisma();		
		glPopMatrix();
				
				//tobillito
		glTranslatef(0, -0.75, 0);
		glPushMatrix();

				glScalef(2, 0.5, 3);
				glColor3f(1, 1, 0);
				prisma();
		glPopMatrix();

				//Pie
		glTranslatef(0, -1.25, 0);

		glPushMatrix();
		glScalef(2,2,3);
		glColor3f(1, 0, 1);
		prisma();

		glPopMatrix();

				// Pierna Derecha
		glTranslatef(-5, 8, 0);

		glPushMatrix();
		glScalef(2, 5, 3);
		glColor3f(0, 1, 0);
		prisma();
		glPopMatrix();

		//rodilla
		glTranslatef(0, -3, 0);

		glPushMatrix();
		glScalef(2, 1, 3);
		glColor3f(1, 1, 0);
		prisma();
		glPopMatrix();
		//tobillo
		glTranslatef(0, -3, 0);

		glPushMatrix();
		glScalef(2, 5, 3);
		glColor3f(0, 1, 0);
		prisma();
		glPopMatrix();

		//tobillito
		glTranslatef(0, -0.75, 0);
		glPushMatrix();

		glScalef(2, 0.5, 3);
		glColor3f(1, 1, 0);
		prisma();
		glPopMatrix();

		//Pie
		glTranslatef(0, -1.25, 0);

		glPushMatrix();
		glScalef(2, 2, 3);
		glColor3f(1, 0, 1);
		prisma();

		glPopMatrix();


		// Brazo 
				//Hombro
		glTranslatef(8.25,20, 0);
		glPushMatrix();
		glScalef(2,1,3);
		prisma();
		glPopMatrix();
				//Brazo
		glTranslatef(2, 0, 0);
		glPushMatrix();
		glScalef(3, 1, 3);
		glColor3f(0,0,1);
		prisma();
		glPopMatrix();

				//Codo
		glTranslatef(1.75, 0, 0);
		glPushMatrix();
		glScalef(0.5, 1, 3);
		glColor3f(0, 1, 1);
		prisma();
		glPopMatrix();

				//Brazo

		glTranslatef(2.25, 0, 0);
		glPushMatrix();
		glScalef(4, 1, 3);
		glColor3f(0, 1, 1);
		prisma();
		glPopMatrix();


				//Muñeca 2

		glTranslatef(2.05, 0, 0);
		glPushMatrix();
		glScalef(.1, 1, 3);
		glColor3f(1, 0, 1);
		prisma();
		glPopMatrix();

		//Mano

		glTranslatef(.55, 0, 0);
		glPushMatrix();
		glScalef(1, 1, 3);
		glColor3f(1, 0, 1);
		prisma();
		glPopMatrix();



		// Brazo 2
			//Hombro
		glTranslatef(-20, 0, 0);
		glPushMatrix();
		glScalef(2, 1, 3);
		prisma();
		glPopMatrix();


		//Brazo
		glTranslatef(-2, 0, 0);
		glPushMatrix();
		glScalef(3, 1, 3);
		glColor3f(0, 0, 1);
		prisma();
		glPopMatrix();

		//Codo
		glTranslatef(-1.75, 0, 0);
		glPushMatrix();
		glScalef(0.5, 1, 3);
		glColor3f(0, 1, 1);
		prisma();
		glPopMatrix();

		//Brazo

		glTranslatef(-2.25, 0, 0);
		glPushMatrix();
		glScalef(4, 1, 3);
		glColor3f(0, 1, 1);
		prisma();
		glPopMatrix();


		//Muñeca 2

		glTranslatef(-2.05, 0, 0);
		glPushMatrix();
		glScalef(.1, 1, 3);
		glColor3f(1, 0, 1);
		prisma();
		glPopMatrix();

		//Mano

		glTranslatef(-.55, 0, 0);
		glPushMatrix();
		glScalef(1, 1, 3);
		glColor3f(1, 0, 1);
		prisma();
		glPopMatrix();



		/*
		//Pierna Izquierda
		glTranslatef(-5, 0, 0);
		glPushMatrix();
		glScalef(1, 5, 3);
		glColor3f(0, 1, 0);
		prisma();
		glPopMatrix();
		*/


  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			transX -= 0.3f;
			break;

		case 'd':
		case 'D':
			transX += 0.3f;
			break;


		
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		rotX -= 0.9;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		rotX += 0.9;
		break;
	case GLUT_KEY_LEFT:
		rotY -= 0.9;
		break;
	case GLUT_KEY_RIGHT:
		rotY -= 0.9;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
