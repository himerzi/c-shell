/**
 *  shell.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <readline/readline.h>
//#include <readline/history.h>
#include "parse.h"   //include declarations for parse-related structs


int main(int argc, char **argv) {
  (void) argc; (void) argv;     /* we don't use argc or argv */
  parseInfo *info;
  while(1) {
    
    char *in_line;
    in_line = readline("-->");
    

    info = parse(in_line);

// print_info(in_line);

  }

  //  free_info(info);
 }
