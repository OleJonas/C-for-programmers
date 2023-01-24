#include <iostream>

using namespace std;

template <typename Type> bool equal(Type a, Type b){
    return a == b;
}

bool equal(double a, double b, double tolerance){
    double diff = abs(a-b);
    return diff <= tolerance;
}

int main(){
    cout << "Tester template med 'Hei' == 'Hei'" << endl;
    cout << equal("Hei", "Hei") << endl;
    cout << "Tester template med 'Hei' == 'Hie'" << endl;
    cout << equal("Hei", "Hie") << endl;
    cout << "Tester double equal med toleranse for 4.0 og 4.01\nToleranse=0.01" << endl;
    cout << equal(4.0,4.01,0.01) << endl;
    cout << "Øker differansen søik at vi skal få false:\nToleranse=0.02" << endl;
    cout << equal(4.0,4.02,0.01) << endl;

    return 0;
}