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

vector<int>v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, B, A;
    cin >> N >> B >> A;
   
    v.resize(N);
    for(int a = 0; a < N; a++)
        cin >> v[a];
   

    sort(v.begin(), v.end());

    int tmp=0;
    int summ = 0;

    int a;
    for( a = 0; a < N; a++)
    {
        summ += (v[a] / 2);
        if(a+1 > A)
            summ+= (v[tmp++] / 2);
       
        if(summ > B)
            break;
    }

    int rs = summ > B ? a : N;
    cout << rs;


    return 0;
}