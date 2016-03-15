//
//  1009.cpp
//  POJ
//
//  Created by Lincoln on 16/2/17.
//  Copyright © 2016年 Lincoln. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::vector;

struct pair
{
    int pixelValue;
    int nextPixelPos;
};

static void storeCandidate(set<int> & candidatePixels, int startPixelInImage, int width);
static int calculatePixel(int candidatePos, int width, int length, const vector<pair> & RLEs);
static void checkCandidate(set<int>::iterator iter, int width, int length, const vector<pair> & RLEs, set<int> & candidatePixels, int & previousEdge, int & startPixelOutImage);

static int absMax(int a, int b);
static int pixelAround(int x, int y, int width, int length, int center, const vector<pair> & RLEs);
static int pixelValueAt(int pos, const vector<pair> & RLEs);
static bool isValid(int x, int y, int width, int length);

// Here is a proposion :
// Each start point to output is adjacent to at least one start point from input.
// Prove:
//      1   2       3       4           5           6               7
//      |z| |- a|   |a b|   |..... z a|
//      |d| |b d|   |d x|   |b c . y d| |a b c ..|  |.. z a b c ..| |... z a b|
//      |x| |x g|   |g h|   |x f . w g| |d x f ..|  |.. y d x f ..| |c . y d x|
//      |f| |h i|   |i -|   |h i .....| |h i j ..|  |.. w g h i ..| |f . w g h|
//                                                                  |i .......|
//      |z| |- a|   |...|   |..... z a|
//      |d| |b d|   |a b|   |b c . y d|
//      |x| |x g|   |d x|   |x f . w g|
//       -   - -     - -     - - - - -
//     if x didn't adjacent to any start point from input, then must have:
//      1.  if d and x are in the same raw: (3 5 6 7)
//          we must have: (where a and f can be border '-')
//              a a a a     or  |a a a      or  a a a|      or  |a a|
//              d d x d         |d x d          d d x|          |d x|
//              f f f f         |f f f          f f f|          |f f|
//          in these cases, the output of pixel x is equal to output of pixel d, so x is not the start point.
//      2.  if d and x are not the same raw: and x is not the left bottom corenr, then we have:
//              |..... a a|
//              |a a . d d|
//              |x d . g g|
//              |g g .....|
//          also in these cases, the output of pixel x is equal to output of pixel d, so x is not the start point.
//      3. if x is the left bottom corner.
//              |..... a a|
//              |a a . d d|
//              |x d . g g|
//          because the pixel g, we can not deciside if x is the start point or not.

// Run Length Encoding
int edgeDetection()
{
    int width;
    while(cin >> width, width != 0)
    {
        int pixelValue, length;
        
        vector<pair> RLEs;
        
        int startPixelInImage = 0;              // the postion of the next start pixel of input image
        int startPixelOutImage = 0;             // the postion of the next start pixel of output image
        int previousEdge = 0;                   // maintain the output message
        
        set<int> candidatePixels;
        set<int>::iterator iter;
        
        cout << width << endl;
        while(cin >> pixelValue >> length, length != 0)
        {
            // store the candidate pixels in a set
            storeCandidate(candidatePixels, startPixelInImage, width);
            startPixelInImage += length;       // update
            
            pair rle;
            rle.pixelValue = pixelValue;
            rle.nextPixelPos = startPixelInImage;
            RLEs.push_back(rle);
            
            // get out one candidate, and check if have all needed pixels
            while(iter = candidatePixels.begin(), iter != candidatePixels.end() && (*iter + width + 1) < startPixelInImage)
            {
                // check the candidate pixel.
                checkCandidate(iter, width, -1, RLEs, candidatePixels, previousEdge, startPixelOutImage);
            }
        }
        // always add the exception in situation 3
        candidatePixels.insert(startPixelInImage - width);
        
        // deal with the last pixels.
        length = startPixelInImage / width;
        while(iter = candidatePixels.begin(), iter != candidatePixels.end())
        {
            if(*iter < startPixelInImage)
               checkCandidate(iter, width, length, RLEs, candidatePixels, previousEdge, startPixelOutImage);
            else
                break;
        }
        cout << previousEdge << ' ' << startPixelInImage - startPixelOutImage << endl;
        cout << "0 0\n";
    }
    cout << "0";
    
    return 0;
}

static void storeCandidate(set<int> & candidatePixels, int startPixelInImage, int width)
{
    int offsets[3] = {-1, 0, 1};
    
    int x = startPixelInImage % width;
    int y = startPixelInImage / width;
    
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            int pos = startPixelInImage + offsets[i] + offsets[j] * width;
            if(isValid(offsets[i] + x, offsets[j] + y, width, y + 2))
                candidatePixels.insert(pos);
        }
    }
}

static void checkCandidate(set<int>::iterator iter, int width, int length, const vector<pair> & RLEs, set<int> & candidatePixels, int & previousEdge, int & startPixelOutImage)
{
    int pos = *iter;
    int edge = calculatePixel(pos, width, length, RLEs);
    
    if(pos == 0)
        previousEdge = edge;
    
    if(previousEdge != edge && pos != 0)
    {
        cout << previousEdge << ' ' << pos - startPixelOutImage << endl;
        previousEdge = edge;
        startPixelOutImage = pos;
    }
    
    candidatePixels.erase(iter);
}

static int calculatePixel(int candidatePos, int width, int length, const vector<pair> & RLEs)
{
    int max = 0;
    int x = candidatePos % width;
    int y = candidatePos / width;
    int center = pixelValueAt(candidatePos, RLEs);
    
    if(length == -1)
        length = y + 2;
    
    int offsets[3] = {-1, 0, 1};
    
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            max = absMax(max , pixelAround(x + offsets[i], y + offsets[j], width, length, center, RLEs));
        }
    }
    
    return max;
}

static int absMax(int a, int b)
{
    int max;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    max = a > b ? a : b;
    
    return max;
}

static int pixelAround(int x, int y, int width, int length, int center, const vector<pair> & RLEs)
{
    int pos = x + y * width;
    
    if(length == -1)
        length = y + 1;
    
    if(isValid(x, y, width, length))
        return pixelValueAt(pos, RLEs) - center;
    
    return 0;
}

// can do better at this, to reduce time.
static int pixelValueAt(int pos, const vector<pair> & RLEs)
{
    for(vector<pair>::const_iterator iter = RLEs.begin(); iter != RLEs.end(); iter++)
    {
        if(iter->nextPixelPos > pos)
            return iter->pixelValue;
    }
    
    return -1;
}

static bool isValid(int x, int y, int width, int length)
{
    if(x < 0 || x == width || y < 0 || y == length)
        return false;
    return true;
}
