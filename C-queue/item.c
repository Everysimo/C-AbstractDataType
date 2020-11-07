#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

struct punto{
    float ascissa;
    float ordinata;
};

int eq(item a, item b){
   return(a==b);
}

float ascissa(item p){
      return p->ascissa;
}

float ordinata(item p){
      return p->ordinata;
}

item creapunto(float x,float y)
{
    item punto=malloc(sizeof(struct punto));

    punto->ascissa=x;
    punto->ordinata=y;

    return punto;
}

void OutputItem(item p)
{
    printf("(%.2f,%.2f)\n",p->ascissa,p->ordinata);
}

float distanza(item p1, item p2){
      float dx,dy;

      dx= (p1->ascissa)-(p2->ascissa);
      dy= (p1->ordinata)-(p2->ordinata);

      return sqrt((dx*dx)+(dy*dy));
}

void InputItem(float *x)
{
    scanf("%f",x);
}

int puntosimmetrico(item p1,item p2)
{
    float x1,x2,y1,y2;
    int xsimmetrico,ysimmetrico;

    x1=p1->ascissa;
    x2=p2->ascissa;
    y1=p1->ordinata;
    y2=p2->ordinata;

    xsimmetrico=(x2+x1)/2;
    ysimmetrico=(y2+y1)/2;
    
    if(xsimmetrico==0 && ysimmetrico==0)
        return 0;
    else
        return 1;
}