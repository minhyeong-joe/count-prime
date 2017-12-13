// Minhyeong Joe
// Homework 4 - Display Prime Numbers.
// Due May 4th, 2016
// This program will find and display all of the prime numbers between lower boundary and upper boundary
#include "HW4_Prime_VS2013.h";
// This member function prompts the user to input lower and upper boundary for the search.
void Prime::set_range()
{
	cout << "Enter the lower boundary: ";
	cin >> min;
	cin.ignore();
	while (min < 2)
	{
		cout << "The lower boundary must be greater than or equal to 2";
		cout << endl << "Enter the lower boundary: ";
		cin >> min;
		cin.ignore();
	}
	cout << "Enter the upper boundary: ";
	cin >> max;
	cin.ignore();
	while (max < min)
	{
		cout << "The upper boundary must be greater than " << min;
		cout << endl << "Enter the upper boundary: ";
		cin >> max;
		cin.ignore();
	}
	array_size = max;
	num = new int[array_size];
}
// This member function simply generates all integers from 1 to upper boundary,
// and allocate them into each element of the array num[].
void Prime::all_num()
{
	for (int i = 0; i < max; i++)
		num[i] = (i + 1);
}
// This member function checks each element for prime condition, and if it is not a prime number, 
// set the non-prime element to a '0' for display_prime() function.
void Prime::find_prime()
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 2; j < (num[i]-1) ; j++)
		{
			if ((num[i] != 0) && (num[i]) % j == 0) // Check prime condition. divisible by 2,3,4...any number one less than itself?
			{
				num[i] = 0;
				break;
			}
		}
	}
}
// This member function displays all numbers that are greater or equal to min, 
// so any '0's (or, any non-prime elements) will not be displayed nor counted into # of prime.
void Prime::display_prime()
{
	for (int i = 0; i < max; i++)
	{
		if (num[i] >= min)
		{
			cout << num[i] << " ";
			prime++;
		}
	}
	if (prime == 1)  // Since "There are 1 prime numbers..." is grammatically incorrect.
		cout << endl << "There is " << prime << " prime number between " << min << " and " << max;
	else
		cout << endl << "There are " << prime << " prime numbers between " << min << " and " << max;
}
int main()
{
	bool loop = true;
	char ans;
	while (loop)
	{
		Prime prime;
		cout << "The program finds and outputs prime numbers within the range the user entered.\n\n";
		prime.set_range();
		prime.all_num();
		prime.find_prime();
		prime.display_prime();
		cout << endl;
		do
		{
			cout << "\nWould you like to try another computation? (Y for yes, or N for no): ";
			cin.get(ans);
			cin.ignore();
			switch (ans)
			{
			case 'y':
			case 'Y':
				system("cls");
				break;
			case 'n':
			case 'N':
				loop = false;
				break;
			default:
				cout << "Invalid input.\n";
				break;
			}
		} while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
	}
	cout << "Press any key to Continue...";
	getchar();
	return 0;
}