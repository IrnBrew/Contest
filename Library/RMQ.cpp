const int MAX_N = 1 << 17;

int n, dat[2 * MAX_N - 1];

void init(int n_){
  n = 1;
  while(n < n_){
    n *= 2;
  }
  for(int i = 0; i < 2 * n - 1; i++){
    dat[i] = LIM_INF;
  }
  return;
}

void update(int k, int a){
  //target node
  k += n - 1;

  //update node
  dat[k] = a;

  //update by climbing up the tree
  while(k > 0){
    k = (k - 1) / 2;
    dat[k] = min(dat[k*2+1], dat[k*2+2]);
  }
}

//the latter three variables are for utility.
//call this function outside by query_(a, b, 0, 0, n) or query(a, b)
int query_(int a, int b, int k, int l, int r){
  if(r < a || l > b){
    return LIM_INF;
  }
  if(a <= l && b <= r){
    return dat[k];
  } else {
    int vl = query_(a, b, k*2+1, l, (l + r) / 2);
    int vr = query_(a, b, k*2+2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

//wrapper function
int query(int a, int b){
  return query_(a, b, 0, 0, n);
}
