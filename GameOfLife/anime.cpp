#include "anime.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "grid.h"
//CTORS:
Anime::Anime()
{
    //create window and select the fps
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Of Life");
    window.setFramerateLimit(40);

    //Fill the Grid
    FillShapes();
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    //Load the Font
    Text();

    //Design Clear button
    clear.setFont(font);
    clear.setString("Clear");
    clear.setCharacterSize(45);
    clear.setFillColor(sf::Color::Red);
    clear.setPosition(1314,96);

    //Design Random button
    random.setFont(font);
    random.setString("Random");
    random.setCharacterSize(45);
    random.setFillColor(sf::Color::Red);
    random.setPosition(1314,196);

    //Design Step button
    step.setFont(font);
    step.setString("Step");
    step.setCharacterSize(45);
    step.setFillColor(sf::Color::Red);
    step.setPosition(1314,296);

    //Design Go button
    go.setFont(font);
    go.setString("Go");
    go.setCharacterSize(45);
    go.setFillColor(sf::Color::Red);
    go.setPosition(1314,396);

    //Design Stop button
    stop.setFont(font);
    stop.setString("Stop");
    stop.setCharacterSize(45);
    stop.setFillColor(sf::Color::Red);
    stop.setPosition(1314,496);

    //Design Save button
    save.setFont(font);
    save.setString("Save");
    save.setCharacterSize(45);
    save.setFillColor(sf::Color::Red);
    save.setPosition(1314,596);

    //Design Load button
    load.setFont(font);
    load.setString("Load");
    load.setCharacterSize(45);
    load.setFillColor(sf::Color::Red);
    load.setPosition(1314,696);

    //Design SavePattern button
    savepattern.setFont(font);
    savepattern.setString("SavePattern");
    savepattern.setCharacterSize(35);
    savepattern.setFillColor(sf::Color::Magenta);
    savepattern.setPosition(1314,796);

    //Design LoadPattern button
    loadpattern.setFont(font);
    loadpattern.setString("LoadPattern");
    loadpattern.setCharacterSize(35);
    loadpattern.setFillColor(sf::Color::Magenta);
    loadpattern.setPosition(1314,896);

    //Design BOX1 button
    box1.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box1.setFillColor(sf::Color::Green);
    box1.setPosition(1314,996);

    //Design BOX2 button
    box2.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box2.setFillColor(sf::Color::Green);
    box2.setPosition(1314+BOX_SIZE+1,996);

    //Design BOX3 button
    box3.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box3.setFillColor(sf::Color::Green);
    box3.setPosition(1314+2*BOX_SIZE+2,996);

    //Design BOX4 button
    box4.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box4.setFillColor(sf::Color::Green);
    box4.setPosition(1314,996+BOX_SIZE+1);

    //Design BOX5 button
    box5.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box5.setFillColor(sf::Color::Green);
    box5.setPosition(1314+BOX_SIZE+1,996+BOX_SIZE+1);

    //Design BOX6 button
    box6.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box6.setFillColor(sf::Color::Green);
    box6.setPosition(1314+2*BOX_SIZE+2,996+BOX_SIZE+1);

    //Design BOX7 button
    box7.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box7.setFillColor(sf::Color::Green);
    box7.setPosition(1314,996+2*BOX_SIZE+2);

    //Design BOX8 button
    box8.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box8.setFillColor(sf::Color::Green);
    box8.setPosition(1314+BOX_SIZE+1,996+2*BOX_SIZE+2);

    //Design BOX9 button
    box9.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box9.setFillColor(sf::Color::Green);
    box9.setPosition(1314+2*BOX_SIZE+2,996+2*BOX_SIZE+2);

    //for Go button, SavePattern button and LoadPattern button
    On = false;
    Save=false;
    Load=false;

    //for SavePattern and LoadPattern
    x1=-1;
    x2=-1;
    y1=-1;
    y2=-1;
    x_set=-1;
    y_set=-1;
}
/* Function Definition:
 *
 * Function Name: run
 * Note I: to keep the window and program updating
 */
void Anime::run()
{
    while(window.isOpen()){
        processEvent();
        update();
        render();
    }
}
/* Function Definition:
 *
 * Function Name: processEvent
 * Note I: to react player's instruction
 */
void Anime::processEvent()
{
    int x;
    int y;
    sf::Event event;
    while(window.pollEvent(event)){
        switch (event.type) {
        //when player close the window
        case sf::Event::Closed:
            window.close();
            break;
        //when player move through the button, the button will change color
        case sf::Event::MouseMoved:
            switch (findPos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
            case 1:
                set = 1;
                break;
            case 2:
                set = 2;
                break;
            case 3:
                set = 3;
                break;
            case 4:
                set = 4;
                break;
            case 5:
                set = 5;
                break;
            case 6:
                set = 6;
                break;
            case 7:
                set = 7;
                break;
            case 8:
                set = 8;
                break;
            case 9:
                set = 9;
                break;
            case 10:
                set = 10;
                break;
            case 11:
                set = 11;
                break;
            case 12:
                set = 12;
                break;
            case 13:
                set = 13;
                break;
            case 14:
                set = 14;
                break;
            case 15:
                set = 15;
                break;
            case 16:
                set = 16;
                break;
            case 17:
                set = 17;
                break;
            case 18:
                set = 18;
                break;
            default:
                set = 0;
                break;
            }
            clickcolor(set);
            break;
        //when player Click the window with the left mouse button
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left){
                //player could click one grid to make the cell alive or dead
                if(event.mouseButton.x>=0 && event.mouseButton.x<=GRID_WIDTH*(CELL_SIZE+1) &&
                   event.mouseButton.y>=0 && event.mouseButton.y <=GRID_HEIGHT*(CELL_SIZE+1) &&
                   Save == false && Load == false){
                    y=event.mouseButton.y/(CELL_SIZE+1);
                    x=event.mouseButton.x/(CELL_SIZE+1);
                    if(a.IsAlive(y,x)){
                        a.Kill(y,x);
                    }
                    else{
                        a.SetAlive(y,x);
                    }
                }
                //to distinguish the event between the left side of window and right side
                else{
                    //to save specific Grid by letting people choose where they want to save
                    if(Save){
                        if(x1 ==-1 && y1==-1){
                            y1=event.mouseButton.x/(CELL_SIZE+1);
                            x1=event.mouseButton.y/(CELL_SIZE+1);
                        }
                        else{
                            if(x2 ==-1 && y2 ==-1){
                                y2=event.mouseButton.x/(CELL_SIZE+1);
                                x2=event.mouseButton.y/(CELL_SIZE+1);
                            }
                            //choose which boxs player want to save
                            else{
                                switch (findPos(event.mouseButton.x,event.mouseButton.y)) {
                                case 10:
                                    a.Savepattern("Pattern01.txt",x1,y1,x2,y2);
                                    break;
                                case 11:
                                    a.Savepattern("Pattern02.txt",x1,y1,x2,y2);
                                    break;
                                case 12:
                                    a.Savepattern("Pattern03.txt",x1,y1,x2,y2);
                                    break;
                                case 13:
                                    a.Savepattern("Pattern04.txt",x1,y1,x2,y2);
                                    break;
                                case 14:
                                    a.Savepattern("Pattern05.txt",x1,y1,x2,y2);
                                    break;
                                case 15:
                                    a.Savepattern("Pattern06.txt",x1,y1,x2,y2);
                                    break;
                                case 16:
                                    a.Savepattern("Pattern07.txt",x1,y1,x2,y2);
                                    break;
                                case 17:
                                    a.Savepattern("Pattern08.txt",x1,y1,x2,y2);
                                    break;
                                case 18:
                                    a.Savepattern("Pattern09.txt",x1,y1,x2,y2);
                                    break;
                                default:
                                    cout <<"Wrong box!"<<endl;
                                }
                                Save=false;
                                x1=-1;
                                x2=-1;
                                y1=-1;
                                y2=-1;
//                                loadpattern.setFillColor(sf::Color::Magenta);
                            }
                        }
                    }
                    //to Load Specific pattern from specific box to the Specific Position
                    else if(Load){
                        if(y_set ==-1 && x_set ==-1){
                            y_set=event.mouseButton.x/(CELL_SIZE+1);
                            x_set=event.mouseButton.y/(CELL_SIZE+1);
                        }
                        //Choose which boxs player want to save in
                        else{
                            switch (findPos(event.mouseButton.x,event.mouseButton.y)) {
                            case 10:
                                a.Loadpattern("Pattern01.txt",x_set,y_set);
                                break;
                            case 11:
                                a.Loadpattern("Pattern02.txt",x_set,y_set);
                                break;
                            case 12:
                                a.Loadpattern("Pattern03.txt",x_set,y_set);
                                break;
                            case 13:
                                a.Loadpattern("Pattern04.txt",x_set,y_set);
                                break;
                            case 14:
                                a.Loadpattern("Pattern05.txt",x_set,y_set);
                                break;
                            case 15:
                                a.Loadpattern("Pattern06.txt",x_set,y_set);
                                break;
                            case 16:
                                a.Loadpattern("Pattern07.txt",x_set,y_set);
                                break;
                            case 17:
                                a.Loadpattern("Pattern08.txt",x_set,y_set);
                                break;
                            case 18:
                                a.Loadpattern("Pattern09.txt",x_set,y_set);
                                break;
                            default:
                                cout <<"Wrong box!"<<endl;
                            }
                            Load=false;
                            x_set=-1;
                            y_set=-1;
                        }
                    }
                    //for buttons
                    else{
                        switch(findPos(event.mouseButton.x,event.mouseButton.y)){
                        case 1:
                            a.Clear();
                            break;
                        case 2:
                            a.PopulateRandom(50);
                            break;
                        case 3:
                            a.Step();
                            break;
                        case 4:
                            a.Step();
                            On = true;
                            break;
                        case 5:
                            On = false;
                            break;
                        case 6:
                            a.Save();
                            break;
                        case 7:
                            a.load();
                            break;
                        case 8:
                            Save=true;
                            break;
                        case 9:
                            Load=true;
                            break;
                        default:
                            break;
                        }
                    }
                }
                std::cout << "the left button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
            else
                std::cout<<"right button was pressed"<<std::endl;
            break;
        default:
            break;
        }
    }
}
/* Function Definition:
 *
 * Function Name: FillShapes
 * Note I: to fill the Grid and check if the cell is alive
 * alive: Red. Dead: White.
 */
void Anime::FillShapes(){
    for (int row=0; row<GRID_HEIGHT; row++){
        for (int col=0; col<GRID_WIDTH; col++){
            int vectorY=row*(CELL_SIZE+1);
            int vectorX=col*(CELL_SIZE+1);
            shapeArray[row][col].setSize(sf::Vector2f(CELL_SIZE,CELL_SIZE));
            shapeArray[row][col].setPosition(sf::Vector2f(vectorX,vectorY));
            if(a.array_value(row,col) == 1)
            {
                shapeArray[row][col].setFillColor(sf::Color::Red);
            }
            else
            {
                shapeArray[row][col].setFillColor(sf::Color::White);
            }
        }
    }
}
/* Function Definition:
 *
 * Function Name: ShowShapes
 * Note I: to show Grid we Fill
 */
void Anime::ShowShapes()
{
    for (int row=0; row<GRID_HEIGHT; row++){
        for (int col=0; col<GRID_WIDTH; col++){
            window.draw(shapeArray[row][col]);
        }
    }
}
/* Function Definition:
 *
 * Function Name: undate
 * Note I: to let the cell keep running unless click Stop
 */
void Anime::update()
{
    if(On){
        a.Step();
    }
}
/* Function Definition:
 *
 * Function Name: render
 * Note I: Put the Grid and Button up
 */
void Anime::render()
{
    window.clear(sf::Color::Yellow);
    FillShapes();
    drawText();
    ShowShapes();
    window.display();
}
/* Function Definition:
 *
 * Function Name: Text
 * Note I: Load Font
 */
void Anime::Text()
{
    if(!font.loadFromFile("tarzeau_ocr_a.ttf")){
        cout<<"can't open!"<<endl;
    }
}
/* Function Definition:
 *
 * Function Name: drawText
 * Note I: draw every button to the screen
 */
void Anime::drawText()
{
    window.draw(clear);
    window.draw(random);
    window.draw(step);
    window.draw(go);
    window.draw(stop);
    window.draw(save);
    window.draw(load);
    window.draw(savepattern);
    window.draw(loadpattern);
    window.draw(box1);
    window.draw(box2);
    window.draw(box3);
    window.draw(box4);
    window.draw(box5);
    window.draw(box6);
    window.draw(box7);
    window.draw(box8);
    window.draw(box9);
}
/* Function Definition:
 *
 * Function Name: findPos
 * Argument: int x:column, int y: row
 * Return: int: index to indicate which buttons player has click
 * Note I: find out their specific location in the window
 */
int Anime::findPos(int x, int y)
{
    //clear
    if(x>=1322 && y >=104 && x<=1466 && y<=144)
        return 1;
    //random
    if(x>=1320 && y>=210 && x<=1498 && y<=240)
        return 2;
    //step
    if(x>=1318 && y>=308 && x<=1430 && y<=346)
        return 3;
    //go
    if(x>=1318 && y>=408 && x<=1374 && y<=438)
        return 4;
    //stop
    if(x>=1318 && y>=506 && x<=1434 && y<=544)
        return 5;
    //save
    if(x>=1320 && y>=610 && x<=1435 && y<=644)
        return 6;
    //load
    if(x>=1316 && y>=706 && x<=1438 && y<=738)
        return 7;
    //savepattern
    if(x>=1318 && y>=808 && x<=1584 && y<=828)
        return 8;
    //loadpattern
    if(x>=1318 && y>=906 && x<=1584 && y<=930)
        return 9;
    //box1
    if(x>=1314 && y>=994 && x<=1366 && y<=1050)
        return 10;
    //box2
    if(x>=1370 && y>=994 && x<=1424 && y<=1050)
        return 11;
    //box3
    if(x>=1428 && y>=994 && x<=1480 && y<=1050)
        return 12;
    //box4
    if(x>=1316 && y>=1054 && x<=1366 && y<=1106)
        return 13;
    //box5
    if(x>=1370 && y>=1054 && x<=1424 && y<=1106)
        return 14;
    //box6
    if(x>=1428 && y>=1054 && x<=1480 && y<=1106)
        return 15;
    //box7
    if(x>=1314 && y>=1110 && x<=1366 && y<=1162)
        return 16;
    //box8
    if(x>=1372 && y>=1110 && x<=1424 && y<=1162)
        return 17;
    //box9
    if(x>=1428 && y>=1110 && x<=1480 && y<=1162)
        return 18;
    return 0;
}
/* Function Definition:
 *
 * Function Name: clickcolor
 * Argument: int set: index indicate which buttons to change color
 */
void Anime::clickcolor(int set){
    switch (set) {
    //clear
    case 1:
        clear.setFillColor(sf::Color::Blue);
        break;
    //random
    case 2:
        random.setFillColor(sf::Color::Blue);
        break;
    //step
    case 3:
        step.setFillColor(sf::Color::Blue);
        break;
    //go
    case 4:
        go.setFillColor(sf::Color::Blue);
        break;
    //stop
    case 5:
        stop.setFillColor(sf::Color::Blue);
        break;
    //save
    case 6:
        save.setFillColor(sf::Color::Blue);
        break;
    //load
    case 7:
        load.setFillColor(sf::Color::Blue);
        break;
    //savepattern
    case 8:
        savepattern.setFillColor(sf::Color::Blue);
        break;
    //loadpattern
    case 9:
        loadpattern.setFillColor(sf::Color::Blue);
        break;
    //box1
    case 10:
        box1.setFillColor(sf::Color::Blue);
        break;
    //box2
    case 11:
        box2.setFillColor(sf::Color::Blue);
        break;
    //box3
    case 12:
        box3.setFillColor(sf::Color::Blue);
        break;
    //box4
    case 13:
        box4.setFillColor(sf::Color::Blue);
        break;
    //box5
    case 14:
        box5.setFillColor(sf::Color::Blue);
        break;
    //box6
    case 15:
        box6.setFillColor(sf::Color::Blue);
        break;
    //box7
    case 16:
        box7.setFillColor(sf::Color::Blue);
        break;
    //box8
    case 17:
        box8.setFillColor(sf::Color::Blue);
        break;
    //box9
    case 18:
        box9.setFillColor(sf::Color::Blue);
        break;
    default:
        clear.setFillColor(sf::Color::Red);
        random.setFillColor(sf::Color::Red);
        step.setFillColor(sf::Color::Red);
        go.setFillColor(sf::Color::Red);
        stop.setFillColor(sf::Color::Red);
        save.setFillColor(sf::Color::Red);
        load.setFillColor(sf::Color::Red);
        savepattern.setFillColor(sf::Color::Magenta);
        loadpattern.setFillColor(sf::Color::Magenta);
        box1.setFillColor(sf::Color::Green);
        box2.setFillColor(sf::Color::Green);
        box3.setFillColor(sf::Color::Green);
        box4.setFillColor(sf::Color::Green);
        box5.setFillColor(sf::Color::Green);
        box6.setFillColor(sf::Color::Green);
        box7.setFillColor(sf::Color::Green);
        box8.setFillColor(sf::Color::Green);
        box9.setFillColor(sf::Color::Green);

        break;
    }
}
