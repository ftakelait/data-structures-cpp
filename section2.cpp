#include<iostream>
#include<stdlib.h>

using namespace std;

// structure definition
struct Rectangle
{
	int length;  // sizeof(length) is 4 bytes
	int breadth;  // sizeof(breadth) is 4 bytes 
};  // total size of this structure is 4*4=8 bytes (it occupies 8 bytes in memory) but not yet untill we declare it in the main() function. 

int main()
{
	int A[5] = {4, 3, 5};
	
	for (int x:A)
	{
		cout << x << endl;
	}
	
	cout << endl;
			
	// declaration of the structure and initialization
	struct Rectangle r = {15, 2}; // now it occupies a scpace in memory
	
	// accessing a member of a structure
	cout << "Area of a rectangle is: " << r.length * r.breadth << endl;
	
	int a = 7;
	int *p; // pointer variable dclaration
	p = &a; // pointer initialization
	cout << "Pointer value: " << *p << endl;  // *p dereferencing
	
	// now to access the Heap in memory, we do the following
	int *ptr;
	ptr = (int *)malloc(5*sizeof(int));  // typecaste with integer, allocate memorey for 5 integers with each o type int
	cout << "Heap: " << *ptr << endl;
	delete [] ptr;

	// we can do it in c++ as follows
	int *ptr1;
	ptr1 = new int[5];
	ptr1[0] = 3; ptr1[1] = 4; ptr1[4] = 1;
	cout << "Heap C++: " << *ptr1 << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << ptr1[i] << endl << endl;	
	}
	delete [] ptr1; // or free(ptr1) in C Lnaguage

	struct Rectangle *prec = &r;
	cout << prec -> length << endl << endl;

	struct Rectangle *prtgl;
	prtgl = (struct Rectangle *)malloc(sizeof(struct Rectangle));
	prtgl -> length = 99;
	cout << prtgl -> length << endl;

	return 0;
}
