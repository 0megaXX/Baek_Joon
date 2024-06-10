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
#include <unordered_map>


using namespace std;

struct Trie
{
	Trie* next[26];
	int OnlyOne = 0;
	bool simai = false;
	bool start = false;


	Trie()
	{
		fill(next, next + 26, nullptr);
	}
	~Trie()
	{
		for (int a = 0; a < 26; a++)
			if (next[a])
				delete next[a];
	}
	void insert(const char* key)
	{

		if (*key == '\0') // 문자열이 끝나는 지점일 경우
		{
			simai = true;
			return;
		}



		int curr = *key - 'a';
		if (next[curr] == NULL)
		{
			if (OnlyOne == 0)
				OnlyOne = 1;
			else
				OnlyOne = 2;

			next[curr] = new Trie();  // 탐색이 처음되는 지점일 경우 동적할당
		}

		next[curr]->insert(key + 1); // 다음 문자 삽입


	}


	int find(const char* key, int click, bool start)
	{





		if (*key == '\0')
		{
			// if(click>0)
			return click;
			// else
			//return 1;
		}
		int curr = *key - 'a';

		if (start)
			return next[curr]->find(key + 1, click + 1, false);

		if (OnlyOne == 1) // 분기가 없고
		{
			if (simai) //끝나는 경우가 있지만 끝이 아니라면
			{
				return next[curr]->find(key + 1, click + 1, false);
			}

			else
			{
				return next[curr]->find(key + 1, click, false);
			}

		}
		else
		{


			return next[curr]->find(key + 1, click + 1, false);

		}

	}
};





int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cass;
	while (cin >> cass)
	{
		Trie* T = new Trie;


		vector<string>v(cass);
		//char s[100001][81];
		for (int a = 0; a < cass; a++)
		{

			cin >> v[a];
			T->insert(v[a].c_str());
		}

		int summ = 0;
		for (int a = 0; a < cass; a++)
		{

			summ += T->find(v[a].c_str(), 0, true);
		}

		float rs = (float)summ / cass;

		cout << fixed;
		cout.precision(2);
		cout << rs << '\n';

    delete T;
	}
	return 0;
}