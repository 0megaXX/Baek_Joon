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

	Trie* next[26]; // 26가지 알파벳에 대한 트라이

	bool fin;

	// 생성자
	Trie()
	{
		fin = false;
		memset(next, 0, sizeof(next));
	}

	// 소멸자
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}

	// 트라이에 문자열 삽입
	void insert(const char* key)
	{

		if (*key == '\0') // 문자열이 끝나는 지점일 경우
		{
			fin = true;
			return;
		}


		//cout << *key << endl;
		int curr = *key - 'a';
		if (next[curr] == NULL)
			next[curr] = new Trie();  // 탐색이 처음되는 지점일 경우 동적할당

		next[curr]->insert(key + 1); // 다음 문자 삽입


	}

	 //트라이에서 문자열 찾기
	Trie* find(const char* key)
	{
	    if (*key == '\0') // 문자열이 끝나는 위치를 반환
	        return this; 

	   int curr = *key - 'a';
	   if (next[curr] == NULL) // 다음 문자가 값이 존재하지 않음
	        return NULL; 

	    return next[curr]->find(key + 1); // 다음 문자를 탐색
	}
};





int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Trie* T = new Trie;
	int N, M;
	cin >> N >> M;
	for (int a = 0; a < N; a++)
	{
		char s[501];
		cin >> s;
		T->insert(s);
	}
	int ct = 0;
	for (int a = 0; a < M; a++)
	{
		char s[501];
		cin >> s;
		if (T->find(s) != NULL)
			ct++;

	}
	cout << ct;
	return 0;
}