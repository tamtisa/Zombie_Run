#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>

using  namespace std;

class gameOver
{
public:
char name[10] = "GAME OVER";
char line[13] = "YOU DIED !!!";
char score[30] = "YOUR SCORE  : ";
char play[30] = "PLAY AGAIN : PRESS R";
char quit[30] = "QUIT : PRESS Q";
char returnMenu[30] = "MAIN MENU : PRESS M";

public:
    void drawText(const char *text, int length, float x, float y)
    {
        glRasterPos2f(x,y);
        for(int i=0; i<length; i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
        }
    }
    void createGameOverScreen(string points, bool fullScreenMode) {

        glColor3d(1.0,0.0,0.0);
        glScalef(2,2,2);

        drawText(name, 10, -0.5, 0.8); //-0.5
        drawText(line, 13, -0.5, 0.50);
        drawText(score, 30, -0.5,0.15);

        if(fullScreenMode == true)
        {
            glRasterPos2f(0.2,0.15);
        }
        else
        {
            glRasterPos2f(0.4,0.15);
        }

        for(int i=0; i<points.length(); i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)points[i]); // showing score
        }

        drawText(play, 30, -0.5,-0.2);
        drawText(quit, 30, -0.5,-0.5);
        drawText(returnMenu, 30, -0.5,-0.8);
    }
};
