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

int main()
{
    
      ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int a, b, c,ans;
	cin >> a >> b >> c; //고정 비용, 가변 비용, 판매 금액 입력

	if (b >= c)
		cout << "-1";   //가변 비용이 판매 비용보다 크거나 같다면 -1을 출력
	else {
		ans = a / (c - b) + 1;
		cout << ans;
	}
	
}