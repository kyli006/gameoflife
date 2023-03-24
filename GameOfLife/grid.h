#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <fstream>
#include "const.h"
using namespace std;
class grid
{
public:
    grid();
    void SetAlive(int i, int j);
    void Kill(int i, int j);
    bool IsAlive(int i, int j);
    int CountNeighbors(int i,int j);
    void CheckCell();
    void Step();
    void Copy();
    void show();
    void Save();
    void load();
    void Savepattern(string FileName, int x1, int y1, int x2, int y2);
    void Loadpattern(string FileName, int x, int y);
    void PopulateRandom(int r);
    void Clear();
    int array_value(int i,int j);
private:
    int a[GRID_HEIGHT][GRID_WIDTH];
    int copy[GRID_HEIGHT][GRID_WIDTH];
    int x_length;
    int y_length;
};

#endif // GRID_H
