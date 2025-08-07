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
#include <tuple>
#include <regex>

using namespace std;
#define MAXX 2147483647

vector<string>v;
vector<string>v2;

bool cmp(string a, string b) 
{
	if (a.length() == b.length()) 
		return a > b;
	
	return a.length() > b.length();
}

bool cmp2(string C, string D) 
{
	string CD="";
    string DC="";

	CD+=C;
	CD+=D;
	DC+=D;
	DC+=C;

    // 결합시 자릿수는 같기 때문에 크기가 큰 순서로 정렬. CD와 DC를 비교
	return CD > DC;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int K, N;
	cin >> K >> N;
    v.resize(K);
    v2.resize(N);
    
	for (int a = 0; a < K; a++) 
		cin >> v[a];
	

	sort(v.begin(), v.end(),cmp); // 숫자와 같게 내림차순 정렬
    
	for (int a = 0; a < K; a++) 
		v2[a] = v[a];
	
	for (int a = K; a < N; a++) 
		v2[a] = v[0]; // 적어도 한 번 이상 사용했다면 나머지는 가장 큰 수를 삽입 

	sort(v2.begin(), v2.end(), cmp2);

	string ans = "";

	for (int a = 0; a < N; a++) 
		ans+=v2[a];
	

	cout << ans;

   
    return 0;
}

