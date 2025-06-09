#ifndef SYSTEM_H
#define SYSTEM_H

#include "command.h"
#include "movie.h"

class System
{
private:
  vector<Command *> commands;

public:
  // add a new command to the list
  void addCommand(const string &type, const string &detail);

  // read commands from a txt file
  void readFromFile(const string &filename);

  // execute all commands
  void executeAll();
};

#endif