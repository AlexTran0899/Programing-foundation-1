#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
   ofstream outfile;
   ifstream infile;
   outfile.open("words.txt");
   // Loop printing phrase
   if (outfile.fail())
   {
   cout << "Error: could not open output file\n";
   exit (EXIT_FAILURE);
   }
   string phrase = "A quick brown fox jumps over the lazy dog.";
   for (int i = 0; i < 10; i++)
      outfile << phrase << endl;
   outfile.close();
   
   infile.open("words.txt");
   string word;
   while (infile >> word)
      cout << word << " ";
   cout << endl;
   infile.close();
   return 0;
}
