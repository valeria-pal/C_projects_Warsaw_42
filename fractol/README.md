# fract-ol

A graphical fractal visualizer written in C using MiniLibX. Supports Mandelbrot and Julia sets with zoom functionality and color depth effects.

## Features

- Visualizes Mandelbrot and Julia fractals
- Mouse scroll zooming (in and out)
- Command-line parameter parsing
- Adjustable Julia set parameters (real and imaginary parts)
- Clean exit via ESC or window close
- Colored output depending on fractal iteration depth
- Uses MiniLibX for rendering

## Installation

Clone the repository and build:

```bash
git clone https://github.com/your_username/fract-ol.git
cd fract-ol
make
```
## Usage

./fractal julia -0.7 0.27015
./fractal julia 0.285 0.01
./fractal mandelbrot


