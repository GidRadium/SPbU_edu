#include "BinTree.h"

typedef struct BinTreeNode
{
    BinTreeValue value;
    size_t count;
    BinTreeNode *left;
    BinTreeNode *right;
} BinTreeNode;

typedef struct BinTree {
    size_t size;
    BinTreeNode *root;
} BinTree;

BinTreeNode* createBinTreeNode(BinTreeValue value) {
    BinTreeNode* binTreeNode = malloc(sizeof(BinTreeNode));
    binTreeNode->value = value;
    binTreeNode->count = 1;
    binTreeNode->left = NULL;
    binTreeNode->right = NULL;
    return binTreeNode;
}

BinTree* createBinTree() {
    BinTree* binTree = malloc(sizeof(BinTree));
    binTree->root = NULL;
    binTree->size = 0;
    return binTree;
}

void insert(BinTreeNode **node, BinTreeValue value) {
    if (node == NULL) {
        // error
        return;
    }

    if (*node == NULL) {
        *node = createBinTreeNode(value);
    } else if ((*node)->value == value) {
        (*node)->count++;
    } else if ((*node)->value < value) {
        insert(&((*node)->left), value);
    } else {
        insert(&((*node)->right), value);
    }
}

void insert(BinTree *binTree, BinTreeValue value) {
    if (binTree == NULL) {
        // error
        return;
    }

    insert(&(binTree->root), value);
}
