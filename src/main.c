#include "display.h"
#include "printing.h"
#include "resources.h"
#include "writting.h"
#include "login.h"
#include "logo.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <security/pam_appl.h>
#include <time.h>

#define VERSION   "V:0.1.0"

int
main( void ) {
    DETAILS * details[ nWindows ] ;
    WINDOW * windows[ nWindows ] ;

	struct config * configuration = ( struct config * ) loadConfig ( ) ;
	if ( configuration == NULL ) {
		printf("Config file with errors.\nCorrect them and try again.\n");
		exit(1);
	}

	initDisplay();
	initColor( configuration );

	bool firstTime	= true;

	char * username = initString() ;
	char * password = initString() ;

	bool connection = false;
	bool shutdown   = false;
	bool reboot     = false;
	bool suspend    = false;

	int columnsBefore = COLS , rowsBefore = LINES ;

	int key = 0 ;

	while ( !connection && !shutdown && !reboot && !suspend ) {
		if ( windowSizeChanges( &columnsBefore , &rowsBefore ) || firstTime ) {
			for ( int i = 0 ; i < nWindows ; i++ ) {
				details [ i ] = NULL ;
			    details [ i ] = ( DETAILS * ) loadResources ( i );
			}
		   	for ( int i = 0 ; i < nWindows ; i++ ) {
				windows [ i ] = NULL ;
				windows [ i ] = (WINDOW *) createNewWindow( details[ i ] );
		   	}
			printLOGO( &windows[ BACKGROUND ] , details[ BACKGROUND ] , configuration->cfg_LogoText , configuration->cfg_LogoSpacing );
			printInformation( windows , details );
			firstTime = false;
		}

		positionCursor( &windows[ USER_BOX ] , 1 , 1 );
		key = getch();
		printBlank ( windows , details );
                printVersion( &windows[ TOP_BAR ] , details[ TOP_BAR ] , VERSION );
                printClock( &windows[ TOP_BAR ] , details[ TOP_BAR ] );

		switch ( key ) {
			default:
			case '\t':
				username  = ( char * ) insertText ( &windows[ USER_BOX ]     , details[ USER_BOX ]->width - 2     , PLAIN_TEXT );					
				refresh();
    			        password  = ( char * ) insertText ( &windows[ PASSWORD_BOX ] , details[ PASSWORD_BOX ]->width - 2 , PASSWORD   );
			case '\n' :
				connection = login( username , password );
				if ( connection )
					break;

                                (void) printTXT ( &windows[ ERROR_MES ] , details[ ERROR_MES ]  , "W: username or password incorrect, try again", "", CENTER , 0 );				
				break;

			case KEY_F(2):
			    if ( questionContinue( &windows[ BACKGROUND ] , details[ BACKGROUND ]  , SHUTDOWN ) ) {
			    	shutdown = true;
			    }
				break;

			case KEY_F(3):
			    if ( questionContinue( &windows[ BACKGROUND ] , details[ BACKGROUND ] , REBOOT ) ) {
			    	reboot = true;
			    }
				break;

			case KEY_F(4):
			    if ( questionContinue( &windows[ BACKGROUND ] , details[ BACKGROUND ] , SUSPEND ) ) {
			    	suspend = true;
			    }
 				break;
		}
	}
	(void) exitDisplay ();

	freeDetails( details );

	if ( username != NULL ) {
		free( username );
		username = NULL ;
	}

	if ( password != NULL ) {
		free( password );
		password = NULL ;
	}

	if ( shutdown )
		execl( "/sbin/shutdown" , "now" , NULL );

	if ( reboot )
		execl( "/sbin/reboot" , "/sbin/reboot" , NULL );

	if ( suspend )
		execl( "/sbin/systemctl" , "suspend" , NULL );

	if ( connection )
		execl( "/bin/bash" , "/bin/bash" , NULL );

	return 0;
}
