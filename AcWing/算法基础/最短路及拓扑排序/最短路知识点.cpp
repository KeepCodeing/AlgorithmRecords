最短路的难点
在于如何将问题转换为最短路模型，如何定义点和边 

稠密图和稀疏图：根据顶点数和边数区分，如果边点数大于顶点数，则一般
为稠密图，相反为稀疏图 

单源最短路
Dijkstra算法的朴素版时间复杂度为O(n^2)，堆优化版的时间复杂度为
O(mlogn)，这也就是说稠密图用朴素版时间复杂度更优秀，而稀疏图用
堆优化版更好

存在负权边的单源最短路 
有Bellman-Ford算法和SPFA算法，一般来说Bellman-Ford时间复杂度是
O(nm)，SPFA的时间复杂度是O(m)，但是可能退化到O(nm)的复杂度 

多源最短路
只有Floyd算法，时间复杂度为O(n^3) 
