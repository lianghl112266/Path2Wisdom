/**
 * 
 * 来自王道绿书算法章节图第一题P114
 * 
 * 这就是7月末数构强化结课考试里的题，思路一模一样，懒得再写一遍，参考代码在 DS\强化\5.cpp
 * 
 * 做法一：并查集
 * 判断遍历完的并查集数量，为1就是联通
 * 时间复杂度O(n+m*a(m))，空间复杂度O(max(n, m)), a(m)为一个增长缓慢的函数， 通常小于4
 * 
 * 做法二：广搜
 * 如果是一个连通集，那么一次遍历就可以访问全部节点
 * 时间复杂度O(n+m)，空间复杂度O(m)
 * 
 * 
 */