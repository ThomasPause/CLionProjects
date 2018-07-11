/*#include <stdio.h>
#include <string.h>
//swap muss IMMER ueber call-by-reference laufen
void swap (int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;   //exklusiv Oder direkt ueber Pointer
}
void swap2 (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;  //geht so in Java nicht!
}
int main() {*/
    /*printf("Hello, World!\n");
    int zahl=1000;
    printf("\n%d", zahl);
    void *test=&zahl; //void-Pointer
    printf("\n%d", *((int*) test));

    int a = 15;
    int b = 38;

    printf("Vorher: %d %d\n", a, b);
    swap2(&a,&b);
    printf("Nachher: %d %d\n", a, b);

    printf("Vorher: %d %d\n", a, b);
    swap(&a,&b);
    printf("Nachher: %d %d\n", a, b);*/

    /*int array[]={1,2};
    int s= sizeof(array[0]);    //eine beliebigen Speicherstelle (hier 1.)
    int n = sizeof(array)/ s;   //Formel zur Groessenberechnung!!
    printf("\n%d", s);  //groesse einer int-Speicherstelle (4 bei 64bit)
    printf("\n%d", n);  //groesse von array*/

    /*char lhs[]= "John Smith";
    char rhs[]= "John Doe";
    printf("%d", strcmp(lhs, rhs));*/ //int Wert des Vergleichs
    // =0 - gleich
    // <0 - 1.unterschiedlicher char ist diesen Wert kleiner in lhs
    // >0 - 1.unterschiedlicher char ist diesen Wert groesser in lhs

    //printf("\n%d", strncmp(lhs, rhs, 5));
    //letzter Wert gibt Anzahl zu vergl.chars an, Ergebnis: 0

/**
 * Basic I/O Programm zum Einlesen eines Strings
 */
#include <stdio.h>
#include <string.h>

int main()
    {
        /*char buchstabe[100];    //99 chars + NULL
        printf("Bitte  max. 99 Buchstaben eingeben: ");
        scanf("%s", buchstabe);  //wartet auf Eingabe
        printf("%s", buchstabe); //gibt Eingabe aus
        if (strlen(buchstabe)>= 5){
            printf("\n%s", "Yeah");
        }*/
        //enums werden fuer Aufzaehlungen genutzt, Zaehlung beginnt normalerweise bei 0,
        // man kann aber auch einen Startwert setzen oder explizite Werte definieren
        enum {herz, karo, pik, kreuz};
        printf("%d\n", pik);    //Ausgabe: 2


        //Zeigerarithmetik: Arrays bestehen aus Zeigern auf die einzelnen Positionen, deshalb auch
        //direkte Verwendung von Zeigern sinnvoll
        /*int reihe[10]={1,2,3,4,5,6,7,8,9,10};
        //Positionszeiger
        int *pos;
        //pos auf 1.Position setzen (reihe[0])
        pos=reihe;
        printf("Wert von pos bei reihe[0]: %d\n", *pos);
        //pos auf naechste Position setzen
        pos++;
        printf("Wert von pos bei reihe[1]: %d\n", *pos);
        //pos auf 5.Position setzen (reihe[4])
        pos = reihe +4;
        printf("Wert von pos bei reihe[4]: %d\n", *pos);
        //pos auf vorherige Position setzen
        pos--;
        printf("Wert von pos bei reihe[3]: %d\n", *pos);
        //alternative Methode, um Eintrag eines bestimmten Feldes zu bekommen
        pos=&reihe[8];
        printf("Wert von pos bei reihe[8]: %d\n", *pos);

        //Ermittlung der Indexnummer: Adresse Positionszeiger - Startadresse Array
        //Setzen von pos auf 6.Adresse
        pos=&reihe[5];
        //Index berechnen
        int index=pos - reihe;

        printf("Index: %d\n", index);
        printf("Wert pos / reihe[index]: %d\n", reihe[index]);
*/
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
        return 0;
    }

