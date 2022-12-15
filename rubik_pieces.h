#ifndef _RUBIK_H_
#define _RUBIK_H_

typedef struct face1* Face1;
typedef struct face2* Face2;
typedef struct face* Face;
typedef struct edge* Edge;
typedef struct corner* Corner;
typedef struct cube* Cube;

struct face1{
    char color[10];
    Edge red;
    Edge blue;
    Edge orange;
    Edge green;
};

struct face2{
    char color[10];
    Edge white;
    Edge yellow;
    Edge left;
    Edge right;
};

struct edge{
    char color_l[10];
    char color_r[10];
    Corner corner_up;
    Corner corner_down;
    void* face_l;
    void* face_r;
};

struct corner{
    char color_u[10];
    char color_l[10];
    char color_r[10];
    Edge edge_d;
    Edge edge_l;
    Edge edge_r;
};

struct cube{
    Face1 white;
    Face1 yellow;
    Face2 red;
    Face2 blue;
    Face2 orange;
    Face2 green;
};

#endif