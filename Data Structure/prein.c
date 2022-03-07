#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct treenode
{
    char data;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode TreeNode;

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

TreeNode *reconstruct(int n, char pre[], char in[])  // n = 幾個點
{
    TreeNode *current;
    int leftn;
    int rightn;

    if (n == 0)
        return NULL;
    leftn = strchr(in, pre[0]) - in;  // 找出左子樹有幾個node
    rightn = n - leftn - 1;  // 找出右子樹有幾個node
    current = (TreeNode *)malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->data = pre[0];  // 建立二元樹根節點
    //傳入左樹長度與左數前序起點，與中序，回傳值作為左樹
    current->left = reconstruct(leftn, pre + 1, in);  
    //傳入右樹長度與右數前序起點，與中序，回傳值作為左樹
    current->right =
        reconstruct(rightn, pre + 1 + leftn,
                    in + leftn + 1);
    return (current);
}

int main(void)
{
    int length;
    char preorder[80];
    char inorder[80];
    TreeNode *root;

    // 先輸入preorder，再輸入inorder
    scanf("%s", preorder);  // ABCDE
    scanf("%s", inorder);  // CBDAE
    length = strlen(preorder);
    assert(length = strlen(inorder));
    root = reconstruct(length, preorder, inorder);
    // 印出postorder
    postorder(root);  // CDBEA
    return 0;
}

//     A
//   B  E
// C  D