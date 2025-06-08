#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <unordered_map>

using namespace std;

class Movie;

class MovieFactory
{
public:
  // make a movie, implemented by subclasses
  virtual Movie *makeMovie() const = 0;

  // find the corresponding movie factory and get factory to create the object
  static Movie *create(const string &type);

protected:
  // register a concrete factory with a given name
  static void registerType(const string &type, MovieFactory *factory);

private:
  // Storage place for the concrete movie factories
  static unordered_map<string, MovieFactory *> &getMap();
};

class Movie
{
public:
  // Abstract classes should always have virtual destructors
  virtual ~Movie() = default;

protected:
  int stock;
  string director;
  string title;
};

#endif MOVIE_H