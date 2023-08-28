#include <iostream>
using namespace std;

int power(long long a, unsigned int b, int c)
{
	int res = 1;	 // Initialize result

	a = a % c; // Update a if it is more than or
				// equal to c

	if (a == 0) return 0; // In case a is divisible by c;

	while (b > 0)
	{
		// If b is odd, multiply a with result
		if (b & 1)
			res = (res*a) % c;

		// b must be even now
		b = b>>1; // b = b/2
		a = (a*a) % c;
	}
	return res;
}

int main()
{
	int a = 2;
	int b = 5;
	int c = 13;
	cout << "Power is " << power(a, b, c);
	return 0;
}


