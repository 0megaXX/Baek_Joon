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
	map<string, Trie*> m; // 문자열 알파벳에 대한 트라이

	void insert(vector<string>& v, int idx)	// 트라이에 문자열 삽입
	{
		if (idx == v.size()) // 다 돌아봤다면
			return;

		if (m.find(v[idx]) == m.end()) //문자열이 없다면
		{
			Trie* trie = new Trie;
			m.insert({ v[idx], trie });
		}
		m[v[idx]]->insert(v, idx + 1); // 다음 문자열 삽입

	}

	void find(int d) {
		for (auto& i : m) {
			for (int j = 0; j < d; j++)
				cout << "--";
			cout << i.first << '\n';
			i.second->find(d + 1);
			delete i.second;
		}
	}
};





int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Trie* T = new Trie;
	int N;
	cin >> N;
	
	while (N--)
	{
		int K;
		cin >> K;
		vector<string>v(K);
		for (int a = 0; a < K; a++)
		{
			cin >> v[a];
		}
		T->insert(v, 0);	

	}

	T->find(0);
	return 0;
}