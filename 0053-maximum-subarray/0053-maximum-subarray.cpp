class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum=nums[0];
        int maxSum=nums[0];

        for (int i=1;i<nums.size();i++){
            currentSum= max(nums[i],currentSum+nums[i]);
            maxSum = max(maxSum,currentSum);
        }
        return maxSum;
        // int maxSum= INT_MIN;

        // for(int i=0;i<nums.size();i++){
        //     int sum =0;
        //     for(int j=i; j<nums.size();j++){
        //         sum +=nums[j];
        //         maxSum = max(maxSum,sum);
        //     }
        // }
        // return maxSum;
    }
};