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

//let x be the x axis
//let y be the y axis
float coordinates[ROW];

//struct to store x and y coordinates 
    typedef struct{
        float x;
        float y
    }location;

location loc1;

//test 
float t_matrix[5][5];//test matrix 
float num = 0;
float num1 = 0;
for(float j = 0; j < width; j++){
        for (float i = 0; i < height; i++)
        {
            t_matrix[i][j];

            loc1.x = num;
            loc1.y = num1;  
        num++;

        }
    num1++;
    }

}
-------------------------*/
/*-------------------------
Circle code
-------------------------*/
void circle(float radius, float x_shift, float y_shift){ 
/*
typedef struct{

x_coord;
y_coord;

}location;

location locations[MAX];
*/



float x = 0, y = 0;

//start x at the leftmost point in the circle 
x = x_shift - radius;  

//check is the values are in the boundary of the base to make a full circle
if (radius > 25){
    
    printf("Radius is too big please enter a number less than or equal to 25\n");
}//checks if radius is too big 

    if (radius == 25 && x_shift > 0 && y_shift >0){
        
        printf("x axis shift and y axis shift have to be zero\n");
    }//if raidus = max checks if the shifts are 0

        if (fabs(x) >= 25 || fabs(x = x_shift + radius >= 25)){
            
            printf("circle is too far left decrease raidus or x axis shift\n");
        }//checks if the x axis shifts are too large

            if (fabs(y = y_shift + radius) >= 25 || fabs(y = y_shift - radius) >= 25){
                
                printf("circle is too high decrease raidus or y axis shift\n");
            } //checks if the y axis shifts are too large


    //top arc of circle
    printf("top arc\n");

    //loops for radius length to find the y values 
for(int i = 0; i <= radius*2; i++){
        y = (sqrt(pow(radius,2) - pow((x-x_shift),2)))+y_shift;//calculates the value of y at the x coord 

            //prints the coordinate value 
                printf("x coordinate: %f\n",x);
                printf("y coordinate: %f\n\n",y);
                    x++;//increments the x coord by 1
    }//end loop 


x = x_shift - radius; ;//reset x coordinate
    
    //bottom arc of circle 
    printf("bottom arc\n");

    //loops for radius length to find the y values 
for(int j = 0; j<= radius*2; j++){
        y = (-1*((sqrt(pow(radius,2) - pow((x-x_shift),2)))))+y_shift;//calculates the value of y at the x coord (negative)
            
            if (y == -0){//if there is a negative zero it makes the zero positive
                y = fabs(y);
            }
            
                printf("x coordinate: %f\n",x);
                printf("y coordinate: %f\n\n",y);
                    x++;
    }//end loop
}//end function




int main(void){

int x = 0; //x distance fram origin
int y = 0; //y distance from origin
int radius = 20;
    circle(radius,x,y);





return 0;
}
