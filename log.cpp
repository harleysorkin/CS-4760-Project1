/*Harley Sorkin
 *CS 4760 Project 1
 *9/15/2022
 */


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

// Add a new message to the list_struct
int addmsg(const char type, const char *msg) {

    log_t *nmsg = new log_t;

    if (nmsg == NULL) {
        perror("Error: addmsg()");
        return -1;
    }
    else {
	time_t now = time(0);

        nmsg->item.string = msg;
        nmsg->item.time = now;
	nmsg->item.type = type;
        nmsg->next = NULL;

        if (nmsg->item.type == 'F') {
            std::cout << ("FATAL message encountered. Saving to \'messages.log\'") << std::endl;
            savelog("messages.log");
        }

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

// Clears list_struct
void clearlog(void) {
    
    log_t *x;

    while (headptr != NULL) {
        x = headptr;
        headptr = headptr->next;
        delete x;
    }
    
    headptr = NULL;
}

//Prints list_struct to the console
char *getlog(void) {

    char *output = new char[MSGLEN];
    log_t *x = headptr;

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

//Writes list_struct to chosen file
int savelog(char *filename) {

    std::ofstream file;
    file.open(filename);

    if (!file) {
        perror("Error: savelog()");
        return -1;
    }
    else {
	char *c = getlog();
        file << c;
        file.close();
        return 0;
    }

}


