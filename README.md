# Image to ASCII Art Converter

This C++ program converts any image into ASCII art using the OpenCV library. ASCII art is a graphic design technique that uses printable characters from the ASCII standard to create images and designs.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This program takes an input image, processes it using OpenCV, and then converts it into ASCII art. Each pixel (or groups of pixels) in the image is replaced with a corresponding ASCII character, which creates a visual representation of the image using text.

## Requirements

- C++ compiler (supporting C++11 or higher)
- OpenCV library
- CMake (for building)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/image-to-ascii.git
   ```

2. Navigate to the project directory:

   ```bash
   cd image-to-ascii
   ```

3. Build the project using CMake:

   ```bash
   cmake .
   make
   ```

## Usage

To convert an image to ASCII art, use the following command:

```bash
./image_to_ascii 
```
<!---<path_to_image> <output_width> <density>
- `<path_to_image>`: Path to the input image file.
- `<output_width>`: Desired width of the output ASCII art (in characters).
- `<density>`: Density of ASCII characters used (1-100, default is 10).--->

Then you need to write a path of an image in images folder.

## Examples

Here are some examples of the program in action:

- Original Image and ASCII representation:

  <img width= 37% alt="castle" src="https://github.com/Peczyn/IMG_to_ASCII/assets/142744067/d3e6094e-32d8-460a-9a96-3c32acf6c9f8">
  <img width= 53% alt="castle_ASCII" src="https://github.com/Peczyn/IMG_to_ASCII/assets/142744067/31a72fcd-7f17-42a3-943f-647bc5117346">

- Some other art
  
   <img width=36% alt="rick_big_zoomed" src="https://github.com/Peczyn/IMG_to_ASCII/assets/142744067/5d5ab267-bb1d-42e3-bb7b-cbb52a6f1490"> 
   <img width=39% alt="car" src="https://github.com/Peczyn/IMG_to_ASCII/assets/142744067/5fbc57d8-25c1-4c58-91fd-9e62c93b5815"> 

## Contributing

Contributions are welcome! If you have any ideas for improvements, new features, or bug fixes, please open an issue or create a pull request with your changes.

## License

This project is licensed under the [MIT License](LICENSE), which means you are free to use, modify, and distribute the code for personal or commercial purposes. Please see the [LICENSE](LICENSE) file for more details.
