#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo(double *input)
{
  double *twice = malloc(sizeof(double));
  *twice = *input * 2.0;
  return twice;
}

int main(int argc, char *argv[])
{
  int *age = malloc(sizeof(int));
  *age = 30;
  double *salary = malloc(sizeof(double));
  *salary = 12345.67;
  double *myList = malloc(3 * sizeof(double));
  myList[0] = 1.2;
  myList[1] = 2.3;
  myList[2] = 3.4;

  double *twiceSalary = multiplyByTwo(salary);

  printf("double your salary is %.3f\n", *twiceSalary);
  printf("%p, %p, %p, %p.\n", age, salary, myList, twiceSalary);
  *age = 15;
  free(age);
  free(salary);
  free(myList);
  free(twiceSalary);
  *age = 10;
  printf("%p, %d\n", age, *age);
  int x = 17;
  printf("%p, %d.\n", &x, x);

  return 0;
}
