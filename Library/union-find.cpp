void init(int n){
  REP(i, 0, n){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y){
    return;
  }

  if(rank[x] < rank[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(rank[x] == rank[y]){
      rank[x]++;
    }
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}
