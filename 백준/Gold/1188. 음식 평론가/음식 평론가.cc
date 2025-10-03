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


int gcd(int a,int b)
{
    if(a>b)
        swap(a,b);
   
    while(a>0)
    {
        int c = b % a;
        b=a;
        a=c;
    }
   
    return b;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin>>N>>M;
   
    cout<<M-gcd(N,M);
   
    return 0;
}
