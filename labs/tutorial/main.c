#include <stdio.h>
/*
define preprocessor constants, don't change
*/
#define HEIGHT 45
#define WIDTH 44

/*
Read the image file to an array, don't change
array: output, the 1D array stores the flattened image matrix.
*/
void read_image(int image[HEIGHT * WIDTH])
{
    FILE *in = fopen("surprise.dat", "rb");
    int count = 0;
    unsigned char b = fgetc(in);
    while (!feof(in))
    {
        image[count] = b;
        b = fgetc(in);
        count++;
    }
    fclose(in);
}

/*
write the character matrix into a text file, don't change
image2D: input, the 2D char array stores a character matrix.
*/
void writetxt(char image2D[HEIGHT][WIDTH])
{
    FILE *out = fopen("image.txt", "w");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            fprintf(out, "%c", image2D[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(out);
}

/*
convert the flattened image matrix to a character matrix.
image: an array stores the flattened image.
image2D: Output, an 2D array stores the character image matrix after the conversion.

Conversion Rule:
image2D[i][j] = ' ' if the pixel value of at coordinate i,j is smaller than 85;
image2D[i][j] = 'I' if the pixel value of at coordinate i,j is bigger than 85 but smaller than 170;
image2D[i][j] = 'M' Otherwise;
*/
void image2char(int image[HEIGHT * WIDTH], char image2D[HEIGHT][WIDTH])
{
    // TODO: Write your code here.
}

void main()
{
    int image[HEIGHT * WIDTH];
    printf("Reading 2D image matrix...");
    read_image(image);

    printf("done!. \n\nConverting data to 2D char array...\n");
    char image2D[HEIGHT][WIDTH];
    image2char(image, image2D);

    printf("done! \n\nWriting to image.txt...");
    writetxt(image2D);
    printf("done! \n");
}