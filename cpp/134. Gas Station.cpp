class Solution{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
		int tank = 0, start = 0, stored = 0;
		for(int i = 0; i < gas.size(); i++){
			// 油不够
			if((tank += gas[i] - cost[i]) < 0){
				// 这个时候起点应该从什么地方开始，是 start++ ？
		        // 稍微改改上面的示例：
		        //      A(3)
		        //  <4>/ \<3>
		        // (5)C - B(4)
		        //     <5>
		        // A 可以走到 B，但却无法走到 C，那么我在 B -> C 的时候发现 A 失败，应该从哪里开始？ B 吗？显然从 B 也是无法到 C 的。
		        // 因为，A 能到 B，此时的 store > 0，如果直接从 B 开始，store = 0，故，如果从 A 到 C 都不可能，显然从 B 到 C 也是不可能的。
		        // 所以此时，更聪明的方法是直接以 C 为起点。
				start = i+1;
				// 但此刻有个问题，我们的循环是按之前的起点来设计的，
				// 现在我们的起点变了，那么终点也会变，怎么能在有限的循环里，得知是否能走完一圈呢。
        		// 借用一下动态规划的技巧，由于是 circular route ,
        		// 那么开始的终点到现在的终点，所需要的油耗，恰恰等于开始的起点，
        		// 到新起点所需要的油耗。那么我们就不必重复计算了，积累上次计算结果即可。
				stored += tank;
				tank = 0;
			}
		}
		return (tank + stored) < 0 ? -1 : start;
	}
};

// leetcode 官方题解
class Solution {
  public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      // If one couldn't get here,
      if (curr_tank < 0) {
        // Pick up the next station as the starting one.
        starting_station = i + 1;
        // Start with an empty tank.
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
};