//////////////////////////////////////////////////////////////////////////////
//  Laboratorio de Computación Gráfica                                    ////
//  Practica # 09 Texturas II Transparencias                              ////
//  Nombre: Pacheco Franco Jesús Enrique                                  ////
//  Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027   ////
//  Grupo: 02                                                             ////
//  Semestre: 2018-2                                                      ////
//  Fecha: 18/Abril/2018                                                  ////
//////////////////////////////////////////////////////////////////////////////

/*
	Todas las texturas que se usaron en este programa se encuentran en la carpeta
	texturas y todas ellas son tipo tga.

	< : Giro sentido antihorario con respecto a (0,1,0)
	> : Giro sentido horario con respecto a (0,1,0)
	^ : Giro sentido antihorario con respecto a (1,0,0)
	v : Giro sentido horario con respecto a (1,0,0)

	w : Carama hacia enfrente
	s : Camara hacia atras
	a : Camara a la izquierda
	d : Camara a la derecha
	
*/

#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };			// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };			// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };		// Light Position


CTexture t_Ajedrez1;
CTexture t_Ajedrez2;
CTexture t_metal01;

/* MIS TEXTURAS */

CTexture chessboard;
CTexture wood;
CTexture darkerWood;

CTexture ornament;
CTexture squareOrnament;


int font = (int) GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid ) {
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA((char *)"texturas/01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP((char *)"texturas/metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA((char *)"texturas/02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	/* MIS CARGAS DE TEXTURAS */

	chessboard.LoadTGA((char *)"texturas/chessboard.tga");
	chessboard.BuildGLTexture();
	chessboard.ReleaseImage();

	wood.LoadTGA((char *)"texturas/wood.tga");
	wood.BuildGLTexture();
	wood.ReleaseImage();

	darkerWood.LoadTGA((char *)"texturas/darkerWood.tga");
	darkerWood.BuildGLTexture();
	darkerWood.ReleaseImage();

	ornament.LoadTGA((char *)"texturas/ornament.tga");
	ornament.BuildGLTexture();
	ornament.ReleaseImage();

	squareOrnament.LoadTGA((char *)"texturas/squareOrnament.tga");
	squareOrnament.BuildGLTexture();
	squareOrnament.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string) {
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint top, GLuint outline) {

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

		
		glBindTexture(GL_TEXTURE_2D, outline);   // Textura para todo el contorno

			glBegin(GL_POLYGON);	//Front
				glColor3f(1.0,1.0,1.0);
				glNormal3f( 0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
					glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
					glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
					glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
			glEnd();
	
			glBegin(GL_POLYGON);	//Right
				glNormal3f( 1.0f, 0.0f, 0.0f);
					glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
					glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
					glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
					glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glEnd();

			glBegin(GL_POLYGON);	//Back
				glNormal3f( 0.0f, 0.0f,-1.0f);
					glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
					glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
					glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
					glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
			glEnd();

			glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
					glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
					glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
					glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
					glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
			glEnd();

			glBegin(GL_POLYGON);  //Bottom
				glNormal3f( 0.0f,-1.0f, 0.0f);
					glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
					glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
					glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
					glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
			glEnd();

		glBindTexture(GL_TEXTURE_2D, top);   // choose the texture to use.
			glBegin(GL_POLYGON);  //Top
				glNormal3f( 0.0f, 1.0f, 0.0f);
					glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
					glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
					glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
					glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
			glEnd();
}

void renderChair(float height, float width, float length, GLuint texture) {

	glPushMatrix(); // Base
		glScalef(length,height*0.0714,width);
		prisma(texture, texture);
	glPopMatrix(); // Fin Base

	glPushMatrix(); // Pata Izq Front
		glTranslatef(-0.375*length,-(height*(0.0714+0.3571))/2 ,0.375*width);
		glScalef(length*0.25,height*0.3571,width*0.25);
		prisma(texture, texture);
	glPopMatrix();

	glPushMatrix(); // Pata Izq Tras 
		glTranslatef(-0.375*length,-(height*(0.0714+0.3571))/2 ,-0.375*width);
		glScalef(length*0.25,height*0.3571,width*0.25);
		prisma(texture, texture);
	glPopMatrix();

	glPushMatrix(); // Pata Der Front
		glTranslatef(0.375*length,-(height*(0.0714+0.3571))/2 ,0.375*width);
		glScalef(length*0.25,height*0.3571,width*0.25);
		prisma(texture, texture);
	glPopMatrix();

	glPushMatrix(); // Pata Der Tras
		glTranslatef(0.375*length,-(height*(0.0714+0.3571))/2 ,-0.375*width);
		glScalef(length*0.25,height*0.3571,width*0.25);
		prisma(texture, texture);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,(height*(0.0714 + 0.5715))/2,-width*0.4375);
		glScalef(length, height*0.5715, width*0.125);
		prisma(texture, texture);
	glPopMatrix();
}

void display ( void ) 
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
		glTranslatef(pos_camX, pos_camY, pos_camZ);
			glRotatef(eye_camX, 1.0, 0.0, 0.0);
			glRotatef(eye_camY, 0.0, 1.0, 0.0);
			glRotatef(eye_camZ, 0.0, 0.0, 1.0);
			
			// Ejes de Referencia

			glBegin(GL_LINES);
				glColor3f(1.0, 0.0, 0.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(100.0f, 0.0f, 0.0f);
				glColor3f(0.0, 1.0, 0.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(0.0f, 100.0f, 0.0f);
				glColor3f(0.0, 0.0, 1.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(0.0f, 0.0f, 100.0f);
			glEnd();

			glPushMatrix(); // Parte Superior Mesa
				glTranslatef(0.0f, 7.0f, 0.0f);

				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);

				glPushMatrix(); 
					glColor3f(1.0, 1.0, 1.0);
					glScalef(4.0,2.0,4.0);  
					prisma(chessboard.GLindex, ornament.GLindex);
				glPopMatrix();

				glPushMatrix(); // Lado Derecho
					glTranslatef(3.5f,0.0f,0.0f);
					glScalef(3.0f, 2.0, 8.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glPushMatrix(); // Lado Izquierdo
					glTranslatef(-3.5f,0.0f,0.0f);
					glScalef(3.0f, 2.0, 8.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glPushMatrix(); // Lado Inferior
					glTranslatef(0.0f,0.0f,3.0f);
					glScalef(4.0f, 2.0, 2.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glPushMatrix(); // Lado Inferior
					glTranslatef(0.0f,0.0f,-3.0f);
					glScalef(4.0f, 2.0, 2.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glDisable(GL_ALPHA_TEST);

			glPopMatrix(); // Fin Parte Superior Mesa

			glPushMatrix();
				glTranslatef(-4.0f, 1.0f, 3.0f);

				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);

				glPushMatrix();
					glScalef(2.0f, 10.0f, 2.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(8.0f, 0.0f, 0.0f);
					glScalef(2.0f, 10.0f, 2.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0f, 0.0f, -6.0f);
					glScalef(2.0f, 10.0f, 2.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				
				glPushMatrix();
					glTranslatef(8.0f, 0.0f, -6.0f);
					glScalef(2.0f, 10.0f, 2.0f);
					prisma(ornament.GLindex, ornament.GLindex);
				glPopMatrix();

				glDisable(GL_ALPHA_TEST);

			glPopMatrix(); // Fin Patas Mesa


			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);

			glPushMatrix(); // Silla Frontal
				glTranslatef(0.0, 1.5, 5.0f);
				glRotatef(180, 0.0, 1.0, 0.0);
				renderChair(14.0,4.0,4.0,squareOrnament.GLindex);
			glPopMatrix();

			glPushMatrix(); // Silla Trasera
				glTranslatef(0.0, 1.5, -5.0f);
				renderChair(14.0,4.0,4.0,squareOrnament.GLindex);
			glPopMatrix();

			glDisable(GL_ALPHA_TEST);
			
	glPopMatrix(); // Camara

	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, (char *)"Practica 9 Texturas II Transparencias");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, (char *)"Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion() {
		glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 9 Texturas II Transparencias"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}