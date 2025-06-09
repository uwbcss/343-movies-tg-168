#include "movie.h"
#include <iostream>
#include <unordered_map>

string Movie::getDirector() { return director; }

string Movie::getTitle() { return title; }

// Storage place for the concrete movie factories
unordered_map<string, MovieFactory *> &MovieFactory::getMap()
{
  static unordered_map<string, MovieFactory *> factories;
  return factories;
}

const unordered_map<string, MovieFactory *> &MovieFactory::getMapC()
{
  return getMap();
}

// return movie type
string MovieFactory::getType() { return type; }

// register a concrete factory with a given name
void MovieFactory::registerType(const string &type, MovieFactory *factory)
{
  getMap().emplace(type, factory);
}

// find the corresponding movie factory and get factory to create the object
Movie *MovieFactory::create(const string &type, const string &detail)
{
  if (!getMap().count(type))
  {
    cout << "Unknown movie type: " << type << ", discarding line: " << detail
         << endl;
    return nullptr;
  }

  return getMap().at(type)->makeMovie(detail);
}

// constructor
Movie::Movie(string typeFull, int stock, string director, string title)
    : typeFull(typeFull), stock(stock), director(director), title(title)
{
}