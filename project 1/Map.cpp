#include "Map.h"

#include <utility>

Map::Map()
    : m_size(0)
{
}

bool Map::empty() const
{
  return m_size == 0;
}

int Map::size() const
{
  return m_size;
}

bool Map::insert(const KeyType &key, const ValueType &value)
{
  if (findKey(key) >= 0)
    return false;

  return addPair(key, value);
}

bool Map::update(const KeyType &key, const ValueType &value)
{
  int index = findKey(key);
  if (index < 0)
    return false;

  m_data[index].value = value;
  return true;
}

bool Map::insertOrUpdate(const KeyType &key, const ValueType &value)
{
  if (update(key, value))
    return true;

  return addPair(key, value);
}

bool Map::erase(const KeyType &key)
{
  int index = findKey(key);
  if (index < 0)
    return false;

  for (int i = index; i < m_size - 1; i++)
    m_data[i] = m_data[i + 1];

  m_size--;
  return true;
}

bool Map::contains(const KeyType &key) const
{
  return findKey(key) >= 0;
}

bool Map::get(const KeyType &key, ValueType &value) const
{
  int index = findKey(key);
  if (index < 0)
    return false;

  value = m_data[index].value;
  return true;
}

bool Map::get(int i, KeyType &key, ValueType &value) const
{
  if (i < 0 || i >= m_size)
    return false;

  for (int candidate = 0; candidate < m_size; candidate++)
  {
    int numLess = 0;
    for (int j = 0; j < m_size; j++)
    {
      if (m_data[j].key < m_data[candidate].key)
        numLess++;
    }

    if (numLess == i)
    {
      key = m_data[candidate].key;
      value = m_data[candidate].value;
      return true;
    }
  }

  return false;
}

void Map::swap(Map &other)
{
  for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    std::swap(m_data[i], other.m_data[i]);

  std::swap(m_size, other.m_size);
}

int Map::findKey(const KeyType &key) const
{
  for (int i = 0; i < m_size; i++)
  {
    if (m_data[i].key == key)
      return i;
  }

  return -1;
}

bool Map::addPair(const KeyType &key, const ValueType &value)
{
  if (m_size >= DEFAULT_MAX_ITEMS)
    return false;

  m_data[m_size] = Pair(key, value);
  m_size++;
  return true;
}
