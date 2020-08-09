#include "ft_printf.h"

void handle_string()
{
    g_data.value = va_arg(g_vlist, string);
    if (g_data.value == NULL)
        g_data.value = sduplicate("(null)");
    g_data.length = stringlen(g_data.value);
    if (prec_exist() && g_frmt.prec < g_data.length)
    {
        shorten_str(&g_data.value, g_frmt.prec, FALSE);
        g_data.length = g_frmt.prec;
    }
    g_data.should_free = TRUE;
}

void handle_number()
{
    long num = g_frmt.lastf == 'u'  ? (long)va_arg(g_vlist, unsigned)
                                    : (long)va_arg(g_vlist, int);
    if (prec_exist() && g_frmt.prec == 0 && num == 0)
        g_data.value = sduplicate("");
    else
        numbr_tostr(&g_data.value, num);
    g_data.length = stringlen(g_data.value);
    g_data.should_free = TRUE;
}

void handle_hex()
{
    size_t hexnum;
    if (is_pointer())
        hexnum = va_arg(g_vlist, size_t);
    else
        hexnum = va_arg(g_vlist, unsigned int);
    if (prec_exist() && g_frmt.prec == 0 && hexnum == (size_t)0)
        g_data.value = sduplicate(is_pointer() ? "0x" : "");
    else
        numbr_tohex(&g_data.value, hexnum, -1);
    g_data.length = stringlen(g_data.value);
    g_data.should_free = TRUE;
}

void handle_char()
{
    char c = g_frmt.lastf == '%' ? '%' : va_arg(g_vlist, int);
    g_data.value = join_char(NULL, c, FALSE);
    g_data.length = 1;
    g_data.should_free = TRUE;
}

void reset_data()
{
    g_data.value = NULL;
    g_data.length = 0;
    g_data.spaces = 0;
    g_data.zeros = 0;
    g_data.should_free = FALSE;
}

void ft_data()
{
    reset_data();
    if (contains("s", g_frmt.lastf))
        handle_string();
    else if (contains("diu", g_frmt.lastf))
        handle_number();
    else if (contains("Xxp", g_frmt.lastf))
        handle_hex();
    else if (contains("c%", g_frmt.lastf))
        handle_char();
}