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
#define MAXX 99999999


int divisor[50];    // 약수

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int num;          
	int rs = 0;         

	cin >> num;
	for (int a = 0; a < num; a++) 
		cin >> divisor[a];
	

	sort(divisor, divisor + num);

	// 약수들 중 가장 작은 값 x 가장 큰 값을 해주면 N
	rs = divisor[0] * divisor[num - 1];
	cout << rs;

}
