#include "classic.h"
#include "system.h"

#include <algorithm>
#include <string>
#include <vector>

// constructor
Classic::Classic(int stock, string director, string title, string actorAndDate)
    : Movie("Classics", stock, director, title) {
  vector<string> vs = System::splitString(actorAndDate, ' ');
  this->actor = vs[0] + " " + vs[1];
  this->date = vs[3] + " " + vs[2];
  month = stoi(vs[2]);
  year = stoi(vs[3]);
}

// getter
string Classic::getInfo() {
  string s = date + ", " + actor + ", " + director + ", " + title + " (" +
             to_string(stock) + ") - " + typeFull;
  return s;
}

// getter
string Classic::getFirst() { return date; }

// getter
string Classic::getSecond() { return actor; }

// constructor
ClassicFactory::ClassicFactory() {
  registerType("C", this);
  type = "C";
}

// make a Classic movie
Movie *ClassicFactory::makeMovie(const string &detail) {
  vector<string> vs = System::splitString(detail);

  Classic *classic = new Classic(stoi(vs[0]), vs[1], vs[2], vs[3]);
  movies[make_pair(classic->date, classic->actor)] = classic;

  return classic;
}

// get movies of this type
vector<Movie *> ClassicFactory::getMovies() {
  vector<Movie *> vm;
  for (auto &&[key, movie] : movies) {
    vm.push_back(movie);
  }

  sort(vm.begin(), vm.end(), [](auto a, auto b) {
    if (a->getFirst() != b->getFirst()) {
      vector<string> vsa = System::splitString(a->getFirst(), ' ');
      vector<string> vsb = System::splitString(b->getFirst(), ' ');
      int yearA = stoi(vsa[0]);
      int yearB = stoi(vsb[0]);
      if (yearA != yearB) {
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

// turn command into key
pair<string, string> ClassicFactory::toKey(string detail) {
  vector<string> vs = System::splitString(detail, ' ');
  string month = vs[0];
  string year = vs[1];
  string date = year + " " + month;
  string actor = vs[2] + " " + vs[3];

  return make_pair(date, actor);
}

ClassicFactory anonymousClassicFactory;