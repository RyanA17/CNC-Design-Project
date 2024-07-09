/*---------------------------------------
CNC Drawing.c

 Created by Ryan A on 6/26/24.
Output: x and y coordinates in an array

 Commands: compile gcc -o runCNC CNC/ Drawing.c (to compile into the exe file)
./runCNC (to run the exe file)

to do: convert all inputs from mm to feet 
(1ft = 304.8mm)
add in conditional statments for the xy shifts
---------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "CNC Drawing.h"

/*-------------------------
Print function
-------------------------*/
void print_func(int max_location){
for (int i = 0; i < max_location; i++){
    printf("(%3.2f,%3.2f)\n\n",locations[i].x_coord, locations[i].y_coord);

    }//end loop
}//loops through the array of xy coordinates

/*-------------------------
Square and Rectangle function
-------------------------*/
void square_rectangle(float side, float side1, float x_shift, float y_shift){

int z = 0;//starts in first cell of the array

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
    z++;//increments the array cell by one

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

int z = 0; //first array cell

//start x at the leftmost point in the circle 
x = x_shift - radius;

if (radius > 25){
    printf("Radius is too big please enter a number less than or equal to 25\n");
}//checks if radius is too big 

for (int j = 0; j <= 1; j++){//loops to do top then bottom arc

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
}//checks to see if the triangle is too big

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
//left most point 
    locations[z].x_coord = -1*(length/ 2) + x_shift;
    locations[z].y_coord = 0 + y_shift;
z++;

//right most point
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
//stores the location of the point in an array
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

char shape[10];
char test[10] = "rectangle";
printf("Choose from below:\n");
printf("rectangle\n");
printf("circle\n");
printf("triangle\n");
printf("line\n");
printf("points\n");
printf("Enter what you want:\n");
scanf("%s\n",shape);
printf("You chose to make a: %s\n",shape);

switch (shape[10]){
case test[10]:
    /* code */
    break;

default:
    break;
}


n_polygon(8,10,0,0);


return 0;
}
