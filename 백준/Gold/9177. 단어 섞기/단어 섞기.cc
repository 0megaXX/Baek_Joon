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
#define MOD 987654321
using namespace std;




int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	int ct = 1;
	
	while (cass--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		string target_s;
		cin >> target_s;
		int s1_len = s1.length();
		int s2_len = s2.length();
		vector<vector<bool>>memo(s1_len+1,vector<bool>(s2_len+1));
		memo[0][0] = true;
		//먼저 두 글자가 찾는 단어의 어디까지 연속되는지 찾는 과정
		for (int a = 1; a <= s1_len; a++)	
			memo[a][0] = (s1[a - 1] == target_s[a - 1]) ? memo[a - 1][0] : false; 
		for (int a = 1; a <= s2_len; a++)	
			memo[0][a] = (s2[a - 1] == target_s[a - 1]) ? memo[0][a - 1] : false;

		for (int a = 1; a <= s1_len; a++)
		{
			for (int b = 1; b <= s2_len; b++)
			{
				//a는 s1중 a까지의 길이
				//b는 s2중 b까지의 길이

				char s1_last = s1[a - 1];
				char s2_last = s2[b - 1];
				char target_last = target_s[a + b - 1];

				if (s1_last != target_last && s2_last != target_last)
					// 만약 s1과 s2의 일부를 조합해 만들수 있는 글자의 마지막이 s1과 s2의 일부를 합친 길이의
					// target_s의 일부분의 끝과 다르다면 현재 s1과 s2의 일부를 조합으로는 만들수 없다.
					memo[a][b] = false;
				else if (s1_last == target_last && s2_last != target_last)
					//s1의 마지막 글자와 s1과 s2의 일부를 합친 길이의 target_s의 마지막 글자가 같다면
					memo[a][b] = memo[a - 1][b];
				else if (s1_last != target_last && s2_last == target_last)
					//s2의 마지막 글자와 s1과 s2의 일부를 합친 길이의 target_s의 마지막 글자가 같다면
					memo[a][b] = memo[a][b - 1];
				else // s1이든 s2든 마지막 글자가 s1과 s2의 일부를 합친 길이의 target_s의 마지막 글자가 같다면
					memo[a][b] = (memo[a][b - 1] || memo[a - 1][b]);
			}
		}

		cout << "Data set " << ct++ << ": ";
		memo[s1_len][s2_len] ? cout << "yes\n" : cout << "no\n";
	}
}
