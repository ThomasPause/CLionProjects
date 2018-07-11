#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int i, x, merk = 0;
    char c;

    while (1) {
    start:
        printf("\n\nPrimzahl\n\n");
        printf("Bitte Zahl eingeben: ");
        scanf("%i", &x);

        // Alle Werte von 2 bis (zahl-1) durchgehen
        // oder bis Abbruchbedingung erreicht ist
        for (i = 2; i < x && !merk; i++) {

            // Test ob sich die Zahl ohne Rest teilen lässt
            if (x % i == 0) {
                // Zahl lässt sich ohne Rest teilen
                // -> also ist die Zahl keine Primzahl
                // Schleife kann sofort verlassen werden
                merk = 1;
            }
        }

        if (merk) {
            // Schleife wurde verlassen
            // es wurde ein Teiler gefunden
            printf("%i ist keine Primzahl", x);
        } else {
            // Schleife wurde komplett durchlaufen
            // es wurde kein Teiler gefunden
            printf("%i ist eine Primzahl", x);
        }
        //printf("\n%s", "Moechten Sie eine weitere Zahl testen? y/n")
        //scanf("%c")
        goto start;
    }
}
