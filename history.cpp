#include "history.h"
#include "movie.h"
#include "system.h"

#include <algorithm>
#include <iostream>

History::History(string detail) : detail(detail) {}

// execute the command
void History::execute() const
{
  if (detail.size() == 0)
  {
    cout << "Invalid command" << endl;

    return;
  }

  int id = stoi(detail.substr(1));

  cout << "History for " << id << " " << System::customers[id]->firstName << " "
       << System::customers[id]->lastName << ":" << endl;

  if (System::customers[id]->history.size() == 0)
  {
    cout << "No history" << endl;

    return;
  }

  for (auto &&i : System::customers[id]->history)
  {
    cout << i << endl;
  }
}

HistoryFactory::HistoryFactory() { registerType("H", this); }

Command *HistoryFactory::makeCommand(const string &detail) const
{
  return new History(detail);
}

HistoryFactory anonymous_HistoryFactory;