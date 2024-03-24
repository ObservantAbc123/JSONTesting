#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Sprite
{
public:
    //vector<vector<vector<int>>> frames;

    Sprite(vector<vector<vector<int>>> framez);
    void rotateClockwise();
    void rotateCounterClockWise();
    string iterateFrames();
    string json;
    vector<vector<vector<int>>> frames;
    string colors[4] = {"red", "green", "blue", "alpha"};
    string convertToJson();

private:
    int dimensionSquared;
};



#endif // SPRITE_H