//Suen Man Ying S1123531 25Nov2024

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <sstream>  // Include this for stringstream (to process input lines)
using namespace std;

// Function to merge K sorted arrays using a Min-Heap (priority queue)
vector<int> mergeKSortedArrays(vector<vector<int>>& sortedArrays) {
    // Min-Heap to store elements as tuples (value, array index, element index)
    // The priority_queue will automatically order tuples based on the first element (value).
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

    // Step 1: Initialize the heap with the first element of each sorted array
    // Each element in the heap is a tuple: (value, arrayIndex, elementIndex)
    for (int i = 0; i < sortedArrays.size(); ++i) {
        // Only push elements to the heap if the array is non-empty
        if (!sortedArrays[i].empty()) {
            // Push the first element of each array with its array index and element index (0)
            minHeap.push(make_tuple(sortedArrays[i][0], i, 0)); 
        }
    }

    vector<int> result; // Vector to store the merged sorted array

    // Step 2: Process the heap until it is empty
    // We repeatedly extract the smallest element from the heap and add it to the result array
    while (!minHeap.empty()) {
        // Extract the smallest element from the heap (this is the tuple)
        auto current = minHeap.top(); // Get the smallest tuple
        minHeap.pop(); // Remove the smallest element from the heap

        // Extract the individual values from the tuple (value, arrayIndex, elementIndex)
        int value = get<0>(current);       // The value itself
        int arrayIndex = get<1>(current); // The index of the array the value came from
        int elementIndex = get<2>(current); // The index of the element within the array

        // Add the smallest value to the result array
        result.push_back(value);

        // Step 3: Insert the next element from the same array into the heap (if it exists)
        // After extracting an element from an array, we move to the next element in that array
        if (elementIndex + 1 < sortedArrays[arrayIndex].size()) {
            // Push the next element from the same array into the heap with updated indices
            minHeap.push(make_tuple(sortedArrays[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1));
        }
    }

    return result; // Return the final merged array
}

int main() {
    int K; // The number of sorted arrays
    cin >> K; // Read the number of arrays
    cin.ignore(); // Ignore the newline character left by cin

    vector<vector<int>> sortedArrays(K); // Vector to store the K sorted arrays

    // Input K sorted arrays
    for (int i = 0; i < K; ++i) {
        string line; // String to hold the input line for each array
        getline(cin, line); // Read the entire line (this will be the elements of the array)
        
        stringstream ss(line); // Create a stringstream from the input line to extract individual integers
        int n;
        // Parse each integer from the stringstream and add it to the corresponding sorted array
        while (ss >> n) {
            sortedArrays[i].push_back(n);
        }
    }

    // Call the function to merge K sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(sortedArrays);

    // Output the merged array
    cout << "Merged Array: [";
    // Print each element of the merged array
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        // Add commas between the elements except for the last one
        if (i != mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl; // End with a closing bracket for the merged array

    return 0; // End of the program
}
