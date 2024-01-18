// By sharqawycs
// 23p0360@eng.asu.edu.eg
// Count the number of vowels in a given string.
#include <iostream>
using namespace std;

// The vowels in the alphabet are a, e, i, o, and u.
int count_vowels(string word)
{
  int length = word.size();
  int vowels_count = 0;

  for (int i = 0; i < length; i++)
  {
    // Check if the current charectar is vowel or not
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
    {
      vowels_count++; // increase count by 1;
    }
  }

  return vowels_count; // If the value remain 0; that means that it have not changed.
}

int main()
{
  string w;
  cout << "Enter string to check the number of vowels: ";
  cin >> w;
  int count = count_vowels(w);

  if (count != 0)
  {
    cout << "Number of vowels: " << count << endl;
  }
  else
  {
    cout << "This string has no vowels :( \n";
  }

  return 0;
}