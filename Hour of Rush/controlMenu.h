#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>

using  namespace std;

class controlMenu
{
public:
char name[15] = "USER MOVEMENT";
char line[20] = "------------------";
char keyboard[9] = "KEYBOARD";
char line1[20] = "-----------------";
char mouse[9] = "MOUSE";
char line2[20] = "-----------------";
char ins1[13] = "MOVE FORWARD";
char ins2[14] = "MOVE BACKWARD";
char ins3[10] = "MOVE LEFT";
char ins4[11] = "MOVE RIGHT";
char ins5[6] = "SHOOT";
char ins6[7] = "RELOAD";
char ins7[11] = "FULLSCREEN";
char ins8[6] = "PAUSE";
char ins9[21] = "TOGGLE : MENU / GAME";
char ins10[10] = "QUIT GAME";
char back_to_menu[5] = "BACK";

public:
    void drawText(const char *text, int length, float x, float y)
    {
        glRasterPos2f(x,y);
        for(int i=0; i<length; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
        }
    }
    void createControlMenu() {

        glColor3d(1.0,0.0,0.0);
        glScalef(2,2,2);
        drawText(name, 15, -0.5, 1.2);
        drawText(line, 20, -0.58, 1.1);

        drawText(keyboard, 9, -1.5, 0.8);
        drawText(line1, 20, -1.70, 0.7);

        drawText(ins1, 13, -1.75, 0.5);
        drawText("-  W", 5, -0.9, 0.5);

        drawText(ins2, 14, -1.75, 0.3);
        drawText(" -  S", 6, -0.9, 0.3);

        drawText(ins3, 10, -1.75, 0.1);
        drawText(" -  A", 6, -0.9, 0.1);

        drawText(ins4, 11, -1.75, -0.1);
        drawText(" -  D", 6, -0.9, -0.1);

        drawText(mouse, 6, 1.0, 0.8);
        drawText(line2, 20, 0.7, 0.7);

        drawText(ins5, 6, 0.7, 0.5);
        drawText(" -   LEFT MOUSE BUTTON", 23, 1.2, 0.5);

        drawText(ins6, 7, 0.7, 0.3);
        drawText(" -   RIGHT MOUSE BUTTON", 23, 1.2, 0.3);

        drawText(ins7, 11, 0.7, 0.0);
        drawText(" -    F1 / ENTER", 18, 1.5, 0.0);

        drawText(ins8, 6, 0.7, -0.2);
        drawText(" -  SPACEBAR", 13, 1.5, -0.2);

        drawText(ins9, 21, -0.75, -0.5);
        drawText(" - M", 5, 0.4, -0.5);

        drawText(ins10, 10, -0.75, -0.7);
        drawText(" - ESC", 7, 0.4, -0.7);

        drawText(back_to_menu, 5, -0.3,-1.1);
    }
};
