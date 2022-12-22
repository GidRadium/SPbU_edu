#pragma once

#include <stdbool.h>

// Checks string by regular expression [A-Z0-9._%+-]+@([A-Z0-9-]+\.)+[A-Z]
bool checkString(const char *string);
