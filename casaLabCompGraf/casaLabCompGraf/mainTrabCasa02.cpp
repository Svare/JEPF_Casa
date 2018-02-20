///////////////////////////////////////////////////////////////////////////
// Laboratorio de Computación Gráfica                                  ////
// Practica # 02                                                       ////
// Nombre: Pacheco Franco Jesús Enrique                                ////
// Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027 ////
// Grupo: 02                                                           ////
// Semestre: 2018-2                                                    ////
// Fecha: 19/Febrero/2018                                              ////
///////////////////////////////////////////////////////////////////////////

// Captura de Pantalla de lo que hicimos para que haya evidencia esto tambien va al repositorio
// que se pueda ver fecha y hora

#include "Main.h"

void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo a dibujar
	
	/* Si no pongo mis vértices dentro de glBegin y glEnd no se muestran en pantalla */

	glPointSize(10.0);
//	glLineWidth(5.0);
	glColor3f(0.0f, 0.0f, 0.0f);
/*
		glBegin(GL_POINTS);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_LINE_STRIP);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_QUADS);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.0f, -1.2f);
			glVertex3f(-3.0f, 3.0f, -1.2f);
			glVertex3f(3.5f, 4.0f, -1.2f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(4.0f, -1.0f, -1.2f);
		glEnd();
*/
	glBegin(GL_LINE_LOOP);
		glVertex3f(3.0f, 4.0f, -1.2f);
		glVertex3f(3.0f, 6.0f, -1.2f);
		glVertex3f(-5.0f, 6.0f, -1.2f);
		glVertex3f(-5.0f, -6.0f, -1.2f);
		glVertex3f(3.0f, -6.0f, -1.2f);
		glVertex3f(3.0f, -4.0f, -1.2f);
		glVertex3f(-3.0f, -4.0f, -1.2f);
		glVertex3f(-3.0f, 4.0f, -1.2f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, 4.0f, -1.2f);
			glVertex3f(3.0f, 6.0f, -1.2f);
			glVertex3f(-5.0f, 6.0f, -1.2f);
			glVertex3f(-3.0f, 4.0f, -1.2f);
		glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-5.0f, 6.0f, -1.2f);
			glVertex3f(-5.0f, -6.0f, -1.2f);
			glVertex3f(-3.0f, -4.0f, -1.2f);
			glVertex3f(-3.0f, 4.0f, -1.2f);
		glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-5.0f, -6.0f, -1.2f);
			glVertex3f(-3.0f, -4.0f, -1.2f);
			glVertex3f(3.0f, -4.0f, -1.2f);
			glVertex3f(3.0f, -6.0f, -1.2f);
	glEnd();

	glFlush();
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

	// Ortogonal
	glOrtho(-10,10,-10,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

