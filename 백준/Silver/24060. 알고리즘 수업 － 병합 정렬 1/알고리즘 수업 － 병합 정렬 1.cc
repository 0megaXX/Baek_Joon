#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>
#include <tuple>

using namespace std;
#define MAXX 2147483647



	int A[500001] = { 0 };
	int tmp[500001] = { 0, };
	int cnt = 0;
	int N, K;
	bool flag = false;
	void merge(int A[], int p, int q, int r)
	{
		int i = p;
		int j = q + 1;
		int t = 1;
		while (i <= q && j <= r)
		{
			if (A[i] <= A[j])
			{
				tmp[t++] = A[i++];
			}
			else
			{
				tmp[t++] = A[j++];
			}
		}
		while (i <= q)
		{
			tmp[t++] = A[i++];
		}
		while (j <= r)
		{
			tmp[t++] = A[j++];
		}
		i = p;
		t = 1;
		while (i <= r)
		{
			A[i++] = tmp[t++];
			cnt++;
			if (cnt == K)
			{
				cout << A[i - 1];
				flag = true;
				return;
			}
		}
	}

	void merge_sort(int A[], int p, int r)
	{
		if (p < r)
		{
			int q = floor((p + r) / 2);
			merge_sort(A, p, q);
			merge_sort(A, q + 1, r);
			merge(A, p, q, r);
		}
	}

	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}
		merge_sort(A, 0, N - 1);
		if (!flag)
			cout << -1;

	}

