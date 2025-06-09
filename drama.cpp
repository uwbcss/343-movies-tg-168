#include "drama.h"
#include "system.h"

#include <algorithm>
#include <string>
#include <vector>

Drama::Drama(int stock, string director, string title, int year)
    : Movie("Drama", stock, director, title), year(year)
{
}

string Drama::getInfo()
{
  string s = director + ", " + title + ", " + to_string(year) + " (" +
             to_string(stock) + ") - " + typeFull;
  return s;
}

string Drama::getFirst() {return director;}

string Drama::getSecond() {return title;}

DramaFactory::DramaFactory()
{
  registerType("D", this);
  type = "D";
}

Movie *DramaFactory::makeMovie(const string &detail)
{
  vector<string> vs = System::splitString(detail);

  Drama *drama = new Drama(stoi(vs[0]), vs[1], vs[2], stoi(vs[3]));
  movies[make_pair(drama->director, drama->title)] = drama;

  return drama;
}

vector<Movie *> DramaFactory::getMovies()
{
  vector<Movie *> vm;
  for (auto &&[key, movie] : movies)
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

         return a->getSecond() < b->getSecond();
       });

  return vm;
}

pair<string, string> DramaFactory::toKey(string detail)
{
  vector<string> vs = System::splitString(detail, ',');
  string director = vs[0];
  string title = vs[1].substr(1);

  return make_pair(director, title);
}

DramaFactory anonymous_DramaFactory;