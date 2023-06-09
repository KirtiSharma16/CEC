class Solution{
private:
        vector<int> fun(string &s){
            int n=s.size();
            vector<int> z(n);
            int l=0, r=0,k;
            for(int i=1;i<n;i++){
                if(i>r){
                    l=r=i;
                    while(r<n && s[r-l]==s[r]) r++;
                    z[i]=r-l;
                    r--;
                }
                else{
                    k=i-l;
                    if(z[k]<r-i+1) z[i]=z[k];
                    else{
                        l=i;
                        while(r<n && s[r-l]==s[r]) r++;
                        z[i]=r-l;
                        r--;
                    }
                }
            }
            return z;
        }
  public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string temp=pat+"$"+txt;
            vector<int> z=fun(temp);
            vector<int> res;
            int n=z.size();
            for(int i=0;i<n;i++){
                if(z[i]==pat.size()){
                    res.push_back(i-pat.size());
                }
            }
            if(res.size()==0) return {-1};
            return res;
        }
};
