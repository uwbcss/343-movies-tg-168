#include "showInventory.h"
#include "movie.h"

// execute the command
vector<string> ShowInventory::execute() const
{
  vector<MovieFactory *> vmf;
  for (auto &&[key, factory] : MovieFactory::getMapC())
  {
    vmf.push_back(factory);
  }

  vector<Movie *> vm;
  for (auto &&movieFactory : vmf)
  {
    vector<Movie *> toAdd = movieFactory->getMovies();
    for (auto &&movie : toAdd)
    {
      vm.push_back(movie);
    }
  }

  vector<string> vs;
  for (auto &&movie : vm)
  {
    vs.push_back(movie->getInfo());
  }

  return vs;
}

ShowInventoryFactory::ShowInventoryFactory() { registerType("I", this); }

Command *ShowInventoryFactory::makeCommand(const string &detail) const
{
  return new ShowInventory();
}

ShowInventoryFactory anonymous_ShowInventoryFactory;