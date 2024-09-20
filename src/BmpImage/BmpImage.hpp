#ifndef BMP_IMAGE_H
#define BMP_IMAGE_H

#include <windows.h>

struct BmpImage {
    BITMAPFILEHEADER m_header;
    BITMAPINFOHEADER m_info;
};

#endif // !BMP_IMAGE_H