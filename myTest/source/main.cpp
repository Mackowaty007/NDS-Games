#include <nds.h>
#include <gl2d.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <nf_lib.h>
using namespace std;

void converter(int pos){
    string str = to_string(pos);
    std::string str2 = str;
    const char* c = str.c_str();
    nocashMessage(c);
}
int main(void) {
    float Y = 0;
    float X = 0;
    float speedY = 0;
    float speedX = 0;
    float speed = 1;
    int ex = (rand() % 100 + 1);
    int ey = (rand() % 100 + 1);
    int button;
    
    converter(ex);
    converter(ey);

    videoSetMode(MODE_5_3D);
    glScreen2D();

    while(1){
        scanKeys();

        button = keysCurrent();
        if (button & KEY_LEFT){
            speedX = -speed;
        }
        else if (button & KEY_RIGHT){
            speedX = speed;
        }
        else{
            speedX = 0;
        }
        if (button & KEY_UP){
            speedY = -speed;
        }
        else if (button & KEY_DOWN){
            speedY = speed;
           }
        else{
            speedY = 0;
        }
        Y += speedY;
        X += speedX;

        glBegin2D();

        glLine(X,Y,X+20,Y+20,RGB15(0,255,0));
        glBoxFilled(ex,ey,ex+10,ey+10,RGB15(255,0,0));

        glEnd2D();
        glFlush(0);
        swiWaitForVBlank();
    }
} 
