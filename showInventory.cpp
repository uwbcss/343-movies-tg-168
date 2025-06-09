#include "showInventory.h"
#include <iostream>

vector<string> &ShowInventory::execute() const
{
  cout << "showInventory command executed" << endl;

  vector<string> inventory;
  return inventory;
}

ShowInventoryFactory::ShowInventoryFactory() { registerType("I", this); }

Command *ShowInventoryFactory::makeCommand(const string &detail) const
{
  return new ShowInventory();
}

ShowInventoryFactory anonymous_ShowInventoryFactory;