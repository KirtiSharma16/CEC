class Solution
{
    private:
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    public:
  // creating max heap to sort in ascending order
    void heapify(int arr[], int n, int i)  
    {
      int largest=i;
      int l=left(i);
      int r=right(i);
      if(l<n && arr[l]>arr[i]) largest=l;
      if(r<n && arr[r]>arr[largest]) largest=r;
      if(largest!=i){
          swap(arr[i],arr[largest]);
          heapify(arr,n,largest);
      }
    }

    public:
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};
