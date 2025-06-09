#ifndef COMEDY_H
#define COMEDY_H

#include "PairHash.h"
#include "movie.h"

#include <unordered_map>

class Comedy : public Movie {
  friend class ComedyFactory;

private:
  int year;

public:
  // constructor
  Comedy(int stock, string director, string title, int year);

  // getter
  string getInfo() override;

  // getter
  string getFirst() override;

  // getter
  string getSecond() override;
};

class ComedyFactory : MovieFactory {
public:
  // constructor
  ComedyFactory();

  // make a Comedy movie
  Movie *makeMovie(const string &detail) override;

  // get movies of this type
  vector<Movie *> getMovies() override;

  // turn command into key
  pair<string, string> toKey(string detail) override;
};

#endif