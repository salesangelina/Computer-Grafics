#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define IMAGE_WIDTH  512 // number of coluns
#define IMAGE_HEIGHT 512 // number of lines of the image

unsigned char * FBptr;

struct color{
 unsigned char R;
 unsigned char G;
 unsigned char B;
 unsigned char A;
};
 
struct point{
 int x;
 int y;
};

color red = {255, 0, 0, 255};
color green = {0,255, 0, 255};
color blue = {0, 0, 255, 255};


#endif // _DEFINITIONS_H_

