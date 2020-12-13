#include <nds.h>
#include <math.h>
#include <gl2d.h>

int mandlebrot(int cX,int cY){
    int zX = 0;
    int zY = 0;
    int n = 0;
    int pX;
    int pY;
    int d;
    const int maxIterations = 5;

    do {
        pX = pow(zX,2) - pow(zY,2);
        pY = 2*zX * zY;
        zX = pX + cX;
        zY = pY + cY;
        d = sqrt(pow(zX,2)-pow(zY,2));
        n += 1;
    }while(d <= 2 && n < maxIterations);
    return (n,d<=2);
}

int main(void){
    //setup
    videoSetMode(MODE_5_3D);
    glScreen2D();
    //var declaration
    const int width = 256;
    const int height = 192;
    float complexX;
    float complexY;
    const int realSetStart = -2;
    const int realSetEnd = 1;
    const int imaginarySetStart = -1;
    const int imaginarySetEnd = 1;
    int isMandlebrotSet;
    int color;

    while(1){
        glBegin2D();
        for (int i=0;i<width;i++){
            for (int j=0;j<height;j++){
                complexX = realSetStart + (i / width) * (realSetEnd - realSetStart);
                complexY = imaginarySetStart  + (j / height) * (imaginarySetEnd - imaginarySetStart);
                //const [m,isMandlebrotSet]
                isMandlebrotSet = mandlebrot(complexX,complexY);
                //float isMandlebrotSet = mandlebrot(complexX,complexY);
                if (isMandlebrotSet){
                    color = 255;
                }
                else{
                    color = 0;
                }
                glBoxFilled(i,j,i+1,j+1,RGB15(color,0,0));
            }
        }
        
        glEnd2D();
        glFlush(0);
        swiWaitForVBlank();
    }
}