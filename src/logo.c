#include "logo.h"

void printLOGO( WINDOW ** window , DETAILS * details ,  char * str , int space ) {
	int len = strlen( str );
	int memNecessary = nRowsChar * len + len*space + space*2 ;

	char matrix [ nLinesChar ][ memNecessary ] ; 

	for ( int i = 0 ; i < nLinesChar ; i++ ) 
		strcpy ( matrix[i], " ");

	if ( space > 1 )
		for ( int i = 0 ; i < nLinesChar ; i++ ) 
			for ( int j = 0 ; j < space-1 ; j++ )
				strcat ( matrix[i] , " " );

	for ( int i = 0 ; i < len ; i++ ) {
		switch ( str[i] ) {
			case 'A':
			case 'a':
				strcat ( matrix[0], " ### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#####");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], "#   #");
				break;
			case 'B':
			case 'b':
				strcat ( matrix[0], "#### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#### ");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], "#### ");
				break;
			case 'C':
			case 'c':
				strcat ( matrix[0], " ####");
				strcat ( matrix[1], "#    ");
				strcat ( matrix[2], "#    ");
				strcat ( matrix[3], "#    ");
				strcat ( matrix[4], " ####");				
				break;
			case 'D':
			case 'd':
				strcat ( matrix[0], "#### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#   #");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], "#### ");				
				break;
			case 'E':
			case 'e':
				strcat ( matrix[0], "#####");
				strcat ( matrix[1], "#    ");
				strcat ( matrix[2], "#### ");
				strcat ( matrix[3], "#    ");
				strcat ( matrix[4], "#####");				
				break;
			case 'F':
			case 'f':
				strcat ( matrix[0], "#####");
				strcat ( matrix[1], "#    ");
				strcat ( matrix[2], "#### ");
				strcat ( matrix[3], "#    ");
				strcat ( matrix[4], "#    ");				
				break;
			case 'G':
			case 'g':
				strcat ( matrix[0], " ####");
				strcat ( matrix[1], "#    ");
				strcat ( matrix[2], "#  ##");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], " ####");				
				break;
			case 'H':
			case 'h':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#####");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], "#   #");				
				break;
			case 'I':
			case 'i':
				strcat ( matrix[0], "#####");
				strcat ( matrix[1], "  #  ");
				strcat ( matrix[2], "  #  ");
				strcat ( matrix[3], "  #  ");
				strcat ( matrix[4], "#####");				
				break;
			case 'J':
			case 'j':
				strcat ( matrix[0], "#####");
				strcat ( matrix[1], "    #");
				strcat ( matrix[2], "    #");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], " ####");				
				break;
			case 'K':
			case 'k':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "#  # ");
				strcat ( matrix[2], "###  ");
				strcat ( matrix[3], "#  # ");
				strcat ( matrix[4], "#   #");				
				break;
			case 'L':
			case 'l':
				strcat ( matrix[0], "#    ");
				strcat ( matrix[1], "#    ");
				strcat ( matrix[2], "#    ");
				strcat ( matrix[3], "#    ");
				strcat ( matrix[4], "#####");				
				break;
			case 'M':
			case 'm':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "## ##");
				strcat ( matrix[2], "# # #");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], "#   #");				
				break;
			case 'N':
			case 'n':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "##  #");
				strcat ( matrix[2], "# # #");
				strcat ( matrix[3], "#  ##");
				strcat ( matrix[4], "#   #");				
				break;
			case 'O':
			case 'o':
				strcat ( matrix[0], " ### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#   #");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], " ### ");				
				break;
			case 'P':
			case 'p':
				strcat ( matrix[0], "#### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#### ");
				strcat ( matrix[3], "#    ");
				strcat ( matrix[4], "#    ");				
				break;
			case 'Q':
			case 'q':
				strcat ( matrix[0], " ### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#   #");
				strcat ( matrix[3], " ### ");
				strcat ( matrix[4], "   ##");				
				break;
			case 'R':
			case 'r':
				strcat ( matrix[0], "#### ");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#### ");
				strcat ( matrix[3], "#  # ");
				strcat ( matrix[4], "#   #");				
				break;
			case 'S':
			case 's':
				strcat ( matrix[0], " ####");
				strcat ( matrix[1], "#    ");
				strcat ( matrix[2], " ### ");
				strcat ( matrix[3], "    #");
				strcat ( matrix[4], "#### ");				
				break;
			case 'T':
			case 't':
				strcat ( matrix[0], "#####");
				strcat ( matrix[1], "  #  ");
				strcat ( matrix[2], "  #  ");
				strcat ( matrix[3], "  #  ");
				strcat ( matrix[4], "  #  ");				
				break;
			case 'U':
			case 'u':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#   #");
				strcat ( matrix[3], "#   #");
				strcat ( matrix[4], " ### ");				
				break;
			case 'V':
			case 'v':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "#   #");
				strcat ( matrix[2], "#   #");
				strcat ( matrix[3], " # # ");
				strcat ( matrix[4], "  #  ");				
				break;
			case 'W':
			case 'w':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], "# # #");
				strcat ( matrix[2], "# # #");
				strcat ( matrix[3], "# # #");
				strcat ( matrix[4], " # # ");				
				break;
			case 'X':
			case 'x':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], " # # ");
				strcat ( matrix[2], "  #  ");
				strcat ( matrix[3], " # # ");
				strcat ( matrix[4], "#   #");				
				break;
			case 'Y':
			case 'y':
				strcat ( matrix[0], "#   #");
				strcat ( matrix[1], " # # ");
				strcat ( matrix[2], "  #  ");
				strcat ( matrix[3], "  #  ");
				strcat ( matrix[4], "  #  ");				
				break;
			case 'Z':
			case 'z':
				strcat ( matrix[0], "#####");
				strcat ( matrix[1], "   ##");
				strcat ( matrix[2], "  #  ");
				strcat ( matrix[3], "##   ");
				strcat ( matrix[4], "#####");				
				break;

		}

		for ( int i = 0 ; i < nLinesChar ; i++)
			for ( int j = 0 ; j < space ; j++ )
				strcat ( matrix[i], " ");
	}
	for ( int i = 0 ; i < nLinesChar ; i++ )
		printTXT ( window , details , matrix[i] , "", CENTER , i+1);
}
