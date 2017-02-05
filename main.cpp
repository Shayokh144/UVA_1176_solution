#include <bits/stdc++.h>

using namespace std;

int dp[100000000]= {0};
int a[100000000]= {0};
int q[100000000]= {0};
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else if(a[n]==0)
        return (josephus(n - 1, k) + k-1) % n + 1;
    else
        return a[n];
}

int main()
{

    int n,k,m,c,g,f,e,flg,dif,idx;

//  q[1]=2;
    for(int i=1; i<=32767; i++)
    {
        dif=0;
        c=2;
        flg=0;
        n=i;
        while(1)
        {



            if(a[n]==0)
            {
                idx=josephus(n, c);
                a[n]=idx;
            }
            else
                idx=a[n];


            if(idx==1)
            {
                dif=dif+n+1;
                q[i]=dif;
                // cout<<dif<<"\n";
                break;

            }
            else if(idx==n)
            {
                // cout<<"dddfds";
                dif=dif+n*2;
                q[i]=dif;
                // cout<<dif<<"\n";
                break;
            }
            else
            {
                dif=dif+(n-idx);
                n=idx;
            }




        }
    }


    while((cin>>n))
    {
        if(n!=0)
            cout<<q[n]<<"\n";


    }
    return 0;
}
