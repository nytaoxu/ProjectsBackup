#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
// int level = 1;

int recursive_call();

int main()
{
  cout << .1 + .2 << endl;
  recursive_call();
  return 0;
}

int recursive_call()
{
  static int level = 1;
  int x[MAX];
  for (int i = 0; i < MAX; ++i)
  {
    x[i] = 7;
  }
  cout << "level = " << level << "\n";
  level++;
  recursive_call();
  return 0;
}

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706
// Round 1B
