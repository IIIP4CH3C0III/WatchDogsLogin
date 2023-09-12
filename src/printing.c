/*
 * File name   : printing.c
 *
 * Author	   : Fábio Pacheco
 *
 * Description : Functions that print most of the information present in program
 *
 */

#include "printing.h"

void printTXT ( WINDOW ** localWindow, DETAILS * details, char str1[] , char str2[] , int startX , int startY ) {
	unsigned int position = margin;
	unsigned int lenStr1, lenStr2;
	
	switch ( startX ) {
		case CENTER:
			//strcat( str1 , str2 );
			lenStr1  = (unsigned int) strlen ( str1 ) ;
			if( details->width != 0 )
				position = details->width / 2 - lenStr1 / 2 ;
			else
			    position = COLS / 2 - lenStr1 / 2 ; 
			    
			mvwprintw( *localWindow , startY , position , "%s" , str1 )   ; 
			break;

		case START:
			mvwprintw( *localWindow , startY , position , "%s" , str1 )   ; 
			break;

		case END:
			lenStr1  = (unsigned int) strlen ( str1 ) ;
			if( details->width != 0 )
				position = details->width - lenStr1 - margin ;
			else
			    position = COLS - lenStr1 - margin ; 
			    
			mvwprintw( *localWindow , startY , position , "%s" , str1 )   ; 
			break;

		case SPACE_BETWEEN:
			lenStr1 = (unsigned int) strlen ( str1 ) ;
			lenStr2 = (unsigned int) strlen ( str2 ) ;
			unsigned int center;

			if( details->width != 0 ) {
				position = details->width - lenStr2 - margin ;
				center   = details->width / 2;
			} else {
			    position = COLS - lenStr2 - margin ; 
			    center   = COLS / 2 ; 
			}
			

			mvwprintw( *localWindow , startY , margin   , "%s" , str1 )   ; 
			mvwprintw( *localWindow , startY , position , "%s" , str2 )   ; 
			mvwprintw( *localWindow , startY , center   , "|" )   ; 
			
			break;
	}	
	wrefresh( *localWindow );
}


void clearWline( WINDOW ** localWindow , DETAILS * details , int line ) {
	int lineSize = details->width - margin ;
	if ( lineSize <= 0 )
		lineSize = COLS;

    for ( int i = margin ; i < lineSize ; i++ )
    	mvwprintw ( *localWindow , line , i , " " );
    wrefresh( *localWindow );	
} 

void printInformation ( WINDOW ** windows , DETAILS ** details  ) {
	char * hostname = (char * )malloc( 64 ) ;
	gethostname( hostname, 64 );
	hostname = realloc ( hostname , strlen ( hostname )+1 ) ;

	char * strAB = (char * )malloc( 64 ) ;	
	strcpy( strAB , "Connect to ");
	strcat( strAB ,  hostname );
	strAB = realloc ( strAB , strlen ( strAB ) ) ;	

    // (void) printTXT ( &windows[ BACKGROUND ] , details[ BACKGROUND ]  , "Env - i3wm"          , "", CENTER, 3 );

    (void) printTXT (  &windows[ BOT_BAR ] , details [ BOT_BAR ] , "F2 Shutdown F3 Reboot F4 Suspend", "F10 Change window manager", SPACE_BETWEEN, 0 );
    
    (void) printTXT ( &windows[ USER_BOX ]     , details[ USER_BOX ]      , "Username" , "", START , 0 );
    (void) printTXT ( &windows[ PASSWORD_BOX ] , details[ PASSWORD_BOX ]  , "Password" , "", END   , 0 );
    (void) printTXT ( &windows[ APPLY_BOX ]    , details[ APPLY_BOX ]     , strAB  , "", CENTER, 0 );	

	if ( strAB != NULL ) {
		free( strAB );
		strAB = NULL ;	
	}

	if ( hostname != NULL ) {
		free( hostname );
		hostname = NULL ;	
	}
}

void printClock ( WINDOW ** window , DETAILS * details ) {
	time_t timer   = time( &timer );
	struct tm * lTime = localtime( &timer ); 

	// 00:00 00/00/0000
	const unsigned int BUFFER_SIZE = 60;
	
	char dateFormat[ BUFFER_SIZE ];
	strcpy( dateFormat, "" );
		
	snprintf( dateFormat , BUFFER_SIZE , "%d:%d %d/%d/%d" ,
           	                            lTime->tm_hour,
           	                            lTime->tm_min,
           	                            lTime->tm_mday,
           	                            lTime->tm_mon+1,
           	                            lTime->tm_year+1900  );

    printTXT ( window , details , dateFormat , "" , END , 0 );
}

void printVersion( WINDOW ** window , DETAILS * details , char * version ) {
    printTXT ( window , details , version , "" , START , 0 );
}


void printBlank ( WINDOW ** windows , DETAILS ** details  ) {
	(void) clearWline ( &windows[ BACKGROUND ]   , details[ BACKGROUND ]   , LINES - 1 );	
	(void) clearWline ( &windows[ USER_BOX ]     , details[ USER_BOX ]     , 1 );	
	(void) clearWline ( &windows[ PASSWORD_BOX ] , details[ PASSWORD_BOX ] , 1 );	
	(void) clearWline ( &windows[ ERROR_MES ]    , details[ ERROR_MES ]    , 0 );	
	(void) clearWline ( &windows[ TOP_BAR ]    , details[ TOP_BAR ]    , 0 );	
}

