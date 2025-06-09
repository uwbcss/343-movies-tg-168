#include "returnCommand.h"
#include "movie.h"
#include "system.h"

#include <algorithm>
#include <iostream>

// constructor
ReturnCommand::ReturnCommand(string detail) : detail(detail) {}

// execute the command
void ReturnCommand::execute() const {
  string mediaType = detail.substr(6, 1);
  if (mediaType != "D") {
    cout << "Invalid media type " << mediaType
         << ", discarding line: " << detail.substr(7) << endl;

    return;
  }

  string movieType = detail.substr(8, 1);
  if (MovieFactory::getMapC().count(movieType) == 0) {
    cout << "Invalid movie type " << movieType
         << ", discarding line: " << detail.substr(7) << endl;

    return;
  }

  int id = stoi(detail.substr(1, 4));
  if (System::customers.count(id) == 0) {
    cout << "Invalid customer ID " << id
         << ", discarding line: " << detail.substr(7) << endl;

    return;
  }

  pair<string, string> key =
      MovieFactory::getMapC().at(movieType)->toKey(detail.substr(10));

  if (MovieFactory::getMapC().at(movieType)->movies.count(key) == 0) {
    cout << "Invalid movie, discarding line: " << detail.substr(7) << endl;

    return;
  }

  if (System::customers[id]->mm[key] == 0) {
    cout << "no such movie to return, discarding line: " << detail.substr(7)
         << endl;

    return;
  }

  MovieFactory::getMapC().at(movieType)->movies.at(key)->stock++;
  System::customers[id]->mm[key]--;
  System::customers[id]->history.push_back(
      "Return " + MovieFactory::getMapC().at(movieType)->movies.at(key)->title);
}

// constructor
ReturnCommandFactory::ReturnCommandFactory() { registerType("R", this); }

// make a Return command
Command *ReturnCommandFactory::makeCommand(const string &detail) const {
  return new ReturnCommand(detail);
}

ReturnCommandFactory anonymousReturnCommandFactory;