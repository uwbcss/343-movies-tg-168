#include "comedy.h"
#include "system.h"

#include <algorithm>
#include <string>
#include <vector>

Comedy::Comedy(int stock, string director, string title, int year)
    : Movie("Comedy", stock, director, title), year(year)
{
}

string Comedy::getInfo()
{
  string s = title + ", " + to_string(year) + ", " + director + " (" +
             to_string(stock) + ") - " + typeFull;
  return s;
}

string Comedy::getFirst() {return title;}

string Comedy::getSecond() {return to_string(year);}

ComedyFactory::ComedyFactory()
{
  registerType("F", this);
  type = "F";
}

Movie *ComedyFactory::makeMovie(const string &detail)
{
  vector<string> vs = System::splitString(detail);

  Comedy *comedy = new Comedy(stoi(vs[0]), vs[1], vs[2], stoi(vs[3]));
  comedies[make_pair(comedy->title, comedy->year)] = comedy;

  return comedy;
}

vector<Movie *> ComedyFactory::getMovies()
{
  vector<Movie *> vm;
  for (auto &&[key, movie] : comedies)
  {
    vm.push_back(movie);
  }

  sort(vm.begin(), vm.end(),
       [](auto a, auto b)
       {
         if (a->getFirst() != b->getFirst())
         {
           return a->getFirst() < b->getFirst();
         }

         return stoi(a->getSecond()) < stoi(b->getSecond());
       });

  return vm;
}

ComedyFactory anonymous_ComedyFactory;