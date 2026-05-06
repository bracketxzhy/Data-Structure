#include "Set.h"

#include <utility>

Set::Node::Node(const ItemType &item)
    : value(item), next(this), prev(this)
{
}

Set::Set()
    : m_head(new Node(ItemType())), m_size(0)
{
}

Set::~Set()
{
  clear();
  delete m_head;
}

Set::Set(const Set &other)
    : Set()
{
  for (Node *p = other.m_head->next; p != other.m_head; p = p->next)
  {
    linkBefore(m_head, new Node(p->value));
    m_size++;
  }
}

Set &Set::operator=(const Set &rhs)
{
  if (this != &rhs)
  {
    Set temp(rhs);
    swap(temp);
  }

  return *this;
}

bool Set::empty() const
{
  return m_size == 0;
}

int Set::size() const
{
  return m_size;
}

bool Set::insert(const ItemType &value)
{
  Node *p = m_head->next;
  while (p != m_head && p->value > value)
    p = p->next;

  if (p != m_head && p->value == value)
    return false;

  linkBefore(p, new Node(value));
  m_size++;
  return true;
}

bool Set::erase(const ItemType &value)
{
  Node *p = findNode(value);
  if (p == m_head)
    return false;

  unlink(p);
  delete p;
  m_size--;
  return true;
}

bool Set::contains(const ItemType &value) const
{
  return findNode(value) != m_head;
}

bool Set::get(int pos, ItemType &value) const
{
  if (pos < 0 || pos >= m_size)
    return false;

  Node *p = m_head->next;
  for (int k = 0; k < pos; k++)
    p = p->next;

  value = p->value;
  return true;
}

void Set::swap(Set &other)
{
  std::swap(m_head, other.m_head);
  std::swap(m_size, other.m_size);
}

Set::Node *Set::findNode(const ItemType &value) const
{
  for (Node *p = m_head->next; p != m_head; p = p->next)
  {
    if (p->value == value)
      return p;
  }

  return m_head;
}

void Set::linkBefore(Node *position, Node *node)
{
  node->next = position;
  node->prev = position->prev;
  position->prev->next = node;
  position->prev = node;
}

void Set::unlink(Node *node)
{
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

void Set::clear()
{
  while (m_head->next != m_head)
  {
    Node *p = m_head->next;
    unlink(p);
    delete p;
  }

  m_size = 0;
}

void unite(const Set &s1, const Set &s2, Set &result)
{
  Set temp;

  for (int k = 0; k < s1.size(); k++)
  {
    ItemType value;
    s1.get(k, value);
    temp.insert(value);
  }

  for (int k = 0; k < s2.size(); k++)
  {
    ItemType value;
    s2.get(k, value);
    temp.insert(value);
  }

  result.swap(temp);
}

void inOnlyOne(const Set &s1, const Set &s2, Set &result)
{
  Set temp;

  for (int k = 0; k < s1.size(); k++)
  {
    ItemType value;
    s1.get(k, value);
    if (!s2.contains(value))
      temp.insert(value);
  }

  for (int k = 0; k < s2.size(); k++)
  {
    ItemType value;
    s2.get(k, value);
    if (!s1.contains(value))
      temp.insert(value);
  }

  result.swap(temp);
}
