#include "uebung5.h"
#include <stdio.h>

// globale lookup table
char g_lookup_table[64];


void bits_print(unsigned int x)
{
	printf("%#010X: ",x);
	int i;
	for(i = sizeof(int)*8-1; i >= 0; i--){
		printf("%i",bit_get(x,i));
		if(i%4 == 0){
			printf(" ");
		}
	}
	printf("\n");
}

void cbits_print(unsigned char x){
	printf("%#010X: ",x);
	int i;
	for(i = sizeof(char)*8-1; i >= 0; i--){
		printf("%i",bit_get(x,i));
	}
	printf("\n");
}

int bits_ror(unsigned int x)
{
	int rightmost = bit_get(x,0);
	int res = x >> 1;
	if(rightmost == 1){
		res = res | (1 << (sizeof(int)*8-1));
	}
	return res;
}

int bits_rol(unsigned int x){
	int leftmost = bit_get(x,sizeof(int)*8-1);
	int res = x << 1;
	if(leftmost == 1){
		res = res | 1;
	}
	return res;
}
  

int bit_get(unsigned int x,unsigned char pos){
	if(pos < sizeof(unsigned int)*8){
		return (x & ( 1 << pos )) >> pos;
	}else{
		return -1;
	}

}

int bit_get_range(unsigned int x,unsigned char pos,unsigned char len){
	if(sizeof(unsigned int)*8 < (pos+len)){
		return -1;
	}
	if(len <= 0){
		return -1;
	}
	int i;
	unsigned int mask = 0;
	int ret;
	for (i = 0; i < len; i++){
		mask = mask << 1;
		mask = (mask | 1);
	}
	mask = mask << (pos);
	ret = (mask & x)>>pos;
	return ret;
}
  

void init_lookup_table(){
	int i;
	for(i = 0; i < 26; i++){
		g_lookup_table[i] = 'A'+i;
	}
	for (i=0; i < 26; i++){
		g_lookup_table[i+26] = 'a'+i;
	}
	for (i = 0; i < 10; i++){
		g_lookup_table[i+52] = '0'+i;
	}
	g_lookup_table[62] = '+';
	g_lookup_table[63] = '/';
}

int encode(unsigned char input[3],unsigned char output[4],int length){
	static int counter = 0;
	counter++;
	switch(length){
	case 1:

		output[0] = input[0] >> 2;

		output[1] = input[0] << 6;
		output[1] = output[1] >> 2;

		output[2] = '=';

		output[3] = '=';

		output[0] = g_lookup_table[output[0]];
		output[1] = g_lookup_table[output[1]];
		break;
	case 2:

		output[0] = input[0] >> 2;

		output[1] = input[0] << 6;
		output[1] = output[1] | (input[1] >> 2);
		output[1] = output[1] >> 2;

		output[2] = input[1] << 4;
		output[2] = output[2] >> 2;

		output[3] = '=';

		output[0] = g_lookup_table[output[0]];
		output[1] = g_lookup_table[output[1]];
		output[2] = g_lookup_table[output[2]];
		break;
	case 3:
		output[0] = input[0] >> 2;

		output[1] = input[0] << 6;
		output[1] = output[1] | (input[1] >> 2);
		output[1] = output[1] >> 2;

		output[2] = input[1] << 4;
		output[2] = output[2] | (input[2] >> 4);
		output[2] = output[2] >> 2;

		output[3] = input[2] << 2;
		output[3] = output[3] >> 2;

		/*cbits_print(output[0]);
		cbits_print(output[1]);
		cbits_print(output[2]);
		cbits_print(output[3]);*/

		output[0] = g_lookup_table[output[0]];
		output[1] = g_lookup_table[output[1]];
		output[2] = g_lookup_table[output[2]];
		output[3] = g_lookup_table[output[3]];

		break;
	default:
		return 1;
	}

	return 0;

}

int encode_file(char* in_filename,char* out_filename){
	FILE *sFile, *dFile;
	char buffer[3];
	char encoded[4];
	int size;
	sFile = fopen(in_filename, "r");
	if (sFile == NULL)
	{
		return 1;
	}
	dFile = fopen(out_filename, "w");
	if (dFile == NULL)
	{
		(void)fclose(sFile);
		return 2;
	}
	while (!(_Bool)feof(sFile) && !(_Bool)ferror(sFile) && !(_Bool)ferror(dFile))
	{
		size = (int)fread(buffer, 1, 3, sFile);
		if ((_Bool)ferror(sFile))
		{
			(void)fclose(sFile);
			(void)fclose(dFile);
			return 3;
		}
		if(size > 0){
			encode(buffer, encoded, size);
			//printf("%.*s",4,encoded);
			(void)fwrite(encoded, 1, (size_t)4, dFile);
			if ((_Bool)ferror(dFile))
			{
				(void)fclose(sFile);
				(void)fclose(dFile);
				return 4;
			}
		}
	}
	(void)fclose(sFile);
	(void)fclose(dFile);

	return 0;
}
  
