#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define Pi 3.14
int win_id;

//Aqui se capturam as teclas comuns (letras, números e ESC, por exemplo)
void myKeyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 'R':
    case 'r':// muda a cor corrente para vermelho
      glColor3f(1.0f, 0.0f, 0.0f);
      break;
    case 'G':
    case 'g':// muda a cor corrente para verde
      glColor3f(0.0f, 1.0f, 0.0f);
      break;
    case 'B':
    case 'b':// muda a cor corrente para azul
      glColor3f(0.0f, 0.0f, 1.0f);
      break;
    //case 27:
    //  glutDestroyWindow(win_id);
    //  exit(0);
    //  break;
  }
  glutPostRedisplay();
}

//Aqui se capturam as teclas especiais (Alt, Control, Shift, F1, F2, etc.)
void myKeyboardSpecial(int key, int x, int y ) {
  switch ( key ) {
    case GLUT_KEY_UP:                   // Quando a seta para cima é teclada...
      glutFullScreen ( );               // Vá para o modo tela cheia...
      break;
    case GLUT_KEY_DOWN:                 // Quando a seta para baixo for teclada...
      glutReshapeWindow ( 640, 480 );   // Vá para modo em janela de 640 por 480
      break;
    default:
      printf("Você apertou a tecla especial código: %d\n", key);  // ...para ajudar você a debugar...
      break;
  }
}

// Função callback chamada para gerenciar eventos do mouse
void myMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {
      float r, g, b;
      r = (double)rand() / (double)RAND_MAX;
      g = (double)rand() / (double)RAND_MAX;
      b = (double)rand() / (double)RAND_MAX;
      glColor3f(r,g,b);
      printf("%.2f, %.2f, %.2f\n", r, g, b);
    }
  glutPostRedisplay();
}

void DrawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC){
	float tStep = (Pi) / (float)uiSlices;
	float sStep = (Pi) / (float)uiStacks;

	//Essa linha desenha em modo wireframe, caso queiram ver os polígonos criados pela função
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for(float t = -Pi/2; t <= (Pi/2)+.0001; t += tStep)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for(float s = -Pi; s <= Pi+.0001; s += sStep)
		{
			glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
			glVertex3f(fA * cos(t+tStep) * cos(s), fB * cos(t+tStep) * sin(s), fC * sin(t+tStep));
		}
		glEnd();
	}
}


void init(void)
{
  // Define a cor de fundo da janela de visualização como preto
  glClearColor (0.0, 0.0, 0.0, 0.0);
  // Define o modo de rastreio de cor utilizado para misturar a cor do material nos pontos da face (smoothing)
  glShadeModel (GL_SMOOTH);
  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);

  //Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 10.0, 10.0, 30.0, 0.0 };

  // Passa os parâmetros definidos acima para a OpenGL
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  // Habilita a luz ambiente, a luz zero e o depth buffer
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  //Primeira cor, para depois mudarmos com os eventos
  glColor3f(0.5, 1.0, 0.5);
};
void chao(void){
  glColor3f(0.82,0.81,0.59);
  glPushMatrix();
  glRotatef(130,0,1,0);
  glScalef(250,30,1000);
  glTranslatef(0,-0.4,0);
  glutSolidCube(1);
  glPopMatrix();
}

void ceu(void){
  glColor3f(0,1,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(200,100,15);
  glTranslatef(0,0,-1);
  glutSolidCube(1);
  glPopMatrix();
}

void folhasabacaxi(void){

//folhas abacaxi
  glColor3f(0.20,0.43,0.011);
  glPushMatrix();
  glTranslatef(0,22,0);
  glScalef(1,20,1);
  glutSolidSphere(1,15,4);
  //DrawEllipsoid(20,10,1,1,1);
  glPopMatrix();

  glColor3f(0.20,0.43,0.011);
  glPushMatrix();
  glTranslatef(1,22,0);
  glRotatef(135,0,0,1);
  glScalef(1,8,1);
  glutSolidSphere(1,15,4);
  //DrawEllipsoid(20,10,1,1,1);
  glPopMatrix();

  glColor3f(0.20,0.43,0.011);
  glPushMatrix();
  glTranslatef(-1,22,0);
  glRotatef(45,0,0,1);
  glScalef(1,8,1);
  glutSolidSphere(1,15,4);
  //DrawEllipsoid(20,10,1,1,1);
  glPopMatrix();

}

void baseabacaxi(void){
 //base abacaxi
  glColor3f(0.97,0.70,0.058);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,2,2);
  glTranslatef(0,2,3);
  glutSolidSphere(10,35,20);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();
}

void janelas(void){
  glColor3f(0.40,0.70,0.84);
  glPushMatrix();
  glScalef(1.2,1.2,1.2);
  //glRotatef(45,0,1,0);
  glTranslatef(5,9,15);
  glutSolidSphere(2,35,20);
  glPopMatrix();

  glColor3f(0.40,0.70,0.84);
  glPushMatrix();
  glScalef(1.2,1.2,1.2);
  //glRotatef(45,0,1,0);
  glTranslatef(-4,14,13);
  glutSolidSphere(2,35,20);
  glPopMatrix();

}

void chamine(void){

  glColor3f(0.58,0.61,0.63);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,3,2);
  glTranslatef(10,8,3);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0.58,0.61,0.63);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(3,1,2);
  glTranslatef(2,22,3);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();
}

void porta(void){

  glColor3f(0.58,0.61,0.63);
  glPushMatrix();
  glScalef(2,7,1.2);
  //glRotatef(45,0,1,0);
  glTranslatef(0.4,0.2,21);
  glutSolidSphere(2,35,20);
  glPopMatrix();

  glColor3f(0.79,0.80,0.80);
  glPushMatrix();
  glScalef(1.8,6.5,1.2);
  //glRotatef(45,0,1,0);
  glTranslatef(0.4,0.2,22);
  glutSolidSphere(2,35,20);
  glPopMatrix();

}

void casa(void){

  // Desenha a casa do bobesponja
  baseabacaxi();
  folhasabacaxi();
  janelas();
  chamine();
  porta();
}

void corpobob(void){


  glColor3f(1,1,0.14);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,1,1);
  glTranslatef(15,12,50);
  glutSolidCube(5);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();


}

void pernasbob(void){


  glColor3f(1,1,0.14);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,5,1);
  glTranslatef(14,1.4,50);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(1,1,0.14);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,5,1);
  glTranslatef(16,1.4,50);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(1,1,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,3.5,1);
  glTranslatef(16,1.8,51);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(1,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,0.4,1);
  glTranslatef(16,17,51.2);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,0.4,1);
  glTranslatef(16,19,51.2);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();


  glColor3f(1,1,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,3.5,1);
  glTranslatef(14,1.8,51);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(1,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,0.4,1);
  glTranslatef(14,17,51.2);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,0.4,1);
  glTranslatef(14,19,51.2);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

}

void pesbob(void){
  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,0.8,1);
  glTranslatef(14,5,51.2);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,1.4,1);
  glTranslatef(13.2,3,51.6);
  glutSolidSphere(0.5,20,10);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,0.8,1);
  glTranslatef(16,5,51.2);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(1,1.4,1);
  glTranslatef(16.7,3,51.6);
  glutSolidSphere(0.5,20,10);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

}

void calcabob(void){

  glColor3f(0.49,0.34,0.039);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(2.5,0.7,1);
  glTranslatef(6,16.4,55);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();


  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.6,0.02,1);
  glTranslatef(27.6,645,60);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.6,0.02,1);
  glTranslatef(22.6,645,60);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.6,0.02,1);
  glTranslatef(25.1,645,60);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

}

void blusabob(void){
  //blusa
  glColor3f(1,1,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(2.5,0.3,1);
  glTranslatef(6,40,55);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

  //gravata
  glColor3f(1,0,0);
  glPushMatrix();
  //glRotatef(90,0,0,1);
  glScalef(0.6,1,1);
  glTranslatef(25.1,13.5,59);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();

}

void rostobob(void){
  //olho esquerdo
  glColor3f(1,1,1);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(14,13.6,52);
  glutSolidSphere(0.8,35,20);
  glPopMatrix();
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(14,16.5,60);
  glutSolidSphere(0.2,35,20);
  glPopMatrix();

  //olho direito
  glColor3f(1,1,1);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(16,13.6,52);
  glutSolidSphere(0.8,35,20);
  glPopMatrix();
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(16,16.5,60);
  glutSolidSphere(0.2,35,20);
  glPopMatrix();

  //nariz
  glColor3f(1,1,0.20);
  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(30,27.5,110);
  glutSolidSphere(0.8,35,20);
  glPopMatrix();

  //dentes
  glColor3f(1,1,1);
  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(31,27,113);
  glutSolidCube(1);
  glPopMatrix();
  glColor3f(1,1,1);
  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(29,27,113);
  glutSolidCube(1);
  glPopMatrix();


  //sobrancelhas
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(0.5,0.7,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(28,23,113);
  glutSolidCube(0.5);
  glPopMatrix();
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(0.5,0.7,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(27,23,113);
  glutSolidCube(0.5);
  glPopMatrix();
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(0.5,0.7,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(29,23,113);
  glutSolidCube(0.5);
  glPopMatrix();

  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(0.5,0.7,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(31,23,113);
  glutSolidCube(0.5);
  glPopMatrix();
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(0.5,0.7,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(32,23,113);
  glutSolidCube(0.5);
  glPopMatrix();
  glColor3f(0,0,0);
  glPushMatrix();
  glScalef(0.5,0.7,0.5);
  //glRotatef(45,0,1,0);
  glTranslatef(33,23,113);
  glutSolidCube(0.5);
  glPopMatrix();



}

void bracosbob(void){

  //esquerdo
  glColor3f(1,1,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.4,0.4,0.4);
  glTranslatef(30.2,10,85);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();
  glColor3f(1,1,0.14);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.7,3,1);
  glTranslatef(25.7,1.5,40);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();



  //direito
  glColor3f(1,1,1);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.4,0.4,0.4);
  glTranslatef(44.8,10,85);
  glutSolidCube(2);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();
  glPopMatrix();
  glColor3f(1,1,0.14);
  glPushMatrix();
  glRotatef(0,0,1,0);
  glScalef(0.7,3,1);
  glTranslatef(17.3,1.5,40);
  glutSolidCube(1);
  //DrawEllipsoid(8,100,1,1,1);
  glPopMatrix();


}

void bob(void){
  corpobob();
  pernasbob();
  pesbob();
  calcabob();
  blusabob();
  rostobob();
  bracosbob();
}

void corpoplankton(void){

  glColor3f(0.25,0.45,0.05);
  glPushMatrix();
  glScalef(1,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-15,3,15);
  glutSolidSphere(0.8,35,20);
  glPopMatrix();
}

void rostoplankton(void){
  glColor3f(0.16,0.31,0.027);
  glPushMatrix();
  glScalef(0.6,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-24.5,4,15);
  glutSolidCube(0.4);
  glPopMatrix();

  glColor3f(0.16,0.31,0.027);
  glPushMatrix();
  glScalef(0.6,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-25.5,4,15);
  glutSolidCube(0.4);
  glPopMatrix();

  glColor3f(0.84,0.89,0.56);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-15,21,52);
  glutSolidSphere(0.6,35,20);
  glPopMatrix();

  glColor3f(1,0,0);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-15,24.3,60);
  glutSolidSphere(0.3,35,20);
  glPopMatrix();



}

void pernasplankton(void){
  glColor3f(0.25,0.45,0.05);
  glPushMatrix();
  glScalef(0.6,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-24.5,2.2,15);
  glutSolidCube(0.3);
  glPopMatrix();

  glColor3f(0.25,0.45,0.05);
  glPushMatrix();
  glScalef(0.6,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-25.5,2.2,15);
  glutSolidCube(0.3);
  glPopMatrix();

}

void bracosplankton(void){
  glColor3f(0.25,0.45,0.05);
  glPushMatrix();
  glScalef(0.4,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-35,3,15);
  glutSolidCube(0.6);
  glPopMatrix();


  glColor3f(0.25,0.45,0.05);
  glPushMatrix();
  glScalef(0.4,2,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-40,3,15);
  glutSolidCube(0.6);
  glPopMatrix();
}

void plankton(void){
  corpoplankton();
  pernasplankton();
  rostoplankton();
  bracosplankton();
}

void mesa(void){

  glColor3f(0.38,0.28,0.03);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-15,2,40);
  glutSolidCube(6);
  glPopMatrix();

  glColor3f(0.38,0.28,0.03);
  glPushMatrix();
  glScalef(1,4,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-25,2,40);
  glutSolidCube(1);
  glPopMatrix();

  glColor3f(0.38,0.28,0.03);
  glPushMatrix();
  glScalef(1,4,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-35,2,40);
  glutSolidCube(1);
  glPopMatrix();

  glColor3f(1,1,1);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-15,14,40);
  glutSolidCube(6);
  glPopMatrix();

}

void caminho(void){
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,33);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,39);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,45);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,51);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,57);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,63);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,69);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(2,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(0.5,0.5,75);
  glutSolidCube(6);
  glPopMatrix();
  glColor3f(0.36,0.36,0.36);
  glPushMatrix();
  glScalef(30,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-4,0.00001,90);
  glutSolidCube(12);
  glPopMatrix();
}

void plantas(void){
  glColor3f(0.38,0.48,0.11);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-10,5,25);
  glutSolidSphere(2,20,10);
  glPopMatrix();
  glColor3f(0.38,0.48,0.11);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-8,5,25);
  glutSolidCube(3);
  glPopMatrix();
  glColor3f(0.38,0.48,0.11);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(-5,5,28);
  glutSolidCube(1);
  glPopMatrix();

   glColor3f(0.38,0.48,0.11);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(10,5,25);
  glutSolidCube(2);
  glPopMatrix();
  glColor3f(0.38,0.48,0.11);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(8,5,25);
  glutSolidSphere(2,40,10);
  glPopMatrix();
  glColor3f(0.38,0.48,0.11);
  glPushMatrix();
  glScalef(1,1,1);
  //glRotatef(45,0,1,0);
  glTranslatef(5,5,28);
  glutSolidCube(1);
  glPopMatrix();
}

void ambiente(void){
  ceu();
  chao();
  casa();
  mesa();
  caminho();
  plantas();
}
void display(void)
{
  // Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Entra no modo de definição de matriz de visualização
  glMatrixMode(GL_MODELVIEW);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a posição da câmera, para onde ela aponta e qual o vetor UP
  gluLookAt(0.0f, 8.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);



  // Desenha a casa
  glScalef(1,1,1);
  ambiente();
  bob();
  plankton();

  // Executa os comandos OpenGL, e depois troca os buffers de vídeo
  glFlush();
}

void reshape (int w, int h)
{
  // Define o viewport como o tamanho da janela
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  // Entra no modo de definição de matriz de projeção
  glMatrixMode (GL_PROJECTION);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a projeção ortogonal
  if (w <= h)
    // Se a largura for menor que a altura, a projeção é feita para manter a proporção da janela
    glOrtho (-50, 50, -50*(GLfloat)h/(GLfloat)w, 50*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
  else
    // Se a altura for menor que a largura, a projeção é feita para manter a proporção da janela
    glOrtho (-50*(GLfloat)w/(GLfloat)h, 50*(GLfloat)w/(GLfloat)h, -50, 50, -100.0, 100.0);

}

int main(int argc, char** argv)
{
  // Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas
  glutInit(&argc, argv);
  // Inicializa o display, indicando que usará:
  // - um buffer de imagem (single buffer);
  // - buffer de profundidade;
  // - padrão de cores RGB)
  glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  // Especifica as dimensões da janela de exibição
  glutInitWindowSize (500, 500);
  // Especifica a posição inicial da janela de exibição
  glutInitWindowPosition (100, 100);
  // Cria a janela de exibição
  win_id = glutCreateWindow ("Bob Esponja - Juan Aleixo");
  // Chama a função init
  init ();
  // Estabelece a função "display" como a função callback de exibição.
  glutDisplayFunc(display);
  // Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
  glutReshapeFunc(reshape);
  // Estabelece a função "keyboard" como a função callback de evento de teclado.
  glutKeyboardFunc(myKeyboard);
  // Estabelece a função "keyboardSpecial" como a função callback de evento de teclado especial.
  glutSpecialFunc(myKeyboardSpecial);
  // Estabelece a função "mouse" como a função callback de evento de mouse.
  glutMouseFunc(myMouse);
  // Entra no loop de eventos, não retorna
  glutMainLoop();
  return 0;
}
