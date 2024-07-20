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

string tmp = "";
void fn(string start, string cur)
{

	if(start==cur) // 일치하다면 종료
	{
		cout << 1;
		exit(0);
	}

	if (start.length() >= cur.length()) // 시작 문자열보다 현재 문자열이 짧아지면 취소
		return ;

	
	if (cur[cur.length() - 1] == 'A')//문자열 끝이 A라면 제거할 수 있음.
	{	
		tmp = cur;
		tmp.erase(tmp.length() - 1);
		fn(start, tmp);
	}
	if (cur[0] == 'B')
	{
		tmp = cur;
		tmp.erase(tmp.begin());
		reverse(tmp.begin(),tmp.end());
		fn(start, tmp);
	}



}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string start, target;
	cin >> start >> target;

	fn(start, target);

	cout << 0;
}
