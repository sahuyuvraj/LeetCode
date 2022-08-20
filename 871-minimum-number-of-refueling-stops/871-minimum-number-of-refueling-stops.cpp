class Solution {
public:
        int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int count=0; //will store our answer
        int maxWeCanReach=startFuel;
        int index=0;
        priority_queue<int>maxHeap; // to get station with maximum fuel 
        
        while(maxWeCanReach<target) //until we reach the target
        {
            
            //index<stations.size(): 
            //until we reach to the end
            
            //stations[index][0]<=maxWeCanReach:
            //we have traversed means we could have fueled our car if needed so put in queue
            while(index<stations.size() && stations[index][0]<=maxWeCanReach)
            {
                maxHeap.push(stations[index][1]);
                index++;
            }
            
            if(maxHeap.empty()) //no fuel stations but we have not reached yet and we can't now
                return -1;
            
            int getMaxFuel=maxHeap.top();
            maxHeap.pop();
            
            maxWeCanReach +=getMaxFuel;
            count++;
        }
        
        return count;
    }
};