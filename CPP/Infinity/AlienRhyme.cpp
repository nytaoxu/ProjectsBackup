#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Rhyme
{
  int position;
  char accentedLetter;
};

void comparingTwoWords(string A, string B, Rhyme &r)
{
  int length = (A.length() <= B.length() ? A.length() : B.length());
  int position = 1;
  while (position <= length)
  {
    if (A[A.length() - position] != B[B.length() - position])
    {
      break;
    }
    position++;
  }
  r.position = position - 1;
  if (position == 1)
  {
    r.accentedLetter = '\0';
  }
  else
  {
    r.accentedLetter = A[A.length() - r.position];
  }
}

int countPairs(vector<string> &x, bool topLevel)
{
  if (x.size() == 0 || x.size() == 1)
  {
    return 0;
  }
  if (x.size() == 2 && !topLevel)
  {
    return 1;
  }
  vector<string> sub_array[27];
  int i = 0;
  while (i < x.size())
  {
    if (x[i].length() == 0)
    { // empty string
      sub_array[0].push_back(x[i]);
    }
    else
    { // non-empty string, take a look at the last letter
      sub_array[x[i][x[i].length() - 1] - 'A' + 1].push_back(x[i].substr(0, x[i].length() - 1));
    }
    i++;
  }
  // cout << "sub_array['I'] = " << sub_array['I' - 'A' + 1].size() << endl;
  int remainder = sub_array[0].size(), result = 0;
  i = 1;
  while (i <= 26)
  {
    int sub_result = countPairs(sub_array[i], false);
    result += sub_result;
    remainder += (sub_array[i].size() - 2 * sub_result);
    i++;
  }
  if (remainder >= 2 && !topLevel)
  {
    result++;
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
    cin >> N;
    string P[N];
    int i = 0;
    vector<string> str;
    while (i < N)
    {
      cin >> P[i];
      str.push_back(P[i]);
      i++;
    }
    i = 0;
    cout << "Case #" << testCase << ": " << 2 * countPairs(str, true) << endl;
    testCase++;
  }
  return 0;
}