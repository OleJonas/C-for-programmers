#include <iostream>

using namespace std;

void find_sum(const int *table, int length){
    //10 first numbers
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    for(int i = 0; i < length; i++){
        if(i < 10) sum1 += *table;
        else if(i > 14) sum3 += *table;
        else sum2 += *table;
        table++;
    }
    cout << "Sum av 10 foerste: " << sum1 << endl;
    cout << "Sum av 5 neste: " << sum2 << endl;
    cout << "Sum av 5 siste: " << sum3 << endl;    
}

int main(){
    int table[20];
    const int *tabptr = table;

    for(int i = 0; i < 20; i++){
        table[i] = i+1;
    }

    find_sum(tabptr, 20);

    return 0;
}