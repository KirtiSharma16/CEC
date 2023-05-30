#include<bits/stdc++.h>
using namespace std;
class Minheap{
private:
    vector<int> v;
    int maxsize, currsize;
public:
    Minheap(int cap){
        v.resize(cap);
        maxsize=cap;
        currsize=0;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    void insertKey(int key){
        if(currsize==maxsize) return;
        v[currsize]=key;
        currsize++;
        int i=currsize-1;
        while(i!=0 && v[parent(i)]>v[i]){
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
    }
    void decreaseKey(int i,int key){
        v[i]=key;
        while(i!=0 && v[parent(i)]>v[i]){
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
    }
    int getMin(){
        return v[0];
    }
    int extractMin(){
        if(currsize<=0) return INT_MAX;
        if(currsize==1){
            currsize--;
            return v[0];
        }
        int ans=v[0];
        v[0]=v[currsize-1];
        currsize--;
        minheapify(0);
        return ans;
    }
    void minheapify(int i){
        int l=left(i);
        int r=left(i);
        int smallest=i;
        if(l<currsize && v[l]<v[i]) smallest=l;
        if(r<currsize && v[r]<v[smallest]) smallest=r;
        if(smallest!=i){
            swap(v[i],v[smallest]);
            minheapify(smallest);
        }
    }
    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }
};
int main()
{
    Minheap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
