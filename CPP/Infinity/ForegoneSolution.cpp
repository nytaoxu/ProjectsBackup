#include <iostream>

using namespace std;

int findDigit(int n)
{
  if (n < 0)
    return findDigit(-n);
  if (n < 10)
    return 1;
  return findDigit(n / 10) + 1;
}

int reverse(int n, int digit)
{
  int result = 0;
  while (digit > 0)
  {
    int r = n % 10;
    n = n / 10;
    result = 10 * result + r;
    digit--;
  }
  return result;
}

void separatingFour(int n, int *result)
{
  if (n == 0)
    return;
  if (n < 0)
    return separatingFour(-n, result);
  int r, digit = findDigit(n);
  while (n > 0)
  {
    r = n % 10;
    n = n / 10;
    result[0] *= 10;
    result[1] *= 10;
    if (r != 4)
    {
      result[0] += r;
    }
    else
    {
      result[1] += r;
    }
  }
  result[0] = reverse(result[0], digit);
  result[1] = reverse(result[1], digit);
  return;
}

int main()
{
  int T;
  cin >> T;
  int N, testCase = 1;
  while (testCase <= T)
  {
    cin >> N;
    int i = 1;
    int x[2] = {0, 0};
    separatingFour(N, x);
    x[0] = x[0] + x[1] / 2;
    x[1] = x[1] / 2;
    cout << "Case #" << testCase << ": " << x[0] << " " << x[1] << endl;
    testCase++;
  }
  return 0;
}