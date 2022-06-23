#include "buildMapLayouts.h"

// Build 1-st map layout
bool** buildMapLayout1(unsigned height, unsigned width)
{
    bool** mapLayout1 = 0;
    mapLayout1 = new bool* [height];

    for (int i = 0; i < height; i++)
    {
        mapLayout1[i] = new bool[width];

        // Build to the different rows
        switch (i)
        {
        case 0:
        case 1:
        case 2:
        case 25:
        case 26:
            // Build to rows 0, 1, 2, 25, 26
            for (int j = 0; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 3:
            // Build to row 3
            for (int j = 0; j <= 13; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 14; j <= 21; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 22; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 4:
            // Build to row 4
            for (int j = 0; j <= 12; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 13; j <= 24; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 25; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 5:
            // Build to row 5
            for (int j = 0; j <= 11; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 12; j <= 28; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 29; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 6:
            // Build to row 6
            for (int j = 0; j <= 10; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 11; j <= 30; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 31; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 7:
            // Build to row 7
            for (int j = 0; j <= 8; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 9; j <= 31; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 8:
            // Build to row 8
            for (int j = 0; j <= 7; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 8; j <= 31; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 9:
        case 10:
            // Build to rows 9 and 10
            for (int j = 0; j <= 6; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 7; j <= 31; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 11:
            // Build to row 11
            for (int j = 0; j <= 5; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 6; j <= 32; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 33; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 12:
            // Build to row 12
            for (int j = 0; j <= 4; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 5; j <= 32; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 33; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 13:
            // Build to row 13
            for (int j = 0; j <= 3; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 4; j <= 34; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 35; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 14:
            // Build to row 14
            for (int j = 0; j <= 3; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 4; j <= 35; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 15:
            // Build to row 15
            for (int j = 0; j <= 4; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 5; j <= 35; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 16:
            // Build to row 16
            for (int j = 0; j <= 5; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 6; j <= 35; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 17:
            // Build to row 17
            for (int j = 0; j <= 6; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 7; j <= 34; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 35; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 18:
            // Build to row 18
            for (int j = 0; j <= 6; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 7; j <= 33; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 34; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 19:
            // Build to row 19
            for (int j = 0; j <= 6; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 7; j <= 31; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 20:
            // Build to row 20
            for (int j = 0; j <= 7; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 8; j <= 30; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 31; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 21:
            // Build to row 21
            for (int j = 0; j <= 9; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 10; j <= 28; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 29; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 22:
            // Build to row 22
            for (int j = 0; j <= 12; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 13; j <= 27; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 28; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 23:
            // Build to row 23
            for (int j = 0; j <= 13; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 14; j <= 24; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 25; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        case 24:
            // Build to row 24
            for (int j = 0; j <= 16; j++)
            {
                mapLayout1[i][j] = false;
            }
            for (int j = 17; j <= 22; j++)
            {
                mapLayout1[i][j] = true;
            }
            for (int j = 23; j < width; j++)
            {
                mapLayout1[i][j] = false;
            }
            break;
        }
    }

    // return the newly built map layout
    return mapLayout1;
}

// Build 2-nd map layout
bool** buildMapLayout2(unsigned height, unsigned width)
{
    bool** mapLayout2 = 0;
    mapLayout2 = new bool* [height];

    for (int i = 0; i < height; i++)
    {
        mapLayout2[i] = new bool[width];

        // Build to the different rows
        switch (i)
        {
        case 0:
        case 1:
        case 26:
            // Build to rows 0, 1 and 26
            for (int j = 0; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 2:
            // Build to row 2
            for (int j = 0; j <= 9; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 10; j <= 16; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 17; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 3:
            // Build to row 3
            for (int j = 0; j <= 8; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 9; j <= 18; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 19; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 4:
            // Build to row 4
            for (int j = 0; j <= 6; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 7; j <= 19; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 20; j <= 26; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 27; j <= 30; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 31; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 5:
            // Build to row 5
            for (int j = 0; j <= 5; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 6; j <= 20; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 21; j <= 25; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 26; j <= 32; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 33; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 6:
            // Build to row 6
            for (int j = 0; j <= 4; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 5; j <= 19; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 20; j <= 24; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 25; j <= 33; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 34; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 7:
            // Build to row 7
            for (int j = 0; j <= 4; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 5; j <= 16; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 17; j <= 24; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 25; j <= 34; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 35; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 8:
            // Build to row 8
            for (int j = 0; j <= 3; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 4; j <= 15; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 16; j <= 25; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 26; j <= 35; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 9:
            // Build to row 9
            for (int j = 0; j <= 3; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 4; j <= 14; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 15; j <= 26; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 27; j <= 35; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 10:
            // Build to row 10
            for (int j = 0; j <= 2; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 3; j <= 13; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 14; j <= 27; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 28; j <= 36; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 11:
            // Build to row 11
            for (int j = 0; j <= 2; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 3; j <= 13; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 14; j <= 27; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 28; j <= 36; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 12:
            // Build to row 12
            for (int j = 0; j <= 1; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 2; j <= 13; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 14; j <= 26; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 27; j <= 36; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 13:
            // Build to row 13
            for (int j = 0; j <= 1; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 2; j <= 14; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 15; j <= 26; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 27; j <= 36; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 14:
            // Build to row 14
            for (int j = 0; j <= 1; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 2; j <= 15; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 16; j <= 25; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 26; j <= 36; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 15:
            // Build to row 15
            for (int j = 0; j <= 1; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 2; j <= 16; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 17; j <= 24; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 25; j <= 36; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 16:
            // Build to row 16
            for (int j = 0; j <= 2; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 3; j <= 17; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 18; j <= 23; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 24; j <= 35; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 17:
            // Build to row 17
            for (int j = 0; j <= 2; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 3; j <= 35; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 18:
        case 19:
            // Build to rows 18 and 19
            for (int j = 0; j <= 3; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 4; j <= 34; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 35; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 20:
            // Build to row 20
            for (int j = 0; j <= 4; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 5; j <= 33; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 34; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 21:
            // Build to row 21
            for (int j = 0; j <= 4; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 5; j <= 31; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 22:
            // Build to row 22
            for (int j = 0; j <= 5; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 6; j <= 31; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 23:
            // Build to row 23
            for (int j = 0; j <= 6; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 7; j <= 30; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 31; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 24:
            // Build to row 24
            for (int j = 0; j <= 8; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 9; j <= 27; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 28; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        case 25:
            // Build to row 25
            for (int j = 0; j <= 9; j++)
            {
                mapLayout2[i][j] = false;
            }
            for (int j = 10; j <= 25; j++)
            {
                mapLayout2[i][j] = true;
            }
            for (int j = 26; j < width; j++)
            {
                mapLayout2[i][j] = false;
            }
            break;
        }
    }

    // return the newly built map layout
    return mapLayout2;
}

// Build 3-rd map layout
bool** buildMapLayout3(unsigned height, unsigned width)
{
    bool** mapLayout3 = 0;
    mapLayout3 = new bool* [height];

    for (int i = 0; i < height; i++)
    {
        mapLayout3[i] = new bool[width];

        // Build to the different rows
        switch (i)
        {
        case 0:
        case 26:
            // Build to rows 0 and 26
            for (int j = 0; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 1:
            // Build to row 1
            for (int j = 0; j <= 19; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 20; j <= 29; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 30; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 2:
            // Build to row 2
            for (int j = 0; j <= 15; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 16; j <= 30; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 31; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 3:
            // Build to row 3
            for (int j = 0; j <= 11; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 12; j <= 31; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 32; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 4:
            // Build to row 4
            for (int j = 0; j <= 9; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 10; j <= 33; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 34; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 5:
            // Build to row 5
            for (int j = 0; j <= 7; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 8; j <= 34; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 35; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 6:
            // Build to row 6
            for (int j = 0; j <= 7; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 8; j <= 35; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 7:
        case 8:
            // Build to rows 7 and 8
            for (int j = 0; j <= 6; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 7; j <= 36; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 9:
        case 10:
            // Build to rows 9 and 10
            for (int j = 0; j <= 5; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 6; j <= 37; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 38; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 11:
            // Build to row 11
            for (int j = 0; j <= 4; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 5; j <= 38; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 39; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 12:
        case 13:
            // Build to rows 12 and 13
            for (int j = 0; j <= 3; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 4; j <= 38; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 39; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 14:
        case 15:
        case 16:
        case 17:
            // Build to rows 14, 15, 16 and 17
            for (int j = 0; j <= 2; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 3; j <= 38; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 39; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 18:
            // Build to row 18
            for (int j = 0; j <= 2; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 3; j <= 21; j++)
            {
                mapLayout3[i][j] = true;
            }

            mapLayout3[i][22] = false;

            for (int j = 23; j <= 38; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 39; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 19:
            // Build to row 19
            for (int j = 0; j <= 4; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 5; j <= 19; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 20; j <= 23; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 24; j <= 37; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 38; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 20:
            // Build to row 20
            for (int j = 0; j <= 9; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 10; j <= 19; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 20; j <= 25; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 26; j <= 37; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 38; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 21:
            // Build to row 21
            for (int j = 0; j <= 11; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 12; j <= 18; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 19; j <= 26; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 27; j <= 37; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 38; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 22:
            // Build to row 22
            for (int j = 0; j <= 13; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 14; j <= 18; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 19; j <= 27; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 28; j <= 36; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 37; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 23:
            // Build to row 23
            for (int j = 0; j <= 14; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 15; j <= 17; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 18; j <= 28; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 29; j <= 35; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 36; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 24:
            // Build to row 24
            for (int j = 0; j <= 28; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 29; j <= 34; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 35; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        case 25:
            // Build to row 25
            for (int j = 0; j <= 29; j++)
            {
                mapLayout3[i][j] = false;
            }
            for (int j = 30; j <= 32; j++)
            {
                mapLayout3[i][j] = true;
            }
            for (int j = 33; j < width; j++)
            {
                mapLayout3[i][j] = false;
            }
            break;
        }
    }

    // return the newly built map layout
    return mapLayout3;
}