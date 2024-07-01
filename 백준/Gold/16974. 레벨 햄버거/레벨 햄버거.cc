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


vector<long long>  patty(51);
vector<long long> burger(51);

long long fn(int level, long long max_height) {

	if (level == 0)//패티 한 장만 있는 레벨 0의 햄버거인 경우
	{
		if (max_height == 1)
			return 1;
		else if (max_height == 0)
			return 0;
	}

	//맨밑은 빵이니 카운트 x
	if (max_height == 1)
		return 0;


	else if (max_height <= 1+ burger[level - 1] )//먹는게 빵+버거 보다 작다면
		return fn(level - 1, max_height - 1); 


	else if (max_height == 1 + burger[level - 1] + 1) //먹는게 빵 + 버거 + 패티 보다 작다면
		return patty[level - 1] + 1;

	
	else if (max_height <= burger[level - 1] + 1 + burger[level - 1] + 1)
		//먹는게 빵 + 버거 +패티 + 버거보다 작다면
		return patty[level - 1] + 1 + fn(level - 1, max_height - 1 - burger[level - 1] - 1);

	//먹는게 버거의 전체 재료 개수와 같다면
	else
		return patty[level - 1] * 2 + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N;
		long long X;
    cin >> N >> X;
    burger[0] = 1;
    patty[0] = 1;
    for (int a = 1; a <= N; a++)
    {
        burger[a] = 1 + burger[a - 1] + 1 + burger[a - 1] + 1;// a번째 햄버거의 크기
        patty[a] = patty[a - 1] + 1 + patty[a - 1]; // a번째 햄버거의 패티 수
    }
	
	cout << fn(N, X);
    return 0;
}