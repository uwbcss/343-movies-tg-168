#include "showInventory.h"
#include "movie.h"

#include <algorithm>
#include <cassert>
#include <iostream>

// execute the command
void ShowInventory::execute() const {

  vector<MovieFactory *> vmf;
  for (auto &&[key, factory] : MovieFactory::getMapC()) {
    vmf.push_back(factory);
  }

  sort(vmf.begin(), vmf.end(),
       [](auto a, auto b) { return a->getType() > b->getType(); });

  vector<Movie *> vm;
  for (auto &&movieFactory : vmf) {
    vector<Movie *> toAdd = movieFactory->getMovies();
    for (auto &&movie : toAdd) {
      vm.push_back(movie);
    }
  }

  vector<string> vs;
  for (auto &&movie : vm) {
    vs.push_back(movie->getInfo());
  }

  for (auto &&s : vs) {
    cout << s << endl;
  }
}

// constructor
ShowInventoryFactory::ShowInventoryFactory() { registerType("I", this); }

// make a showInventory command
Command *ShowInventoryFactory::makeCommand(const string &detail) const {
  assert(detail.empty());
  return new ShowInventory();
}

ShowInventoryFactory anonymousShowInventoryFactory;