#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
typedef void (*new_remove)( const char *);

int remove( const char *fname)
{
    if ( strstr( fname, "PROTECT") == NULL )
    {
        new_remove old_remove;
        old_remove = dlsym( RTLD_NEXT, "remove");
        old_remove( fname );
        return 0;
    }
    else{
    	return 1;
    }
}
