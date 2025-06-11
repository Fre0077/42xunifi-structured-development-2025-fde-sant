#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    VALID = 0,
    INVALID = 1,
    INVALID_SIMILAR  = 2
} PwValidationState;

typedef struct {
    PwValidationState state;
} PwStatus;

typedef struct PasswordHistory
{
    char *password;
    struct PasswordHistory *next;
} PasswordHistory;

int str_len(const char *new_pw);
int check_upper(const char *new_pw);
int check_lower(const char *new_pw);
int check_digit(const char *new_pw);
int check_special(const char *new_pw);
int check_old(const char *s1, const char *s2);
PwStatus validate_password(const char *new_pw, PasswordHistory *history);