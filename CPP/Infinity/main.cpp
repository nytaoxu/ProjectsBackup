#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>

// using namespace std;

// class Product
// {
// private:
//   /* data */
// public:
//   Product(/* args */);
//   ~Product();
// };

// Product::Product(/* args */)
// {
// }

// Product::~Product()
// {
// }

// void change(int &x)
// {
//   x++;
// }

// int main(int argc, char const *argv[])
// {
//   /* code */
//   unsigned int i = pow(2, 32) - 1;
//   cout << "pow(2, 32) - 1 = " << i << endl;
//   cout << "pow(2, 32) = " << i + 1 << endl;
//   short s = pow(2, 15) - 1;
//   cout << s << endl;
//   s = s + 1;
//   cout << s << endl;

//   cout << "Size of short int is " << sizeof(short int) << endl;
//   cout << "Size of short is " << sizeof(short) << endl;
//   cout << 0.1f + 0.2f << endl;
//   cout << "Size of bool is " << sizeof(bool) << endl;
//   cout << numeric_limits<int>::min() << endl;
//   cout << numeric_limits<int>::max() << endl;
//   printf("%-5d, %.3f", -12, 3.1235f);

//   return 0;
// }

int main()
{
  std::string answer;
  std::cout << "Enter Miles : ";
  std::getline(std::cin, answer);
  double miles = stod(answer);
  const double convertion = 1.60934f;
  double km = miles * convertion;
  std::cout << answer;
  printf(" miles equals %.4f kilometers.\n", km);
  return 0;
}