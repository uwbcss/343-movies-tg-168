#include "system.h"

#include <cassert>
#include <fstream>
#include <iostream>

// add a new command to the list
void System::addCommand(const string &type, const string &detail)
{
  Command *command = CommandFactory::create(type, detail);
  if (command)
  {
    commands.push_back(command);
  }
}

// read commands from a txt file
void System::readFromFile(const string &filename)
{
  ifstream fs(filename);
  assert(fs.is_open());
  string type;
  string detail;
  while (fs >> type)
  {
    getline(fs, detail);

    Command *command = CommandFactory::create(type, detail);
    if (command)
    {
      commands.push_back(command);
    }
    cout << detail << endl;
  }
  fs.close();
}

// execute all commands
void System::executeAll()
{
  for (const auto &command : commands)
  {
    command->execute();
    delete command;
  }
}