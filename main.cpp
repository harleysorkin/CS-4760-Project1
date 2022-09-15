#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <iostream>

#include "log.h"

int main (int argc, char **argv) {

    int opt;

    while((opt = getopt(argc, argv, ":ht:")) != -1) {
        switch(opt) {
            case 't':
                std::cout << ("Average time between writes: ") << (optarg) << (" second") <<  std::endl;
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

}
