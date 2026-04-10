#include "Map.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void testEmptyAndInsert()
{
  Map m;
  assert(m.empty());
  assert(m.size() == 0);

  ValueType value = -1234.5;
  assert(!m.get("missing", value));
  assert(value == -1234.5);

  assert(m.insert("Fred", 2.956));
  assert(!m.empty());
  assert(m.size() == 1);
  assert(!m.insert("Fred", 1.0));
}

void testUpdatePaths()
{
  Map m;
  assert(!m.update("ghost", 3.5));
  assert(m.insert("Lucy", 2.5));
  assert(m.update("Lucy", 4.5));

  ValueType value = 0;
  assert(m.get("Lucy", value));
  assert(value == 4.5);

  assert(m.insertOrUpdate("Lucy", 8.0));
  assert(m.get("Lucy", value));
  assert(value == 8.0);

  assert(m.insertOrUpdate("Ethel", 3.538));
  assert(m.get("Ethel", value));
  assert(value == 3.538);
}

void testEraseAndContains()
{
  Map m;
  assert(m.insert("B", 2));
  assert(m.insert("A", 1));
  assert(m.insert("C", 3));
  assert(m.contains("A"));
  assert(!m.contains("Z"));
  assert(!m.erase("Z"));
  assert(m.erase("A"));
  assert(!m.contains("A"));
  assert(m.size() == 2);

  ValueType value = 0;
  assert(m.get("B", value) && value == 2);
  assert(m.get("C", value) && value == 3);
}

void testOrderedGet()
{
  Map m;
  assert(m.insert("Little Ricky", 3.206));
  assert(m.insert("Ethel", 3.538));
  assert(m.insert("Ricky", 3.350));
  assert(m.insert("Lucy", 2.956));
  assert(m.insert("Fred", 2.956));
  assert(m.insert("", 4.0));

  KeyType key = "unchanged";
  ValueType value = -7;
  assert(!m.get(-1, key, value));
  assert(key == "unchanged");
  assert(value == -7);
  assert(!m.get(6, key, value));
  assert(key == "unchanged");
  assert(value == -7);

  assert(m.get(0, key, value) && key == "" && value == 4.0);
  assert(m.get(1, key, value) && key == "Ethel" && value == 3.538);
  assert(m.get(2, key, value) && key == "Fred" && value == 2.956);
  assert(m.get(3, key, value) && key == "Little Ricky" && value == 3.206);
  assert(m.get(4, key, value) && key == "Lucy" && value == 2.956);
  assert(m.get(5, key, value) && key == "Ricky" && value == 3.350);
}

void testSwapAndCopy()
{
  Map first;
  Map second;

  assert(first.insert("Fred", 2.956));
  assert(second.insert("Ethel", 3.538));
  assert(second.insert("Lucy", 2.956));

  first.swap(second);
  assert(first.size() == 2);
  assert(second.size() == 1);
  assert(first.contains("Ethel"));
  assert(first.contains("Lucy"));
  assert(second.contains("Fred"));

  Map copied(first);
  assert(copied.size() == 2);
  assert(copied.contains("Ethel"));
  assert(copied.contains("Lucy"));

  Map assigned;
  assigned = second;
  assert(assigned.size() == 1);
  assert(assigned.contains("Fred"));

  assert(assigned.insert("Barney", 1.5));
  assert(!second.contains("Barney"));
}

void testCapacity()
{
  Map m;
  for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
  {
    assert(m.insert("key" + to_string(i), i));
  }

  assert(m.size() == DEFAULT_MAX_ITEMS);
  assert(!m.insert("overflow", 999));
}

int main()
{
  testEmptyAndInsert();
  testUpdatePaths();
  testEraseAndContains();
  testOrderedGet();
  testSwapAndCopy();
  testCapacity();

  cout << "Passed all tests" << endl;
}
