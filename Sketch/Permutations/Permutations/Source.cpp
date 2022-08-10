#include <iostream>
using namespace std;

int main() {
	int testN, num;

	cin >> testN;

	for (int j = 0; j < testN; j++)
	{
		cin >> num;
		gen_permutation(num);
	}
	return 0;
}

static int* gen_permutation(int n) {
	for (int i = 1; i <= n; i++)
	{
		
	}
	return;
}