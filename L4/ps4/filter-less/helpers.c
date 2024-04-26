#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
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
            int tmpB = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            if (tmpB > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = tmpB;
            }

            int tmpG = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            if (tmpG > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = tmpG;
            }

            int tmpR = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            if (tmpR > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = tmpR;
            }
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

// A functino for blur
RGBTRIPLE box_blur(int h, int w, int height, int width, RGBTRIPLE copy[][]);

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
            image[i][j] = box_blur(i, j, height, width, copy[height][width]);
        }
    }
    return;
}

// Taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.
RGBTRIPLE box_blur(int h, int w, int height, int width, RGBTRIPLE copy[][])
{
    int num;
    RGBTRIPLE new;
    new.rgbtRed = 0;
    new.rgbtGreen = 0;
    new.rgbtBlue = 0;
    for (int i = h - 1; i < h + 2; i++)
    {
        for (int j = w - 1; j < w + 2; j++)
        {
            if (i > 0 && i < height && j > 0 && j < width)
            {
                new.rgbtRed += copy[i][j].rgbtRed;
                new.rgbtGreen += copy[i][j].rgbtGreen;
                new.rgbtBlue += copy[i][j].rgbtBlue;
                num++;
            }
        }
    }
    new.rgbtRed /= num;
    new.rgbtGreen /= num;
    new.rgbtBlue /= num;
    return new;
}
