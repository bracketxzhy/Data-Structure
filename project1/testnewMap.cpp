#include "newMap.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void testCapacityHandling()
{
  Map small(2);
  assert(small.insert("A", 1));
  assert(small.insert("B", 2));
  assert(!small.insert("C", 3));

  Map def;
  assert(def.insert("Fred", 2.956));
  assert(def.size() == 1);
}

void testOrderedGetAndErase()
{
  Map m(10);
  assert(m.insert("Little Ricky", 3.206));
  assert(m.insert("Ethel", 3.538));
  assert(m.insert("Ricky", 3.350));
  assert(m.insert("Lucy", 2.956));
  assert(m.insert("Fred", 2.956));

  KeyType key = "stay";
  ValueType value = -1;
  assert(!m.get(-1, key, value));
  assert(key == "stay");
  assert(value == -1);

  assert(m.get(0, key, value) && key == "Ethel");
  assert(m.get(4, key, value) && key == "Ricky");
  assert(m.erase("Lucy"));
  assert(!m.contains("Lucy"));
  assert(m.size() == 4);
}

void testCopyAssignAndSwap()
{
  Map a(5);
  Map b(2);

  assert(a.insert("Fred", 2.956));
  assert(a.insert("Ethel", 3.538));
  assert(b.insert("Lucy", 2.956));
  assert(b.insert("Barney", 1.5));

  Map copied(a);
  assert(copied.size() == 2);
  assert(copied.contains("Fred"));
  assert(copied.contains("Ethel"));

  Map assigned(1);
  assigned = a;
  assert(assigned.size() == 2);
  assert(assigned.contains("Fred"));
  assert(assigned.contains("Ethel"));

  assigned = assigned;
  assert(assigned.size() == 2);
  assert(assigned.contains("Fred"));
  assert(assigned.contains("Ethel"));

  assert(assigned.insert("Wilma", 7.0));
  assert(!a.contains("Barney"));

  KeyType extra = "Ricky";
  ValueType value = 1.0;
  a.swap(b);
  assert(!a.insert(extra, value));
  assert(b.insert(extra, value));
}

void testInsertOrUpdateAndLookup()
{
  Map m(3);
  assert(m.insertOrUpdate("A", 1));
  assert(m.insertOrUpdate("A", 4));
  assert(m.insertOrUpdate("B", 2));
  assert(m.insertOrUpdate("C", 3));
  assert(!m.insertOrUpdate("D", 5));

  ValueType value = 99;
  assert(m.get("A", value) && value == 4);
  assert(!m.get("Z", value) && value == 4);
}

int main()
{
  testCapacityHandling();
  testOrderedGetAndErase();
  testCopyAssignAndSwap();
  testInsertOrUpdateAndLookup();

  cout << "Passed all tests" << endl;
}
