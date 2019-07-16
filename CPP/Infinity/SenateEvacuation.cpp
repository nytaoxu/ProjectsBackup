#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  int N;
  int testCase = 1;
  while (testCase <= T)
  {
    cin >> N;
    int P[N];
    int i = 0;
    int totalSenators = 0;
    int largest = 0, secondLargest = -1; // N must be no less than 2.
    while (i < N)
    {
      cin >> P[i];
      totalSenators += P[i];
      if (P[i] > P[largest])
      {
        largest = i;
      }
      i++;
    }
    cout << "Case #" << testCase << ":";
    i = 0;
    while (i < N)
    {
      if (i != largest)
      {
        if (secondLargest == -1)
        {
          secondLargest = i;
        }
        else if (P[i] > P[secondLargest])
        {
          secondLargest = i;
        }
      }
      i++;
    }
    // output
    int difference = P[largest] - P[secondLargest];
    while (difference > 0)
    {
      if (difference == 1)
      {
        P[largest]--;
        totalSenators--;
        cout << " " << (char)(65 + largest);
      }
      else
      {
        P[largest] -= 2;
        totalSenators -= 2;
        cout << " " << (char)(65 + largest) << (char)(65 + largest);
      }
      difference = P[largest] - P[secondLargest];
    }
    // P[largest] == P[secondLargest]
    // Print all the other political parties first
    i = 0;
    while (i < N)
    {
      if (i != largest && i != secondLargest)
      {
        while (P[i] > 0)
        {
          if (P[i] == 1)
          {
            P[i]--;
            totalSenators--;
            cout << " " << (char)(65 + i);
          }
          else
          {
            P[i] -= 2;
            totalSenators -= 2;
            cout << " " << (char)(65 + i) << (char)(65 + i);
          }
        }
      }
      i++;
    }
    // Print the two
    while (P[largest] > 0)
    {
      P[largest]--;
      P[secondLargest]--;
      totalSenators -= 2;
      cout << " " << (char)(65 + largest) << (char)(65 + secondLargest);
    }
    cout << endl;
    testCase++;
  }
  return 0;
}