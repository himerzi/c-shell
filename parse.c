/**
 *  parse.c
 *  The parser parses these symbols <, >, |, &.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include <ctype.h>

char** split(char *cmdline, char * delim) {

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
  //printf("cmdline: %s, token_gen1: %s\n", cmdline, token_generator);
  while(token_generator != NULL) {
    tokens[j] = token_generator;
    token_generator = strtok(NULL, delim);
    j++;
  }
  tokens[j] = NULL;//setting end element to NULL
  return tokens;
}

/* performs the actul parsing of input */
void parse_commands(char ** commands, parseInfo * prse) {
  
  int i = 0;
  int command_number = 0;
  while(commands[i] != NULL){
    (prse->CommArray[command_number]).command = commands[i];
   
    int vars_i = 0;
    int var_cursor = i+1; // points to location on commands of variable
                          // thaat its attempting to parse;
    while(commands[var_cursor] != NULL && strcmp(commands[var_cursor], "|") != 0){
   
      (prse->CommArray[command_number]).VarList[vars_i] = commands[var_cursor];
      vars_i++;
     
      var_cursor++;
    }
    command_number++;
    i = var_cursor + 1;
  }
}


/*   parse commandline for space separated commands */
parseInfo * parse(char *cmdline){
  parseInfo *prse = malloc(sizeof(parseInfo));
  char **tokens = split(cmdline, " ");  
  parse_commands(tokens, prse);
  
  print_pinfo(prse);
  // free tokens once we are done with them
  for (int i = 0; i < MAX_TOKENS; i++) {
    // not all strings may have been malloc'd so check if null first
    if (tokens[i] == NULL) {
      continue;
    }
  }

  printf("free tokens\n");
  free(tokens);

  return prse;
}

void print_pinfo(parseInfo *prse){
  int k = 0;
  while(k<5){
    printf("comm: %s, ", prse->CommArray[k].command);
    for(int j = 0; j < MAX_VAR_NUM; j++){
      printf("var: %s, ", prse->CommArray[k].VarList[j]);      
    }
    printf("\n");
    k++;
  }
}
void print_tokens(char **tokens){
  for (int k = 0; k < MAX_TOKENS; k++) {
    printf("%s,", tokens[k]);
  }
  printf("\n");
}


  /* /\*  free memory used in parseInfo *\/ */
  /* void free_info (parseInfo *info) { */
  /*    foreach memory_block in parseInfo */
  /*       free(memory_block) */
  /* } */
