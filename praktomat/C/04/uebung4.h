#ifndef __UEBUNG_4_H
#define __UEBUNG_4_H

#ifdef __cplusplus
extern "C"
{
#endif

/** \brief Datei auf der Standardausgabe ausgeben
*
* \param[in] *filename Name/Pfad der Datei die ausgegeben wird
* \return 0 bei Erfolg \n
*         1 Fehler beim Oeffnen \n
*         2 Fehler beim Auslesen der Datei
*/
int print_file(char *filename);


/** \brief Datei kopieren
*
* \param[in] *source Name/Pfad der Datei die kopiert wird (Quelldatei)

* \return 0 bei Erfolg \n
*         1 Fehler beim Oeffnen der Quelldatei \n
*         2 Fehler beim Oeffnen der Zieldatei \n
*         3 Fehler beim Auslesen der Quelldatei \n
*         4 Fehler beim Schreiben der Zieldatei
*/
int copy_file(char *source,char* dest);

/** \brief enum zum Beschreiben des Geschlechts
*
*/
enum e_addressbook_sex {
  ADDRESSBOOK_SEX_MALE=0,
  ADDRESSBOOK_SEX_FEMALE,
  ADDRESSBOOK_SEX_UNKNOWN
};

/** \brief Struktur die ein Geburtsdatum speichert
*
*/
struct s_date_of_birth {
  int year:23;                 /*!< Jahr */
  unsigned int month:4;        /*!< Monat */
  unsigned int day:5;          /*!< Tag */
};

/** \brief Struktur die einen Datensatz eines Adressbuchs definiert
*
*/
struct s_addressbook_record {
  unsigned int id;               /*!< id zum verwalten der Eintraege */
  char name[30];                 /*!< Name */
  char firstname[30];            /*!< Vorname */
  enum e_addressbook_sex sex;    /*!< Geschlecht */
  struct s_date_of_birth birth;  /*!< Geburtsdatum */
};

struct id3tag
{
	char tag[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	char genre;
};

/** \brief Diese Funktion speichert ein Adressbuch in einer Datei
*	
* \param[in] *filename Name/Pfad der Zieldatei
* \param[in] *addressbook ein Array mit Adressbuchdatensaetzen
* \param[in] entries Anzahl der Datensaetze im Array
* \param[in] append Zieldatei neu anlegen (append==0) oder Daten anfuegen (append=1)
* \return 0 bei Erfolg \n
*         1 Fehler beim Oeffnen der Datei \n
*         2 Fehler beim Schreiben der Datei
*/
int addressbook_save(char* filename,struct s_addressbook_record* addressbook,int entries,int append);


/** \brief Diese Funktion liest ein Adressbuch aus einer Datei ein und speichert die Datensaetze in einem Array
*	
* \param[in] *filename Name/Pfad der Datei (Adressbuch)
* \param[out] *addressbook Array in dem die Datensaetze abgelegt werden
* \param[in,out] *entries Anzahl der verfuegbaren Speicherplaetze im Array (input) \n
*                         Anzahl der eingelesenen Datensaetze (output)
* \return 0 bei Erfolg \n
*         1 Fehler beim Oeffnen der Datei \n
*         2 Fehler beim Auslesen der Datei \n
*         3 Weitere Datensaetze in der Quelldatei, aber das Ziel-Array (addressbook) ist voll (entries)
*/
int addressbook_load(char* filename,struct s_addressbook_record* addressbook,int *entries);

/** \brief ID3-Tag einer MP3-Datei auszulesen und auf der Standardausgabe auszugeben
*	
* \param[in] *filename Name/Pfad der MP3-Datei
* \return 0 bei Erfolg \n
*         1 Fehler beim Oeffnen der MP3-Datei \n
*         2 Kein ID3-Tag in der Datei vorhanden \n
*         3 Fehler beim Auslesen der MP3-Datei
*/
int print_id3(char* filename);

int set_id3(char* filename, struct id3tag tag);

#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_4_H
