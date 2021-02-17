#include <stdio.h>
void createSymbol(int range, char symbol){for(;range>=1;range--){printf("%c ", symbol);}}
void d_program();void main(){printf("\n---------------------\n\n");d_program();
printf("\n\n---------------------\n\n");}
int input(char text[]){int inRET;printf("%s", text);scanf("%d", &inRET);return inRET;}