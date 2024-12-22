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


vector<int>w; // 가로 
vector<int>h; // 세로  
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m, t;
	cin >> n >> m;
	cin >> t; // 자르는 횟수
	w.resize(n);
	h.resize(m);
	
	for (int a = 0; a < t; a++)
	{
		int b, c;
		cin >> b >> c;

		if (b == 0)
			h.push_back(c);

		else if (b == 1)
			w.push_back(c);
	}
	w.push_back(n);
	h.push_back(m);
	sort(h.begin(), h.end());
	sort(w.begin(), w.end());
	int rs = 0;
	if (h.size() == 1 && w.size() > 1)
	{
		for (int a = 1; a < w.size(); a++)
		{
			if (h[0] * (w[a] - w[a - 1]) > rs) 
				rs = h[0] * (w[a] - w[a - 1]);
			
		}
		cout << rs;
	}
	else if (h.size() > 1 && w.size() > 1)
	{
		for (int a = 1; a < h.size(); a++)
			for (int b = 1; b < w.size(); b++)

				if ((h[a] - h[a - 1]) * (w[b] - w[b - 1]) > rs) 
					rs = (h[a] - h[a - 1]) * (w[b] - w[b - 1]);

		cout << rs;
	}
	else if (h.size() > 1 && w.size() == 1)
	{
		for (int a = 1; a < h.size(); a++)	
			if (w[0] * (h[a] - h[a - 1]) > rs) 
				rs = h[0] * (w[a] - w[a - 1]);		
		
		cout << rs;
	}
	else 
		cout << w[0] * h[0];
	


}

