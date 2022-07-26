/*
 * @lc app=leetcode.cn id=2350 lang=cpp
 *
 * [2350] 不可能得到的最短骰子序列
 *
 * https://leetcode.cn/problems/shortest-impossible-sequence-of-rolls/description/
 *
 * algorithms
 * Hard (62.81%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 5.3K
 * Testcase Example:  '[4,2,1,2,3,3,2,4,1]\n4'
 *
 * 给你一个长度为 n 的整数数组 rolls 和一个整数 k 。你扔一个 k 面的骰子 n 次，骰子的每个面分别是 1 到 k ，其中第 i
 * 次扔得到的数字是 rolls[i] 。
 * 
 * 请你返回 无法 从 rolls 中得到的 最短 骰子子序列的长度。
 * 
 * 扔一个 k 面的骰子 len 次得到的是一个长度为 len 的 骰子子序列 。
 * 
 * 注意 ，子序列只需要保持在原数组中的顺序，不需要连续。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：rolls = [4,2,1,2,3,3,2,4,1], k = 4
 * 输出：3
 * 解释：所有长度为 1 的骰子子序列 [1] ，[2] ，[3] ，[4] 都可以从原数组中得到。
 * 所有长度为 2 的骰子子序列 [1, 1] ，[1, 2] ，... ，[4, 4] 都可以从原数组中得到。
 * 子序列 [1, 4, 2] 无法从原数组中得到，所以我们返回 3 。
 * 还有别的子序列也无法从原数组中得到。
 * 
 * 示例 2：
 * 
 * 
 * 输入：rolls = [1,1,2,2], k = 2
 * 输出：2
 * 解释：所有长度为 1 的子序列 [1] ，[2] 都可以从原数组中得到。
 * 子序列 [2, 1] 无法从原数组中得到，所以我们返回 2 。
 * 还有别的子序列也无法从原数组中得到，但 [2, 1] 是最短的子序列。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：rolls = [1,1,3,2,2,2,3,3], k = 4
 * 输出：1
 * 解释：子序列 [4] 无法从原数组中得到，所以我们返回 1 。
 * 还有别的子序列也无法从原数组中得到，但 [4] 是最短的子序列。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == rolls.length
 * 1 <= n <= 10^5
 * 1 <= rolls[i] <= k <= 10^5
 * 
 * 
 */
	
// 1960 分

// 贪心的思路
// 想不到的点:当遇到一个数, 如果累计的数量比答案小,那么可以记上,然后如果记全了,就答案+1;
// 当 某一级答案没记录全的时候, 可以忽略下一级的答案

// 220914 回归通过, 想的是用unordered_set 存, 存满了就答案加1

// @lc code=start
class Solution {
    
public:
    // int shortestSequence(vector<int>& rolls, int k) {
    //     int result = 1;
    //     int left = k;
    //     vector<int> ki(k + 1);
    //     for(int i = 0; i < rolls.size(); i++){
    //         if(ki[rolls[i]] < result){
    //             ki[rolls[i]] = result;
    //             if(--left == 0){
    //                 left = k;
    //                 result++;
    //             }
    //         }
    //     }
    //     return result;
    // }
    int shortestSequence(vector<int>& rolls, int k) {
        int result = 1;
        unordered_set<int> us;
        for(int i = 0; i < rolls.size(); i++){
            us.insert(rolls[i]);
            if(us.size() == k){
                result++;
                us.clear();
            }
        }
        return result;
    }
};
// @lc code=end

