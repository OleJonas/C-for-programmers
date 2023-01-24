#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length){
    const char filename[] = "temp.dat";
    ifstream file;
    file.open(filename);

    if(!file){
        cout << "Feil ved aapning av innfil." << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < length; i++){
        file >> temperatures[i];
    }

    file.close();
}

int main(){
    const int length = 11;
    double temperatures[length];

    int under = 0;
    int in = 0;
    int over = 0;

    read_temperatures(temperatures, length);

    for(int j = 0; j < length; j++){
        double temp = temperatures[j];
        cout << temp << endl;
        if(temp < 10) under++;
        else if(temp > 20) over++;
        else in++;

    }
    
    cout << "Antall under 10 er " << under << endl;
    cout << "Antall mellom 10 og 20 er " << in << endl;
    cout << "Antall over 20 er " << over << endl;
    
    return 0;
}