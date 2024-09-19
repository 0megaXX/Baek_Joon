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




bool visit[9]{false};
int cass;


void back(int len, string s)
{
	if (cass == len)

	{
		for(int a=0;a<s.length();a++)
			cout << s[a] << ' ';
		cout << '\n';
		return;
	}

		for (int a = 1; a <= cass; a++)
		{
			if (!visit[a])
			{
				visit[a] = true;
				string tmp = to_string(a);
				back( len + 1, s + tmp);
				visit[a] = false;
			}


		}



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	
	cin >> cass ;
	back(0, "");
}