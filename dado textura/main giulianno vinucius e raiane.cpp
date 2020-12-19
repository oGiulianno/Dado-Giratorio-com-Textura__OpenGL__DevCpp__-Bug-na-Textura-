/***************************************

dado
dado.cpp

Prof: Gustavo Vinhal

Alunos: GIULIANNO G LATORRACA
		VINICIUS HENRIQUE DA SILVA SOUZA
		RAIANE PEREIRA ALCANTARA

****************************************/


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>


GLfloat angle, fAspect;
GLdouble obsX, obsY, obsZ;

GLuint idTextura;

float xrot;
float yrot;
float zrot;
float ratio;

void loadBMP(char *filename) {

	unsigned int width, height;
	unsigned char header[54];

	unsigned char * data;

	FILE * file;
	file = fopen(filename, "rb");

	if (file == NULL)
		return;

	
	if (fread(header, 1, 54, file) != 54) {
		printf("erro ao ler arquivo\n");
		return;
	}
	width = *(int*) &(header[0x12]);
	height = *(int*) &(header[0x16]);

	data = (unsigned char *) malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i) {
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;
	}

	glGenTextures(1, &idTextura);
	glBindTexture(GL_TEXTURE_2D, idTextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
	GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);
}


void display(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsX, obsY, obsZ, 0, 0, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glTranslatef(0,0,-1);
		glRotatef(1, 0, 1, 0);
		glRotatef ( xrot, 1.0, 0.0, 0.0 );
		glRotatef ( yrot, 0.0, 1.0, 0.0 );
		glRotatef ( zrot, 0.0, 0.0, 1.0 );
		

	
	glBegin( GL_QUADS);
	

	
	// Face frontal 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.5f, -0.3f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, -0.3f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	
	 //Face posterior
	 glTexCoord2f(0.0f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, -1.0f);
	 glTexCoord2f(0.5f, 0.0f);
	 glVertex3f(-1.0f, 1.0f, -1.0f);
	 glTexCoord2f(0.5f, -0.3f);
   	 glVertex3f(1.0f, 1.0f, -1.0f);
	 glTexCoord2f(0.0f, -0.3f);
	 glVertex3f(1.0f, -1.0f, -1.0f);
	 
	// Face superior
	 glTexCoord2f(0.0f, 1.0f);
	 glVertex3f(-1.0f, 1.0f, -1.0f);
	 glTexCoord2f(0.0f, 0.0f);
	 glVertex3f(-1.0f, 1.0f, 1.0f);
	 glTexCoord2f(1.0f, 0.0f);
	 glVertex3f(1.0f, 1.0f, 1.0f);
	 glTexCoord2f(1.0f, 1.0f);
	 glVertex3f(1.0f, 1.0f, -1.0f);
	// Face inferior
	 glTexCoord2f(1.0f, 1.0f);
	 glVertex3f(-1.0f, -1.0f, -1.0f);
	 glTexCoord2f(0.0f, 1.0f);
	 glVertex3f(1.0f, -1.0f, -1.0f);
	 glTexCoord2f(0.0f, 0.0f);
	 glVertex3f(1.0f, -1.0f, 1.0f);
	 glTexCoord2f(1.0f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, 1.0f);
	// Face lateral direita
	 glTexCoord2f(1.0f, 0.0f);
	 glVertex3f(1.0f, -1.0f, -1.0f);
	 glTexCoord2f(1.0f, 1.0f);
	 glVertex3f(1.0f, 1.0f, -1.0f);
	 glTexCoord2f(0.0f, 1.0f);
	 glVertex3f(1.0f, 1.0f, 1.0f);
	 glTexCoord2f(0.0f, 0.0f);
	 glVertex3f(1.0f, -1.0f, 1.0f);
	// Face lateral esquerda
	 glTexCoord2f(0.0f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, -1.0f);
	 glTexCoord2f(1.0f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, 1.0f);
	 glTexCoord2f(1.0f, 1.0f);
	 glVertex3f(-1.0f, 1.0f, 1.0f);
	 glTexCoord2f(0.0f, 1.0f);
	 glVertex3f(-1.0f, 1.0f, -1.0f);
	 
	glEnd();
	
	xrot+=0.10f;
	yrot+=0.101f;
	zrot+=0.102f;
	glRotatef(1, 0, 1, 0);
	
	glutSwapBuffers();
	

}
/*
void DrawCube(GLfloat alfa)
{

	glBegin ( GL_QUADS );
		// Front Face
		//glColor4f(0.7f,0.7f,0, alfa);
		glVertex3f(-1.0f, -1.0f,  1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		//glColor4f(0,0,0.7f, alfa);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f,  1.0f, -1.0f);
		glVertex3f( 1.0f,  1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		//glColor4f(0.7f,0,0.7f, alfa);
		glVertex3f(-1.0f,  1.0f, -1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		//glColor4f(0.7f,0.7f,0.7f, alfa);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		// Right face
		//glColor4f(0,0.5f,0, alfa);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f,  1.0f, -1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		//glColor4f(0.7f,0,0, alfa);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f, -1.0f);
		//loadBMP("dado.bmp");
	glEnd();
}

void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	// Desabilita o BLEND par ao primeiro objeto
	glDisable(GL_BLEND);
	glPushMatrix();
		glTranslatef(0,0,-1);
		glRotatef ( xrot, 1.0, 0.0, 0.0 );
		glRotatef ( yrot, 0.0, 1.0, 0.0 );
		glRotatef ( zrot, 0.0, 0.0, 1.0 );

		// habilita remoção de faces traseiras
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		DrawCube(0.5);	
			
	glPopMatrix();
	
	// Habilita o BLEND para ao segundo objeto
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	
	// NovaCorNaTela = CorDoObjeto * AlfaDoObjeto + CorAntigaNaTele * (1-AlfaDoObjeto)

	glPushMatrix();
		glTranslatef(0,0,0);
		//DesenhaVidro(AlfaVidro);
	glPopMatrix();

	xrot+=0.10f;
	yrot+=0.101f;
	zrot+=0.102f;
	
	glutSwapBuffers();
	
}*/

void init(void) {
	GLfloat luzAmbiente[4] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat posicaoLuz[4] = { 0.0, -40.0, 0.0, 1.0 };

	GLfloat especularidade[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLint especMaterial = 60;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	angle = 20;
	obsX = 10;
	obsY = 10;
	obsZ = 10;
	
	glRotatef(1, 0, 1, 0);

	loadBMP("dado.bmp");
}

void configProjection(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, fAspect, 0.4, 500);
}

void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	fAspect = (GLfloat) w / (GLfloat) h;
	configProjection();
}


/*
void keyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		obsX -= 1;
		break;
	case GLUT_KEY_RIGHT:
		obsX += 1;
		break;
	case GLUT_KEY_UP:
		obsY += 1;
		break;
	case GLUT_KEY_DOWN:
		obsY -= 1;
		break;
	case GLUT_KEY_HOME:
		obsZ += 1;
		break;
	case GLUT_KEY_END:
		obsZ -= 1;
		break;
	case GLUT_KEY_F10: //resetar
		obsX = 10;
		obsY = 10;
		obsZ = 10;
		angle = 18;
		configProjection();
		break;
	}
	glutPostRedisplay();
}*/

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 350);
	glutCreateWindow("dado");
	
	glutDisplayFunc ( display );
	glutReshapeFunc(resize);
	glutIdleFunc ( display );
	//glutSpecialFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
