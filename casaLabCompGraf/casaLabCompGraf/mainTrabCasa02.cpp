///////////////////////////////////////////////////////////////////////////
// Laboratorio de Computación Gráfica                                  ////
// Trabajo en casa # 02                                                ////
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Blanco de fondo
	//glClearDepth(1.0f);								// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);							// Tipo de Depth Testing a realizar
	
	
}

/* Funcion que se encarga de dibujar cuadrados unitarios del color
	que se le pasa como tercer argumento, toma como centro del cuadrado
	el vertice que se le pasa en las coordenadas de los dos primeros
	parametros */

void drawPixel(float xPos, float yPos, float color[3]) {
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_QUADS);
		glVertex3f(xPos + 0.5f,yPos + 0.5f, -1.2f);
		glVertex3f(xPos - 0.5f, yPos + 0.5f, -1.2f);
		glVertex3f(xPos - 0.5f, yPos - 0.5f, -1.2f);
		glVertex3f(xPos + 0.5f, yPos - 0.5f, -1.2f);
	glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo a dibujar
	
	/* Si no pongo mis vértices dentro de glBegin y glEnd no se muestran en pantalla */
	
	// Colores

	float rojoCereza[3] = {1.0f, 0.0f, 0.0f};
	float verdeHoja[3] = { 0.0f, 0.66f, 0.34f };
	float negroRama[3] = {0.0f, 0.0f, 0.0f};

	// Fila 01

	drawPixel(4.0f, 1.0f, negroRama);
	drawPixel(5.0f, 1.0f, negroRama);
	drawPixel(6.0f, 1.0f, negroRama);
	drawPixel(7.0f, 1.0f, negroRama);

	// Fila 02

	drawPixel(3.0f, 2.0f, negroRama);
	drawPixel(8.0f, 2.0f, negroRama);
	drawPixel(13.0f, 2.0f, negroRama);
	drawPixel(14.0f, 2.0f, negroRama);
	drawPixel(15.0f, 2.0f, negroRama);
	drawPixel(16.0f, 2.0f, negroRama);

	drawPixel(4.0f, 2.0f, rojoCereza);
	drawPixel(5.0f, 2.0f, rojoCereza);
	drawPixel(6.0f, 2.0f, rojoCereza);
	drawPixel(7.0f, 2.0f, rojoCereza);
	
	// Fila 03

	drawPixel(2.0f, 3.0f, negroRama);
	drawPixel(9.0f, 3.0f, negroRama);
	drawPixel(12.0f, 3.0f, negroRama);
	drawPixel(17.0f, 3.0f, negroRama);

	drawPixel(3.0f, 3.0f, rojoCereza);
	drawPixel(4.0f, 3.0f, rojoCereza);
	drawPixel(5.0f, 3.0f, rojoCereza);
	drawPixel(6.0f, 3.0f, rojoCereza);
	drawPixel(7.0f, 3.0f, rojoCereza);
	drawPixel(8.0f, 3.0f, rojoCereza);
	drawPixel(13.0f, 3.0f, rojoCereza);
	drawPixel(14.0f, 3.0f, rojoCereza);
	drawPixel(15.0f, 3.0f, rojoCereza);
	drawPixel(16.0f, 3.0f, rojoCereza);
	
	// Fila 04

	drawPixel(2.0f, 4.0f, negroRama);
	drawPixel(9.0f, 4.0f, negroRama);
	drawPixel(11.0f, 4.0f, negroRama);
	drawPixel(18.0f, 4.0f, negroRama);

	drawPixel(3.0f, 4.0f, rojoCereza);
	drawPixel(4.0f, 4.0f, rojoCereza);
	drawPixel(5.0f, 4.0f, rojoCereza);
	drawPixel(6.0f, 4.0f, rojoCereza);
	drawPixel(8.0f, 4.0f, rojoCereza);
	drawPixel(12.0f, 4.0f, rojoCereza);
	drawPixel(13.0f, 4.0f, rojoCereza);
	drawPixel(16.0f, 4.0f, rojoCereza);
	drawPixel(17.0f, 4.0f, rojoCereza);

	// Fila 05

	drawPixel(2.0f, 5.0f, negroRama);
	drawPixel(9.0f, 5.0f, negroRama);
	drawPixel(11.0f, 5.0f, negroRama);
	drawPixel(18.0f, 5.0f, negroRama);

	drawPixel(3.0f, 5.0f, rojoCereza);
	drawPixel(4.0f, 5.0f, rojoCereza);
	drawPixel(5.0f, 5.0f, rojoCereza);
	drawPixel(6.0f, 5.0f, rojoCereza);
	drawPixel(8.0f, 5.0f, rojoCereza);
	drawPixel(12.0f, 5.0f, rojoCereza);
	drawPixel(14.0f, 5.0f, rojoCereza);
	drawPixel(15.0f, 5.0f, rojoCereza);
	drawPixel(16.0f, 5.0f, rojoCereza);
	drawPixel(17.0f, 5.0f, rojoCereza);
	
	// Fila 06

	drawPixel(2.0f, 6.0f, negroRama);
	drawPixel(9.0f, 6.0f, negroRama);
	drawPixel(11.0f, 6.0f, negroRama);
	drawPixel(18.0f, 6.0f, negroRama);

	drawPixel(3.0f, 6.0f, rojoCereza);
	drawPixel(4.0f, 6.0f, rojoCereza);
	drawPixel(5.0f, 6.0f, rojoCereza);
	drawPixel(7.0f, 6.0f, rojoCereza);
	drawPixel(8.0f, 6.0f, rojoCereza);
	drawPixel(12.0f, 6.0f, rojoCereza);
	drawPixel(13.0f, 6.0f, rojoCereza);
	drawPixel(14.0f, 6.0f, rojoCereza);
	drawPixel(15.0f, 6.0f, rojoCereza);
	drawPixel(16.0f, 6.0f, rojoCereza);
	drawPixel(17.0f, 6.0f, rojoCereza);

	// Fila 07

	drawPixel(3.0f, 7.0f, negroRama);
	drawPixel(8.0f, 7.0f, negroRama);
	drawPixel(11.0f, 7.0f, negroRama);
	drawPixel(18.0f, 7.0f, negroRama);

	drawPixel(4.0f, 7.0f, rojoCereza);
	drawPixel(5.0f, 7.0f, rojoCereza);
	drawPixel(6.0f, 7.0f, rojoCereza);
	drawPixel(7.0f, 7.0f, rojoCereza);
	drawPixel(12.0f, 7.0f, rojoCereza);
	drawPixel(13.0f, 7.0f, rojoCereza);
	drawPixel(14.0f, 7.0f, rojoCereza);
	drawPixel(15.0f, 7.0f, rojoCereza);
	drawPixel(16.0f, 7.0f, rojoCereza);
	drawPixel(17.0f, 7.0f, rojoCereza);
	
	// Fila 08

	drawPixel(4.0f, 8.0f, negroRama);
	drawPixel(5.0f, 8.0f, negroRama);
	drawPixel(6.0f, 8.0f, negroRama);
	drawPixel(7.0f, 8.0f, negroRama);
	drawPixel(12.0f, 8.0f, negroRama);
	drawPixel(17.0f, 8.0f, negroRama);

	drawPixel(13.0f, 8.0f, rojoCereza);
	drawPixel(14.0f, 8.0f, rojoCereza);
	drawPixel(15.0f, 8.0f, rojoCereza);
	drawPixel(16.0f, 8.0f, rojoCereza);

	// Fila 09

	drawPixel(6.0f, 9.0f, negroRama);
	drawPixel(13.0f, 9.0f, negroRama);
	drawPixel(14.0f, 9.0f, negroRama);
	drawPixel(15.0f, 9.0f, negroRama);
	drawPixel(16.0f, 9.0f, negroRama);

	// Fila 10

	drawPixel(7.0f, 10.0f, negroRama);
	drawPixel(12.0f, 10.0f, negroRama);

	// Fila 11

	drawPixel(8.0f, 11.0f, negroRama);
	drawPixel(11.0f, 11.0f, negroRama);

	// Fila 12

	drawPixel(8.0f, 12.0f, negroRama);
	drawPixel(11.0f, 12.0f, negroRama);

	// Fila 13

	drawPixel(9.0f, 13.0f, negroRama);
	drawPixel(12.0f, 13.0f, negroRama);
	drawPixel(13.0f, 13.0f, negroRama);
	drawPixel(14.0f, 13.0f, negroRama);

	// Fila 14

	drawPixel(10.0f, 14.0f, negroRama);
	drawPixel(12.0f, 14.0f, negroRama);
	drawPixel(15.0f, 14.0f, negroRama);

	drawPixel(13.0f, 14.0f, verdeHoja);
	drawPixel(14.0f, 14.0f, verdeHoja);

	// Fila 15

	drawPixel(10.0f, 15.0f, negroRama);
	drawPixel(11.0f, 15.0f, negroRama);
	drawPixel(12.0f, 15.0f, negroRama);
	drawPixel(16.0f, 15.0f, negroRama);

	drawPixel(13.0f, 15.0f, verdeHoja);
	drawPixel(14.0f, 15.0f, verdeHoja);
	drawPixel(15.0f, 15.0f, verdeHoja);

	// Fila 16

	drawPixel(11.0f, 16.0f, negroRama);
	drawPixel(13.0f, 16.0f, negroRama);
	drawPixel(16.0f, 16.0f, negroRama);

	drawPixel(14.0f, 16.0f, verdeHoja);
	drawPixel(15.0f, 16.0f, verdeHoja);

	// Fila 17

	drawPixel(11.0f, 17.0f, negroRama);
	drawPixel(14.0f, 17.0f, negroRama);
	drawPixel(15.0f, 17.0f, negroRama);
	drawPixel(16.0f, 17.0f, negroRama);

	// Fila 18

	drawPixel(17.0f, 18.0f, negroRama);

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
	glOrtho(-5.0,25.0,-5.0,25,0.1,2);

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

