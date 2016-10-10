/*
 * stl_test1.cpp
 *
 */

// http://stackoverflow.com/questions/1855704/c-binary-file-i-o-to-from-containers-other-than-char-using-stl-algorithms

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::ostream_iterator<double> oi_t;
typedef std::istream_iterator<double> ii_t;

int main () {

    // generate some data to test
   std::vector<double> vd;
   for (int i = 0; i < 20; i++)
   {
     double d = rand() / 1000000.0;
     vd.push_back(d);
   }

   // perform output to a binary file
   ofstream output ("temp.bin", ios::binary);
   copy (vd.begin(), vd.end(), oi_t(output, (char *)NULL));
   output.close();

   // input from the binary file to a container
   std::vector<double> vi;
   ifstream input ("temp.bin", ios::binary);
   ii_t ii(input);
   copy (ii, ii_t(), back_inserter(vi));
   input.close();

   // output data to screen to verify/compare the results
   for (int i = 0; i < vd.size(); i++)
     printf ("%8.4f  %8.4f\n", vd[i], vi[i]);

   printf ("vd.size() = %d\tvi.size() = %d\n", vd.size(), vi.size());
   return 0;
}

// The resulting output is as follows and has two problems, afaik:
// 1804.2894  1804.2985
// 846.9309    0.9312
// 1681.6928    0.6917
// 1714.6369    0.6420
// 1957.7478    0.7542
// ...
// 1) Every double read from the binary data is missing the information before
//    the decimal place.
// 2) The data is mangled at the 3rd decimal place (or earlier) and some arbitrary
//    error is being introduced.
//
// For the question 1) You need to specify a separator (for example a space).
// The non-decimal part was stuck to the decimal part of the previous number.
// Casting and using NULL is generally wrong in C++. Should have been a hint ;)
//
//     copy (vd.begin(), vd.end(), oi_t(output, " "));
//
// For the question 2)
//     #include <iomanip>
//     output << setprecision(9);
//
// just curious - why is a separator necessary in the ostream_iterator definition?
// Is a byte actually getting used up each time oi is being used to designate a blank
// space? Can't we do without that extra byte and just read in the correct number
// of bytes corresponding to a double and forego a separator?
//
// Actually, your file isn't a binary file is the way you expect it. Just open
// the temp.bin file in a text editor. I don't think you can use the stream
// manipulators the ways you're doing it for storing the data in binary format.
//
// yes, I was noticing that they weren't being stored in binary format.
// What's the idiomatic way to output binary data from an STL container as such?
//
// will the above code remain same for a list with a user defined class variable
// instead of list<double>








