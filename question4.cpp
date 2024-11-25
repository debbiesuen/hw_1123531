//Suen Man Ying S1123531 25Nov2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Structure to represent a task
struct Task {
    int profit;    // Profit of the task
    int deadline;  // Deadline of the task (1-based index)
    
    // Constructor to initialize the task
    Task(int p, int d) : profit(p), deadline(d) {}
};

// Comparator for the max-heap (priority queue) to prioritize tasks with higher profit
struct CompareProfit {
    bool operator()(const Task& t1, const Task& t2) {
        return t1.profit < t2.profit;  // If profit of t1 is less than t2, t1 will be prioritized lower
    }
};

// Function to find the maximum profit and schedule tasks
pair<int, vector<int>> scheduleTasks(vector<Task>& tasks) {
    // Step 1: Sort tasks by profit in descending order
    sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
        return t1.profit > t2.profit;  // Sorting by profit in decreasing order
    });

    // Step 2: Find the maximum deadline to know the number of slots
    int maxDeadline = 0;
    for (const Task& t : tasks) {
        maxDeadline = max(maxDeadline, t.deadline); // Find the maximum deadline
    }

    // Step 3: Initialize an array to track which slots are already taken
    vector<bool> slots(maxDeadline, false);  // Array to keep track of available slots
    vector<int> scheduledTasks;  // Store the profit of tasks that are scheduled

    int totalProfit = 0;  // Variable to store the total profit

    // Step 4: Iterate through the tasks and try to schedule them
    for (const Task& currentTask : tasks) {
        // Try to find an available slot for the current task, starting from the latest slot before its deadline
        for (int j = currentTask.deadline - 1; j >= 0; j--) {
            if (!slots[j]) {  // If slot is available
                slots[j] = true;  // Mark the slot as taken
                totalProfit += currentTask.profit;  // Add the profit to total profit
                scheduledTasks.push_back(currentTask.profit);  // Add task's profit to scheduled tasks list
                break;  // Exit once the task is scheduled
            }
        }
    }

    return {totalProfit, scheduledTasks};  // Return the total profit and list of scheduled tasks
}

int main() {
    int N;  // Number of tasks
    cin >> N;  // Input the number of tasks

    vector<Task> tasks;

    // Input N tasks with their profit and deadline
    for (int i = 0; i < N; i++) {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.push_back(Task(profit, deadline));  // Add the task to the list
    }

    // Call the function to schedule tasks and calculate the maximum profit
    pair<int, vector<int>> result = scheduleTasks(tasks);

    // Output the result: maximum profit and the list of scheduled tasks
    cout << "Maximum Profit: " << result.first << endl;  // Print the total maximum profit
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < result.second.size(); ++i) {
        cout << result.second[i];
        if (i != result.second.size() - 1) cout << ", ";  // Print comma between values
    }
    cout << "]" << endl;  // End the list with a closing bracket

    return 0;  // Return 0 to indicate successful execution
}
