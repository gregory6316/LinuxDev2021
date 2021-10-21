#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv)
{
	int start = 0, end = 0, step = 1, i = -1;
	switch ( argc )
	{
		case 2:
        		end = atoi(argv[1]);
			break;
		case 3:
			start = atoi(argv[1]);
			end = atoi(argv[2]);
			break;
		case 4:
			start = atoi(argv[1]);
			end = atoi(argv[2]);
			step = atoi(argv[3]);
			break;
		default:
			printf("Incorrect amount of arguments!\n");
			return 0;
	}
	if ((start - end) * step > 0 )
	{
		printf("Incorrect step\n");
		return 0;
	}
	for ( i = start; i != end; i += step )
	{
		printf("%d\n", i);
	}
	return 0;
}


