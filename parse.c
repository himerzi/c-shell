/**
 *  parse.c
 */

  void init_info(parseInfo *p) {
      initialize parseInfo struct
  }

  /* parse a single command */
  void parse_command(char * command, struct commandType *comm) {

  }

  /*   parse commandline for space separated commands */
  parseInfo *parse (char *cmdline) {
    foreach cmd in cmdline {
      if (cmd == command) {
        parse_command(cmd, type)
      }
    }
  }

  /* prints out parse struct */
  void print_info (parseInfo *info) {
     foreach type in parseInfo {
       print "type_name: type"
     }
  }  

  /*  free memory used in parseInfo */
  void free_info (parseInfo *info) {
     foreach memory_block in parseInfo
        free(memory_block)
  }
