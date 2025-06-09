#ifndef CLASSIC_H
#define CLASSIC_H

#include "PairHash.h"
#include "movie.h"

#include <unordered_map>

class Classic : public Movie {
  friend class ClassicFactory;

private:
  int year;
  int month;

  string date;
  string actor;

public:
  // constructor
  Classic(int stock, string director, string title, string actorAndDate);

  // getter
  string getInfo() override;

  // getter
  string getFirst() override;

  // getter
  string getSecond() override;
};

class ClassicFactory : MovieFactory {
public:
  // constructor
  ClassicFactory();

  // make a Classic movie
  Movie *makeMovie(const string &detail) override;

  // get movies of this type
  vector<Movie *> getMovies() override;

  // turn command into key
  pair<string, string> toKey(string detail) override;
};

#endif