#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 500;

int compare(char a, char b)
{
  int d = a - b;
  if (d == 0)
  {
    return 0;
  }
  else if (d == -2 || d == -1 || d == 3)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

char findChar(string a, int n)
{
  int length = a.length();
  n = n % length;
  return a[n];
}

string findSolution(const string c[], const int &n, string &current)
{
  if (current.length() > MAX_LEN)
  {
    return "IMPOSSIBLE";
  }

  if (current.length() > 0)
  {
    char x = current[current.length() - 1];
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      int y = compare(x, findChar(c[i], current.length() - 1));
      if (y == -1)
      {
        return "IMPOSSIBLE";
      }
      sum += y;
    }
    if (sum == n)
    {
      return current;
    }
  }

  current += "P";
  string result = findSolution(c, n, current);
  if (result != "IMPOSSIBLE")
  {
    return result;
  }
  current[current.length() - 1] = 'R';
  result = findSolution(c, n, current);
  if (result != "IMPOSSIBLE")
  {
    return result;
  }
  current[current.length() - 1] = 'S';
  return findSolution(c, n, current);
}

int main()
{
  int T;
  cin >> T;
  int testCase = 1;
  while (testCase <= T)
  {
    int A;
    cin >> A;
    string C[A];

    for (int i = 0; i < A; ++i)
    {
      cin >> C[i];
    }
    string s = "";
    cout << "Case #" << testCase << ": " << findSolution(C, A, s) << "\n";
    testCase++;
  }
  return 0;
}