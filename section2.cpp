#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

// structure definition
struct Rectangle
{
	int length;  // sizeof(length) is 4 bytes
	int breadth;  // sizeof(breadth) is 4 bytes 
};  // total size of this structure is 4*4=8 bytes (it occupies 8 bytes in memory) but not yet untill we declare it in the main() function. 

int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

template<size_t N>
void func(int (&A)[N])
{
  for (int x : A)
  {
    cout << x << endl;
  }
}

void func1(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << endl;
  }
}

int* arrayfunc(int n)
{
  int *p;
  p = (int *)malloc(n*sizeof(int));
  
  for (int i = 0; i < n; i++)
  {
    p[i] = 0;
  }
  
  return p;
}

void changeLength(struct Rectangle *p, int l)
{
  p->length = l;
}

struct test {
  int A[5];
  int n;
};

void myfun(struct test *ele)
{
  ele->A[0] = 5;
}

int main()
{
	int A[5] = {4, 3, 5};
	func(A);
	cout << endl;
	func1(A, 3);
	cout << endl;
	// for (int x:A)
	// {
	//	cout << x << endl;
	// }
	
	// cout << endl;
	
	int *B;
	B = arrayfunc(5);
	//B[0] = 1; B[1] = 11; B[2] = 1;
	cout << "My function returns: " << B[0] << endl;
	
	// declaration of the structure and initialization
	struct Rectangle r = {15, 2}; // now it occupies a scpace in memory
	changeLength(&r, 20);
	// accessing a member of a structure
	cout << "Area of a rectangle is: " << r.length * r.breadth << endl;
	
	struct test t = {{11, 12, 13, 14}, 4};
	myfun(&t);
	cout << "My test structure is: " << t.A[0] << " " << t.n << endl;
	
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
	cout << prtgl->length << endl << endl;
	
	int x, y, z;
	x = 5; y = 5;
	z = add(x, y);
	cout << "Sum: " << z << endl << endl;;

	int n = 5; int m = 10;  
	swap(&n, &m);
	printf("Swap n=5, m=10 to: n=%d, m=%d\n", n, m);
        
	return 0;
}
