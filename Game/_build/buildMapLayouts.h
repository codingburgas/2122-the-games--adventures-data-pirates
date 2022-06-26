#pragma once

// Data for every block of the map
struct mapData {
    bool drawKey = true;
    bool grassKey = false;
    bool spKey = false;
};

// Build 1-st map layout
bool** buildMapLayout1(int height, int width);

// Build 2-nd map layout
bool** buildMapLayout2(int height, int width);

// Build 3-rd map layout
bool** buildMapLayout3(int height, int width);