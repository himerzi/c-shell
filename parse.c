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
void parse_command(char * command, struct commandType *comm) {
  char *cmd_token;
  
  cmd_token = strtok(command, " ");
  if (cmd_token != NULL) comm->command = cmd_token;
  
  int i = 0;
  while(cmd_token != NULL){
    cmd_token = strtok(NULL, " ");
    comm->VarList[i] = cmd_token;
    i++;
  }
}

char** split(char *cmdline, char * delim) {

  //  printf("%lu\n", ((size_t) MAX_TOKENS) * sizeof(char*));
  //  printf("MAX_TOKENS * sizeof(char*): %lu\n", MAX_TOKENS * sizeof(char*));

  char **tokens = (char **) malloc(MAX_TOKENS * sizeof(char*));
  int i;
  for (i = 0; i < MAX_TOKENS; i++) {
    tokens[i] = (char *) malloc(MAX_STRING_LEN * sizeof(char));
    //printf("malloc: %u %p\n", i, tokens[i]);
    if (tokens[i] == NULL) {
      printf("HERP\n");
    }
  }

  char * token_generator = strtok(cmdline, delim);
  int j = 0;
  printf("cmdline: %s, token_gen1: %s\n", cmdline, token_generator);
  while(token_generator != NULL) {
    tokens[j] = token_generator;
    token_generator = strtok(NULL, delim);
    j++;
  }
  
  for (int k = 0; k < MAX_TOKENS; k++) {
    printf("%s,", tokens[k]);
  }
  printf("\n");

  return tokens;
}

/*   parse commandline for space separated commands */
parseInfo * parse(char *cmdline){
  // (void) cmdline;             /* FIXME */
  parseInfo *prse = NULL;     /* FIXME */
  // struct commandType *cmd_type;
  // char *next_toke;
  // prse  = malloc(sizeof(parseInfo));
  char **tokens = split(cmdline, " ");
  
  
  printf("%p", tokens);
  for (int i = 0; i < MAX_TOKENS; i++) {
    //printf("free: %d\n", i);
    //free(tokens[i]);
 }
  //free(tokens);


  //int i = 0;
  //while(1){    
    
    //      parse_command(next_toke, &(prse->CommArray[i]));
    //i++;
                    
  // }

    //printf("next toke is: %s\n", next_toke);
    //parse_command(next_toke,  &(prse->CommArray[i]));
    //printf("parsed command into parse info : %s, With vars: %s\n", (prse->CommArray[i]).command,);
  //} 
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
