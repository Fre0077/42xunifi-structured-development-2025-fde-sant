#include "password_validator.h"

int main ()
{
    const char *curr_pw = "Password1@";
    const char *test_pw[] = {
        "Password1@",    // uguale a quella vecchia
        "pass",          // troppo corta
        "password1@",    // manca maiuscola
        "PASSWORD1@",    // manca minuscola
        "Password@@",    // manca cifra
        "Password12",    // manca speciale
        "Password2@",    // valida
        NULL
    };

    for (int i = 0; test_pw[i] != NULL; i++) {
        PwStatus result = validate_password(test_pw[i], curr_pw);
        printf("Test #%d: \"%s\" -> %s\n", i+1, test_pw[i],
               result.state == VALID ? "VALIDA" : "NON VALIDA");
    }
    return 0;
}

int str_len(const char *new_pw)
{
    int i = 0;
    while (new_pw[i])
        i++;
    return i;
}

int check_upper(const char *new_pw)
{
    int i = 0;
    while (new_pw[i])
    {
        if (new_pw[i] <= 'Z' && new_pw[i] >= 'A')
            return 0;
        i++;
    }
    return 1;
}

int check_lower(const char *new_pw)
{
    int i = 0;
    while (new_pw[i])
    {
        if (new_pw[i] <= 'z' && new_pw[i] >= 'a')
            return 0;
        i++;
    }
    return 1;
}

int check_digit(const char *new_pw)
{
    int i = 0;
    while (new_pw[i])
    {
        if (new_pw[i] <= '9' && new_pw[i] >= '0')
            return 0;
        i++;
    }
    return 1;
}

int check_special(const char *new_pw)
{
    int i = 0;
    while (new_pw[i])
    {
        if (new_pw[i] == '@' || new_pw[i] == '#' || new_pw[i] == '%' || new_pw[i] == '^' || new_pw[i] == '&' || new_pw[i] == '*')
            return 0;
        i++;
    }
    return 1;
}

int check_old(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return (s1[i] == '\0' && s2[i] == '\0');
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    PwStatus status;
    status.state = VALID;
    if (!new_pw || !curr_pw)
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
    else if (check_old(new_pw, curr_pw))
        status.state = INVALID;
    return status;
}