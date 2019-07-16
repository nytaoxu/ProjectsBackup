#include <iostream>
#include <algorithm>

using namespace std;

int findCommonDivisor(int m, int n)
{
  if (m < 0)
  {
    m = -m;
  }
  if (n < 0)
  {
    n = -n;
  }
  if (m == 0 || m == n)
  {
    return n;
  }
  if (n == 0)
  {
    return m;
  }
  if (m > n)
  {
    return findCommonDivisor(n, m);
  }
  // 0 < m < n
  int r = n % m;
  return findCommonDivisor(r, m);
}

int findIndex(int *array, int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == element)
    {
      return i;
    }
  }
  return -1;
}

bool isPrime(int n)
{
  if (n <= 1)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int T;
  cin >> T;
  int testCase = 1;
  while (testCase <= T)
  {
    int N, L;
    cin >> N >> L;
    int value[L];
    int i;
    for (i = 0; i < L; i++)
    {
      cin >> value[i];
    }

    int letters[L + 1];
    int firstPrimeIndex = -1;
    int divisor;
    for (i = 0; i < L - 1; i++)
    {
      divisor = findCommonDivisor(value[i], value[i + 1]);
      if (isPrime(divisor))
      {
        firstPrimeIndex = i;
        break;
      }
    }
    // cout << "firstPrimeIndex = " << firstPrimeIndex << endl;
    if (firstPrimeIndex == -1)
    {
      exit(1);
    }
    letters[firstPrimeIndex + 1] = divisor;
    for (i = firstPrimeIndex; i >= 0; i--)
    {
      letters[i] = value[i] / letters[i + 1];
    }
    for (i = firstPrimeIndex + 2; i <= L; i++)
    {
      letters[i] = value[i - 1] / letters[i - 1];
    }
    // letters[L + 1] constructed.

    // letters array is constructed.
    int lettersDictionary[26];
    int current = 0;
    for (i = 0; i <= L; i++)
    {
      if (findIndex(lettersDictionary, current, letters[i]) == -1)
      {
        lettersDictionary[current] = letters[i];
        current++;
      }
    }
    sort(lettersDictionary, lettersDictionary + current);

    // mySort(lettersDictionary, current);
    // sorted

    string result = "";
    for (i = 0; i <= L; i++)
    {
      result += ((char)('A' + findIndex(lettersDictionary, current, letters[i])));
    }
    cout << "Case #" << testCase << ": " << result << endl;
    testCase++;
  }
  return 0;
}