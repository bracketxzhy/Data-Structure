#ifndef NEWMAP_H_INCLUDED
#define NEWMAP_H_INCLUDED

#include <string>

using KeyType = std::string;
using ValueType = double;

const int DEFAULT_MAX_ITEMS = 150;

class Map
{
public:
  Map();
  explicit Map(int capacity);
  ~Map();
  Map(const Map &other);
  Map &operator=(const Map &rhs);

  bool empty() const;
  int size() const;

  bool insert(const KeyType &key, const ValueType &value);
  bool update(const KeyType &key, const ValueType &value);
  bool insertOrUpdate(const KeyType &key, const ValueType &value);
  bool erase(const KeyType &key);

  bool contains(const KeyType &key) const;
  bool get(const KeyType &key, ValueType &value) const;
  bool get(int i, KeyType &key, ValueType &value) const;

  void swap(Map &other);

private:
  struct Pair
  {
    Pair()
        : key(), value()
    {
    }

    Pair(const KeyType &k, const ValueType &v)
        : key(k), value(v)
    {
    }

    KeyType key;
    ValueType value;
  };

  Pair *m_data;
  int m_size;
  int m_capacity;

  int findKey(const KeyType &key) const;
  bool addPair(const KeyType &key, const ValueType &value);
};

#endif
