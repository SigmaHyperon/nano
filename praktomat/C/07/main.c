#include "uebung7.h"

int main(){
	char pal[4] = "abb";
	char stuff[10] = {'a', 'b', 'd', '\0'};
	char text[100] = "dfughrjv;dfnbojhdriogjabdfsihgkjsfkjvbsfkjvb";
	char passwd[127] = {};
	/*printf("%i\n", my_strlen(stuff));
	my_toupper(stuff);
	printf("%s\n", stuff);
	my_tolower(stuff);
	printf("%s\n", stuff);
	printf("%s\n", my_strstr(text, stuff));
	printf("%i\n", palindrome_test(pal));*/
	passwd_gen(passwd, 127, 1);
	passwd_gen(passwd, 127, 2);
	passwd_gen(passwd, 127, 4);
	passwd_gen(passwd, 127, 8);
	return 0;
}
