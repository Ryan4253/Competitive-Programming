int in[1505];

void initialize(int n){
    for(int i=0;i<n;i++)
        in[i] = i;
}
int hasEdge(int a, int b){
    if(a > b){
    	if(in[a] == 1){
    		return 1;
    	}
    	else{
    		in[a]--;
    		return 0;
    	}
    }
    else{
    	if(in[b] == 1){
    		return 1;
    	}
    	else{
    		in[b]--;
    		return 0;
    	}
    }
}