#include <bits/stdc++.h>

using namespace std;

void permutation(const int &length, string &str, vector<int> &v, vector<string> &s)
{
  if (v.size() == 0)
  {
    if (str.length() == length)
    {
      // cout << "str = " << str << endl;
      s.push_back(str);
    }
    return;
  }
  for (int i = 0; i < v.size(); i++)
  {
    int k = v[i];
    v.erase(v.begin() + i);
    str = str + to_string(k);
    // cout << "&str = " << &str << endl;
    permutation(length, str, v, s);
    // cout << "&str = " << &str << endl;
    str = str.substr(0, str.length() - 1);
    v.insert(v.begin() + i, k);
  }
}

int main()
{
  vector<int> v;
  vector<string> s;
  string str = "";
  const int n = 3;
  for (int i = 1; i <= n; i++)
  {
    v.push_back(i);
  }
  // cout << "&str = " << &str << endl;
  permutation(n, str, v, s);
  // cout << "&str = " << &str << endl;
  for (int i = 0; i < s.size(); i++)
  {
    cout << s[i] << endl;
  }
  cout << "There are " << s.size() << " permutations.\n";
  return 0;
}
// ANAND DUBEY