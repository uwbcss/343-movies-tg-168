#include "system.h"

#include <cassert>
#include <fstream>
#include <iostream>

// destructor
System::~System() {
  for (auto &&[key, customer] : customers) {
    delete customer;
  }
}

// add a new command to the list
void System::addCommand(const string &type, const string &detail) {
  Command *command = CommandFactory::create(type, detail);
  if (command != nullptr) {
    commands.push_back(command);
  }
}

// read commands from a txt file
void System::readCommandsFromFile(const string &filename) {
  ifstream fs(filename);
  assert(fs.is_open());
  string type;
  string detail;
  while (fs >> type) {
    getline(fs, detail);

    addCommand(type, detail);
  }
  fs.close();
}

std::unordered_map<int, Customer *> System::customers;

// read customers from a file
void System::readCustomersFromFile(const string &filename) {
  ifstream fs(filename);
  assert(fs.is_open());
  int id;
  while (fs >> id) {
    string firstName;
    fs >> firstName;
    string lastName;
    fs >> lastName;

    customers[id] = new Customer(firstName, lastName);
  }
  fs.close();
}

// add a new movie to the list
void System::addMovie(const string &type, const string &detail) {
  MovieFactory::create(type, detail);
}

// read movies from a txt file
void System::readMoviesFromFile(const string &filename) {
  ifstream fs(filename);
  assert(fs.is_open());
  char type;
  char comma;
  string detail;
  while (fs >> type >> comma) {
    getline(fs, detail);

    string typeS(1, type);
    addMovie(typeS, detail);
  }
  fs.close();
}

// execute all commands
void System::executeAll() {
  for (const auto &command : commands) {
    command->execute();

    delete command;
  }
}

// helper - get rid of spaces before and after string
string System::trimString(const string &str) {
  return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}

// helper - split string into multiple based on delimiter
vector<string> System::splitString(const string &str, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(System::trimString(token));
  }
  return tokens;
}