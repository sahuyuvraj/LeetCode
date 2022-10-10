//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    unordered_map<int,int>mp;
    vector<int>v;
    int count;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        count=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        auto it=find(v.begin(),v.end(),key);
        if(it!=v.end()){
            v.erase(it);
            v.push_back(key);
            return mp[key];
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here  
        auto it=find(v.begin(),v.end(),key);
      
        if(it!=v.end()){
            v.erase(it);
            v.push_back(key);
             mp[key]=value;
        }else{
            if(count==0){
                v.erase(v.begin());
                v.push_back(key);
                mp[key]=value;
            }else{
                v.push_back(key);
                mp[key]=value;
                count--;
            }
        }
     
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends