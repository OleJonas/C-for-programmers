#include <iostream>

using namespace std;

int main(){
    double number = 3;
    double *ptr = &number;
    double &ref = number;

    number = 4;
    cout << number << endl;
    *ptr = 7;
    cout << number << endl;
    ref = 12;
    cout << number << endl;

    return 0;
}