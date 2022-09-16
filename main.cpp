/*Harley Sorkin
 *CS 4760 Project 1
 *9/15/2022
 */


#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#include "log.h"

int main (int argc, char **argv) {

    int opt, s;
    int sec = 2; //Default time to wait
    char* filename;
    srand(time(NULL)); //Sets seed for random numbers

    //Use getopt() to parse command line arguments
    while((opt = getopt(argc, argv, ":ht:")) != -1) {
        switch(opt) {
            case 't':
                std::cout << ("Average time between writes: ") << (optarg) << (" second") <<  std::endl;
		sec = atoi(optarg);
                break;
                        
            case 'h':
                std::cout << "Usage: ./driver [-h] [-t sec] [logfile]\nWhere sec is the average amount of time between writes to the logfile (default 2s)\nAnd logfile is the name of the file to be written to (default messages.log)" << std::endl;
                exit(0);

            case ':':
                std::cout << ("Option needs a value.\n") << std::endl;
                exit(0);
                                
            default:
                std::cout << ("Please choose a valid argument.\n") << std::endl;
                exit(0);
        }
    }
 
    //Get optional filename
    if (optind < argc) {
        while (optind < argc) {
            filename = argv[optind];
	    strcat(filename, ".log");
            optind++;
        }
    }
    else {
        filename = "messages.log";
    }

    std::cout << ("Chosen output filename: ") << filename << std::endl;


    //Testing

    addmsg('I', "INFO: This is a flagged as informational");
    s = (rand() % (2 * sec + 1) + 1);
    sleep(s);
    
    addmsg('W', "WARN: This is a flagged as warning");
    s = (rand() % (2 * sec + 1) + 1);
    sleep(s);
    
    addmsg('E', "ERROR: This is a flagged as error");
    s = (rand() % (2 * sec + 1) + 1);
    sleep(s);
    
    addmsg('F', "FATAL: This is a flagged as fatal");
    
    //Print log to command line
    char* a = getlog();
    std::cout << a;
   
    addmsg('I', "INFO: This message won't be saved");
    clearlog();
    
    savelog(filename);
    std::cout << ("Saved log to ") << filename << std::endl;

}


