#pragma once

#include "../../../structs/Stack/Stack.h"

#include <stdbool.h>

// Returns false if smth goes wrong
bool checkBracketSequenceCorrectness(char *bracketSequence, int *errorCode);
