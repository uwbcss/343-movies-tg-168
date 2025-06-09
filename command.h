#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Command;

class CommandFactory
{
public:
  // make a command, implemented by subclasses
  virtual Command *makeCommand(const string &detail) const = 0;

  // find the corresponding command factory and get factory to create the object
  static Command *create(const string &type, const string &detail);

protected:
  // register a concrete factory with a given name
  static void registerType(const string &type, CommandFactory *factory);

private:
  // Storage place for the concrete command factories
  static unordered_map<string, CommandFactory *> &getMap();
};

class Command
{
public:
  // different commands have different uses, implemented by subclasses
  virtual vector<string> &execute() const = 0;

  // Abstract classes should always have virtual destructors
  virtual ~Command() = default;
};

#endif COMMAND_H