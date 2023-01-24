#include <iostream>

using namespace std;

int main(){
    const int interval = 5;
    double temp;
    int under = 0;
    int in = 0;
    int over = 0;

    cout << "Du skal skrive inn " << interval << " temperaturer:" << endl;

    for(int i = 1; i <= interval; i++){
        cout << "Temperatur nr " << i << ":";
        cin >> temp;
        if(temp < 10) under++;
        else if(temp > 20) over++;
        else in++;
    }
    
    cout << "Antall under 10 er " << under << endl;
    cout << "Antall mellom 10 og 20 er " << in << endl;
    cout << "Antall over 20 er " << over << endl;
    
    return 0;
}