class Solution {
public:
    
    int partition(int low,int high,int pivot_index,vector<int>&arr)
    {  
       
        int pivot=arr[pivot_index];
        swap(arr[high],arr[pivot_index]);
        
        int store_index=low;

        for(int i=low;i < high;i++)
        {
            if(arr[i] < pivot)
            {
                swap(arr[i],arr[store_index]);
                store_index++;
            }
        }

       swap(arr[high],arr[store_index]);
       return store_index;
    }
   
    int findKthLargest(vector<int>& arr, int k)
    {  
       int low=0;
       int high=arr.size()-1;
       int n=arr.size();

       while(true)
       {
          int pivot_index=rand()%(high-low+1)+low;
          int new_pivot=partition(low,high,pivot_index,arr);

          if(new_pivot==(n-k))return arr[new_pivot];
          else if(new_pivot > n-k)
            high=new_pivot-1;
          else
            low=new_pivot+1;
       }
    }

};