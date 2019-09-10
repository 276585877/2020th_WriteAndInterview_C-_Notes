﻿/***************************************
【题目】：
有一个长为n的数列a0, a1, ......, a(n-1)。请求出这个序列中最长的上升子序列的长度。
上升子序列指的是对于任意的i<j都满足ai<aj的子序列，
该问题被称为最长上升子序列（LIS，Longest Increasing Subsequence）的著名问题。
举个例子：给你一个序列为（1，5 ，2，6，9，10，3，15），那么它的最长上升子序列为：（1，2，6，9，10，15）
【思路】：
这个问题用DP的思想很容易解决，那么现在再来说一下DP（动态规划）的思想。
《https://blog.csdn.net/ltrbless/article/details/81318935》
***************************************/

/***************************************
一、DP思想：
1、把一个大的问题分解成一个一个的子问题。
2、如果得到了这些子问题的解，然后经过一定的处理，就可以得到原问题的解。
3、如果这些子问题与原问题有着结构相同，即小问题还可以继续的分解。
4、这样一直把大的问题一直分下去，问题的规模不断地减小，直到子问题小到不能再小，最终会得到最小子问题。
5、最小子问题的解显而易见，这样递推回去，就可以得到原问题的解。

二、DP的具体实现：
1、分析问题，得到状态转换方程（递推方程）。
2、根据状态转换方程，从原子问题开始，不断的向上求解，知道得到原问题的解。
3、在通过递推方程不断求解的过程，实际上是一个填表的过程。

举个2个栗子，让大家更好的理解DP的思想。
第一个栗子：//http://node2.vjmirror.rainng.com/contest/239734#problem/B
问题描述：给你一个有N（N是奇数 && 1<=N<=999999）个数的序列，
而且保证这N个数中有一个数M，它重复出现的  次数 >=（N + 1)/2 ，让你找出这个数M。
Sample Input:
5
1 3 2 3 3
Sample Output:
3
按照DP的思想，把这个大问题先分解成若干个小问题。所以呢当N为N时，至少有（N + 1）/ 2个M，另外的数就先不管他；
......然后当N为5得时候，依据题意那么一定至少有3个M，另外两个数就先不管他；
当N为3的时候，根据题意得，一定有2个数为M，另外一个数就先不管他；
当N为1的时候，那么这个数一定是M。
所以就可以把这个序列中得两个不同的数删去（只要有两个数不同就删去），最后剩下的一定是M；
即，M这个数出现的  次数 >=（N + 1)的一半，所以每次删除两个不同的数，剩下的一定是一个或两个数，一定是M。
举个栗子： 
intput: 9
        3 6 9 3 3 3 8 6 3
loc ：  1 2 3 4 5 6 7 8 9
1、2位置删去 3、4位置删去 6、7位置删去 8、9位置删去，，还剩一个5位置，那么5位置的 3 就是要找的M .


***************************************/

