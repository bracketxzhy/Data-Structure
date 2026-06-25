#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

string infix2postfix(const string &infix)
{
  stack<char> st;
  string postfix;

  for (char c : infix)
  {
    if (isspace(static_cast<unsigned char>(c)))
      continue;

    if (isalnum(static_cast<unsigned char>(c)))
    {
      postfix += c;
    }
    else if (c == '(')
    {
      st.push(c);
    }
    else if (c == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        postfix += st.top();
        st.pop();
      }

      if (!st.empty())
        st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && c != '^')))
            {
                postfix += st.top();
                st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty())
  {
    if (st.top() != '(')
      postfix += st.top();
    st.pop();
  }
  return postfix;
}

int main()
{
  string infix;
  getline(cin, infix);
  cout << infix2postfix(infix) << endl;
  return 0;
}
