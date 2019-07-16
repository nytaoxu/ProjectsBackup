#include <iostream>

using namespace std;

string flip(string s)
{
  string result = "";
  for (int i = 0; i < s.length(); i++)
  {
    s[i] == 'E' ? result.append("S") : result.append("E");
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
    int N;
    string P;
    cin >> N >> P;
    cout << "Case #" << testCase << ": " << flip(P) << endl;
    testCase++;
  }
  return 0;
}