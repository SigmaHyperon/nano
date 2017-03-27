#include <stdio.h>
#include "uebung6.h"


uint8_t x = 5;
uint8_t y = 5;
struct Point start;
unsigned char maze_array [100] [100] = {
		{0,0,0,0,0},
		{0,1,0,1,0},
		{2,1,0,1,3},
		{0,1,1,1,0},
		{0,0,0,0,0}
};

unsigned char dmaze_array [100] [100];

int main(){
	/*printf("%i\n",fak(10));
	printf("%i\n",fak_it(10));
	printf("%i\n",fib(1));
	printf("%i\n",fib(2));
	printf("%i\n",fib(3));
*/
	maze_from_file("maze2.txt",dmaze_array,&x, &y);
	maze_print(dmaze_array, x, y);
	start = maze_start_pos(dmaze_array,x,y);
	printf("maze ret: %d\n",maze(dmaze_array,x,y,start.x, start.y));
	printf("\n");
	maze_print(dmaze_array, x, y);
	printf("Start: X.%d Y.%d", start.x, start.y);
	return 0;
}
