#include "ft_printf.h"

void sp_string()
{
    if (zero_exists())
        g_data.zeros = positive(g_frmt.minw - g_data.length);
    else
        g_data.spaces = positive(g_frmt.minw - g_data.length);
}

void sp_number()
{
    g_factor = is_negative(g_data.value) ? 1 : 0;
    if (zero_exists() && !prec_exist())
        g_data.zeros = positive(g_frmt.minw - g_data.length);
    else if (prec_exist())
        g_data.zeros = positive(g_frmt.prec - g_data.length + g_factor);
    g_data.spaces = positive(g_frmt.minw - (g_data.zeros + g_data.length));
}

void sp_hex()
{
    g_factor = g_frmt.lastf == 'p' ? 2 : 0;
    if (zero_exists() && !prec_exist())
        g_data.zeros = positive(g_frmt.minw - g_data.length);
    else if (prec_exist())
        g_data.zeros = positive(g_frmt.prec - g_data.length + g_factor);
    g_data.spaces = positive(g_frmt.minw - (g_data.zeros + g_data.length));
}

void sp_char()
{
    if (zero_exists())
        g_data.zeros = positive(g_frmt.minw - g_data.length);
    else
        g_data.spaces = positive(g_frmt.minw - g_data.length);
}

void ft_spacing()
{
    if (contains("s", g_frmt.lastf))
        sp_string();
    else if (contains("diu", g_frmt.lastf))
        sp_number();
    else if (contains("Xxp", g_frmt.lastf))
        sp_hex();
    else if (contains("c%", g_frmt.lastf))
        sp_char();
}