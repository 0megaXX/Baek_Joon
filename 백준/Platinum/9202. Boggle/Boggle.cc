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

using namespace std;



char boggle[4][4];
bool visit[4][4];
int dx[8]{ 0,0,1,-1,1,1,-1,-1 };
int dy[8]{ 1,-1,0,0,1,-1,1,-1 };
int max_len;
int score;
int found_word;
string max_s;
set<string>Set;
set<string>ans;

struct Trie
{
	Trie* next[26];

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

		

		// if (*key == '\0') // 문자열이 끝나는 지점일 경우
		//{
		//	fin = true;
		//	return;
		//}
		int curr = *key - 'A';
		if (next[curr] == NULL)
			next[curr] = new Trie();  // 탐색이 처음되는 지점일 경우 동적할당

		if (*(key + 1) == '\0') // 문자열이 끝나는 지점일 경우
				{
					fin = true;
					return;
				}


		next[curr]->insert(key + 1); // 다음 문자 삽입
	}


	//트라이에서 문자열 찾기
	Trie* find(char key)
	{
		if (key == '\0') // 문자열이 끝나는 위치를 반환
			return this;

		int curr = key - 'A';
		if (next[curr] == NULL) // 다음 문자가 값이 존재하지 않음
			return NULL;

		return next[curr]; // 다음 문자의 트라이를 반환
	}


};


void score_cal(int len)
{
	switch (len)
	{
	case 1:
	case 2:
		score += 0;
		break;
	case 3:
	case 4:
		score += 1;
		break;
	case 5:
		score += 2;
		break;
	case 6:
		score += 3;
		break;
	case 7:
		score += 5;
		break;
	case 8:
		score += 11;
		break;

	}


}



void search(int x, int y, Trie* T, string s)
{

	string ns = s + boggle[x][y];


	if (T->fin && T->find(boggle[x][y]) != NULL)//현재 문자가 끝이 날 수 있다면.
	{
		if (ans.find(ns)!=ans.end() && Set.find(ns) == Set.end()) //찾아 본 적이 없다면
		{
			Set.insert(ns);
			found_word++;

			int cur_len = ns.length();
			
			score_cal(cur_len);

			if (cur_len > max_len)
			{
				max_len = cur_len;
				max_s = ns;
			}
			else if (cur_len == max_len)
			{
				max_s = min(max_s, ns);
			}
		}
	}


	Trie* cur = T->find(boggle[x][y]); // T의 다음 글자를 연결하여 만드는 단어의 일부가 존재하는지 확인

	if (cur != NULL) //다음 연결할 수 있는 글자가 존재한다면.
	{

		int nx, ny;
		for (int a = 0; a < 8; a++)
		{

			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && !visit[nx][ny] && cur->find(boggle[nx][ny]) != NULL)
			{
					visit[nx][ny] = true;
					search(nx, ny, cur, ns);
					visit[nx][ny] = false;	
			}
		}

	}
	

}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* T = new Trie();
	int w;
	cin >> w;
	for (int a = 0; a < w; a++)
	{
		char s[10];
		cin >> s;
		ans.insert(s);
		T->insert(s);
	}

	memset(visit, false, sizeof(visit));
	int cass;
	cin >> cass;
	while (cass--)
	{
		Set.clear();
		max_len = 0;
		max_s = "";
		score = 0;
		found_word = 0;

		for (int a = 0; a < 4; a++)
			for (int b = 0; b < 4; b++)
				cin >> boggle[a][b];

		for (int a = 0; a < 4; a++)
			for (int b = 0; b < 4; b++)
			{		
				visit[a][b] = true;
				string s = "";
				search(a, b, T, s);
				visit[a][b] = false;
			}
		cout << score << ' ' << max_s << ' ' << found_word <<'\n';



	}
	delete T;
}
