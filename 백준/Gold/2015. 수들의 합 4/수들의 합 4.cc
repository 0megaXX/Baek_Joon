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

int stack_sum[200001];
map<int, long long>Map;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    int sizz,want;
    Map[0] = 1;

    long long cnt = 0;

    cin >> sizz >> want;
    for (int a = 0; a < sizz; a++)
    {
        int b;
        cin >> b;
        //Map[b]++;
        if (a == 0)
            stack_sum[a] = b;
       
        else
            stack_sum[a] = b + stack_sum[a - 1];


        cnt += Map[stack_sum[a] - want];

        Map[stack_sum[a]]++;
    }



    cout << cnt;
}