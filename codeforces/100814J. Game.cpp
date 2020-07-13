//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

char str[30][30];

char vowel[] = {'a','e','i','o','u'};

bool rec(string st, int p) {
    //cout<<st<<" "<<p<<endl;
    if(st.size() == 1) {
        for(int i = 0; i < 5; i++) {
            if(st[0] == vowel[i]) {
                return p == 0;
            }
        }
        return p == 1;
    }
    string tem = "";
    for(int i = 0; i+1 < st.size(); i+=2) {
        tem = tem+str[st[i]-'a'][st[i+1]-'a'];
    }
    if(st.size()%2 == 1)
        tem = tem+st[st.size()-1];
    if(!rec(tem,p^1)) return true;

    if(st.size()%2 == 0) return false;

    tem = st[0];
    for(int i = 1; i+1 < st.size(); i+=2) {
        tem = tem+str[st[i]-'a'][st[i+1]-'a'];
    }
    return !rec(tem,p^1);
}

int main() {
    int ti;
    scanf("%d", &ti);
    while(ti--) {
        for(int i = 0; i < 26; i++)
            scanf(" %s", str[i]);
        string st;
        cin>>st;
        if(rec(st,0))
            puts("Salah");
        else
            puts("Marzo");
    }
    return 0;
}


