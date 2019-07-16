#include <iostream>
#include <algorithm>

using namespace std;

long long int findCommonDivisor(long long int m, long long int n)
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
  long long int r = n % m;
  return findCommonDivisor(r, m);
}

long long int findIndex(long long int *array, long long int size, long long int element)
{
  for (long long int i = 0; i < size; i++)
  {
    if (array[i] == element)
    {
      return i;
    }
  }
  return -1;
}

bool isPrime(long long int n)
{
  if (n <= 1)
  {
    return false;
  }
  for (long long int i = 2; i * i <= n; i++)
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
  long long int T;
  cin >> T;
  long long int testCase = 1;
  while (testCase <= T)
  {
    long long int N, L;
    cin >> N >> L;
    long long int value[L];
    long long int i;
    for (i = 0; i < L; i++)
    {
      cin >> value[i];
    }

    long long int letters[L + 1];
    long long int firstPrimeIndex = -1;
    long long int divisor;
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
    long long int lettersDictionary[26];
    long long int current = 0;
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