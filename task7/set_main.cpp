#include <iostream>
#include "Set.hpp"

using namespace std;

ostream &operator<<(ostream &out, const Set &set) {
  for(int i : set.ints) out << i << " ";
  return out;
}

int main(){
    Set s1;
    Set s2({1,2,3,7,4});
    s1 + 2;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    s1 += s2;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    s2 = s1;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
}