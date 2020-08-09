#include "ft_printf.h"

int ft_printf(const string format, ...)
{
    int i = 0;

    va_start(g_vlist, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i += ft_format(&format[i + 1]);
            ft_data();
            ft_spacing();
            ft_print();
        }
        else
            g_count += putnchar(format[i++], 1);
    }
    va_end(g_vlist);
    return (g_count);
}