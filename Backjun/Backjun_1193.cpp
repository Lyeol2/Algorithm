#include <iostream>

using namespace std;


int main()
{
	int X;
	cin >> X;

	int max = 2;
	int child = 1;
	int parent = 1;
	bool flipping = true;

	for (size_t i = 1; i < X; i++)
	{
		if (X == 1) break;

		child += (max % 2 !=0) ? 1 : -1;
		parent += (max % 2 == 0) ? 1 : -1;

		if (child == 0) child++;
		if (parent == 0) parent++;
		if (child == max || parent == max)
		{
			max++;
		}
	}
	cout << child << "/" << parent << "\n";


}