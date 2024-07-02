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


int N;
int arr[110];
int visit1[110], visit2[110], num1, num2, ans[110], answer;

void dfs(int x) {
	ans[answer + num1++] = arr [x];
	visit1[x] = 1;

	if (!visit2[arr [x]]) 
		num2++;
		visit2[arr[x]] = 1;
	
	if (!visit1[arr[x]]) 
		dfs(arr[x]);
	
	visit1[x] = 0;
	visit2[arr[x]] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		int check = 0;
		for (int j = 0; j < answer; j++)
			if (i == ans[j])
				check = 1;
		if (!visit1[i] && !check) {
			dfs(i);
			if (num1 == num2)
				answer += num1;
			num1 = 0;
			num2 = 0;
		}
	}
	sort(ans, ans + answer);
	cout << answer <<'\n';

	for (int i = 0; i < answer; i++)
		cout << ans[i] << '\n';

}