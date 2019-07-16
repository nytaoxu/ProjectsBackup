#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin >> T;
  int testCase = 1;
  while (testCase <= T)
  {
    int P, Q;
    cin >> P >> Q;
    int x[P];
    int y[P];
    char d[P];
    Q++;
    int matrix[Q][Q];
    for (int i = 0; i < Q; i++)
    {
      for (int j = 0; j < Q; j++)
      {
        matrix[i][j] = 0;
      }
    }
    for (int i = 0; i < P; i++)
    {
      cin >> x[i] >> y[i] >> d[i];
      // N S E W
      switch (d[i])
      {
      case 'N':
        for (int ii = 0; ii < Q; ii++)
        {
          for (int jj = y[i] + 1; jj < Q; jj++)
          {
            matrix[ii][jj]++;
          }
        }
        break;
      case 'S':
        for (int ii = 0; ii < Q; ii++)
        {
          for (int jj = y[i] - 1; jj >= 0; jj--)
          {
            matrix[ii][jj]++;
          }
        }
        break;
      case 'E':
        for (int ii = x[i] + 1; ii < Q; ii++)
        {
          for (int jj = 0; jj < Q; jj++)
          {
            matrix[ii][jj]++;
          }
        }
        break;
      case 'W':
        for (int ii = x[i] - 1; ii >= 0; ii--)
        {
          for (int jj = 0; jj < Q; jj++)
          {
            matrix[ii][jj]++;
          }
        }
        break;
      default:
        break;
      }
    }
    int rx = -1, ry = -1, result = -1;
    for (int i = 0; i < Q; i++)
    {
      for (int j = 0; j < Q; j++)
      {
        if (matrix[i][j] >= result)
        {
          if (matrix[i][j] > result)
          {
            rx = i;
            ry = j;
            result = matrix[i][j];
          }
          else
          {
            if (rx > i || (rx == i && ry > j))
            {
              rx = i;
              ry = j;
              result = matrix[i][j];
            }
          }
        }
      }
    }
    cout << "Case #" << testCase << ": " << rx << " " << ry << endl;
    testCase++;
  }
  return 0;
}