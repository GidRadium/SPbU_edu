#pragma once

typedef int DynamicArrayElement;

typedef struct DynamicArray DynamicArray;

DynamicArray * createDynamicArray();

void deleteDynamicArray(DynamicArray *dArray);

void clear(DynamicArray *dArray);

DynamicArrayElement get(DynamicArray *const dArray, int index);

void set(DynamicArray *const dArray, int index, DynamicArrayElement element);

void pushBack(DynamicArray *const dArray, DynamicArrayElement element);

void popBack(DynamicArray *const dArray);

size_t getSize(DynamicArray *const dArray);
