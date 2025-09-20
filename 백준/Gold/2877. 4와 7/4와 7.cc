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



vector<int>v1, v2;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   

    int K;
    cin >> K;

    K+=1;

    while(K>=1) //2진수 변환
    {
        v1.push_back(K%2);
        K/=2;
    }

    for(int a = v1.size()-1; a>=0; a--)
        v2.push_back(v1[a]); //역순 저장

   
    for(int a=1; a<v2.size(); a++) //루트노드 제외 출력
    {
        if(v2[a]==0)
            cout << 4;
        else
            cout << 7;
    }
   
   
    return 0;
}