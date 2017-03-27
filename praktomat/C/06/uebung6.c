
#include <stdio.h>

#include "uebung6.h"

// hier Code ergaenzen

char maze_chars[6] = {'#', ' ', 'S', 'F', '+', '?'};

unsigned int fak(unsigned int n){
	if(n == 0){
		return 1;
	}else{
		return n * fak(n-1);
	}
}

unsigned int fak_it(unsigned int n){
	if(n == 0){
		return 1;
	}else{
		int i;
		int ret = 1;
		for(i = n; i >= 1; i--){
			ret = ret * i;
		}
		return ret;
	}
}

unsigned int fib(unsigned int n){
	if(n <= 2){
		return 1;
	}else{
		int ret = fib(n-1) + fib(n-2);
		return ret;
	}
}

void maze_print(unsigned char labyrinth[][100],uint8_t size_x,uint8_t size_y){
	int i, j;
	for(i = 0; i < (int)size_x; i++){
		for(j = 0; j < (int)size_y;j++){
			printf("%c",maze_chars[(int)labyrinth[i][j]]);
		}
		printf("\n");
	}
}

int maze_from_file(char* filename,unsigned char labyrinth[][100],uint8_t *size_x,uint8_t *size_y){
	FILE *sFile;
	char line[101];
	int linenumber = 0;
	int i = 0;
	int x, y;
	sFile = fopen(filename, "rb");
	if(sFile == NULL)
	{
		return 1;
	}
	(void)fgets(line,101,sFile);
	if((_Bool)ferror(sFile))
	{
		(void)fclose(sFile);
		return 2;
	}
	if(sscanf(line, "%dx%d", &x, &y) < 2){
		(void)fclose(sFile);
		return 2;
	}
	*size_y = (uint8_t)y;
	*size_x = (uint8_t)x;

	if(*size_x > 100 || *size_y > 100){
		return 3;
	}
	//return 0;
	while( !(_Bool)ferror(sFile) && !(_Bool)feof(sFile) && linenumber < (int) *size_x)
	{
		(void)fgets(line,101,sFile);
		if((_Bool)ferror(sFile))
		{
			(void)fclose(sFile);
			return 2;
		}
		for(i = 0; (i<(int)*size_y); i++){
			switch(line[i]){
				case 'W': labyrinth[linenumber][i] = (unsigned char)MAZE_WALL; break;
				case ' ': labyrinth[linenumber][i] = (unsigned char)MAZE_WALKWAY; break;
				case 'S': labyrinth[linenumber][i] = (unsigned char)MAZE_START; break;
				case 'F': labyrinth[linenumber][i] = (unsigned char)MAZE_FINISH; break;
				default: labyrinth[linenumber][i] = (unsigned char)MAZE_WALL;
			}
		}
		linenumber++;
		//printf("%s", line);

	}
	if((_Bool)ferror(sFile))
	{
		(void)fclose(sFile);
		return 2;
	}
	if(!(_Bool)feof(sFile))
	{
		(void)fclose(sFile);
		return 0;
	}
	(void)fclose(sFile);

	return 0;
}

struct Point maze_start_pos(unsigned char labyrinth[][100],uint8_t size_x,uint8_t size_y){
	int i, j;
	struct Point ret;
	ret.x = -1;
	ret.y = -1;
	for(i = 0; i < (int)size_x; i++){
		for(j = 0; j < (int)size_y;j++){
			if(labyrinth[i][j] == (unsigned char)MAZE_START){
				ret.y = (int8_t)j;
				ret.x = (int8_t)i;
			}
		}
	}
	return ret;
}

int maze(unsigned char labyrinth[][100],uint8_t size_x,uint8_t size_y,uint8_t start_x,uint8_t start_y){
	int ret = 0;
	//up
	if(start_x > 0){
		if(labyrinth[start_x - 1][start_y] == (unsigned char)MAZE_FINISH){
			return 0;
		}
		if(labyrinth[start_x - 1][start_y] == (unsigned char)MAZE_WALKWAY){
			labyrinth[start_x - 1][start_y] = (unsigned char)MAZE_STEP;
			ret = maze(labyrinth, size_x, size_y, start_x-1, start_y);
			if(ret == 0){
				return 0;
			}
			labyrinth[start_x - 1][start_y] = (unsigned char)MAZE_WRONG;
		}
	}

	//down
	if(start_x < (size_x-1)){
		if(labyrinth[start_x + 1][start_y] == (unsigned char)MAZE_FINISH){
			return 0;
		}
		if(labyrinth[start_x + 1][start_y] == (unsigned char)MAZE_WALKWAY){
			labyrinth[start_x + 1][start_y] = (unsigned char)MAZE_STEP;
			ret = maze(labyrinth, size_x, size_y, start_x+1, start_y);
			if(ret == 0){
				return 0;
			}
			labyrinth[start_x + 1][start_y] = (unsigned char)MAZE_WRONG;
		}
	}

	//left
	if(start_y > 0){
		if(labyrinth[start_x][start_y - 1] == (unsigned char)MAZE_FINISH){
			return 0;
		}
		if(labyrinth[start_x][start_y - 1] == (unsigned char)MAZE_WALKWAY){
			labyrinth[start_x][start_y - 1] = (unsigned char)MAZE_STEP;
			ret = maze(labyrinth, size_x, size_y, start_x, start_y - 1);
			if(ret == 0){
				return 0;
			}
			labyrinth[start_x][start_y - 1] = (unsigned char)MAZE_WRONG;
		}
	}

	//right
	if(start_y < (size_y-1)){
		if(labyrinth[start_x][start_y + 1] == (unsigned char)MAZE_FINISH){
			return 0;
		}
		if(labyrinth[start_x][start_y + 1] == (unsigned char)MAZE_WALKWAY){
			labyrinth[start_x][start_y + 1] = (unsigned char)MAZE_STEP;
			ret = maze(labyrinth, size_x, size_y, start_x, start_y + 1);
			if(ret == 0){
				return 0;
			}
			labyrinth[start_x][start_y + 1] = (unsigned char)MAZE_WRONG;
		}
	}
	return 1;
}
