#ifndef __UEBUNG_8_H
#define __UEBUNG_8_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** \brief Ein Listenelement einer einfach verketetten Liste. */
struct list_element {
  struct list_element *next;	/*!< Zeigen auf den Nachfolger in der Liste */
  int value;			/*!< Der Wert der in einem Listenelement gespeichert wird. In diesem Beispiel ein int.*/
};

/** \brief Ein Listenkopf zu verwalten einer einfach verketetten Liste. */
struct list_head {
  struct list_element *front;	/*!< Zeiger auf das erste Element der Liste. */
  struct list_element *end;	/*!< Zeiger auf das letzte Element der Liste. */
};

/** \brief Diese Funktion erstellt einen neuen Listenkopf fuer ein einfach verketette Liste.
*
* \return Zeiger auf initialisierten Listenkopf bei Erfolg \n
*	  NULL im Fehlerfall
*/
struct list_head* list_new(void);

/** \brief Ein neues Listenelement erzeugen und vorn (*front) an die Liste anfuegen.
*
* \param[in] *head Der Listenkopf der Liste
*
* \return Zeiger auf das neue, initialisierte Listenelement bei Erfolg \n
*	  NULL im Fehlerfall
*/
struct list_element* list_push(struct list_head* head);

/** \brief Ein neues Listenelement erzeugen und am Ende (*end) der Liste anfuegen.
*
* \param[in] *head Der Listenkopf der Liste
*
* \return Zeiger auf das neue, initialisierte Listenelement bei Erfolg \n
*	  NULL im Fehlerfall
*/
struct list_element* list_append(struct list_head* head);

/** \brief Das erste Listenelement (*front) aus der Liste entfernen und zurueckgeben.
*
* \param[in] *head Der Listenkopf der Liste
*
* \return Zeiger auf das entfernte Listenelement bei Erfolg \n
*	  NULL wenn die Liste leer ist
*/
struct list_element* list_pop(struct list_head* head);

/** \brief Ein Listenelement der Liste zurueckgeben.
*
* Das Listenelement wird NICHT geloescht (free()).
*
* \param[in] *head Der Listenkopf der Liste
* \param[in] *element Ein Listenelement der Liste. Der Nachfolger dieses Elements (*next) wird
*			zurueckgeben.
*			Ist *element NULL, wird das erste Listenelement zurueckgeben.
*
* \return Zeiger auf das Listenelement bei Erfolg \n
*	  NULL wenn *element auf das letzte Listenelement zeigt oder wenn *element kein Element der Liste ist
*/
struct list_element* list_get_next(struct list_head* head,struct list_element* element);

/** \brief Ein neues Listenelement erzeugen und an gegebener Position in die Liste einfuegen.
*
* \param[in] *head Der Listenkopf der Liste
* \param[in] *element Ein Element der Liste. Das neue Element wird nach diesem in die Liste
*			eingefuegt.
*			Ist *element NULL, wird das Element vorn angefuegt,
*
* \return Zeiger auf das neue Listenelement bei Erfolg \n
*	  NULL im Fehlerfall oder wenn *element kein Element der Liste ist
*/
struct list_element* list_insert(struct list_head* head,struct list_element* element);

/** \brief Ein Listenelement aus der Liste entfernen.
*
* Das Listenelement wird NICHT geloescht (free()).
*
* \param[in] *head Der Listenkopf der Liste
* \param[in] *element Das zu entfernende Element.
*
* \return Zeiger auf das entfernte Listenelement bei Erfolg \n
*	  NULL im Fehlerfall oder wenn *element kein Element der Liste ist
*/
struct list_element* list_remove(struct list_head* head,struct list_element* element);

/** \brief Diese Funktion liefert die Anzahl der Listenelemente bzw. die Laenge der Liste zurueck.
*
*
* \param[in] *head Der Listenkopf der Liste
*
* \return Die Laenge der Liste
*/
uint32_t list_length(struct list_head* head);

/** \brief Diese Funktion gibt alle Elemente und den Listenkopf frei.
*
* Alle Elemente werden aus der Liste entferent und deren Speicher wird freigegeben (free()).
* Anschließend wird auch der Speicher des Listenkopfs freigegeben und *head wird auf NULL gesetzt.
*
* \param[in,out] **head Referenz auf den Listenkopf.
*/
void list_free(struct list_head** head);



#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_8_H
