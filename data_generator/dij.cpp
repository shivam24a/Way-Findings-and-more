#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool b[1005];
vector<vector<pair<ll,ll> > > vc(1005);
vector<vector<ll>> par(1005);
ll dis[1005][1005];
ll tr[1005];
void dij(ll i){
	dis[i][i]=0;
	// ll pr=i;
	tr[i]=i;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > pq;
	pq.push({0,i});
	while(!pq.empty()) {
		ll el= pq.top().second;
		pq.pop();
		if(b[el]) continue;
		b[el]=1;
		par[i][el]=tr[el];
		// pr=el;
		// cout<<el<<"_";
		for(auto elem:vc[el]) {
			if(dis[i][elem.first]>dis[i][el]+elem.second) {
				dis[i][elem.first]=dis[i][el]+elem.second;
				pq.push({dis[i][elem.first],elem.first});
				tr[elem.first]=el;
			}
		}
	}
}

ll path_tracer(ll fr,ll to){
	while(fr!=to){
		cout<<to<<" ";
		to=par[fr][to];
	}
	return 0;
}

int main(){
	freopen("input_data.txt","r",stdin);
	for(ll i=0;i<1005;i++)for(ll j=0;j<1005;j++)par[i].push_back(0),dis[i][j]=1e18;
	ll n,x,y,w;
	cin>>n;
	for(ll i=0; i<n; i++) {
		cin>>x>>y>>w;
		vc[x].push_back({y,w});
		vc[y].push_back({x,w});
	}

	for(ll i=1;i<37;i++){
		dij(i);memset(b,0,sizeof(b)),memset(tr,0,sizeof(tr));
	}
	// for(ll i=1;i<6;i++){
	// 	for(ll j=0;j<6;j++)cout<<i<<" "<<j<<" : "<<par[i][j]<<"_"<<dis[i][j]<<"\n";cout<<"\n";
	// }
	cout<<"___";
	// path_tracer(2,5);
	cout<<18<<" "<<26<<" "<<dis[18][26]<<"\n";
	cout<<18<<" "<<36<<" "<<dis[18][36]<<"\n";



}
