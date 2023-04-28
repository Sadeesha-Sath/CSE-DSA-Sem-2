#include <iostream>
using namespace std;

struct node
{
  int key;
  struct node *left, *right;
};

// create node
node *create(int key)
{
  node *n_node = new node;
  n_node->key = key;
  n_node->left = NULL;
  n_node->right = NULL;
  return n_node;
}

// In-order traversal
void traverseInOrder(struct node *root)
{

  if (root == NULL)
    return;

  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key)
{

  if (node == NULL)
  {
    return create(key);
  }

  if (key <= node->key)
  {
    node->left = insertNode(node->left, key);
  }
  else
  {
    node->right = insertNode(node->right, key);
  }

  return node;
}

node *min_node(node *root)
{
  if (root->left == NULL)
  {
    return root;
  }
  return min_node(root->left);
}
// Delete node
struct node *deleteNode(struct node *root, int key)
{
  // search until the item is being found
  if (root == NULL)
    return root;
  else if (root->key > key)
    root->left = deleteNode(root->left, key);

  else if (root->key < key)
    root->right = deleteNode(root->right, key);

  else
  { // I founcd you,  it's showtime

    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      root == NULL;
    }
    else if (root->left == NULL)
    {
      node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root;
      root = root->left;
      delete temp;
    }
    else
    {
      node *temp = min_node(root->right);

      root->key = temp->key;
      deleteNode(root->right, temp->key);
    }
  }
  return root;
}

// Driver code
int main()
{
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1)
  {
    switch (operation)
    {
    case 1: // insert
      cin >> operand;
      root = insertNode(root, operand);
      cin >> operation;
      break;
    case 2: // delete
      cin >> operand;
      root = deleteNode(root, operand);
      cin >> operation;
      break;
    default:
      cout << "Invalid Operator!\n";
      return 0;
    }
  }
  traverseInOrder(root);

  return 0;
}
