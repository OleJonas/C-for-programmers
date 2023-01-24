#include <vector>

#pragma once

class Set {
public:
  std::vector<int> ints;

  Set();
  Set(std::vector<int> collection);
  void operator+(int i);
  Set operator+=(const Set &set);
  Set operator=(const Set &set);
  void append(int integer);
  int size() const;
  int get(int i) const;

};
// a