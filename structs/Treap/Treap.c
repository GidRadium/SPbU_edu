#include "Treap.h"

#include <stdbool.h>

bool isLess(TreapKey a, TreapKey b) {
    return a < b;
}

typedef struct TreapNode {
    TreapKey key;
    int priority;
    TreapNode *left;
    TreapNode *right;
} TreapNode;

typedef struct Treap {
    TreapNode *root;
    size_t size;
} Treap;

typedef struct TreapNodePair {
    TreapNode* left;
    TreapNode* right;
} TreapNodePair;

Treap *createTreap() {
    Treap *treap = malloc(sizeof(Treap));
    if (treap == NULL) {
        return NULL;
    }

    return treap;
}

void deleteTreap(Treap *treap) {
    
}

TreapNodePair split(TreapNode *treapNode, TreapKey key) {
    if (treapNode == NULL) {
        return (TreapNodePair){NULL, NULL};
    }

    if (isLess(treapNode->key, key)) {
        TreapNodePair splittedTreapNode = split(treapNode->right, key);
        treapNode->right = splittedTreapNode.left;
        return (TreapNodePair){treapNode, splittedTreapNode.right};
    } else {
        TreapNodePair splittedTreapNode = split(treapNode->left, key);
        treapNode->left = splittedTreapNode.right;
        return (TreapNodePair){splittedTreapNode.left, treapNode};
    }
}

TreapNode *merge(TreapNode *leftNode, TreapNode *rightNode) {
    if (rightNode == NULL) {
        return leftNode;
    } else if (leftNode == NULL) {
        return rightNode;
    }

    if (leftNode->priority > rightNode->priority) {
        leftNode->right = merge(leftNode->right, rightNode);
        return leftNode;
    } else {
        rightNode->left = merge(leftNode, rightNode->left);
        return rightNode;
    }
}



