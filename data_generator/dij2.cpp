#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool b[1005];
vector<vector<ll > > vc(1005);
ll d[1005][1005],par[1005][1005];
ll dis[1005][1005],tr[1005];

void dij(ll i){
	dis[i][i]=0;
	tr[i]=i;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	pq.push({0,i});
	while(!pq.empty()) {
		ll el= pq.top().second;
		pq.pop();
		if(b[el]) continue;
		b[el]=1;
		par[i][el]=tr[el];
		for(auto elem:vc[el]) {
			if(dis[i][elem]>dis[i][el]+d[el][elem]) {
				dis[i][elem]=dis[i][el]+d[el][elem];
				pq.push({dis[i][elem],elem});
				tr[elem]=el;
			}
		}
	}
}

bool path_tracer(ll fr,ll to){
	to=par[fr][to];
	if(to==0) return 0;
	while(fr!=to) {
		cout<<to<<" ";
		to=par[fr][to];
	}
	return 1;
}
int main(){
	freopen("input_data.txt","r",stdin);
	freopen("data.json","w",stdout);
	for(ll i=0; i<1005; i++) for(ll j=0; j<1005; j++) dis[i][j]=1e18;
	ll n,x,y,w;
	cin>>n;
	for(ll i=0; i<n; i++) {
		cin>>x>>y>>w;
		vc[x].push_back(y);
		vc[y].push_back(x);
		d[x][y]=w,d[y][x]=w;
	}

	for(ll i=1; i<=n; i++) {
		dij(i), memset(b,0,sizeof(b)),memset(tr,0,sizeof(tr));
	}


	// JSON File writer from input_data.txt to data.json
	cout<<"{\n";
	cout<<"\"dis\":[ ";
	for(ll i=0; i<37; i++) {
		cout<<"[ ";
		for(ll j=0; j<37; j++) {
			cout<<dis[i][j]<<" ,";
		}
		cout<<dis[i][37]<<" ],\n";
	}
	cout<<"[ ";
	for(ll j=0; j<37; j++) {
		cout<<dis[37][j]<<", ";
	}
	cout<<dis[37][37]<<" ] ]\n";

		cout<<",\"par\":[ ";
	for(ll i=0; i<37; i++) {
		cout<<"[ ";
		for(ll j=0; j<37; j++) {
			cout<<par[i][j]<<" ,";
		}
		cout<<par[i][37]<<" ],\n";
	}
	cout<<"[ ";
	for(ll j=0; j<37; j++) {
		cout<<par[37][j]<<", ";
	}
	cout<<par[37][37]<<" ] ]\n";
	// cout<<"___";
	// path_tracer(1,14);
	cout<<"}";


}

