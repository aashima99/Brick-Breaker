#include <stdlib.h>    
#include <GL/glut.h>
#include<stdio.h>
#include<string.h>
#include <math.h>


int ball_color = 3, level = 0, size = 1;;
GLfloat twoModel[] = { GL_TRUE };
int game_level[] = { 7,5,2 };
float rate = game_level[level];

GLfloat paddle_size[] = { 2,4,6 };
GLfloat brick_color_array[][3] = { {0,0.25,1} };
GLfloat paddle_color_array[][3] = { {1,1,0} };
GLfloat ball_color_array[][3] = { {1,0,1} };
GLfloat text_color_array[][4] = { {1,0,0} };

//The grid parameters for the bricks
int rows = 4;
int columns = 10;

// Structure to store the coordinates of each brick
struct brick_coords {

	GLfloat x;
	GLfloat y;
};

//Array to store the bricks
brick_coords brick_array[50][50];
GLfloat px, bx = 0, by = -12.8, speed = 0, dirx = 0, diry = 0, start = 0;



// Function to draw the paddle
void draw_paddle()
{
	glColor3fv(paddle_color_array[0]);
	glBegin(GL_POLYGON);
	glVertex3f(-paddle_size[size] + px, 0 - 15, 0);
	glVertex3f(paddle_size[size] + px, 0 - 15, 0);
	glVertex3f(paddle_size[size] + px, 1 - 15, 0);
	glVertex3f(-paddle_size[size] + px, 1 - 15, 0);
	glEnd();
}


//Function to draw a single brick
void brick(GLfloat x, GLfloat y, GLfloat z)
{
	glColor3fv(brick_color_array[0]);
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x + 3, y, z);
	glVertex3f(x + 3, y + 1, z);
	glVertex3f(x, y + 1, z);
	glEnd();
}


// Function to draw the grid of bricks
void draw_bricks()
{
	int i, j;
	if (start == 0)
	{
		for (i = 1; i <= rows; i++)
		{
			for (j = 1; j <= columns; j++)
			{

				brick_array[i][j].x = (GLfloat)(j * 4 * 0.84);
				brick_array[i][j].y = (GLfloat)(i * 2 * 0.6);
			}
		}
	}


	glPushMatrix();
	glTranslatef(-19.5, 5, 0);

	for (i = 1; i <= rows; i += 1)
	{
		for (j = 1; j <= columns; j += 1)
		{

			if (brick_array[i][j].x == 0 || brick_array[i][j].y == 0)
			{
				continue;
			}
			brick(brick_array[i][j].x, brick_array[i][j].y, 0);
		}
	}
	glPopMatrix();
}

//Function to draw the spherical ball
void draw_ball(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * 3.14;

	glColor3fv(ball_color_array[0]);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

}

//handle level
void change_difficulty(int action)
{
	level = action - 1;
}

//handle menu
void handle_menu(int action)
{

}

//handle paddle size
void change_paddle_size(int action)
{
	size = action - 1;
}

//add menu
void addMenu()
{

	int submenu1 = glutCreateMenu(change_difficulty);
	glutAddMenuEntry("Level-1", 1);
	glutAddMenuEntry("Level-2", 2);
	glutAddMenuEntry("Level-3", 3);

	int submenu2 = glutCreateMenu(change_paddle_size);
	glutAddMenuEntry("Small", 1);
	glutAddMenuEntry("Medium", 2);
	glutAddMenuEntry("Large", 3);

	glutCreateMenu(handle_menu);
	glutAddSubMenu("Difficulty", submenu1);
	glutAddSubMenu("Paddle Size", submenu2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void text()
{
	char text[40] = "Press 's' to release the ball";
	char text1[40] = "Press 'a' to move the paddle left";
	char text2[40] = "Press 'd' to move the paddle right";
	char text3[40] = "Press 'q' to close the window";
	// The color
	glColor3fv(text_color_array[0]);
	// Position of the text to be printer
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRasterPos3f(0.2, 0, 20);
	for (int i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	glRasterPos3f(0.2, -0.15, 20);
	for (int i = 0; text1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
	glRasterPos3f(0.2, -0.30, 20);
	for (int i = 0; text2[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
	glRasterPos3f(0.2, -0.45, 20);
	for (int i = 0; text3[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text3[i]);
	glPopMatrix();
}


//The main display function
void display(void) {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 0, 0, 0, 0, -25, 0, 1, 0);
	glTranslatef(0, 0, -25);
	draw_paddle();
	draw_bricks();
	draw_ball(bx, by, 1.0);
	text();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}


//function to take in keyboard entries
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd': px += 3; break;
	case 'a': px -= 3; break;
	case 'q': exit(0); break;
	case 's':
		if (!start)
		{
			dirx = diry = 1;
			rate = game_level[level];
			start = 1;
			glutSetCursor(GLUT_CURSOR_NONE);

		}
		break;
	}
	if (px > 15)
	{
		px = 15;
	}
	if (px < -15)
	{
		px = -15;
	}
	if (start == 0)
	{
		px = 0;
	}
	glutPostRedisplay();
}


//Function to handle the case when the ball strikes the bricks
void hit()
{
	int i, j;
	for (i = 1; i <= rows; i++)
		for (j = 1; j <= columns; j++)
		{
			if ((bx >= brick_array[i][j].x - 19.5 - 0.1) && (bx <= brick_array[i][j].x + 3 - 19.5 + 0.1))
			{
				if (by >= brick_array[i][j].y + 5 - 0.1 && by <= brick_array[i][j].y + 5 + 1.2 + 0.1)
				{
					brick_array[i][j].x = 0;
					brick_array[i][j].y = 0;
					diry = diry * -1;
				}
				//cout<<bx<<" "<<by<<"\t"<<brick_array[i][j].x<<" "<<brick_array[i][j].y;
			}
			else if (by >= brick_array[i][j].y + 5 - 0.1 && by <= brick_array[i][j].y + 5 + 1.2 + 0.1)
			{
				if ((bx >= brick_array[i][j].x - 19.5 - 0.1) && (bx <= brick_array[i][j].x + 3 - 19.5 + 0.1))
				{
					brick_array[i][j].x = 0;
					brick_array[i][j].y = 0;
					dirx = dirx * -1;
				}
				//cout<<bx<<" "<<by<<"\t"<<brick_array[i][j].x<<" "<<brick_array[i][j].y;
			}
		}
}


//The idle function. Handles the motion of the ball along with rebounding from various surfaces
void idle()
{
	hit();
	if (bx < -16 || bx>16 && start == 1) // Reflection from right left wall
	{
		dirx = dirx * -1;
	}
	if (by < -15 || by>14 && start == 1)  // Reflection from top bottom wall
	{
		diry = diry * -1;
	}
	bx += dirx / (rate);
	by += diry / (rate);
	rate -= 0.001; // Rate at which the speed of ball increases

	float x = paddle_size[size];
	//Make changes here for the different position of ball after rebounded by paddle
	if (by <= -12.8 && bx<(px + x * 2 / 3) && bx>(px + x / 3) && start == 1)
	{
		dirx = 1;
		diry = 1;
	}
	else if (by <= -12.8 && bx<(px - x / 3) && bx>(px - x * 2 / 3) && start == 1)
	{
		dirx = -1;
		diry = 1;
	}
	else if (by <= -12.8 && bx<(px + x / 3) && bx>(px - x / 3) && start == 1)
	{
		dirx = dirx;
		diry = 1;
	}
	else if (by <= -12.8 && bx<(px - (x * 2 / 3)) && bx>(px - (x + 0.3)) && start == 1)
	{
		dirx = -1.5;
		diry = 0.8;
	}
	else if (by <= -12.8 && bx<(px + (x + 0.3)) && bx>(px + x / 3) && start == 1)
	{
		dirx = 1.5;
		diry = 0.8;
	}
	else if (by < -13)
	{
		start = 0;
		by = -12.8;
		bx = 0;
		dirx = 0;
		diry = 0;
		px = 0;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1100, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Brick Breaker");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	addMenu();

	glutMainLoop();
	return 0;
}