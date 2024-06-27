//
//  CNC Drawing.c
//
//
//  Created by Ryan Achong on 6/26/24.
//Output: x and y coordinates in an array 

#include <stdio.h>
#include <math.h>

#define ROW 50 /* max rows */
#define COL 50 /* max columns */
//1ft = 304.8mm

/*-------------------------
Functions
-------------------------*/
//void circle;

int i = 0; //Rows
int j = 0; //Columns
int num = 0;

int main(void){

//define the matrix with the max row and columns
int matrix[ROW][COL];

for(int j = 0; j < 10; j++){
    for (int i = 0; i < 10; i++) {
        matrix[i][j] = num;
        
        printf("%d",matrix[i][j]);
    };
    
    printf("\n");
    num++;
};
return 0;
}
