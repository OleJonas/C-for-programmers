#include "Set.hpp"
#include <vector>
#include <iostream>

using namespace std;

Set::Set() : ints({}) {}
Set::Set(vector<int> integers) : ints(integers) {}

int Set::size() const{
    return ints.size();
}

int Set::get(int i) const{
    return ints[i];
}

void Set::operator+(int i){
    bool found = false;
    for(int j : ints){
        if(i == j) found = true;
    }
    if(!found) ints.push_back(i);
}

Set Set::operator+=(const Set &set){
    Set s = *this;
    bool found = false;
    for(int i = 0; i < set.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(set.ints[i] == s.ints[j]) found = true;
        }
        if(!found) ints.push_back(set.ints[i]);
        else found = false;
    }
    return s;
}

Set Set::operator=(const Set &set){
    ints = set.ints;
    return *this;
}