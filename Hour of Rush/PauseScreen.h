#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>

using  namespace std;

class PauseScreen
{
public:

    void drawText(const char *text, int length, float x, float y)
    {
        glRasterPos2f(x,y);

        for(int i=0; i<length; i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
        }
    }
};


