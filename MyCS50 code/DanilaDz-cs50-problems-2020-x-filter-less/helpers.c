#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // avarage of colors to make grey
            float gray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);
            
            image[j][i].rgbtRed = gray;
            image[j][i].rgbtGreen = gray;
            image[j][i].rgbtBlue = gray;
        }
    }
    
    return;
}
// makes sure there is no overflow
int max(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }
    return rgb;
}



// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // does a function that converts regular colors to sepia
            int sepiaRed = max(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));
            int sepiaGreen = max(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            int sepiaBlue = max(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));
            
            // sets the original colors to sepia
            image[j][i].rgbtRed = sepiaRed;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtBlue = sepiaBlue;
        }
    }
    
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
 
    for (int i = 0; i < (width / 2); i++)
    {
        for (int j = 0; j < height; j++)
        {
            // place holder for colors
            int hold_red = image[j][i].rgbtRed;
            int hold_green = image[j][i].rgbtGreen;
            int hold_blue = image[j][i].rgbtBlue;
        
            // swaps the pixels around to reflect image
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
        
            image[j][width - i - 1].rgbtRed = hold_red;
            image[j][width - i - 1].rgbtGreen = hold_green;
            image[j][width - i - 1].rgbtBlue = hold_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //makes a copy of the image
    RGBTRIPLE copy[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            float pixels = 0.00;
            
            // loops through pixels around one pixel to determine what values to use to blur the pixel
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if (i + a < 0 || i + a > height - 1 || j + b < 0 || j + b > width - 1)
                    {
                        continue;
                    }
                    red += image[i + a][j + b].rgbtRed;
                    green += image[i + a][j + b].rgbtGreen;
                    blue += image[i + a][j + b].rgbtBlue;
                    pixels++;
                }
            }

            // equation to blur the image
            copy[j][i].rgbtRed = round(red / pixels);
            copy[j][i].rgbtGreen = round(green / pixels);
            copy[j][i].rgbtBlue = round(blue / pixels);
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
