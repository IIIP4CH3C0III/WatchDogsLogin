#ifndef RESOURCES_H
#define RESOURCES_H

#include <stdbool.h>
#include <stdlib.h>
#include "display.h"
#include "logo.h"

#define nWindows       7

DETAILS * loadResources( int ArrayID );
char * initString ( void );

void freeDetails( DETAILS ** details );

#define BACKGROUND     0
#define TOP_BAR        1
#define BOT_BAR        2 
#define USER_BOX       3 
#define PASSWORD_BOX   4
#define APPLY_BOX      5 
#define ERROR_MES      6 

struct config {
	char   cfg_LogoText[ 32 ] ;
	int    cfg_LogoSpacing ;
	int    clr_Background ;
	int    clr_Foreground ;
	int    clr_Extras ;
	int    clr_fontBackground ;
	int    clr_fontForeground ;
	int    clr_fontError ;
};

struct config * loadConfig ( void );
int colorSelection ( char * str );

void initColor ( struct config * configuration )  ;

#endif
