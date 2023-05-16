#include "checkString.h"

#include <stdlib.h>
#include <string.h>

typedef enum State {
    StartState,
    BeforeDogState,
    StartBeforeLastSymbolState,
    BeforeLastSymbolState,
    AfterPointState,
    CanBeEndState
} State;

bool checkString(const char *string) {
    State state = StartState;
    bool failed = false;
    size_t size = strlen(string);
    for (size_t i = 0; i < size; i++) {
        char s = string[i]; // string[i] is too long
        switch (state) {
            case StartState:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '.' || s == '_' || s == '%' || s == '+' || s == '-') {
                    state = BeforeDogState;
                } else {
                    failed = true;
                }

                break;
            case BeforeDogState:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '.' || s == '_' || s == '%' || s == '+' || s == '-') {
                    // nothing
                } else if (s == '@') {
                    state = StartBeforeLastSymbolState;
                } else {
                    failed = true;
                }

                break;
            case StartBeforeLastSymbolState:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '-') {
                    state = BeforeLastSymbolState;
                } else {
                    failed = true;
                }

                break;
            case BeforeLastSymbolState:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '-') {
                    // nothing
                } else if (s == '.') {
                    state = AfterPointState;
                } else {
                    failed = true;
                }

                break;
            case AfterPointState:
                if (s >= 'A' && s <= 'Z') {
                    state = CanBeEndState;
                } else if ((s >= '0' && s <= '9') || s == '-') {
                    state = BeforeLastSymbolState;
                } else {
                    failed = true;
                }

                break;
            case CanBeEndState:
                if ((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || s == '-') {
                    state = BeforeLastSymbolState;
                } else if (s == '.') {
                    state = AfterPointState;
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

    return state == CanBeEndState;
}
