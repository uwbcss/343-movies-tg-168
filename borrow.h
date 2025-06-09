#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include <string>
#include <vector>

using namespace std;

class Borrow : public Command {
private:
  string detail;

public:
  // constructor
  explicit Borrow(string detail);

  // borrow a movie
  void execute() const override;
};

class BorrowFactory : public CommandFactory {
public:
  // register this factory
  BorrowFactory();

  // make a Borrow command
  Command *makeCommand(const string &detail) const override;
};

#endif