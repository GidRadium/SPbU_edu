#include "Treap.h"

#include <stdbool.h>
#include <stdio.h>

bool isLess(TreapKey left, TreapKey right) {
    return (left < right);
}

typedef struct TreapNode TreapNode;

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

    *treap = (Treap){NULL, (size_t)0};

    return treap;
}

void deleteSubtree(TreapNode *subtreeRoot) {
    if (subtreeRoot == NULL) {
        return;
    }

    if (subtreeRoot->left != NULL) {
        deleteSubtree(subtreeRoot->left);
    }

    if (subtreeRoot->right != NULL) {
        deleteSubtree(subtreeRoot->right);
    }

    free(subtreeRoot);
}

void deleteTreap(Treap *treap) {
    if (treap == NULL) {
        return;
    }

    if (treap->root != NULL) {
        deleteSubtree(treap->root);
    }

    free(treap);
}

void clear(Treap *treap) {
    if (treap == NULL) {
        return;
    }

    if (treap->root != NULL) {
        deleteSubtree(treap->root);
    }

    *treap = (Treap){NULL, 0};
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

    if (rightNode->priority < leftNode->priority) {
        leftNode->right = merge(leftNode->right, rightNode);
        return leftNode;
    } else {
        rightNode->left = merge(leftNode, rightNode->left);
        return rightNode;
    }
}

void insert(Treap *treap, TreapKey key) {
    if (treap == NULL || count(treap, key)) {
        return;
    }

    TreapNode *newNode = malloc(sizeof(TreapNode));
    *newNode = (TreapNode){key, rand(), NULL, NULL};

    TreapNodePair splittedRoot = split(treap->root, key);
    splittedRoot.left = merge(splittedRoot.left, newNode);
    treap->root = merge(splittedRoot.left, splittedRoot.right);

    treap->size++;
}

void erase(Treap *treap, TreapKey key) {
    if (treap == NULL || treap->root == NULL) {
        return;
    }

    TreapNode **node = &(treap->root);
    while (*node != NULL) {
        if (isLess(key, (*node)->key)) {
            node = &((*node)->left);
        } else if (isLess((*node)->key, key)) {
            node = &((*node)->right);
        } else {
            printf("found %d\n", key);
            *node = merge((*node)->left, (*node)->right);
            treap->size--;
            return;
        }
    }
}

size_t count(Treap *treap, TreapKey key) {
    if (treap == NULL || treap->root == NULL) {
        return 0;
    }

    TreapNode* node = treap->root;
    while (node != NULL) {
        if (isLess(key, node->key)) {
            node = node->left;
        } else if (isLess(node->key, key)) {
            node = node->right;
        } else {
            return 1;
        }
    }

    return 0;
}

TreapKey getBegin(Treap *treap) {
    if (treap == NULL || treap->root == NULL) {
        return 0;
    }

    TreapNode* node = treap->root;
    while (node->left != NULL) {
        node = node->left;
    }

    return node->key;
}

TreapKey getEnd(Treap *treap) {
    if (treap == NULL || treap->root == NULL) {
        return 0;
    }

    TreapNode* node = treap->root;
    while (node->right != NULL) {
        node = node->right;
    }

    return node->key;
}

size_t getSize(Treap *treap) {
    if (treap == NULL) {
        return 0;
    }

    return treap->size;
}

bool isEmpty(Treap *treap) {
    if (treap == NULL) {
        return 1;
    }

    return !((bool)treap->size);
}

void addSubtreeToArray(TreapKey *array, size_t *lastEmpty, TreapNode *subtreeRoot) {
    if (subtreeRoot == NULL) {
        return;
    }

    addSubtreeToArray(array, lastEmpty, subtreeRoot->left);
    array[*lastEmpty] = subtreeRoot->key;
    (*lastEmpty)++;
    addSubtreeToArray(array, lastEmpty, subtreeRoot->right);
}

TreapKey *getAsArray(Treap *treap) {
    size_t size = getSize(treap);
    if (size == 0) {
        return NULL;
    }

    size_t lastEmpty = 0;
    TreapKey *array = calloc(size + 10, sizeof(TreapKey));
    addSubtreeToArray(array, &lastEmpty, treap->root);

    return array;
}
