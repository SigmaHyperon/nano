#ifndef __UEBUNG_7_H
#define __UEBUNG_7_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif


/** \brief Diese Funktion bestimmt die Laenge eines Null-terminierten Strings
*
* \param[in] *str der String
*
* \return Laenge des Strings; das '\0'-Zeichen wird nicht mitgezaehlt \n
*         -1 wenn str NULL ist \n
*/
int my_strlen(char* str);


/** \brief Diese Funktion ersetzt alle Kleinbuchstaben durch Grossbuchstaben im gegebenen String
*
* \param[in,out] *str der String
*/
void my_toupper(char* str);


/** \brief Diese Funktion ersetzt alle Grossbuchstaben durch Kleinbuchstaben im gegebenen String
*
* \param[in,out] *str der String
*/
void my_tolower(char* str);


/** \brief Die Funktion findet die erste Position der Zeichenfolge substr im String str.
*
* \param[in] *str der String
* \param[in] *substr Substring; die Zeichenkette die in str gesucht wird
*
* \return Zeiger auf den Anfang der gefundenen Zeichenkette in str oder NULL
*/
char* my_strstr(char* str,char* substr);


/** \brief Die Funktion prueft, ob der gegebene String ein Palindrom ist
*
* \param[in] *str der String
*
* \return 0 - str ist kein Palindrom \n
*         1 - str ist ein Palindrom \n
*        -1 - str ist NULL
*/
int palindrome_test(char* str);


enum CharacterSet {
  LOWER_LETTERS 	= (1<<0),	/*!< a-z */
  CAPITAL_LETTERS	= (1<<1),	/*!< A-Z */
  DIGITS		= (1<<2),	/*!< 0-9 */
  SPECIAL_LETTERS	= (1<<3)	/*!< #+*-_... */
  };

/** \brief Diese Funktion generiert ein zufaelliges Passwort ueber dem Alphabeth der gegebenen Zeichenklassen
*
* \param[out] *passwd in diesem String wird das Passwort gespeichert
* \param[in] passwd_len die Laenge des Passwort das zurueckgegeben wird; passwd muss mind. passwd_len+1 Zeichen aufnehmen koennen
* \param[in] char_set die zu verwendenden Zeichenklassen
*
* \return 0 bei Erfolg \n
*         1 bei Fehler (passwd==NULL, passwd_len<1, keine Zeichenklasse)
*/
int passwd_gen(char* passwd,uint16_t passwd_len,uint8_t char_set);



int compareString(char* str1, char* str2, int length);

#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_7_H
