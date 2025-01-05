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

using namespace std;
#define MAXX 99999999





int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n, score, p;
	int rank[100];


	cin >> n >> score >> p;

	for (int a = 0; a < n; a++) 
		cin >> rank[a];
	

	//계산단
	int cnt = 0;
	int my_rank = 1;
	for (int a = 0; a < n; a++) 
	{
		if (score < rank[a]) // 밑 등수면
			my_rank += 1;
		else if(score == rank[a]) // 동일 등수면
			my_rank = my_rank;
		else 
			break;

		cnt++;
	}


	if (cnt == p) 
		my_rank = -1;

	if (n == 0)
		my_rank = 1;



	cout << my_rank;
	return 0;

}
