#ifndef HISTORY_H
#define HISTORY_H_H

#include "command.h"
#include <string>
#include <vector>

using namespace std;

class History : public Command
{
private:
  string detail;

public:
  History(string detail);

  // display history
  void execute() const override;
};

class HistoryFactory : public CommandFactory
{
public:
  // register this factory
  HistoryFactory();

  // make a History command
  Command *makeCommand(const string &detail) const override;
};

#endif