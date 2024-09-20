# Small BMP Image Converter

## A little about...
This project was created as part of a test assignment while job hunting for one of the positions. I had some free time and decided to tackle this interesting task. This is my first experience in this area of development. It has been a great learning opportunity for me, as I learned how BMP files work, how to read them, and how to interact with them.

I also learned about the bit sequence alignment rule, which is necessary for such file extensions.
Additionally, this is my first time using CMake for project building; I’m keeping an eye on this technology for the future XD.

<p align="center">
  <img src="https://github.com/user-attachments/assets/39f5e8d9-4e78-48d7-a5c3-46d08767be28" alt="Image leave :(" />
</p>


# Installing
To clone the repository, you can simply use the universal git cloning method:
```
git clone https://github.com/soamane/bmp-converter.git
```
### Building the Solution with CMake
```
> mkdir build
> cd build
> cmake ..
```
### Compiling the Project with CMake
You just need to run the project build using: ```> cmake --build .```

# Notes
- The BMP format requires that each row of the image data be aligned to 4 bytes. This is handled in the **GetRowByteSize()** method.
- The console display is a simple representation of the image, where only black and white pixels are shown.
- The program converts only 24/32-bit images
