#include <iostream>

using namespace std;

bool isValid(int i, int j, int m, int n)
{
  if (i == m || j == n || (i - j) == (m - n) || (i + j) == (m + n))
  {
    return false;
  }
  return true;
}

string step(int i, int j)
{
  return to_string(i) + " " + to_string(j);
}

int nextPosition(int x, int step, int max)
{
  x += step;
  while (x > max)
  {
    x -= max;
  }
  return x;
}

string output(int R, int C, bool reverse, int **universe)
{
  string result = "";
  int row = 1, column = 0, count = 1;
  int prev_i = 1, prev_j = 1;
  result += (reverse ? step(prev_i, prev_j) : step(prev_j, prev_i));
  while (count < R * C)
  {
    result += "\n";
    row = nextPosition(prev_i, 1, R);
    column = nextPosition(prev_j, 2, C);
    count++;
  }
  return result;
}

int main()
{
  int T;
  cin >> T;
  int testCase = 1;
  while (testCase <= T)
  {
    int R, C;
    cin >> R >> C;
    bool reverse = false;
    if (R > C)
    {
      int temp = R;
      R = C;
      C = temp;
      reverse = true;
    }
    // R <= C
    if (R == 1 || C == 1 || (R == 2 && C < 5) || (C == 2 && R < 5) || (R == 3 && C == 3))
    {
      cout << "Case #" << testCase << ": IMPOSSIBLE" << endl;
    }
    else
    {
      cout << "Case #" << testCase << ": POSSIBLE" << endl;
      int *universe[C];
      int i = 1;
      while (i <= R)
      {
        int newRow[C];
        int j = 0;
        while (j < C)
        {
          newRow[j] = 0;
          j++;
        }
        universe[i - 1] = newRow;
        i++;
      }
      cout << output(R, C, reverse, universe) << endl;
    }

    testCase++;
  }
  return 0;
}