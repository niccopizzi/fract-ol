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

This command will render the Julia Set, it accepts a second optional argument which is the complex number of the Julia Set (see below for an explaination of what complex numbers are), if no complex number is provided it will show the Julia Set for the complex number 0. Julia fractal is different from the Mandelbrot one in the sense that there's a different Julia fractal for each complex number, that's why for this specific fractal you can use the arrow keys to modify the complex number associated with the Julia fractal and see all the different shapes it can have.
Here's an example
![Julia Set](https://github.com/niccopizzi/fract-ol/blob/main/images/Julia.png)


### BURNING SHIP

 ```bash
./fractol "Burning Ship"
```

This is the last fractal and is also my favorite one, by running the command you will get something on screen that looks like this:

![Burning Ship](https://github.com/niccopizzi/fract-ol/blob/main/images/BurningShip.png)

---

## IMPORTANT CONCEPTS

