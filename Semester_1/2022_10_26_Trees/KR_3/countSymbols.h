#pragma once

// Function that counts char symbols in file. 
// Returns -1 if file not found.
// Returns 1 if resiltArray is NULL.
void countSymbols(int resultArray[256], const char* filePath, int* errorCode);
