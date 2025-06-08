#include "movie.h"
#include <iostream>
#include <unordered_map>

// Storage place for the concrete movie factories
unordered_map<string, MovieFactory *> &MovieFactory::getMap()
{
  static unordered_map<string, MovieFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void MovieFactory::registerType(const string &type, MovieFactory *factory)
{
  getMap().emplace(type, factory);
}

// find the corresponding movie factory and get factory to create the object
Movie *MovieFactory::create(const string &type)
{
  if (!getMap().count(type))
  {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }

  return getMap().at(type)->makeMovie();  
}