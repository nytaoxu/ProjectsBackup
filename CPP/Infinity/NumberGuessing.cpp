#include <iostream>
// #include <string>

using namespace std;

int main()
{
  int T;
  cin >> T;
  int A, B, N, Q;
  string response;
  while (T > 0)
  {
    cin >> A >> B;
    A++;
    cin >> N;
    while (N > 0)
    {
      Q = (A + B) / 2;
      cout << Q << endl;
      // cin.ignore();
      // getline(cin, response);
      cin >> response;
      if (response == "CORRECT")
      {
        break;
      }
      else if (response == "TOO_BIG")
      {
        B = Q - 1;
      }
      else if (response == "TOO_SMALL")
      {
        A = Q + 1;
      }
      N--;
    }
    T--;
  }
  return 0;
}