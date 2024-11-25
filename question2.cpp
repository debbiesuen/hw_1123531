//Suen Man Ying S1123531 25Nov2024

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string name;     // Task name
    int priority;    // Task priority

    // Constructor to initialize a task
    Task(string task_name, int task_priority) : name(task_name), priority(task_priority) {}

    // Overload the < operator to ensure max-heap behavior
    // Higher priority tasks should appear earlier in the queue
    bool operator<(const Task& other) const {
        return priority < other.priority; // Larger priority = Higher rank in the heap
    }
};

// TaskPriorityQueue class to manage the task queue
class TaskPriorityQueue {
private:
    priority_queue<Task> max_heap; // Max-heap to store tasks based on priority

public:
    // Add a task to the queue
    void add_task(const string& task_name, int priority) {
        max_heap.push(Task(task_name, priority)); // Push the new task into the heap
    }

    // Retrieve and remove the highest-priority task
    string get_highest_priority_task() {
        if (!max_heap.empty()) {
            Task top_task = max_heap.top(); // Get the task with the highest priority
            max_heap.pop();                 // Remove it from the heap
            return top_task.name;           // Return the task name
        }
        return ""; // Return empty string if the heap is empty
    }

    // Display remaining tasks in descending order of priority
    vector<pair<string, int>> display_remaining_tasks() {
        vector<pair<string, int>> tasks;
        priority_queue<Task> temp_heap = max_heap; // Create a temporary copy of the heap

        // Iterate over the heap and extract tasks
        while (!temp_heap.empty()) {
            Task task = temp_heap.top(); // Get the highest-priority task
            tasks.push_back({task.name, task.priority}); // Add task to the result list
            temp_heap.pop(); // Remove the task from the temporary heap
        }

        return tasks; // Return the list of tasks sorted by priority
    }
};

int main() {
    int N; // Number of operations to process
    cin >> N;

    TaskPriorityQueue queue; // Create an instance of TaskPriorityQueue

    // Process each operation
    for (int i = 0; i < N; ++i) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            string task_name;
            int priority;
            cin >> task_name >> priority; // Read task name and priority
            queue.add_task(task_name, priority); // Add the task to the priority queue
        } else if (operation == "GET") {
            string highest_priority_task = queue.get_highest_priority_task(); // Fetch the top task
            if (!highest_priority_task.empty()) {
                cout << highest_priority_task << endl; // Print the task name
            }
        }
    }

    // Display the remaining tasks at the end
    vector<pair<string, int>> remaining_tasks = queue.display_remaining_tasks();

    cout << "Remaining tasks: ";
    cout << "[";
    for (size_t i = 0; i < remaining_tasks.size(); ++i) {
        // Print each task as ('TaskName', Priority)
        cout << "('" << remaining_tasks[i].first << "', " << remaining_tasks[i].second << ")";
        if (i != remaining_tasks.size() - 1) cout << ", "; // Add a comma except for the last task
    }
    cout << "]" << endl;

    return 0;
}
