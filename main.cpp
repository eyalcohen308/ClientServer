// Tomer Shlasky 204300602

/**
 * Main changes-
 * Less division to functions -  save call time.
 * Save necesary vars in registers/local vars - faster to get.
 * Used memcpy instead of malloc and copy.
 * Sub \ add instead  mul \ div.
 * Define var instead of do the same operations over ond over.
 */
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

#define KERNELSIZE_DIV_2 1 //because kernelSize define 3, kernelSize\2 = 1
#define CON 2295
#define ELSE 255

#include <stdbool.h>

void smooth_for_blur(int dim_1, pixel *src, pixel *dst) {
    register int i;
    register int j;
    int dim= dim_1;
    register int size = dim - KERNELSIZE_DIV_2;
    register int index = dim;

    for (i = KERNELSIZE_DIV_2; i < size; i++) {
        for (j = KERNELSIZE_DIV_2; j < size; j++) {
            register int red;
            register int green;
            register int blue;
            register int spec_index = index - dim + j - 1;

            red = (int) src[spec_index].red;
            green = (int) src[spec_index].green;
            blue = (int) src[spec_index].blue;

            red += (int) src[++spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            red += (int) src[++spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            spec_index += dim - 2;

            red += (int) src[spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            red += (int) src[++spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            red += (int) src[++spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            spec_index += dim -2;

            red += (int) src[spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            red += (int) src[++spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            red += (int) src[++spec_index].red;
            green += (int) src[spec_index].green;
            blue += (int) src[spec_index].blue;

            int index_plus_j = index + j; // to minimize 3 add to 1 add
            dst[index_plus_j].red = (red > 0 ? (red < CON ? (red / 9) : ELSE) : 0);
            dst[index_plus_j].green = (green > 0 ? (green < CON ? (green / 9) : ELSE) : 0);
            dst[index_plus_j].blue = (blue > 0 ? (blue < CON ? (blue / 9) : ELSE) : 0);
        }
        index += dim; //index = i * dim
    }
}

void smooth_for_sharpen(int dim_1, pixel *src, pixel *dst) {
    register int i;
    register int j;
    int dim = dim_1;
    register int size = dim - KERNELSIZE_DIV_2;
    register int index = dim;
    register pixel s;

    for (i = KERNELSIZE_DIV_2; i < size; ++i) {
        for (j = KERNELSIZE_DIV_2; j < size; ++j) {
            int index_plus_j = index + j;
            s = src[index_plus_j]; // use local vars instead pointer
            int index_min_dim_plus_j = index - dim + j;
            int index_plus_dim_plus_j = index + dim + j;
            register int spec_index = index_min_dim_plus_j - 1;

            //check if there are 3X3 pixels the same - if there are there is no change in the center pixel
            if (src[spec_index].red == src[index_min_dim_plus_j].red
                && src[spec_index].green == src[index_min_dim_plus_j].green
                && src[spec_index].blue == src[index_min_dim_plus_j].blue
                && src[index_min_dim_plus_j].red == src[index_min_dim_plus_j + 1].red
                && src[index_min_dim_plus_j].green == src[index_min_dim_plus_j + 1].green
                && src[index_min_dim_plus_j].blue == src[index_min_dim_plus_j + 1].blue
                && src[index_min_dim_plus_j + 1].red == src[index_plus_j - 1].red
                && src[index_min_dim_plus_j + 1].green == src[index_plus_j - 1].green
                && src[index_min_dim_plus_j + 1].blue == src[index_plus_j - 1].blue
                && src[index_plus_j - 1].red == s.red
                && src[index_plus_j - 1].green == s.green
                && src[index_plus_j - 1].blue == s.blue
                && s.red == src[index_plus_j + 1].red
                && s.green == src[index_plus_j + 1].green
                && s.blue == src[index_plus_j + 1].blue
                && src[index_plus_j + 1].red == src[index_plus_dim_plus_j - 1].red
                && src[index_plus_j + 1].green == src[index_plus_dim_plus_j - 1].green
                && src[index_plus_j + 1].blue == src[index_plus_dim_plus_j - 1].blue
                && src[index_plus_dim_plus_j - 1].red == src[index_plus_dim_plus_j].red
                && src[index_plus_dim_plus_j - 1].green == src[index_plus_dim_plus_j].green
                && src[index_plus_dim_plus_j - 1].blue == src[index_plus_dim_plus_j].blue
                && src[index_plus_dim_plus_j].red == src[index_plus_dim_plus_j + 1].red
                && src[index_plus_dim_plus_j].green == src[index_plus_dim_plus_j + 1].green
                && src[index_plus_dim_plus_j].blue == src[index_plus_dim_plus_j + 1].blue) {
                // end of if condition

                dst[index_plus_j] = s; // make no change in the center pixel
            } else {
                register int red = 0;
                register int green = 0;
                register int blue = 0;

                red -= (int) src[spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                red -= (int) src[++spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                red -= (int) src[++spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                spec_index += dim -2;

                red -= (int) src[spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                red += (int) (src[++spec_index].red + src[spec_index].red);
                green += (int) (src[spec_index].green + src[spec_index].green);
                blue += (int) (src[spec_index].blue + src[spec_index].blue);

                red += (int) (src[spec_index].red + src[spec_index].red);
                green += (int) (src[spec_index].green + src[spec_index].green);
                blue += (int) (src[spec_index].blue + src[spec_index].blue);

                red += (int) (src[spec_index].red + src[spec_index].red);
                green += (int) (src[spec_index].green + src[spec_index].green);
                blue += (int) (src[spec_index].blue + src[spec_index].blue);

                red += (int) (src[spec_index].red + src[spec_index].red);
                green += (int) (src[spec_index].green + src[spec_index].green);
                blue += (int) (src[spec_index].blue + src[spec_index].blue);

                red += (int) src[spec_index].red;
                green += (int) src[spec_index].green;
                blue += (int) src[spec_index].blue;

                red -= (int) src[++spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                spec_index += dim -2;

                red -= (int) src[spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                red -= (int) src[++spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                red -= (int) src[++spec_index].red;
                green -= (int) src[spec_index].green;
                blue -= (int) src[spec_index].blue;

                dst[index_plus_j].red = (red > 0 ? (red < ELSE ? red : ELSE) : 0);
                dst[index_plus_j].green = (green > 0 ? (green < ELSE ? green : ELSE) : 0);
                dst[index_plus_j].blue = (blue > 0 ? (blue < ELSE ? blue : ELSE) : 0);
            }
        }
        index += dim; //index = i * dim
    }
}

void myfunction(Image *image2, char *srcImgpName, char *blurRsltImgName, char *sharpRsltImgName) {
    //blurKernel[3][3]
    /*
    * [1, 1, 1]
    * [1, 1, 1]
    * [1, 1, 1]
    */

    //sharpKernel[3][3]
    /*
    * [-1, -1, -1]
    * [-1, 9, -1]
    * [-1, -1, -1]
    */

    // use local vars instead of global
    register int local_n = n; // n and m must be equals
    int size = local_n, size_of_pixel = sizeof(pixel), i;
    for (i = 0; i < local_n; ++i) {
        size += local_n; //size = n * n
    }

    size = size * size_of_pixel; //size = (n * n) * sizeof(pixel)

    register pixel *pixelsImg = (pixel *) image->data;
    register pixel *backupOrg = malloc(size);
    memcpy(backupOrg, pixelsImg, size);

    smooth_for_blur(local_n, backupOrg, pixelsImg);

    free(backupOrg);

    writeBMP(image2, srcImgpName, blurRsltImgName);

    pixelsImg = (pixel *) image->data;
    register pixel *backupOrg2 = malloc(size);
    memcpy(backupOrg2, pixelsImg, size);

    smooth_for_sharpen(local_n, backupOrg2, pixelsImg);

    free(backupOrg2);

    writeBMP(image2, srcImgpName, sharpRsltImgName);
}
