任务调度：
	当处理器空闲时，将目前用时最少的Job推给处理器处理：这个Job将在5s进行运行，一旦在5ms没有完成，则变为下一轮调度表的候选。

Job包含以下的几个域：
	jobID: Unique
	executed_time: has been scheduled so far
	total_time: remaing time to complete is "total_time-executed_time"

所有的时间都是以ms为单位。

调度表的要求：
	1. 将最少执行时间的Job推到处理器运行
	2. 给定一个jobID，能打印三元组(jobID,executed_time,total_time)
	3. 给定jobID的范围[low, high]，打印这其中所有的三元组(jobID,executed_time,total_time)
	4. 给定一个jobID，能打印出比给定jobID大的最小的三元组(jobID,executed_time,total_time)
	5. 给定一个jobID，能打印比给定jobID小的最大的三元组(jobID,executed_time,total_time)
	6. 能将一个新的job插入到堆和红黑树中

为了完成调度工作，必须使用最小堆和红黑树。最小堆用于executed_time，红黑树用于jobID。需要维护一个在最小堆和红黑树节点间对应关系的指针。最小堆的最大尺寸位置，在当前容量不够时要采用array doubling

在运行完成以个job后应该移除这个job，否则将其executed_time加5ms

编程环境：C++/Java，需要在服务器thunder.cise.ufl.edu上运行

提交需要包含jobscheduler.makefile和源程序

输入格式：
	Insert(jobID,total_time)
	PrintJob(jobID)
	PrintJob(jobID1,jobID2)
	NextJob(jobID)
	PreviousJob(jobID)

必须在job完成时添加新的job

样例输入：
0: Insert(5,25)
2: Insert(9,30)
7: Insert(30,3)
9: PrintJob(30)
10: Insert(1345,12)
13: PrintJob(10,300)
14: Insert(3455,14)
17: NextJob(30)
31: PreviousJob(345)
39: Insert(4455,14)
50: PrintJob(1,5000)


0: Insert(50,60000)
49950: Insert(19,55000)
99950: Insert(30,58000)
125900: PrintJob(19)
199500: Insert(1250,47000)
229500: Insert(1350,37000)
230000: PrintJob(30,5200)
235000: NextJob(1350)
236000: PreviousJob(1350)

(19,49975,55000)
(1250,30000,47000),(1350,500,37000)
(0,0,0)
(1250,30000,47000)

第一个数字是全局时间。有一个从0开始计时的全局时间计时器（需要模拟时间）。

PirntJob, NextJob, PreviousJob需要在O(log(n))的复杂度完成（最小堆）

printJob(jobID1, jobID2)需要在O(log(n)+S)完成: 找到(jobID1, jobID2)的最高节点，然后中序遍历该节点（节点id在范围内才进一步递归，否则结束）

输出格式： "output_file.txt"
	如果存在则输出三元组，否则输出(0,0,0)

需要撰写报报

注意：
	1. 不要用复杂的数据结构。即，需要自己实现最小堆和红黑树。同时，不允许使用任何Map相关的库
	2. 所有的代码需要自己编写。会有查重！

最小堆：
	使用数组，那么下标从0开始，父节点是i，则左子树是2*i+1，右子树是2*i+2。如果子节点是i，则父节点是（i-1)/2。
	最小堆的操作主要有两个，一个是add，思路是，新建一个节点在最后，然后不断地和父节点比较，如果小于父节点，就交换，直到大于等于或者root。
	第二个操作是输出root，那么需要把最后一个节点移至root位置，然后重新梳理最小堆，因为此时可能不再是最小堆了，梳理过程用函数modify实现。该函数的实现思路是传入一个i参数，表明以i为根的子树需要梳理，然后让i和比i小的子节点中的较小值交换，再递归地梳理被交换的节点。

红黑树：https://blog.csdn.net/sun_tttt/article/details/65445754
	1. 节点是红色或者是黑色
	2. 根节点是黑色
	3. 每个叶节点（NIL或空节点）是黑色
	4. 每个红色节点的两个子节点都是黑色的（也就是说不存在两个连续的红色节点）
	5. 从任一节点到其没个叶节点的所有路径都包含相同数目的黑色节点

