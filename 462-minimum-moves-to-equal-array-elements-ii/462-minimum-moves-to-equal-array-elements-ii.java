class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;
        //Sort the array
        Arrays.sort(nums);
        
        //Find the median
        int median = n%2==0 ? (nums[n/2]+nums[n/2-1])/2 : nums[n/2];
        int steps = 0;
        
        //Calculate steps
        for(int num : nums) {
            steps += Math.abs(num-median);
        }
        
        return steps;
    }
}

