#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "PairHash.h"

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Customer {
public:
// constructor
  Customer(string firstName, string lastName);

  string firstName;
  string lastName;

  unordered_map<pair<string, string>, int, PairStringHash> mm;

  vector<string> history;
};

#endif