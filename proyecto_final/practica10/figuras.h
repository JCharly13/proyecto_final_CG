//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text1,GLuint text2,GLuint text3, GLuint text4, GLuint text5);
	void prisma3(GLuint text, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5);
	void prisma4(GLuint text, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5);
	void prisma5(GLuint text, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5);
	void trapecio(GLuint text, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5);
	void plano(GLuint text);
	void banqueta(GLuint text, GLuint text1, GLuint text2, GLuint text3, GLuint text4, GLuint text5);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);


};
