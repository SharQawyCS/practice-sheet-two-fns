// By sharqawycs
// 23p0360@eng.asu.edu.eg
#include <iostream>
using namespace std;

// I've used Euclideas algorithm to calculate GCD (Discrete Maths -_-)
// Do not forget to search about it.
int gcd(int a, int b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int main()
{
  int x, y;

  cout << "Enter the first number: ";
  cin >> x;

  cout << "Enter the second number: ";
  cin >> y;

  int result = gcd(x, y);
  cout << "GCD(" << x << "," << y << ") = " << result << endl;

  return 0;
}