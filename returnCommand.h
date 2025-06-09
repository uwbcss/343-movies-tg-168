#ifndef RETURN_COMMAND_H
#define RETURN_COMMAND_H

#include "command.h"
#include <string>
#include <vector>

using namespace std;

class ReturnCommand : public Command
{
private:
  string detail;

public:
  ReturnCommand(string detail);

  // return a movie
  void execute() const override;
};

class ReturnCommandFactory : public CommandFactory
{
public:
  // register this factory
  ReturnCommandFactory();

  // make a ReturnCommand command
  Command *makeCommand(const string &detail) const override;
};

#endif