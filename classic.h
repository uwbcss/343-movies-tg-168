#ifndef CLASSIC_H
#define CLASSIC_H

#include "PairHash.h"
#include "movie.h"

#include <unordered_map>

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
public:
  ClassicFactory();

  Movie *makeMovie(const string &detail) override;

  vector<Movie *> getMovies() override;

  pair<string, string> toKey(string detail) override;
};

#endif