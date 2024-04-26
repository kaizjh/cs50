#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = (int)round(average);
            image[i][j].rgbtGreen = (int)round(average);
            image[i][j].rgbtRed = (int)round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float tmpB = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            float tmpG = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            float tmpR = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;

            if (tmpB > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = (int)round(tmpB);

            if (tmpG > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = (int)round(tmpG);

            if (tmpR > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = (int)round(tmpR);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = width / 2;
    RGBTRIPLE tmp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width -j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// A function for blur
RGBTRIPLE box_blur(int h, int w, int height, int width, RGBTRIPLE copy[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = box_blur(i, j, height, width, copy);
        }
    }
    return;
}

// Forming a 3 * 3 box, taking each pixel and, for each color value,
// Giving it a new value by averaging the color values of neighboring(in the box) pixels.
RGBTRIPLE box_blur(int h, int w, int height, int width, RGBTRIPLE copy[height][width])
{
    int num = 0;
    float sum[3] = {0, 0, 0};

    RGBTRIPLE new_pixel;
    new_pixel.rgbtRed = 0;
    new_pixel.rgbtGreen = 0;
    new_pixel.rgbtBlue = 0;

    for (int i = h - 1; i < h + 2; i++)
    {
        for (int j = w - 1; j < w + 2; j++)
        {
            if (i >= 0 && i < height && j >= 0 && j < width)
            {
                sum[0] += copy[i][j].rgbtRed;
                sum[1] += copy[i][j].rgbtGreen;
                sum[2] += copy[i][j].rgbtBlue;
                num++;
            }
        }
    }

    new_pixel.rgbtRed = (int)round(sum[0] / num);
    new_pixel.rgbtGreen = (int)round(sum[1] / num);
    new_pixel.rgbtBlue = (int)round(sum[2] / num);
    return new_pixel;
}
