#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int mx = 0;
    int mn = 0;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            mn = i;
        }
        else if (temp == n)
        {
            mx = i;
        }
        v.pb(temp);
    }

    int absmx = min(mx, n - mx - 1);
    int absmn = min(mn, n - mn - 1);
    int sol = 0;

    if (absmx <= absmn)
    {
        sol += (absmx + 1);

        if (absmx != mx)
        {
            for (int i = 0; i <= absmx; i++)
            {
                v.pop_back();
            }
        }
        else
        {
            v.erase(v.begin(), v.begin() + absmx + 1);
        }

        int newmn = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < v[newmn])
            {
                newmn = i;
            }
        }

        int newabsmn = min(newmn, (int)v.size() - newmn - 1);
        sol += newabsmn + 1;
    }
    else
    {
        sol += (absmn + 1);

        if (absmn != mn)
        {
            for (int i = 0; i <= absmn; i++)
            {
                v.pop_back();
            }
        }
        else
        {
            v.erase(v.begin(), v.begin() + absmn + 1);
        }

        int newmx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > v[newmx])
            {
                newmx = i;
            }
                            //cout << v[newmx] << endl;

        }
        int newabsmx = min(newmx, (int)v.size() - newmx - 1);
        sol += newabsmx + 1;
    }

    
    cout << sol << endl;

    /*
  if(mx >= n/2 && mn >= n/2){
      cout << n-min(mx, mn) << endl;

  }
  else if(mx <= n/2 && mn <= n/2){
      cout << max(mx, mn)+1 << endl;
  }
  else if(mx >= n/2 && mn <= n/2){
      cout << (n-mx) + mn + 1<< endl;
  }
  else{
      cout << (n-mn) + mx + 1<< endl;
  }
  */
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
}