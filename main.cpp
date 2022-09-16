#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

#include "log.h"

int main (int argc, char **argv) {

    int opt, s;
    int sec = 2;
    char* filename;
    srand(time(NULL));

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
 
    if (optind < argc) {
        while (optind <argc) {
            filename = argv[optind];
            optind++;
        }
    }
    else {
        filename = "messages.log";
    }

    std::cout << ("Chosen output filename: ") << filename << std::endl;

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
    s = (rand() % (2 * sec + 1) + 1);
    sleep(s); 
    
    char* a = getlog();
    std::cout << a;
    //clearlog();
    savelog(filename);
    std::cout << ("Saved log to ") << filename << std::endl;

}


