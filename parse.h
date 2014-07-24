#define MAX_VAR_NUM 10
#define PIPE_MAX_NUM 10
#define FILE_MAX_SIZE 40
#define MAX_STRING_LEN 32
#define MAX_TOKENS MAX_VAR_NUM * PIPE_MAX_NUM + (PIPE_MAX_NUM - 1)
struct commandType {
  char *command;
  char *VarList[MAX_VAR_NUM];
  int VarNum;
};

/* parsing information structure */
typedef struct {
  int   boolInfile;		       /* boolean value - infile specified */
  int   boolOutfile;		       /* boolean value - outfile specified */
  int   boolBackground;		       /* run the process in the background? */
  struct commandType CommArray[PIPE_MAX_NUM];
  int   pipeNum;
  char  inFile[FILE_MAX_SIZE];	       /* file to be piped from */
  char  outFile[FILE_MAX_SIZE];	       /* file to be piped into */
} parseInfo;

/* the function prototypes */
//parseInfo *parse(char *);
//void free_info(parseInfo *);
//void print_info(parseInfo *);
void print_info(char *s);
parseInfo *parse(char *);
void parse_command(char * command, struct commandType *comm);

