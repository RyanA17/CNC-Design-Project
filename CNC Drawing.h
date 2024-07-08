//
//  CNC Drawing.h
//  
//
//  Created by Ryan A on 7/8/24.
//

#ifndef CNC_Drawing_h
#define CNC_Drawing_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50
#define pi 3.14159 //use M_PI?

typedef struct{
float x_coord;
float y_coord;
}location;//store xy coordinates

location locations[MAX];//array of structs
float x = 0, y = 0;//xy values start at the origin

/*-------------------------
Function declarations
-------------------------*/
void print_func(int);
void square_rectangle(float,float,float,float);
void circle(float,float,float);
void triangle(float,float,float);
void line(float,float,float);
void points(float,float);
void n_polygon(int,float,float,float);


#endif /* CNC_Drawing_h */
