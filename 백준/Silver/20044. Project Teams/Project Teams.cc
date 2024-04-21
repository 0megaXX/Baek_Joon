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


int student[10000];	// 학생들의 코딩역량


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int team;	
	int cur = 0;
	int minn = 0;

	cin >> team;

	for (int i = 0; i < 2 * team; i++) 
		cin >> student[i];
	

	//  코딩 역량 정렬
	sort(student, student + 2 * team);

	
	minn = student[0] + student[2 * team - 1];

	for (int i = 0; i < 2 * team; i++) {
		
		cur = student[i] + student[2 * team - i - 1];
		if (minn > cur) // 최솟값 갱신
			minn = cur;
		
	}

	cout << minn;

}