#include "ft_printf.h"

int     get_flags(string format, string *flgs)
{
    int     i = 0;

    while (format[i] && !contains(FORMATS, format[i]))
        *flgs = join_char(*flgs, format[i++], TRUE);
    if (format[i])
        *flgs = join_char(*flgs, format[i++], TRUE);
    return (i);
}

int     handle_astrisk(int i, char flag)
{
    int     itemp;
    itemp = va_arg(g_vlist, int);
    if (itemp < 0 && flag == 'm') g_frmt.dash = TRUE;
    else if (itemp < 0 && flag == 'p') g_frmt.dot = FALSE;
    if (flag == 'm') g_frmt.minw = itemp < 0 ? -itemp : itemp;
    else if (flag == 'p') g_frmt.prec = itemp < 0 ? 0 : itemp;
    return ++i;
}

int     handle_numbers(string flgs, int i, char flag)
{
    string  stemp = NULL;
    while (flgs[i] >= '0' && flgs[i] <= '9')
        stemp = join_char(stemp, flgs[i++], TRUE);
    if (flag == 'm') g_frmt.minw = stemp ? atoi(stemp) : 0;
    else if (flag == 'p') g_frmt.prec = stemp ? atoi(stemp) : 0;
    return i;
}

int     handle_zerodash(string flgs, int i)
{
    while (flgs[i] == '0' || flgs[i] == '-')
    {
        if (flgs[i] == '-') g_frmt.dash = TRUE;
        else if (flgs[i] == '0') g_frmt.zero = TRUE;
        i++;
    }
    return i;
}

int     handle_dot(int i)
{
    g_frmt.dot = TRUE;
    return ++i;
}

void    reset_format()
{
    g_frmt.zero = FALSE;
    g_frmt.dash = FALSE;
    g_frmt.dot = FALSE;
    g_frmt.minw = 0;
    g_frmt.prec = 0;
    g_frmt.lastf = '\0';
}

void    setup_format(string flgs)
{
    int     i = 0;
    reset_format();
    if (flgs[i] == '0' || flgs[i] == '-')
        i = handle_zerodash(flgs, i);
    if (flgs[i] >= '0' && flgs[i] <= '9')
        i = handle_numbers(flgs, i, 'm');
    if (flgs[i] == '*')
        i = handle_astrisk(i, 'm');
    if (flgs[i] == '.')
        i = handle_dot(i);
    if (flgs[i] >= '0' && flgs[i] <= '9')
        i = handle_numbers(flgs, i, 'p');
    if (flgs[i] == '*')
        i = handle_astrisk(i, 'p');
    g_frmt.lastf = flgs[i];
}

int     ft_format(string format)
{
    int     flags_len;
    string  flags = NULL;

    flags_len = get_flags(format, &flags);
    setup_format(flags);
    return (flags_len + 1);
}