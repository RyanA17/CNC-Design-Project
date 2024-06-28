//
//  CNC Drawing.c
//
//
//  Created by Ryan Achong on 6/26/24.
//  Output: x and y coordinates in an array
//
//  Commands: compile gcc -o runCNC CNC/ Drawing.c (to compile into the exe file)
//  ./runCNC (to run the exe file)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50
//1ft = 304.8mm

/*-------------------------
Functions
-------------------------*/
void square(float height,float width);
void circle(float radius, float x_center, float y_center);

/*-------------------------
Square code

void square(float height,float width){

}
-------------------------*/
/*-------------------------
Circle code
-------------------------*/
void circle(float radius, float x_shift, float y_shift){ 

//struct to store the xy pairs 
typedef struct{

float x_coord;
float y_coord;

}location;

location locations[MAX];//array of structs


float x = 0, y = 0;
int z = 0; //array cell

//start x at the leftmost point in the circle 
x = x_shift - radius;

//check is the values are in the boundary of the base to make a full circle
if (radius > 25){
    
    printf("Radius is too big please enter a number less than or equal to 25\n");
}//checks if radius is too big 

    if (radius == 25 && x_shift > 0 && y_shift >0){
        
        printf("x axis shift and y axis shift have to be zero\n");
    }//if raidus = max checks if the shifts are 0

        if (fabs(x) >= 25 || abs(x_shift + radius >= 25)){
            
            printf("circle is too far left decrease raidus or x axis shift\n");
        }//checks if the x axis shifts are too large

            if (fabs(y_shift + radius) >= 25 || fabs(y_shift - radius) >= 25){
                
                printf("circle is too high decrease raidus or y axis shift\n");
            } //checks if the y axis shifts are too large


    //loops for diameter length to find the y values 
for(int i = 0; i <= radius*2; i++){
        y = (sqrt(pow(radius,2) - pow((x-x_shift),2)))+y_shift;//calculates the value of y at the x coord 

            //store the value in the struct 
        locations[z].x_coord = x;
        locations[z].y_coord = y; 

                    x++;//increments the x coord by 1
                    z++;//goes to the next array cell
    }//end loop 


x = x_shift - radius; ;//reset x coordinate (should it start at right most point?)
    //loops for diameter length to find the y values 
for(int j = 0; j<= radius*2; j++){
        y = (-1*((sqrt(pow(radius,2) - pow((x-x_shift),2)))))+y_shift;//calculates the value of y at the x coord (negative)
            
            if (y == -0){//if there is a negative zero it makes the zero positive
                y = fabs(y);
            }
            
            locations[z].x_coord = x;
            locations[z].y_coord = y;

                    x++;
                    z++;
    }//end loop


for (int i = 0; i < z; i++){
    
    printf("x coordinate %0.3f\n",locations[i].x_coord);
    printf("y coordinate %0.3f\n\n",locations[i].y_coord);

}

}//end function




int main(void){

int x = 4; //center x distance fram origin
int y = 2; //center y distance from origin
int radius = 2;
    circle(radius,x,y);





return 0;
}
