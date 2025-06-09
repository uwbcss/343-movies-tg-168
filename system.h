#ifndef SYSTEM_H
#define SYSTEM_H

#include "command.h"
#include "customer.h"
#include "movie.h"

#include <sstream>

class System {
private:
  vector<Command *> commands;

public:
  // destructor
  ~System();

  // add a new command to the list
  void addCommand(const string &type, const string &detail);

  // read commands from a txt file
  void readCommandsFromFile(const string &filename);

  // read customers from a file
  static void readCustomersFromFile(const string &filename);

  // add a new movie to the list
  static void addMovie(const string &type, const string &detail);

  // read movies from a txt file
  static void readMoviesFromFile(const string &filename);

  // execute all commands
  void executeAll();

  // helper - get rid of spaces before and after string
  static string trimString(const string &str);

  // helper - split string into multiple based on delimiter
  static vector<string> splitString(const string &str, char delimiter = ',');

  static unordered_map<int, Customer *> customers;
};

#endif