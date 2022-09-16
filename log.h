/*Harley Sorkin
 *CS 4760 Project 1
 *9/15/2022
 */


#include <time.h>

typedef struct data_struct {
    time_t time;
    char type;
    const char *string;
} data_t;

int addmsg(const char type, const char *msg);
void clearlog(void);
char *getlog(void);
int savelog(char *filename);
