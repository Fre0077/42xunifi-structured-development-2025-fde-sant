#include "password_validator.h"

int one_difference(const char *s1, const char *s2)
{
    int i = 0;
    int count = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            count++;
        i++;
    }
    if (s1[i] != '\0' || s2[i] != '\0')
        return 0;
    if (count <= 1)
        return 1;
    return 0;
}

int check_older(const char *new_pw, PasswordHistory *history)
{
    PasswordHistory *head = history;
    for (int i = 0; i < 2 && history->next; i++)
    {
        history = history->next;
        if (one_difference(new_pw, history->password))
        {
            history = head;
            return 1;
        }
    }
    history = head;
    return 0;
}

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
    PwStatus status;
    status.state = VALID;
    if (!new_pw || !history)
        status.state = INVALID;
    else if (str_len(new_pw) < 8)
        status.state = INVALID;
    else if (check_upper(new_pw))
        status.state = INVALID;
    else if (check_lower(new_pw))
        status.state = INVALID;
    else if (check_digit(new_pw))
        status.state = INVALID;
    else if (check_special(new_pw))
        status.state = INVALID;
    else if (check_old(new_pw, history->password))
        status.state = INVALID;
    else if (check_older(new_pw, history))
        status.state = INVALID_SIMILAR;
    return status;
}