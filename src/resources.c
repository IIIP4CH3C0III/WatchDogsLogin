#include "resources.h"

char * initString ( void ) {
	char * string = ( char * ) malloc ( sizeof(char) );
	string[0] = '\0';
	return string;
}

DETAILS * loadResources( int ArrayID ) {

	DETAILS * details = ( DETAILS * ) malloc ( sizeof( DETAILS ) );

	switch( ArrayID ) {
		case BACKGROUND:  
			details->height  = 0 ;
			details->width   = 0 ;
			details->startY  = 0 ;
			details->startX  = 0 ;
			details->color   = COLOR_BACKGROUND;
			details->box     = NO_BOX;	
			break;
		case TOP_BAR: 
			details->height  = 1 ;
			details->width   = 0 ;
			details->startY  = 1 + nLinesChar + 1 ;
			details->startX  = 0 ;
			details->color   = COLOR_FOREGROUND;
			details->box     = NO_BOX;	
			break;
		case BOT_BAR: 
			details->height  = 1 ;
			details->width   = 0 ;
			details->startY  = LINES - 2 ;
			details->startX  = 0 ;
			details->color   = COLOR_FOREGROUND;
			details->box     = NO_BOX;	
			break;
		case USER_BOX: 
			details->height  = 3 ;
			details->width   = COLS/2 - 2 ;
			details->startY  = LINES/2 - 1;
			details->startX  = 1;
			details->color   = COLOR_BACKGROUND;
			details->box     = BOX;
			break;
		case PASSWORD_BOX:  
			details->height  = 3 ;
			details->width   = COLS/2 - 2 ;
			details->startY  = LINES/2 - 1;
			details->startX  = COLS/2 + 1;
			details->color   = COLOR_BACKGROUND;
			details->box     = BOX;
			break;
		case APPLY_BOX:
			details->height  = 1 ;
			details->width   = COLS - 5 ;
			details->startY  = LINES/2 + 2;
			details->startX  = 2;
			details->color   = COLOR_BUTTON;
			details->box     = NO_BOX;
			break;		
		case ERROR_MES:  
			details->height  = 1 ;
			details->width   = COLS - 5 ;
			details->startY  = LINES/2 + 3;
			details->startX  = 2;
			details->color   = COLOR_WARNING;
			details->box     = NO_BOX;
			break;		
		default:
			break;
	}
	return details;	
}

void freeDetails( DETAILS ** details ) {
	for( int i = 0 ; i < nWindows; i++ ) 
		if ( details[ i ] != NULL ) {
			free( details[i] );
			details[i] = NULL ;
		}
}

struct config * loadConfig ( void ) {
    struct config * configuration = ( struct config * ) malloc ( sizeof(struct config) );

	FILE * configFile = NULL ; 
	configFile = ( FILE * ) fopen ("./config","r");

	if ( configFile == NULL )
		return NULL;

	const int BUFFER_SIZE = 32 ;
	char buffer[ BUFFER_SIZE ];
	char * string = NULL ;

	while ( fgets ( buffer , BUFFER_SIZE , configFile ) != NULL ) {
		string = strtok( buffer , "=" );

		if ( strcmp ( string , "logo" ) == 0 ) {
			string = strtok( NULL , "=");
			strcpy ( configuration->cfg_LogoText , string );
		}

		if ( strcmp ( string , "logo_spacing" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->cfg_LogoSpacing = atoi ( string );
		}

		if ( strcmp ( string , "color_background" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->clr_Background = colorSelection ( string );
			if ( configuration->clr_Background == -1 ) 
				return NULL;
		}

		if ( strcmp ( string , "color_foreground" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->clr_Foreground = colorSelection ( string );
			if ( configuration->clr_Foreground == -1 ) 
				return NULL;
		}

		if ( strcmp ( string , "color_extras" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->clr_Extras = colorSelection ( string );
			if ( configuration->clr_Extras == -1 ) 
				return NULL;
		}

		if ( strcmp ( string , "color_font_background" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->clr_fontBackground = colorSelection ( string );
			if ( configuration->clr_fontBackground == -1 ) 
				return NULL;
		}

		if ( strcmp ( string , "color_font_foregournd" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->clr_fontForeground = colorSelection ( string );
			if ( configuration->clr_fontForeground == -1 ) 
				return NULL;
		}

		if ( strcmp ( string , "color_font_error" ) == 0 ) {
			string = strtok( NULL , "=");
			configuration->clr_fontError = colorSelection ( string );
			if ( configuration->clr_fontError == -1 ) 
				return NULL;
		}
	}

	if ( configFile != NULL ) {
		fclose( configFile );
		configFile = NULL;
	}

	return configuration;
}


void initColor ( struct config * configuration ) {
	init_pair( COLOR_BACKGROUND , configuration->clr_fontBackground , configuration->clr_Background );
	init_pair( COLOR_FOREGROUND , configuration->clr_fontForeground , configuration->clr_Foreground );
	init_pair( COLOR_BUTTON     , configuration->clr_fontBackground , configuration->clr_Extras );
	init_pair( COLOR_WARNING    , configuration->clr_fontError      , configuration->clr_Background );
}

int colorSelection ( char * str ) {
	if ( strcmp ( str, "BLACK\n" ) == 0 ) 
		return 0;
	else if ( strcmp ( str, "RED\n" ) == 0 ) 
		return 1;
	else if ( strcmp ( str, "GREEN\n" ) == 0 ) 
		return 2;
	else if ( strcmp ( str, "YELLOW\n" ) == 0 ) 
		return 3;
	else if ( strcmp ( str, "BLUE\n" ) == 0 ) 
		return 4;
	else if ( strcmp ( str, "MAGENTA\n" ) == 0 ) 
		return 5;
	else if ( strcmp ( str, "CYAN\n" ) == 0 ) 
		return 6;
	else if ( strcmp ( str, "WHITE\n" ) == 0 ) 
		return 7;
	else
		return -1;
}
