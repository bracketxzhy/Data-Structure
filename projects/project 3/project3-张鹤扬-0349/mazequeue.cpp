#include <iostream>
#include <queue>

using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
  private:
    int m_row;
    int m_col;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
  queue<Coord> coordQueue;
  coordQueue.push(Coord(sr, sc));
  maze[sr][sc] = '#';

  while (!coordQueue.empty())
  {
    Coord current = coordQueue.front();
    coordQueue.pop();

    int r = current.r();
    int c = current.c();

    if (r == er && c == ec)
      return true;

    if (maze[r][c+1] == '.')
    {
      coordQueue.push(Coord(r, c+1));
      maze[r][c+1] = '#';
    }
    if (maze[r+1][c] == '.')
    {
      coordQueue.push(Coord(r+1, c));
      maze[r+1][c] = '#';
    }
    if (maze[r][c-1] == '.')
    {
      coordQueue.push(Coord(r, c-1));
      maze[r][c-1] = '#';
    }
    if (maze[r-1][c] == '.')
    {
      coordQueue.push(Coord(r-1, c));
      maze[r-1][c] = '#';
    }
  }

  return false;
}

int main()
{
  char maze[10][10] = {
    { 'X','X','X','X','X','X','X','X','X','X' },
    { 'X','.','.','.','X','.','.','X','.','X' },
    { 'X','.','X','X','X','.','.','.','.','X' },
    { 'X','.','X','.','X','X','X','X','.','X' },
    { 'X','X','X','.','.','.','.','.','.','X' },
    { 'X','.','.','.','X','.','X','X','.','X' },
    { 'X','.','X','.','X','.','.','X','.','X' },
    { 'X','.','X','X','X','X','.','X','.','X' },
    { 'X','.','.','X','.','.','.','X','.','X' },
    { 'X','X','X','X','X','X','X','X','X','X' }
  };

  if (pathExists(maze, 4, 3, 1, 8))
    cout << "Solvable!" << endl;
  else
    cout << "Out of luck!" << endl;
}
