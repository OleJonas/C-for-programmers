#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    vector<double> double_vec;
    for(int i = 0; i < 5; i++) double_vec.emplace_back((double)i);

    cout << "Front: " << double_vec.front() << "\nBack: " << double_vec.back() << endl;

    auto it = double_vec.begin()+1;
    double_vec.emplace(it, 20.3);
    cout << "Element nr. 2: " << double_vec[1] << endl;
    cout << "Element front: " << double_vec.front() << endl;

    auto double_vec_end = double_vec.end();
    auto help = find(double_vec.begin(), double_vec_end, 20.3);
    if(help != double_vec_end) cout << "Found at index: " << *help << endl;
}