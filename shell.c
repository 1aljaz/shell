#include <stdio.h>
#include <stdlib.h>

#define in_buff_limit 1024

char* sh_read_line();

int main(){
  printf("-->");
  char* line = sh_read_line();
  printf("%s", line);
  return 0;
}

char* sh_read_line(){
  int c;
  char* line = malloc(in_buff_limit);
  int curr = 0;
  int buffer = in_buff_limit;

  while (1){
    c = getchar();
    if ((c == EOF) || (c == '\n')){
      line[curr+1] = '\0';
      return line;
    }

    if (curr + 1 >= buffer){
      buffer *= 2;
      realloc(line, buffer);
    }
  }
}
