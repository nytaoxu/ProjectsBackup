#include <iostream>
// #include <algorithm>

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

void mySort(int *array, int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    for (int j = i + 1; j < arraySize; j++)
    {
      if (array[i] > array[j])
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
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
    int divisor = findCommonDivisor(value[0], value[1]);
    int letters[L + 1];
    letters[1] = divisor;
    letters[0] = value[0] / divisor;

    for (i = 2; i <= L; i++)
    {
      letters[i] = value[i - 1] / letters[i - 1];
    }
    // letters array is constructed.
    int lettersDictionary[L + 1];
    int current = 0;
    for (i = 0; i <= L; i++)
    {
      if (findIndex(lettersDictionary, current, letters[i]) == -1)
      {
        lettersDictionary[current] = letters[i];
        current++;
      }
    }
    // sort(lettersDictionary, lettersDictionary + current);
    mySort(lettersDictionary, current);
    // sorted
    // char result[L + 1];
    string result = "";
    for (i = 0; i <= L; i++)
    {
      // result[i] = ((char)('A' + findIndex(lettersDictionary, current, letters[i])));
      result += ((char)('A' + findIndex(lettersDictionary, current, letters[i])));
    }
    // cout << "N = " << N << ", P = " << P << endl;

    // cout << "Case #" << testCase << ": ";
    // for (i = 0; i <= L; i++)
    // {
    //   cout << result[i];
    // }
    // cout << endl;
    cout << "Case #" << testCase << ": " << result << endl;
    testCase++;
  }
  return 0;
}