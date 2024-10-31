/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/23 12:19:25 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int burning_ship_set(double complex c, int max_iterations)
{
    double x0;
    double y0;
    double x;
    double y;
    double x2;
    double y2;
    int iteration;

    iteration = 0;
    x = 0.0;
    y = 0.0;
    y0 = cimag(c);
    x0 = creal(c);
    x2 = 0.0;
    y2 = 0.0;
    while ((x2 + y2) <= 4 && iteration < max_iterations)
    {
        y = fabs((x + x) * y + y0);
        x = fabs(x2 - y2 + x0);
        x2 = x * x;
        y2 = y * y;
        iteration++;
    }
    return (iteration % max_iterations);
}

void calculate_burning_ship(t_data data, t_fractal fractal)
{
    double real;
    double imag;
    int x_axis;
    int y_axis;
    int burning_ship_palette[30] = {0x000000, 0x330000, 0x660000, 0x930000, 0xBF0000, 0xEF0000, 0xFF0000, 0xFF3300, 0xFF6600, 0xFF9900,
                                    0xFFCC00, 0xFFFF00, 0xE5FF00, 0xCFFF00, 0xBFFF00, 0xA5FF00, 0x80FF00, 0x60FF00, 0x40FF00, 0x00FF00,
                                    0x00CC00, 0x008000, 0x006000, 0x004000, 0x003000, 0x330000, 0x260000, 0x1A0000, 0x0C0000, 0x060000};

    y_axis = 0;
    if (fractal.brightness != 1.0)
        shift_color(burning_ship_palette, fractal.brightness);
    while (y_axis <= HEIGHT)
    {
        x_axis = 0;
        while (x_axis <= WIDTH)
        {
            real = fractal.x_start + (double)x_axis / WIDTH * fractal.scale;
            imag = fractal.y_start + (double)y_axis / HEIGHT * fractal.scale;
            image_put_pixel(data.image, x_axis, y_axis, burning_ship_palette[burning_ship_set(real + imag * I, fractal.max_iter) % 30]);
            x_axis++;
        }
        y_axis++;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}
