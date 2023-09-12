#include "writting.h"

char *
insertText ( WINDOW ** localWindow , int BUFFER_SIZE , int type ) {
	int character , 
	    pointerText = 0,
	    startY = 1 ;
	    
	bool addEndOfString = false;	    
	char * buffer = ( char * ) malloc ( sizeof(char) * BUFFER_SIZE );

	wmove( *localWindow , startY , margin );
	wrefresh ( *localWindow );	

	while ( ( character = getch() ) != '\t' && pointerText < BUFFER_SIZE ) {
		if ( character == KEY_BACKSPACE ) {
			if ( pointerText > 0 ) {
				pointerText-- ;
				buffer[ pointerText ] = '\0';
				mvwprintw ( *localWindow , startY, pointerText+margin , " " );
				wmove( *localWindow , startY , pointerText+margin );
			}
		}
		else if ( character == '\n' ) {
			buffer[ pointerText ] = '\0';
			pointerText++;
			addEndOfString = true;
			break;
		}
		else if ( isprint( character )) {
			buffer[ pointerText ] = character ;

			if ( type == PLAIN_TEXT )
				mvwprintw ( *localWindow , startY, pointerText+margin , "%c" , character);			
			if ( type == PASSWORD )
				mvwprintw ( *localWindow , startY, pointerText+margin , "*");			

			pointerText++;
			
		}						
		wrefresh ( *localWindow );	
	}

	if ( !addEndOfString ) {
		buffer[ pointerText ] = '\0';
		pointerText++;
	}
	
	buffer = ( char * ) realloc ( buffer , pointerText ) ;
	return buffer;
}

bool 
questionContinue ( WINDOW ** window , DETAILS * details , int type ) {
	nodelay(stdscr, FALSE);
	if ( type == SHUTDOWN )
		printTXT ( window , details , "Are you sure you want shutdown? (y/n)" , "" , START , LINES - 1 );
	if ( type == REBOOT )
		printTXT ( window , details , "Are you sure you want reboot? (y/n)" , "" , START , LINES - 1 );
	if ( type == SUSPEND )
		printTXT ( window , details , "Are you sure you want suspend? (y/n)" , "" , START , LINES - 1 );

	int key  ;
	if ( (key = getch()) == 'y' || key == 'Y' )
		return true ;

	clearWline ( window , details , LINES - 1 );
	return false;
}
