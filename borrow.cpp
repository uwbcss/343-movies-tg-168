#include "borrow.h"
#include "movie.h"
#include "system.h"

#include <algorithm>
#include <iostream>

Borrow::Borrow(string detail) : detail(detail) {}

// execute the command
void Borrow::execute() const
{
  string mediaType = detail.substr(6, 1);
  if (mediaType != "D")
  {
    cout << "Invalid media type " << mediaType
         << ", discarding line: " << detail.substr(7) << endl;

    return;
  }

  string movieType = detail.substr(8, 1);
  if (MovieFactory::getMapC().count(movieType) == 0)
  {
    cout << "Invalid movie type " << movieType
         << ", discarding line: " << detail.substr(7) << endl;

    return;
  }

  int id = stoi(detail.substr(1, 4));
  if (System::customers.count(id) == 0)
  {
    cout << "Invalid customer ID " << id
         << ", discarding line: " << detail.substr(7) << endl;

    return;
  }

  pair<string, string> key =
      MovieFactory::getMapC().at(movieType)->toKey(detail.substr(10));
  cout << key.first << endl;
  cout << key.second << endl;

  if (MovieFactory::getMapC().at(movieType)->movies.count(key) == 0)
  {
    cout << "Invalid movie, discarding line: " << detail.substr(7) << endl;

    return;
  }

  if (MovieFactory::getMapC().at(movieType)->movies.at(key)->stock == 0)
  {
    cout << "no stock left, discarding line: " << detail.substr(7) << endl;

    return;
  }

  MovieFactory::getMapC().at(movieType)->movies.at(key)->reduceStock();
  System::customers[id]->mm[key]++;
}

BorrowFactory::BorrowFactory() { registerType("B", this); }

Command *BorrowFactory::makeCommand(const string &detail) const
{
  return new Borrow(detail);
}

BorrowFactory anonymous_BorrowFactory;