#include "platform.h"
/*-----------------------------------------------------------------------------*
| GetKey: function per il riconoscimento dei tasti direzionali.				    |
|                                                                              |
| Richiede input da tastiera tramite la funzione Getch (ArCisoft's PLATFORM).  |
| Riconosce sequenze di caratteri appartenenti a tabelle ASCII estese          |
| codificandole in un unico intero (costituito dalla somma delle sequenze      |
| di riconoscimento e il carattere più significativo), nel caso si tratti      |
| di uno dei quattro tasti freccia. In caso contrario, restituisce l'intero    |
| del corrispondente tasto digitato.                                           |
|                                                                              |
| La function e' multipiattaforma e necessita della seguente tabella di        |
| decodifica:																                   |
|																			                      |
|		   	sistemi UNIX                                                       |
|		      27+91+68 = freccia sinistra                                        |
|           27+91+67 = freccia destra                                          |
|           27+91+65 = freccia su                                              |
|           27+91+66 = freccia giu	                                           |
|           sistemi MICROSOFT                                                  |
|	         224+100+75 = freccia sinistra                                          |
|           224+100+77 = freccia destra                                            |
|           224+100+72 = freccia su                                                |
|           224+100+80 = freccia giu	                                              |
|                                                                              |
| Creazione: 20/11/2008                                   Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

int GetKey()
{
#ifdef _GNU_SOURCE
/*-----------------------------------------------------------------------------*
| Procedura per sistemi UNIX                                                   |
*-----------------------------------------------------------------------------*/
 char* buffer;// buffer di lettura: contiene una stringa o un carattere digitato
 int n;		  // lunghezza della stringa digitata
 int key;	  // intero del carattere di output
 
 n=0;
 buffer=(char*)calloc(16,sizeof(char));
 buffer[n]=Getch();  // memorizza input o parte di esso nella prima locazione

 n=strlen(stdin->_IO_read_ptr); // conta i caratteri rimasti nel buffer di stdin
 if(n!=0)   // se sono presenti altri caratteri nel buffer di stdin 
 {
   fgets(buffer,n+1,stdin); // salva il resto della sequenza nell'array buffer
   key=buffer[n-1]+27+91;   // aggiorna l'output con il codice id della freccia
                            // determinata dal carattere più significativo
 }
 else       // se non sono presenti altri caratteri nello stream
   key=buffer[n];           // aggiorna l'output con l'unico carattere salvato
   
 free(buffer);
 stdin->_IO_buf_base='\0';// azzera la stringa puntata dal buffer dello stream
                          // stdin, evitando l'occorrenza di caratteri residui
 return key;
#else
/*-----------------------------------------------------------------------------*
| Procedura per sistemi MICROSOFT                                              |
*-----------------------------------------------------------------------------*/
	int buffer;      // buffer di lettura: contiene l'input da tastiera

	buffer=Getch();  // ottiene il primo carattere della sequenza
	if(buffer==224)  // se si tratta del codice identificativo
		buffer+=Getch()+100;    // aggiorna il nostro buffer sommandolo al 
		                       // carattere rimasto nello stdin
		
	return buffer;
#endif
}
