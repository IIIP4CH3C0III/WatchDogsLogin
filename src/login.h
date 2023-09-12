#ifndef LOGIN_H
#define LOGIN_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <security/pam_appl.h>

bool 
login ( char * username , char * password );

#endif
