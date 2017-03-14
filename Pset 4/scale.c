/**
 * scale.c
 *
 * CS50 AP
 * Scale
 * Olivia Brown
 *
 * Resizes a 24-bit BMP by a factor of n
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // Proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // Capture n factor
    int n = atoi(argv[1]);

    // Check size of n
    if ((n < 1) || (n > 100))
    {
        printf("The scale factor must larger than 0 and smaller than 100\n");
        return 5;
    }

    // Capture files
    char* infile = argv[2];
    char* outfile = argv[3];

    // Open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER inBF;
    fread(&inBF, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER inBi;
    fread(&inBi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Check if infile is a 24-bit uncompressed BMP
    if (inBF.bfType != 0x4d42 || inBF.bfOffBits != 54 || inBi.biSize != 40 || 
        inBi.biBitCount != 24 || inBi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // Copy infile's header's 
    BITMAPFILEHEADER outBf = inBF;
    BITMAPINFOHEADER outBi = inBi;

    // Edit the attributes that change with scaling
    outBi.biWidth *= n;
    outBi.biHeight *= n;

    // Find necessary padding
    int inPadding =  (4 - (inBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outPadding =  (4 - (outBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    outBi.biSizeImage = (sizeof(RGBTRIPLE) * abs(outBi.biHeight) * outBi.biWidth) + (outBi.biWidth * outPadding);
    outBf.bfSize = outBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // Write outfile's BITMAPFILEHEADER
    fwrite(&outBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&outBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // length of infile in bytes
    int offset = inBi.biWidth * sizeof(RGBTRIPLE) + inPadding;

    // Iterate over infile
    for (int i = 0, biHeight = abs(inBi.biHeight); i < biHeight; i++)
    {
        for (int verticalCopy = 0; verticalCopy < n; verticalCopy++)
        {
            // Iterate over pixels
            for (int j = 0; j < inBi.biWidth; j++)
            {
                // Temp
                RGBTRIPLE triple;

                // Read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int horizontalCopy = 0; horizontalCopy < n; horizontalCopy++)
                {
                    // Rrite RGB to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // Skip over input padding
            fseek(inptr, inPadding, SEEK_CUR);

            // then add output padding if neccessary
            for (int k = 0; k < outPadding; k++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, -offset, SEEK_CUR); 
        }

        // Move pointer to beginning of next line
        fseek(inptr, offset , SEEK_CUR);
    }

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    return 0;
}