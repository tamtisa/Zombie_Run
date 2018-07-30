#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>

using  namespace std;

class highScoreMenu
{
public:
string name = "HIGH SCORES";
string line = "------------------";
string back_to_menu = "BACK";

public:
    void drawText(string text, int length, float x, float y)
    {
        glRasterPos2f(x,y);
        for(int i=0; i<length; i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
        }
    }
    void createHighScoreMenu() {

        glColor3d(1.0,0.0,0.0);
        glScalef(2,2,2);
        drawText(name, 11, -0.5, 1.2);
        drawText(line, 20, -0.73, 1.1);

        //reading from text file
        ifstream inFile;
        inFile.open("Highscore.txt");

        if(!inFile)
        {
            cout<<"Unable to open the File !!"<<endl;
            exit(1);
        }

        string high, high1, high2, high3;
        short counter = 0;

        while(getline(inFile,high))
        {
            counter++;

            if(counter == 1)
                high1 = high;
            else if(counter == 2)
                high2 = high;
            else if(counter == 3)
                high3 = high;
        }

        short int len1,len2,len3;

        len1 = high1.length();
        len2 = high2.length();
        len3 = high3.length();

        //cout<<high1<<" "<<high2<<" "<<high3<<endl;

        inFile.close();

        drawText("1. ", 4, -0.4, 0.5);
        drawText(high1, len1, -0.3, 0.5);

        drawText("2. ", 4, -0.4, 0.3);
        drawText(high2, len2, -0.3, 0.3);

        drawText("3. ", 4, -0.4, 0.1);
        drawText(high3, len3, -0.3, 0.1);

        drawText(back_to_menu, 5, -0.3,-1.1);
    }
};
