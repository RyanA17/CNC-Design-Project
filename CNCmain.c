//
//  CNCmain.c
//  
//
//  Created by Ryan A on 7/11/24.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "CNCdrawing.h"

/*-------------------------
-------------------------*/
int main(void){

square_rectangle(10,4,0,0);
circle(5,0,0);
triangle(3,0,0);
line(20,0,0);
points(10,4);
n_polygon(8,10,0,0);


return 0;
}
