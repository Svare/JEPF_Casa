//////////////////////////////////////////////////////////////////////////////
//  Laboratorio de Computación Gráfica                                    ////
//  Practica # 06 Modelado Jerarquico                                     ////
//  Nombre: Pacheco Franco Jesús Enrique                                  ////
//  Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027   ////
//  Grupo: 02                                                             ////
//  Semestre: 2018-2                                                      ////
//  Fecha: 04/Abril/2018                                                  ////
//////////////////////////////////////////////////////////////////////////////

/*
	W: ACERCAR
	S: ALEJAR
	A: ROTAR ANTIHORARIO EJE Y
	D: ROTAR HORARIO EJE Y
*/

#include "Main.h"


// Variables used to calculate frames per second: (Windows)

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0,mercurio=0,venus=0,tierra=0,luna=0,marte=0,jupiter=0,saturno=0,urano=0,neptuno=0,satelite=0;

double SOL = 0.0, MERCURIO = 0.0,
		VENUS = 0.0, TIERRA = 0.0,
		MARTE = 0.0, JUPITER = 0.0,
		SATURNO = 0.0, URANO = 0.0,
		NEPTUNO = 0.0, LUNA01 = 0.0,
		LUNA02 = 0.0, LUNA03 = 0.0,
		EJE = 0.0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-1200.0+camaraZ);			//camara
	
	/* EJES DE REFERENCIA */

	glBegin(GL_LINES); // Ejes de Referencia
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1500.0f, 0.0f, 0.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 1500.0f, 0.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 1500.0f);
	glEnd(); // Fin Ejes de Referencia
	
	/* SISTEMA SOLAR */

	glPushMatrix();
		glRotatef(SOL,0.0f,1.0f,0.0f);
		glColor3f(1.0f, 1.0f, 0.0f); // Amarillo
		glutWireSphere(50.0f, 20, 20); // Sol
	glPopMatrix();

	glPushMatrix();	
		glRotatef(MERCURIO,0.0f,1.0f,0.0f);
		glTranslatef(110, 0, 0);
		glRotatef(EJE, 0.0f, 1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f); // Rojo
		glutWireSphere(5.0,20,20); // Mercurio
	glPopMatrix();

	glPushMatrix();	
		glRotatef(VENUS,1.0f,1.0f,0.0f);
		glTranslatef(0, 0, 134);
		glRotatef(EJE, 0.0f, 1.0f, 0.0f);
		glColor3f(1.0f, 0.5f, 0.1f); // Naranja
		glutWireSphere(12.0, 20, 20); // Venus
	glPopMatrix();

	glPushMatrix(); // Tierra & Luna
		glRotatef(TIERRA,1.0f,0.0f,0.0f);
		glTranslatef(0, 0, 160);

		glPushMatrix(); // Tierra
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f); // Azul
			glutWireSphere(13.0, 20, 20); // Tierra
		glPopMatrix();// Fin Tierra

		glPushMatrix(); // Luna
			glRotatef(LUNA03,1.0f,1.0f,0.0f);
			glTranslatef(0, 0, 15);
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(1.0, 20, 20); // Luna
		glPopMatrix(); // Fin Luna
	glPopMatrix(); // Fin Tierra & Luna

	glPushMatrix(); // Marte & Lunas
		glRotatef(MARTE,-1.0,1.0,0.0);
		glTranslatef(0, 0, 178.0);

		glPushMatrix(); // Phobos
			glRotatef(LUNA01,0.0f,1.0f,0.0f);
			glTranslatef(9, 0, 0);
			glRotatef(mercurio, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(1.0, 20, 20); // Luna
		glPopMatrix(); // Fin Phobos

		glPushMatrix();
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 0.5f); // Amarillo Claro
			glutWireSphere(7.0, 20, 20); // Marte
		glPopMatrix();

		glPushMatrix(); // Deimos
			glRotatef(LUNA03,1.0f,1.0f,0.0f);
			glTranslatef(0, 0, 11);
			glRotatef(mercurio, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(1.0, 20, 20); // Luna
		glPopMatrix(); // Fin Deimos
	glPopMatrix(); // Marte & Lunas

	/* JUPITER */

	glPushMatrix(); // Jupiter & Lunas
		glRotatef(JUPITER,0.0,1.0,0.0);
		glTranslatef(-329.0, 0, 0.0);

		glPushMatrix(); // Europa
			glRotatef(LUNA01,0.0f,1.0f,0.0f);
			glTranslatef(-84, 0, 0);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(7.0, 20, 20); // Europa
		glPopMatrix(); // Fin Europa

		glPushMatrix();
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(0.52f, 0.33f, 0.11f); // Cafe
			glutWireSphere(70.0, 20, 20); // Jupiter
		glPopMatrix();

		glPushMatrix(); // Ganymede
			glRotatef(LUNA02,1.0f,1.0f,0.0f);
			glTranslatef(0, 0, 98);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(7.0, 20, 20); // Ganymede
		glPopMatrix(); // Fin Ganymede

		glPushMatrix(); // Callisto
			glRotatef(LUNA03,-1.0f,1.0f,0.0f);
			glTranslatef(0, 0, -112);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(7.0, 20, 20); // Callisto
		glPopMatrix(); // Fin Callisto

	glPopMatrix(); // Jupiter & Lunas
	
	glPushMatrix(); // Saturno & Lunas
		glRotatef(SATURNO,-1.0,-1.0,0.0);
		glTranslatef(0.0, 0, -630.0);

		glPushMatrix(); // Mimas
			glRotatef(LUNA01,0.0f,1.0f,0.0f);
			glTranslatef(88, 0, 0);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(1.0, 20, 20); // Mimas
		glPopMatrix(); // Fin Mimas

		glPushMatrix();
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(0.11f, 0.5f, 0.5f); // Verde Pino
			glutWireTorus(10, 85, 20, 20);
			glColor3f(0.33f, 0.11f, 0.52f); // Morado
			glutWireSphere(50.0, 20, 20); // Saturno
		glPopMatrix();

		glPushMatrix(); // Tethys
			glRotatef(LUNA03,1.0f,1.0f,0.0f);
			glTranslatef(0, 0, 96);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(4.0, 20, 20); // Tethys
		glPopMatrix(); // Fin Tethys

	glPopMatrix(); // Saturno & Lunas

	glPushMatrix(); // Urano & Lunas
		glRotatef(URANO,-1.0,0.0,0.0);
		glTranslatef(0.0, 0, -710.0);

		glPushMatrix(); // Puck
			glRotatef(LUNA01,1.0f,1.0f,0.0f);
			glTranslatef(0, 0, 33);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(1.0, 20, 20); // Puck
		glPopMatrix(); // Fin Puck

		glPushMatrix();
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f); // Verde
			glutWireSphere(25.0, 20, 20); // Urano
		glPopMatrix();

		glPushMatrix(); // Titania
			glRotatef(LUNA03,-1.0f,1.0f,0.0f);
			glTranslatef(0, 0, -38);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(4.0, 20, 20); // Titania
		glPopMatrix(); // Fin Titania

	glPopMatrix(); // Fin Urano & Lunas

	glPushMatrix(); // Neptuno & Lunas
		glRotatef(NEPTUNO,1.0,-1.0,0.0);
		glTranslatef(0.0, 0, 820.0);

		glPushMatrix(); // Proteus
			glRotatef(LUNA01,1.0f,1.0f,0.0f);
			glTranslatef(0, 0, 29);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(2.0, 20, 20); // Proteus
		glPopMatrix(); // Fin Proteus

		glPushMatrix();
			glRotatef(EJE, 0.0f, 1.0f, 0.0f);
			glColor3f(0.85f, 0.11f,0.85f); // Rosa
			glutWireSphere(24.0, 20, 20); // Neoptuno
		glPopMatrix();

		glPushMatrix(); // Triton
			glRotatef(LUNA03,-1.0f,1.0f,0.0f);
			glTranslatef(0, 0, -50);
			glRotatef(EJE, 1.0f, 0.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f); // Blanco
			glutWireSphere(10.0, 20, 20); // Titania
		glPopMatrix(); // Fin Triton
	glPopMatrix(); // Neptuno & Lunas

	glutSwapBuffers ();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		
		mercurio = (mercurio - 9) % 360;
		venus = (venus - 8) % 360;
		tierra = (tierra - 7) % 360;
		marte = (marte - 6) % 360;
		jupiter = (jupiter - 5) % 360;
		saturno = (saturno - 4) % 360;
		urano = (urano - 3) % 360;
		neptuno = (neptuno - 2) % 360;
		sol = (sol - 1) % 360;

		satelite = (satelite - 30) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	SOL += 0.25;
	MERCURIO += 0.03;
	VENUS += 0.02;
	TIERRA += 0.01;
	MARTE += 0.009;
	JUPITER += 0.008;
	SATURNO += 0.007;
	URANO += 0.006;
	NEPTUNO += 0.005;

	LUNA01 += 0.5;
	LUNA02 += 0.35;
	LUNA03 += 0.25;

	EJE += 0.20;
	
	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 5000.0);
	
	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ += 10.0f;
			break;
		case 's':
		case 'S':
			camaraZ -= 10.0f;
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


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}