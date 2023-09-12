/*
 * File name   : printing.h
 *
 * Author	   : Fábio Pacheco
 *
 */

#ifndef PRINTING_H
#define PRINTING_H

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "resources.h"

#define CENTER         1
#define START          2
#define END            3
#define SPACE_BETWEEN  4

#define margin         1

void printTXT ( WINDOW ** localWindow,
                DETAILS * details,
                char str1[] ,
                char str2[] ,
                int startX  , 
                int startY
              );

void clearWline( WINDOW ** localWindow ,
                 DETAILS * details ,
                 int line 
			  ); 

void printInformation ( WINDOW ** windows , DETAILS ** details  );
void printClock ( WINDOW ** window  , DETAILS * details ) ;
void printVersion( WINDOW ** window , DETAILS * details , char * version );
void printBlank ( WINDOW ** windows , DETAILS ** details  );

#endif
   
