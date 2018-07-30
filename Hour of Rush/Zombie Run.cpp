#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <GL/glut.h>
#include <time.h>
#include<Windows.h>
#include<Mmsystem.h>
#include"PauseScreen.h"
#include"Menu.h"
#include"controlMenu.h"
#include"Highscore.h"
#include"GameOverScreen.h"
using namespace std;

PauseScreen pauseScreen;
Menu menu;
controlMenu controlScreen;
highScoreMenu highScore;
gameOver gameEndScreen;

int windowWidth  = 1024;     // Windowed mode's width
int windowHeight = 576;     // Windowed mode's height
int windowPosX   = 200;      // Windowed mode's top-left corner x
int windowPosY   = 100;

unsigned long int total_points = 0;
bool gCount = false; // writing high score once

short random = 0;
bool zombie1State = false;
bool zombie2State = false;
bool zombie3State = false;
bool zombie4State = false;

short zombie1Hit = 0; // zombie life
short zombie2Hit = 0;
short zombie3Hit = 0;
short zombie4Hit = 0;

short playerHit = 0; // player life

bool soundPlayingFlag = false; // to switch from menu sound to background sound
bool gameOverSoundFlag = false;
bool restartFlag = false;
bool fromGameToMenu = false;
bool firstMenuFlag = false;

bool flag1 = false; //for zombie1 leg & hand movement

bool fullScreenMode = false;

bool paused = false; //pausing the game
bool gameMenu = true;
bool gameControlMenu = false;
bool showHighScore = false;
bool gameover = false;

float zombie1x = -4.0;
float zombie1y = 0.5;

float zombie2x = 3.5;
float zombie2y = -1.5;

float zombie3x = 4.5;
float zombie3y = 0.5;

float zombie4x = -3.5;
float zombie4y = -2.0;

float zombieSpeedControl = -0.003;

char playerPos = 'F';

char bullet1ShootPos;
char bullet2ShootPos;
char bullet3ShootPos;
char bullet4ShootPos;
char bullet5ShootPos;

bool bullet1 = false;
bool bullet2 = false;
bool bullet3 = false;
bool bullet4 = false;
bool bullet5 = false;

short bulletCount = 0;

float shootPos1x;
float shootPos1y;
float shootPos2x;
float shootPos2y;
float shootPos3x;
float shootPos3y;
float shootPos4x;
float shootPos4y;
float shootPos5x;
float shootPos5y;

float playerX = 0.0f;
float playerY = -2.15f;

//scenery start

int w,h;

float getX(int x){
    return (float)x/(1600/7);
}

float getY(int y){
    return (float)y/(800/7);
}

float _movesun = 0.0f;
float _cloud = -0.5f;

void cloud1()
 {

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.044;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.98f,y+.74f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.035;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.95f,y+.8f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.9f,y+.82f );
	}
	glEnd();

 glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.94f,y+.74f );
	}
	glEnd();

 glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.035;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.85f,y+.8f );
	}
	glEnd();

glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.043;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.81f,y+.74f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.87f,y+.75f );
	}
	glEnd();
}


void cloud2()
{
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.044;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.42,y+.74f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.035;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.41f,y+.8f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.36f,y+.82f );
	}
	glEnd();

 glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.40f,y+.74f );
	}
	glEnd();

 glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.035;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.31f,y+.8f );
	}
	glEnd();

glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.043;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.29f,y+.74f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.33f,y+.75f );
	}
	glEnd();



	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.33f,y+.68f );
	}
	glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.043;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x-.40f,y+.69f );
	}
	glEnd();

}

void cloud3()
{
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.044;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.10,y+.74f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.035;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.13f,y+.8f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.18f,y+.82f );
	}
	glEnd();

 glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.14f,y+.74f );
	}
	glEnd();

 glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.035;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.23f,y+.8f );
	}
	glEnd();

glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.043;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.27f,y+.74f );
	}
	glEnd();

	glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+.21f,y+.75f );
	}
	glEnd();
}

//scenery end

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

void bulletLogic()
{
    //bullet1 start
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();

    if(bullet1 == false)
    {
        glTranslatef(0.0, -2.60, 1.0);
    }
    else
    {
        glTranslatef(shootPos1x , shootPos1y, 1.0);
        //cout<<shootPos1x<<" s "<<shootPos1y<<endl;
        //cout<<zombie2x<<" z "<<zombie2y<<endl;

        //bullet shoot in specific direction
        //Bullet collision

        if(bullet1ShootPos == 'F' && shootPos1y < 0.7)
        {
            //extra checking for house start

            if((shootPos1x >= -2.88 && shootPos1x <= -0.56) && shootPos1y >= 0.0)
            {
                bullet1 = false;
            }

            //extra check end

            if(((shootPos1x >= (zombie1x-0.3)) && (shootPos1x <= (zombie1x+0.3)) && zombie1State) || ((shootPos1x >= (zombie2x-0.3)) && (shootPos1x <= (zombie2x+0.3)) && zombie2State) || ((shootPos1x >= (zombie3x-0.3)) && (shootPos1x <= (zombie3x+0.3)) && zombie3State) || ((shootPos1x >= (zombie4x-0.3)) && (shootPos1x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos1x >= (zombie1x-0.3)) && (shootPos1x <= (zombie1x+0.3)) && zombie1State) //Detection for zombie 1
                {
                    if((shootPos1y >= (zombie1y-1.0)) && (shootPos1y <= (zombie1y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie1y+=0.1; //translating the zombie forward
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos1x >= (zombie2x-0.3)) && (shootPos1x <= (zombie2x+0.3)) && zombie2State && bullet1) //bullet1 is still true //Detection for zombie 2
                {
                    if((shootPos1y >= (zombie2y-1.0)) && (shootPos1y <= (zombie2y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie2y+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos1x >= (zombie3x-0.3)) && (shootPos1x <= (zombie3x+0.3)) && zombie3State && bullet1) //Detection for zombie 3
                {
                    if((shootPos1y >= (zombie3y-1.0)) && (shootPos1y <= (zombie3y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie3y+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos1x >= (zombie4x-0.3)) && (shootPos1x <= (zombie4x+0.3)) && zombie4State && bullet1) //Detection for zombie 4
                {
                    if((shootPos1y >= (zombie4y-1.0)) && (shootPos1y <= (zombie4y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie4y+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet1) //bullet1 is still true
            {
                shootPos1y+=0.1;
            }
        }
        else if(bullet1ShootPos == 'B' && shootPos1y > -2.15)
        {
            if(((shootPos1x >= (zombie1x-0.3)) && (shootPos1x <= (zombie1x+0.3)) && zombie1State) || ((shootPos1x >= (zombie2x-0.3)) && (shootPos1x <= (zombie2x+0.3)) && zombie2State) || ((shootPos1x >= (zombie3x-0.3)) && (shootPos1x <= (zombie3x+0.3)) && zombie3State) || ((shootPos1x >= (zombie4x-0.3)) && (shootPos1x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos1x >= (zombie1x-0.3)) && (shootPos1x <= (zombie1x+0.3)) && zombie1State)
                {
                    if((shootPos1y <= (zombie1y+0.3)) && (shootPos1y >= (zombie1y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie1y-=0.1; // translating the zombie backward
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos1x >= (zombie2x-0.3)) && (shootPos1x <= (zombie2x+0.3)) && zombie2State && bullet1)
                {
                    if((shootPos1y <= (zombie2y+0.3)) && (shootPos1y >= (zombie2y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie2y-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos1x >= (zombie3x-0.3)) && (shootPos1x <= (zombie3x+0.3)) && zombie3State && bullet1)
                {
                    if((shootPos1y <= (zombie3y+0.3)) && (shootPos1y >= (zombie3y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie3y-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos1x >= (zombie4x-0.3)) && (shootPos1x <= (zombie4x+0.3)) && zombie4State && bullet1)
                {
                    if((shootPos1y <= (zombie4y+0.3)) && (shootPos1y >= (zombie4y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie4y-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet1)
            {
                shootPos1y-=0.1;
            }
        }
        else if(bullet1ShootPos == 'L' && shootPos1x > -4.15)
        {
            if(((shootPos1y >= (zombie1y-0.7)) && (shootPos1y <= (zombie1y+0.5)) && zombie1State) || ((shootPos1y >= (zombie2y-0.7)) && (shootPos1y <= (zombie2y+0.5)) && zombie2State) || ((shootPos1y >= (zombie3y-0.7)) && (shootPos1y <= (zombie3y+0.5)) && zombie3State) || ((shootPos1y >= (zombie4y-0.7)) && (shootPos1y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos1y >= (zombie1y-0.7)) && (shootPos1y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos1x >= (zombie1x)) && (shootPos1x <= (zombie1x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie1x-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos1y >= (zombie2y-0.7)) && (shootPos1y <= (zombie2y+0.5)) && zombie2State && bullet1)
                {
                    if((shootPos1x >= (zombie2x)) && (shootPos1x <= (zombie2x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie2x-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos1y >= (zombie3y-0.7)) && (shootPos1y <= (zombie3y+0.5)) && zombie3State && bullet1)
                {
                    if((shootPos1x >= (zombie3x)) && (shootPos1x <= (zombie3x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie3x-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos1y >= (zombie4y-0.7)) && (shootPos1y <= (zombie4y+0.5)) && zombie4State && bullet1)
                {
                    if((shootPos1x >= (zombie4x)) && (shootPos1x <= (zombie4x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie4x-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet1) //bullet1 is still true, does not hit anything
            {
                shootPos1x-=0.1;
            }
        }
        else if(bullet1ShootPos == 'R' && shootPos1x < 4.15)
        {
            if(((shootPos1y >= (zombie1y-0.7)) && (shootPos1y <= (zombie1y+0.5)) && zombie1State) || ((shootPos1y >= (zombie2y-0.7)) && (shootPos1y <= (zombie2y+0.5)) && zombie2State) || ((shootPos1y >= (zombie3y-0.7)) && (shootPos1y <= (zombie3y+0.5)) && zombie3State) || ((shootPos1y >= (zombie4y-0.7)) && (shootPos1y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos1y >= (zombie1y-0.7)) && (shootPos1y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos1x >= (zombie1x-0.3)) && (shootPos1x <= (zombie1x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie1x+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos1y >= (zombie2y-0.7)) && (shootPos1y <= (zombie2y+0.5)) && zombie2State && bullet1)
                {
                    if((shootPos1x >= (zombie2x-0.3)) && (shootPos1x <= (zombie2x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie2x+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos1y >= (zombie3y-0.7)) && (shootPos1y <= (zombie3y+0.5)) && zombie3State && bullet1)
                {
                    if((shootPos1x >= (zombie3x-0.3)) && (shootPos1x <= (zombie3x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie3x+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos1y >= (zombie4y-0.7)) && (shootPos1y <= (zombie4y+0.5)) && zombie4State && bullet1)
                {
                    if((shootPos1x >= (zombie4x-0.3)) && (shootPos1x <= (zombie4x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet1 = false;
                        zombie4x+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet1) //bullet1 is still true, does not hit anything
            {
                shootPos1x+=0.1;
            }
        }
        else
        {
            bullet1 = false;
        }
    }

    glPushMatrix();

    glScalef(0.2,0.2,0);

    glutSolidCube(0.3); //.7 (.1,.2,0)

    glPopMatrix();

    glPopMatrix();
    //bullet1 end

    //bullet2 start
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();

    if(bullet2 == false)
    {
        glTranslatef(0.0, -2.60, 1.0);
    }
    else
    {
        glTranslatef(shootPos2x , shootPos2y, 1.0);

        //bullet shoot in specific direction
        //Bullet collision

        if(bullet2ShootPos == 'F' && shootPos2y < 0.7)
        {
            if((shootPos2x >= -2.88 && shootPos2x <= -0.56) && shootPos2y >= 0.0)
            {
                bullet2 = false;
            }

            if(((shootPos2x >= (zombie1x-0.3)) && (shootPos2x <= (zombie1x+0.3)) && zombie1State) || ((shootPos2x >= (zombie2x-0.3)) && (shootPos2x <= (zombie2x+0.3)) && zombie2State) || ((shootPos2x >= (zombie3x-0.3)) && (shootPos2x <= (zombie3x+0.3)) && zombie3State) || ((shootPos2x >= (zombie4x-0.3)) && (shootPos2x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos2x >= (zombie1x-0.3)) && (shootPos2x <= (zombie1x+0.3)) && zombie1State) //Detection for zombie 1
                {
                    if((shootPos2y >= (zombie1y-1.0)) && (shootPos2y <= (zombie1y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie1y+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos2x >= (zombie2x-0.3)) && (shootPos2x <= (zombie2x+0.3)) && zombie2State && bullet2) //bullet2 is still true //Detection for zombie 2
                {
                    if((shootPos2y >= (zombie2y-1.0)) && (shootPos2y <= (zombie2y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie2y+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos2x >= (zombie3x-0.3)) && (shootPos2x <= (zombie3x+0.3)) && zombie3State && bullet2) //Detection for zombie 3
                {
                    if((shootPos2y >= (zombie3y-1.0)) && (shootPos2y <= (zombie3y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie3y+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos2x >= (zombie4x-0.3)) && (shootPos2x <= (zombie4x+0.3)) && zombie4State && bullet2) //Detection for zombie 4
                {
                    if((shootPos2y >= (zombie4y-1.0)) && (shootPos2y <= (zombie4y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie4y+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet2) //bullet2 is still true
            {
                shootPos2y+=0.1;
            }
        }
        else if(bullet2ShootPos == 'B' && shootPos2y > -2.15)
        {
            if(((shootPos2x >= (zombie1x-0.3)) && (shootPos2x <= (zombie1x+0.3)) && zombie1State) || ((shootPos2x >= (zombie2x-0.3)) && (shootPos2x <= (zombie2x+0.3)) && zombie2State) || ((shootPos2x >= (zombie3x-0.3)) && (shootPos2x <= (zombie3x+0.3)) && zombie3State) || ((shootPos2x >= (zombie4x-0.3)) && (shootPos2x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos2x >= (zombie1x-0.3)) && (shootPos2x <= (zombie1x+0.3)) && zombie1State)
                {
                    if((shootPos2y <= (zombie1y+0.3)) && (shootPos2y >= (zombie1y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie1y-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos2x >= (zombie2x-0.3)) && (shootPos2x <= (zombie2x+0.3)) && zombie2State && bullet2)
                {
                    if((shootPos2y <= (zombie2y+0.3)) && (shootPos2y >= (zombie2y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie2y-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos2x >= (zombie3x-0.3)) && (shootPos2x <= (zombie3x+0.3)) && zombie3State && bullet2)
                {
                    if((shootPos2y <= (zombie3y+0.3)) && (shootPos2y >= (zombie3y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie3y-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos2x >= (zombie4x-0.3)) && (shootPos2x <= (zombie4x+0.3)) && zombie4State && bullet2)
                {
                    if((shootPos2y <= (zombie4y+0.3)) && (shootPos2y >= (zombie4y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie4y-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet2)
            {
                shootPos2y-=0.1;
            }
        }
        else if(bullet2ShootPos == 'L' && shootPos2x > -4.15)
        {
            if(((shootPos2y >= (zombie1y-0.7)) && (shootPos2y <= (zombie1y+0.5)) && zombie1State) || ((shootPos2y >= (zombie2y-0.7)) && (shootPos2y <= (zombie2y+0.5)) && zombie2State) || ((shootPos2y >= (zombie3y-0.7)) && (shootPos2y <= (zombie3y+0.5)) && zombie3State) || ((shootPos2y >= (zombie4y-0.7)) && (shootPos2y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos2y >= (zombie1y-0.7)) && (shootPos2y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos2x >= (zombie1x)) && (shootPos2x <= (zombie1x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie1x-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos2y >= (zombie2y-0.7)) && (shootPos2y <= (zombie2y+0.5)) && zombie2State && bullet2)
                {
                    if((shootPos2x >= (zombie2x)) && (shootPos2x <= (zombie2x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie2x-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos2y >= (zombie3y-0.7)) && (shootPos2y <= (zombie3y+0.5)) && zombie3State && bullet2)
                {
                    if((shootPos2x >= (zombie3x)) && (shootPos2x <= (zombie3x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie3x-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos2y >= (zombie4y-0.7)) && (shootPos2y <= (zombie4y+0.5)) && zombie4State && bullet2)
                {
                    if((shootPos2x >= (zombie4x)) && (shootPos2x <= (zombie4x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie4x-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet2) //bullet2 is still true, does not hit anything
            {
                shootPos2x-=0.1;
            }
        }
        else if(bullet2ShootPos == 'R' && shootPos2x < 4.15)
        {
            if(((shootPos2y >= (zombie1y-0.7)) && (shootPos2y <= (zombie1y+0.5)) && zombie1State) || ((shootPos2y >= (zombie2y-0.7)) && (shootPos2y <= (zombie2y+0.5)) && zombie2State) || ((shootPos2y >= (zombie3y-0.7)) && (shootPos2y <= (zombie3y+0.5)) && zombie3State) || ((shootPos2y >= (zombie4y-0.7)) && (shootPos2y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos2y >= (zombie1y-0.7)) && (shootPos2y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos2x >= (zombie1x-0.3)) && (shootPos2x <= (zombie1x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie1x+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos2y >= (zombie2y-0.7)) && (shootPos2y <= (zombie2y+0.5)) && zombie2State && bullet2)
                {
                    if((shootPos2x >= (zombie2x-0.3)) && (shootPos2x <= (zombie2x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie2x+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos2y >= (zombie3y-0.7)) && (shootPos2y <= (zombie3y+0.5)) && zombie3State && bullet2)
                {
                    if((shootPos2x >= (zombie3x-0.3)) && (shootPos2x <= (zombie3x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie3x+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos2y >= (zombie4y-0.7)) && (shootPos2y <= (zombie4y+0.5)) && zombie4State && bullet2)
                {
                    if((shootPos2x >= (zombie4x-0.3)) && (shootPos2x <= (zombie4x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet2 = false;
                        zombie4x+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet2) //bullet2 is still true, does not hit anything
            {
                shootPos2x+=0.1;
            }
        }
        else
        {
            bullet2 = false;
        }
    }

    glPushMatrix();

    glScalef(0.2,0.2,0);

    glutSolidCube(0.3); //.7 (.1,.2,0)

    glPopMatrix();

    glPopMatrix();
    //bullet2 end

    //bullet3 start
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();

    if(bullet3 == false)
    {
        glTranslatef(0.0, -2.60, 1.0);
    }
    else
    {
        glTranslatef(shootPos3x , shootPos3y, 1.0);

        //bullet shoot in specific direction
        //Bullet collision

        if(bullet3ShootPos == 'F' && shootPos3y < 0.7)
        {
            if((shootPos3x >= -2.88 && shootPos3x <= -0.56) && shootPos3y >= 0.0)
            {
                bullet3 = false;
            }

            if(((shootPos3x >= (zombie1x-0.3)) && (shootPos3x <= (zombie1x+0.3)) && zombie1State) || ((shootPos3x >= (zombie2x-0.3)) && (shootPos3x <= (zombie2x+0.3)) && zombie2State) || ((shootPos3x >= (zombie3x-0.3)) && (shootPos3x <= (zombie3x+0.3)) && zombie3State) || ((shootPos3x >= (zombie4x-0.3)) && (shootPos3x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos3x >= (zombie1x-0.3)) && (shootPos3x <= (zombie1x+0.3)) && zombie1State) //Detection for zombie 1
                {
                    if((shootPos3y >= (zombie1y-1.0)) && (shootPos3y <= (zombie1y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie1y+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos3x >= (zombie2x-0.3)) && (shootPos3x <= (zombie2x+0.3)) && zombie2State && bullet3) //bullet3 is still true //Detection for zombie 2
                {
                    if((shootPos3y >= (zombie2y-1.0)) && (shootPos3y <= (zombie2y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie2y+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos3x >= (zombie3x-0.3)) && (shootPos3x <= (zombie3x+0.3)) && zombie3State && bullet3) //Detection for zombie 3
                {
                    if((shootPos3y >= (zombie3y-1.0)) && (shootPos3y <= (zombie3y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie3y+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos3x >= (zombie4x-0.3)) && (shootPos3x <= (zombie4x+0.3)) && zombie4State && bullet3) //Detection for zombie 4
                {
                    if((shootPos3y >= (zombie4y-1.0)) && (shootPos3y <= (zombie4y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie4y+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet3) //bullet3 is still true
            {
                shootPos3y+=0.1;
            }
        }
        else if(bullet3ShootPos == 'B' && shootPos3y > -2.15)
        {
            if(((shootPos3x >= (zombie1x-0.3)) && (shootPos3x <= (zombie1x+0.3)) && zombie1State) || ((shootPos3x >= (zombie2x-0.3)) && (shootPos3x <= (zombie2x+0.3)) && zombie2State) || ((shootPos3x >= (zombie3x-0.3)) && (shootPos3x <= (zombie3x+0.3)) && zombie3State) || ((shootPos3x >= (zombie4x-0.3)) && (shootPos3x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos3x >= (zombie1x-0.3)) && (shootPos3x <= (zombie1x+0.3)) && zombie1State)
                {
                    if((shootPos3y <= (zombie1y+0.3)) && (shootPos3y >= (zombie1y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie1y-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos3x >= (zombie2x-0.3)) && (shootPos3x <= (zombie2x+0.3)) && zombie2State && bullet3)
                {
                    if((shootPos3y <= (zombie2y+0.3)) && (shootPos3y >= (zombie2y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie2y-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos3x >= (zombie3x-0.3)) && (shootPos3x <= (zombie3x+0.3)) && zombie3State && bullet3)
                {
                    if((shootPos3y <= (zombie3y+0.3)) && (shootPos3y >= (zombie3y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie3y-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos3x >= (zombie4x-0.3)) && (shootPos3x <= (zombie4x+0.3)) && zombie4State && bullet3)
                {
                    if((shootPos3y <= (zombie4y+0.3)) && (shootPos3y >= (zombie4y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie4y-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet3)
            {
                shootPos3y-=0.1;
            }
        }
        else if(bullet3ShootPos == 'L' && shootPos3x > -4.15)
        {
            if(((shootPos3y >= (zombie1y-0.7)) && (shootPos3y <= (zombie1y+0.5)) && zombie1State) || ((shootPos3y >= (zombie2y-0.7)) && (shootPos3y <= (zombie2y+0.5)) && zombie2State) || ((shootPos3y >= (zombie3y-0.7)) && (shootPos3y <= (zombie3y+0.5)) && zombie3State) || ((shootPos3y >= (zombie4y-0.7)) && (shootPos3y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos3y >= (zombie1y-0.7)) && (shootPos3y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos3x >= (zombie1x)) && (shootPos3x <= (zombie1x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        zombie1x-=0.1;
                        bullet3 = false;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos3y >= (zombie2y-0.7)) && (shootPos3y <= (zombie2y+0.5)) && zombie2State && bullet3)
                {
                    if((shootPos3x >= (zombie2x)) && (shootPos3x <= (zombie2x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie2x-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos3y >= (zombie3y-0.7)) && (shootPos3y <= (zombie3y+0.5)) && zombie3State && bullet3)
                {
                    if((shootPos3x >= (zombie3x)) && (shootPos3x <= (zombie3x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie3x-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos3y >= (zombie4y-0.7)) && (shootPos3y <= (zombie4y+0.5)) && zombie4State && bullet3)
                {
                    if((shootPos3x >= (zombie4x)) && (shootPos3x <= (zombie4x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie4x-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet3) //bullet3 is still true, does not hit anything
            {
                shootPos3x-=0.1;
            }
        }
        else if(bullet3ShootPos == 'R' && shootPos3x < 4.15)
        {
            if(((shootPos3y >= (zombie1y-0.7)) && (shootPos3y <= (zombie1y+0.5)) && zombie1State) || ((shootPos3y >= (zombie2y-0.7)) && (shootPos3y <= (zombie2y+0.5)) && zombie2State) || ((shootPos3y >= (zombie3y-0.7)) && (shootPos3y <= (zombie3y+0.5)) && zombie3State) || ((shootPos3y >= (zombie4y-0.7)) && (shootPos3y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos3y >= (zombie1y-0.7)) && (shootPos3y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos3x >= (zombie1x-0.3)) && (shootPos3x <= (zombie1x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie1x+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos3y >= (zombie2y-0.7)) && (shootPos3y <= (zombie2y+0.5)) && zombie2State && bullet3)
                {
                    if((shootPos3x >= (zombie2x-0.3)) && (shootPos3x <= (zombie2x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie2x+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos3y >= (zombie3y-0.7)) && (shootPos3y <= (zombie3y+0.5)) && zombie3State && bullet3)
                {
                    if((shootPos3x >= (zombie3x-0.3)) && (shootPos3x <= (zombie3x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie3x+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos3y >= (zombie4y-0.7)) && (shootPos3y <= (zombie4y+0.5)) && zombie4State && bullet3)
                {
                    if((shootPos3x >= (zombie4x-0.3)) && (shootPos3x <= (zombie4x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet3 = false;
                        zombie4x+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet3) //bullet3 is still true, does not hit anything
            {
                shootPos3x+=0.1;
            }
        }
        else
        {
            bullet3 = false;
        }
    }

    glPushMatrix();

    glScalef(0.2,0.2,0);

    glutSolidCube(0.3); //.7 (.1,.2,0)

    glPopMatrix();

    glPopMatrix();
    //bullet3 end

    //bullet4 start
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();

    if(bullet4 == false)
    {
        glTranslatef(0.0, -2.60, 1.0);
    }
    else
    {
        glTranslatef(shootPos4x , shootPos4y, 1.0);

        //bullet shoot in specific direction
        //Bullet collision

        if(bullet4ShootPos == 'F' && shootPos4y < 0.7)
        {
            if((shootPos4x >= -2.88 && shootPos4x <= -0.56) && shootPos4y >= 0.0)
            {
                bullet4 = false;
            }

            if(((shootPos4x >= (zombie1x-0.3)) && (shootPos4x <= (zombie1x+0.3)) && zombie1State) || ((shootPos4x >= (zombie2x-0.3)) && (shootPos4x <= (zombie2x+0.3)) && zombie2State) || ((shootPos4x >= (zombie3x-0.3)) && (shootPos4x <= (zombie3x+0.3)) && zombie3State) || ((shootPos4x >= (zombie4x-0.3)) && (shootPos4x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos4x >= (zombie1x-0.3)) && (shootPos4x <= (zombie1x+0.3)) && zombie1State) //Detection for zombie 1
                {
                    if((shootPos4y >= (zombie1y-1.0)) && (shootPos4y <= (zombie1y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie1y+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos4x >= (zombie2x-0.3)) && (shootPos4x <= (zombie2x+0.3)) && zombie2State && bullet4) //bullet4 is still true //Detection for zombie 2
                {
                    if((shootPos4y >= (zombie2y-1.0)) && (shootPos4y <= (zombie2y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie2y+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos4x >= (zombie3x-0.3)) && (shootPos4x <= (zombie3x+0.3)) && zombie3State && bullet4) //Detection for zombie 3
                {
                    if((shootPos4y >= (zombie3y-1.0)) && (shootPos4y <= (zombie3y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie3y+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos4x >= (zombie4x-0.3)) && (shootPos4x <= (zombie4x+0.3)) && zombie4State && bullet4) //Detection for zombie 4
                {
                    if((shootPos4y >= (zombie4y-1.0)) && (shootPos4y <= (zombie4y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie4y+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet4) //bullet4 is still true
            {
                shootPos4y+=0.1;
            }
        }
        else if(bullet4ShootPos == 'B' && shootPos4y > -2.15)
        {
            if(((shootPos4x >= (zombie1x-0.3)) && (shootPos4x <= (zombie1x+0.3)) && zombie1State) || ((shootPos4x >= (zombie2x-0.3)) && (shootPos4x <= (zombie2x+0.3)) && zombie2State) || ((shootPos4x >= (zombie3x-0.3)) && (shootPos4x <= (zombie3x+0.3)) && zombie3State) || ((shootPos4x >= (zombie4x-0.3)) && (shootPos4x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos4x >= (zombie1x-0.3)) && (shootPos4x <= (zombie1x+0.3)) && zombie1State)
                {
                    if((shootPos4y <= (zombie1y+0.3)) && (shootPos4y >= (zombie1y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie1y-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos4x >= (zombie2x-0.3)) && (shootPos4x <= (zombie2x+0.3)) && zombie2State && bullet4)
                {
                    if((shootPos4y <= (zombie2y+0.3)) && (shootPos4y >= (zombie2y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie2y-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos4x >= (zombie3x-0.3)) && (shootPos4x <= (zombie3x+0.3)) && zombie3State && bullet4)
                {
                    if((shootPos4y <= (zombie3y+0.3)) && (shootPos4y >= (zombie3y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie3y-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos4x >= (zombie4x-0.3)) && (shootPos4x <= (zombie4x+0.3)) && zombie4State && bullet4)
                {
                    if((shootPos4y <= (zombie4y+0.3)) && (shootPos4y >= (zombie4y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie4y-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet4)
            {
                shootPos4y-=0.1;
            }
        }
        else if(bullet4ShootPos == 'L' && shootPos4x > -4.15)
        {
            if(((shootPos4y >= (zombie1y-0.7)) && (shootPos4y <= (zombie1y+0.5)) && zombie1State) || ((shootPos4y >= (zombie2y-0.7)) && (shootPos4y <= (zombie2y+0.5)) && zombie2State) || ((shootPos4y >= (zombie3y-0.7)) && (shootPos4y <= (zombie3y+0.5)) && zombie3State) || ((shootPos4y >= (zombie4y-0.7)) && (shootPos4y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos4y >= (zombie1y-0.7)) && (shootPos4y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos4x >= (zombie1x)) && (shootPos4x <= (zombie1x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie1x-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos4y >= (zombie2y-0.7)) && (shootPos4y <= (zombie2y+0.5)) && zombie2State && bullet4)
                {
                    if((shootPos4x >= (zombie2x)) && (shootPos4x <= (zombie2x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie2x-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos4y >= (zombie3y-0.7)) && (shootPos4y <= (zombie3y+0.5)) && zombie3State && bullet4)
                {
                    if((shootPos4x >= (zombie3x)) && (shootPos4x <= (zombie3x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie3x-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos4y >= (zombie4y-0.7)) && (shootPos4y <= (zombie4y+0.5)) && zombie4State && bullet4)
                {
                    if((shootPos4x >= (zombie4x)) && (shootPos4x <= (zombie4x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie4x-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet4) //bullet4 is still true, does not hit anything
            {
                shootPos4x-=0.1;
            }
        }
        else if(bullet4ShootPos == 'R' && shootPos4x < 4.15)
        {
            if(((shootPos4y >= (zombie1y-0.7)) && (shootPos4y <= (zombie1y+0.5)) && zombie1State) || ((shootPos4y >= (zombie2y-0.7)) && (shootPos4y <= (zombie2y+0.5)) && zombie2State) || ((shootPos4y >= (zombie3y-0.7)) && (shootPos4y <= (zombie3y+0.5)) && zombie3State) || ((shootPos4y >= (zombie4y-0.7)) && (shootPos4y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos4y >= (zombie1y-0.7)) && (shootPos4y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos4x >= (zombie1x-0.3)) && (shootPos4x <= (zombie1x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie1x+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos4y >= (zombie2y-0.7)) && (shootPos4y <= (zombie2y+0.5)) && zombie2State && bullet4)
                {
                    if((shootPos4x >= (zombie2x-0.3)) && (shootPos4x <= (zombie2x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie2x+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos4y >= (zombie3y-0.7)) && (shootPos4y <= (zombie3y+0.5)) && zombie3State && bullet4)
                {
                    if((shootPos4x >= (zombie3x-0.3)) && (shootPos4x <= (zombie3x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie3x+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos4y >= (zombie4y-0.7)) && (shootPos4y <= (zombie4y+0.5)) && zombie4State && bullet4)
                {
                    if((shootPos4x >= (zombie4x-0.3)) && (shootPos4x <= (zombie4x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet4 = false;
                        zombie4x+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet4) //bullet4 is still true, does not hit anything
            {
                shootPos4x+=0.1;
            }
        }
        else
        {
            bullet4 = false;
        }
    }

    glPushMatrix();

    glScalef(0.2,0.2,0);

    glutSolidCube(0.3); //.7 (.1,.2,0)

    glPopMatrix();

    glPopMatrix();
    //bullet4 end

    //bullet5 start
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();

    if(bullet5 == false)
    {
        glTranslatef(0.0, -2.60, 1.0);
    }
    else
    {
        glTranslatef(shootPos5x , shootPos5y, 1.0);

        //bullet shoot in specific direction
        //Bullet collision

        if(bullet5ShootPos == 'F' && shootPos5y < 0.7)
        {
            if((shootPos5x >= -2.88 && shootPos5x <= -0.56) && shootPos5y >= 0.0)
            {
                bullet5 = false;
            }

            if(((shootPos5x >= (zombie1x-0.3)) && (shootPos5x <= (zombie1x+0.3)) && zombie1State) || ((shootPos5x >= (zombie2x-0.3)) && (shootPos5x <= (zombie2x+0.3)) && zombie2State) || ((shootPos5x >= (zombie3x-0.3)) && (shootPos5x <= (zombie3x+0.3)) && zombie3State) || ((shootPos5x >= (zombie4x-0.3)) && (shootPos5x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos5x >= (zombie1x-0.3)) && (shootPos5x <= (zombie1x+0.3)) && zombie1State) //Detection for zombie 1
                {
                    if((shootPos5y >= (zombie1y-1.0)) && (shootPos5y <= (zombie1y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie1y+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos5x >= (zombie2x-0.3)) && (shootPos5x <= (zombie2x+0.3)) && zombie2State && bullet5) //bullet5 is still true //Detection for zombie 2
                {
                    if((shootPos5y >= (zombie2y-1.0)) && (shootPos5y <= (zombie2y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie2y+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos5x >= (zombie3x-0.3)) && (shootPos5x <= (zombie3x+0.3)) && zombie3State && bullet5) //Detection for zombie 3
                {
                    if((shootPos5y >= (zombie3y-1.0)) && (shootPos5y <= (zombie3y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie3y+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos5x >= (zombie4x-0.3)) && (shootPos5x <= (zombie4x+0.3)) && zombie4State && bullet5) //Detection for zombie 4
                {
                    if((shootPos5y >= (zombie4y-1.0)) && (shootPos5y <= (zombie4y))) //zombie1y-0.3 or zombie1y-1.0
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie4y+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet5) //bullet5 is still true
            {
                shootPos5y+=0.1;
            }
        }
        else if(bullet5ShootPos == 'B' && shootPos5y > -2.15)
        {
            if(((shootPos5x >= (zombie1x-0.3)) && (shootPos5x <= (zombie1x+0.3)) && zombie1State) || ((shootPos5x >= (zombie2x-0.3)) && (shootPos5x <= (zombie2x+0.3)) && zombie2State) || ((shootPos5x >= (zombie3x-0.3)) && (shootPos5x <= (zombie3x+0.3)) && zombie3State) || ((shootPos5x >= (zombie4x-0.3)) && (shootPos5x <= (zombie4x+0.3)) && zombie4State))
            {
                if((shootPos5x >= (zombie1x-0.3)) && (shootPos5x <= (zombie1x+0.3)) && zombie1State)
                {
                    if((shootPos5y <= (zombie1y+0.3)) && (shootPos5y >= (zombie1y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie1y-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos5x >= (zombie2x-0.3)) && (shootPos5x <= (zombie2x+0.3)) && zombie2State && bullet5)
                {
                    if((shootPos5y <= (zombie2y+0.3)) && (shootPos5y >= (zombie2y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie2y-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos5x >= (zombie3x-0.3)) && (shootPos5x <= (zombie3x+0.3)) && zombie3State && bullet5)
                {
                    if((shootPos5y <= (zombie3y+0.3)) && (shootPos5y >= (zombie3y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie3y-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos5x >= (zombie4x-0.3)) && (shootPos5x <= (zombie4x+0.3)) && zombie4State && bullet5)
                {
                    if((shootPos5y <= (zombie4y+0.3)) && (shootPos5y >= (zombie4y-0.6))) //zombie1y-0.6 or
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie4y-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet5)
            {
                shootPos5y-=0.1;
            }
        }
        else if(bullet5ShootPos == 'L' && shootPos5x > -4.15)
        {
            if(((shootPos5y >= (zombie1y-0.7)) && (shootPos5y <= (zombie1y+0.5)) && zombie1State) || ((shootPos5y >= (zombie2y-0.7)) && (shootPos5y <= (zombie2y+0.5)) && zombie2State) || ((shootPos5y >= (zombie3y-0.7)) && (shootPos5y <= (zombie3y+0.5)) && zombie3State) || ((shootPos5y >= (zombie4y-0.7)) && (shootPos5y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos5y >= (zombie1y-0.7)) && (shootPos5y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos5x >= (zombie1x)) && (shootPos5x <= (zombie1x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie1x-=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos5y >= (zombie2y-0.7)) && (shootPos5y <= (zombie2y+0.5)) && zombie2State && bullet5)
                {
                    if((shootPos5x >= (zombie2x)) && (shootPos5x <= (zombie2x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie2x-=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos5y >= (zombie3y-0.7)) && (shootPos5y <= (zombie3y+0.5)) && zombie3State && bullet5)
                {
                    if((shootPos5x >= (zombie3x)) && (shootPos5x <= (zombie3x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie3x-=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos5y >= (zombie4y-0.7)) && (shootPos5y <= (zombie4y+0.5)) && zombie4State && bullet5)
                {
                    if((shootPos5x >= (zombie4x)) && (shootPos5x <= (zombie4x+0.3))) //For early detection (Actually : zombie1x-0.2)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie4x-=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet5) //bullet5 is still true, does not hit anything
            {
                shootPos5x-=0.1;
            }
        }
        else if(bullet5ShootPos == 'R' && shootPos5x < 4.15)
        {
            if(((shootPos5y >= (zombie1y-0.7)) && (shootPos5y <= (zombie1y+0.5)) && zombie1State) || ((shootPos5y >= (zombie2y-0.7)) && (shootPos5y <= (zombie2y+0.5)) && zombie2State) || ((shootPos5y >= (zombie3y-0.7)) && (shootPos5y <= (zombie3y+0.5)) && zombie3State) || ((shootPos5y >= (zombie4y-0.7)) && (shootPos5y <= (zombie4y+0.5)) && zombie4State))
            {
                if((shootPos5y >= (zombie1y-0.7)) && (shootPos5y <= (zombie1y+0.5)) && zombie1State)
                {
                    if((shootPos5x >= (zombie1x-0.3)) && (shootPos5x <= (zombie1x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie1x+=0.1;
                        zombie1Hit++; //count bullet hit

                        if(zombie1Hit == 10)
                        {
                            zombie1State = false;
                            total_points+=50;
                        }
                    }
                }
                if((shootPos5y >= (zombie2y-0.7)) && (shootPos5y <= (zombie2y+0.5)) && zombie2State && bullet5)
                {
                    if((shootPos5x >= (zombie2x-0.3)) && (shootPos5x <= (zombie2x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie2x+=0.1;
                        zombie2Hit++; //count bullet hit

                        if(zombie2Hit == 9)
                        {
                            zombie2State = false;
                            total_points+=20;
                        }
                    }
                }
                if((shootPos5y >= (zombie3y-0.7)) && (shootPos5y <= (zombie3y+0.5)) && zombie3State && bullet5)
                {
                    if((shootPos5x >= (zombie3x-0.3)) && (shootPos5x <= (zombie3x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie3x+=0.1;
                        zombie3Hit++; //count bullet hit

                        if(zombie3Hit == 9)
                        {
                            zombie3State = false;
                            total_points+=40;
                        }
                    }
                }
                if((shootPos5y >= (zombie4y-0.7)) && (shootPos5y <= (zombie4y+0.5)) && zombie4State && bullet5)
                {
                    if((shootPos5x >= (zombie4x-0.3)) && (shootPos5x <= (zombie4x))) //For late detection (Actually : zombie1x-1.0)
                    {
                        cout<<"Detected"<<endl;
                        bullet5 = false;
                        zombie4x+=0.1;
                        zombie4Hit++; //count bullet hit

                        if(zombie4Hit == 8)
                        {
                            zombie4State = false;
                            total_points+=30;
                        }
                    }
                }
            }

            if(bullet5) //bullet5 is still true, does not hit anything
            {
                shootPos5x+=0.1;
            }
        }
        else
        {
            bullet5 = false;
        }
    }

    glPushMatrix();

    glScalef(0.2,0.2,0);

    glutSolidCube(0.3); //.7 (.1,.2,0)

    glPopMatrix();

    glPopMatrix();
    //bullet5 end
}

void zombie1()
{
    //enemy start

    glPushMatrix();

    glTranslatef(zombie1x, zombie1y, 0);

    float cal_PlayerY = roundf((playerY*100)/100);
    float cal_PlayerX = roundf((playerX*100)/100);
    float cal_Zombie1x = roundf((zombie1x*100)/100);
    float cal_Zombie1y = roundf((zombie1y*100)/100);//cout<<"z( "<<cal_Zombie1x<<", "<<cal_Zombie1y<<") "<<"p ("<<cal_PlayerX<<", "<<cal_PlayerY<<endl;

    //player to zombie collision
    if((cal_Zombie1y >= cal_PlayerY-0.1) && (cal_Zombie1y <= cal_PlayerY+0.1)) //Checking y-axis range
    {
        if(cal_Zombie1x > cal_PlayerX+0.15)
        {
            glRotatef(-30, 0.0, 1.0, 0.0); //Rotate left
        }
        else if(cal_Zombie1x < cal_PlayerX-0.15)
        {
            glRotatef(30, 0.0, 1.0, 0.0); //Rotate Right
        }
        else //collision
        {
            if(zombie1x > playerX) //move zombie & player a bit
            {
                zombie1x+=0.2;
                playerX-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie1x-=0.2;
                playerX+=0.1;
            }

            cout<<"Col\n";

            mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            mciSendString("play zombite1", NULL, 0, NULL); //repeat

            //mciSendString("close playerHurt", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"hurt.mp3\" type mpegvideo alias playerHurt", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play playerHurt", NULL, 0, NULL); //repeat

            playerHit++;

            if(playerHit == 6) // game over
            {
                gameover = true;
                gCount = false;
            }
        }
    }
    else
    {
        if((cal_Zombie1y < cal_PlayerY-0.15))
        {
            glRotatef(180, 0.0, 1.0, 0.0); //Rotate Backward
        }
        else
        {
            glRotatef(0, 0.0, 1.0, 0.0); //Rotate Forward
        }
    }

    //zombie1 to other zombie collision start
    if(zombie2State && (cal_Zombie1y >= zombie2y-0.3) && (cal_Zombie1y <= zombie2y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie1x > zombie2x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie1x < zombie2x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie1x > zombie2x) //move zombie & player a bit
            {
                zombie1x+=0.2;
                zombie2x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie1x-=0.2;
                zombie2x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie3State && (cal_Zombie1y >= zombie3y-0.3) && (cal_Zombie1y <= zombie3y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie1x > zombie3x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie1x < zombie3x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie1x > zombie3x) //move zombie & player a bit
            {
                zombie1x+=0.2;
                zombie3x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie1x-=0.2;
                zombie3x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie4State && (cal_Zombie1y >= zombie4y-0.3) && (cal_Zombie1y <= zombie4y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie1x > zombie4x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie1x < zombie4x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie1x > zombie4x) //move zombie & player a bit
            {
                zombie1x+=0.2;
                zombie4x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie1x-=0.2;
                zombie4x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    //zombie1 to other zombie collision end

    glScalef(0.17,0.17,0.17);

    //zombie chasing start
    if(playerX > zombie1x)
            zombie1x+=(0.01+zombieSpeedControl);
        else
            zombie1x-=(0.01+zombieSpeedControl);

        if(playerY > zombie1y)
            zombie1y+=(0.01+zombieSpeedControl);
        else
            zombie1y-=(0.01+zombieSpeedControl);

        //zombie chasing end

        //zombie drawing start

    glColor3f(.85, .64, .13);

    //Head start
    glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, 0.0, 1.0);
	glVertex3f(-0.1, 0.5 , 1.0);
	glVertex3f(0.0, 0.5 , 1.0);

	glVertex3f(0.0, 0.6 , 1.0);
	glVertex3f(0.1, 0.6 , 1.0);

	glVertex3f(0.1, 0.7 , 1.0);
	glVertex3f(0.2, 0.7 , 1.0);

	glVertex3f(0.2, 0.8 , 1.0);
	glVertex3f(0.3, 0.8 , 1.0);

	glVertex3f(0.3, 0.9 , 1.0);
	glVertex3f(0.4, 0.9 , 1.0);

	glVertex3f(0.4, 1.0 , 1.0);
	glVertex3f(0.5, 1.0 , 1.0);

	glVertex3f(1.0, 1.0 , 1.0);

	glVertex3f(1.0, 0.9 , 1.0);
	glVertex3f(1.1, 0.9 , 1.0);

	glVertex3f(1.1, 0.8 , 1.0);
	glVertex3f(1.2, 0.8 , 1.0);

	glVertex3f(1.2, 0.7 , 1.0);
	glVertex3f(1.3, 0.7 , 1.0);

	glVertex3f(1.3, 0.6 , 1.0);
	glVertex3f(1.4, 0.6 , 1.0);

	glVertex3f(1.4, 0.5 , 1.0);
	glVertex3f(1.5, 0.5 , 1.0);

	glVertex3f(1.5, 0.0 , 1.0);

	glVertex3f(1.4, 0.0 , 1.0);
	glVertex3f(1.4, -0.1 , 1.0);

	glVertex3f(1.3, -0.1 , 1.0);
	glVertex3f(1.3, -0.2 , 1.0);

	glVertex3f(1.2, -0.2 , 1.0);
	glVertex3f(1.2, -0.3 , 1.0);

	glVertex3f(1.1, -0.3 , 1.0);
	glVertex3f(1.1, -0.4 , 1.0);

	glVertex3f(1.0, -0.4 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0 , 1.0);
	glVertex3f(0.0, -0.1 , 1.0);
	glVertex3f(0.1, -0.1 , 1.0);

	glVertex3f(0.1, -0.2 , 1.0);
	glVertex3f(0.2, -0.2 , 1.0);

	glVertex3f(0.2, -0.3 , 1.0);
	glVertex3f(0.3, -0.3 , 1.0);

	glVertex3f(0.3, -0.4 , 1.0);
	glVertex3f(0.4, -0.4 , 1.0);

	glVertex3f(0.4, -0.5 , 1.0);
	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	//Head end

	//body start

	glColor3f(.85, .71, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(0.5, -0.5 , 1.0);
	glVertex3f(0.5, -0.7 , 1.0);
	glVertex3f(-0.3, -0.8 , 1.0);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);
	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(0.7, -0.7 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glEnd();

	//body end

	//left hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(-0.3, -0.8 , 1.0);
	glVertex3f(-1.0, -0.8 , 1.0);
	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-0.3, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(-_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-1.0, -2.5 , 1.0);
	glVertex3f(-0.5, -2.5 , 1.0);
	glVertex3f(-0.5, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.9, -2.5 , 1.0);
	glVertex3f(-0.9, -2.7 , 1.0);
	glVertex3f(-0.8, -2.7 , 1.0);
	glVertex3f(-0.8, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(-0.7, -2.5 , 1.0);
	glVertex3f(-0.7, -2.7 , 1.0);
	glVertex3f(-0.6, -2.7 , 1.0);
	glVertex3f(-0.6, -2.5 , 1.0);

	glEnd();

	//thumb end

    glPopMatrix();

	//left hand end

	//right hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(2.2, -0.8 , 1.0);
	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(1.5, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(2.2, -2.5 , 1.0);
	glVertex3f(1.7, -2.5 , 1.0);
	glVertex3f(1.7, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(1.8, -2.5 , 1.0);
	glVertex3f(1.8, -2.7 , 1.0);
	glVertex3f(1.9, -2.7 , 1.0);
	glVertex3f(1.9, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(2.0, -2.5 , 1.0);
	glVertex3f(2.0, -2.7 , 1.0);
	glVertex3f(2.1, -2.7 , 1.0);
	glVertex3f(2.1, -2.5 , 1.0);

	glEnd();

	//thumb end

	glPopMatrix();

	//right hand end

	//Hip start

	glPushMatrix();

	glColor3f(0, 0, 1);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);
	glVertex3f(0.3, -3.25 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -3.25 , 1.0);
	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);

	glEnd();

	glPopMatrix();

	//Hip end

	//left leg start

	glPushMatrix();

	glRotatef(_angle,1.0,1.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(-0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(0.0, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//left leg end

	//Right leg start

	glPushMatrix();

	glRotatef(-_angle,1.0,1.0,0.0);

	glColor3f(0, 0, 1);

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(0.9, -4.5 , 1.0);
	glVertex3f(1.5, -4.5 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(1.2, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//Right leg end

	//Eyes start

	//left eye begin

	glPushMatrix();

	glTranslatef(0.3,0.1,1);

	glColor3f(0,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//left eye end

	glPopMatrix();

	//right eye begin

	glPushMatrix();

	glTranslatef(1,0.1,1);

	glColor3f(0,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//right eye end

	glPopMatrix();

	//Eyes end

	//Mouth begin

	glPushMatrix();

	glTranslatef(-0.6,-0.4,1);

	glColor3f(0,0,0);

    glBegin(GL_QUADS);

    glVertex3f(1,0,1);
    glVertex3f(1.5,0,1);
    glVertex3f(1.5,0.1,1);
    glVertex3f(1,0.1,1);

    glEnd();

    glPopMatrix();

	//Mouth end

	 //blood points start

	 //1 start

    glPushMatrix();

    glTranslatef(-.6,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //1 end

    //2 start

    glPushMatrix();

    glTranslatef(-.2,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //2 end

    //3 start

    glPushMatrix();

    glTranslatef(-.3,-.9,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //3 end

     //4 start

    glPushMatrix();

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //4 end

     //5 start

    glPushMatrix();

    glTranslatef(-.8,-1.3,1);
    glScalef(0.8,.9,.5);

    glBegin(GL_POLYGON);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.3,-0.5,1);
    //glVertex3f(1.7,-0.5,1);
    glVertex3f(2,0,1);
    glVertex3f(1.7,0.5,1);
    glVertex3f(1.3,0.5,1);

    glEnd();

    glPopMatrix();

    //5 end

    //6 start

    glPushMatrix();

    glTranslatef(-.3,-1.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //6 end

    //7 start

    glPushMatrix();

    glTranslatef(-.3,-1.8,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //7 end

    //8 start

    glPushMatrix();

    glTranslatef(-.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //8 end

    //9 start

    glPushMatrix();

    glTranslatef(-.5,-2.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //9 end

    //10 start

    glPushMatrix();

    glTranslatef(.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //10 end

    //11 start

    glPushMatrix();

    glTranslatef(.6,-2.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //11 end

    //12 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //12 end

    //13 start

    glPushMatrix();

    glTranslatef(.7,-3.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //13 end

    //14 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //14 end

    //15 start

    glPushMatrix();

    glTranslatef(-0.5,-2.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //15 end

    //16 start

    glPushMatrix();

    glTranslatef(-1,-3.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //16 end

    //17 start

    glPushMatrix();

    glTranslatef(-.2,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //17 end

    //18 start

    glPushMatrix();

    glTranslatef(-.2,-1.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //18 end

    //19 start

    glPushMatrix();

    glTranslatef(-.1,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //19 end

    //20 start

    glPushMatrix();

    glTranslatef(-1.5,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //20 end

    //21 start

    glPushMatrix();

    glTranslatef(-1.8,-1.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //21 end

    //22 start

    glPushMatrix();

    glTranslatef(-1.8,-2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //22 end

    //23 start

    glPushMatrix();

    glTranslatef(.8,-1.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //23 end

    //24 start

    glPushMatrix();

    glTranslatef(.7,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //24 end

    //blood points end

    glPopMatrix();

	//zombie drawing end

	//enemy end
}

void zombie2()
{
    //enemy start

    glPushMatrix();

    glTranslatef(zombie2x, zombie2y, 0);

    float cal_PlayerY = roundf((playerY*100)/100);
    float cal_PlayerX = roundf((playerX*100)/100);
    float cal_Zombie2x = roundf((zombie2x*100)/100);
    float cal_Zombie2y = roundf((zombie2y*100)/100);

    if((cal_Zombie2y >= cal_PlayerY-0.1) && (cal_Zombie2y <= cal_PlayerY+0.1)) //Checking y-axis range
    {
        if(cal_Zombie2x > cal_PlayerX+0.15)
        {
            glRotatef(-30, 0.0, 1.0, 0.0); //Rotate left
        }
        else if(cal_Zombie2x < cal_PlayerX-0.15)
        {
            glRotatef(30, 0.0, 1.0, 0.0); //Rotate Right
        }
        else //collision
        {
            if(zombie2x > playerX) //move zombie & player a bit
            {
                zombie2x+=0.2;
                playerX-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie2x-=0.2;
                playerX+=0.1;
            }

            cout<<"Col\n";

            mciSendString("close zomBite2", NULL, 0, NULL); //closing the song file
            mciSendString("open \"bite2.mp3\" type mpegvideo alias zomBite2", NULL, 0, NULL); //open the mp3 file
            mciSendString("play zombite2", NULL, 0, NULL); //repeat

            playerHit++;

            if(playerHit == 6)
            {
                gameover = true;
                gCount = false;
            }
        }
    }
    else
    {
        if((cal_Zombie2y < cal_PlayerY-0.15))
        {
            glRotatef(180, 0.0, 1.0, 0.0); //Rotate Backward
        }
        else
        {
            glRotatef(0, 0.0, 1.0, 0.0); //Rotate Forward
        }
    }

    //zombie2 to other zombie collision start
    if(zombie1State && (cal_Zombie2y >= zombie1y-0.3) && (cal_Zombie2y <= zombie1y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie2x > zombie1x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie2x < zombie1x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie2x > zombie1x) //move zombie & player a bit
            {
                zombie2x+=0.2;
                zombie1x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie2x-=0.2;
                zombie1x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie3State && (cal_Zombie2y >= zombie3y-0.3) && (cal_Zombie2y <= zombie3y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie2x > zombie3x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie2x < zombie3x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie2x > zombie3x) //move zombie & player a bit
            {
                zombie2x+=0.2;
                zombie3x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie2x-=0.2;
                zombie3x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie4State && (cal_Zombie2y >= zombie4y-0.3) && (cal_Zombie2y <= zombie4y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie2x > zombie4x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie2x < zombie4x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie2x > zombie4x) //move zombie & player a bit
            {
                zombie2x+=0.2;
                zombie4x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie2x-=0.2;
                zombie4x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    //zombie2 to other zombie collision end

    glScalef(0.17,0.17,0.17);

    //zombie chasing start
    if(playerX > zombie2x)
            zombie2x+=(0.005+zombieSpeedControl);
        else
            zombie2x-=(0.005+zombieSpeedControl);

        if(playerY > zombie2y)
            zombie2y+=(0.005+zombieSpeedControl);
        else
            zombie2y-=(0.005+zombieSpeedControl);

        //zombie chasing end

        //zombie drawing start

    glColor3f(.85, .64, .13);

    //Head start
    glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, 0.0, 1.0);
	glVertex3f(-0.1, 0.5 , 1.0);
	glVertex3f(0.0, 0.5 , 1.0);

	glVertex3f(0.0, 0.6 , 1.0);
	glVertex3f(0.1, 0.6 , 1.0);

	glVertex3f(0.1, 0.7 , 1.0);
	glVertex3f(0.2, 0.7 , 1.0);

	glVertex3f(0.2, 0.8 , 1.0);
	glVertex3f(0.3, 0.8 , 1.0);

	glVertex3f(0.3, 0.9 , 1.0);
	glVertex3f(0.4, 0.9 , 1.0);

	glVertex3f(0.4, 1.0 , 1.0);
	glVertex3f(0.5, 1.0 , 1.0);

	glVertex3f(1.0, 1.0 , 1.0);

	glVertex3f(1.0, 0.9 , 1.0);
	glVertex3f(1.1, 0.9 , 1.0);

	glVertex3f(1.1, 0.8 , 1.0);
	glVertex3f(1.2, 0.8 , 1.0);

	glVertex3f(1.2, 0.7 , 1.0);
	glVertex3f(1.3, 0.7 , 1.0);

	glVertex3f(1.3, 0.6 , 1.0);
	glVertex3f(1.4, 0.6 , 1.0);

	glVertex3f(1.4, 0.5 , 1.0);
	glVertex3f(1.5, 0.5 , 1.0);

	glVertex3f(1.5, 0.0 , 1.0);

	glVertex3f(1.4, 0.0 , 1.0);
	glVertex3f(1.4, -0.1 , 1.0);

	glVertex3f(1.3, -0.1 , 1.0);
	glVertex3f(1.3, -0.2 , 1.0);

	glVertex3f(1.2, -0.2 , 1.0);
	glVertex3f(1.2, -0.3 , 1.0);

	glVertex3f(1.1, -0.3 , 1.0);
	glVertex3f(1.1, -0.4 , 1.0);

	glVertex3f(1.0, -0.4 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0 , 1.0);
	glVertex3f(0.0, -0.1 , 1.0);
	glVertex3f(0.1, -0.1 , 1.0);

	glVertex3f(0.1, -0.2 , 1.0);
	glVertex3f(0.2, -0.2 , 1.0);

	glVertex3f(0.2, -0.3 , 1.0);
	glVertex3f(0.3, -0.3 , 1.0);

	glVertex3f(0.3, -0.4 , 1.0);
	glVertex3f(0.4, -0.4 , 1.0);

	glVertex3f(0.4, -0.5 , 1.0);
	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	//Head end

	//body start

	glColor3f(.85, .71, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(0.5, -0.5 , 1.0);
	glVertex3f(0.5, -0.7 , 1.0);
	glVertex3f(-0.3, -0.8 , 1.0);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);
	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(0.7, -0.7 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glEnd();

	//body end

	//left hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(-0.3, -0.8 , 1.0);
	glVertex3f(-1.0, -0.8 , 1.0);
	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-0.3, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(-_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-1.0, -2.5 , 1.0);
	glVertex3f(-0.5, -2.5 , 1.0);
	glVertex3f(-0.5, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.9, -2.5 , 1.0);
	glVertex3f(-0.9, -2.7 , 1.0);
	glVertex3f(-0.8, -2.7 , 1.0);
	glVertex3f(-0.8, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(-0.7, -2.5 , 1.0);
	glVertex3f(-0.7, -2.7 , 1.0);
	glVertex3f(-0.6, -2.7 , 1.0);
	glVertex3f(-0.6, -2.5 , 1.0);

	glEnd();

	//thumb end

    glPopMatrix();

	//left hand end

	//right hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(2.2, -0.8 , 1.0);
	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(1.5, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(2.2, -2.5 , 1.0);
	glVertex3f(1.7, -2.5 , 1.0);
	glVertex3f(1.7, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(1.8, -2.5 , 1.0);
	glVertex3f(1.8, -2.7 , 1.0);
	glVertex3f(1.9, -2.7 , 1.0);
	glVertex3f(1.9, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(2.0, -2.5 , 1.0);
	glVertex3f(2.0, -2.7 , 1.0);
	glVertex3f(2.1, -2.7 , 1.0);
	glVertex3f(2.1, -2.5 , 1.0);

	glEnd();

	//thumb end

	glPopMatrix();

	//right hand end

	//Hip start

	glPushMatrix();

	glColor3f(1, 0, 0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);
	glVertex3f(0.3, -3.25 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -3.25 , 1.0);
	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);

	glEnd();

	glPopMatrix();

	//Hip end

	//left leg start

	glPushMatrix();
	glColor3f(1, 0, 0);

	glRotatef(_angle,1.0,1.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(-0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(0.0, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//left leg end

	//Right leg start

	glPushMatrix();

	glRotatef(-_angle,1.0,1.0,0.0);

	glColor3f(0, 0, 1);

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(0.9, -4.5 , 1.0);
	glVertex3f(1.5, -4.5 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(1.2, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//Right leg end

	//Eyes start

	//left eye begin

	glPushMatrix();

	glTranslatef(0.3,0.1,1);

	glColor3f(1,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//left eye end

	glPopMatrix();

	//right eye begin

	glPushMatrix();

	glTranslatef(1,0.1,1);

	glColor3f(1,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//right eye end

	glPopMatrix();

	//Eyes end

	//Mouth begin

	glPushMatrix();

	glTranslatef(-0.6,-0.4,1);

	glColor3f(0,0,0);

    glBegin(GL_QUADS);

    glVertex3f(1,0,1);
    glVertex3f(1.5,0,1);
    glVertex3f(1.5,0.1,1);
    glVertex3f(1,0.1,1);

    glEnd();

    glPopMatrix();

	//Mouth end

	 //blood points start

	 //1 start

    glPushMatrix();

    glTranslatef(-.6,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //1 end

    //2 start

    glPushMatrix();

    glTranslatef(-.2,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //2 end

    //3 start

    glPushMatrix();

    glTranslatef(-.3,-.9,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //3 end

     //4 start

    glPushMatrix();

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //4 end

     //5 start

    glPushMatrix();

    glTranslatef(-.8,-1.3,1);
    glScalef(0.8,.9,.5);

    glBegin(GL_POLYGON);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.3,-0.5,1);
    //glVertex3f(1.7,-0.5,1);
    glVertex3f(2,0,1);
    glVertex3f(1.7,0.5,1);
    glVertex3f(1.3,0.5,1);

    glEnd();

    glPopMatrix();

    //5 end

    //6 start

    glPushMatrix();

    glTranslatef(-.3,-1.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //6 end

    //7 start

    glPushMatrix();

    glTranslatef(-.3,-1.8,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //7 end

    //8 start

    glPushMatrix();

    glTranslatef(-.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //8 end

    //9 start

    glPushMatrix();

    glTranslatef(-.5,-2.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //9 end

    //10 start

    glPushMatrix();

    glTranslatef(.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //10 end

    //11 start

    glPushMatrix();

    glTranslatef(.6,-2.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //11 end

    //12 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //12 end

    //13 start

    glPushMatrix();

    glTranslatef(.7,-3.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //13 end

    //14 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //14 end

    //15 start

    glPushMatrix();

    glTranslatef(-0.5,-2.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //15 end

    //16 start

    glPushMatrix();

    glTranslatef(-1,-3.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //16 end

    //17 start

    glPushMatrix();

    glTranslatef(-.2,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //17 end

    //18 start

    glPushMatrix();

    glTranslatef(-.2,-1.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //18 end

    //19 start

    glPushMatrix();

    glTranslatef(-.1,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //19 end

    //20 start

    glPushMatrix();

    glTranslatef(-1.5,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //20 end

    //21 start

    glPushMatrix();

    glTranslatef(-1.8,-1.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //21 end

    //22 start

    glPushMatrix();

    glTranslatef(-1.8,-2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //22 end

    //23 start

    glPushMatrix();

    glTranslatef(.8,-1.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //23 end

    //24 start

    glPushMatrix();

    glTranslatef(.7,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //24 end

    //blood points end

    glPopMatrix();

	//zombie drawing end

	//enemy end
}

void zombie3()
{
    //enemy start

    glPushMatrix();

    glTranslatef(zombie3x, zombie3y, 0);

    float cal_PlayerY = roundf((playerY*100)/100);
    float cal_PlayerX = roundf((playerX*100)/100);
    float cal_Zombie3x = roundf((zombie3x*100)/100);
    float cal_Zombie3y = roundf((zombie3y*100)/100);

    if((cal_Zombie3y >= cal_PlayerY-0.1) && (cal_Zombie3y <= cal_PlayerY+0.1)) //Checking y-axis range
    {
        if(cal_Zombie3x > cal_PlayerX+0.15)
        {
            glRotatef(-30, 0.0, 1.0, 0.0); //Rotate left
        }
        else if(cal_Zombie3x < cal_PlayerX-0.15)
        {
            glRotatef(30, 0.0, 1.0, 0.0); //Rotate Right
        }
        else //collision
        {
            if(zombie3x > playerX) //move zombie & player a bit
            {
                zombie3x+=0.2;
                playerX-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie3x-=0.2;
                playerX+=0.1;
            }

            cout<<"Col\n";

            mciSendString("close zomBite3", NULL, 0, NULL); //closing the song file
            mciSendString("open \"bite3.mp3\" type mpegvideo alias zomBite3", NULL, 0, NULL); //open the mp3 file
            mciSendString("play zombite3", NULL, 0, NULL); //repeat

            playerHit++;

            if(playerHit == 6)
            {
                gameover = true;
                gCount = false;
            }
        }
    }
    else
    {
        if((cal_Zombie3y < cal_PlayerY-0.3))
        {
            glRotatef(180, 0.0, 1.0, 0.0); //Rotate Backward
        }
        else
        {
            glRotatef(0, 0.0, 1.0, 0.0); //Rotate Forward
        }
    }

    //zombie3 to other zombie collision start
    if(zombie1State && (cal_Zombie3y >= zombie1y-0.3) && (cal_Zombie3y <= zombie1y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie3x > zombie1x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie3x < zombie1x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie3x > zombie1x) //move zombie & player a bit
            {
                zombie3x+=0.2;
                zombie1x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie3x-=0.2;
                zombie1x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie2State && (cal_Zombie3y >= zombie2y-0.3) && (cal_Zombie3y <= zombie2y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie3x > zombie2x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie3x < zombie2x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie3x > zombie2x) //move zombie & player a bit
            {
                zombie3x+=0.2;
                zombie2x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie3x-=0.2;
                zombie2x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie4State && (cal_Zombie3y >= zombie4y-0.3) && (cal_Zombie3y <= zombie4y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie3x > zombie4x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie3x < zombie4x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie3x > zombie4x) //move zombie & player a bit
            {
                zombie3x+=0.2;
                zombie4x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie3x-=0.2;
                zombie4x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    //zombie3 to other zombie collision end

    glScalef(0.17,0.17,0.17);

    //zombie chasing start
    if(playerX > zombie3x)
            zombie3x+=(0.006+zombieSpeedControl);
        else
            zombie3x-=(0.006+zombieSpeedControl);

        if(playerY > zombie3y)
            zombie3y+=(0.006+zombieSpeedControl);
        else
            zombie3y-=(0.006+zombieSpeedControl);

        //zombie chasing end

        //zombie drawing start

    glColor3f(.85, .64, .13);

    //Head start
    glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, 0.0, 1.0);
	glVertex3f(-0.1, 0.5 , 1.0);
	glVertex3f(0.0, 0.5 , 1.0);

	glVertex3f(0.0, 0.6 , 1.0);
	glVertex3f(0.1, 0.6 , 1.0);

	glVertex3f(0.1, 0.7 , 1.0);
	glVertex3f(0.2, 0.7 , 1.0);

	glVertex3f(0.2, 0.8 , 1.0);
	glVertex3f(0.3, 0.8 , 1.0);

	glVertex3f(0.3, 0.9 , 1.0);
	glVertex3f(0.4, 0.9 , 1.0);

	glVertex3f(0.4, 1.0 , 1.0);
	glVertex3f(0.5, 1.0 , 1.0);

	glVertex3f(1.0, 1.0 , 1.0);

	glVertex3f(1.0, 0.9 , 1.0);
	glVertex3f(1.1, 0.9 , 1.0);

	glVertex3f(1.1, 0.8 , 1.0);
	glVertex3f(1.2, 0.8 , 1.0);

	glVertex3f(1.2, 0.7 , 1.0);
	glVertex3f(1.3, 0.7 , 1.0);

	glVertex3f(1.3, 0.6 , 1.0);
	glVertex3f(1.4, 0.6 , 1.0);

	glVertex3f(1.4, 0.5 , 1.0);
	glVertex3f(1.5, 0.5 , 1.0);

	glVertex3f(1.5, 0.0 , 1.0);

	glVertex3f(1.4, 0.0 , 1.0);
	glVertex3f(1.4, -0.1 , 1.0);

	glVertex3f(1.3, -0.1 , 1.0);
	glVertex3f(1.3, -0.2 , 1.0);

	glVertex3f(1.2, -0.2 , 1.0);
	glVertex3f(1.2, -0.3 , 1.0);

	glVertex3f(1.1, -0.3 , 1.0);
	glVertex3f(1.1, -0.4 , 1.0);

	glVertex3f(1.0, -0.4 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0 , 1.0);
	glVertex3f(0.0, -0.1 , 1.0);
	glVertex3f(0.1, -0.1 , 1.0);

	glVertex3f(0.1, -0.2 , 1.0);
	glVertex3f(0.2, -0.2 , 1.0);

	glVertex3f(0.2, -0.3 , 1.0);
	glVertex3f(0.3, -0.3 , 1.0);

	glVertex3f(0.3, -0.4 , 1.0);
	glVertex3f(0.4, -0.4 , 1.0);

	glVertex3f(0.4, -0.5 , 1.0);
	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	//Head end

	//body start

	glColor3f(.85, .71, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(0.5, -0.5 , 1.0);
	glVertex3f(0.5, -0.7 , 1.0);
	glVertex3f(-0.3, -0.8 , 1.0);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);
	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(0.7, -0.7 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glEnd();

	//body end

	//left hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(-0.3, -0.8 , 1.0);
	glVertex3f(-1.0, -0.8 , 1.0);
	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-0.3, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(-_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-1.0, -2.5 , 1.0);
	glVertex3f(-0.5, -2.5 , 1.0);
	glVertex3f(-0.5, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.9, -2.5 , 1.0);
	glVertex3f(-0.9, -2.7 , 1.0);
	glVertex3f(-0.8, -2.7 , 1.0);
	glVertex3f(-0.8, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(-0.7, -2.5 , 1.0);
	glVertex3f(-0.7, -2.7 , 1.0);
	glVertex3f(-0.6, -2.7 , 1.0);
	glVertex3f(-0.6, -2.5 , 1.0);

	glEnd();

	//thumb end

    glPopMatrix();

	//left hand end

	//right hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(2.2, -0.8 , 1.0);
	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(1.5, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(2.2, -2.5 , 1.0);
	glVertex3f(1.7, -2.5 , 1.0);
	glVertex3f(1.7, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(1.8, -2.5 , 1.0);
	glVertex3f(1.8, -2.7 , 1.0);
	glVertex3f(1.9, -2.7 , 1.0);
	glVertex3f(1.9, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(2.0, -2.5 , 1.0);
	glVertex3f(2.0, -2.7 , 1.0);
	glVertex3f(2.1, -2.7 , 1.0);
	glVertex3f(2.1, -2.5 , 1.0);

	glEnd();

	//thumb end

	glPopMatrix();

	//right hand end

	//Hip start

	glPushMatrix();

	glColor3f(0, 0.55, 0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);
	glVertex3f(0.3, -3.25 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -3.25 , 1.0);
	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);

	glEnd();

	glPopMatrix();

	//Hip end

	//left leg start

	glPushMatrix();
	//glColor3f(0, 0, 1);

	glRotatef(_angle,1.0,1.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(-0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(0.0, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//left leg end

	//Right leg start

	glPushMatrix();

	glRotatef(-_angle,1.0,1.0,0.0);

	glColor3f(0, 0.55, 0);

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(0.9, -4.5 , 1.0);
	glVertex3f(1.5, -4.5 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(1.2, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//Right leg end

	//Eyes start

	//left eye begin

	glPushMatrix();

	glTranslatef(0.3,0.1,1);

	glColor3f(0,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//left eye end

	glPopMatrix();

	//right eye begin

	glPushMatrix();

	glTranslatef(1,0.1,1);

	glColor3f(1,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//right eye end

	glPopMatrix();

	//Eyes end

	//Mouth begin

	glPushMatrix();

	glTranslatef(-0.6,-0.4,1);

	glColor3f(0,0,0);

    glBegin(GL_QUADS);

    glVertex3f(1,0,1);
    glVertex3f(1.5,0,1);
    glVertex3f(1.5,0.1,1);
    glVertex3f(1,0.1,1);

    glEnd();

    glPopMatrix();

	//Mouth end

	 //blood points start

	 //1 start

    glPushMatrix();

    glTranslatef(-.6,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //1 end

    //2 start

    glPushMatrix();

    glTranslatef(-.2,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //2 end

    //3 start

    glPushMatrix();

    glTranslatef(-.3,-.9,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //3 end

     //4 start

    glPushMatrix();

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //4 end

     //5 start

    glPushMatrix();

    glTranslatef(-.15,-1.3,0);
    glScalef(0.8,.9,.5);

    glBegin(GL_POLYGON);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.3,-0.5,1);
    //glVertex3f(1.7,-0.5,1);
    glVertex3f(2,0,1);
    glVertex3f(1.7,0.5,1);
    glVertex3f(1.3,0.5,1);

    glEnd();

    glPopMatrix();

    //5 end

    //6 start

    glPushMatrix();

    glTranslatef(-.3,-1.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //6 end

    //7 start

    glPushMatrix();

    glTranslatef(-.3,-1.8,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //7 end

    //8 start

    glPushMatrix();

    glTranslatef(-.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //8 end

    //9 start

    glPushMatrix();

    glTranslatef(-.5,-2.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //9 end

    //10 start

    glPushMatrix();

    glTranslatef(.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //10 end

    //11 start

    glPushMatrix();

    glTranslatef(.6,-2.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //11 end

    //12 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //12 end

    //13 start

    glPushMatrix();

    glTranslatef(.7,-3.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //13 end

    //14 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //14 end

    //15 start

    glPushMatrix();

    glTranslatef(-0.5,-2.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //15 end

    //16 start

    glPushMatrix();

    glTranslatef(-1,-3.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //16 end

    //17 start

    glPushMatrix();

    glTranslatef(-.2,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //17 end

    //18 start

    glPushMatrix();

    glTranslatef(-.2,-1.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //18 end

    //19 start

    glPushMatrix();

    glTranslatef(-.1,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //19 end

    //20 start

    glPushMatrix();

    glTranslatef(-1.5,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //20 end

    //21 start

    glPushMatrix();

    glTranslatef(-1.8,-1.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //21 end

    //22 start

    glPushMatrix();

    glTranslatef(-1.8,-2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //22 end

    //23 start

    glPushMatrix();

    glTranslatef(.8,-1.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //23 end

    //24 start

    glPushMatrix();

    glTranslatef(.7,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //24 end

    //blood points end

    glPopMatrix();

	//zombie drawing end

	//enemy end
}

void zombie4()
{
    //enemy start

    glPushMatrix();

    glTranslatef(zombie4x, zombie4y, 0);

    float cal_PlayerY = roundf((playerY*100)/100);
    float cal_PlayerX = roundf((playerX*100)/100);
    float cal_Zombie4x = roundf((zombie4x*100)/100);
    float cal_Zombie4y = roundf((zombie4y*100)/100);

    if((cal_Zombie4y >= cal_PlayerY-0.1) && (cal_Zombie4y <= cal_PlayerY+0.1)) //Checking y-axis range
    {
        if(cal_Zombie4x > cal_PlayerX+0.15)
        {
            glRotatef(-30, 0.0, 1.0, 0.0); //Rotate left
        }
        else if(cal_Zombie4x < cal_PlayerX-0.15)
        {
            glRotatef(30, 0.0, 1.0, 0.0); //Rotate Right
        }
        else //collision
        {
            if(zombie4x > playerX) //move zombie & player a bit
            {
                zombie4x+=0.2;
                playerX-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie4x-=0.2;
                playerX+=0.1;
            }

            cout<<"Col\n";

            mciSendString("close zomBite4", NULL, 0, NULL); //closing the song file
            mciSendString("open \"bite4.mp3\" type mpegvideo alias zomBite4", NULL, 0, NULL); //open the mp3 file
            mciSendString("play zombite4", NULL, 0, NULL); //repeat

            playerHit++;

            if(playerHit == 6)
            {
                gameover = true;
                gCount = false;
            }
        }
    }
    else
    {
        if((cal_Zombie4y < cal_PlayerY-0.15))
        {
            glRotatef(180, 0.0, 1.0, 0.0); //Rotate Backward
        }
        else
        {
            glRotatef(0, 0.0, 1.0, 0.0); //Rotate Forward
        }
    }

    //zombie4 to other zombie collision start
    if(zombie1State && (cal_Zombie4y >= zombie1y-0.3) && (cal_Zombie4y <= zombie1y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie4x > zombie1x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie4x < zombie1x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie4x > zombie1x) //move zombie & player a bit
            {
                zombie4x+=0.2;
                zombie1x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie4x-=0.2;
                zombie1x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie2State && (cal_Zombie4y >= zombie2y-0.3) && (cal_Zombie4y <= zombie2y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie4x > zombie2x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie4x < zombie2x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie4x > zombie2x) //move zombie & player a bit
            {
                zombie4x+=0.2;
                zombie2x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie4x-=0.2;
                zombie2x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    if(zombie3State && (cal_Zombie4y >= zombie3y-0.3) && (cal_Zombie4y <= zombie3y+0.3)) //Checking y-axis range
    {
        if(cal_Zombie4x > zombie3x+0.3)
        {
            //do nothing
        }
        else if(cal_Zombie4x < zombie3x-0.3)
        {
            //do nothing
        }
        else //collision
        {
            if(zombie4x > zombie3x) //move zombie & player a bit
            {
                zombie4x+=0.2;
                zombie3x-=0.1;
            }
            else //move zombie & player a bit
            {
                zombie4x-=0.2;
                zombie3x+=0.1;
            }

            cout<<"ZomCol\n";

            //mciSendString("close zomBite1", NULL, 0, NULL); //closing the song file
            //mciSendString("open \"bite1.mp3\" type mpegvideo alias zomBite1", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play zombite1", NULL, 0, NULL); //repeat
        }
    }

    //zombie4 to other zombie collision end

    glScalef(0.17,0.17,0.17);

    //zombie chasing start
    if(playerX > zombie4x)
            zombie4x+=(0.009+zombieSpeedControl);
        else
            zombie4x-=(0.009+zombieSpeedControl);

        if(playerY > zombie4y)
            zombie4y+=(0.009+zombieSpeedControl);
        else
            zombie4y-=(0.009+zombieSpeedControl);

        //zombie chasing end

        //zombie drawing start

    glColor3f(.85, .64, .13);

    //Head start
    glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(-0.1, 0.0, 1.0);
	glVertex3f(-0.1, 0.5 , 1.0);
	glVertex3f(0.0, 0.5 , 1.0);

	glVertex3f(0.0, 0.6 , 1.0);
	glVertex3f(0.1, 0.6 , 1.0);

	glVertex3f(0.1, 0.7 , 1.0);
	glVertex3f(0.2, 0.7 , 1.0);

	glVertex3f(0.2, 0.8 , 1.0);
	glVertex3f(0.3, 0.8 , 1.0);

	glVertex3f(0.3, 0.9 , 1.0);
	glVertex3f(0.4, 0.9 , 1.0);

	glVertex3f(0.4, 1.0 , 1.0);
	glVertex3f(0.5, 1.0 , 1.0);

	glVertex3f(1.0, 1.0 , 1.0);

	glVertex3f(1.0, 0.9 , 1.0);
	glVertex3f(1.1, 0.9 , 1.0);

	glVertex3f(1.1, 0.8 , 1.0);
	glVertex3f(1.2, 0.8 , 1.0);

	glVertex3f(1.2, 0.7 , 1.0);
	glVertex3f(1.3, 0.7 , 1.0);

	glVertex3f(1.3, 0.6 , 1.0);
	glVertex3f(1.4, 0.6 , 1.0);

	glVertex3f(1.4, 0.5 , 1.0);
	glVertex3f(1.5, 0.5 , 1.0);

	glVertex3f(1.5, 0.0 , 1.0);

	glVertex3f(1.4, 0.0 , 1.0);
	glVertex3f(1.4, -0.1 , 1.0);

	glVertex3f(1.3, -0.1 , 1.0);
	glVertex3f(1.3, -0.2 , 1.0);

	glVertex3f(1.2, -0.2 , 1.0);
	glVertex3f(1.2, -0.3 , 1.0);

	glVertex3f(1.1, -0.3 , 1.0);
	glVertex3f(1.1, -0.4 , 1.0);

	glVertex3f(1.0, -0.4 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.0 , 1.0);
	glVertex3f(0.0, -0.1 , 1.0);
	glVertex3f(0.1, -0.1 , 1.0);

	glVertex3f(0.1, -0.2 , 1.0);
	glVertex3f(0.2, -0.2 , 1.0);

	glVertex3f(0.2, -0.3 , 1.0);
	glVertex3f(0.3, -0.3 , 1.0);

	glVertex3f(0.3, -0.4 , 1.0);
	glVertex3f(0.4, -0.4 , 1.0);

	glVertex3f(0.4, -0.5 , 1.0);
	glVertex3f(0.5, -0.5 , 1.0);

	glEnd();

	//Head end

	//body start

	glColor3f(.85, .71, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(0.5, -0.5 , 1.0);
	glVertex3f(0.5, -0.7 , 1.0);
	glVertex3f(-0.3, -0.8 , 1.0);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);
	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(0.7, -0.7 , 1.0);
	glVertex3f(1.0, -0.5 , 1.0);

	glEnd();

	//body end

	//left hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(-0.3, -0.8 , 1.0);
	glVertex3f(-1.0, -0.8 , 1.0);
	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-0.3, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(-_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-1.0, -1.3 , 1.0);
	glVertex3f(-1.0, -2.5 , 1.0);
	glVertex3f(-0.5, -2.5 , 1.0);
	glVertex3f(-0.5, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.9, -2.5 , 1.0);
	glVertex3f(-0.9, -2.7 , 1.0);
	glVertex3f(-0.8, -2.7 , 1.0);
	glVertex3f(-0.8, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(-0.7, -2.5 , 1.0);
	glVertex3f(-0.7, -2.7 , 1.0);
	glVertex3f(-0.6, -2.7 , 1.0);
	glVertex3f(-0.6, -2.5 , 1.0);

	glEnd();

	//thumb end

    glPopMatrix();

	//left hand end

	//right hand start

	glColor3f(.85, .64, .13);

    glBegin(GL_POLYGON);

    //1st part start

	glVertex3f(1.5, -0.8 , 1.0);
	glVertex3f(2.2, -0.8 , 1.0);
	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(1.5, -1.3 , 1.0);

	glEnd();

	//1st part end

	//2nd part start

	glPushMatrix();

	glRotatef(_angle,1.0,0.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(2.2, -1.3 , 1.0);
	glVertex3f(2.2, -2.5 , 1.0);
	glVertex3f(1.7, -2.5 , 1.0);
	glVertex3f(1.7, -1.3 , 1.0);

	glEnd();

	//2nd part end

	//thumb start

    glColor3f(1,0,0);

	glBegin(GL_POLYGON);

	glVertex3f(1.8, -2.5 , 1.0);
	glVertex3f(1.8, -2.7 , 1.0);
	glVertex3f(1.9, -2.7 , 1.0);
	glVertex3f(1.9, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(2.0, -2.5 , 1.0);
	glVertex3f(2.0, -2.7 , 1.0);
	glVertex3f(2.1, -2.7 , 1.0);
	glVertex3f(2.1, -2.5 , 1.0);

	glEnd();

	//thumb end

	glPopMatrix();

	//right hand end

	//Hip start

	glPushMatrix();

	glColor3f(0.3, .25, .35);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -2.5 , 1.0);
	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);
	glVertex3f(0.3, -3.25 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);
	glVertex3f(1.5, -2.5 , 1.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -3.25 , 1.0);
	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);
	glVertex3f(1.5, -3.25 , 1.0);

	glEnd();

	glPopMatrix();

	//Hip end

	//left leg start

	glPushMatrix();
	glColor3f(0, 0, 1);

	glRotatef(_angle,1.0,1.0,0.0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.3, -4.0 , 1.0);
	glVertex3f(-0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.5 , 1.0);
	glVertex3f(0.3, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(0.0, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//left leg end

	//Right leg start

	glPushMatrix();

	glRotatef(-_angle,1.0,1.0,0.0);

	glColor3f(0, 0, 1);

	glBegin(GL_POLYGON);

	glVertex3f(0.9, -4.0 , 1.0);
	glVertex3f(0.9, -4.5 , 1.0);
	glVertex3f(1.5, -4.5 , 1.0);
	glVertex3f(1.5, -4.0 , 1.0);

	glEnd();

	//Leg part start

    glPushMatrix();

    glTranslatef(1.2, -4.72, 1);
    glScalef(0.8,1,0.5);

    glColor3f(.85, .64, .13);
	glutSolidCube(.5);

	glPopMatrix();

	//Leg part end

	glPopMatrix();

	//Right leg end

	//Eyes start

	//left eye begin

	glPushMatrix();

	glTranslatef(0.3,0.1,1);

	glColor3f(1,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//left eye end

	glPopMatrix();

	//right eye begin

	glPushMatrix();

	glTranslatef(1,0.1,1);

	glColor3f(0,0,0);

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x,y,1);
	}
	glEnd();

	//right eye end

	glPopMatrix();

	//Eyes end

	//Mouth begin

	glPushMatrix();

	glTranslatef(-0.6,-0.4,1);

	glColor3f(.25,0,0);

    glBegin(GL_QUADS);

    glVertex3f(1,0,1);
    glVertex3f(1.5,0,1);
    glVertex3f(1.5,0.1,1);
    glVertex3f(1,0.1,1);

    glEnd();

    glPopMatrix();

	//Mouth end

	 //blood points start

	 //1 start

    glPushMatrix();

    glTranslatef(-.6,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //1 end

    //2 start

    glPushMatrix();

    glTranslatef(-.2,-.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //2 end

    //3 start

    glPushMatrix();

    glTranslatef(-.3,-.9,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //3 end

     //4 start

    glPushMatrix();

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //4 end

     //5 start // larger one

    glPushMatrix();

    glTranslatef(-.8,-1.3,0);
    glScalef(0.8,.9,.5);

    glBegin(GL_POLYGON);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.3,-0.5,1);
    //glVertex3f(1.7,-0.5,1);
    glVertex3f(2,0,1);
    glVertex3f(1.7,0.5,1);
    glVertex3f(1.3,0.5,1);

    glEnd();

    glPopMatrix();

    //5 end

    //6 start

    glPushMatrix();

    glTranslatef(-.3,-1.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //6 end

    //7 start

    glPushMatrix();

    glTranslatef(-.3,-1.8,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //7 end

    //8 start

    glPushMatrix();

    glTranslatef(-.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //8 end

    //9 start

    glPushMatrix();

    glTranslatef(-.5,-2.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //9 end

    //10 start

    glPushMatrix();

    glTranslatef(.5,-2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //10 end

    //11 start

    glPushMatrix();

    glTranslatef(.6,-2.4,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //11 end

    //12 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //12 end

    //13 start

    glPushMatrix();

    glTranslatef(.7,-3.2,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //13 end

    //14 start

    glPushMatrix();

    glTranslatef(.6,-2.7,1);

    glTranslatef(-.5,-.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //14 end

    //15 start

    glPushMatrix();

    glTranslatef(-0.5,-2.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //15 end

    //16 start

    glPushMatrix();

    glTranslatef(-1,-3.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //16 end

    //17 start

    glPushMatrix();

    glTranslatef(-.2,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //17 end

    //18 start

    glPushMatrix();

    glTranslatef(-.2,-1.7,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //18 end

    //19 start

    glPushMatrix();

    glTranslatef(-.1,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //19 end

    //20 start

    glPushMatrix();

    glTranslatef(-1.5,-1.3,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //20 end

    //21 start

    glPushMatrix();

    glTranslatef(-1.8,-1.8,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //21 end

    //22 start

    glPushMatrix();

    glTranslatef(-1.8,-2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //22 end

    //23 start

    glPushMatrix();

    glTranslatef(.8,-1.5,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //23 end

    //24 start

    glPushMatrix();

    glTranslatef(.7,-2.2,1);

    glBegin(GL_QUADS);

    glColor3f(1,0,0);

    glVertex3f(1,0,1);
    glVertex3f(1.1,0,1);
    glVertex3f(1.1,0.3,1);
    glVertex3f(1,0.3,1);

    glEnd();

    glPopMatrix();

    //24 end

    //blood points end

    glPopMatrix();

	//zombie drawing end

	//enemy end
}

void lifeBar()
{
    glPushMatrix(); // Main push pop start
	glTranslatef(4.0, 2.65, 0.0);
	glScalef(.3,.3,0);

        if(playerHit < 2)
        {
            //1st heart start

            //1st triangle start

            glBegin(GL_TRIANGLES);
            glColor3f(1.0,0.0,0.0);

            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.5,0.0,0.0);
            glVertex3f(0.25,0.2,0.0);

            glEnd();

            //1st triangle end

            //2nd triangle start

            glBegin(GL_TRIANGLES);

            glVertex3f(0.5,0.0,0.0);
            glVertex3f(1.0,0.0,0.0);
            glVertex3f(0.75,0.2,0.0);

            glEnd();

            //2nd triangle end

            //rectangle 1 start

            glBegin(GL_QUADS);

            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.0,-0.15,0.0);
            glVertex3f(1.0,-0.15,0.0);
            glVertex3f(1.0,0.0,0.0);

            glEnd();

            //rectangle 1 end

            if(playerHit < 1)
            {
                //rectangle 2 start

                glBegin(GL_QUADS);

                glVertex3f(0.0,-0.15,0.0);
                glVertex3f(0.0,-0.3,0.0);
                glVertex3f(1.0,-0.3,0.0);
                glVertex3f(1.0,0.0,0.0);

                glEnd();

                //rectangle 2 end

                //3rd triangle start

                glBegin(GL_TRIANGLES);

                glVertex3f(0.0,-0.3,0.0);
                glVertex3f(0.5,-0.6,0.0);
                glVertex3f(1.0,-0.3,0.0);

                glEnd();

                //3rd triangle end

                //1st heart end
            }
        }

        //2nd heart start

        glPushMatrix();
        glTranslatef(1.3, 0.0, 0.0);

        if(playerHit < 4)
        {
            //1st triangle start

            glBegin(GL_TRIANGLES);
            glColor3f(1.0,0.0,0.0);

            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.5,0.0,0.0);
            glVertex3f(0.25,0.2,0.0);

            glEnd();

            //1st triangle end

            //2nd triangle start

            glBegin(GL_TRIANGLES);

            glVertex3f(0.5,0.0,0.0);
            glVertex3f(1.0,0.0,0.0);
            glVertex3f(0.75,0.2,0.0);

            glEnd();

            //2nd triangle end

            //rectangle 1 start

            glBegin(GL_QUADS);

            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.0,-0.15,0.0);
            glVertex3f(1.0,-0.15,0.0);
            glVertex3f(1.0,0.0,0.0);

            glEnd();

            //rectangle 1 end

            if(playerHit < 3)
            {
                //rectangle 2 start

                glBegin(GL_QUADS);

                glVertex3f(0.0,-0.15,0.0);
                glVertex3f(0.0,-0.3,0.0);
                glVertex3f(1.0,-0.3,0.0);
                glVertex3f(1.0,0.0,0.0);

                glEnd();

                //rectangle 2 end

                //3rd triangle start

                glBegin(GL_TRIANGLES);

                glVertex3f(0.0,-0.3,0.0);
                glVertex3f(0.5,-0.6,0.0);
                glVertex3f(1.0,-0.3,0.0);

                glEnd();

                //3rd triangle end
            }
        }

        glPopMatrix();

        //2nd heart end

        //3rd heart start

        glPushMatrix();
        glTranslatef(2.6, 0.0, 0.0);

        if(playerHit < 6)
        {
            //1st triangle start

            glBegin(GL_TRIANGLES);
            glColor3f(1.0,0.0,0.0);

            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.5,0.0,0.0);
            glVertex3f(0.25,0.2,0.0);

            glEnd();

            //1st triangle end

            //2nd triangle start

            glBegin(GL_TRIANGLES);

            glVertex3f(0.5,0.0,0.0);
            glVertex3f(1.0,0.0,0.0);
            glVertex3f(0.75,0.2,0.0);

            glEnd();

            //2nd triangle end

            //rectangle 1 start

            glBegin(GL_QUADS);

            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.0,-0.15,0.0);
            glVertex3f(1.0,-0.15,0.0);
            glVertex3f(1.0,0.0,0.0);

            glEnd();

            //rectangle 1 end

            if(playerHit < 5)
            {
                //rectangle 2 start

                glBegin(GL_QUADS);

                glVertex3f(0.0,-0.15,0.0);
                glVertex3f(0.0,-0.3,0.0);
                glVertex3f(1.0,-0.3,0.0);
                glVertex3f(1.0,0.0,0.0);

                glEnd();

                //rectangle 2 end

                //3rd triangle start

                glBegin(GL_TRIANGLES);

                glVertex3f(0.0,-0.3,0.0);
                glVertex3f(0.5,-0.6,0.0);
                glVertex3f(1.0,-0.3,0.0);

                glEnd();

                //3rd triangle end
            }
        }

        glPopMatrix();

        //3rd heart end

	glPopMatrix(); //Main push/pop end

	glColor3f(0,1,0); //for showing colored score
}

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

	if(paused)
    {
         pauseScreen.drawText("GAME  PAUSED !!", 16, -0.65, 0.2);
    }

    if(gameover)
    {
        firstMenuFlag = false;

        //writing highscore once

        if(gCount == false)
        {
            string value; // to store high score from text file
            unsigned long int v1,v2,v3; // 3 High scores
            short c = 0;

            ifstream inFile;
            inFile.open("Highscore.txt");

            while(getline(inFile,value))
            {
                c++;

                if(c == 1)
                {
                    v1 = atoi(value.c_str());
                }
                else if(c == 2)
                {
                    v2 = atoi(value.c_str());
                }
                else if(c == 3)
                {
                    v3 = atoi(value.c_str());
                }
            }

            inFile.close();//cout<<v1<<" "<<v2<<" "<<v3<<endl;

            if(total_points > v1)
                v1 = total_points;
            else if(total_points > v2)
                v2 = total_points;
            else if(total_points > v3)
                v3 = total_points;

            //cout<<v1<<" "<<v2<<" "<<v3<<endl;

            ofstream outFile;
            outFile.open("Highscore.txt");

            value = "";
            stringstream dd;

            dd << v1;
            value = dd.str();
            value+="\n";
            dd.str("");

            dd << v2;
            value += dd.str();
            value+="\n";
            dd.str("");

            dd << v3;
            value += dd.str(); //cout<<value<<endl;

            outFile << value;


            outFile.close();

            gCount = true;
        }

        //sending score to game-over screen

        stringstream ff;
        ff << total_points;

        string points = ff.str();

        //stop birdSound
        mciSendString("stop birdSound", NULL, 0, NULL); //stopping the song
        mciSendString("close birdSound", NULL, 0, NULL); //closing the song file

         //stop zombieSound
        mciSendString("stop zombieGrowl", NULL, 0, NULL); //stopping the song
        mciSendString("close zombieGrowl", NULL, 0, NULL); //closing the song file

        //stop playing background music
        mciSendString("stop backgroundMusic", NULL, 0, NULL); //stopping the song
        mciSendString("close backgroundMusic", NULL, 0, NULL); //closing the song file

        if(gameOverSoundFlag == false)
        {
            //start game over voice
            mciSendString("close GameOverTheme", NULL, 0, NULL); //closing the song file
            mciSendString("open \"game over.mp3\" type mpegvideo alias GameOverTheme", NULL, 0, NULL); //open the mp3 file
            mciSendString("play GameOverTheme", NULL, 0, NULL); //repeat
            gameOverSoundFlag = true;
        }

        //start playing theme song
        mciSendString("open \"theme.mp3\" type mpegvideo alias themeSong", NULL, 0, NULL); //open the mp3 file
        mciSendString("play themeSong repeat", NULL, 0, NULL); //repeat

        gameEndScreen.createGameOverScreen(points, fullScreenMode); // sending score
    }
    else if(gameMenu) //creating menu
    {
        //stop birdSound
        mciSendString("stop birdSound", NULL, 0, NULL); //stopping the song
        mciSendString("close birdSound", NULL, 0, NULL); //closing the song file

        //stop zombieSound
        mciSendString("stop zombieGrowl", NULL, 0, NULL); //stopping the song
        mciSendString("close zombieGrowl", NULL, 0, NULL); //closing the song file

        //stop playing background music
        mciSendString("stop backgroundMusic", NULL, 0, NULL); //stopping the song
        mciSendString("close backgroundMusic", NULL, 0, NULL); //closing the song file

        //start playing theme song
        //mciSendString("close themeSong", NULL, 0, NULL);
        //mciSendString("open \"theme.mp3\" type mpegvideo alias themeSong", NULL, 0, NULL); //open the mp3 file
        //mciSendString("play themeSong repeat", NULL, 0, NULL); //repeat
        soundPlayingFlag = true;
        gameOverSoundFlag = false;
        menu.createMenu(firstMenuFlag);
    }
    else if(gameControlMenu)
    {
        controlScreen.createControlMenu(); //sub menu
    }
    else if(showHighScore)
    {
        highScore.createHighScoreMenu(); // sub menu
    }
    else //Game started
    {
        if(soundPlayingFlag || restartFlag)
        {
            mciSendString("stop themeSong", NULL, 0, NULL); //stopping the song
            mciSendString("close themeSong", NULL, 0, NULL); //closing the song file

            //mciSendString("open \"background.mp3\" type mpegvideo alias backgroundMusic", NULL, 0, NULL); //open the mp3 file
            //mciSendString("play backgroundMusic repeat", NULL, 0, NULL); //repeat

            mciSendString("open \"growl.mp3\" type mpegvideo alias zombieGrowl", NULL, 0, NULL); //open the mp3 file
            mciSendString("play zombieGrowl repeat", NULL, 0, NULL); //repeat

            mciSendString("open \"bird.mp3\" type mpegvideo alias birdSound", NULL, 0, NULL); //open the mp3 file
            mciSendString("play birdSound repeat", NULL, 0, NULL); //repeat

            soundPlayingFlag = false;
            restartFlag = false;
        }

        firstMenuFlag = true;

        //player push/pop start
        glPushMatrix(); //Save the current state of transformations


        glTranslatef(playerX, playerY, 1.0); //Move to the center of the triangle
        glScalef(0.4,0.3, 0.4);

        if(playerPos == 'L')
        {
            glRotatef(90, 0.0, 1.0, 0.0);
        }
        else if(playerPos == 'R')
        {
            glRotatef(-90, 0.0, 1.0, 0.0);
        }
        else if(playerPos == 'F')
        {
            glRotatef(0, 0.0, 1.0, 0.0);
        }
        else
        {
            glRotatef(180, 0.0, 1.0, 0.0); //Player in back position
        }

        //player start

        glPushMatrix();
        glColor3f(1.0,0,0.0);
        glTranslatef(0,2.00,0.0);
        //glRotatef(-110,1.0,0.0,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.55);
        glPopMatrix();


        glPushMatrix();
        //glRotatef(_angle,0.0,1.0,0.0);
        glPushMatrix();
        glColor3f(1.0,1.0,0.0);
        glTranslatef(0,1.00,0.0);
        //glRotatef(-110,1.0,0.0,0.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(0.8);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,1.0,0.0);
        glTranslatef(0.8,1.0,0.0);
        glScalef(1.0,3.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0.0,1.0);
        glTranslatef(-0.8,1.0,0.0);
        glScalef(1.0,3.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,1.0,1.0);
        glTranslatef(-0.8,0.5,0.0);
        glScalef(0.8,1.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();


        glPushMatrix();
        glColor3f(0,1.0,1.0);
        glTranslatef(0.8,0.5,0.0);
        glScalef(0.8,1.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);


        glPopMatrix();



        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(0.2,0.0,0.0);
        glScalef(1.4,3.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-0.2,0.0,0.0);
        glScalef(1.4,3.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glTranslatef(0.2,-0.5,0.0);
        glScalef(1.0,2.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glTranslatef(-0.2,-0.5,0.0);
        glScalef(1.0,2.0,1.0);
        //glRotatef(_angle,0.0,1.0,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        glPopMatrix();

    //player end

        glPopMatrix(); //Undo the move to the center of the triangle
        //player push/pop end

        lifeBar();

        //Player score start

        stringstream ss;
        ss << total_points;

        string score = ss.str();

        string sc = "Score : ";

        glRasterPos2f(4.05,2.2);

        for(int i=0; i<sc.length(); i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)sc[i]);
        }

        for(int i=0; i<score.length(); i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)score[i]);
        }

        //Player score end

        bulletLogic(); //Bullet throwing logic & collision detection

        if(zombie1State == false && zombie2State == false && zombie3State == false && zombie4State == false)
        {
            random = rand() % 4 + 1;
            //random = 4;

            if(random == 1)
            {
                zombie1State = true;
            }
            else if(random == 2)
            {
                zombie1State = true;
                zombie2State = true;
            }
            else if(random == 3)
            {
                zombie1State = true;
                zombie2State = true;
                zombie3State = true;
            }
            else if(random == 4)
            {
                zombie1State = true;
                zombie2State = true;
                zombie3State = true;
                zombie4State = true;
            }

            zombieSpeedControl+=0.003;

            //resetting everything

            zombie1Hit = 0;
            zombie2Hit = 0;
            zombie3Hit = 0;
            zombie4Hit = 0;

            zombie1x = -4.0;
            zombie1y = 0.5;

            zombie2x = 3.5;
            zombie2y = -1.5;

            zombie3x = 4.5;
            zombie3y = 0.5;

            zombie4x = -3.5;
            zombie4y = -2.0;
        }

        if(zombie1State)
        {
            zombie1();
        }

        if(zombie2State)
        {
            zombie2();
        }

        if(zombie3State)
        {
            zombie3();
        }

        if(zombie4State)
        {
            zombie4();
        }

        //scenery starts again

        //clouds start

        glPushMatrix();
        glTranslatef(_cloud, 0.25, 0.0);

        //cloud1 start
        glPushMatrix();
        glTranslatef(0.8, -0.7, 0.0);
        glScalef(5.5,3.5,0);

        cloud1();

        glPopMatrix();
        //cloud1 end

         //cloud2 start
        glPushMatrix();
        glTranslatef(1.0, -0.6, 0.0);
        glScalef(5.5,3.5,0);

        cloud2();

        glPopMatrix();
        //cloud2 end

         //cloud3 start
        glPushMatrix();
        glTranslatef(1.0, -0.7, 0.0);
        glScalef(5.5,3.5,0);

        cloud3();

        glPopMatrix();
        //cloud3 end

        glPopMatrix();

        //clouds end

        //SUN start

        glPushMatrix();
        glColor3f(1.50,0.50,0.20);
        glTranslatef(-3.5,2.35,0.0);
        glScalef(1.8,1,0);
        glRotatef(_movesun,0.0,1.0,0.0);
        glutSolidSphere(.30,20,20); //(GLdouble radius,GLint slices, GLint stacks);
        glPopMatrix();

        //SUN end

        //house start
        //roof start
        glPushMatrix(); //Save the current state of transformations
        glTranslatef(-2, 1.3, 0.0); //Move to the center of the pentagon
        glColor3ub (188 , 149, 84);
        glScalef(1.3, .5, 0.0); //Scale by 0.7 in the x, y, and z directions

        glBegin(GL_POLYGON);
        glVertex3f(0.7, 0.7, 0.0);
        glVertex3f(0.4, -0.8, 0.0);
        glVertex3f(-1, -0.8, 0.0);
        glVertex3f(-0.7, 0.7, 0.0);

        glEnd();
        glPopMatrix(); //Undo the move to the center of the pentagon/*

        //right side roof start
        glPushMatrix();
        glColor3ub (188 , 149, 84);
        glTranslatef(-.95,1.25,0.0);
        glRotatef(30,0,0,1);
        glScalef(.3,2,0);
        glutSolidCube(.4);
        //glEnd();
        glPopMatrix();
        //right side roof end
        //lower part house
	    glPushMatrix();
        glPushMatrix();
        glColor3ub (192 , 187, 167);
        glTranslatef(-2.32,.52,0.0);
        glScalef(2.8,1.3,0);
        glutSolidCube(.6);
        glPopMatrix();
        //lower part end

        //window 1 start
        glPushMatrix();
        glColor3ub (113 , 84, 57);
        glTranslatef(-2.7,.5,0.0);
        glutSolidCube(.25);

        glPopMatrix();
        //window 1 end

        //window 2 start
        glPushMatrix();
        glColor3ub (113 , 84, 57);
        glTranslatef(-2,.5,0.0);
        glutSolidCube(.25);
        glPopMatrix();

        //window 2 end
        //right side bottom

        glPushMatrix();
        glColor3ub (192 , 180, 167);
        glTranslatef(-1.3,.7,0.0);
        glRotatef(20,0,0,1);
        glScalef(1.8,2.3,0);
        glutSolidCube(.4);
        glPopMatrix();

        //
        glPushMatrix();
        glColor3ub (192 , 180, 167);
        glTranslatef(-.98,.7,0.0);
        glScalef(1,2,0);
        glutSolidCube(.33);
        glPopMatrix();
        //
        glPushMatrix();
        glColor3ub (192 , 180, 167);
        glTranslatef(-1.15,1.2,0.0);
        glRotatef(30,0,0,1);
        glScalef(1.1,1.3,0);
        glutSolidCube(.4);
        glPopMatrix();
        //right side bottom end

        //door start
        glPushMatrix();
        glTranslatef(-.63, .38, 3); //Move to the center of the pentagon
        glColor3ub (113 , 84, 57);
        glScalef(.1, .27, 0); //Scale by 0.7 in the x, y, and z directions
        glRotatef(13,1,0,1);

        glBegin(GL_POLYGON);
        glVertex3f(0.7, 0.7, 0.0);
        glVertex3f(0.4, -0.8, 0.0);
        glVertex3f(-1, -0.8, 0.0);
        glVertex3f(-0.7, 0.7, 0.0);

        glEnd();
        glPopMatrix();
        //door end

        //house end

         //Tree Start


//tree-1



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( -1100),getY( 50 ));
                    glVertex2f(getX( -1090),getY( 50));
                    glVertex2f(getX( -1090),getY( 100));
                    glVertex2f(getX( -1100),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -1065),getY( 120));
                    glVertex2f(getX( -1125),getY( 120));
                    glVertex2f(getX(-1095),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -1069),getY( 108));
                    glVertex2f(getX( -1121),getY( 108));
                    glVertex2f(getX( -1095),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -1074),getY( 95));
                    glVertex2f(getX( -1116),getY( 95));
                    glVertex2f(getX( -1095),getY( 118));
                glEnd();






//tree-2



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( -1000),getY( 50 ));
                    glVertex2f(getX( -990),getY( 50));
                    glVertex2f(getX( -990),getY( 100));
                    glVertex2f(getX( -1000),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -965),getY( 120));
                    glVertex2f(getX( -1025),getY( 120));
                    glVertex2f(getX(-995),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -969),getY( 108));
                    glVertex2f(getX( -1021),getY( 108));
                    glVertex2f(getX( -995),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -974),getY( 95));
                    glVertex2f(getX( -1016),getY( 95));
                    glVertex2f(getX( -995),getY( 118));
                glEnd();




//tree-3



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( -900),getY( 50 ));
                    glVertex2f(getX( -890),getY( 50));
                    glVertex2f(getX( -890),getY( 100));
                    glVertex2f(getX( -900),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -865),getY( 120));
                    glVertex2f(getX( -925),getY( 120));
                    glVertex2f(getX(-895),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -869),getY( 108));
                    glVertex2f(getX( -921),getY( 108));
                    glVertex2f(getX( -895),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -874),getY( 95));
                    glVertex2f(getX( -916),getY( 95));
                    glVertex2f(getX( -895),getY( 118));
                glEnd();




//tree-4



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( -800),getY( 50 ));
                    glVertex2f(getX( -790),getY( 50));
                    glVertex2f(getX( -790),getY( 100));
                    glVertex2f(getX( -800),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -765),getY( 120));
                    glVertex2f(getX( -825),getY( 120));
                    glVertex2f(getX(-795),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -769),getY( 108));
                    glVertex2f(getX( -821),getY( 108));
                    glVertex2f(getX( -795),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -774),getY( 95));
                    glVertex2f(getX( -816),getY( 95));
                    glVertex2f(getX( -795),getY( 118));
                glEnd();







//tree-5



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( -200),getY( 50 ));
                    glVertex2f(getX( -190),getY( 50));
                    glVertex2f(getX( -190),getY( 100));
                    glVertex2f(getX( -200),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -165),getY( 120));
                    glVertex2f(getX( -225),getY( 120));
                    glVertex2f(getX(-195),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -169),getY( 108));
                    glVertex2f(getX( -221),getY( 108));
                    glVertex2f(getX( -195),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -174),getY( 95));
                    glVertex2f(getX( -216),getY( 95));
                    glVertex2f(getX( -195),getY( 118));
                glEnd();




//tree-6



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( -100),getY( 50 ));
                    glVertex2f(getX( -90),getY( 50));
                    glVertex2f(getX( -90),getY( 100));
                    glVertex2f(getX( -100),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -65),getY( 120));
                    glVertex2f(getX( -125),getY( 120));
                    glVertex2f(getX(-95),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -69),getY( 108));
                    glVertex2f(getX( -121),getY( 108));
                    glVertex2f(getX( -95),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( -74),getY( 95));
                    glVertex2f(getX( -116),getY( 95));
                    glVertex2f(getX( -95),getY( 118));
                glEnd();






//tree-7



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 0),getY( 50 ));
                    glVertex2f(getX( 10),getY( 50));
                    glVertex2f(getX( 10),getY( 100));
                    glVertex2f(getX( 0),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 35),getY( 120));
                    glVertex2f(getX( -25),getY( 120));
                    glVertex2f(getX( 5),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 31),getY( 108));
                    glVertex2f(getX( -21),getY( 108));
                    glVertex2f(getX( 5),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 26),getY( 95));
                    glVertex2f(getX( -16),getY( 95));
                    glVertex2f(getX( 5),getY( 118));
                glEnd();





//tree-8



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 100),getY( 50 ));
                    glVertex2f(getX( 110),getY( 50));
                    glVertex2f(getX( 110),getY( 100));
                    glVertex2f(getX( 100),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 135),getY( 120));
                    glVertex2f(getX( 75),getY( 120));
                    glVertex2f(getX( 105),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 131),getY( 108));
                    glVertex2f(getX( 79),getY( 108));
                    glVertex2f(getX( 105),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 126),getY( 95));
                    glVertex2f(getX( 84),getY( 95));
                    glVertex2f(getX( 105),getY( 118));
                glEnd();




//tree-9



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 200),getY( 50 ));
                    glVertex2f(getX( 210),getY( 50));
                    glVertex2f(getX( 210),getY( 100));
                    glVertex2f(getX( 200),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 235),getY( 120));
                    glVertex2f(getX( 175),getY( 120));
                    glVertex2f(getX( 205),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 231),getY( 108));
                    glVertex2f(getX( 179),getY( 108));
                    glVertex2f(getX( 205),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 226),getY( 95));
                    glVertex2f(getX( 184),getY( 95));
                    glVertex2f(getX( 205),getY( 118));
                glEnd();




//tree-10



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 300),getY( 50 ));
                    glVertex2f(getX( 310),getY( 50));
                    glVertex2f(getX( 310),getY( 100));
                    glVertex2f(getX( 300),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 335),getY( 120));
                    glVertex2f(getX( 275),getY( 120));
                    glVertex2f(getX( 305),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 331),getY( 108));
                    glVertex2f(getX( 279),getY( 108));
                    glVertex2f(getX( 305),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 326),getY( 95));
                    glVertex2f(getX( 284),getY( 95));
                    glVertex2f(getX( 305),getY( 118));
                glEnd();






//tree-11



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 400),getY( 50 ));
                    glVertex2f(getX( 410),getY( 50));
                    glVertex2f(getX( 410),getY( 100));
                    glVertex2f(getX( 400),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 435),getY( 120));
                    glVertex2f(getX( 375),getY( 120));
                    glVertex2f(getX( 405),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 431),getY( 108));
                    glVertex2f(getX( 379),getY( 108));
                    glVertex2f(getX( 405),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 426),getY( 95));
                    glVertex2f(getX( 384),getY( 95));
                    glVertex2f(getX( 405),getY( 118));
                glEnd();


//tree11
glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 600),getY( 50 ));
                    glVertex2f(getX( 610),getY( 50));
                    glVertex2f(getX( 610),getY( 100));
                    glVertex2f(getX( 600),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 635),getY( 120));
                    glVertex2f(getX( 575),getY( 120));
                    glVertex2f(getX( 605),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 631),getY( 108));
                    glVertex2f(getX( 579),getY( 108));
                    glVertex2f(getX( 605),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 626),getY( 95));
                    glVertex2f(getX( 584),getY( 95));
                    glVertex2f(getX( 605),getY( 118));
                glEnd();

//tree12



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 500),getY( 50 ));
                    glVertex2f(getX( 510),getY( 50));
                    glVertex2f(getX( 510),getY( 100));
                    glVertex2f(getX( 500),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 535),getY( 120));
                    glVertex2f(getX( 475),getY( 120));
                    glVertex2f(getX( 505),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 531),getY( 108));
                    glVertex2f(getX( 479),getY( 108));
                    glVertex2f(getX( 505),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 526),getY( 95));
                    glVertex2f(getX( 484),getY( 95));
                    glVertex2f(getX( 505),getY( 118));
                glEnd();


//tree13



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 700),getY( 50 ));
                    glVertex2f(getX( 710),getY( 50));
                    glVertex2f(getX( 710),getY( 100));
                    glVertex2f(getX( 700),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 735),getY( 120));
                    glVertex2f(getX( 675),getY( 120));
                    glVertex2f(getX( 705),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 731),getY( 108));
                    glVertex2f(getX( 679),getY( 108));
                    glVertex2f(getX( 705),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 726),getY( 95));
                    glVertex2f(getX( 684),getY( 95));
                    glVertex2f(getX( 705),getY( 118));
                glEnd();


//tree14



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 800),getY( 50 ));
                    glVertex2f(getX( 810),getY( 50));
                    glVertex2f(getX( 810),getY( 100));
                    glVertex2f(getX( 800),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 835),getY( 120));
                    glVertex2f(getX( 775),getY( 120));
                    glVertex2f(getX( 805),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 831),getY( 108));
                    glVertex2f(getX( 779),getY( 108));
                    glVertex2f(getX( 805),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 826),getY( 95));
                    glVertex2f(getX( 784),getY( 95));
                    glVertex2f(getX( 805),getY( 118));
                glEnd();


//tree15



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 900),getY( 50 ));
                    glVertex2f(getX( 910),getY( 50));
                    glVertex2f(getX( 910),getY( 100));
                    glVertex2f(getX( 900),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 935),getY( 120));
                    glVertex2f(getX( 875),getY( 120));
                    glVertex2f(getX( 905),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 931),getY( 108));
                    glVertex2f(getX( 879),getY( 108));
                    glVertex2f(getX( 905),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 926),getY( 95));
                    glVertex2f(getX( 884),getY( 95));
                    glVertex2f(getX( 905),getY( 118));
                glEnd();


//tree16



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 1000),getY( 50 ));
                    glVertex2f(getX( 1010),getY( 50));
                    glVertex2f(getX( 1010),getY( 100));
                    glVertex2f(getX( 1000),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 1035),getY( 120));
                    glVertex2f(getX( 975),getY( 120));
                    glVertex2f(getX( 1005),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 1031),getY( 108));
                    glVertex2f(getX( 979),getY( 108));
                    glVertex2f(getX( 1005),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 1026),getY( 95));
                    glVertex2f(getX( 984),getY( 95));
                    glVertex2f(getX( 1005),getY( 118));
                glEnd();


//tree17



glColor3ub (113 , 84, 57);
                glPointSize(5.0);
                glBegin(GL_POLYGON);

                    glVertex2f(getX( 1100),getY( 50 ));
                    glVertex2f(getX( 1110),getY( 50));
                    glVertex2f(getX( 1110),getY( 100));
                    glVertex2f(getX( 1100),getY( 100));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 1135),getY( 120));
                    glVertex2f(getX( 1075),getY( 120));
                    glVertex2f(getX( 1105),getY( 145));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 1131),getY( 108));
                    glVertex2f(getX( 1079),getY( 108));
                    glVertex2f(getX( 1105),getY( 132));
                glEnd();


                glColor3ub (34 , 103, 7);
                glPointSize(5.0);
                glBegin(GL_POLYGON);
                    glVertex2f(getX( 1126),getY( 95));
                    glVertex2f(getX( 1084),getY( 95));
                    glVertex2f(getX( 1105),getY( 118));
                glEnd();

        //tree end

        //Grass start

        glColor3ub (90 , 168, 64);
        glBegin(GL_POLYGON);

        glVertex3f(-6.0,-5.0,-1);
        glVertex3f(-6.0,0.7,-1);
        glVertex3f(6.0,0.7,-1);
        glVertex3f(6.0,-5.0,-1);

        glEnd();

        //Grass end

        //sky start

        glColor3ub (120, 219, 237);
        glBegin(GL_POLYGON);

        glVertex3f(-6.0,0.7,-1);
        glVertex3f(-6.0,5.0,-1);
        glVertex3f(6,5.0,-1);
        glVertex3f(6,0.7,-1);

        glEnd();

        //sky end

        //scenery ends again

        glColor3f(1,0,0); // to color Pause
    }

	glutSwapBuffers();
}

void shoot()
{
    bulletCount++;

    if(bulletCount <= 5)
    {
        //play bullet sound

        if(bullet1 == false)
        {
            mciSendString("close Gunshot1", NULL, 0, NULL); //close any previous gunshot
            mciSendString("open \"gunshot1.mp3\" type mpegvideo alias Gunshot1", NULL, 0, NULL); //open the mp3 file
            mciSendString("play Gunshot1", NULL, 0, NULL); //repeat

            //cout<<1<<endl;
            bullet1 = true;
            //holding shoot position
            bullet1ShootPos = playerPos;

            if(bullet1ShootPos == 'F')
            {
                shootPos1x = playerX;
                shootPos1y = playerY + 0.5;
            }
            else if(bullet1ShootPos == 'B')
            {
                shootPos1x = playerX;
                shootPos1y = playerY - 0.5;
            }
            else if(bullet1ShootPos == 'L')
            {
                shootPos1x = playerX - 0.5;
                shootPos1y = playerY;
            }
            else
            {
                shootPos1x = playerX + 0.5;
                shootPos1y = playerY;
            }
            //cout<<playerX<<" "<<playerY;
        }
        else if(bullet2 == false)
        {
            mciSendString("close Gunshot2", NULL, 0, NULL); //close any previous gunshot
            mciSendString("open \"gunshot2.mp3\" type mpegvideo alias Gunshot2", NULL, 0, NULL); //open the mp3 file
            mciSendString("play Gunshot2", NULL, 0, NULL); //repeat

            bullet2 = true;
            //holding shoot position
            bullet2ShootPos = playerPos;

            if(bullet2ShootPos == 'F')
            {
                shootPos2x = playerX;
                shootPos2y = playerY + 0.5;
            }
            else if(bullet2ShootPos == 'B')
            {
                shootPos2x = playerX;
                shootPos2y = playerY - 0.5;
            }
            else if(bullet2ShootPos == 'L')
            {
                shootPos2x = playerX - 0.5;
                shootPos2y = playerY;
            }
            else
            {
                shootPos2x = playerX + 0.5;
                shootPos2y = playerY;
            }
        }
        else if(bullet3 == false)
        {
            mciSendString("close Gunshot3", NULL, 0, NULL); //close any previous gunshot
            mciSendString("open \"gunshot3.mp3\" type mpegvideo alias Gunshot3", NULL, 0, NULL); //open the mp3 file
            mciSendString("play Gunshot3", NULL, 0, NULL); //repeat

            bullet3 = true;
            //holding shoot position
            bullet3ShootPos = playerPos;

            if(bullet3ShootPos == 'F')
            {
                shootPos3x = playerX;
                shootPos3y = playerY + 0.5;
            }
            else if(bullet3ShootPos == 'B')
            {
                shootPos3x = playerX;
                shootPos3y = playerY - 0.5;
            }
            else if(bullet3ShootPos == 'L')
            {
                shootPos3x = playerX - 0.5;
                shootPos3y = playerY;
            }
            else
            {
                shootPos3x = playerX + 0.5;
                shootPos3y = playerY;
            }
        }
        else if(bullet4 == false)
        {
            mciSendString("close Gunshot4", NULL, 0, NULL); //close any previous gunshot
            mciSendString("open \"gunshot4.mp3\" type mpegvideo alias Gunshot4", NULL, 0, NULL); //open the mp3 file
            mciSendString("play Gunshot4", NULL, 0, NULL); //repeat

            bullet4 = true;
            //holding shoot position
            bullet4ShootPos = playerPos;

            if(bullet4ShootPos == 'F')
            {
                shootPos4x = playerX;
                shootPos4y = playerY + 0.5;
            }
            else if(bullet4ShootPos == 'B')
            {
                shootPos4x = playerX;
                shootPos4y = playerY - 0.5;
            }
            else if(bullet4ShootPos == 'L')
            {
                shootPos4x = playerX - 0.5;
                shootPos4y = playerY;
            }
            else
            {
                shootPos4x = playerX + 0.5;
                shootPos4y = playerY;
            }
        }
        else if(bullet5 == false)
        {
            mciSendString("close Gunshot5", NULL, 0, NULL); //close any previous gunshot
            mciSendString("open \"gunshot5.mp3\" type mpegvideo alias Gunshot5", NULL, 0, NULL); //open the mp3 file
            mciSendString("play Gunshot5", NULL, 0, NULL); //repeat

            bullet5 = true;
            //holding shoot position
            bullet5ShootPos = playerPos;

            if(bullet5ShootPos == 'F')
            {
                shootPos5x = playerX;
                shootPos5y = playerY + 0.5;
            }
            else if(bullet5ShootPos == 'B')
            {
                shootPos5x = playerX;
                shootPos5y = playerY - 0.5;
            }
            else if(bullet1ShootPos == 'L')
            {
                shootPos5x = playerX - 0.5;
                shootPos5y = playerY;
            }
            else
            {
                shootPos5x = playerX + 0.5;
                shootPos5y = playerY;
            }
        }
    }
    else
    {
        //reload voice
        mciSendString("close reloadVoice", NULL, 0, NULL); //closing the song file
        mciSendString("open \"reload_voice.mp3\" type mpegvideo alias reloadVoice", NULL, 0, NULL); //open the mp3 file
        mciSendString("play reloadVoice", NULL, 0, NULL); //repeat
    }
}

void myMouse(int b, int s, int x, int y) {      // mouse click callback
	if (s == GLUT_DOWN) {

            if(gameMenu && fullScreenMode == false)
            {
                if(b == GLUT_LEFT_BUTTON && ((x >= 435 && x <= 542) && (y >= 200 && y <= 215))) // start playing 509
                {
                    if(firstMenuFlag)
                    {
                        if(x >= 435 && x <= 542) // Check for resume button
                        {
                            gameMenu = false;
                            fromGameToMenu = false;
                            fullScreenMode = true;
                            glutFullScreen(); //start the game in full screen
                            glutPostRedisplay();
                        }
                    }
                    else
                    {
                        if(x >= 435 && x <= 509)
                        {
                            gameMenu = false;
                            fullScreenMode = true;
                            glutFullScreen(); //start the game in full screen
                            glutPostRedisplay();
                        }
                    }
                }
                else if(b == GLUT_LEFT_BUTTON && ((x >= 435 && x <= 572) && (y >= 231 && y <= 245))) //open sub menu
                {
                    gameControlMenu = true;
                    gameMenu = false;
                    glutPostRedisplay();
                }
                else if(b == GLUT_LEFT_BUTTON && ((x >= 435 && x <= 604) && (y >= 260 && y <= 276))) // open sub menu
                {
                    showHighScore = true;
                    gameMenu = false;
                    glutPostRedisplay();
                }
                else if(b == GLUT_LEFT_BUTTON && ((x >= 435 && x <= 503) && (y >= 289 && y <= 312))) // exit
                {
                    exit(0);
                }

                //cout<<x<<" "<<y<<endl;
            }
            else if(gameMenu && fullScreenMode == true)
            {
                if(b == GLUT_LEFT_BUTTON && ((x >= 585 && x <= 690) && (y >= 273 && y <= 290))) // start playing 657
                {
                    if(firstMenuFlag)
                    {
                        if(x >= 585 && x <= 690)
                        {
                            gameMenu = false;
                            fromGameToMenu = false;
                            glutPostRedisplay(); // Check for resume button
                        }
                    }
                    else
                    {
                        if(x >= 585 && x <= 657)
                        {
                            gameMenu = false;
                            glutPostRedisplay();
                        }
                    }
                }
                else if(b == GLUT_LEFT_BUTTON && ((x >= 585 && x <= 721) && (y >= 314 && y <= 328))) //open sub menu
                {
                    gameControlMenu = true;
                    gameMenu = false;
                    glutPostRedisplay();
                }
                else if(b == GLUT_LEFT_BUTTON && ((x >= 585 && x <= 752) && (y >= 351 && y <= 370))) // open sub menu
                {
                    showHighScore = true;
                    gameMenu = false;
                    glutPostRedisplay();
                }
                else if(b == GLUT_LEFT_BUTTON && ((x >= 585 && x <= 652) && (y >= 392 && y <= 411))) // exit
                {
                    exit(0);
                }

                //cout<<x<<" "<<y<<endl;
            }
            else if(gameControlMenu && fullScreenMode == false)
                {
                    if((x >= 447 && x <= 505) && (y >= 491 && y <= 505))
                    {
                        gameControlMenu = false;
                        gameMenu = true;
                        glutPostRedisplay();
                    }
                }
                else if(gameControlMenu && fullScreenMode == true)
                {
                    if((x >= 597 && x <= 659) && (y >= 659 && y <= 675))
                    {
                        gameControlMenu = false;
                        gameMenu = true;
                        glutPostRedisplay();
                    }
                }
                else if(showHighScore && fullScreenMode == false)
                {
                    if((x >= 447 && x <= 505) && (y >= 491 && y <= 505))
                    {
                        showHighScore = false;
                        gameMenu = true;
                        glutPostRedisplay();
                    }
                }
                else if(showHighScore && fullScreenMode == true)
                {
                    if((x >= 595 && x <= 674) && (y >= 656 && y <= 675))
                    {
                        showHighScore = false;
                        gameMenu = true;
                        glutPostRedisplay();
                    }
                }
            else
            {
                if (b == GLUT_LEFT_BUTTON && paused == false && gameover == false) {

                        shoot();
                        glutPostRedisplay();
                    }
                    else if (b == GLUT_RIGHT_BUTTON && paused == false && gameover == false) {

                        mciSendString("close reloadSound", NULL, 0, NULL); //closing the song file

                        mciSendString("open \"reload.mp3\" type mpegvideo alias reloadSound", NULL, 0, NULL); //open the mp3 file
                        mciSendString("play reloadSound", NULL, 0, NULL); //repeat

                        bulletCount = 0;
                    }
            }
	}
}

/* Callback handler for special-key event */
void specialKeys(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
         //fullScreenMode = !fullScreenMode;         // Toggle state
         if (!fullScreenMode) {                     // Full-screen mode

            glutFullScreen();
            fullScreenMode = true;                    // Switch into full screen
         } else {                                         // Windowed mode
            glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
            glutPositionWindow(200, 100);   // Position top-left corner (windowPosX, windowPosY)
            fullScreenMode = false;
         }

         break;

         default:
         break;
   }
}

void reset() //reset everything
{
    zombie1State = false;
    zombie2State = false;
    zombie3State = false;
    zombie4State = false;

    zombieSpeedControl = -0.003;

    bullet1 = false;
    bullet2 = false;
    bullet3 = false;
    bullet4 = false;
    bullet5 = false;

    playerHit = 0;
    bulletCount = 0;
    total_points = 0;

    playerX = 0.0f;
    playerY = -2.15f;
    playerPos = 'F';

    _movesun = 0.0f;
    _cloud = -0.5f;
}


void keyboard(unsigned char key, int x, int y)
{
    if(gameover == false)
    {
        if(fromGameToMenu == false) //if in just menu bar, no movement
        {
            switch (key) {

        case 'w':

    if(paused == false)
    {
        playerPos = 'F';

        if((playerX <= -0.56 && playerX >= -3.04))
        {
            if(playerY <= -0.63)
            {
                 playerY += 0.08f;
                 glutPostRedisplay();
            }
        }
        else if(playerY < -0.15)
        {
            playerY += 0.08f;
            glutPostRedisplay();
        }
    }

    break;

    case 's':

    if(paused == false)
    {
        playerPos = 'B';

        if(playerY > -2.15)
        {
            playerY -= 0.08f;
            glutPostRedisplay();
        }
    }

    break;

    case 'a':

    if(paused == false)
    {
        playerPos = 'L';

        if(playerY >= -0.60)
        {
            if(playerX >= -0.54 || (playerX <= -2.86 && playerX > -4.05))
            {
                playerX -= 0.08f;
                glutPostRedisplay();
            }
        }
        else if(playerX > -4.05)
        {
            playerX -= 0.08f;
            glutPostRedisplay();
        }
    }

    break;

    case 'd':

    if(paused == false)
    {
        playerPos = 'R';

        if(playerY >= -0.60)
        {
            if(playerX < -2.88 || (playerX >= -0.58 && playerX < 4.05))
            {
                playerX += 0.08f;
                glutPostRedisplay();
            }
        }
        else if(playerX < 4.05)
        {
            playerX += 0.08f;
            glutPostRedisplay();
        }
    }

    break;

    case 32 : //space bar

        if(gameover == false && gameMenu == false && gameControlMenu == false && showHighScore == false)
        {
            if(paused == false)
            {
                paused = true;

                mciSendString("pause zombieGrowl", NULL, 0, NULL); //repeat
                mciSendString("pause birdSound", NULL, 0, NULL); //repeat
                mciSendString("pause backgroundMusic", NULL, 0, NULL); //repeat

            }
            else
            {
                paused = false;

                mciSendString("resume zombieGrowl", NULL, 0, NULL); //repeat
                mciSendString("resume birdSound", NULL, 0, NULL); //repeat
                mciSendString("resume backgroundMusic", NULL, 0, NULL); //repeat
            }

            glutPostRedisplay();
        }

        break;

        default:
        break;

    }
  }

}
    else //game over screen
    {
        switch(key)
        {
            case 'q': // quit
            exit(0);

        break;

        case 'm': //main menu

            //resetting everything

            reset();

            //reseted

            gameover = false;
            gameMenu = true;
            glutPostRedisplay();

            break;

        case 'r': //restart
            gameover = false;

            reset(); //resetting everything

            restartFlag = true;
            gameOverSoundFlag = false;

            //reseted

            glutPostRedisplay();

            break;

            default:
            break;
        }
    }

    switch(key)
    {
        case 13 : //Enter button
        if (!fullScreenMode) {                     // Full-screen mode

            glutFullScreen();
            fullScreenMode = true;                    // Switch into full screen
         } else {                                         // Windowed mode
            glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
            glutPositionWindow(200, 100);   // Position top-left corner (windowPosX, windowPosY)
            fullScreenMode = false;
         }

         break;

        case 'm':
            if(firstMenuFlag && paused == false)
            {
                if(fromGameToMenu == false)
                {
                    gameMenu = true;
                    fromGameToMenu = true;
                }
                else
                {
                    gameMenu = false;
                    fromGameToMenu = false;
                }
            }

            break;

        case 27 : //Escape key
        exit(0);

        break;

         default:
         break;
    }
}

void update(int value) {

    if(paused == false)
    {
        //for scenery start
        _cloud += 0.002;
        if(_cloud > 10.0)
        {
            _cloud = -0.1;
        }

        _movesun += 10.0f;
        if (_movesun > 360) {
            _movesun -= 360;
        }
        //for scenery end

        if (_angle < 1 && flag1 == false) {
            _angle += 2.0f;
        }
        else
        {
            flag1 = true;
        }

        if (_angle > -1 && flag1 == true) {
            _angle -= 2.0f;
        }
        else
        {
            flag1 = false;
        }

        glutPostRedisplay(); //Tell GLUT that the display has changed
    }
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(windowPosX, windowPosY);

	//Create the window
	glutCreateWindow("Hour of Rush");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMouseFunc(myMouse);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	srand(time(NULL)); //seed random val
	//PlaySound("theme.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

	if(gameMenu)
    {
        mciSendString("open \"theme.mp3\" type mpegvideo alias themeSong", NULL, 0, NULL); //open the mp3 file
        mciSendString("play themeSong repeat", NULL, 0, NULL); //repeat
    }

	glutMainLoop();
	return 0;
}
