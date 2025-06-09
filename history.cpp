#include "history.h"
#include "movie.h"
#include "system.h"

#include <algorithm>
#include <iostream>

// constructor
History::History(string detail) : detail(detail) {}

// execute the command
void History::execute() const {
  if (detail.empty()) {
    cout << "Invalid command" << endl;

    return;
  }

  int id = stoi(detail.substr(1));

  cout << "History for " << id << " " << System::customers[id]->firstName << " "
       << System::customers[id]->lastName << ":" << endl;

  if (System::customers[id]->history.empty()) {
    cout << "No history" << endl;

    return;
  }

  for (auto &&i : System::customers[id]->history) {
    cout << i << endl;
  }
}

// register this factory
HistoryFactory::HistoryFactory() { registerType("H", this); }

// make a History command
Command *HistoryFactory::makeCommand(const string &detail) const {
  return new History(detail);
}

HistoryFactory anonymousHistoryFactory;