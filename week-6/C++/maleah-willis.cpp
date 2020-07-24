#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Tree
{
    public:
    int val;
    Tree * left;
    Tree * right;
    Tree()
    {
        val = 0;
        left = NULL;
        right = NULL;
    };

    Tree(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }

    Tree(int x, Tree * l, Tree * r)
    {
        val = x;
        left = l;
        right = r;
    }
};

int maxDifference(Tree * root)
{
    int max_diff = INT_MIN; // this will be a placeholder max until we find our actual max

    // if the tree is empty, return
    if (root == NULL) return INT_MAX;
    // if the tree is only one node, return that node
    else if (root->left == NULL && root->right == NULL) return root->val;
    else
    {
        int min_val, left, right, curr_diff;
        left = maxDifference(root->left); // take the left child
        right = maxDifference(root->right); // take the right child
            
        min_val = min(left, right); // find the minimum value between left and right
            
        //if (left < right) min = left;
        //else if (right < left) min = right;
            
        curr_diff = root->val - min_val; // subtract the smallest child from the root
        //if (curr_diff > max_diff) max_diff = curr_diff;
        max_diff = max(max_diff, curr_diff); // check to see if this new difference is greater than the last
    }
        
    return max_diff;
}

Tree * mirrorTree(Tree * root)
{
    // if tree is empty, return
    if (root == NULL) return root;

    else
    {
        // we want to access the left and right subtrees from this node and swap them
        // using recursion, we take the left and right subtrees and use a swapping function to swap them
        Tree * l = mirrorTree(root->left);
        Tree * r = mirrorTree(root->right);
        swap(l, r);
    }
    
    return root;
}

int main()
{
    cout << "Please choose a problem to solve (enter 1, 2, or 3):" << endl;
    cout << "1: Max Difference" << endl;
    cout << "2: Print Leaf to Root" << endl;
    cout << "3: Mirror" << endl;

    int answer;
    cin >> answer;

    Tree * t;

    if (answer == 1)
    {
        maxDifference(t);
    }

    else if (answer == 2)
    {

    }

    else if (answer == 3)
    {
        mirrorTree(t);
    }

    else
    {
        cout << "Please enter 1, 2, or 3.";
    }
}
