#pragma once

#include <stdlib.h>

typedef int BinTreeValue;

typedef struct BinTreeNode BinTreeNode;

typedef struct BinTree BinTree;

BinTree* createBinTree();

void insert(BinTree *binTree, BinTreeValue value);

void erase(BinTree *binTree, BinTreeValue value);

int count(BinTree *binTree, BinTreeValue value);

size_t getSize(BinTree *binTree);

void deleteBinTree();
