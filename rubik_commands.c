#include <stdlib.h>
#include <string.h>
#include "rubik_pieces.h"

Cube createCube(char entries[6][3][3][10]);
void printCube(Cube cube);
void U(Cube cube, void* face, void* up);
void U_(Cube cube, void* face, void* up);
void D(Cube cube, void* face, void* up);
void D_(Cube cube, void* face, void* up);
void R(Cube cube, void* face, void* up);
void R_(Cube cube, void* face, void* up);
void L(Cube cube, void* face, void* up);
void L_(Cube cube, void* face, void* up);
void F(Cube cube, void* face);
void F_(Cube cube, void* face);
void B(Cube cube, void* face);
void B_(Cube cube, void* face);

Cube createCube(char entries[6][3][3][10]){
    /* for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                printf("%s ", entries[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    } */
    Cube cube = (Cube)malloc(sizeof(struct cube));

    Face1 white = (Face1)malloc(sizeof(struct face1));
    strcpy(white->color, "white");
    Face1 yellow = (Face1)malloc(sizeof(struct face1));
    strcpy(yellow->color, "yellow");
    Face2 red = (Face2)malloc(sizeof(struct face2));
    strcpy(red->color, "red");
    Face2 blue = (Face2)malloc(sizeof(struct face2));
    strcpy(blue->color, "blue");
    Face2 orange = (Face2)malloc(sizeof(struct face2));
    strcpy(orange->color, "orange");
    Face2 green = (Face2)malloc(sizeof(struct face2));
    strcpy(green->color, "green");
    cube->white = white;
    cube->blue = blue;
    cube->green = green;
    cube->orange = orange;
    cube->red = red;
    cube->yellow = yellow;

    //White
    Edge edge = (Edge)malloc(sizeof(struct edge));
    white->red = edge;
    red->white = edge;
    edge->face_r = (Face1)white;
    edge->face_l = (Face2)red;

    edge = (Edge)malloc(sizeof(struct edge));
    white->blue = edge;
    blue->white = edge;
    edge->face_r = (Face1)white;
    edge->face_l = (Face2)blue;

    edge = (Edge)malloc(sizeof(struct edge));
    white->orange = edge;
    orange->white = edge;
    edge->face_r = (Face1)white;
    edge->face_l = (Face2)orange;

    edge = (Edge)malloc(sizeof(struct edge));
    white->green = edge;
    green->white = edge;
    edge->face_r = (Face1)white;
    edge->face_l = (Face2)green;

    //Yellow
    edge = (Edge)malloc(sizeof(struct edge));
    yellow->red = edge;
    red->yellow = edge;
    edge->face_r = (Face2)red;
    edge->face_l = (Face1)yellow;

    edge = (Edge)malloc(sizeof(struct edge));
    yellow->blue = edge;
    blue->yellow = edge;
    edge->face_r = (Face2)blue;
    edge->face_l = (Face1)yellow;

    edge = (Edge)malloc(sizeof(struct edge));
    yellow->orange = edge;
    orange->yellow = edge;
    edge->face_r = (Face2)orange;
    edge->face_l = (Face1)yellow;

    edge = (Edge)malloc(sizeof(struct edge));
    yellow->green = edge;
    green->yellow = edge;
    edge->face_r = (Face2)green;
    edge->face_l = (Face1)yellow;

    //Sides
    edge = (Edge)malloc(sizeof(struct edge));
    red->left = edge;
    blue->right = edge;
    edge->face_l = (Face2)blue;
    edge->face_r = (Face2)red;

    edge = (Edge)malloc(sizeof(struct edge));
    blue->left = edge;
    orange->right = edge;
    edge->face_l = (Face2)orange;
    edge->face_r = (Face2)blue;

    edge = (Edge)malloc(sizeof(struct edge));
    orange->left = edge;
    green->right = edge;
    edge->face_l = (Face2)green;
    edge->face_r = (Face2)orange;

    edge = (Edge)malloc(sizeof(struct edge));
    green->left = edge;
    red->right = edge;
    edge->face_l = (Face2)red;
    edge->face_r = (Face2)green;

    //White up
    Corner corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = white->red;
    corner->edge_r = white->blue;
    corner->edge_d = red->left;
    white->blue->corner_up = corner;
    blue->right->corner_down = corner;
    red->white->corner_down = corner;

    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = white->green;
    corner->edge_r = white->red;
    corner->edge_d = green->left;
    white->red->corner_up = corner;
    red->right->corner_down = corner;
    green->white->corner_down = corner;

    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = white->orange;
    corner->edge_r = white->green;
    corner->edge_d = orange->left;
    white->green->corner_up = corner;
    green->right->corner_down = corner;
    orange->white->corner_down = corner;

    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = white->blue;
    corner->edge_r = white->orange;
    corner->edge_d = blue->left;
    white->orange->corner_up = corner;
    orange->right->corner_down = corner;
    blue->white->corner_down = corner;

    //Yellow up
    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = yellow->orange;
    corner->edge_r = yellow->blue;
    corner->edge_d = orange->right;
    yellow->blue->corner_down = corner;
    yellow->orange->corner_up = corner;
    orange->right->corner_up = corner;

    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = yellow->green;
    corner->edge_r = yellow->orange;
    corner->edge_d = green->right;
    yellow->orange->corner_down = corner;
    yellow->green->corner_up = corner;
    green->right->corner_up = corner;

    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = yellow->red;
    corner->edge_r = yellow->green;
    corner->edge_d = red->right;
    yellow->green->corner_down = corner;
    yellow->red->corner_up = corner;
    red->right->corner_up = corner;

    corner = (Corner)malloc(sizeof(struct corner));
    corner->edge_l = yellow->blue;
    corner->edge_r = yellow->red;
    corner->edge_d = blue->right;
    yellow->red->corner_down = corner;
    yellow->blue->corner_up = corner;
    blue->right->corner_up = corner;

    strcpy(white->red->corner_down->color_u, entries[0][0][0]);
    strcpy(white->red->color_r, entries[0][0][1]);
    strcpy(white->red->corner_up->color_u, entries[0][0][2]);
    strcpy(white->blue->color_r, entries[0][1][0]);
    strcpy(white->green->color_r, entries[0][1][2]);
    strcpy(white->orange->corner_up->color_u, entries[0][2][0]);
    strcpy(white->orange->color_r, entries[0][2][1]);
    strcpy(white->orange->corner_down->color_u, entries[0][2][2]);

    Face2 sides[] = {red, blue, orange, green};
    for(int i = 1 ; i < 5 ; i++){
        strcpy(sides[i-1]->yellow->corner_down->color_r, entries[i][0][0]);
        strcpy(sides[i-1]->yellow->color_r, entries[i][0][1]);
        strcpy(sides[i-1]->yellow->corner_up->color_l, entries[i][0][2]);
        strcpy(sides[i-1]->left->color_r, entries[i][1][0]);
        strcpy(sides[i-1]->right->color_l, entries[i][1][2]);
        strcpy(sides[i-1]->white->corner_down->color_l, entries[i][2][0]);
        strcpy(sides[i-1]->white->color_l, entries[i][2][1]);
        strcpy(sides[i-1]->white->corner_up->color_r, entries[i][2][2]);
    }

    strcpy(yellow->red->corner_up->color_u, entries[5][0][0]);
    strcpy(yellow->red->color_l, entries[5][0][1]);
    strcpy(yellow->red->corner_down->color_u, entries[5][0][2]);
    strcpy(yellow->green->color_l, entries[5][1][0]);
    strcpy(yellow->blue->color_l, entries[5][1][2]);
    strcpy(yellow->orange->corner_down->color_u, entries[5][2][0]);
    strcpy(yellow->orange->color_l, entries[5][2][1]);
    strcpy(yellow->orange->corner_up->color_u, entries[5][2][2]);

    return cube;
}

void printCube(Cube cube){
    Face1 white = cube->white;
    Face1 yellow = cube->yellow;
    Face2 red = cube->red;
    Face2 blue = cube->blue;
    Face2 orange = cube->orange;
    Face2 green = cube->green;
    
    printf("%s %s %s\n", white->red->corner_down->color_u, white->red->color_r, white->red->corner_up->color_u);
    printf("%s %s %s\n", white->blue->color_r, white->color, white->green->color_r);
    printf("%s %s %s\n", white->orange->corner_up->color_u, white->orange->color_r, white->orange->corner_down->color_u);
    printf("\n");

    Face2 sides[] = {red, blue, orange, green};
    for(int i = 0 ; i < 4 ; i++){
        printf("%s %s %s\n", sides[i]->yellow->corner_down->color_r, sides[i]->yellow->color_r, sides[i]->yellow->corner_up->color_l);
        printf("%s %s %s\n", sides[i]->left->color_r, sides[i]->color, sides[i]->right->color_l);
        printf("%s %s %s\n", sides[i]->white->corner_down->color_l, sides[i]->white->color_l, sides[i]->white->corner_up->color_r);
        printf("\n");
    }

    printf("%s %s %s\n", yellow->red->corner_up->color_u, yellow->red->color_l, yellow->red->corner_down->color_u);
    printf("%s %s %s\n", yellow->green->color_l, yellow->color, yellow->blue->color_l);
    printf("%s %s %s\n", yellow->orange->corner_down->color_u, yellow->orange->color_l, yellow->orange->corner_up->color_u);
    printf("\n");
}

void U(Cube cube, void* face, void* up){
    if((cube->white == face) || (cube->yellow == face)){
        Face1 face1_ = (Face1)face;
        Face2 up_ = (Face2)up;
        Face1 face2_ = up_->yellow->face_l;
        Face2 left = up_->left->face_l;
        Face2 right = up_->right->face_r;
        if(face1_ == cube->white){
            if(up_ == cube->red){
                face1_->red = up_->right;
                face1_->red->face_r = face1_;
                face2_->red = up_->left;
                face2_->red->face_l = face2_;
                right->left = up_->yellow;
                right->left->face_r = right;
                left->right = up_->white;
                left->right->face_l = left;
            }
        }else{
            //
        }
    }else{
        face = (Face2)face;
        if((cube->white == up) || (cube->yellow == up)){
            up = (Face1)up;
        }else{
            up = (Face2)up;
        }
    }
}

/* void U_(Cube cube, void* face, void* up);
void D(Cube cube, void* face, void* up);
void D_(Cube cube, void* face, void* up);
void R(Cube cube, void* face, void* up);
void R_(Cube cube, void* face, void* up);
void L(Cube cube, void* face, void* up);
void L_(Cube cube, void* face, void* up);
void F(Cube cube, void* face);
void F_(Cube cube, void* face);
void B(Cube cube, void* face);
void B_(Cube cube, void* face);
 */