#include <nds.h>
#include <gl2d.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <nf_lib.h>
#include <cmath>
using namespace std;

void debuger(int pos){
    string str = to_string(pos);
    std::string str2 = str;
    const char* c = str.c_str();
    nocashMessage(c);
}

int count(int Z,int C){
    Z = pow(Z,2) + C;
    return(Z);
}

int main(void) {
    float X;
    float Y;
    float Cx;
    float Cy;
    int Size = 4;
    //kolory RGB
    int RC;
    int GC;
    int BC;
    float Z;
    int iterations = 1;
    int ScreenHeight = 192 / Size;
    int ScreenWidth = 256 / Size;
    //is this pixel a part of the set?
    int isPart = 0;

    videoSetMode(MODE_5_3D);
    glScreen2D();
    while (1){
        scanKeys();
        glBegin2D();
        X=0;
        Y=0;
        //kolory RGB
        RC = 0;
        GC = 255;
        BC = 0;
        //kolorowanie pixeli
        for (int i = 0;i <= ScreenHeight -1; i++){
            RC = 0;
            for (int i = 0;i <= ScreenWidth - 1; i++){
                //obliczanie czy liczba należy do zbioru
                //isPart = 0;
                RC = 0;
                Z = 0;
                Cx = (X - (256/2))/10;
                Cy = (Y - (192/2))/10;
                for (int i = 0;i <= iterations;i++){
                    Z = count(Z,Cx);
                    if (Z > ScreenWidth){
                        isPart = 1;
                    }
                }
                for (int i = 0;i <= iterations;i++){
                    Z = count(Z,Cy);
                    //this line only gets executed when there is a number that is a part of the set
                    if (Z > ScreenHeight && isPart==1){
                        RC = 255;
                        debuger(Cx);
                        nocashMessage(":");
                        debuger(Cy);
                        nocashMessage("||");
                    }
                }
                glBoxFilled(X,Y,X+Size-1,Y+Size-1,RGB15(RC,GC,BC));
                X = X + Size;
            }
            X = 0;
            Y = Y + Size;
        }
        //glBoxFilled(0,0,Size,Size,RGB15(0,0,0));

        glEnd2D();
        glFlush(0);
        swiWaitForVBlank();
    }
} 
