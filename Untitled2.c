#include<stdio.h>

void main() {


char color;

int num;



printf("Please enter the number(0-6): ");

scanf("%d",&num);


color=1<<num;


printf("\n\n");


if( color==1)

printf("Violet");


else if( color==2)

printf("Indigo");


else if( color==4)

printf("Blue");


else if( color==8)

printf("Green");


else if(color==16)

printf("Yellow");


else if( color==32)

printf("Orange");


else if(	color==64)

printf("Red");


else

printf("Wrong color number!");



}
