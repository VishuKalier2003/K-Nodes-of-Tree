// Evaluating the Nodes from a given Node at a distance of K from the given Node in the Binary Search Tree
#include <iostream>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        if(root == NULL)   // If Tree is empty nothing to show
            return;            // Control moves out of the function
        Node* temp = root;
        ShowTree(root -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(root -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << root -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(root -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << root -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(root -> right);     // Recursive Call
    }
    int PrintAncestorNodes(Node* root, Node* target, int k)  // Setting up the Targe Node
    {
        if(root == NULL)      // If current becomes Null then the Node is not found
            return -1;
        if(root == target)   // Found our Target, we search for the Subtree Nodes
        {
            PrintSubtreeNodes(root, k);    //  calling the function
            return 0;
        }
        int dl = PrintAncestorNodes(root -> left, target, k);   // Left distance evaluation
        if(dl != -1)    // If there is left distance
        {
            if(dl + 1 == k)   // If left distance increment equals to the desired distance 
            {
                cout << root -> data << ", ";
            }
            else
                PrintSubtreeNodes(root -> right, k-dl-2);   // Right Subtree Nodes, -2 comes because we already moved
            return 1+dl;                                    // one point downwards from the right subtree and we already 
        }                                                   // covered another distance in reaching the parent Node first
        int dr = PrintAncestorNodes(root -> right, target, k);   // Similarly for the right distance
        if(dr != -1)            // If right distacne exists
        {
            if(dr + 1 == k)   // If the increment in distance equates to the required distance
            {
                cout << root -> data << ", ";
            }
            else
                PrintSubtreeNodes(root -> left, k-dr-2);  // Otherwise we will call the Subtree Nodes for the Left, -2 comes
            return 1+dr;                                  // because we already traversed two point distance while checking 
        }                                                 // the ancestor Nodes
        return -1;   // If neither condition satisfies, the node with required distance does not exist
    }
    void PrintSubtreeNodes(Node* root, int k)  // Checking for the Subtrees
    {
        if(root == NULL || k < 0)  // If there is no further traversal possible or needed we will backtrack
            return;
        if(k == 0)    // If the Node is found with the required parameters, print it
        {
            cout << root -> data << ", ";
        }
        PrintSubtreeNodes(root -> left, k-1);   // Recursive Call for Left Subtree, k will be reduced for every Recursion 
        PrintSubtreeNodes(root -> right, k-1);  // Recursive Call for Right Subtree, k will be reduced for every Recursion
    }
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    binarytree.ShowTree(root);    // Displaying binary tree with Nodes
    cout << "Enter the node distance from the specific Node : ";
    cin >> x;
    binarytree.PrintAncestorNodes(root, root -> left, x);  // Call the function
    return 0;   // End of the Program
}