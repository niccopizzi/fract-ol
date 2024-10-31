/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:21:27 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/23 12:06:21 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mandelbrot_set(double complex c, int max_iterations)
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
        y = (x + x) * y + y0;
        x = x2 - y2 + x0;
        x2 = x * x;
        y2 = y * y;
        iteration++;
    }
    return (iteration % max_iterations);
}

void calculate_mandelbrot(t_data data, t_fractal fractal)
{
    int x_axis;
    int y_axis;
    double real;
    double imag;
    int mandelbrot_palette[30] = {0x000000, 0x0033FF, 0x0066FF, 0x0099FF, 0x00CCFF, 0x00FFFF, 0x19E5FF, 0x33CCFF, 0x4CB2FF, 0x66A5FF,
                                  0x80CCFF, 0x99E5FF, 0xB2FFFF, 0xCCFFCC, 0xE5FF99, 0xFFFF66, 0xFFCC00, 0xFFB300, 0xFF9900, 0xFF8000,
                                  0xFF6600, 0xFF4C00, 0xFF3300, 0xFF1900, 0xFF0000, 0xE50000, 0xCC0000, 0xB30000, 0x990000, 0x800000};

    if (fractal.brightness != 1.0)
        shift_color(mandelbrot_palette, fractal.brightness);
    y_axis = 0;
    while (y_axis <= HEIGHT)
    {
        x_axis = 0;
        while (x_axis <= WIDTH)
        {
            real = fractal.x_start + (double)x_axis / WIDTH * fractal.scale;
            imag = fractal.y_start + (double)y_axis / HEIGHT * fractal.scale;
            image_put_pixel(data.image, x_axis, y_axis, mandelbrot_palette[mandelbrot_set(real + imag * I, fractal.max_iter) % 30]);
            x_axis++;
        }
        y_axis++;
    }
}
