#include <iostream>
#include "gtest/gtest.h"

using namespace std;


int  arr[10];

int kth(int l, int r, int k)
{
	long long x = arr[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (l <= k && k <= j)
		return kth(l, j, k);
	if (i <= k && k <= r)
		return kth(i, r, k);
	return arr[k];
}


TEST(kth, Statisic){
	int g = kth(0, 10, 3);
	ASSERT_TRUE(g == -8);
};

int main(int argc, char *argv[]){
	int n = 10;
	int k = 2;
	for (int i = 1; i < n + 1; i++){
		arr[i] = k*i;
		k *= -1;
	}
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



