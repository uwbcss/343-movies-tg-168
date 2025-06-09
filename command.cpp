#include "command.h"
#include <iostream>
#include <unordered_map>

// Storage place for the concrete command factories
unordered_map<string, CommandFactory *> &CommandFactory::getMap()
{
  static unordered_map<string, CommandFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void CommandFactory::registerType(const string &type, CommandFactory *factory)
{
  getMap().emplace(type, factory);
}

// find the corresponding command factory and get factory to create the object
Command *CommandFactory::create(const string &type, const string &detail)
{
  if (!getMap().count(type))
  {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }

  return getMap().at(type)->makeCommand(detail);  
}