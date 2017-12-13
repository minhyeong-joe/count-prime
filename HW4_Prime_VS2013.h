// Minhyeong Joe
// Homework 4 - Display Prime Numbers.
// Due May 4th, 2016
// This is a header file.

#ifndef _HW4_Prime_VS2013_H
#define _HW4_Prime_VS2013_H
#include <iostream>
using namespace std;
class Prime
{
	int array_size;
	int *num;
	int min, max, prime = 0;
public:
	void set_range();
	void all_num();
	void find_prime();
	void display_prime();
};
#endif