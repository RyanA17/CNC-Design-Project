//
//  CNC Drawing.c
//
//
//  Created by Ryan A on 6/26/24.
//  Output: x and y coordinates in an array
//
//  Commands: compile gcc -o runCNC CNC/ Drawing.c (to compile into the exe file)
//  ./runCNC (to run the exe file)
//  to do: convert all inputs from mm to feet 
//  1ft = 304.8mm
//ADD IN CONDITIONAL STATEMENTS FOR THE XY SHIFTS

//float length = sqrt(((pow(x,2))+(pow(y,2))));
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50
#define pi 3.14159

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
void check_neg_zero (float,float);

/*-------------------------
Print function
-------------------------*/
void print_func(int array_location){
for (int i = 0; i < array_location; i++){
    printf("(%3.2f,%3.2f)\n\n",locations[i].x_coord, locations[i].y_coord);

    }
}   

/*-------------------------
Square and Rectangle function
-------------------------*/
void square_rectangle(float side, float side1, float x_shift, float y_shift){

int z = 0;

if (side == side1 && side > 50){
    printf("side length is too big enter a number less than or equal to 50:");
}//checks if square is too big

if(side != side1){
    if (side > 50 || side1 > 50){
        printf("side length is too big enter a number less than or equal to 50:");
    } 
}//checks if rectangle is too big

    //start top right corner 
        locations[z].x_coord = (side/2) + x_shift;
        locations[z].y_coord = (side1/2) + y_shift;
    z++;

    //move to top left corner 
        locations[z].x_coord = -1*((side/2) + x_shift);
        locations[z].y_coord = (side1/2) + y_shift;
    z++;

    //move to bottom left corner 
        locations[z].x_coord = -1*((side/2) + x_shift);
        locations[z].y_coord = -1*((side1/2) + y_shift);
    z++;

    //move to bottom right corner 
        locations[z].x_coord = (side/2) + x_shift;
        locations[z].y_coord = -1*((side1/2) + y_shift);
    z++;

    //move to top right corner 
        locations[z].x_coord = (side/2) + x_shift;
        locations[z].y_coord = (side1/2) + y_shift;
    z++;

//prints all pairs of xy locations
printf("Coordinates for square/rectangle\n");
print_func(z);

}

/*-------------------------
Circle function  
-------------------------*/
void circle(float radius, float x_shift, float y_shift){ 

int z = 0; //array cell

//start x at the leftmost point in the circle 
x = x_shift - radius;

if (radius > 25){
    printf("Radius is too big please enter a number less than or equal to 25\n");
}//checks if radius is too big 

for (int j = 0; j <= 1; j++){//loops to do top and bottom arc

    //loops for diameter length to find the y values 
    for(int i = 0; i <= radius*2; i++){

        if (j == 0){
            y = sqrt(pow(radius,2) - pow((x - x_shift),2))+y_shift;
            //calculates the value of y at the x coord 
}//top arc
        
        if (j == 1){
            y = (-1*(sqrt(pow(radius,2) - pow((x - x_shift),2))))+y_shift;
            //calculates the value of y at the x coord (negative)
}//bottom arc

            //store the value in the struct 
        locations[z].x_coord = x;
        locations[z].y_coord = y; 

                    x++;//increments the x coord by 1
                    z++;//goes to the next array cell
        }//end loop 
x = x_shift - radius;//reset x coordinate 
}//end loop

printf("Coordinates for circle\n");

//calls the print function
print_func(z);

}//end function

/*-------------------------
Triangle function
-------------------------*/
void triangle(float base, float x_shift, float y_shift){

int z = 0;

//find the height of the triangle
float height = sqrt(pow(base,2) - pow((base/2),2));

if (base > 50) {
    printf("base is too big please enter a number smaller than 50:");
}

//bottom left of triangle 
    locations[z].x_coord = -1*(base/2) + x_shift;
    locations[z].y_coord = -1*(height/2) + y_shift;
z++;

//top point of triangle 
    locations[z].x_coord = 0 + x_shift;
    locations[z].y_coord = (height/2) + y_shift;
z++;

//bottome right of triangle
    locations[z].x_coord = (base/2) + x_shift;
    locations[z].y_coord = -1*(height/2) + y_shift;
z++;

//starting point
    locations[z].x_coord = -1*(base/2) + x_shift;
    locations[z].y_coord = -1*(height/2) + y_shift;
z++;

printf("Coordinates for triangle\n");
print_func(z);

}//end function

/*-------------------------
Line function
-------------------------*/
void line(float length, float x_shift, float y_shift){

if (length > 50){
    printf("line too long enter a number less than 50:");
}

int z = 0;

    locations[z].x_coord = -1*(length/ 2) + x_shift;
    locations[z].y_coord = 0 + y_shift;
z++;

    locations[z].x_coord = (length/2) + x_shift;
    locations[z].y_coord = 0 + y_shift;
z++;

printf("Coordinates for line\n");
print_func(z);

}//end function 

/*-------------------------
Points function
-------------------------*/
void points(float x, float y){

if (x > 50 || y > 50) {
    printf("Coordinates are out of the plane enter a number less than 50:");
}

int z = 0;
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

printf("Coordinate for point\n");
print_func(z);
}

/*-------------------------
N-polygon function
-------------------------*/
void n_polygon(int side, float radius, float x_shift, float y_shift){
int z = 0;

if (radius > 50){
    printf("radius is took big enter a number less than 50:");
}

    for (int i = 0; i <= side; i++) {
    
        locations[z].x_coord = radius * cos(((2*pi*i)/side)+(pi/2)) + x_shift;
        locations[z].y_coord = radius * sin(((2*pi*i)/side)+(pi/2)) + y_shift;
    
        z++;
    }
printf("%d sided polygon\n",side);
print_func(z);
}


/*-------------------------
-------------------------*/
int main(void){
float radius = 2;
float side = 10, side1 = 6;
float base = 4;
float length = 25;
float x = 1, y = 9;

n_polygon(8,10,0,0);


return 0;
}
