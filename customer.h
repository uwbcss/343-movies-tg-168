#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "PairHash.h"

#include <string>
#include <unordered_map>

using namespace std;

// namespace std
// {
// template <> struct hash<pair<string, string>>
// {
//   // hash for pair<string, string>
//   size_t operator()(const pair<string, string> &p) const
//   {
//     size_t h = 0;
//     for (char c : p.first)
//     {
//       h = (h << 5) + h + c;
//     }

//     h += p.second.size();

//     return h;
//   }
// };
// } // namespace std

class Customer
{
private:
  string firstName;
  string lastName;

public:
  Customer(string firstName, string lastName);

  unordered_map<pair<string, string>, int, PairStringHash> mm;
};

#endif