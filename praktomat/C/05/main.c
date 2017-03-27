#include <stdio.h>
#include "uebung5.h"

int main(){
	unsigned char input[3] = {'0', '0', '7'};
	unsigned char output[4] = {};
	int x = 0x8000F172;
	//int y = 0xF171;
	//bits_ror(x);
	//printf("\n");
	//bits_ror(y);
	//bits_print(x);
	//bits_print(bits_ror(x));
	//bits_print(x);
	//bits_print(bit_get_range(x, 4, 30));
	//init_lookup_table();
	encode(input, output, 1);
	printf("%.*s",4,output);
	//printf("%c",output[0]);
	//printf("%c",output[1]);
	//printf("%c",output[2]);
	//printf("%c\n",output[3]);
	//cbits_print(output[0]);
	//cbits_print(output[1]);
	//cbits_print(output[2]);
	//cbits_print(output[3]);
	//encode_file("maze.txt", "encoded.txt");
	return 0;
}
