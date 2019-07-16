#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin >> T;
  int testCase = 1;
  while (testCase <= T)
  {
    int N, K;
    cin >> N >> K;
    int C[N], D[N];
    for (int i = 0; i < N; i++)
    {
      cin >> C[i];
    }
    for (int i = 0; i < N; i++)
    {
      cin >> D[i];
    }
    int fairfight = 0;
    int L, R;
    for (L = 0; L <= N - 1; L++)
    {
      for (R = L; R <= N - 1; R++)
      {
        int maxC = -1, maxD = -1;
        for (int i = L; i <= R; i++)
        {
          if (C[i] > maxC)
            maxC = C[i];
          if (D[i] > maxD)
            maxD = D[i];
        }
        int difference = maxC - maxD;
        if (difference < 0)
          difference = -difference;
        if (difference <= K)
          fairfight++;
      }
    }
    cout << "Case #" << testCase << ": " << fairfight << endl;
    testCase++;
  }
  return 0;
}