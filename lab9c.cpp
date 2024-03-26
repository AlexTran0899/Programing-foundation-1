#include <iostream>
#include <string>
using namespace std;

char rot13(char ch)
{
   if ((ch >= 'a') && (ch <= 'z'))
      return char((13 + ch - 'a') % 26 + 'a');
   else if ((ch >= 'A') && (ch <= 'Z'))
      return char((13 + ch - 'A') % 26 + 'A');
   else
      return ch;
}

string rot13(string str)
{
   for (unsigned int i = 0; i < str.length(); i++)
      str[i] = rot13(str[i]);
   return str;
}

int main()
{
   string word;
   while (cin >> word)
      cout << rot13(word) << " ";
   return 0;
}
