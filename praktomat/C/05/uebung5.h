#ifndef __UEBUNG_5_H
#define __UEBUNG_5_H

#ifdef __cplusplus
extern "C"
{
#endif

/** \brief Ausgabe einer Ganszahl in Hexadezimal- und Binaerdarstellung
*
*  Bsp. Ausgabe: "0x0000F172: 0000 0000 0000 0000 1111 0001 0111 0010"
*
* \param[in] x Der Wert der hex und bin dargestellt wird
*/
void bits_print(unsigned int x);
void cbits_print(unsigned char x);

/** \brief binaere Rotation nach rechts um ein Bit
*
* \param[in] x der Wert auf den diese Operation angewendet wird
* \return der Wert von x nach der Rotation
*/
int bits_ror(unsigned int x);

/** \brief binaere Rotation nach links um ein Bit
*
* \param[in] x der Wert auf den diese Operation angewendet wird
* \return der Wert von x nach der Rotation
*/
int bits_rol(unsigned int x);

/** \brief diese Funktion ermittelt den Wert eines Bits in einer Ganszahl
*
* \param[in] x die Zahl
* \param[in] pos die Position des abgefragten Bits; Gueltige Werte 0 bis Bitbreite-1 (z.B. 0 bis 31)
* \return der Wert des Bits: 0 oder 1 \n
*         -1 im Fehlerfall
*/
int bit_get(unsigned int x,unsigned char pos);

/** \brief diese Funktion gibt mehre Bits einer gegeben Ganszahl zurueck
*
*  Gegeben ist eine Zahl, von der ab einer Posoition 'pos' ein oder mehr Bits ('len') zurueckgegeben 
*  werden sollen. Der zurueckgelieferte Bit-Bereich ist an Bit 0 auszurichten, d.h. werden die Bits 5,6 und 7
*  abgefragt, enthaelt das Ergebnis (Rueckgabewert) diese Bits an Position 0,1 und 2.
*
* \param[in] x die Zahl
* \param[in] pos die Position ab der Bits abgefragt werden; kleinster moeglicher Wert ist 0
* \param[in] len die Anzahl der Bits die beginned bei pos abgefragt werden
* \return der Wert der Bits\n
*         -1 im Fehlerfall
*/
int bit_get_range(unsigned int x,unsigned char pos,unsigned char len);

/** \brief diese Funktion initialisiert das globale Array 'g_lookup_table'
*
*/
void init_lookup_table();

/** \brief diese Funktion kodiert 1 bis 3 Eingabebyte in 4 Ausgabe Byte
*
*  Die Kodierung erfolgt gemaess der Aufgabenstellung/Beschreibung.
*
*  \note Bevor diese Funktion genutzt werden kann, muss die Funktion 'init_lookup_table()'
*        gerufen werden!
*
* \param[in] input 1 bis 3 Byte Eingabesymbole, die Laenge wird durch 'length' bestimmt
* \param[out] output enthaelt das Ergebnis der Kodierung
* \param[in] length Laenge der in input zu nutzenden Daten; gueltige Werte: 1, 2 und 3
* \return 0 bei Erfolg \n
*         1 bei ungueltiger Laenge
*/
int encode(unsigned char input[3],unsigned char output[4],int length);

/** \brief diese Funktion verwendet die Funktion 'encode()' um eine gegebene Datei zu kodieren
*
*  \note Bevor diese Funktion genutzt werden kann, muss die Funktion 'init_lookup_table()'
*        gerufen werden!
*
* \param[in] in_filename Name/Pfad der Quelldatei
* \param[in] out_filename Name/Pfad der Zieldatei
* \return 0 bei Erfolg \n
*         1 Fehler beim Offnen der Quelldatei \n
*         2 Fehler beim Anlegen und Oeffnen der Zieldatei \n
*         3 Fehler beim Lesen der Quelldatei \n
*         4 Fehler beim Schreiben der Zieldatei \n
*/
int encode_file(char* in_filename,char* out_filename);

#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_5_H
