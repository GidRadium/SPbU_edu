#include "BinTreeMap.h"

#include <stdbool.h>

typedef struct BinTreeMapNode {
    BinTreeMapKey key;
    BinTreeMapValue value;
    BinTreeMapNode *left;
    BinTreeMapNode *right;
} BinTreeMapNode;

typedef struct BinTreeMap {
    BinTreeMapNode *root;
    size_t size;
} BinTreeMap;

BinTreeMap* createBinTreeMap() {
    BinTreeMap *binTreeMap = malloc(sizeof(BinTreeMap));

    binTreeMap->root = NULL;
    binTreeMap->size = 0;

    return binTreeMap;
}

void set(BinTreeMap *binTreeMap, BinTreeMapKey key, BinTreeMapValue value) {
    if (binTreeMap == NULL) {
        return;
    }

    BinTreeMapNode *newNode = NULL;

    if (binTreeMap->root == NULL) {
        binTreeMap->root = malloc(sizeof(BinTreeMapNode));
        binTreeMap->size++;
        newNode = binTreeMap->root;
    }

    BinTreeMapNode *tempNode = binTreeMap->root;

    while (newNode == NULL) {
        if (tempNode->key < key) {
            if (tempNode->left != NULL) {
                tempNode = tempNode->left;
            } else {
                tempNode->left = malloc(sizeof(BinTreeMapNode));
                binTreeMap->size++;
                newNode = tempNode->left;
            }
        } else if (tempNode->key > key) {
            if (tempNode->right != NULL) {
                tempNode = tempNode->right;
            } else {
                tempNode->right = malloc(sizeof(BinTreeMapNode));
                binTreeMap->size++;
                newNode = tempNode->right;
            }
        } else {
            tempNode->value = value;
            return;
        }
    }

    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

BinTreeMapValue get(BinTreeMap *binTreeMap, BinTreeMapValue key) {
    if (binTreeMap == NULL) {
        return NULL;
    }

    BinTreeMapNode *tempNode = binTreeMap->root;

    while (tempNode != NULL && tempNode->key != key) {
        tempNode = (tempNode->key < key ? tempNode->left : tempNode->right);
    }

    if (tempNode == NULL) {
        return NULL;
    }

    return tempNode->value;
}
