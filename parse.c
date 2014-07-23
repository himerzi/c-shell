/**
 *  parse.c
 */
#include <stdio.h>
#include <string.h>
#include "parse.h"
#include <ctype.h>

  /* void init_info(parseInfo *p) { */
  /*     initialize parseInfo struct */
  /* } */

  /* parse a single command */
void parse_command(char * command, struct commandType *comm) {
  comm->command = command;
  comm->VarNum = 0;
  //printf("parse_command: parsing a single command\n");
}

/*   parse commandline for space separated commands */
parseInfo * parse(char *cmdline){
  parseInfo *prse;
  commandType *cmd_type;
  char *next_toke;
  prse  = malloc(sizeof(parseInfo));

  next_toke = strtok(cmdline, " ");

  int i = 0;
  while(next_toke != NULL){    
    next_toke = strtok(NULL, " ");
    parse_command(next_toke,  prse->CommArray[i]);
    printf("parse token: %c\n", cmdline[i]);
    i++;
  } 
  return prse;
}

  /* /\* prints out parse struct *\/ */
  /* void print_info (parseInfo *info) { */
  /*    foreach type in parseInfo { */
  /*      print "type_name: type" */
  /*    } */
  /* } */


  void print_info (char *in_line) {
     
    printf("%s\n", in_line);
    
  }

  /* /\*  free memory used in parseInfo *\/ */
  /* void free_info (parseInfo *info) { */
  /*    foreach memory_block in parseInfo */
  /*       free(memory_block) */
  /* } */
