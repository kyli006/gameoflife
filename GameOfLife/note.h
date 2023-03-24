#ifndef NOTE_H
#define NOTE_H
#include<iostream>
using namespace std;





//Note for finishing this project:
//It's hard, but it's a wonderful learning experience

/* void grid::SetAlive and void grid::Kill and bool grid::IsAlive
 *
 * There three function are very basic but are very useful in processEvent
 *
 * SetAlive(int i, int j): Set a[i][j]=1;
 *
 * Kill(int i, int j): Set a[i][j]=0;
 *
 * IsAlive(int i, int j): Return true if a[i][j]==1;
 * -----------------------------------------------------------------------------------------------------
 *
 * void grid::Step
 *
 * Step(): is a big function that includes CountNeighbors, CheckCell and Copy, use for >> [Go] and [Step] button
 * -----------------------------------------------------------------------------------------------------
 *
 * void grid::PopulateRandom and void grid::Clear
 *
 * PopulateRandom(int r): create r numbers of random live cell inside the grid, use for >> [Random] button
 *
 * Clear(): make every content of a[i][j] = 0 , copy[i][j] = 0, use for >> [Clear] button
 * -----------------------------------------------------------------------------------------------------
 *
 * int grid::CountNeighbors(int i, int j) and void grid::CheckCell()
 *
 * These two functions are the the core of this program.
 *
 * CountNeighbors(): I first record how many neighbour each cell have, about boundary, I decide not to
 * count the cell outside the grid, so if the cell is on the boundary, it only counts the neighbours
 * which are inside the grid
 *
 * CheckCell(): if (neighbours ==1) then the copy[i][j] will dead and equal to 0, if (neighbours ==2)
 * copy[i][j] will remain same which mean copy[i][j] which equal to a[i][j], if(neighbours ==3) then copy[i][j]
 * will be alive and equal to 1; other than above case, copy[i][j] will be 0
 * -----------------------------------------------------------------------------------------------------
 *
 * void grid::Save() and void grid::load()
 *
 * At first, these two functions are weird for me. Because we haven't learn a lot about File, but overall, it
 * is easy to use and
 *
 * Save(): I use the basic pattern to write this function and make sure open the file at the beginning and close it at
 * the end, inputFile.fail() is very important, I wrote an error code there, so I can know exactly where got wrong.
 * I use this way to debug and it work effciently, use for >> [Save] button
 *
 * load(): It's almost the same procedure, I just follow the pattern and make sure I don't forget anything, use
 * for >> [Load] button
 * -----------------------------------------------------------------------------------------------------
 *
 * void grid::Savepattern and void grid::Loadpattern
 *
 * Compare to the basic Save and load, these two are more complicated. The diffculty for me is not writing this
 * function, it's how to use this function in sfml
 *
 * Savepattern(): this function take 5 argument, it can save the specific grid into specific file, I have set two if
 * statement to prevent player choose the larger coordinate for first point and smaller coordinate for second point.
 * It can save all the grid between two points I calculate their difference of row and column. So that I know where
 * is the end of pattern and when should I stop load the pattern. use for >> [savePattern] button
 *
 * Loadpattern(): this function take 3 argument, fileName is the name of file that is used to load. x and y are coordinate.
 * So the user could choose where to load the pattern. use for >> [loadPattern] button
 *
 * Savepattern() in sfml: This one is really an challenge. Once the user click Savepattern,in order to prevent mistake, I have to disable
 * the feature that could make the cell alive by clicking the grid. I also wrote the if else statement to distinguish the beginning
 * position and end position let the program know the first click in grid is for the beginning position. Second click is the end position and
 * then enforce the user to click the box in order to finish the whole procedure.After the whole process finish, we need to enable the
 * feature of clicking grid again.
 *
 * Loadpattern() in sfml: This one is simliar with Savepattern(), once user click this, I have to disable the feature of clicking grid
 * and prompt user to choose the position to load. After that, choose one of the pattern from 9 boxs. After the whole process finish,
 * we need to enable the feature of clicking grid again.
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::run
 *
 * run(): this is a big function and the simplest place to see how this program work, including processEvent(), update() and render(),
 * it will react the instruction, undate window until the window is closed
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::processEvent
 *
 * This is one of the most important part of this program. This function could connect the mousebutton with my program.
 * All my button and modification of grid are writting in here. You have to understand what this class do in order to
 * use processEvent properly. I do MouseMove here to change the color of button when user put their mouse on those button.
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::FillShapes and void Anime::ShowShapes
 *
 * Explanation: these two function are where I set the size of cell and draw the grid. It's important to know the GRID_WIDTH * CELL_SIZE
 * or GRID_HEIGHT * CELL_SIZE shouldn't larger than the size of the window. Otherwise, it's going to draw outside of window.
 * Moreover, I paint the cell when I create a grid. So I could see live cell and dead cell.
 * -----------------------------------------------------------------------------------------------------
 *
 * int Anime::findPos
 *
 * findPos(int x, int y): this function also very important, I have a switch inside this function. So when I call this function
 * in processEvent, it could tell me which button player is clicking. So the program can react properly.
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::update
 *
 * update(): this function will keep working when people click [Go] and will stop when click [Stop]
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::render
 *
 * render(): this function will renew the window and keep changing.
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::Text and void Anime::drawText
 *
 * Text(): will load the font
 *
 * drawText(): will draw the text to screen
 * -----------------------------------------------------------------------------------------------------
 *
 * void Anime::clickcolor
 *
 * clickcolor(int set): this function will know which button player is putting the mouse and change the color of
 * the bottom
 * -----------------------------------------------------------------------------------------------------
 */

















#endif // NOTE_H
