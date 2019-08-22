class Solution {
    public int lengthOfLongestSubstring(String s) {
    	// maxlen 用来记录子串的最大长度
    	// pos 用来记录最后一个重复字符的位置, 初始为 0
        int maxlen = 0, pos = 0;
        // index 数组表示当前字符的索引
        int[] index = new int[128];

        for(int i = 0; i < s.length(); i++){
        	pos = Math.max(index[s.charAt(i)], pos);
        	maxlen = Math.max(maxlen, i - pos + 1);
        	index[s.charAt(i)] = i + 1;
        }
        return maxlen;
    }
}