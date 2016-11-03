void init(int n){
  REP(i, 0, n){
    par[i] = i;
    rnk[i] = 0;
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

  if(rnk[x] < rnk[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(rnk[x] == rnk[y]){
      rnk[x]++;
    }
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}
