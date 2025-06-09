#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

#include <unordered_map>

namespace std
{
template <> struct hash<pair<string, int>>
{
  // hash for pair<string, int>
  size_t operator()(const pair<string, int> &p) const
  {
    size_t h = 0;
    for (char c : p.first)
    {
      h = (h << 5) + h + c;
    }

    h += p.second;

    return h;
  }
};
} // namespace std

class Comedy : public Movie
{
  friend class ComedyFactory;
  friend struct ByTitleAndYear;

private:
  int year;

public:
  Comedy(int stock, string director, string title, int year);

  string getInfo() override;

  int getYear() override;
};

class ComedyFactory : MovieFactory
{
private:
  unordered_map<pair<string, int>, Comedy *> comedies;

public:
  ComedyFactory();

  Movie *makeMovie(const string &detail) override;

  vector<Movie *> getMovies() override;
};

struct ByTitleAndYear
{
  bool operator()(Comedy const *a, Comedy const *b) const
  {
    if (a->title != b->title)
    {
      return a->title < b->title;
    }

    return a->year < b->year;
  }
};

#endif