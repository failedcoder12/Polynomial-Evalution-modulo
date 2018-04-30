// https://www.codechef.com/problems/POLYEVAL

    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    #define M 786433
    const ll mod = M;
    const ll root = 1000;
    const ll root_pw = 1<<18;
    ll power(ll x,ll y)
    {
        if(y==0) return 1;
        ll z = power(x,y/2);
        if(y%2==0) return ((ll)z*z)% M;
        else return ((ll)x%M * ((ll)z*z)%M)%M;
    }
    void ntt (vector<ll> & a) {
        ll n = (ll) a.size();
     
        for (ll i=1, j=0; i<n; ++i) {
            ll bit = n >> 1;
            for (; j>=bit; bit>>=1)
                j -= bit;
            j += bit;
            if (i < j)
                swap (a[i], a[j]);
        }
        for (ll len=2; len<=n; len<<=1) {
            ll wlen = root;
            for (ll i=len; i<root_pw; i<<=1)
                wlen = ll (wlen * 1ll * wlen % mod);
            for (ll i=0; i<n; i+=len) {
                ll w = 1;
                for (ll j=0; j<len/2; ++j) {
                    ll u = a[i+j],  v = ll (a[i+j+len/2] * 1ll * w % mod);
                    a[i+j] = u+v < mod ? u+v : u+v-mod;
                    a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                    w = ll (w * 1ll * wlen % mod);
                }
            }
        }
    }
    int main(){
        vector<ll> A0,A1,A2,Y;
        ll ans[M+2];
        ll n;
        cin>>n;
        ll d = 512*512;
        //Number multiple of two and ggreater than 2.5*10^5
     
        for(ll i=0;i<=n;i++){
            ll v;
            cin>>v;
            if(i%3==0) A0.push_back(v);
            else if(i%3==1) A1.push_back(v);
            else A2.push_back(v);
        }
     
        ans[0] = A0[0];
     
        for(ll i=n+1;i<786432;i++){
            if(i%3==0) A0.push_back(0);
            else if(i%3==1) A1.push_back(0);
            else A2.push_back(0);
        }
        ntt(A0);
        ntt(A1);
        ntt(A2);
     
        ll a2 = 10,a3 = 10*10;
        for(ll i=0;i<d;i++)
        {
            ll an =((ll)A0[i] + (((ll)A1[i]*power(a2,i))%M) + (((ll)A2[i]*power(a3,i))%M))%M;
            Y.push_back(an);
        }
        for(ll i=d;i<2*d;i++){
            ll an =((ll)A0[i-d] + (((ll)A1[i-d]*power(a2,i))%M) + (((ll)A2[i-d]*power(a3,i))%M))%M;
            Y.push_back(an);
        }
        for(ll i=2*d;i<3*d;i++){
            ll an =((ll)A0[i - 2*d] + (((ll)A1[i - 2*d]*power(a2,i))%M) + (((ll)A2[i - 2*d]*power(a3,i))%M))%M;
            Y.push_back(an);
        }
     
        for(ll i=0;i<(M-1);i++){
            ans[power(10,i)] = Y[i];
        }
        ll q;
        cin>>q;
        while(q--){
            ll v;
            cin>>v;
            cout<<ans[v]<<endl;
        }
    } 