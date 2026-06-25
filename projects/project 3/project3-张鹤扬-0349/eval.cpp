#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

bool isOperand(char ch)
{
  return ch == 'T' || ch == 'F';
}

bool isBinaryOperator(char ch)
{
  return ch == '&' || ch == '|';
}

int precedence(char op)
{
  if (op == '!')
    return 3;
  if (op == '&')
    return 2;
  if (op == '|')
    return 1;
  return 0;
}

bool applyOperator(stack<bool>& values, char op)
{
  if (op == '!')
  {
    if (values.empty())
      return false;

    bool value = values.top();
    values.pop();
    values.push(!value);
    return true;
  }

  if (values.size() < 2)
    return false;

  bool right = values.top();
  values.pop();
  bool left = values.top();
  values.pop();

  if (op == '&')
    values.push(left && right);
  else if (op == '|')
    values.push(left || right);
  else
    return false;

  return true;
}

int evaluate(string infix, string& postfix, bool& result)
{
  stack<char> operators;
  string builtPostfix;
  bool needOperand = true;

  for (int i = 0; i < static_cast<int>(infix.size()); i++)
  {
    char ch = infix[i];

    if (ch == ' ')
      continue;

    if (isOperand(ch))
    {
      if (!needOperand)
        return 1;

      builtPostfix += ch;
      needOperand = false;
    }
    else if (ch == '!')
    {
      if (!needOperand)
        return 1;

      operators.push(ch);
    }
    else if (ch == '(')
    {
      if (!needOperand)
        return 1;

      operators.push(ch);
    }
    else if (ch == ')')
    {
      if (needOperand)
        return 1;

      bool foundOpen = false;
      while (!operators.empty())
      {
        char op = operators.top();
        operators.pop();

        if (op == '(')
        {
          foundOpen = true;
          break;
        }

        builtPostfix += op;
      }

      if (!foundOpen)
        return 1;

      while (!operators.empty() && operators.top() == '!')
      {
        builtPostfix += operators.top();
        operators.pop();
      }
    }
    else if (isBinaryOperator(ch))
    {
      if (needOperand)
        return 1;

      while (!operators.empty() &&
             operators.top() != '(' &&
             precedence(operators.top()) >= precedence(ch))
      {
        builtPostfix += operators.top();
        operators.pop();
      }

      operators.push(ch);
      needOperand = true;
    }
    else
      return 1;
  }

  if (needOperand)
    return 1;

  while (!operators.empty())
  {
    if (operators.top() == '(')
      return 1;

    builtPostfix += operators.top();
    operators.pop();
  }

  stack<bool> values;
  for (int i = 0; i < static_cast<int>(builtPostfix.size()); i++)
  {
    char ch = builtPostfix[i];

    if (ch == 'T')
      values.push(true);
    else if (ch == 'F')
      values.push(false);
    else if (!applyOperator(values, ch))
      return 1;
  }

  if (values.size() != 1)
    return 1;

  postfix = builtPostfix;
  result = values.top();
  return 0;
}

int main()
{
  string pf;
  bool answer = false;
  bool unchanged = answer;

  assert(evaluate("T| F", pf, answer) == 0 && pf == "TF|" && answer);
  unchanged = answer;
  assert(evaluate("", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("T|", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("F F", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("TF", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("()", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("()T", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("T(F|T)", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("T(&T)", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("(T&(F|F)", pf, answer) == 1 && answer == unchanged);
  unchanged = answer;
  assert(evaluate("T+F", pf, answer) == 1 && answer == unchanged);
  assert(evaluate("F | !F & (T&F) ", pf, answer) == 0
         && pf == "FF!TF&&|" && !answer);
  assert(evaluate(" F ", pf, answer) == 0 && pf == "F" && !answer);
  assert(evaluate("((T))", pf, answer) == 0 && pf == "T" && answer);
  assert(evaluate("!!!F", pf, answer) == 0 && pf == "F!!!" && answer);
  assert(evaluate("!(T|F)&T", pf, answer) == 0 && pf == "TF|!T&" && !answer);
  cout << "Passed all tests" << endl;
}
