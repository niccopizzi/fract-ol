/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/23 12:06:46 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int julia_set(double complex z, double complex c, int max_iterations)
{
    int iteration;

    iteration = 0;
    while (cabs(z) <= 2 && iteration < max_iterations)
    {
        z = z * z + c;
        iteration++;
    }
    return (iteration % max_iterations);
}
void calculate_julia(t_data data, t_fractal fractal)
{
    double real;
    double imag;
    int x_axis;
    int y_axis;
    int psychedelic_palette[30] = {0x000000, 0xFF00CC, 0xFF0099, 0xFF0066, 0xFF0033, 0xFF0000, 0xFF3300, 0xFF6600, 0xFF9900, 0xFFCC00,
                                   0xFFFF00, 0xCCFF00, 0x99FF00, 0x66FF00, 0x33FF00, 0x00FF00, 0x00FF33, 0x00FF66, 0x00FF99, 0x00FFCC,
                                   0x00FFFF, 0x00CCFF, 0x0099FF, 0x0066FF, 0x0033FF, 0x0000FF, 0x3300FF, 0x6600FF, 0x9900FF, 0xCC00FF};

    if(fractal.brightness != 1.0)
        shift_color(psychedelic_palette, fractal.brightness);
    y_axis = 0;
    while (y_axis <= HEIGHT)
    {
        x_axis = 0;
        while (x_axis <= WIDTH)
        {
            real = fractal.x_start + (double)x_axis / WIDTH * fractal.scale;
            imag = fractal.y_start + (double)y_axis / HEIGHT * fractal.scale;
            image_put_pixel(data.image, x_axis, y_axis, psychedelic_palette[julia_set(real + imag * I, fractal.c, fractal.max_iter) % 30]);
            x_axis++;
        }
        y_axis++;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}
