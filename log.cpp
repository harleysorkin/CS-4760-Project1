#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <ctime>

#include "log.h"

#define  MSGLEN 9999

typedef struct list_struct {
    data_t item;
    struct list_struct *next;
} log_t;

static log_t *headptr = NULL;
static log_t *tailptr = NULL;

int addmsg(const char type, const char *msg) {
    log_t *nmsg = new log_t;

    if (nmsg == NULL) {
        perror("Error: addmsg()");
        return -1;
    }
    else {
	time_t now = time(0);

        strcpy(nmsg->item.string, msg);
        nmsg->item.time = now;
	nmsg->item.type = type;
        nmsg->next = NULL;

        if (headptr == NULL) {
            headptr = nmsg;
            tailptr = nmsg;
        }
        else {
            tailptr->next = nmsg;
            tailptr = nmsg;
        }
       
        return 0;
    }
}

void clearlog(void) {
    
    log_t *x;

    while (headptr != NULL) {
        x = headptr;
        headptr = headptr->next;
        delete x;
    }
    
    headptr = NULL;
}

char *getlog(void) {

    char *output = NULL;
    log_t *x = headptr;

    if (output == NULL) {
        perror("Error: getlog()");
        return NULL;
    }
    else {
        while (x != NULL) {
            time_t now = x->item.time;
	    char* dt = ctime(&now);
	    strcat(output, dt);
	    strcat(output, " ");
	    strcat(output, (x->item).string);
            strcat(output, "\n");
            x = x->next;
        }

        return output;
    }
}

int savelog(char *filename) {

    std::ofstream file;
    file.open(filename);

    if (!file) {
        perror("Error: savelog()");
        return -1;
    }
    else {
        file << getlog();
        file.close();
        return 0;
    }

}


