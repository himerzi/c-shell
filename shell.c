/**
 *  shell.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
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
    //now lets do something with info....
    int status = my_system(info->CommArray[0].command, info->CommArray[0].VarList);
    printf("ran with exit code %d\n", status);
  
    if (status == -1) {
      perror("waitpid");
      //exit(EXIT_FAILURE);
    }


    if (WIFEXITED(status)) {
      printf("child exited, status=%d\n", WEXITSTATUS(status));
      
      
    } else if (WIFSIGNALED(status)) {
      printf("child killed (signal %d)\n", WTERMSIG(status));
      
      
    } else if (WIFSTOPPED(status)) {
      printf("child stopped (signal %d)\n", WSTOPSIG(status));
    }
    
  //  free_info(info);
  }
}

int my_system(const char *command, char **VarList){
  
       int status;
       pid_t pid;
       VarList[4] = "S";

       pid = fork ();
       if (pid == 0)
         {
           /* This is the child process.  Execute the shell command. */
           //char *mylist[] = {"blah",  "/", NULL};
           VarList[0] = "dummydoo";
           execvp (command, VarList);
           _exit (EXIT_FAILURE);
         }
       else if (pid < 0)
         /* The fork failed.  Report failure.  */
         status = -1;
       else
         /* This is the parent process.  Wait for the child to complete.  */
         if (waitpid (pid, &status, 0) != pid)
           status = -1;
       return status;
}
