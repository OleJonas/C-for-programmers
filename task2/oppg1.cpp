#include <iostream>

using namespace std;

void print(int i, int j, int *p, int *q){
    cout << "i verdi: " << i << ", adresse: " << &i << endl;
    cout << "j verdi: " << j << ", adresse: " << &j << endl;
    cout << "p verdi: " << p << ", adresse: " << &p << endl;
    cout << "q verdi: " << q << ", adresse: " << &q << endl;
}

int main(){
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    print(i, j, p, q);
    // Her skal p og q sine verdier være adressene til i og j.
    /*cout << "i verdi: " << i << ", adresse: " << &i << endl;
    cout << "j verdi: " << j << ", adresse: " << &j << endl;
    cout << "p verdi: " << p << ", adresse: " << &p << endl;
    cout << "q verdi: " << q << ", adresse: " << &q << endl;*/

    // Etter foelgende programbit utfoeres skal i vaere 7,
    // j = 9 saa 8. Til slutt skal p peke til samme variabel som q,
    // altsaa peker p til i.
    *p = 7;
    *q += 4;
    print(i, j, p, q);

    *q = *p + 1;
    print(i, j, p, q);

    p = q;
    print(i, j, p, q);
    cout << *p << " " << *q << endl;

    return 0;
}