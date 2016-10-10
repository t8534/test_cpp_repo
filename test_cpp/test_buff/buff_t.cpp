//============================================================================
// Name        : buff_t.cpp
//============================================================================
//
// TODO:
// 1.
// Where the best to use binary style.
// std::ofstream outfile("out_alfa.txt", std::ios_base::binary);
//
// 2.
// write() is const char, what about unsigned char for 8 bit bytes ?
//
// You can do the casting on a pointer...
// outfile.write((char *)&data[0], data_size);
//
// the same can be done for reading (i.e. just pass a pointer to the first element
// of an array of unsigned char casting it to a pointer to char).
//
// ---
//
// When data is of type unsigned char* or unsigned char[] and you just want to write
// the bits into the file do a pointer cast:
// for(int x=0; x<data_size; x++)
// {
// outfile.write((char*)data + x, 1);
// }
//
// As casting removes the issue of one at a time writing:
// outfile.write((char*)data, data_size);
//
// And you do it all at once. Note that this outdoes the type checking and therefore
// is not the best solution.
//




#include <iostream>     // std::cout
#include <fstream>
#include <ostream>
#include <iterator>     // std::ostream_iterator
#include <algorithm>    // std::copy
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>


using namespace std;


void test()
{
#if 0
	// classic
	FILE* file = fopen( "myfile.bin", "wb" );
	fwrite( array, 1, 100, file );

	// second
	std::ofstream file("myfile.bin", std::ios::binary);
	file.write(data, 100);
	// Could be combined into:
	std::ofstream("myfile.bin", std::ios::binary).write(data, 100);

	// or
	std::ofstream out("somefile.bin", std::ios::binary);
	out.write(array, sizeof(array));

	// or
	//#include <fstream>
	ofstream fout;
	fout.open("file.bin", ios::binary | ios::out);
	int a[4] = {100023, 23, 42, 13};
	fout.write((char*) &a, sizeof(a));  //arek: is it ok, because sizeof shows the number of items, not bytes.
	fout.close();

	// Another approach:
	// This will convert a char 'a' to an int(or byte) value 97.
	ofstream sw("C:\\Test.txt");
	for(int i = 0; i < 256; i++)
	{
	  sw << (int)myArray[i];
	}

	// or
	// To write a byte or a group of bytes using std::fstream or std::ofstream,
	// you use the write() function: std::ostream::write()
	const int ArraySize = 100;
	Byte byteArray[ArraySize] = ...;
	std::ofstream file("myFile.data");
	if(file)
	{
	   file.write(&byteArray[0], ArraySize);
	   file.write(&moreData, otherSize);
	}



	// Write a vector content

	// To store a vector in a file, you have to write the contents of the vector, not the vector
	// itself.
	// You can access the raw data with &vector[0], address of the first element (given it contains
	// at least one element).
	ofstream outfile(filename, ios::out | ios::binary);
	outfile.write(static_char<char*>&data[0], data.size());
	// This should be fairly efficient at writing. fstream is generic, use ofstream if you
	// are going to write.
	// Note: Make sure that the vector is not empty before doing this.

	// Note, that with C++11 &data[0] may be replaced with data.data() which looks a little
	// cleaner.
	// Use vector::data to get a pointer the the underlying data:
	//file.write(data.data(), data.size());
	// You use it like this file.write(reinterpret_cast<const char*>(&myVector[0]), myVector.size());


	//To test your output, reopen it as an input file and print the bytes.
	ifstream in("myfile.txt", ios_base::binary);
	while(!in.eof()) printf("%02X ", in.get()); //print next byte as a zero-padded width-2 capitalized hexadecimal).
	in.close();
#endif

}


// int data[4] = {100023,   23,   42,   13}
//              0x0186B7, 0x17, 0x2A, 0x0D
// Result in file: B7 86 01 00 17 00 00 00 2A 00 00 00 0D 00 00 00
//
// double data[4] = {23.4, 3.5, 0.8, 5.4}
// Result in file:
// 66 66 66 66  66 66 37 40  00 00 00 00  00 00 0C 40
// 9A 99 99 99  99 99 E9 3F  9A 99 99 99  99 99 15 40
void test_bytebuf()
{

	// OK.
	/*
	//int data[4] = {100023, 23, 42, 13};
	double data[4] = {23.4, 3.5, 0.8, 5.4};
	ofstream file("test_bytebuf.bin", std::ios::binary);
	file.write((const char*)data, sizeof(data));
	file.close();
	*/

	// vector<unsigned char> as a binary byte buffer.
    // Example of bytes write.
	// todo:
	// [Q]
	// Not works for unsigned char if use static_cast<unsigned char*>, but with
	// (const char*) this is ok.
	// [A]
	// With (const char*) it works because it use reinterpret_cast<> finally.
	// The static_cast cannot be used because it no allow to cast pointers without
	// any relations between. The reinterpret_cast should be used than.

	// OK, work.
	/*
	unsigned char tmpArr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<unsigned char> outVect(tmpArr, tmpArr + sizeof(tmpArr)/sizeof(tmpArr[0]));
	std::ofstream outfile("out_bytebuff.txt", std::ios_base::binary);
	//outfile.write(static_cast<char*>(&outVect[0]), outVect.size());
	outfile.write(reinterpret_cast<char*>(&outVect[0]), outVect.size());
	*/
	// OK, work.
	unsigned char tmpArr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<unsigned char> outVect(tmpArr, tmpArr + sizeof(tmpArr)/sizeof(tmpArr[0]));
	std::ofstream outfile("out_bytebuff.txt", std::ios_base::binary);
	outfile.write((const char*)(&outVect[0]), outVect.size());


	/*
	// Copy a file
	#include <fstream>      // std::ifstream, std::ofstream

	int main () {
	  std::ifstream infile ("test.txt",std::ifstream::binary);
	  std::ofstream outfile ("new.txt",std::ofstream::binary);

	  // get size of file
	  infile.seekg (0,infile.end);
	  long size = infile.tellg();
	  infile.seekg (0);

	  // allocate memory for file content
	  char* buffer = new char[size];  // todo: what about unsigned char ?

	  // read content of infile
	  infile.read (buffer,size);

	  // write to outfile
	  outfile.write (buffer,size);

	  // release dynamically-allocated memory
	  delete[] buffer;

	  outfile.close();
	  infile.close();
	  return 0;
	}
	*/




}



// Write to the file, read, display vector content.
// Byte, int, double, string diff size.
void test_vect()
{
	// The best way for STL containers is to use stream iterator.
	// However it use >> operator which convert data into printable ASCII.
	// This is not row values.

	// Vector initialization:
	//
	// sizeof(array) is one of the few exceptions that allows to get the total size of elements
	// of the array and NOT the arr pointer dimension.
	// So basically he's using vector(pointer_to_first_element,
	// pointer_to_first_element + size_in_bytes_of_the_whole_array / size_of_one_element)
	// that is: vector(pointer_to_first_element, pointer_after_final_element). The type is
	// already given with the <int>, so the vector knows how much is one element.
	// Remember that iterators can be treated as pointers so you're basically using
	// the vector(iterator begin, iterator end) constructor.
	// If your compiler supports C++11, you can simply do:
    // std::vector<int> myVector = { 1,16,32,64 };

	//static const int arr[] = {100023, 23, 42, 13};
	static const int arr[] = {14, 23, 42, 13};
	vector<int> outVector (arr, arr + sizeof(arr) / sizeof(arr[0]) );  //todo: why arr+sizeof ??


    std::ofstream outfile("out_vector.txt");
    //std::ostream_iterator<int> output_iterator(outfile);
    std::ostream_iterator<int> output_iterator(outfile, " ");
    std::copy(outVector.begin(), outVector.end(), output_iterator);
    outfile.close(); // Must be closed before ifstream, because it make also flush.


    // Read data back into vector.
    // Not work if the file is: 14, 23, 42, 13,
    // Not work if the file is: 14234213
    // To read correct the file should be  14 23 42 13.
    // Than istream_iterator which use << operator interpret spaces as a separators
    // between numbers.
    //std::ifstream infile("out_vector.txt",std::ios_base::binary);
    std::ifstream infile("out_vector.txt");
    std::istream_iterator<int> in_it(infile), eof;
    std::vector<int> newVector(in_it, eof);
    infile.close(); // close explicilty for consistency

    std::vector<int>::iterator pos;
    for(pos = newVector.begin(); pos != newVector.end(); ++pos)
    {
    	cout << *pos << ", " << endl;
    }

}



// Write to the file, read, display set content.
void test_set()
{
	// C++11 init
	//set<int> outSet = {10, 12, 14, 16, 18, 20};
    //set<int> newSet;

    // C++ old
    int tmp[] = {10, 12, 14, 16, 18, 20};
    set<int> outSet(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));

    std::ofstream outfile("out_set.txt");
    // Only space, because istream iterator use << operator to separate numbers.
    std::ostream_iterator<int> output_iterator(outfile, " ");
    std::copy(outSet.begin(), outSet.end(), output_iterator);
    outfile.close(); // Must be closed before ifstream, because it make also flush.


    // Read data back into set.
    // Data in the file should be separated by space.
    // Than istream_iterator which use << operator interpret spaces as a separators
    // between numbers.
    std::ifstream infile("out_set.txt");
    std::istream_iterator<int> in_it (infile), eof;
    std::set<int> newSet(in_it, eof);
    infile.close(); // close explicilty for consistency

    std::set<int>::iterator pos;
    for(pos = newSet.begin(); pos != newSet.end(); ++pos)
    {
    	cout << *pos << ", " << endl;
    }

}


// Write to the file, read, display map content.
// There is no native way to use stream iterators for map.
void test_map()
{
	// C++11 init
	//map<int, string> outMap = {1, "Joyce", 2, "Austen", 3, "Dickens"};
	//map<int, string> newMap;

	map<int, string> outMap;
	map<int, string> newMap;

	outMap[1] = "Joyce";
	outMap[2] = "Austen";
	outMap[3] = "Dickens";

	/*
	// http://stackoverflow.com/questions/634087/stdcopy-to-stdcout-for-stdpair
	// http://www.thecodingforums.com/threads/copy-map-to-ostream_iterator.285989/
	// http://stackoverflow.com/questions/771453/copy-map-values-to-vector-in-stl
	//
    std::ofstream outfile("out_map.txt");
    //std::ostream_iterator<int> output_iterator(outfile);
    std::ostream_iterator<int> output_iterator(outfile, ", ");
    std::copy(outMap.begin(), outMap.end(), output_iterator);
    outfile.close(); // Must be closed before ifstream, because it make also flush.
    */

    // Read data back into set.
    /*
    std::ifstream infile("out_set.txt",std::ios_base::binary);
    std::istreambuf_iterator<int> iter(infile);
    std::copy(iter, std::istreambuf_iterator<int>(), std::back_inserter(newVector)); // this leaves newVector empty
    infile.close(); // close explicilty for consistency
    */


}


// Write to the file, read, display list content.
void test_list()
{
    int tmp[] = {10, 12, 14, 16, 18, 20};
    list<int> outList(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));

    std::ofstream outfile("out_list.txt");
    // Only space, because istream iterator use << operator to separate numbers.
    std::ostream_iterator<int> output_iterator(outfile, " ");
    std::copy(outList.begin(), outList.end(), output_iterator);
    outfile.close(); // Must be closed before ifstream, because it make also flush.


    // Read data back into set.
    // Data in the file should be separated by space.
    // Than istream_iterator which use << operator interpret spaces as a separators
    // between numbers.
    std::ifstream infile("out_list.txt");
    std::istream_iterator<int> in_it (infile), eof;
    std::list<int> newList(in_it, eof);
    infile.close(); // close explicilty for consistency

    std::list<int>::iterator pos;
    for(pos = newList.begin(); pos != newList.end(); ++pos)
    {
    	cout << *pos << ", " << endl;
    }

}

// Write to the file, read, display list content.
void test_queue()
{
	// std::queue and std::stack are not actually containers, they are so called container
	// adaptors which uses a container (by default std::deque). Therefore you can not initialize
	// it as other containers.
	// For a container to be able to use an initializer list, it must have a constructor taking
	// an std::initializer_list as argument. The container adaptors don't do that.
	// If it's deliberate or an oversight of the standards committee is up to anyones
	// interpretation.
    //int tmp[] = {10, 12, 14, 16, 18, 20};
    //queue<int> outQueue(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));

	// Edit2: I should probably add one more detail: since stack and queue can both accept
	// another container for the initialization, you can pretty easily do something like:
	//std::stack<int> data(std::vector<int>{1,2,3,4});
	//
	// This is somewhat verbose, but unlikely to cause any loss of efficiency (the container
	// will be passed as an rvalue reference, so its representation will be "stolen" instead
	// of copied). There is one caveat though: if the type of container you use doesn't match
	// the container underlying the container adapter, you'll get a copy rather than a move
	// (and consequently, may lose some efficiency).

	// The initialization not work with vector but work with list.
	// todo:
	// This is to clarify, seems to be only deque could be used as initializer.
	// What about list ?
	//static const int arr[] = {14, 23, 42, 13};
	//vector<int> tmpVect (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	//queue<int, vector<int> > myQueue (tmpVect);  // todo: what this declaration mean ?
	static const int tmp[] = {10, 12, 14, 16, 18, 20};
	list<int> tmpList(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));
	queue<int,std::list<int> > myQueue(tmpList);

	// The queue have no iterators. This is adapter, not container.
	std::ofstream outfile("out_queue.txt");
	while (!myQueue.empty())
	{
		outfile << myQueue.front() << ' ';
		myQueue.pop();
	}
	std::cout << '\n';

}


// Write the 2 dimensional table.
// At the begin of the file there is a header which contains table size,
// and other informations.
// Write to the file, read, display content.
void test_header()
{

}



// Test vector of sets
void test_vector_of_set()
{

}



// Test vector of queues
void test_vector_of_queues()
{

}


// Test vector of maps
void test_vector_of_map()
{

}


// Test map of vectors
void test_map_of_vectors()
{

}



// Test vector to list


// Test vector to queue


// Test vector to set




int main() {
	cout << "Start" << endl;
	test_bytebuf();
	//test_vect();
	//test_set();
	//test_map();
	//test_list();
	//test_queue();

	cout << "Stop" << endl;
	return 0;
}


