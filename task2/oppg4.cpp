using namespace std;

int main(){

    /*
    int &b;

    Denne vil ikke fungere fordi maaten dette er skrevet paa
    antyder at det er en referanse til noe allerede eksisterende.
    Om det skal vaere tilfellet, maa man initialisere den med hva den skal referere til.
    Dette kan f.eks. gjoeres ved aa endre koden til int &b = a; slik at baade a og b referer til samme variabel.
    */


    /*
    *a = *b + *c;

    Her er det to like feil. Hverken a eller b er initialiserte som pointers. Dereferanseoperatoren har derfor ingen mening paa disse to variablene
    fordi deres verdi ikke er et sted i minnet, men heller en int. For c fungerer *c fint, nettopp fordi denne er initialisert som en pointer som peker til b
    sin minneadresse.
    For aa fikse denne biten kan man skrive slik:
    a = b + *c;
    Som egentlig bare kunne blitt skrevet som a += a; fordi a = b = *c i dette tilfellet.
    */


    /*
    &b = 2;

    Dette fungerer ikke fordi &-tegnet brukes paa venstresiden av likhetstegnet for aa initialisere referanser. Naar man ikke lenger initialiserer referansene,
    bruker man bare det nye navnet man har initialisert den med. 
    En fiks ville vaert: b = 2; slik at man ogsaa endret a til 2 fordi baade a og b refererer til samme variabel.
    */

    int a = 5;
    int &b = a;
    int *c;
    c = &b;
    a = b + *c;
    b = 2;

    return 0;
}