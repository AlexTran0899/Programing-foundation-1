#include <iostream>
#include <fstream>
using namespace std;
int main()
{
   ifstream infile;
   infile.open("numbers.txt");
   // Initialize variables
   int val = 0;
   infile >> val;
   int min = val;
   int max = val;
   int ave = val;
   int cnt = 1;

   // Loop reading input
   while (infile >> val)
   {
      cout << val << endl;
      if (val < min) min = val;
      if (val > max) max = val;
      ave += val;
      cnt++;
   }

   // Print results
   cout << "min = " << min << endl;
   cout << "max = " << max << endl;
   cout << "ave = " << ave/cnt << endl;
   infile.close();
   return 0;
}

