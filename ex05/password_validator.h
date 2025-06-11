#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    VALID = 0,
    INVALID = 1
} PwValidationState;

typedef struct {
    PwValidationState state;
} PwStatus;

PwStatus validate_password(const char *new_pw, const char *curr_pw);