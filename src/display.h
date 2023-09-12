/*
 * File name   : display.h
 *
 * Author	   : Fábio Pacheco
 *
 */

#ifndef DISPLAY_H
#define DISPLAY_H

/* Part of the template */ 
void initDisplay (void);
void exitDisplay (void);

#include <ncurses.h>
#include <stdbool.h>

void positionCursor ( WINDOW ** localWindow , int y , int x );
bool windowSizeChanges( int * columnsBefore , int * rowsBefore );

/* Theme Colors */
#define COLOR_BACKGROUND     1
#define COLOR_FOREGROUND     2
#define COLOR_BUTTON         3
#define COLOR_WARNING        4

#define NO_BOX				 0
#define BOX					 1 

typedef struct{
	int height; 
	int width ; 
	int startY; 
	int startX; 
	int color ; 
	int box   ;
} DETAILS ;

WINDOW *createNewWindow( DETAILS * details );

#endif 
