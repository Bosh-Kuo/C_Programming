#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode TreeNode;

void print_bs_tree(TreeNode *root)
{
    if (root == NULL)
        return;
    // 若一個節點為非NULL root，永遠先印出left subtree再印right subtree
    print_bs_tree(root->left);
    printf("data = %d\n", root->data);
    print_bs_tree(root->right);
}

TreeNode *insert_bs_tree(TreeNode *root, int data)
{
    struct treenode *current;
    // 若二元樹是空的，就建立一個節點，並形成一個只含一個節點的二元搜尋樹
    if (root == NULL)
    {
        current = (TreeNode *)malloc(sizeof(TreeNode));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return (current);
    }
    // 如果要加入的data比根節點的data小，則加入左子樹，左子樹的跟節點可能會發生變化，所以將回傳node指定為新的左子樹
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    // 如果要加入的data比根節點的data大，則加入右子樹，右子樹的跟節點可能會發生變化，所以將回傳node指定為新的右子樹
    else
        root->right = insert_bs_tree(root->right, data);
    return (root);
}

int main(void)
{
    int i;
    int insert_keys[5];

    for (i = 0; i < 5; i++)
        scanf("%d", &(insert_keys[i]));

    TreeNode *root = NULL;
    for (i = 0; i < 5; i++)
        root = insert_bs_tree(root, insert_keys[i]);
    print_bs_tree(root);
    return 0;
}