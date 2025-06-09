#ifndef PAIR_HASH_H
#define PAIR_HASH_H

#include <string>
#include <utility>

using namespace std;

struct PairStringHash
{
  size_t operator()(pair<string, string> const &p) const noexcept
  {
    size_t h = 0;
    for (char c : p.first)
    {
      h = (h << 5) + h + c;
    }

    h += p.second.size();

    return h;
  }
};

#endif
