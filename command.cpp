#include "command.h"
#include <iostream>
#include <unordered_map>

// Storage place for the concrete command factories
unordered_map<string, CommandFactory *> &CommandFactory::getMap() {
  static unordered_map<string, CommandFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void CommandFactory::registerType(const string &type, CommandFactory *factory) {
  getMap().emplace(type, factory);
}

// find the corresponding command factory and get factory to create the object
Command *CommandFactory::create(const string &type, const string &detail) {
  if (getMap().count(type) == 0U) {
    cout << "Unknown command type: " << type << ", discarding line: " << detail
         << endl;
    return nullptr;
  }

  return getMap().at(type)->makeCommand(detail);
}