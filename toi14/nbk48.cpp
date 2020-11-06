#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// total watch: x episode
// total cost: y baht
struct EPCost {
  int ep;
  int cost;
};

int n, q;
vector<int> ps, qm;
vector<struct EPCost> epcs;

bool compare(struct EPCost l, struct EPCost r) {
  return l.cost < r.cost;
}

int findMaxEp(int x) {
  int l=0, r=epcs.size()-1;
  int index=0;
  while(l<=r) {
    int mid = (l+r)/2;
    if(x>=epcs[mid].cost) {
      index = mid;
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  return qm[index];
}

int main() {
  cin >> n >> q;

  // Episode Prices
  for(int i=0; i<n; i++) {
    int p;
    cin >> p;
    ps.push_back(p);
  }

  // Initial Episode Cost
  // total watch: 0 episodes
  // total cost: 0 baht
  struct EPCost iepc;
  iepc.ep = 0;
  iepc.cost = 0;
  epcs.push_back(iepc);

  // Quick Sum Episode Prices
  int sum=0;
  for(int i=0; i<ps.size(); i++) {
    sum+=ps[i];
    struct EPCost epc;
    epc.ep = i+1;
    epc.cost = sum;
    epcs.push_back(epc);
  }

  sort(epcs.begin(), epcs.end(), compare);


  // Quick Max of episodes
  // pay: x bath
  // max episodes available: y episodes
  int eps = epcs[0].ep;
  for(int i=0; i<epcs.size(); i++) {
    eps = max(epcs[i].ep, eps);
    qm.push_back(eps);
  }

  // Pay and Available episodes Log
  // for(int i=0; i<qm.size(); i++) {
  //   // cout << epcs[i].ep << " " << qm[i] << endl;
  //   cout << "pay: " << epcs[i].cost << endl;
  //   cout << "watch: " << epcs[i].ep << endl;
  //   cout << "real: " << qm[i] << endl;
  //   cout << endl;
  // }

  // Questions
  for(int i=0; i<q; i++) {
    int x;
    cin >> x;
    cout << findMaxEp(x) << endl;
  }
  return 0;
}