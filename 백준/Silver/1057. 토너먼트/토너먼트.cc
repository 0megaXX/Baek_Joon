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

using namespace std;
#define MAXX 2147483647

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int n, human1, human2;
    int turn = 0;

    cin>>n>>human1>>human2;
    
    while(human1 != human2)
    {
        // 확실한 내림을 위한 + 1
        human1 = (human1+1)/2;
        human2 = (human2+1)/2;
        turn++;
    }
    
    cout<<turn;
}