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

//store xy coordinates
typedef struct{

    float x_coord;
    float y_coord;

}location;

location locations[MAX];//array of structs

//xy values start at the origin
float x = 0, y = 0;

/*-------------------------
Function declarations
-------------------------*/
void print_func(int z);
void square_rectangle(float side, float side1);
void circle(float radius, float x_shift, float y_shift);
void triangle(float base, float height);
void line(float length);
void points(float x, float y);


/*-------------------------
Print function
-------------------------*/
void print_func(int z){
    printf("  X            Y  \n");
    printf("------------------\n");
for (int i = 0; i < z; i++){
    printf("%3.3f",locations[i].x_coord);
    printf("    |   ");
    printf("%3.3f\n",locations[i].y_coord);
    printf("         |   \n");

    }
}   

/*-------------------------
Square and Rectangle function
-------------------------*/
void square_rectangle(float side, float side1){

int z = 0;

    //start bottom left corner 
    x = 0;
    y = 0;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to bottom right corner 
    x = side;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to top right corner 
    y = side1;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to top left corner 
    x = 0;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

    //move to bottom left corner 
    y = 0;
        locations[z].x_coord = x;
        locations[z].y_coord = y;
    z++;

//prints all pairs of xy locations
print_func(z);

}

/*-------------------------
Circle function
-------------------------*/
void circle(float radius, float x_shift, float y_shift){ 

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

for (int j = 0; j <= 1; j++){//loops to do top and bottom arc

    //loops for diameter length to find the y values 
    for(int i = 0; i <= radius*2; i++){

        if (j == 0){//top arc
            y = (sqrt(pow(radius,2) - pow((x-x_shift),2)))+y_shift;
            //calculates the value of y at the x coord 
}
        
        if (j == 1){//bottom arc 
            y = (-1*((sqrt(pow(radius,2) - pow((x-x_shift),2)))))+y_shift;
            //calculates the value of y at the x coord (negative)
}

            //store the value in the struct 
        locations[z].x_coord = x;
        locations[z].y_coord = y; 

                    x++;//increments the x coord by 1
                    z++;//goes to the next array cell
        }//end loop 
x = x_shift - radius; ;//reset x coordinate (should it start at right most point?)
}//end loop

printf("Coordinates for circle\n");

//calls the print function
print_func(z);

}//end function

/*-------------------------
Triangle function
-------------------------*/
void triangle(float base, float height){

int z = 0;

x = x + base;//bottom right
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

x = 0;//top left 
y = y + height;
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

y = 0;//back to start
    locations[z].x_coord = x;
    locations[z].y_coord = y;
z++;

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

x = x - length/ 2;
    locations[z].x_coord = x;
    locations[z].y_coord = 0;
z++;

x = x + length;
    locations[z].x_coord = x;
    locations[z].y_coord = 0;
z++;

print_func(z);

}//end function 

/*-------------------------
Points function
-------------------------*/
void points(float x, float y){

}

int main(void){

int h = 4; //center x distance fram origin
int k = 2; //center y distance from origin
int radius = 2;

    circle(radius,h,k);
    //square_rectangle(h,h);
    //triangle(h,k);
    //line(h);
    //points(h,k)

return 0;
}
