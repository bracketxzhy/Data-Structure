#ifndef GAMERMAP_H_INCLUDED
#define GAMERMAP_H_INCLUDED

#include <string>
#include "Map.h"

class GamerMap
{
public:
  GamerMap();

  bool addGamer(std::string name);
  double hoursSpent(std::string name) const;
  bool play(std::string name, double hours);
  int numGamers() const;
  void print() const;

private:
  Map m_map;
};

#endif
