#define MAX_VAR_NUM 10
#define PIPE_MAX_NUM 10
#define FILE_MAX_SIZE 40

struct commandType {
  char *command;
  char *VarList[MAX_VAR_NUM];
  int VarNum;
};

/* parsing information structure */
typedef struct {
  struct commandType CommArray[PIPE_MAX_NUM];
  int   pipeNum;
} parseInfo;

/* the function prototypes */
//parseInfo *parse(char *);
//void free_info(parseInfo *);
//void print_info(parseInfo *);
void print_info(char *s);
parseInfo *parse(char *);
void parse_command(char * command, struct commandType *comm);

