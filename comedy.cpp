#include "comedy.h"
#include "system.h"

#include <algorithm>
#include <string>
#include <vector>

// constructor
Comedy::Comedy(int stock, string director, string title, int year)
    : Movie("Comedy", stock, director, title), year(year) {}

// getter
string Comedy::getInfo() {
  string s = title + ", " + to_string(year) + ", " + director + " (" +
             to_string(stock) + ") - " + typeFull;
  return s;
}

// getter
string Comedy::getFirst() { return title; }

// getter
string Comedy::getSecond() { return to_string(year); }

ComedyFactory::ComedyFactory() {
  registerType("F", this);
  type = "F";
}

// make a Comedy movie
Movie *ComedyFactory::makeMovie(const string &detail) {
  vector<string> vs = System::splitString(detail);

  Comedy *comedy = new Comedy(stoi(vs[0]), vs[1], vs[2], stoi(vs[3]));
  movies[make_pair(comedy->title, to_string(comedy->year))] = comedy;

  return comedy;
}

// get movies of this type
vector<Movie *> ComedyFactory::getMovies() {
  vector<Movie *> vm;
  for (auto &&[key, movie] : movies) {
    vm.push_back(movie);
  }

  sort(vm.begin(), vm.end(), [](auto a, auto b) {
    if (a->getFirst() != b->getFirst()) {
      return a->getFirst() < b->getFirst();
    }

    return stoi(a->getSecond()) < stoi(b->getSecond());
  });

  return vm;
}

// turn command into key
pair<string, string> ComedyFactory::toKey(string detail) {
  vector<string> vs = System::splitString(detail, ',');
  string title = vs[0];
  string year = vs[1].substr(0);

  return make_pair(title, year);
}

ComedyFactory anonymousComedyFactory;