Question 1: Binary Tree - Find the Diameter of a Binary Tree
Problem Statement:
Write a program to calculate the diameter of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root.
You are required to:
Build the binary tree using level-order input. Use -1 to represent null nodes.
Implement a function to calculate the diameter of the binary tree efficiently using recursion.

Input:
[1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1]

Output:
3





Question 2: Heap Sort - Build a Priority Queue for Tasks
Problem Statement:
Write a program to manage a task priority queue using a max heap. Each task has a name and a priority level. Your program should allow:
Add a Task: Add a task with a given priority.
Get the Highest Priority Task: Remove and return the task with the highest priority.
Display the Remaining Tasks: Print the remaining tasks in descending order of priority.

Input:
6
ADD TaskA 15
ADD TaskB 10
ADD TaskC 20
GET
ADD TaskD 5
GET

Output:
TaskC
TaskA
Remaining tasks: [('TaskB', 10), ('TaskD', 5)]





Question 3: Merge K Sorted Arrays Using Min Priority Queue
You are given K sorted arrays of integers. Write a Python program to merge these arrays into a single sorted array using a Min Priority Queue.
Your program should:
Insert the first element of each array into a Min Priority Queue along with the array index and element index.
Extract the smallest element from the queue, add it to the result array, and insert the next element from the same array into the queue.
Continue this process until all elements from all arrays are merged.

Input:
4
10 20 30
5 15 25 35
1 7 13
2 12 22 32

Output:
Merged Array: [1, 2, 5, 7, 10, 12, 13, 15, 20, 22, 25, 30, 32, 35]





Question 4: Schedule Tasks with Deadlines Using Max Priority Queue
You are given N tasks, each with a profit and a deadline. Write a Python program to schedule the tasks such that the maximum profit is achieved, using a Max Priority Queue.
Each task must be completed within its deadline (1-based index), and only one task can be scheduled at a time.

Input
5
50 3
60 1
70 2
80 1
90 3

Output
Maximum Profit: 240
Scheduled Tasks: [90, 80, 70]



