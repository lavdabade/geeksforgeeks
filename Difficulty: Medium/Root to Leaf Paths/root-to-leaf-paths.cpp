/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  private:
    void paths(Node* root, vector<int> &currPath, vector<vector<int>> &listOfPaths) {
        currPath.push_back(root->data);
        if(!root->left && !root->right) {
            listOfPaths.push_back(currPath);
            currPath.pop_back();
            return;
        }
        if(root->left) paths(root->left, currPath, listOfPaths);
        if(root->right) paths(root->right, currPath, listOfPaths);
        currPath.pop_back();
    }
    
  public:
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> listOfPaths;
        if(!root) return listOfPaths;
        vector<int> currPath;
        paths(root, currPath, listOfPaths);
        return listOfPaths;
    }
};