
int g(int i){
	return a[i];
}
int binarysearch(int k,int l,int r){
	r--,r++;
	while(l<r){
		int m=(l>>1)+(r>>1)+(l&r&1);
		if(g(m)<k){
			l=m;
		}
		else{
			r=m;
		}
	}
	return r;
}
