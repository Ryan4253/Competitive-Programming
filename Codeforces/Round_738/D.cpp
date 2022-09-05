#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first;
#define S second;

struct Disjoint_Set{
	vector<int> p;
	vector<int> sz;
	int size;
	int setcnt;

	/**
     * @brief Constructs the disjoint set
	 * @param n the size of the disjoint set
     */
	Disjoint_Set(int n){
		size = n;
		p.resize(size);
		sz.resize(size);
		initialize();
	}

    /**
     * @brief initializes the disjoint set. Every element starts in their individual group
     */
	void initialize(){
		setcnt = size;
		for(int i = 0; i < size; i++){
			p[i] = i;
		}
		fill(sz.begin(), sz.end(), 1);
	}

    /**
     * @brief finds the set the index is in
     * @param index the index to search
	 * @return the parent of the set
     */
	int find(int index){
		if(p[index] == index){
			return index;
		}
		else{
			return p[index] = find(p[index]);
		}
	}

	/**
     * @brief returns the number of sets
     */
	int getSetCnt(){
		return setcnt;
	}

	/**
     * @brief returns the number of elements in a given set
	 * @param index one element of the given set
     */
	int getSetSize(int index){
		return sz[find(index)];
	}

    /**
     * @brief merges two sets
     * @param a, b elements of the two sets to merge
     */    
	void merge(int a, int b){
		if(find(a) != find(b)){
			sz[find(b)] += sz[find(a)];
			setcnt--;
			p[find(a)] = find(b);
		}
	}
};

Disjoint_Set mocha(1005);
Disjoint_Set diana(1005);

void solve(){
    int n, m1, m2; cin >> n >> m1 >> m2;
    mocha.initialize();
    diana.initialize();

    for(int i = 0; i < m1; i++){
        int x, y; cin >> x >> y;
        mocha.merge(x, y);
    }

    for(int j = 0; j < m2; j++){
        int x, y; cin >> x >> y;
        diana.merge(x, y);
    }

    vector<pii> sol;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((mocha.find(i) != mocha.find(j)) && (diana.find(i) != diana.find(j))){
                sol.pb(mp(i, j));
            }
        }
    }


    cout << sol.size() << endl;
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i].first << " " << sol[i].second << endl;
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1;
  while(n--){
    solve();
  }
}