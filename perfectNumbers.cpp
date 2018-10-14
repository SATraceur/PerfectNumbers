#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void perfectNumber(int limit, int sum, int badness);


int main(int argc, char** argv)
{
	const int limit = argc > 1 ? atoi(argv[1]) : 1000000;
	const int badness = argc > 2 ? atoi(argv[2]) : -1;

	perfectNumber(limit, 0, badness);


	system("pause");
	return(0);
}

int _abs(int v) { return v < 0 ? -v : v; }

void perfectNumber(int limit, int sum, int badness)
{
	int count = 0;


	for (int i = 2; i < limit; i++) // iterates from 2 to the specified limit.
	{
		sum = 1; // resets sum for every iteration of the 'i' for loop
		for (int j = 2; (j*j) <= i; j++) // iterates through every number less than the sqrt of i to test for divisibility
		{
			if (i % j == 0) // if 'i' is divisible by 'j'
			{
				sum += j; // then add it to a sum
				if (j != i / j)
				{
					sum += i / j; // then find the recipricol factor
				}
			}
		}
		if (i == sum) // if the sum of the divisors are equal to the original number 'i'
		{
			if (badness >= 0) // and the badness is not a negative number
			{
				cout << i << " "; // then it'll tell user its a perfect number
			}
			count++; // this is a count for how many perfect and near perfect numbers there are, it will count independantly of the sign of the badness
		}

		int temp = _abs(i - sum); // sets temp to the absolute value of the difference between the number being tested and the sum of its divisors

		if (temp <= _abs(badness) && temp != 0) // if that difference is less than or equal to the badness then...
		{
			if (badness >= 0)
			{
				cout << i << " "; // it tells the user it is a 'near perfect number' and displays the badness
			}                                                                                // only if the badness is not negative
			count++; // the program continues to count perfect and near perfect numbers regardless of the sign of the badness
		}
	}
	if (badness < 0) // finally, if the badness was negative it will display the number of perfect and near perfect numbers and their badness.
	{
		cout << count;
	}



}
