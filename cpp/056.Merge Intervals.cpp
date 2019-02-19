/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	static bool cmp(const Interval &lhs, const Interval &rhs){
		if(lhs.start != rhs.start){
			return lhs.start < rhs.start;
		}else{
			return lhs.end < rhs.end;
		}
	}

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size() == 0) return ans;
        // 对所有区间按左区间从小到大排序
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
        	if(ans.back().end < intervals[i].start){
        		ans.push_back(intervals[i]);
        	}else{
        		ans.back().end = max(ans.back().end, intervals[i].end);
        	}
        }
        return ans;
    }
};