/**
 *  parse.c
 *  The parser parses these symbols <, >, |, &.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include <ctype.h>

/* void init_info(parseInfo *p) { */
/*     initialize parseInfo struct */
/* } */

/* parse a single command */
/* void parse_command(char * command, commandType *comm) { */
/*   char *cmd_token; */
  
/*   cmd_token = strtok(command, " "); */
/*   if (cmd_token != NULL) comm->command = cmd_token; */
  
/*   int i = 0; */
/*   while(cmd_token != NULL){ */
/*     cmd_token = strtok(NULL, " "); */
/*     comm->VarList[i] = cmd_token; */
/*     i++; */
/*   } */
/* } */

char** split(char *cmdline, char * delim) {
  char **tokens = (char **) malloc(MAX_TOKENS * sizeof(char*));

  // no point in malloc-ing for each string since we re-point to the return of strtok, so these malloc will be lost
  //char * token_generator = strtok(cmdline, delim);
  /* int i = 0; */
  /* while(token_generator != NULL) { */
  /*   tokens[i] = token_generator; */
  /*   token_generator = strtok(NULL, delim); */
  /*   i++; */
  /* } */

  return tokens;
}

/*   parse commandline for space separated commands */
parseInfo * parse(char *cmdline){
  //parseInfo *prse;// = malloc(sizeof(parseInfo));
  //commandType *cmd_type;
  //  char *next_toke;
  char **tokens = split(cmdline, " ");
  
  /* int i = 0; */
  /* while(1){     */
  /*   parse_command(next_toke, &(prse->CommArray[i])); */
  /*   i++; */
  /* } */

  //printf("next toke is: %s\n", next_toke);
  //parse_command(next_toke,  &(prse->CommArray[i]));
  //printf("parsed command into parse info : %s, With vars: %s\n", (prse->CommArray[i]).command,);

  // free tokens once we are done with them
  for (int i = 0; i < MAX_TOKENS; i++) {
    // not all strings may have been malloc'd so check if null first
    if (tokens[i] == NULL) {
      continue;
    }
    printf("free: %p\n", tokens[i]);
    free(tokens[i]);
  }
  printf("free tokens\n");
  free(tokens);
  return NULL;
}

/* /\* prints out parse struct *\/ */
/* void print_info (parseInfo *info) { */
/*    foreach type in parseInfo { */
/*      print "type_name: type" */
/*    } */
/* } */


/* void print_info (char *in_line) { */
     
/*   printf("%s\n", in_line); */
    
/* } */

/* /\*  free memory used in parseInfo *\/ */
/* void free_info (parseInfo *info) { */
/*    foreach memory_block in parseInfo */
/*       free(memory_block) */
/* } */
