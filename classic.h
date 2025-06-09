#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

#include <unordered_map>

namespace std
{
template <> struct hash<pair<string, string>>
{
  // hash for pair<string, int>
  size_t operator()(const pair<string, string> &p) const
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
} // namespace std

class Classic : public Movie
{
  friend class ClassicFactory;

private:
  int year;
  int month;

  string date;
  string actor;

public:
  Classic(int stock, string director, string title, string actorAndDate);

  string getInfo() override;

  string getFirst() override;

  string getSecond() override;
};

class ClassicFactory : MovieFactory
{
private:
  unordered_map<pair<string, string>, Classic *> classics;

public:
  ClassicFactory();

  Movie *makeMovie(const string &detail) override;

  vector<Movie *> getMovies() override;
};

#endif