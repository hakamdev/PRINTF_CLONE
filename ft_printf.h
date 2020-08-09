#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE '1'
# define FALSE '\0'
# define FORMATS "diuXxspc%"

typedef char*   string;
typedef char    bool;
typedef struct  s_format
{
    bool    zero;
    bool    dash;
    bool    dot;
    int     minw;
    int     prec;
    char    lastf;
}               t_format;
typedef struct  s_output
{
    string  value;
    int     length;
    int     zeros;
    int     spaces;
    bool    should_free;
}               t_output;

t_format    g_frmt;
t_output    g_data;
va_list     g_vlist;
long        g_count;
int         g_factor;

int         ft_printf(const string format, ...);
int         ft_format(string format);
void        ft_data();
void        ft_spacing();
void        ft_print();

string      new_string(size_t len);
string      join_char(string s, char c, bool fre);
string      sduplicate(string s);
void        shorten_str(string *s, int newlen, bool fre);
void        numbr_tostr(string *snum, long num);
void        numbr_tohex(string *shex, size_t num, int index);
void        scopy(string src, string dest);
bool        contains(string s, char c);
bool        zero_exists();
bool        dash_exists();
bool        prec_exist();
bool        is_negative();
bool        is_pointer();
int         positive(int num);
int         putnchar(char c, int n);
int         putstr(string s, int len);
int         stringlen(string s);
char        to_upper(char c);

#endif