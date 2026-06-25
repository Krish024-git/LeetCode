class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<bool> vec(nums.size(),false);
        vector<int> value;
        vector<int> freq;

        for(int i=0;i<nums.size();i++){
            int count=1;
            if(!vec[i]){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[i]==nums[j]){
                        count++;
                        vec[j] = true;
                    }
                }
                value.push_back(nums[i]);
                freq.push_back(count);

            }
        }

        vector<int> ans;

        for(int i=0;i<k;i++){
            int maxIndex = 0;
            for(int j=1;j<freq.size();j++){
                if(freq[j]>freq[maxIndex]){
                    maxIndex = j;
                }
            }
            ans.push_back(value[maxIndex]);
            freq[maxIndex] = -1;
        }
        return ans;
    }
};