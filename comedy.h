#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie
{
private:
  int stock;
  string director;
  string title;
  int year;
};

class ComedyFactory : MovieFactory
{
public:
  ComedyFactory();
  Movie *makeMovie() const override;
};

#endif