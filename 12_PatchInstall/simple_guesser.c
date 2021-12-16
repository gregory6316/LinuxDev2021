#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)
#include "config.h"
#define MANUAL _("Simple number guesser \n\
\n\
Usage: ./simple_guesser [OPTIONS] \n\
\n\
    --help    show help \n")
#define LOCALE_PATH "../share/locale/"
int main(int argc, char **argv[])
{
    if (argc >= 2){
        return !printf(MANUAL);
    }
    setlocale(LC_ALL,"");
    bindtextdomain("simple_guesser", LOCALE_PATH);
    textdomain("simple_guesser");
    char *dir;

    int left = 1, right = 100, middle, result;
    char answer[80];
    printf(_("Choose number from 1 to 100\n"));
    while(left != right) {
        middle = (left + right) / 2;
        printf(_("Your number greater than %d?: "), middle);
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
    printf(_("Selected value: %d?\n"), left);
    return 0;
}
