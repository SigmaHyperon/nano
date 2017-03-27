#ifndef __UEBUNG_6_H
#define __UEBUNG_6_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif


/** \brief Diese Funktion berechnet die Fakultaet rekursiv fuer den Wert n
*
* \param[in] n 
* \return die Fakultaet von n
*/
unsigned int fak(unsigned int n);

/** \brief Diese Funktion berechnet die Fakultaet iterativ fuer den Wert n
*
* \param[in] n 
* \return die Fakultaet von n
*/
unsigned int fak_it(unsigned int n);

/** \brief Diese Funktion berechnet die Fibonacci-Folge rekursiv fuer den Wert n
*
* \param[in] n 
* \return der Wert der Fibonacci-Folge fuer n
*/
unsigned int fib(unsigned int n);

/** \brief Der Type an einer Koordinate im Labyrith.
*
*/
enum maze_field_type {
    MAZE_WALL = 0,      /*!< Wand */
    MAZE_WALKWAY,       /*!< Gang */
    MAZE_START,         /*!< Start */
    MAZE_FINISH,        /*!< Ziel */
    MAZE_STEP,          /*!< Ein Schritt zum Ziel */
    MAZE_WRONG          /*!< Falscher Weg */
};

/** \brief Ein Labyrith auf der Konsole ausgeben
*
* \param[in] labyrinth Das Labyrith das ausgegeben werden soll
* \param[in] size_x Die Groesse des Labyriths in x-Richtung \n
*		    Gueltige Indizes fuer x sind 0 bis size_x-1
* \param[in] size_y Die Groesse des Labyriths in y-Richtung \n
*		    Gueltige Indizes fuer y sind 0 bis size_y-1
*/
void maze_print(unsigned char labyrinth[][100],uint8_t size_x,uint8_t size_y);

/** \brief Ein Labyrith aus einer Datei auslesen
*
* \param[in] *filename Name der Datei in der das Labyrith gespeichert ist
* \param[out] labyrinth Ein Array in dem das eingelesene Labyrith gespeichert wird
* \param[out] *size_x Die Groesse des Labyriths in x-Richtung \n
*		    Gueltige Indizes fuer x sind 0 bis size_x-1
* \param[out] *size_y Die Groesse des Labyriths in y-Richtung \n
*		    Gueltige Indizes fuer y sind 0 bis size_y-1
*
* \return 0 bei Erfolg \n
*	  1 Fehler beim Oeffnen der Datei
*	  2 Fehler beim Lesen der Datei
*	  3 Labyrith in der Datei ist zu gross
*	  4 sonstige Fehler
*/
int maze_from_file(char* filename,unsigned char labyrinth[][100],uint8_t *size_x,uint8_t *size_y);


struct Point
{
  int8_t x;
  int8_t y;
};

/** \brief Startpunkt eines Labyriths bestimmen
*
* \param[in] labyrinth Das Labyrith
* \param[in] size_x Die Groesse des Labyriths in x-Richtung \n
*		    Gueltige Indizes fuer x sind 0 bis size_x-1
* \param[in] size_y Die Groesse des Labyriths in y-Richtung \n
*		    Gueltige Indizes fuer y sind 0 bis size_y-1
*
* \return ein gueltiger Startpunbkt bei Erfolg \n
*	  die Koordinaten (-1,-1) im Fehlerfall
*/
struct Point maze_start_pos(unsigned char labyrinth[][100],uint8_t size_x,uint8_t size_y);


/** \brief Einen Weg durch das Labyrith suchen
*
* \param[in] labyrinth Das Labyrith das ausgegeben werden soll
* \param[in] size_x Die Groesse des Labyriths in x-Richtung \n
*		    Gueltige Indizes fuer x sind 0 bis size_x-1
* \param[in] size_y Die Groesse des Labyriths in y-Richtung \n
*		    Gueltige Indizes fuer y sind 0 bis size_y-1
* \param[in] start_x X-Koordinate des Startpunktes
* \param[in] start_y Y-Koordinate des Startpunktes
*
* \return 0 ein Weg wurde gefunden -- Erfolg \n
*	  1 kein Weg gefunden
*/
int maze(unsigned char labyrinth[][100],uint8_t size_x,uint8_t size_y,uint8_t start_x,uint8_t start_y);


#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_6_H
