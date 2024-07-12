//
//  CNCdrawing.h
//  
//
//  Created by Ryan A on 7/11/24.
//

#ifndef CNCdrawing_h
#define CNCdrawing_h

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


#endif /* CNCdrawing_h */
