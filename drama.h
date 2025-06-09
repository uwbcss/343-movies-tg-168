#ifndef DRAMA_H
#define DRAMA_H

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

class Drama : public Movie
{
  friend class DramaFactory;

private:
  int year;

public:
  Drama(int stock, string director, string title, int year);

  string getInfo() override;

  string getFirst() override;

  string getSecond() override;
};

class DramaFactory : MovieFactory
{
private:
  unordered_map<pair<string, string>, Drama *> dramas;

public:
  DramaFactory();

  Movie *makeMovie(const string &detail) override;

  vector<Movie *> getMovies() override;
};

#endif