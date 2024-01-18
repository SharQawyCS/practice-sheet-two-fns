// By sharqawycs
// 23p0360@eng.asu.edu.eg
// Check if a given string is a palindrome (reads the same backward as forward).
#include <iostream>
using namespace std;

// The palindrome string is the srting its reversed string = the original string.
// abcdcba ==reversing==> abcdcba, the original == the reversed so, it is palindrome.
// Note: There is another solution by checking if the 1st letter == last letter & 2nd == the letter before the last etc...

void check_palindrome(string word)
{
  int length = word.size();  // Length of the string
  string reversed_word = ""; // Empty string

  // Reversing
  for (int i = length - 1; i >= 0; i--)
  {
    reversed_word += word[i]; // Add the last char in word to reversed_word etc...
  }

  if (word == reversed_word)
  {
    cout << "This srting is palindrome :)\n";
  }
  else
  {
    cout << "Sadly, it is not palindrome :(";
  }
}

int main()
{

  string w;
  cout << "Please enter a word to check if it is palindrome or not !! : ";
  cin >> w;

  check_palindrome(w);

  return 0;
}