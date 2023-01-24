#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table){
    for(auto &e : table){
        out << e << " ";
    }
    return out;
}

void check_equal_with_tolerance(vector<int>::iterator begin, vector<int>::iterator end, int ints [], int tolerance){
    if(equal(begin, end, ints, [tolerance](int i, int j){
        int small_big [2] = {i,j};
        if(i > j){
            small_big[0] = j; small_big[1] = i;
        }
        cout << small_big[1]%small_big[0] << endl;
        return (small_big[1]%small_big[0] <= tolerance)? true : false;
    })){
        cout << "Like på intervallet" << endl;
    } else{
        cout << "Ikke like på intervallet" << endl;
    }
}

int main(){

    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    // a)
    auto res = find_if(v1.begin(), v1.end(), [](int a){
        return a > 15;
    });

    cout << "Resultat av find_if med i > 15 som predikat: " << *res << endl;


    // b)
    check_equal_with_tolerance(v1.begin(), v1.begin()+5, &v2[0], 2);
    check_equal_with_tolerance(v1.begin(), v1.begin()+4, &v2[0], 2);


    // c)
    cout << "v1 før erstatning: " << v1 << endl;
    replace_copy_if(v1.begin(), v1.end()+1, v1.begin(), [](int a){
        return (a%2) == 1;
    }, 100);
    cout << "Etter erstatning: " << v1 << endl;

    return 0;
}