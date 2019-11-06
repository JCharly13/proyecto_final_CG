
#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture text1;
CTexture text2;
CTexture text3;	
CTexture text4;	
CTexture text5;	
CTexture text6;	
CTexture text7;	
CTexture text8;
CTexture text9;
CTexture text10;
CTexture text11;
CTexture text12;
CTexture text13;
CTexture text14;
CTexture text15;
CTexture text16;
CTexture text17;
CTexture text18;
CTexture text19;
CTexture text20;
CTexture text21;
CTexture text22;
CTexture text23;
CTexture text24;
CTexture text25;
CTexture text26;
CTexture text27;
CTexture text28;
CTexture text29;
CTexture text30;
CTexture text31;
CTexture text32;
CTexture text33;
CTexture text34;


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;

//Animación del coche
float movbola1 = -7.4;
float movbola2z = -10.1;
float movbola3z = -12.16;
float movbola2x = -3.85;
float movbola3x = -3.5;
float movdardo = 1.0;
float rotartarro = 0.0;
bool flag = false;
bool g_fanimacion = false;
bool g_fanimacion2 = false;
bool g_fanimacion3 = false;
bool g_fanimacion4 = false;

bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;

bool recorrido4 = true;
bool recorrido5 = false;
bool recorrido6 = false;

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("moesbar_right.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("orilla.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("carretera.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("banqueta.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("moesbar_front.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	text7.LoadTGA("techo.tga");
	text7.BuildGLTexture();
	text7.ReleaseImage();

	text8.LoadTGA("o20.tga");
	text8.BuildGLTexture();
	text8.ReleaseImage();

	text9.LoadTGA("moesbar_inside.tga");
	text9.BuildGLTexture();
	text9.ReleaseImage();

	text10.LoadTGA("moesbar_right_inside.tga");
	text10.BuildGLTexture();
	text10.ReleaseImage();

	text11.LoadTGA("moesbar_inside2.tga");
	text11.BuildGLTexture();
	text11.ReleaseImage();

	text12.LoadTGA("piso.tga");
	text12.BuildGLTexture();
	text12.ReleaseImage();

	text13.LoadTGA("techo1.tga");
	text13.BuildGLTexture();
	text13.ReleaseImage();

	text14.LoadTGA("moesbar_left_inside.tga");
	text14.BuildGLTexture();
	text14.ReleaseImage();

	text15.LoadTGA("tablitas.tga");
	text15.BuildGLTexture();
	text15.ReleaseImage();

	text16.LoadTGA("barra.tga");
	text16.BuildGLTexture();
	text16.ReleaseImage();

	text17.LoadTGA("barra1.tga");
	text17.BuildGLTexture();
	text17.ReleaseImage();

	text18.LoadTGA("barra3.tga");
	text18.BuildGLTexture();
	text18.ReleaseImage();

	text19.LoadTGA("barra4.tga");
	text19.BuildGLTexture();
	text19.ReleaseImage();

	text20.LoadTGA("barra5.tga");
	text20.BuildGLTexture();
	text20.ReleaseImage();

	text21.LoadTGA("barra6.tga");
	text21.BuildGLTexture();
	text21.ReleaseImage();

	text22.LoadTGA("barra6-1.tga");
	text22.BuildGLTexture();
	text22.ReleaseImage();

	text23.LoadTGA("barra6-2.tga");
	text23.BuildGLTexture();
	text23.ReleaseImage();

	text24.LoadTGA("sillon.tga");
	text24.BuildGLTexture();
	text24.ReleaseImage();

	text25.LoadTGA("tubo.tga");
	text25.BuildGLTexture();
	text25.ReleaseImage();

	text26.LoadTGA("tomdaly.tga");
	text26.BuildGLTexture();
	text26.ReleaseImage();

	text27.LoadTGA("tele.tga");
	text27.BuildGLTexture();
	text27.ReleaseImage();

	text28.LoadTGA("tablero1.tga");
	text28.BuildGLTexture();
	text28.ReleaseImage();

	text29.LoadTGA("tablero2.tga");
	text29.BuildGLTexture();
	text29.ReleaseImage();

	text30.LoadTGA("paño.tga");
	text30.BuildGLTexture();
	text30.ReleaseImage();

	text31.LoadTGA("lampara.tga");
	text31.BuildGLTexture();
	text31.ReleaseImage();

	text32.LoadTGA("lampara1.tga");
	text32.BuildGLTexture();
	text32.ReleaseImage();

	text33.LoadTGA("lampara2.tga");
	text33.BuildGLTexture();
	text33.ReleaseImage();

	text34.LoadTGA("cadena.tga");
	text34.BuildGLTexture();
	text34.ReleaseImage();


	//Carga de Figuras
	kit._3dsLoad("kitt.3ds");	
	//kit.VertexNormals();
	
	llanta._3dsLoad("k_rueda.3ds");


	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

	

		glPushMatrix();		

			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//Para que el comando glColor funcione con iluminacion
			glEnable(GL_COLOR_MATERIAL);
			

			glPushMatrix(); //Carrertera
			glTranslatef(0.0, 0.0, 0.0);
			glScalef(60, 0.1, 7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, text4.GLindex, text4.GLindex, text4.GLindex, text4.GLindex, text4.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //banqueta
				glTranslatef(0.0,0.0,-4.5);
				glRotatef(180, 0.0, 0.0, 1.0);
				glScalef(60.0,0.3,2.0);
				glDisable(GL_LIGHTING);
				fig4.banqueta(0, 0, 0, 0, text5.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //banqueta2
			glTranslatef(0.0, 0.0, -3.5);
			glRotatef(180, 0.0, 0.0, 1.0);
			glScalef(60.0, 0.5, 0.2);
			glDisable(GL_LIGHTING);
			fig4.banqueta(text3.GLindex, text3.GLindex, text3.GLindex, text3.GLindex, text3.GLindex, 0);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //bar
				glTranslatef(0.0,4.5,-12.0);
				glScalef(14.0,9.0,13.0);
				glDisable(GL_LIGHTING);
				fig5.prisma2(text6.GLindex, 0, text2.GLindex, text2.GLindex,0,0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //bar-inside
			glTranslatef(0.0, 4.5, -12.0);
			glScalef(13.8, 8.8, 12.8);
			glDisable(GL_LIGHTING);
			fig5.prisma3(text9.GLindex, text11.GLindex, text10.GLindex, text14.GLindex, text12.GLindex, text13.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //techo-bar
			glTranslatef(0.0, 9.15, -12.0);
			glScalef(14.1, 0.4, 13.1);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text8.GLindex, text8.GLindex, text8.GLindex, text8.GLindex, text8.GLindex, text7.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //barra
				glTranslatef(2.7, 1.2, -12.0);
				glScalef(1.5, 2.3, 8.0);
				glPushMatrix();
					glTranslatef(1.23, 0.0, 0.39);
					glScalef(1.5, 1.0, 0.22);
					glPushMatrix();
						glTranslatef(0.0, 0.0, -3.55);
						glScalef(1.0, 1.0, 1.0);
						glDisable(GL_LIGHTING);
						fig5.prisma4(text17.GLindex, text17.GLindex, text19.GLindex, text17.GLindex, text19.GLindex, text19.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glDisable(GL_LIGHTING);
					fig5.prisma4(text17.GLindex, text17.GLindex, text19.GLindex, text17.GLindex, text19.GLindex, text19.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glDisable(GL_LIGHTING);
				fig5.prisma5(text17.GLindex, text18.GLindex, text16.GLindex, text19.GLindex, text19.GLindex, text19.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //barra1
				glTranslatef(2.7, 2.4, -12.0);
				glScalef(1.6, 0.1, 8.1);
				glPushMatrix();
					glTranslatef(1.23, 0.0, 0.39);
					glScalef(1.5, 1.0, 0.22);
					glPushMatrix();
						glTranslatef(0.0, 0.0, -3.55);
						glScalef(1.0, 1.0, 1.0);
						glDisable(GL_LIGHTING);
						fig5.prisma4(text23.GLindex, text21.GLindex, text21.GLindex, text21.GLindex, text21.GLindex, text20.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glDisable(GL_LIGHTING);
					fig5.prisma4(text23.GLindex, text21.GLindex, text21.GLindex, text21.GLindex, text21.GLindex, text20.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glDisable(GL_LIGHTING);
				fig5.prisma4(text22.GLindex, text22.GLindex, text20.GLindex, text21.GLindex, text21.GLindex, text21.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //barra2
				glTranslatef(2.7, 2.52, -12.0);
				glScalef(1.7, 0.15, 8.2);
				glPushMatrix();
					glTranslatef(1.23, 0.0, 0.39);
					glScalef(1.5, 1.0, 0.22);
				glPushMatrix();
						glTranslatef(0.0, 0.0, -3.55);
						glScalef(1.0, 1.0, 1.0);
						glDisable(GL_LIGHTING);
						fig5.prisma4(text17.GLindex, text17.GLindex, text19.GLindex, text17.GLindex, text19.GLindex, text19.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
							glDisable(GL_LIGHTING);
							fig5.prisma4(text17.GLindex, text17.GLindex, text19.GLindex, text17.GLindex, text19.GLindex, text19.GLindex);
							glEnable(GL_LIGHTING);
					glPopMatrix();
				glDisable(GL_LIGHTING);
				fig5.prisma5(text17.GLindex, text18.GLindex, text19.GLindex, text19.GLindex, text19.GLindex, text19.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //banco1
					glTranslatef(1.0, 1.3, -9.0);
					glScalef(1.0, 0.3, 1.0);
					glPushMatrix();
						glTranslatef(0.36, -4.2, 0.23);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata1
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.36, -4.2, -0.23);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata2
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-0.36, -4.2, 0.23);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata3
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-0.36, -4.2, -0.23);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata4
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0, -4.2, 0.42);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata5
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0.0, -4.2, -0.42);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata6
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, -1.0, 0.0);
						glScalef(1.0, 3.0, 1.0);
						glDisable(GL_LIGHTING);
						fig5.torus(0.55, 0.4, 16, 8);	//aro1
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.0, -3.0, 0.0);
						glScalef(1.0, 3.0, 1.0);
						glDisable(GL_LIGHTING);
						fig5.torus(0.55, 0.4, 16, 8);	//aro2
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glDisable(GL_LIGHTING);
					fig2.cilindro(0.55, 1.1, 16, text24.GLindex);	//Funcíon creacion cilindro
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //banco2
				glTranslatef(1.0, 1.3, -11.0);
				glScalef(1.0, 0.3, 1.0);
				glPushMatrix();
				glTranslatef(0.36, -4.2, 0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata1
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.36, -4.2, -0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata2
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-0.36, -4.2, 0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata3
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-0.36, -4.2, -0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata4
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.0, -4.2, 0.42);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata5
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.0, -4.2, -0.42);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata6
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -1.0, 0.0);
				glScalef(1.0, 3.0, 1.0);
				glDisable(GL_LIGHTING);
				fig5.torus(0.55, 0.4, 16, 8);	//aro1
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -3.0, 0.0);
				glScalef(1.0, 3.0, 1.0);
				glDisable(GL_LIGHTING);
				fig5.torus(0.55, 0.4, 16, 8);	//aro2
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glDisable(GL_LIGHTING);
				fig2.cilindro(0.55, 1.1, 16, text24.GLindex);	//Funcíon creacion cilindro
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //banco3
				glTranslatef(1.0, 1.3, -13.0);
				glScalef(1.0, 0.3, 1.0);
				glPushMatrix();
				glTranslatef(0.36, -4.2, 0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata1
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.36, -4.2, -0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata2
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-0.36, -4.2, 0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata3
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-0.36, -4.2, -0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata4
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.0, -4.2, 0.42);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata5
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.0, -4.2, -0.42);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata6
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -1.0, 0.0);
				glScalef(1.0, 3.0, 1.0);
				glDisable(GL_LIGHTING);
				fig5.torus(0.55, 0.4, 16, 8);	//aro1
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -3.0, 0.0);
				glScalef(1.0, 3.0, 1.0);
				glDisable(GL_LIGHTING);
				fig5.torus(0.55, 0.4, 16, 8);	//aro2
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glDisable(GL_LIGHTING);
				fig2.cilindro(0.55, 1.1, 16, text24.GLindex);	//Funcíon creacion cilindro
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //banco4
				glTranslatef(1.0, 1.3, -15.0);
				glScalef(1.0, 0.3, 1.0);
				glPushMatrix();
				glTranslatef(0.36, -4.2, 0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata1
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.36, -4.2, -0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata2
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-0.36, -4.2, 0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata3
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-0.36, -4.2, -0.23);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata4
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.0, -4.2, 0.42);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata5
				glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.0, -4.2, -0.42);
				glDisable(GL_LIGHTING);
				fig2.cilindro(0.06, 5, 16, text25.GLindex);	//pata6
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -1.0, 0.0);
				glScalef(1.0, 3.0, 1.0);
				glDisable(GL_LIGHTING);
				fig5.torus(0.55, 0.4, 16, 8);	//aro1
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -3.0, 0.0);
				glScalef(1.0, 3.0, 1.0);
				glDisable(GL_LIGHTING);
				fig5.torus(0.55, 0.4, 16, 8);	//aro2
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glDisable(GL_LIGHTING);
				fig2.cilindro(0.55, 1.1, 16, text24.GLindex);	//Funcíon creacion cilindro
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //television
				glTranslatef(5.4, 7.0, -6.8);
				glRotatef(35, 0.0, -1.0, 1.0);
				glScalef(1.7, 1.5, 1.7);
				glDisable(GL_LIGHTING);
				fig3.prisma2(text27.GLindex, text27.GLindex, text26.GLindex, text27.GLindex, text27.GLindex, text27.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //tiro al blanco
				glTranslatef(6.8, 4.6, -6.8);
				glPushMatrix();
					glRotatef(90, 0.0, 0.0, 1.0);
					glScalef(1.7, 0.2, 1.7);
					glDisable(GL_LIGHTING);
					fig2.cilindro(0.55, 1.0, 16, text28.GLindex);	
					glEnable(GL_LIGHTING);
				glPopMatrix();
					glScalef(2.8, 2.8, 2.8);
					glEnable(GL_ALPHA_TEST);
					glTranslatef(0.42, 0.0, 0.0);
					glAlphaFunc(GL_GREATER, 0.1f);
					glDisable(GL_LIGHTING);
					fig2.plano(text29.GLindex);	
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();  //mesa-de-billar
				glTranslatef(-4.0, 1.3, -10.0);
				glPushMatrix();
					glScalef(3.0, 1.0, 6.0);
					glDisable(GL_LIGHTING);
					fig4.trapecio(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text30.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(3.0, 0.1, 0.2);      //banda1
					glTranslatef(0.0, 5.5, 14.7);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(3.0, 0.1, 0.2);        //banda2
					glTranslatef(0.0, 5.5, -14.7);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(0.2, 0.1, 5.7);        //banda3
					glTranslatef(7.0, 5.5, 0.0);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(0.2, 0.1, 5.7);      //banda4
					glTranslatef(-7.0, 5.5, 0.0);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(0.5, 0.8, 0.5);    //pata1
					glTranslatef(1.8, -1.0, 4.0);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(0.5, 0.8, 0.5);   //pata2
					glTranslatef(-1.8, -1.0, -4.0);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
					glScalef(0.5, 0.8, 0.5);     //pata3
					glTranslatef(1.8, -1.0, -4.0);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPushMatrix();
				glScalef(0.5, 0.8, 0.5);   //pata4
					glTranslatef(-1.8, -1.0, 4.0);
					glDisable(GL_LIGHTING);
					fig4.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
				glPopMatrix();

				glPushMatrix(); //lampara
					glTranslatef(-4.0, 5.5, -10.0);
					glPushMatrix();
						glRotatef(180, 1.0, 0.0, 0.0);
						glScalef(2.0, 1.0, 4.0);
						glDisable(GL_LIGHTING);
						fig4.trapecio(text31.GLindex, text31.GLindex, text31.GLindex, text31.GLindex, text33.GLindex, text32.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0, 0.5, 0.0);
						glRotatef(180, 1.0, 0.0, 0.0);
						glScalef(1.0, 0.4, 2.0);
						glDisable(GL_LIGHTING);
						fig4.trapecio(text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.7, 2.0, 1.5);   //cadena1
						glScalef(0.1, 3.5, 0.1);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-0.7, 2.0, 1.5);   //cadena2
						glScalef(0.1, 3.5, 0.1);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.7, 2.0, -1.5);   //cadena3
						glScalef(0.1, 3.5, 0.1);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-0.7, 2.0, -1.5);   //cadena4
						glScalef(0.1, 3.5, 0.1);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex, text25.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-6.9, 4.0, -7.1); //base tacos
					glPushMatrix();
						glScalef(0.1, 3.2, 2.2);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text20.GLindex, text20.GLindex, text20.GLindex, text20.GLindex, text20.GLindex, text20.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.2, 0.0, 1.0);
						glScalef(0.5, 3.2, 0.2);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.2, 0.0, -1.0);
						glScalef(0.5, 3.2, 0.2);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.2, 1.7, 0.0);
						glScalef(0.5, 0.2, 2.2);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.2, -1.7, 0.0);
						glScalef(0.5, 0.2, 2.2);
						glDisable(GL_LIGHTING);
						fig2.prisma2(text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex, text18.GLindex);
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.3, -1.5, 0.65);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 3, 16, text18.GLindex);	//taco1
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.3, -1.5, -0.65);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 3, 16, text18.GLindex);	//taco2
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.3, -1.5, -0.25);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 3, 16, text18.GLindex);	//taco3
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0.3, -1.5, 0.25);
						glDisable(GL_LIGHTING);
						fig2.cilindro(0.06, 3, 16, text18.GLindex);	//taco 4
						glEnable(GL_LIGHTING);
					glPopMatrix();

				glPopMatrix();

				glPushMatrix();       //dardo
					glTranslatef(movdardo, 4.5, -7.0);
					glRotatef(90, 0.0, 0.0, 1.0);
					glDisable(GL_LIGHTING);
					fig2.cilindro(0.05, 0.6, 16, text18.GLindex);	
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-4.0, 1.9, movbola1);
					if (movbola1 <= -10) {       //animacion simple 1
						g_fanimacion = false;
						circuito = true;
					}
					glDisable(GL_LIGHTING);
					fig2.esfera(0.09, 12, 12, text20.GLindex);	//bola
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(movbola2x, 1.9, movbola2z);
					glDisable(GL_LIGHTING);
					fig2.esfera(0.09, 12, 12, text24.GLindex);	//bola
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(movbola3x, 1.9, movbola3z);
					glDisable(GL_LIGHTING);
					fig2.esfera(0.09, 12, 12, text28.GLindex);	//bola
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(3.0, 2.6, -10.2);
					glRotatef(rotartarro, 0.0, 1.0, 0.0);
					if (rotartarro > 360) {
						g_fanimacion4 = false;
					}
					glPushMatrix();
					glScalef(0.5, 0.7, 0.5);
					glDisable(GL_LIGHTING);
					fig2.cilindro(0.5, 1.0, 16, text27.GLindex);
					glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0.0, 0.4, -0.3);
					glScalef(0.2, 0.4, 0.2);
					fig2.prisma2(text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex);
					glPopMatrix();
				glPopMatrix();



		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	if (g_fanimacion3) {  //animacion simple2
	
		if (movdardo < 6.6 && flag == false)
		{
			movdardo += 0.01;
			if (movdardo >= 6.6)
			{
				flag = true;
			}
		}
		else if (movdardo > 1)
		{
			movdardo -= 0.01;
		}

		else
		{
			movdardo -= 0.01;
			if (movdardo <= 1)
			{
				flag = false;
			}
		}
	}

	if(g_fanimacion)
	{
		movbola1 -=0.01;  //animacionsimple3
	}
	if (circuito) {  //maquina de estados uno
		if(recorrido1){
			movbola2x += 0.008;
			movbola2z -= 0.008;
			if (movbola2x > -2.8) {
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2) {
			movbola2x -= 0.0041;
			movbola2z -= 0.008;
			if (movbola2z < -12.2) {
				recorrido2 = false;
				recorrido3 = true;
				g_fanimacion2 = true;
			}
		
		}

		if (recorrido3) {
			movbola2x += 0.008;
			movbola2z -= 0.008;
			if (movbola2z < -12.7) {
				recorrido3 = false;
			}
		}
		
	}

	if (g_fanimacion2) {         //maquina 2
			if (recorrido4) {
				movbola3x -= 0.008;
				movbola3z -= 0.008;
				if (movbola3z < -12.75) {
					recorrido4 = false;
					recorrido5 = true;
				}
			}
			if (recorrido5) {
				movbola3x -= 0.004;
				movbola3z += 0.008;
				if (movbola3z > -10.5) {
					recorrido5 = false;
					recorrido6 = true;
				}
			}
			if (recorrido6) {
				movbola3x += 0.006;
				movbola3z += 0.008;
				if (movbola3z > -7.3) {
					recorrido6 = false;
				}
			}
	}

	if (g_fanimacion4) {
		rotartarro += 1;
	}

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'l': //Poner algo en movimiento
		case 'L':
			g_fanimacion3 ^= true; //Activamos/desactivamos la animacíon
			break;

		case 'i': //Poner algo en movimiento
		case 'I':
			g_fanimacion^= true; //Activamos/desactivamos la animacíon
			break;

		case 'j': //Poner algo en movimiento
		case 'J':
			g_fanimacion4 ^= true; //Activamos/desactivamos la animacíon
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
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
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
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto_final"); // Nombre de la Ventana
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
