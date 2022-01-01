# Learning C
## Changelog
```
+ Makros
+ bedingte Kompilierung
+ Header einbinden
+ structs(unv.)
+ zeigerarithmetik
+ 2 und mehrdimensionale Arrays
+ malloc, calloc, free
+ 26.03.: Fundgrube: gets(), Umlaute ersetzt
+ "inspired by" in der Linksammlung hinzugefuegt
+ 29.03.: Abschnitte File IO und Error Handling hinzugefügt
+ File IO hinter Basic IO verschoben 
```
## Allgemeines
* [Prozess des Kompilierens](https://codeforwin.org/2017/08/c-compilation-process.html)
* [Keywords und Identifier](https://codeforwin.org/2017/08/keywords-identifiers-c.html)
* [Operatoren](https://en.wikipedia.org/wiki/Operators_in_C_and_C) 
* keine access modifiers (private, public, ..) wie in Java (warum?)
* main braucht keinen expliziten return code
## Datentypen
* Ganzzahlen: `int, char, short, long, long long`
* Ganzzahlen:(ohne Vorzeichen): wie oben mit zusätzlichem Keyword `unsigned`
* Fliesskommazahlen: `float, double`
* (selbst) strukturierte Datentypen: `struct`
* zu Boolean: Es gibt per default kein Boolean in C!!
    * ab C99: `#include <stdbool.h>`
    * sonst selbst definieren wie folgt:
    ```c= 
    #define bool char;
    #define true 1;
    #define false 0;
    ```
    ![Data types hierarchy in C](https://codeforwin.org/wp-content/uploads/2017/08/Data-types-hierarchy-in-C-language.png)
## Strings
* Präprozessoranweisung: `#include <string.h>`
* Strings sind Char-Arrays
* Referenzierung auch über char-Pointer sinnvoll
* Definition: `char name[]= "John Smith";`
* Länge: `strlen(name);`
* Vergleich (char-weise): 
```c=
char lhs[]= "John Smith";  
char rhs[]= "John Doe";  
printf("%d", strcmp(lhs, rhs)); //int Wert des Vergleichs  
// =0 - gleich  
// <0 - 1.unterschiedlicher char ist diesen Wert kleiner in lhs  
// >0 - 1.unterschiedlicher char ist diesen Wert grösser in lhs  
  
printf("\\n%d", strncmp(lhs, rhs, 5));
//letzter Wert gibt Anzahl zu vergl.chars an, Ergebnis: 0

```


## Pointer
* Allgemeines

    * Pointer sind Zeiger auf andere Variablen. Variablen sind Adressen im Arbeitsspeicher. Also zeigen Pointer auf Adressen im RAM.
    * Pointer werden so zugewiesen, dass sie auf den Wert der Variablen zeigen (obwohl sie selbst nur auf einer Speicheradresse angelegt sind --> Verweise)

* Deklaration im C-Code
    * Pointer muss selben Datentyp wie die Variable haben, auf die gezeigt wird
    * Kennzeichnung mit * (Dereference)
    * um den Wert aus der Speicherstelle zu lesen, wird der Reference-Operator & benutzt. Damit wird der WERT der Variablen in die Pointervariable gespeichert.
    * um den Wert der Pointervariablen auszugeben, wird der Dereference-Operator * vor den Pointernamen geschrieben
    * Beispiel:
    ```c=
    int main(){
        int test=1000;
        int *pTest = &test            //liest aus test
        printf("test: %d/n", test);   //1000
        printf("pTest: %d/n", *pTest);//1000
        printf("pTest: %p/n", &pTest);//Adresse des Pointers
        *pTest=2000
        printf("test: %d/n", test);   //2000 (Whut??)
    } 
    ```
* Advanced: Void Pointer:
    * Void Pointer können einen beliebigen Typ von Pointern entgegen nehmen
    * Void Pointer können nicht dereferenziert werden
    * Stattdesssen muss ein cast auf den richtigen Typ gemacht werden

*Dieses Programm wird nicht kompilieren:*
```c=
int main(){
    int a = 10;
    void *ptr = &a;
    printf("%d", *ptr);
    return 0;
}
```
*Was stattdessen funktioniert:*
``` c=
int main(){
    int a[] = {1, 2};
    void *ptr = &a;
    ptr = ptr + sizeof(int);    //sizeof(int)x Index der gesuchten Speicherstelle +1
    printf("%d", *(int *) ptr);    //Cast auf int zum Dereferenzieren; output: 2
    return 0;
}
```
*Anderes Beispiel:*
``` c=
int main(){
    int a = 1000;
    void *ptr = &a;
    printf("%d", *(int *) a);    //Output: 1000
    return 0;
}
```
## Arrays
* 0-basiert
* Es gibt keine Grenzen! Da es keine Exceptions gibt, zeigen Zugriffe ausserhalb des Arrays auf freie Speicherstellen
* Initialisierung: `Datentyp name[groesse];` z.B. `int array[5];` 
* auch direkte Zuweisung ist möglich, z.B.: `int array[]={1,2,3};`
* 2-dimensionale Arrays: `int array2[5][2];` oder
 `int array2[][]={{1,2,3,4,5},{1,2}}`
 Beispiel:
 ```c=
 //Initialisierung und Ausgabe eines 2-dimensionalen Array vom Typ array[Y][X]  
int brett[8][8]={0};  
brett[2][1]=1;  
brett[4][2]=2;  
brett[3][5]=3;  
brett[6][7]=4;  
  
int i,j;  
  
for (i=0; i<8; i++){  
    for (j=0; j<8; j++){  
        printf("%d", brett[i][j]);  
   }  
    printf("\n");  
}
```
* mehrdimensionale Arrays analog mit Typ `array[X][Y][Z]..`
* Dimension des Arrays herausfinden:
```c=
int array[]={1,2};  
int s= sizeof(array[0]); //eine beliebigen Speicherstelle (hier 1.)  
int n = sizeof(array)/ s; //Formel zur Grössenberechnung!!  
printf("\n%d", s); //grösse einer int-Speicherstelle (4 bei 64bit)  
printf("\n%d", n); //grösse von array
```
## Literals
### Integer Literals
* können als Dezimal, Octal und Hexadezimal angegeben werden
    * Dezimal z.B. `a = 111;`
    * Octal z.B. `b = 0165;`
    * Hexadezimal z.B. `c = 0X1A5;`
*  zusätzlich können noch u/U für Unsigned, l/L für Long und ul/UL für Unsigned Long Integer hinzugefügt werden
### Float Literals
* entweder als Dezimal- oder als Exponential-Notation
    * Dezimal: z.B.: `+1` `1.2` `-0.4` `0.` `.3` `-.3`
    * Exponentialschreibweise, allgemeine Syntax:
    `[+/-] <Mantissa> <e/E> [+/-] <Exponent>`
    z.B.: `0.1e1` `0e-5` `5e25` `+5E+10` `-5.2e0`
### Character Literals
* es gibt viele Wege, Character Literals auszudrücken:
    * in single quotes: z.B. `‘a’` `‘0’` `‘/’` `‘.’`
    * als escape sequence characters: z.B. `‘\n’` `‘\a’` `‘\b’`
    * als ASCII Repräsentant: z.B. `65` für `A`
    * als Octal- oder Hexadezimal-Repräsentant unter Nutzung der escape sequence: z.B. `\05` `\xA`
    * als UniCode-Wert des Characters: z.B. `\u00A9`
    * Multi-Character-Konstanten: theoretisch möglich, aber nicht praktikabel, denn `'abcd'` ist für den Compiler das selbe wie `'d'`
### String Literals
* sind eine Folge (ein Array) von Characters in double quotes
* String literals belegen (Anzahl der Chars)+1 Bytes
* das letzte Byte ist ein `\0` (NULL)-Character, der das Ende des Strings anzeigt
* Konkatenation mit '+' ist möglich
* Beispiel String Literal und Ausgabe:
```c=
char b[] = "Test-String";  
printf("%s", b); //Ausgabe mit %s
```
## Mathematische Ausdruecke
* werden durch `#include <math.h>` zur Verfügung gestellt
* [Referenz mit allen Methoden](http://www.cplusplus.com/reference/cmath/)
* Konstanten werden mit dem Keyword `const` oder mit `#define` deklariert
    * Beispiele: 
        * als Präprozessoranweisung: `#define PI 3.14159`
        * mit `const`: 
        `const float PI = 3.14159f;` `float const e = 2.71828f;`
## Basic IO
* Beispiel für IO mit einzelnem Char:
``` c= 
/*
 * Basic I/O Programm zum Einlesen eines Characters 
 */
#include <stdio.h>  
 
   int main(){
   
       char buchstabe;  
       printf("Bitte einen Buchstaben eingeben: ");  
  
   /* Input character using getchar() and store in buchstabe */  
       buchstabe = getchar();  
  
   /* Output buchstabe using putchar() */  
       putchar(buchstabe);  
  
       return 0;  
   }
```
* Beispiel mit scanf() und printf():
``` c=
/**  
 * Basic I/O Programm zum Einlesen eines Strings 
 */
 #include <stdio.h>  
  
   int main(){
   
       char buchstabe\[100\]; //99 chars + NULL  
       printf("Bitte  max. 99 Buchstaben eingeben: ");  
       scanf("%s", buchstabe); //wartet auf Eingabe  
       printf("%s", buchstabe); //gibt Eingabe aus  
  
       return 0;  
   }
```
## File IO
[Überblick](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)
[Mehr Codebeispiele, deutsch](https://de.wikibooks.org/wiki/C-Programmierung:_Dateien)
* Im Allgemeinen ist es egal, welche Art von Datei geöffnet wird. Unter C wird eine Datei immer als `char`-Array angesehen.
* Ein spezieller Zeiger vom Typ `FILE` geht mit Dateien um.
* Die Reihenfolge für Dateiverarbeitung ist immer folgende: Öffnen - Einlesen - *Daten verarbeiten* - *evtl. Daten schreiben* - Schließen

**Codebeispiel:**
```c=
#include <stdio.h>

int main(){  
    FILE *pFile;    //Erstellung eines FILE Pointers
    pFile = fopen("datei.txt", "r");    //Öffnen der Datei mit Lesezugriff
    if (pFile == NULL) {    //Abfangen eines Fehlers
        perror("Error opening file");
    }  
    else{  
        char character = fgetc(pFile);    //Zeichenweises Einlesen
        while (character != EOF)    //Jedes Zeichen untersuchen, bis das Ende der Datei erreicht wurde
        {  
            printf ("%c", character);    //aktuell eingelesenes Zeichen ausgeben
            character = fgetc(pFile);    //nächstes Zeichen setzen
        }  
        fclose(pFile);    //Datei schließen
    }  
    return 0;  
}
```

*Genau wie in Java ist auch das Abfangen von Fehlern wichtig (Datei existiert nicht, Datei kann nicht geöffnet werden, ...). Mehr dazu im Abschnitt *"Error handling"*.*
### Öffnen
Eine Datei kann mit verschiedenen Modi geöffnet werden.
**Übersicht aller möglichen Modi für `fopen()`:**


| Modus | Beschreibung |
| -------- | -------- |
| r *(read)* | Datei für Lesezugriff öffnen |
| w *(write)* | Datei für Schreibzugriff öffnen. Existiert bereits eine Datei mit dem selben Namen, dann wird diese überschrieben. |
| a *(append)* | Datei öffnen, um neuen Inhalt an das Ende der Datei zu schreiben. Existiert bereits eine Datei mit dem selben Namen, dann wird diese überschrieben. |
| r+ *(read/update)* | Datei mit Lese- und Schreibzugriff zur Aktualisierung öffnen. Die Datei muss existieren. |
| w+ *(write/update)* | Erstelle leere Datei und öffne mit Lese- und Schreibzugriff zur Aktualisierung. Existiert eine Datei mit dem selben Namen, wird der Inhalt gelöscht und die Datei als neue, leere Datei behandelt. |
| a+ *(append/update)* | Wie w+, aber der neue Inhalt wird an das Ende der Datei geschrieben. |

Möchte man binaries einlesen, dann muss hinter jedem Modus zusätzlich `b` angehängt werden, also z.B. `r+b` oder `rb`. 
*(Lies: Read and update binary und read binary.)*
### Schließen
Eine Datei wird mit `fclose(FILE *pFile)` geschlossen. `*pFile` ist der Pointer des File-Streams. `fclose()` gibt bei Erfolg 0 zurück und bei Fehlern die Konstante `EOF`.
### Schreiben
Schreiben kann wahlweise zeichen- oder zeilenweise erfolgen.
* Zeichenweise mit `fputc(int c, FILE *pFile)`, wobei `c` intern als `unsigned char` behandelt wird. Die Zuweisung `c = 'A'` funktioniert also.
* Zeilenweise mit `fputs(const char* str, FILE *pFile)`, wobei der Inhalt in `*str` geschrieben wird.
### Lesen
Lesen kann wahlweise zeichen- oder zeilenweise erfolgen.
* Zeichenweise mit `fgetc(FILE *pFile)`. Gibt bei Erfolg den `char` aus dem Stream zurück.
* Zeilenweise mit `fgets(char* buffer, int n, FILE *pFile)`. `char* buffer` ist ein Pointer auf den String, in den die in `*pFile` gelesene Zeile gespeichert wird (zusätzlich wird noch `\0` angehängt). `n` ist die Anzahl der Zeichen, die auf einmal gelesen werden sollen. Für `*pFile` kann auch `stdin` angegeben werden, also die Standardeingabe.
### Error handling
//TODO
[Überblick](https://www.tutorialspoint.com/cprogramming/c_error_handling.htm)
### Codebeispiele
Programm, um den Inhalt einer Datei zu lesen, auszugeben und die Datei rückwärts auszugeben:
```c=
int main(){
    char* path = "datei.txt";
    FILE *pFile;  
    pFile = fopen(path, "r");  
    
    if (pFile == NULL) {  //Mögliche Fehler abfangen
        perror("Error opening file");  
    }  
    else{  
        printf("Original:\n");
        
        int character = fgetc(pFile);    //char von der aktuellen Zeigerposition des Streams ausgeben (wird intern erhöht)
        while (character != EOF)  
        {  
            printf ("%c", character);  
            character = fgetc(pFile);  
        }  
  
    printf("\n\nReverse:\n");  
    fseek(pFile, 0, SEEK_END);    //An das Ende der Datei springen  
    long position = ftell(pFile);    //Positionsmarke für das Dateiende setzen  
      
    int i = 0;  
    while (i < position) {  
        ++i;  
        fseek(pFile, -i, SEEK_END); //An das Ende der Datei springen, aber mit -i als Versatz  
        printf("%c", fgetc(pFile)); //Ausgabe des chars an der aktuellen Zeigerposition  
    }  
  
    fclose(pFile);    //Datei schließen
    }
}
```

Inhalt von `datei.txt`:
```
Das ist eine Beispieldatei.
Hier kommt noch mehr Inhalt dazu.
Und was ist mit dieser Zeile?
```

Output:
```
Original:
Das ist eine Beispieldatei.
Hier kommt noch mehr Inhalt dazu.
Und was ist mit dieser Zeile?

Reverse:
?elieZ reseid tim tsi saw dnU
.uzad tlahnI rhem hcon tmmok reiH
.ietadleipsieB enie tsi saD
```
## Flow Control
* nahezu identisch mit Java
* es gibt:
    * if, if..else, if..else if..else (Verschachtelung möglich)
    * switch case
    * for-, while-, do while-Loops
    * jump-statements: continue, break, goto (siehe Sprünge mit `goto`)
## Sprünge mit `goto`
* Grundsätzlich: Sprünge mit `goto` sollten sehr sparsam benutzt werden (in Sonderfällen), da es nahezu immer eine bessere Art und Weise gibt, den logischen Fluss herzustellen
* **Bad practice:** `goto` in Verbindung mit globalen (`static`)on Variablen. 
* Für den Sprung muss ein Label festgelegt werden, das wie folgt im Code definiert wird:
`[Labelname]:` also zum Beispiel ``jumper:``
Mit `goto [Labelname];` wird dann zur Sprungmarke gesprungen.
**Beispiel:**

``` c=
#include <stdio.h>

int main(){

    /* Variable declaration */
    int i, j, k;

    /* Some sample loop */
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            k = 1;
            while(k<=10){
                /* Some condition */
                if(j==5 && k==5){
                    /* Move the program control outside the loop */
                    goto out_of_loop;
                }
                printf("%d ", k);
                k++;
            }
        }
    }
    /* goto label */
    out_of_loop:

    return 0;
}
```
## Makros
* komplexere Funktionen lassen sich bereits für den Präprozessor realisieren 
    * Vorteil: Die Laufzeit verändert sich und das Programm läuft in compile time statt in run time. Es braucht länger zum kompilieren, aber ist schneller in der Ausführung. 
* man kann Makros (wie jeder normalen Funktion auch) Argumente übergeben 
* da es sich um Textersetzungen handelt, sind Makros datentypunabhängig
* Beispiel 1:
```c=
#include<stdio.h>
#define HALBIEREN(wert) ((wert) / 2)

    int main(){
        int zahl = 8;
        int haelfte = HALBIEREN(zahl);
        printf("%d\n", haelfte);
        return 0;
    }
```
* Beispiel 2:
```c=
#include<stdio.h>
#define TAUSCHE(a, b, typ) { typ temp; temp=b; b=a; a=temp; }

    int main() {
	int zahla=4, zahlb=7;
	printf("zahl A: %d\\nzahl B: %d\\n", zahla, zahlb);
 	TAUSCHE(zahla, zahlb, int);
	printf("zahl A: %d\\nzahl B: %d\\n", zahla, zahlb);	
	return 0;
}
```
## Bedingte Kompilierung
* man kann bestimmte Teile des Codes von der Kompilierung ausschliessen, wenn man eine symbolische Konstante verwendet und die Keywords `#ifdef` und `#endif` zum Eingrenzen des gewünschten Bereichs nutzt
* Verzweigungen mit `#if` und `#else` sind auch möglich
* zum Debuggen manchmal sinnvoll
* Anwendungsbeispiel:
```c=
#include<stdio.h>
#define DEBUG

    int main() {
	int a=2, b=3, ergebnis;
	ergebnis = (2\*a) + (2\*b);
	#ifdef DEBUG
	printf("* Debug: ergebnis = (2*%d) + (2*%d);\\n", a, b);
	#else
	printf("Das Ergebnis ist %d\\n", ergebnis);
	#endif	
	return 0;
}

```
## Header-Dateien und deren Einbindung
* bei komplexeren Projekten ist es sinnvoll Funktionalitäten auszulagern in so genannte Header-Dateien 
* diese werden dann in die Datei mit der `main()` inkludiert mit `#include`
* Beispiel:
```c=
/* Datei beispiel.c */

#include<stdio.h>
#include "funktionen.h"

    int main() {
	printf("Produkt: %d\n", mult(4, 5));
	printf("Summe: %d\n", add(4, 5));
	return 0;
}
```
```c=
/* Datei funktionen.h */

int mult(int a, int b) {
	return a * b;
}

int add(int a, int b) {
	return a + b;
}
```
## Structs
### Aufzählungen
* für Aufzählungen kann `enum` benutzt werden, um Konstanten zu definieren

*Zählung beginnt normalerweise bei 0*
```c=
enum {herz, karo, pik, kreuz};  
printf("%d\\n", pik); //Ausgabe: 2
```
*oder einem definierten Startwert*
```c=
enum {herz=10, karo, pik, kreuz};  
printf("%d\\n", pik); //Ausgabe: 12
```
*oder man weist feste Werte zu*
```c=
enum {herz=11, karo=14, pik=12, kreuz=13};  
printf("%d\\n", pik); //Ausgabe: 12
```
### Strukturen `struct`
* Keyword`struct`, Name der Struktur und in {}Block die Definitionen der Variablen
* Beispiel:
```c=
struct adresse {
	char name[50];
	char strasse[100];
	short hausnummer;
	long plz;
	char stadt[50];
};
```
* um damit arbeiten zu können, muss ein "Objekt", eine Instanz erzeugt werden
```c=
// Variable der Struktur erstellen
struct adresse adresseKurt;

// Zugriff auf die Elemente
strcpy(adresseKurt.name, "Kurt Kanns");
strcpy(adresseKurt.strasse, "Kannichweg");
adresseKurt.hausnummer = 23;
adresseKurt.plz = 45678;
strcpy(adresseKurt.stadt, "Kannstadt");

printf("Name: %s\n", adresseKurt.name);
```
* die Erzeugung gleicher Instanzen einer Struktur ist auch möglich
```c=
struct person {
	char name[50];
	int alter;
} kurt, dieter, antonia;

kurt.alter = 33;
dieter.alter = 27;
antonia.alter = 23;
```
* zur Initialisierung wird ein weiterer Block mit den Werten angehängt
```c=
struct person {
	char name\[50\];
	int alter;
}
kurt = { "Kurt Kanns", 33 },
antonia = { "Antonia", 23 };

struct person dieter = { "Dieter Dunkel", 27 };

printf("kurt, Name: %s, Alter: %d\\n", kurt.name, kurt.alter);
printf("antonia, Name: %s, Alter: %d\\n", antonia.name, antonia.alter);
printf("dieter, Name: %s, Alter: %d\\n", dieter.name, dieter.alter);
```
* **Typdefinition** ist möglich mit `typedef`, man kann eigene Datentypen und auch Strukturen definieren (vgl. Prinzip der Objekte)
```c=
typedef struct {
	char name[50];
	int alter;
}person;

// Objekte erstellen
person kurt, dieter, antonia;
```
* man kann auch Felder und Zeiger auf structs verwenden 
*hier wird ein  Feld mit 10 Instanzen erzeugt und mit Daten zum Alter gefüllt*
```c=
typedef struct {
	char name[50];
	int alter;
}sPerson;

sPerson person[10];

int i;
for(i=0; i<10; i++) {
	person[i].alter = 20 + i;
	printf("%d ", person[i].alter);
}
```
*die Funktion **ausgabePerson()** gibt Daten der Struktur aus, die mit einem Zeiger übergeben werden*
```c=
#include<stdio.h>
#include<string.h>

typedef struct {
	char name[50];
	int alter;
}sPerson;

void ausgabePerson(sPerson *person) {
	printf("Name: %s\n", (*person).name);
	printf("Alter: %d\n", person->alter);
}

int main() {
	sPerson kurt;
	strcpy(kurt.name, "Kurt Kanns");
	kurt.alter = 33;
	ausgabePerson(&kurt);
	return 0;
}
```
### Vereinigung `union`
* bei der Vereinigung werden Variablen vereinigt, die sich den gleichen Speicherplatz teilen 
* verändert man eine Variable, hat dies Einfluss auf den gemeinschaftlich genutzten Speicherplatz und somit auf andere Variablen in der Vereinigung 
* Keyword `union` erstellt Vereinigung, Aufbau ist analog zu `struct`

*hier wird ein Union mit einer **int** und **float** Variable erstellt. Setzt man die Union auf einen Integer-Wert, erhält man nur beim Zugriff auf **numInt** eine sinnvolle Ausgabe. Greift man auf numFloat zu, erscheint keine sinnvolle Ausgabe, da numFloat vom Typ **float** und in der Union kein **float** Wert gespeichert ist.*
```c=
union number {
	int numInt;
	float numFloat;
};

union number myNumber;

myNumber.numInt = 5;
printf("numInt: %d\n", myNumber.numInt);	//Ausgabe: 5
printf("numFloat: %f\n", myNumber.numFloat);	//Ausgabe: 0.000000

myNumber.numFloat = 1.2345;
printf("numInt: %d\n", myNumber.numInt);	//Ausgabe: 1067320345
printf("numFloat: %f\n", myNumber.numFloat);	//Ausgabe: 1.234500
```
### `struct` vs. `union`
* `union` reserviert nur den Platz fuer den groesseren Typ (z.B. int und char reserviert nur Speicher fuer int)
* deshalb auch nur Nutzung von jeweils einer Variable gleichzeitig moeglich
* also: `union` benoetigt weniger Speicherplatz als `struct`, hat aber bedingt dadurch auch eingeschraenkte Funktionalitaet
*   
### Bitfelder
## Zeigerarithmetik
* Arrays bestehen aus Zeigern auf die einzelnen Positionen, deshalb auch direkte Verwendung von Zeigern sinnvoll
```c=
int reihe[10]={1,2,3,4,5,6,7,8,9,10};  //Positionszeiger  
int *pos;  //pos auf 1.Position setzen (reihe[0])  
pos=reihe;  
printf("Wert von pos bei reihe[0]: %d\n", *pos);  //pos auf nächste Position setzen  
pos++;  
printf("Wert von pos bei reihe[1]: %d\n", *pos);  //pos auf 5.Position setzen (reihe[4])  
pos = reihe +4;  
printf("Wert von pos bei reihe[4]: %d\n", *pos);  
//pos auf vorherige Position setzen  
pos--;  
printf("Wert von pos bei reihe[3]: %d\n", *pos);  
//alternative Methode, um Eintrag eines bestimmten Feldes zu bekommen  
pos=&reihe[8];  
printf("Wert von pos bei reihe[8]: %d\n", *pos);  
```
* Ermittlung der Indexnummer: Adresse Positionszeiger - Startadresse Array
```c=
int reihe[10]={1,2,3,4,5,6,7,8,9,10};  //Positionszeiger  
int *pos;  
//Ermittlung der Indexnummer: Adresse Positionszeiger - Startadresse Array  
//Setzen von pos auf 6.Adresse  
pos=&reihe[5];  
//Index berechnen  
int index=pos - reihe;  
  
printf("Index: %d\n", index);  
printf("Wert pos / reihe[index]: %d\n", reihe[index]);
```
* mehrdimensionale Zeigerarithmetik ist etwas komplexer
```c=
// Array und Spaltengrenze setzen
int brett[8][8]={ 0 }, Y_Max=8;

// Startposition
int *posStart = &brett[0][0];

// Testwert setzen
brett[2][4] = 7;

// Beschaffung Testwert mit Zeigerarithmetik
int *pos;
pos = posStart + (2 * Y_Max) + 4;

printf("%d\n", *pos ); //Ausgabe: 7
```


## Memory Allocation
* manuelle dynamische Speicherverwaltung zur Laufzeit
* notwendig ist die Einbindung der Bibliothek `stdlib.h`
* neuer Datentyp: size_t vom Typ long int, zur Angabe einer Datengrösse in Byte
* Mit **Memory Allocation** reservieren wir zur Laufzeit des Programms auf sichere Art Speicherplatz, z.B. für Felder. Mit dem Parameter **size** wird die Größe des Speicherbedarfs in Byte übergeben. Der Rückgabewert ist ein **void**-Zeiger auf den Anfang des Speicherbereichs oder ein **NULL**-Zeiger, wenn kein freier Speicher mehr zur Verfügung steht. Der **void**-Zeiger soll aussagen, dass der Datentyp des belegten Speicherbereichs unbekannt ist
`void *malloc(size_t size);`
* In diesem Beispielprogramm hat der Benutzer durch eine Tastatureingabe die Möglichkeit, die Array-Größe zu bestimmen. Mit **sizeof(int)** erhalten wir die benötigte Größe zur Speicherung eines Integer-Wertes. Die Gesamtgröße ist abhängig von der Anzahl der Elemente, also wird die Einzelgröße noch mit der gewünschten Anzahl multipliziert. Da **malloc** einen **void**-Zeiger liefert, wir in diesem Fall aber einen **int**-Zeiger haben, casten wir die Rückgabe mit **(int *)**. Das Casten ist nicht unbedingt notwendig, da der **void**-Zeiger automatisch in den richtigen Typ transformiert wird. Es ist jedoch sauberer und erleichtert die Arbeit, wenn man den Code später in C++ Projekten verwenden möchte.
```c=
#include<stdio.h>
#include<stdlib.h>

    int main() {
	int size=0;
	int *array;

	printf("Array-Groesse eingeben: ");
	scanf("%d", &size);

	// Speicher reservieren
	array = (int *) malloc(size * sizeof(int));

	if(array != NULL) {
		printf("\nSpeicher ist reserviert\n");
	}else {
		printf("\nKein freier Speicher vorhanden.\n");
	}

	return 0;
}
```
* Mit **Cleared Memory Allocation** wird ebenfalls Speicher reserviert, allerdings nicht nach Bytes, sondern nach Elementen. Der erste Parameter bestimmt die Anzahl der Elemente, der zweite die Größe eines Elementes. Im Prinzip kein großer Unterschied zu **malloc,** nur dass **calloc** alle Speicherstellen mit 0 initialisiert. **malloc** lässt den Speicherinhalt unverändert. Die Rückgabewerte sind identisch zu **malloc**
`void *calloc(size_t n, size_t size);`
* In obigem Beispiel ändert sich also nur eine Zeile: 
`array = (int *) calloc(size, sizeof(int));`
* `free`gibt mit`malloc`oder`calloc`**reservierten Speicher** wieder **frei**, obigem Beispiel wäre`free(array);`hinzuzufügen

## Fundgrube, Code snippets
### Bitweises Vertauschen zweier Zahlen

```c=
int a = 10;
int b = 20;

printf("%d %d\n", a, b);    //Output: 10 20
a ^= b;
b ^= a;
a ^= b;
printf("%d %d", a, b);    //Output: 20 10
```
*Erklärung:*
Der `^`-Operator entspricht dem XOR-Operator, d.h. es wird bei Unterschieden der Wert 1 gesetzt und bei Gleichheit der Wert 0.
Werden die Zahlen in binär dargestellt, wird die Funktionsweise des Vertauschens klar:
```
a^b:

 0000 1010    //10, a
^0001 0100    //20, b
----------
 0001 1110    //30, temporärer Wert von a
 
b^a:

 0001 0100    //20, b
^0001 1110    //30, temporärer Wert von a
----------
 0000 1010    //10, Wert von b
 
 a^b:
 
 0001 1110    //30, temporärer Wert von a
^0000 1010    //10, b
----------
 0001 0100    //20, Wert von a
```
### Bad practice: Benutzung von gets() 
[Stackoverflow.com Diskussion](https://stackoverflow.com/questions/1694036/why-is-the-gets-function-so-dangerous-that-it-should-not-be-use) 
* `gets()` liest einen oder mehrere `char` ein und speichert sie in einem String. Das Problem: Es kann eine unbegrenzte Anzahl von `char` übergeben werden, auch so viele, dass ein Buffer Overflow entsteht (`char` am Anfang des Arrays werden von neuen chars überschrieben). Nur wenn man genau weiß, welcher Text eingelesen wird, kann auch die Länge des Buffers beschränkt werden. Der erste Internetwurm ([Morris-Wurm](https://en.wikipedia.org/wiki/Morris_worm)) hat diese Schwachstelle ausgenutzt. 
* `gets()` wurde aus der Standardbibliothek in C11 heraus genommen, aber zwecks Kompabilität wird es noch von vielen Compilern unterstützt. GCC wird eine Fehlermeldung bei der Benutzung ausgeben, aber die Benutzung nicht verhindern.
* Eine sichere Alternative ist `fgets()`, welche zusätzlich noch die Länge des Buffers entgegen nimmt. 
## Linksammlung

* [Online C Compiler](https://www.onlinegdb.com/online_c_compiler)
* [printf-Reference](http://www.cplusplus.com/reference/cstdio/printf/)
* inspired by:
	* http://www.c-howto.de/tutorial/
	* https://codeforwin.org/2017/08/introduction-c-programming.html
	* http://www.c-programmieren.com/C-Lernen.html

