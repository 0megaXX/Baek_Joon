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

//최대공약수 
int gcd(int n,int m){
    if(n%m==0)
        return m;
    else
        return gcd(m,n%m);

}

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    string s;
    string tmp;
    int n,m;

    cin>>s;
    
    //문자열 입력받아서 n과 m반환하기
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]==':')
        {
            tmp= s.substr(0,a); // 앞 수 분리(n)
            n=stoi(tmp);

            //m 구하기
            tmp=s.substr(a+1,s.length()); // 뒷 구 분ㅂ리 (m)
            m=stoi(tmp);

            break;
            
        }
    }


    int num=gcd(n,m);
    cout<< n / num <<":"<< m / num ; 
    
    return 0;
}