#ifndef MOVIE_H
#define MOVIE_H

#include "PairHash.h"

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Movie;

class MovieFactory
{
  friend class System;

public:
  // make a movie, implemented by subclasses
  virtual Movie *makeMovie(const string &detail) = 0;

  virtual vector<Movie *> getMovies() = 0;

  // find the corresponding movie factory and get factory to create the object
  static Movie *create(const string &type, const string &detail);

  static const unordered_map<string, MovieFactory *> &getMapC();

  string getType();

  unordered_map<pair<string, string>, Movie *, PairStringHash> movies;

  virtual pair<string, string> toKey(string detail) = 0;

protected:
  // register a concrete factory with a given name
  static void registerType(const string &type, MovieFactory *factory);

  string type;

private:
  // Storage place for the concrete movie factories
  static unordered_map<string, MovieFactory *> &getMap();
};

class Movie
{
public:
  // constructor
  Movie(string typeFull, int stock, string director, string title);

  virtual string getInfo() = 0;

  // Abstract classes should always have virtual destructors
  virtual ~Movie() = default;

  void reduceStock();

  virtual string getFirst() = 0;

  virtual string getSecond() = 0;

  int stock;
  string title;

protected:
  string typeFull;
  string director;
};

#endif