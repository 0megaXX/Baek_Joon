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
#define MAXX 987654321
using namespace std;

int L, C;
vector<char>v;
bool visit[111111111];
char rs[100000];



bool check_(char a)
{

	if ( a == 'e' ||  a == 'u' || a == 'i' ||
		a == 'o' || a == 'a')
		return true;

	else 
		return false;

}
void back(int start,int len, bool perfact, int consonant)
{
	if(len==L)
	{
		if(perfact && consonant>=2)
			cout << rs << '\n';
		return;
	}


	for (int a = start; a < C; a++)
	{
		if (!visit[a])
		{
			if (!perfact)
			{

				int n_consonant = consonant + !check_(v[a]);
				visit[a] = true;
				rs[len] = v[a];
				back(a + 1, len + 1, check_(v[a]),n_consonant);
				visit[a] = false;
				
			}
			else
			{
				int n_consonant = consonant + !check_(v[a]);
				visit[a] = true;
				rs[len] = v[a];
				back(a + 1, len + 1, perfact,n_consonant);
				visit[a] = false;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	memset(visit, false, sizeof(visit));
	cin >> L >> C;

	for (int a = 0; a < C; a++)
	{
		char b;
		cin >> b;
		v.push_back(b);
	}

	sort(v.begin(), v.end());

	back(0, 0, false,0);
}
