#include "grid.h"
#include <iostream>
using namespace std;
//CTORS:
grid::grid()
{
    x_length=0;
    y_length=0;
    for(int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            a[i][j]=0;
            copy[i][j]=0;
        }
    }
}
/* Function Definition:
 *
 * Function Name: SetAlive
 * Argument: int: i: row, int: j: column
 * Note I: Make a[i][j] alive
 */
void grid::SetAlive(int i, int j){
    a[i][j]=1;
}
/* Function Definition:
 *
 * Function Name: Kill
 * Argument: int: i: row, int: j: column
 * Note I: Make a[i][j] dead
 */
void grid::Kill(int i, int j){
    a[i][j]=0;
}
/* Function Definition:
 *
 * Function Name: IsAlive
 * Argument: int: i: row, int: j: column
 * Return: return true if a[i][j]==1
 */
bool grid::IsAlive(int i, int j){
    if(a[i][j]==1){
        return true;
    }
    return false;
}
/* Function Definition:
 *
 * Function Name: CountNeighbors
 * Argument: int: i: row, int: j: column
 * Return: Return the number of neighbors of a[i][j]
 * Note I: I used four if statement to prevent this function calculate outside of boundary
 */
int grid::CountNeighbors(int i, int j){
    int count=0;
    int c=i-1;
    int b=j-1;
    int d=i+1;
    int e=j+1;
    if(i==0){
        c=i;
    }
    if(j==0){
        b=j;
    }
    if(i==GRID_HEIGHT-1){
        d=i;
    }
    if(j==GRID_WIDTH-1){
        e=j;
    }
    for(int k=c; k<=d; k++){
        for(int h=b; h<=e; h++){
            if (a[k][h]==1){
                count++;
            }
        }
    }
    if(a[i][j]==1)
        count--;
    return count;
}
/* Function Definition:
 *
 * Function Name: Step
 * Note I: This function give value to copy[i][j] first and check the status of every cell
 * after finish, copy copy[i][j] to a[i][j]
 */
void grid::Step(){
    for(int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            copy[i][j]=CountNeighbors(i,j);
        }
    }
    CheckCell();
    Copy();
}
/* Function Definition:
 *
 * Function Name: CheckCell
 * Note I: After knowing how many neighbours each cell have, check status of each cell
 */
void grid::CheckCell(){
    for(int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            if(copy[i][j]==2){
                copy[i][j]=a[i][j];
            }
            else if(copy[i][j]==3)
                copy[i][j]=1;
            else{
                copy[i][j]=0;
            }
        }
    }
}
/* Function Definition:
 *
 * Function Name: Copy
 * Note I: copy copy[i][j] to a[i][j]
 */
void grid::Copy(){
    for(int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            a[i][j]=copy[i][j];
        }
    }
}
/* Function Definition:
 *
 * Function Name: show
 * Note I: show 2d array a[i][j]
 */
void grid::show(){
    for(int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            cout <<a[i][j]<<" ";
        }
        cout <<endl;
    }
}
/* Function Definition:
 *
 * Function Name: PopulaRandom
 * Argument: int r: numbers of random live cell you want to put on screen
 * Note I: create random live cell inside the grid
 */
void grid::PopulateRandom(int r){
    for(int i=0; i<r; i++){
        if(a[rand()%GRID_HEIGHT][rand()%GRID_WIDTH]==1){
            i--;
        }
        else{
            a[rand()%GRID_HEIGHT][rand()%GRID_WIDTH]=1;
        }
    }
}
/* Function Definition:
 *
 * Function Name: clear
 * Note I: make every content of a[i][j] = 0 , copy[i][j] = 0
 */
void grid::Clear(){
    for(int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            a[i][j]=0;
            copy[i][j]=0;
        }
    }
}
/* Function Definition:
 *
 * Function Name: array_value
 * Argument: int i: row, int j: column
 * Return: int: value of a[i][j]
 * Note I: use to access private
 */
int grid::array_value(int i,int j){
    return a[i][j];
}
/* Function Definition:
 *
 * Function Name: Save
 * Note I: to save the whole grid into file
 */
void grid::Save(){
    ofstream textFile;
    textFile.open("SimpleFile.txt");
    if(textFile.fail()){
        cout <<"Could not open output file..."<<endl;
        cin.get();
        exit(1);
    }
    for (int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            textFile << a[i][j] <<" ";
        }
        textFile <<endl;
    }
    textFile.close();
}
/* Function Definition:
 *
 * Function Name: load
 * Note I: to load the whole grid from file
 */
void grid::load(){
    ifstream inputFile;
    inputFile.open("SimpleFile.txt");
    if(inputFile.fail()){
        cout <<"There is no file..."<<endl;
        cin.get();
        exit(1);
    }
    for (int i=0; i<GRID_HEIGHT; i++){
        for(int j=0; j<GRID_WIDTH; j++){
            inputFile >> a[i][j];
        }
        cout <<endl;
    }
    inputFile.close();
}
/* Function Definition:
 *
 * Function Name: Savepattern
 * Argument: string: FileName: the name of file you want to save in, int x1: the row of first grid you pick
 * int y1: the column of first grid you pick, int x2: the row of second grid you pick,
 * int y2:the column of second grid you pick
 * Note I: to save the specific grid into specific file
 */
void grid::Savepattern(string FileName, int x1, int y1, int x2, int y2){
    int temp=0;
    if(x1>x2){
        temp=x1;
        x1=x2;
        x2=temp;
    }
    x_length=x2-x1;
    y_length=y2-y1;
    if(y1>y2){
        temp=y1;
        y1=y2;
        y2=temp;
    }
    ofstream textFile;
    textFile.open(FileName);
    if(textFile.fail()){
        cout <<"Could not open output file..."<<endl;
        cin.get();
        exit(1);
    }
    for (int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            textFile << a[i][j] <<" ";
        }
        textFile <<endl;
    }
    textFile.close();
}
/* Function Definition:
 *
 * Function Name: Savepattern
 * Argument: string: FileName: the name of file you want to load from,
 * int x: the row you want to load the pattern
 * int y: the column you want to load the pattern
 * Note I: to load the specific grid from file to screen
 */
void grid::Loadpattern(string FileName, int x, int y){
    ifstream inputFile;
    inputFile.open(FileName);
    if(inputFile.fail()){
        cout <<"There is no file..."<<endl;
        cin.get();
        exit(1);
    }
    for (int i=x; i<=x+x_length; i++){
        for(int j=y; j<=y+y_length; j++){
            inputFile >> a[i][j];
        }
        cout <<endl;
    }
    inputFile.close();
}
