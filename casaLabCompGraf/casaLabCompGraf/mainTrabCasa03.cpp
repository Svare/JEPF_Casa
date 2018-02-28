///////////////////////////////////////////////////////////////////////////
// Laboratorio de Computación Gráfica                                  ////
// Trabajo en casa # 03                                                ////
// Nombre: Pacheco Franco Jesús Enrique                                ////
// Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027 ////
// Grupo: 02                                                           ////
// Semestre: 2018-2                                                    ////
// Fecha: 28/Febrero/2018                                              ////
///////////////////////////////////////////////////////////////////////////

/* Con la tecla 'a' hacemos girar el prisma
	Con la tecla 'w' acercamos el prisma
	Con la tecla 's' alejamos el prisma */

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>

#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float Z = 0.0; // Para acercar o alejar el prisma
float A = 0.0; // Para Rotar el prisma


void InitGL ( GLvoid )     // Inicializamos parametros
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

/* Esta funcion es la encargada de dibujar el prisma, tiene como parametros el largo, el alto y el ancho
	y la piramide se dubuja justamente al centro del punto actual que se tiene cuando se hace la llamada
	a la funcion*/

void prismaRectangular(float longitud, float altura, float anchura) {
	GLfloat x, y, z;

	x = longitud / 2;
	y = altura / 2;
	z = anchura / 2;

	GLfloat vertexes[8][3] = {
								{ -x,y,-z },
								{ x,y,-z },
								{ x,y,z },
								{ -x,y,z },
								{ -x,-y,-z },
								{ -x,-y,z },
								{ x,-y,z },
								{ x,-y,-z },
							};
	
	glBegin(GL_QUADS); // FRONT
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3fv(vertexes[0]);
		glVertex3fv(vertexes[4]);
		glVertex3fv(vertexes[7]);
		glVertex3fv(vertexes[1]);
	glEnd();

	glBegin(GL_QUADS); // BACK
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3fv(vertexes[3]);
		glVertex3fv(vertexes[2]);
		glVertex3fv(vertexes[6]);
		glVertex3fv(vertexes[5]);
	glEnd();

	glBegin(GL_QUADS); // LEFT
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(vertexes[0]);
		glVertex3fv(vertexes[3]);
		glVertex3fv(vertexes[5]);
		glVertex3fv(vertexes[4]);
	glEnd();

	glBegin(GL_QUADS); // RIGHT
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3fv(vertexes[1]);
		glVertex3fv(vertexes[7]);
		glVertex3fv(vertexes[6]);
		glVertex3fv(vertexes[2]);
	glEnd();

	glBegin(GL_QUADS); // TOP
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3fv(vertexes[0]);
		glVertex3fv(vertexes[1]);
		glVertex3fv(vertexes[2]);
		glVertex3fv(vertexes[3]);
	glEnd();

	glBegin(GL_QUADS); // BOTTOM
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3fv(vertexes[4]);
		glVertex3fv(vertexes[5]);
		glVertex3fv(vertexes[6]);
		glVertex3fv(vertexes[7]);
	glEnd();
}

//void animation() {
//	A += 0.1;
//	glutPostRedisplay();
//}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.	

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);
		glVertex3f(100.0f, 0.0f, -1.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0.0f, 100.0f, -1.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0.0f, 0.0f, -1.0f);
	glEnd();

	glTranslatef(0.0, 0.0, -100.0 + Z);
	glRotatef(0.0 + A, 1.0, 1.0, 0.0);

	// Funcion que dibuja el prisma

	prismaRectangular(50.0, 100.0, 50.0);
	

    glutSwapBuffers ( );
    //glFlush();
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

	//glOrtho(-2, 2, -2, 2, -1.0, 20);

	glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 2000.0f);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			Z += 10.0;
			printf("Posicion en Z: %f\n", transZ);
			printf("\nProfundidad: %f\n",Z);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			Z -= 10.0;
			printf("Posicion en Z: %f\n", transZ);
			printf("\nProfundidad: %f\n", Z);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			A += 5.0;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
 /* glutIdleFunc(animation);*/
  glutMainLoop        ( );          //

  

  return 0;
}



