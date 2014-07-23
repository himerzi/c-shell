/**
 *  shell.c
 */
int main(int argc, char **argv) {
  while(1) {
    cmdLine = readline(printPrompt());

       info  = parse(cmdLine);

       print_info(info);
    }

    free_info(info);
 }
