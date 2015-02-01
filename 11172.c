#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Relational Operators */
int main(int argc, char *argv[]){
  int num_lines;

  scanf("%d", &num_lines);

  int line;
  char output[num_lines * 2];
  output[0] = '\0';

  for(line=0; line < num_lines; line++){
    int left, right;
    scanf("%d %d", &left, &right);
    if(left < right){
      strcat(output, "<\n");
    }
    else if (left > right){
      strcat(output, ">\n");
    }
    else {
      strcat(output, "=\n");
    }
  }

  printf("%s", output);

  return 0;
}
