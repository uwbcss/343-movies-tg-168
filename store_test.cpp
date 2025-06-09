/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "command.h"
#include "movie.h"
#include "system.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

void testSystem()
{
  cout << "Start testSystem" << endl;

  System s;

  string mfile = "data4movies.txt";
  s.readMoviesFromFile(mfile);

  string cfile = "testcommands-1.txt";
  s.readCommandsFromFile(cfile);

  s.executeAll();

  cout << "End testSystem" << endl;
}

void testStore1()
{
  cout << "Start testStore1" << endl;

  vector<Movie *> movies;
  vector<Command *> commands;

  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  string commandType;
  string detail;
  while (fs >> commandType)
  {
    out << commandType;
    getline(fs, detail);

    Command *command = CommandFactory::create(commandType, detail);
    if (command)
    {
      commands.push_back(command);
    }
    // cout << detail << endl;
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);

  for (const auto &command : commands)
  {
    command->execute();
    delete command;
  }

  cout << "End testStore1" << endl;
}

void testStore2()
{
  cout << "Start testStore2" << endl;
  cout << "End testStore2" << endl;
}

void testStoreFinal()
{
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll()
{
  testSystem();
  // testStore1();
  // testStore2();
  // testStoreFinal();
}
