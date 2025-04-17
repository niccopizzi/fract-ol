# fract-ol
A program to display fractals

This program is about displaying fractals on screen, you can type on terminal 
```bash
git clone git@github.com:niccopizzi/fract-ol.git
cd fract-ol
make
```

Once the program is compiled run 

```bash
./fractol Mandelbrot
```

This will render the mandelbrot fractal and you will get something similar to this
![Mandelbrot](https://github.com/niccopizzi/fract-ol/blob/main/images/Mandelbrot.png) 

You can also

- `Change the color palette` -> using +/-
- `Move around the fractal`  -> using the arrow keys
- `Zoom in / out`            -> using the mouse wheel


 ---
 ## OTHER FRACTALS

 ### JULIA SET

 ```bash
./fractol Julia
```

This command will render the Julia Set. It accepts a second optional argument which is the complex number of the Julia Set (see below for an explanation of what complex numbers are), if no complex number is provided it will show the Julia Set for the complex number 0. Julia fractal is different from the Mandelbrot one in the sense that there's a different Julia fractal for each complex number, that's why for this specific fractal you can use the arrow keys to modify the complex number associated with the Julia fractal and see all the different shapes it can have.
Here's an example
![Julia Set](https://github.com/niccopizzi/fract-ol/blob/main/images/Julia.png)

---

### BURNING SHIP

 ```bash
./fractol "Burning Ship"
```

This is the last fractal and is also my favorite one, by running the command you will get something on screen that looks like this:

![Burning Ship](https://github.com/niccopizzi/fract-ol/blob/main/images/BurningShip.png)

---

## IMPORTANT CONCEPTS


### - Complex Numbers

Complex numbers are quite an interesting topic in mathematics, in essence a complex number is a number in the form of `a + b*i` where `a` and `b` are two real numbers and `i` is a special number equal to the square root of -1 `i = √-1`

So a complex number has two distinct parts:
- A **real** part -> the `a`
- A **imaginary** part -> the `b*i`

To work with complex numbers we can take advantage of the `<complex.h>` header, in which the complex type is defined.
To define a variable let's say `num` as complex we can just define it as 
 ```c
double complex num;
```
or 
 ```c
float complex num;
```
The following functions are needed for this project :

1. `cabs`  ->  returns the absolute value of the number;
2. `creal` ->  extracts the real part of the number;
3. `cimag` ->  extracts the imaginary part of the number;

