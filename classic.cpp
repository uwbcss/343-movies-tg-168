#include "classic.h"
#include "system.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

Classic::Classic(int stock, string director, string title, string actorAndDate)
    : Movie("Classics", stock, director, title)
{
  vector<string> vs = System::splitString(actorAndDate, ' ');
  this->actor = vs[0] + " " + vs[1];
  this->date = vs[3] + " " + vs[2];
  month = stoi(vs[2]);
  year = stoi(vs[3]);
}

string Classic::getInfo()
{
  string s = date + ", " + actor + ", " + director + ", " + title + " (" +
             to_string(stock) + ") - " + typeFull;
  return s;
}

string Classic::getFirst() { return date; }

string Classic::getSecond() { return actor; }

ClassicFactory::ClassicFactory()
{
  registerType("C", this);
  type = "C";
}

Movie *ClassicFactory::makeMovie(const string &detail)
{
  vector<string> vs = System::splitString(detail);

  for (auto &&v : vs)
  {
    cout << v << endl;
  }

  Classic *classic = new Classic(stoi(vs[0]), vs[1], vs[2], vs[3]);
  // cout << classic->date << endl;
  // cout << classic->actor << endl;
  classics[make_pair(classic->date, classic->actor)] = classic;

  return classic;
}

vector<Movie *> ClassicFactory::getMovies()
{
  vector<Movie *> vm;
  for (auto &&[key, movie] : classics)
  {
    vm.push_back(movie);
  }

  sort(vm.begin(), vm.end(),
       [](auto a, auto b)
       {
         if (a->getFirst() != b->getFirst())
         {
           vector<string> vsa = System::splitString(a->getFirst(), ' ');
           vector<string> vsb = System::splitString(b->getFirst(), ' ');
           int yearA = stoi(vsa[0]);
           int yearB = stoi(vsb[0]);
           if (yearA != yearB)
           {
             return yearA < yearB;
           }

           int monthA = stoi(vsa[1]);
           int monthB = stoi(vsb[1]);
           return monthA < monthB;
         }

         return a->getSecond() < b->getSecond();
       });

  return vm;
}

ClassicFactory anonymous_ClassicFactory;