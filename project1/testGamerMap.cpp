#include "GamerMap.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void testBasicBehavior()
{
  GamerMap gamers;
  assert(gamers.numGamers() == 0);
  assert(gamers.addGamer("Alice"));
  assert(!gamers.addGamer("Alice"));
  assert(gamers.numGamers() == 1);
  assert(gamers.hoursSpent("Alice") == 0);
  assert(gamers.hoursSpent("Nobody") == -1);
}

void testPlay()
{
  GamerMap gamers;
  assert(!gamers.play("Missing", 3));
  assert(gamers.addGamer("Alice"));
  assert(!gamers.play("Alice", -1));
  assert(gamers.play("Alice", 2.5));
  assert(gamers.play("Alice", 1.5));
  assert(gamers.hoursSpent("Alice") == 4.0);
}

void testPrint()
{
  GamerMap gamers;
  assert(gamers.addGamer("Alice"));
  assert(gamers.addGamer("Bob"));
  assert(gamers.play("Alice", 2));
  assert(gamers.play("Bob", 5));

  ostringstream captured;
  streambuf *oldBuffer = cout.rdbuf(captured.rdbuf());
  gamers.print();
  cout.rdbuf(oldBuffer);

  string output = captured.str();
  assert(output == "Alice 2\nBob 5\n" || output == "Bob 5\nAlice 2\n");
}

int main()
{
  testBasicBehavior();
  testPlay();
  testPrint();

  cout << "Passed all tests" << endl;
}
