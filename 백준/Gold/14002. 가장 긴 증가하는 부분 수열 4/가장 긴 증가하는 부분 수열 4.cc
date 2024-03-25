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
#include <deque>
using namespace std;




int arr[1001]{0};
int cct[1001]{ 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<int>>kk(1001);
	int size;
	cin >> size;
	for (int a = 1; a <= size; a++)
	{
		cin >> arr[a];
		cct[a] = 1;
	}

	cct[1] = 1;
	kk[0].push_back(0);
	kk[1].push_back(arr[1]);
	int maxx = 0;
	vector<int>max_v = kk[1];



	for (int a = 2; a <= size; a++)
	{
		int b = a;
	
		kk[a].push_back(arr[a]);
		maxx = max(cct[a], maxx);
		while (b)
		{
			
			if (arr[b] < arr[a])
			{

				if (cct[b] + 1 > cct[a])
				{

					cct[a] = cct[b] + 1;
					kk[a] = kk[b];
					kk[a].push_back(arr[a]);
				}
			}

			b--;
			
			if (maxx < cct[a])
			{
				maxx = cct[a];
				max_v = kk[a];
			
			}
		}
	}
	cout << max_v.size()<<"\n";

	for (int i = 0; i<max_v.size();i++)
	{
		cout << max_v[i] << " ";
	}
	
}
