#include "ft_printf.h"

void pr_string()
{
    if (!dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
    g_cnt += putnchar('0', g_data.zeros);
    g_cnt += putstr(g_data.value, g_data.length);
    if (dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
}

void pr_number()
{
    if (!dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
    if (is_negative(g_data.value))
        g_cnt += putstr(g_data.value, g_factor);
    g_cnt += putnchar('0', g_data.zeros);
    g_cnt += putstr(g_data.value + g_factor, 
                    g_data.length - g_factor);
    if (dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
}

void    pr_hex()
{
    if (!dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
    if (g_frmt.lastf == 'p')
        g_cnt += putstr(g_data.value, g_factor);
    g_cnt += putnchar('0', g_data.zeros);
    g_cnt += putstr(g_data.value + g_factor,
                    g_data.length - g_factor);
    if (dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);

}

void    pr_char()
{
    if (!dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
    g_cnt += putnchar('0', g_data.zeros);
    g_cnt += putstr(g_data.value, 1);
    if (dash_exists())
        g_cnt += putnchar(' ', g_data.spaces);
}

void ft_print()
{
    if (contains("s", g_frmt.lastf))
        pr_string();
    else if (contains("diu", g_frmt.lastf))
        pr_number();
    else if (contains("Xxp", g_frmt.lastf))
        pr_hex();
    else if (contains("c%", g_frmt.lastf))
        pr_char();
}