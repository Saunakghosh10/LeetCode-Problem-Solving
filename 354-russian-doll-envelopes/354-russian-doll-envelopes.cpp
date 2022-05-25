class Solution {
public:
    
    //nlogn dp
    
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        // sort on the basis of comparator
        // if first key are equal second key must be increasing order
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b)
             {
                 if(a[0]<b[0])
                     return true;
                 if(a[0]==b[0])
                     return a[1]>b[1];
                 return false;
             });
        
        int n = envelopes.size();
        
        vector<int> store;
        
        // start by pushing first height
        store.push_back(envelopes[0][1]);
        
        int length = 1;
        
        for(int i=1;i<n;i++)
        {
            // take lower bound with current height
            auto itr = lower_bound(store.begin(),store.end(),envelopes[i][1]);
            
            // if iterator is at it's end, we found the key contributing for increasing subsequence
            if(itr==store.end())
            {
                length++;
                store.push_back(envelopes[i][1]);
            }
            else
                *itr = envelopes[i][1];
        }
        
        return length;
        
        
    }
    
    // O(n^2) dynamic programming
    
    /*int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        // sort first to get the minimum width at the beginning first
        sort(envelopes.begin(),envelopes.end());
        
        int n = envelopes.size();
        
        // fill dp[i] = 1
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++)
        {
            int h1 = envelopes[i][0];
            int w1 = envelopes[i][1];
            for(int j=0;j<i;j++)
            {
                int h2 = envelopes[j][0];
                int w2 = envelopes[j][1];
                
                // find longest increasing subsequence upto current index 
                // satisfying the given condition
                if(h1>h2 and w1>w2)
                    dp[i] = max(dp[i],1+dp[j]);
            }
        }
        
        // return maximum element of the dp array
        return *max_element(dp.begin(),dp.end());
    }*/
};