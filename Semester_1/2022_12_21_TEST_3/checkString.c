#include "checkString.h"

#include <stdlib.h>
#include <string.h>

typedef enum State {
    Start,
    BeforeDog,
    StartBeforeLastSymbol,
    BeforeLastSymbol,
    AfterPoint,
    CanBeEnd
} State;

bool checkString(const char *string) {
    State state = Start;
    bool failed = false;
    size_t size = strlen(string);
    for (size_t i = 0; i < size; i++) {
        char s = string[i]; // string[i] is too long
        switch (state) {
            case Start:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '.' || s == '_' || s == '%' || s == '+' || s == '-') {
                    state = BeforeDog;
                } else {
                    failed = true;
                }

                break;
            case BeforeDog:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '.' || s == '_' || s == '%' || s == '+' || s == '-') {
                    // nothing
                } else if (s == '@') {
                    state = StartBeforeLastSymbol;
                } else {
                    failed = true;
                }

                break;
            case StartBeforeLastSymbol:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '-') {
                    state = BeforeLastSymbol;
                } else {
                    failed = true;
                }

                break;
            case BeforeLastSymbol:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '-') {
                    // nothing
                } else if (s == '.') {
                    state = AfterPoint;
                } else {
                    failed = true;
                }

                break;
            case AfterPoint:
                if (s >= 'A' && s <= 'Z') {
                    state = CanBeEnd;
                } else if ((s >= '0' && s <= '9') || s == '-') {
                    state = BeforeLastSymbol;
                } else {
                    failed = true;
                }

                break;
            case CanBeEnd:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '-') {
                    state = BeforeLastSymbol;
                } else if (s == '.') {
                    state = AfterPoint;
                } else {
                    failed = true;
                }

                break;
            default:
                break;
        }

        if (failed) {
            return false;
        }
    }

    return state == CanBeEnd;
}
