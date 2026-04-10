#include "GamerMap.h"
#include <iostream>

GamerMap::GamerMap()
{
}

bool GamerMap::addGamer(std::string name)
{
  return m_map.insert(name, 0);
}

double GamerMap::hoursSpent(std::string name) const
{
  double hours = -1;
  return m_map.get(name, hours) ? hours : -1;
}

bool GamerMap::play(std::string name, double hours)
{
  if (hours < 0)
    return false;

  double currentHours = 0;
  if (!m_map.get(name, currentHours))
    return false;

  return m_map.update(name, currentHours + hours);
}

int GamerMap::numGamers() const
{
  return m_map.size();
}

void GamerMap::print() const
{
  for (int i = 0; i < m_map.size(); i++)
  {
    std::string name;
    double hours;
    m_map.get(i, name, hours);
    std::cout << name << " " << hours << std::endl;
  }
}
