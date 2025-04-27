#include<iostream>

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
	return 0;
}