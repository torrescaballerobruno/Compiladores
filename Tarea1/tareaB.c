#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX 10000
#define SIZEMATCH(match) (match.rm_eo - match.rm_so)

int evaluarExp(regex_t p, char *cadena) {
  regmatch_t *con;
  int i;
  con = alloca(sizeof(regmatch_t)*(p.re_nsub+1));
  if (regexec(&p, cadena, p.re_nsub, con, 0)) {
    printf("Cadena no aceptada: %s\n",cadena);
  }else {
    for(i=0; i < p.re_nsub; i++) {
      if (con[i].rm_so != -1) {
        size_t length = SIZEMATCH(con[i]);
        char * sub;

        sub = ( char *) malloc(length+1);
        strncpy(sub,cadena+con[i].rm_so,length);
        sub[length] = '\0';
        printf("Cadena aceptada %s\n",sub);
        free(sub);
      }
    }
  }
}

int main() {
  char *cadena = (char *) malloc(MAX);
  char *expresion = (char *) malloc(MAX);
  char trash; regex_t p; int err;

  printf("Expresion = "); scanf("%[^\n]", expresion);
  if (err=regcomp(&p,expresion,REG_EXTENDED|REG_NEWLINE)){
    printf("Error compiling regular expression!\n");
    exit(err);
  }
  scanf("%c",&trash);
  printf("Cadena = "); scanf("%[^\n]", cadena);
  scanf("%c",&trash);
  evaluarExp(p, cadena);
}