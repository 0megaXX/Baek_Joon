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


int month[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct info
{
    string mm;
    string dd;
    string time;
    string obj;
    string name;
    bool flag;
};


long long fn(string m,string d,string t,string mm,string dd,string tt){

    long long t2 = stoll(tt.substr(0,2)) * 60 + stoll(tt.substr(3,2));
    long long t1 = stoll(t.substr(0,2)) * 60 + stoll(t.substr(3,2));
    if(m == mm)
    {
        long long day = (stoll(dd) - stoll(d)) * 60 * 24;
        return day + (t2 -t1);
    }
    else
    {
        long long day = 0;
        if(stoll(mm) - stoll(m) > 1)
        {

            for(long long i=stoll(m) + 1 ; i< stoll(mm); i++)
                day += (month[i] * 60 * 24);
            
        }
        day += (stoll(dd) + (month[stoll(m)] - stoll(d))) * 60 * 24;
        return day + (t2 - t1);
    }
    
}


int main(){
    
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    long long n,f;
    string l;

    cin >> n >> l >> f;

    string d = l.substr(0,3);
    string h = l.substr(4,2);
    string s = l.substr(7,2);

    long long reservedTime = (stoll(d) * 24 + stoll(h)) * 60 + stoll(s);

    map<string,info> objInfo;
    map<string,long long> mans;

    for(long long a=0; a<n; a++)
    {
        string date, time, obj, name;
        cin >> date >> time >> obj >> name;

        string mm = date.substr(5,2);
        string dd = date.substr(8,2);

        if(objInfo[obj+name].flag)
        {
            info i = objInfo[obj+name];
            long long used = fn(i.mm,i.dd,i.time,mm,dd,time);
            if(reservedTime < used)
                mans[name] += (used - reservedTime) * f;
            
            objInfo.erase(obj+name);
        }
        else
            objInfo[obj+name] = {mm,dd,time,obj,name,true};
        
    }
    if(mans.empty()) 
    {
        cout << -1;
        return 0;
    }
    vector<pair<string,long long>> v;
    
    for(auto i : mans)
        v.push_back({i.first,i.second});
    
    sort(v.begin(),v.end());
    for(auto i : v)
        cout << i.first << ' ' << i.second <<"\n";
    
    return 0;
}