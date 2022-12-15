#include <stdio.h>
#include <string.h>
#include "rubik_pieces.h"
#include "rubik_commands.c"

int main(){
    char input[6][3][3][10];

    printf("Order for input:\n");
    printf("White\nRed\nBlue\nOrange\nGreen\nYellow\n\n");
    printf("For color white and yellow, top side should be red\n");
    printf("For all other colors, yellow is top\n");

    char color[10];

    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                scanf("%s", color);
                strcpy(input[i][j][k], color);
            }
        }
    }

    /* for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                printf("%s ", input[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    } */

    Cube cube = createCube(input);

    printCube(cube);

    U(cube, cube->white, cube->red);
}