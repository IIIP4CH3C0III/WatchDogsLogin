/*
 * File name   : display.c
 *
 * Author	   : Fábio Pacheco
 *
 * Description : Functions that play with Ncurses library, and do most of the functions necessary.
 *               There is the possibility of changing the color pair in here.
 */


#include "display.h"

void initDisplay (void) {
	initscr();
	start_color();
	cbreak();	// Disable the buffer in line;
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE); // Don't wait for a input after a certain time
	use_default_colors();
}

void exitDisplay (void) {
	endwin();
}

WINDOW *createNewWindow( DETAILS * details ) {
	WINDOW *localWin;
	localWin = newwin( details->height , details->width , details->startY , details->startX );
	wrefresh( localWin );
	wbkgd ( localWin , COLOR_PAIR( details->color ) );

	if( details->box )
		box( localWin , 0 , 0 );

	refresh();
	wrefresh ( localWin );

	return localWin;		
}

bool windowSizeChanges( int * columnsBefore , int * rowsBefore ) {
	if( *columnsBefore != COLS || *rowsBefore != LINES ) {
		*columnsBefore = COLS;
		*rowsBefore = LINES;
		return true;
	}
	return false;
}

void positionCursor ( WINDOW ** localWindow , int y , int x ) {
	wmove ( *localWindow , y , x );
	wrefresh( *localWindow );
}
