#pragma once

typedef int DynamicArrayElement;

typedef struct DynamicArray DynamicArray;

DynamicArray * createDynamicArray();

void deleteDynamicArray(DynamicArray *dArray);

DynamicArrayElement get(DynamicArray *dArray, size_t index);

void set(DynamicArray *dArray, int index, DynamicArrayElement element);

void pushBack(DynamicArray *dArray, DynamicArrayElement element);

void popBack(DynamicArray *dArray);
