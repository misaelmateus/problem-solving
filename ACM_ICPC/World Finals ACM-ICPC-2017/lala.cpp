    #include <iostream>
    using namespace std;
     
    int main(){
    	int n;
        string s,g;
        cin>>n>>s>>g;
    	int ponto=0;
    	for(int i=0;i<n;i++){
    		if(s[i]== g[i])
    			ponto++;
    	}
    	cout<<ponto<<endl;
    	return 0;
    }