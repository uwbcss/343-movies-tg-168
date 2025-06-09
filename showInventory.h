#ifndef SHOW_INVENTORY_H
#define SHOW_INVENTORY_H

#include "command.h"
#include <string>
#include <vector>

using namespace std;

class ShowInventory : public Command {
public:
  // show the inventory of movies
  void execute() const override;
};

class ShowInventoryFactory : public CommandFactory {
public:
  // register this factory
  ShowInventoryFactory();

  // make a ShowInventory command
  Command *makeCommand(const string &detail) const override;
};

#endif