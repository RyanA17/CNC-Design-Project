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

//float length = sqrt(((pow(x,2))+(pow(y,2))));
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50

typedef struct{
float x_coord;
float y_coord;
}location;//store xy coordinates

location locations[MAX];//array of structs
float x = 0, y = 0;//xy values start at the origin

/*-------------------------
Function declarations
-------------------------*/
void print_func(int array_location);
void square_rectangle(float side, float side1);
void circle(float radius);
void triangle(float base);
void line(float length);
void points(float x, float y);


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
void square_rectangle(float side, float side1){

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
    x = side/2;
    y = side1/2;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to top left corner 
    x = x - side;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to bottom left corner 
    y = y - side1;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to bottom right corner 
    x = x + side;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to bottom left corner 
    y = y + side1;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

//prints all pairs of xy locations
printf("Coordinates for square/rectangle\n");
print_func(z);

}

/*-------------------------
Circle function
-------------------------*/
void circle(float radius){ 

int z = 0; //array cell

//start x at the leftmost point in the circle 
x = -1*(radius);

if (radius > 25){
    printf("Radius is too big please enter a number less than or equal to 25\n");
}//checks if radius is too big 

for (int j = 0; j <= 1; j++){//loops to do top and bottom arc

    //loops for diameter length to find the y values 
    for(int i = 0; i <= radius*2; i++){

        if (j == 0){//top arc
            y = sqrt(pow(radius,2) - pow(x,2));
            //calculates the value of y at the x coord 
}
        
        if (j == 1){//bottom arc 
            y = -1*(sqrt(pow(radius,2) - pow(x,2)));
            //calculates the value of y at the x coord (negative)
}

            //store the value in the struct 
        locations[z].x_coord = x;
        locations[z].y_coord = y; 

                    x++;//increments the x coord by 1
                    z++;//goes to the next array cell
        }//end loop 
x = -1*(radius);//reset x coordinate 
}//end loop

printf("Coordinates for circle\n");

//calls the print function
print_func(z);

}//end function

/*-------------------------
Triangle function
-------------------------*/
void triangle(float base){

int z = 0;

//find the height of the triangle
float height = sqrt(pow(base,2) - pow((base/2),2));


//bottom left of triangle 
y = -1*(height/2);
x = -1*(base/2);
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

//top point of triangle 
x = 0;
y = (height/2);
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

//bottome right of triangle
x = (base/2);
y = -1*(height/2);
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

y = -1*(height/2);
x = -1*(base/2);
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

printf("Coordinates for triangle\n");
print_func(z);

}//end function

/*-------------------------
Line function
-------------------------*/
void line(float length){

if (length > 50){
    printf("line too long enter a number less than 50:");
}

int z = 0;

x = -1*(length/ 2);
    locations[z].x_coord = x;
    locations[z].y_coord = 0;
z++;

x = (length/2);
    locations[z].x_coord = x;
    locations[z].y_coord = 0;
z++;

printf("Coordinates for line\n");
print_func(z);

}//end function 

/*-------------------------
Points function
-------------------------*/
void points(float x, float y){
int z = 0;
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;
printf("Coordinate for point\n");
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

square_rectangle(side,side1);
circle(radius);
triangle(base);
line(length);
points(x,y);


return 0;
}
