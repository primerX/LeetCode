class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        int[] result = new int[2];

        for(int i = 0 ; i < nums.length; i++){
        	if(mp.containsKey(target - nums[i])){
        		result = new int[] {mp.get(target - nums[i]), i};
        		break;
        	}
        	else{
        		mp.put(nums[i], i);
        	}
        }

        return result;
    }
}