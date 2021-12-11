/*! 
 * \mainpage Documentation
 * Simple number guesser 
 *
 * Usage: ./simple_guesser [OPTIONS]\n 
 *   \-\-help  \-  display help\n
 *   \-\-version \- display version\n
 *   \-r   \-     use roman numbers\n
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)
#include "config.h"
#include "roman_table.h"
#define LOCALE_PATH "."
#define MANUAL _("Simple number guesser \n\
\n\
Usage: ./simple_guesser [OPTIONS] \n\
\n\
    --help    show help \n\
    --version show version \n\
    -r        use roman numbers \n")
/** @file  simple_guesser.c*/
/**
 * Get roman corresponding to x and return it
 * @param x int from 1 to 100
 */
char * to_roman(int x)
{
    return roman[x];
}
/**
 * This program will guess a number from 1 to 100.
 * To run russian version run with @p LC_ALL=ru_RU.utf8.
 * To run english version run with @p LC_ALL=C.
 * @param -r toggle roman numbers ( @p argv[1] ).
 */
int main(int argc, char *argv[])
{
    int romanflag = 0;
    bindtextdomain("simple_guesser", LOCALE_PATH);
    textdomain("simple_guesser");
    setlocale(LC_ALL,"");
    if (argc > 2){
        return !printf(MANUAL);
    }
    if(argc == 2) {
       
        if(!strcmp(argv[1], "--help")) {          
            return !printf(MANUAL);   
        } else if(!strcmp(argv[1], "--version")) {
           
            return !printf("%s\n", VERSION);      
        } 
          else if(!strcmp(argv[1], "-r")) {
            romanflag = 1;
        }
          else {
            return !printf(MANUAL);
        }
    }
   
    int left = 1, right = 100, middle, result;
    char answer[80];
    char buf[64];
    printf(_("Choose number from 1 to 100\n"));
    while(left != right) {
        middle = (left + right) / 2;
        sprintf(buf, "%d", middle);
        printf(_("Your number greater than %s?: "), romanflag ? to_roman(middle) : buf);
        if (scanf("%s", answer) == 1){
        	if (strstr(answer, _("Yes")) || 
        	    strstr(answer, _("Y")) || 
        	    strstr(answer, _("yes")) || 
        	    strstr(answer, _("y"))) {
        	    left = middle + 1;
        	} else if (strstr(answer, _("No")) ||
        	    strstr(answer, _("N")) ||
        	    strstr(answer, _("no")) ||
        	    strstr(answer, _("n"))) {
        	    right = middle;
        	}
    	}
    }
    sprintf(buf, "%d", left);
    printf(_("Selected value: %s?\n"), romanflag ? to_roman(left) : buf);
    return 0;
}
