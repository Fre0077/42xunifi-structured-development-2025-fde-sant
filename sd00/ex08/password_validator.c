#include "password_validator.h"

int main()
{
    // Crea la lista delle password precedenti (history)
    PasswordHistory pw4 = { "OldPass3@", NULL };
    PasswordHistory pw3 = { "OldPass2@", &pw4 };
    PasswordHistory pw2 = { "OldPas42@", &pw3 };
    PasswordHistory pw1 = { "OldPas41@", &pw2 };

    // Nuova password da testare
    const char *new_pw = "OldPass3@";

    // Valida la nuova password
    PwStatus result = validate_password(new_pw, &pw1);

    // Stampa il risultato
    if (result.state == VALID)
        printf("Password VALIDA\n");
    else if (result.state == INVALID_SIMILAR)
        printf("Password NON VALIDA: troppo simile a una delle ultime 3\n");
    else
        printf("Password NON VALIDA\n");

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
