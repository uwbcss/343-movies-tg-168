#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include "PairHash.h"

#include <unordered_map>

class Comedy : public Movie
{
  friend class ComedyFactory;

private:
  int year;

public:
  Comedy(int stock, string director, string title, int year);

  string getInfo() override;

  string getFirst() override;

  string getSecond() override;
};

class ComedyFactory : MovieFactory
{
public:
  ComedyFactory();

  Movie *makeMovie(const string &detail) override;

  vector<Movie *> getMovies() override;

  pair<string, string> toKey(string detail) override;
};

#endif