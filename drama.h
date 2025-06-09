#ifndef DRAMA_H
#define DRAMA_H

#include "PairHash.h"
#include "movie.h"

#include <unordered_map>

class Drama : public Movie {
  friend class DramaFactory;

private:
  int year;

public:
  // constructor
  Drama(int stock, string director, string title, int year);

  // getter
  string getInfo() override;

  // getter
  string getFirst() override;

  // getter
  string getSecond() override;
};

class DramaFactory : MovieFactory {
public:
  // constructor
  DramaFactory();

  // make a Drama movie
  Movie *makeMovie(const string &detail) override;

  // get movies of this type
  vector<Movie *> getMovies() override;

  // turn command into key
  pair<string, string> toKey(string detail) override;
};

#endif