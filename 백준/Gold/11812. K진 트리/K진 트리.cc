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
#define MAXX 987654321
using namespace std;


long long node;
int ary, cass;




long long get_dep(long long start)
{

	long long dep = 0;


	if (ary == 1)//1진 트리라면
		dep = start;

	else
	{

		if (start != 0) //위치가 정점이 아니라면
		{
			dep = 1;

			while (start!=1)
			{
				start = ceil((start-1) / (float)ary);
				dep++;
			}



		}
	}

	return dep;

}

long long parent(long long start)
{
	return	start= ceil((start - 1) / (float)ary);
}


void find_dist(long long a, long long b)
{

	long long dep_a = 0, dep_b = 0;
	long long ans = 0;
	dep_a = get_dep(a);
	dep_b = get_dep(b);

	//cout << dep_a << ' ' << dep_b << endl;;

	//깊이는 a>=b 로 정렬
	if (dep_a < dep_b)
	{
		swap(dep_a, dep_b);
		swap(a, b);
	}

	if (ary == 1) // 1진트리라면
		ans = dep_a - dep_b;


	else
	{
		long long dif = dep_a - dep_b; // 현재 차이나는 깊이
		ans += dif;// 차이만큼 더하고 깊이 맞춤

		for (long long b = 0; b < dif; b++)
			a = parent(a); // 깊이 차이만큼 올라가기

		while (a!=b)
		{
			a = parent(a);
			b = parent(b);
			ans += 2;

		}
	}
	cout << ans << '\n';

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> ary >> cass;

	while (cass--)
	{

		long long a, b;
		cin >> a >> b;
		find_dist(a, b);

	}
	
}