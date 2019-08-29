#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> sense(vector<double> p,string Z,vector<string> world,double pHit,double pMiss);
vector<double> move(vector<double>p,int U,double pExact,double pOvershoot,double pUndershoot);
void vec_print(vector<double> vec);

int main()
{
    vector<double> p(5,0.2);
    vector<string> world={"green", "red", "red", "green", "green"};
    vector<string> measurements={"red","green"};
    vector<int> motions(2,1);
    double pHit=0.6;
    double pMiss=0.2;
    double pExact=0.8;
    double pOvershoot=0.1;
    double pUndershoot=0.1;
    for(int k=0;k<measurements.size();k++)
    {
        p=sense(p,measurements[k],world,pHit,pMiss);
        p=move(p,motions[k],pExact,pOvershoot,pUndershoot);
        
    }
    vec_print(p);

    return 0;
}

vector<double> sense(vector<double> p,string Z,vector<string> world,double pHit,double pMiss)
{
    vector<double> q;
    int hit;
    double s=0;
    for(int i=0;i<p.size();i++)
    {
        hit=(Z==world[i]);
        q.push_back(p[i]*(hit*pHit+(1-hit)*pMiss));
        s+=q[i];

    }
    for(int i=0;i<p.size();i++)
    {
       q[i]/=s;

    }

    
    return q;
}
/* 
vector<double> move(vector<double>p,int U,double pExact,double pOvershoot,double pUndershoot)
{
    vector<double> q;
    
    for(int i=0;i<p.size();i++)
    {
        q.push_back( pExact*  p[(i-U)%p.size()]  + pOvershoot * p[(i-U-1) % p.size()] + pUndershoot * p[(i-U+1)%p.size()] );
    }
    return q;
}
*/
vector<double> move(vector<double> p, int U, double pExact, 
                    double pOvershoot, double pUndershoot) 
{
    /* 
     * Updates probability based on movement.
     */

    vector<double> q;
    double s = 0; // holds probability values calculated below

    // Calculate new probabilities
    for (int i = 0; i < p.size(); i++) {
        // The modulo operator behaves a bit different in C++ with negatives
        // If we took it as -1 % p.size(), we'd get zero instead of four
        // -1 + p.size() will give us what we would get from -1 % p.size in Python
        if ((i-U)<0)
        {
            s=p[i-U+p.size()] * pExact;
        }
        else
        {
            s=p[(i-U)%p.size()] * pExact;
        }
        if((i-U-1)<0)
        {
            s+=p[i-U-1+p.size()] * pOvershoot;
        }
        else
        {
            s+=p[(i-U-1)%p.size()] * pOvershoot;
        }
        if((i-U+1)<0)
        {
            s+=p[i-U+1+p.size()] * pUndershoot;
        }
        else
        {
            s+=p[(i-U+1)%p.size()] * pUndershoot;
        }
        
        q.push_back(s);
        

        
    }

    return q;
}


void vec_print(vector<double> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";

    }
    cout<<"\n";
}
