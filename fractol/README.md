# fractol

### Summary

- Keywords: `graphics` `mathematical notation` `complex numbers` `optimization` `event handling`

1. Objective

   - creating a small fractal exploration program. First, you have to know what a fractal is.
   - coding a graphic program that open a window, create images and deal with keyboard and mouse events using the school graphical library.
     - initial option is using the `MiniLibX`.
     - BUT, I choose the [MLX42](https://github.com/codam-coding-college/MLX42/tree/master) from codam coding college, one of our community.
       - warning, the responsibility of using this library is totally up to the decision of the student, and also my campuse allow our students to use the library with their own decision.

2. Instructions

   - **Program name**: `fractol`
   - **Turn in files**: Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c
   - **Makefile**: NAME, all, clean, fclean, re
   - **Arguments**: The type of fractal to display and any other option available
   - **External functions**:
     - `open` `close` `read` `write` `malloc` `free` `perror` `strerror` `exit`
     - All functions of the math library (-lm compiler option, man man 3 math)
     - All functions of the MiniLibX (in my case, MLX42)
     - `ft_printf` and any equivalent YOU coded
   - **Libft authorized**: YES
   - **Limitations**:
     - You **must** user the MiniLibX. Either the version available on the school machines, or installing it using its sources.
       - (I choose to use MLX42, instead, and I took care about how to implement with Makefile)
   - You have to turn in a `Makefile` which will compile your source files. It must not relink.
   - Global variables are forbidden.

3. Requirements

   - **Mandatory - Rendering**:

     - Your program must offer the **Julia** set and the **Mandelbrot** set.
     - The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
     - You must be able to create different Julia sets by passing different parameters to the program.
     - A parameter is passed on the command line to define what type of fractal will be displayed in a window.
       - You can handle more parameters to use them as rendering options.
       - If no parameter is provided, or if the parameter is invalid, tha program displays a list of available parameters and exits properly.
     - You must use at least a few **colors** to show the depth of each fractal. It's even better if you hack away on psychedelic effects.

   - **Mandatory - Graphic management**:

     - Your program has to display the image in a window.
     - The menegement of your window must remain smooth (changing to another window, minimizing, and so forth).
     - Pressing `ESC` must close the window and quit the program in a clean way.
     - Clicking on the cross on the window's frame must close the window and quit the program ina clean way.
     - The use of the `images` of the `MiniLibX` (or `MLX42`) is mandatory.

   - **Bonus**:
     - One more different fractal (more than a hundred different types of fratals are referenced online).
     - The zoom follows the actual mouse position.
     - In addition to the zoom: moving the view by pressing the arrows keys.
     - Make the color range shift.

---

**references)**

- [MLX42 - from the Codam coding college](https://github.com/codam-coding-college/MLX42/tree/master)
- [Fractal Geometry - for the fundamental of fractal](https://users.math.yale.edu/public_html/People/frame/Fractals/)
- [Lode's Computer Graphics Tutorial - to turn the math notation into code](https://lodev.org/cgtutor/juliamandelbrot.html)
- [scipython.com - another code implentation of Julia set](https://scipython.com/book/chapter-7-matplotlib/problems/p72/the-julia-set/)
- [Examples of Julia set](https://en.wikipedia.org/wiki/Filled_Julia_set)
- [Douady Rabbit - one more different fractal](https://en.wikipedia.org/wiki/Douady_rabbit)
