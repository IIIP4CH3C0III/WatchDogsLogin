/*
 * File name   : writting.h
 *
 * Author	   : Fábio Pacheco
 *
 */

#ifndef WRITTING_H
#define WRITTING_H

#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include "resources.h"
#include "printing.h"

#define PLAIN_TEXT    0
#define PASSWORD      1

#define SHUTDOWN      0
#define REBOOT        1
#define SUSPEND       2

char *
insertText ( WINDOW ** localWindow ,
			 int BUFFER_SIZE ,
             int type
           );

bool questionContinue ( WINDOW ** window , DETAILS * details , int type );


#endif
   
