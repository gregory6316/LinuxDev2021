#include <stdio.h>
#include <string.h>


int main( int argc, char **argv)
{
    if ( argc != 3 )
    {
        fprintf( stderr, "Wrong number of arguments!\nUsage: ./move <input_file> <output_file>\n");
        return 1;
    }

    if ( strcmp( argv[1], argv[2]) == 0)
    {
        fprintf( stderr, "Files must be different!\n");
        return 2;
    }

    FILE *infile, *outfile;

    infile = fopen( argv[1], "rb");
    
    if ( infile == NULL )
    {
        fprintf( stderr, "Error opening infile!\n");
        return 3;
    }

    outfile = fopen( argv[2], "wb");

    if ( outfile == NULL )
    {
        if ( fclose(infile) != 0){

        fprintf( stderr, "Error closing infile and opening outfile!\n");
        return 9;
        }   
        fprintf( stderr, "Error opening outfile!\n");
        return 4;
    }

    int r, size = 4096;
    char str[size];
    
    while( 1 == 1 )
    {
        if ( fgets( str, size, infile) == NULL  )
        {
            if ( remove(argv[2]) != 0)
            {
                fprintf( stderr, "Error reading infile and deleting outfile!\n");
                return 10;
            }
            fprintf( stderr, "Error reading infile!\n");
            return 5;
        }
        if ( (r = fputs( str, outfile)) == EOF )
        {
            if ( remove(argv[2]) != 0)
            {
                fprintf( stderr, "Error writing in outfile and deleting outfile!\n");
                return 11;
            }
            fprintf( stderr, "Error writing in outfile!\n");
            return 6;
        }
        if ( feof( infile ) )
        {
            break;
        }
    }
    
    if ( fclose(outfile) != 0)
    {
        if ( fclose(infile) != 0)
        {
            if ( remove(argv[2]) != 0)
            {
                fprintf( stderr, "Error closing infile and closing/deleting outfile!\n");
                return 13;
            }
            fprintf( stderr, "Error closing infile and closing outfile!\n");
            return 12;
        }
        if ( remove(argv[2]) != 0)
            {
                fprintf( stderr, "Error closing outfile and deleting outfile!\n");
                return 14;
            }
        fprintf( stderr, "Error closing outfile\n");
        return 8;
    }
    if ( remove(argv[1]) != 0)
    {
        outfile = fopen( argv[2], "wb");
        if ( outfile == NULL)
        {
             fprintf( stderr, "Error deleting infile and opening/deleting outfile!\n");
             return 15;   
        }
        if ( remove(argv[2]) != 0)
        {
            fprintf( stderr, "Error deleting infile and outfile!\n");
            return 16;
        }
        fprintf( stderr, "Error deleting infile!\n");
        return 7;
    }


    return 0;
}













