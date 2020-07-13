#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int tsts;
    cin>>tsts;
    for(int ii=0;ii<tsts;ii++)
    {
        int ppl,b,k,mtot=0;
        cin>>ppl>>b;
        for(int lll=0;lll<b;lll++)
        {
        cin>>k;
        int mbk=1;
        for(int i=0;i<k;i++)
        {
            int bx;
            cin>>bx;
            mbk=(mbk*bx)%ppl;
        }
        mtot+=mbk;
        mtot=mtot%ppl;
        }
        cout<<mtot<<endl;
    }
    return 0;
}
