#include "ft_printf.h"

int     positive(int num)
{
    return num < 0 ? 0 : num;
}

bool    contains(string s, char c)
{
    while (*s)
        if (*s++ == c)
            return TRUE;
    return FALSE;
}

string  new_string(size_t len)
{
    return (string)malloc(len * sizeof(char));
}

int     stringlen(string s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char    to_upper(char c)
{
    return c >= 'a' && c <= 'z' ? c - 32 : c;
}

void    scopy(string src, string dest)
{
    if (!src || !dest)
        return;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

string  join_char(string s, char c, bool fre)
{
    string newstr;
    int slen = 0;
    if (!s)
    {
        newstr = new_string(2);
        newstr[0] = c;
        newstr[1] = '\0';
        return newstr;
    }
    slen = stringlen(s);
    newstr = new_string(slen + 2);
    scopy(s, newstr);
    newstr[slen] = c;
    newstr[slen + 1] = '\0';
    if (fre)
        free(s);
    return (newstr);
}

string  sduplicate(string s)
{
    if (s == NULL) return NULL;
    string new_s = new_string(stringlen(s) + 1);
    scopy(s, new_s);
    return (new_s);
}

void    shorten_str(string *s, int newlen, bool fre)
{
    string temp = NULL;
    if (s == NULL)
        return;
    temp = *s;
    *s = new_string(newlen);
    (*s)[newlen] = '\0';
    while (newlen--)
        (*s)[newlen] = temp[newlen];
    if (fre)
        free(temp);
}

void    numbr_tostr(string *snum, long num)
{
    if (num < 0)
    {
        num = -num;
        *snum = join_char(*snum, '-', TRUE);
    }
    if (num >= 0 && num <= 9)
        *snum = join_char(*snum, num + 48, TRUE);
    if (num > 9)
    {
        numbr_tostr(snum, num / 10);
        numbr_tostr(snum, num % 10);
    }
}

void    numbr_tohex(string *shex, size_t num, int index)
{
    static string hex = "0123456789abcdef";
    if (g_frmt.lastf == 'p' && index == -1)
        *shex = sduplicate("0x");
    if (num == (size_t)0 && index == -1)
        *shex = join_char(*shex, '0', TRUE);
    if (num > 0)
        numbr_tohex(shex, num / 16, num % 16);
    if (index >= 0)
    {
        char hexchar = g_frmt.lastf == 'X' ? to_upper(hex[index]) : hex[index];
        *shex = join_char(*shex, hexchar, TRUE);
    }
}

int     putnchar(char c, int n)
{
    int i = 0;
    while (i++ < n)
        write(1, &c, 1);
    return (n);
}

int     putstr(string s, int len)
{
    write(1, s, len);
    return len;
}

bool    zero_exists()
{
    return (g_frmt.zero && !g_frmt.dash);
}

bool    dash_exists()
{
    return (g_frmt.dash);
}

bool    prec_exist()
{
    return (g_frmt.dot);
}

bool    is_negative()
{
    return (g_data.value[0] == '-');
}

bool    is_pointer()
{
    return (g_frmt.lastf == 'p');
}



