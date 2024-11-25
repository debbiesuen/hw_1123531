//Suen Man Ying S1123531 25Nov2024

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Definition of the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from the given level-order traversal
TreeNode* buildTree(const vector<int>& data) {
    if (data.empty()) return nullptr;  // If the input data is empty, return null

    // Initialize the root node with the first element in the array
    TreeNode* root = new TreeNode(data[0]);
    
    // Queue to store nodes for level-order traversal
    queue<TreeNode*> q;
    q.push(root);
    int i = 1; // Start from the second element in the array
    
    // Loop to construct the tree based on level-order input
    while (i < data.size()) {
        TreeNode* current = q.front(); // Get the front node of the queue
        q.pop();  // Remove it from the queue

        // If the next value is not -1, it means we have a left child for the current node
        if (data[i] != -1) {
            current->left = new TreeNode(data[i]);
            q.push(current->left);  // Add the left child to the queue
        }
        i++;  // Move to the next element in the data array

        // If the next value is not -1, it means we have a right child for the current node
        if (i < data.size() && data[i] != -1) {
            current->right = new TreeNode(data[i]);
            q.push(current->right);  // Add the right child to the queue
        }
        i++;  // Move to the next element in the data array
    }
    
    return root;  // Return the constructed binary tree's root
}

// Helper function to calculate the height and diameter of the binary tree recursively
int heightAndDiameter(TreeNode* node, int& diameter) {
    if (!node) return 0;  // If the node is null, return a height of 0

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = heightAndDiameter(node->left, diameter);
    int rightHeight = heightAndDiameter(node->right, diameter);

    // Update the diameter. It is the maximum of the current diameter and 
    // the sum of the left and right subtree heights (the longest path between two nodes through this node)
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current node's subtree (1 + max of left and right heights)
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;  // Initialize diameter to 0
    heightAndDiameter(root, diameter);  // Call the helper function to calculate the height and diameter
    return diameter;  // Return the calculated diameter
}

int main() {
    string input;
    cout << "Enter the level-order traversal of the tree (use -1 for null nodes): ";
    getline(cin, input);  // Read the entire input string

    // Remove the square brackets and split the input string by commas
    input = input.substr(1, input.size() - 2);  // Removing the '[' and ']'
    stringstream ss(input);  // Use stringstream to parse the input string
    string temp;
    vector<int> data;

    // Parse integers from the stringstream and store them in the data vector
    while (getline(ss, temp, ',')) {
        data.push_back(stoi(temp));  // Convert string to integer and add it to the vector
    }

    // Build the binary tree from the level-order data
    TreeNode* root = buildTree(data);

    // Calculate the diameter of the binary tree
    int result = diameterOfBinaryTree(root);

    // Output the result
    cout << "Diameter of the binary tree: " << result << endl;

    return 0;
}
