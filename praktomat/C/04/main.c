#include <stdio.h>
#include "uebung4.h"

int main()
{
//	struct s_addressbook_record aBook[5];
//	struct s_addressbook_record bBook[5];
//	struct s_addressbook_record cBook[5];
/*	strncpy(aBook[0].firstname, "Takao", 30);
	strncpy(aBook[0].name, "Heavy Cruiser", 30);
	aBook[0].id = 0;
	struct s_date_of_birth aBirth;
	aBirth.day = 12;
	aBirth.month = 5;
	aBirth.year = 1930;
	aBook[0].birth = aBirth;
	aBook[0].sex = 1;

	strncpy(aBook[1].firstname, "Yamato", 30);
	strncpy(aBook[1].name, "Super Battleship", 30);
	aBook[1].id = 1;
	struct s_date_of_birth bBirth;
	bBirth.day = 8;
	bBirth.month = 8;
	bBirth.year = 1940;
	aBook[1].birth = bBirth;
	aBook[1].sex = 2;

	strncpy(aBook[2].firstname, "Shimakaze", 30);
	strncpy(aBook[2].name, "experimental Destroyer", 30);
	aBook[2].id = 2;
	struct s_date_of_birth cBirth;
	cBirth.day = 18;
	cBirth.month = 7;
	cBirth.year = 1942;
	aBook[2].birth = cBirth;
	aBook[2].sex = 1;*/
/*	strncpy(aBook[0].firstname, "Hans", 30);
	strncpy(aBook[0].name, "Wurst", 30);
	aBook[0].id = 0;
	struct s_date_of_birth aBirth;
	aBirth.day = 23;
	aBirth.month = 5;
	aBirth.year = 1996;
	aBook[0].birth = aBirth;
	aBook[0].sex = 0;

	strncpy(aBook[1].firstname, "Max", 30);
	strncpy(aBook[1].name, "Mustermann", 30);
	aBook[1].id = 1;
	struct s_date_of_birth bBirth;
	bBirth.day = 17;
	bBirth.month = 11;
	bBirth.year = 1992;
	aBook[1].birth = bBirth;
	aBook[1].sex = 0;

	strncpy(aBook[2].firstname, "Erika", 30);
	strncpy(aBook[2].name, "Mustermann", 30);
	aBook[2].id = 2;
	struct s_date_of_birth cBirth;
	cBirth.day = 3;
	cBirth.month = 3;
	cBirth.year = 1995;
	aBook[2].birth = cBirth;
	aBook[2].sex = 1;*/

//	int entries = 3;
//	int entries2 = 6;



struct id3tag aTag;
strcpy(aTag.tag,"TAG");
strcpy(aTag.title,"test");
strcpy(aTag.artist, "test2");
strcpy(aTag.album, "test3");
strcpy(aTag.year, "2016");
strcpy(aTag.comment, "test4");
aTag.genre = 117;
//	printf("test1 returned %i\n",print_file("test_files/test.txt"));
//	printf("test2 returned %i\n",copy_file("test_files/test.txt", "test_files/test2.txt"));
//	printf("test3 returned %i\n",addressbook_save("addressbook.book",aBook, entries, 1));
//	printf("test4 returned %i\n",addressbook_load("addressbook.book",bBook, &entries2));
//	printf("test4 returned %i\n",entries2);
//	int ret2 = addressbook_load("test_files/address.book",cBook, &entries2);
//	print_id3("test_files/mp3/test1.mp3");
//	printf("\n");
//	print_id3("test_files/mp3/test2.mp3");
//	printf("\n");
//	print_id3("test_files/mp3/test3.mp3");
//	printf("\n");
//	print_id3("test_files/mp3/test6.mp3");
//	printf("test5 returned %i\n",print_id3("test.txt"));
	print_id3("test_files/mp3/test3.mp3");
	set_id3("test_files/mp3/test3.mp3", aTag);
	print_id3("test_files/mp3/test3.mp3");
	return 0;
}
