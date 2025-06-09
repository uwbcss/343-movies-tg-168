#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include "PairHash.h"

#include <unordered_map>

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
public:
  DramaFactory();

  Movie *makeMovie(const string &detail) override;

  vector<Movie *> getMovies() override;

  pair<string, string> toKey(string detail) override;
};

#endif