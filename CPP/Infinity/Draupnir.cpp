#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T, W;
  cin >> T >> W;
  int testCase = 1;
  while (testCase <= T)
  {
    int R[7] = {0};
    int response[7];
    for (int i = 1; i <= W; i++)
    {
      cout << i << endl;
      cin >> response[i];
    }
    R[1] = (-4 * response[2] - 2 * response[3] + 4 * response[1] + response[6]) / 40;
    R[2] = response[2] - response[1] - 2 * R[1];
    R[3] = response[3] - response[2] - 4 * R[1];
    R[4] = response[4] - response[3] - 8 * R[1] - 2 * R[2];
    R[5] = response[5] - response[4] - 16 * R[1];
    R[6] = response[6] - response[5] - 32 * R[1] - 4 * R[2] - 2 * R[3];

    for (int i = 1; i <= 6; i++)
    {
      cout << R[i];
      if (i < 6)
        cout << " ";
    }
    cout << endl;
    int r;
    cin >> r;
    testCase++;
  }
  return 0;
}