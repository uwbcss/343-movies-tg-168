#include "drama.h"
#include "system.h"

#include <algorithm>
#include <string>
#include <vector>

// constructor
Drama::Drama(int stock, string director, string title, int year)
    : Movie("Drama", stock, director, title), year(year) {}

// getter
string Drama::getInfo() {
  string s = director + ", " + title + ", " + to_string(year) + " (" +
             to_string(stock) + ") - " + typeFull;
  return s;
}

// getter
string Drama::getFirst() { return director; }

// getter
string Drama::getSecond() { return title; }

DramaFactory::DramaFactory() {
  registerType("D", this);
  type = "D";
}

// make a Drama movie
Movie *DramaFactory::makeMovie(const string &detail) {
  vector<string> vs = System::splitString(detail);

  Drama *drama = new Drama(stoi(vs[0]), vs[1], vs[2], stoi(vs[3]));
  movies[make_pair(drama->director, drama->title)] = drama;

  return drama;
}

// get movies of this type
vector<Movie *> DramaFactory::getMovies() {
  vector<Movie *> vm;
  for (auto &&[key, movie] : movies) {
    vm.push_back(movie);
  }

  sort(vm.begin(), vm.end(), [](auto a, auto b) {
    if (a->getFirst() != b->getFirst()) {
      return a->getFirst() < b->getFirst();
    }

    return a->getSecond() < b->getSecond();
  });

  return vm;
}

// turn command into key
pair<string, string> DramaFactory::toKey(string detail) {
  vector<string> vs = System::splitString(detail, ',');
  string director = vs[0];
  string title = vs[1].substr(1);

  return make_pair(director, title);
}

DramaFactory anonymousDramaFactory;