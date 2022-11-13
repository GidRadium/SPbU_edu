#pragma once

#include <stdlib.h>

typedef int BinTreeMapKey;

typedef char* BinTreeMapValue;

typedef struct BinTreeMapNode BinTreeMapNode;

typedef struct BinTreeMap BinTreeMap;

BinTreeMap* createBinTreeMap();

void set(BinTreeMap *binTreeMap, BinTreeMapKey key, BinTreeMapValue value);

BinTreeMapValue get(BinTreeMap *binTreeMap, BinTreeMapValue key);

void erase(BinTreeMap *binTreeMap, BinTreeMapKey key);

size_t getSize(BinTreeMap *binTreeMap);

void deleteBinTreeMap(BinTreeMap *binTreeMap);
