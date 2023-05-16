#pragma once

// Stored element type
typedef struct {
    char *string;
    int value;
} DynamicArrayElement;

#define DynamicArrayElementNULL ((DynamicArrayElement){0, 0})

// Main struct of DynamicArray
typedef struct DynamicArray DynamicArray;

// Allocates mem for DynamicArray. Returns NULL if something goes wrong
DynamicArray *createDynamicArray();

// Deletes DynamicArray struct
void deleteDynamicArray(DynamicArray *dArray);

// Clears all elements and frees memmory
void clear(DynamicArray *dArray);

// Returns DynamicArrayElement by mod(size)
DynamicArrayElement get(DynamicArray *const dArray, int index);

// Sets DynamicArrayElement by mod(size)
void set(DynamicArray *const dArray, int index, DynamicArrayElement element);

// Pushes DynamicArrayElement to the back of array. Allocates mem sometimes
void pushBack(DynamicArray *const dArray, DynamicArrayElement element);

// Deletes last DynamicArrayElement
void popBack(DynamicArray *const dArray);

// Returns count of stored objects
size_t getSize(DynamicArray *const dArray);

// Erases element by index mod(size)
void erase(DynamicArray * const dArray, int index);
