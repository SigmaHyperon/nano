#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "uebung7.h"

 /* Code hier einfuegen */
int my_strlen(char* str){
	if (str == NULL){
		return -1;
	}
	int counter = 0;
	while (str[counter] != '\0'){
		counter ++;
	}
	return counter;
}

void my_toupper(char* str){
	if (str == NULL){
		return;
	}
	int i;
	for(i = 0; i < my_strlen(str); i++){
		if((str[i] >= 'a') && (str[i] <= 'z')){
			str[i] = str[i] & ~(1 << 5);
		}
	}
}

void my_tolower(char* str){
	if (str == NULL){
		return;
	}
	int i;
	for(i = 0; i < my_strlen(str); i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] | (1 << 5);
		}
	}
}

char* my_strstr(char* str,char* substr){
	if(str == NULL || substr == NULL){
		return NULL;
	}
	int i;
	for (i = 0; i < my_strlen(str); i++){
		if(str[i] == substr[0]){
			if(compareString(str + i, substr, my_strlen(substr))){
				return str + i;
			}
		}
	}
	return NULL;

}

int compareString(char* str1, char* str2, int length){
	if(str1 == NULL || str2 == NULL){
		return 0;
	}
	int i;
	for (i = 0; i < length; i++){
		if(str1[i] != str2[i]){
			return 0;
		}
	}
	return 1;
}

int palindrome_test(char* str){
	if(str == NULL){
		return -1;
	}
	int i;
	int length = my_strlen(str);
	for (i = 0; i < length; i++){
		if(str[i] != str[length - 1 - i]){
			return 0;
		}
	}
	return 1;
}

int passwd_gen(char* passwd,uint16_t passwd_len,uint8_t char_set){
	if(passwd == NULL || char_set == 0 || passwd_len == 0){
		return 1;
	}
	char CharSet[256] = {};
	int i = 0;
	int counter = 0;
	if(char_set & LOWER_LETTERS){
		for (i = counter; i < counter + 26; i++ ){
			CharSet[i] = 'a' + i - counter;
		}
		counter = i;
	}
	if(char_set & CAPITAL_LETTERS){
		for (i = counter; i < counter + 26; i++ ){
			CharSet[i] = 'A' + i - counter;
		}
		counter = i;
	}
	if(char_set & DIGITS){
		for (i = counter; i < counter + 10; i++ ){
			CharSet[i] = '0' + i - counter;
		}
		counter = i;
	}
	if(char_set & SPECIAL_LETTERS){
		for (i = counter; i < counter + 15; i++ ){
			CharSet[i] = '!' + i - counter;
		}
		counter = i;
	}
	time_t t;
	srand((unsigned) time(&t));
	int j;
	for (j = 0; j < passwd_len; j++){
		/*unsigned int upper = counter;
		float lower = rand()/(RAND_MAX+1);
		printf("u:%i ", upper);
		printf("l:%f ", lower);*/
		//int index = 0;
		int index = (int)((float)counter*rand()/(RAND_MAX+1.0));
		//int index = rand()%counter;
		//printf("i:%i ", index);
		//printf("%i", rand());
		//int index = random(counter);
		passwd[j] = CharSet[index];
	}
	//printf("\n");
	static int turn = 0;
	turn ++;
	passwd[j] = '\0';
	//printf("%s %i %i %i\n", passwd, passwd_len, char_set, turn);
	//printf("%i\n", RAND_MAX);
	//printf("%i\n", rand());
	//printf("%s\n",system("head -5 /dev/urandom"));
	return 0;
}
