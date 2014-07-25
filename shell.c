/**
 *  shell.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "parse.h"   //include declarations for parse-related structs


int main(int argc, char **argv) {
  // parseInfo *info;  
  while(1) {
   
    char *in_line;
    in_line = readline("-->");
    
    //info = 
    parse(in_line);
    
    // print_info(in_line);
  }

  //  free_info(info);
 }
