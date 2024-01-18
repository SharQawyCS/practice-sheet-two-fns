// By sharqawycs
// 23p0360@eng.asu.edu.eg

#include <iostream>
using namespace std;

void to_binary(int num)
{
  cout << "Binary representation of " << num << ": ";

  //the case when the number is 0
  if (num == 0)
  {
    cout << "0";
    return;
  }

  // an array to store binary digits
  int binary[32]; //  32 bits
  int index = 0;

  // Convert the number to binary 
  while (num > 0)
  {
    binary[index++] = num % 2;
    num /= 2;
  }

  // Display the binary number
  for (int i = index - 1; i >= 0; --i)
  {
    cout << binary[i];
  }

  cout << endl;
}

int main()
{
  int number;
  cout << "Enter an integer: ";
  cin >> number;

  to_binary(number);

  return 0;
}
