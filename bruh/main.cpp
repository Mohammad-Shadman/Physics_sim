//#include <curses.h>
//#include "wall/wall.h"
//#include "stdlib.h"
//#include <iostream>
#include "vector/vector.h"
#include "physics/physics.h"
#include "line/line.h"
#include <conio.h>

#include <fstream>

//compile command for ncurses
//g++ main.cpp vector/vector.cpp vector/vector.h physics/physics.cpp physics/physics.h -LC:\MinGW\lib\libpdcurses -llibpdcurses

//main compile command
//g++ main.cpp vector/vector.cpp vector/vector.h physics/physics.cpp physics/physics.h line/line.cpp line/line.h


void updateFile(std::ofstream &myFile,Vector player){
    myFile.open("Data.csv",std::ios::out);

    myFile<<"player.x,player.y\n";
    myFile << player.x<<","<<player.y<<"\n";
    
        
    myFile.close();
    
}


int main (){
    /*
    initscr();
    noecho();
    cbreak();
    //halfdelay(1);
    raw();
    //nodelay(stdscr, true);
    */
    //enum dir {FILL,VERT,HORZ};
    //enum rep {FILLER,RIGHT,LEFT,UP,DOWN};
    //Wall up (Wall::DOWN,u);
    //Wall left (Wall::RIGHT,l);
    //Wall down (Wall::UP,d);
    //Wall right (Wall::LEFT,r);
    //Data<< "x,y"<<std::endl;
    //float u=0,d=50,r=100,l=0,
    
    float n=1;
    std::ofstream Data;
    std::ofstream lines_f;
    Vector pos (50,60);
    Physics p (pos, 0.75,4,1,1);
    Line lines[] = {Line( Vector(40,50), Vector(70,50),1 ), Line (Vector(80,10),Vector(80,100),1)};
    int nol=1;//nomber of lines
    lines_f.open("lines.csv",std::ios::out);
    for (int i = 0; i<nol;i++){
        lines_f << lines[i].a.x<<","<<lines[i].a.y<<","<<lines[i].b.x<< ","<<lines[i].b.y<<"\n";
    }
    lines_f.close();
    char key;
    float force=0.1;
    int prev_v;
    while(n==1){
        key = _getch();
        //gets the key that is being pressed with conio or curses and likes each key to a direction
        switch(key){
            case 'a':
                p.addf(Vector(-force,0));
                break;
            case 'd':
                p.addf(Vector(force,0));
                break;
            case 'w':
                p.addf(Vector(0,-force));
                break;
            case 's':
                p.addf(Vector(0,force));
                break;
            case 'k':
                n=0;
        }
        //if (p.plr.y < 29) { p.acc.y +=.2;}

        //if (key != 'w'|| key != 'a'|| key != 's'|| key != 'd'){p.fric();} <- old code for applying faux friction 
        
        if (p.acc.mag() < 0.1){p.acc.scale(0);}// on ice prevention
        
        if (p.plr.y > 30){
          //p.plr.y-=.1;
          if (p.vel.y > 0){p.vel.y*=-0.99;p.plr.y += p.vel.y;}
        }
        for(int i=0;i<nol;i++){
            lines[i].fricCalc(p);
            lines[i].findAltitude(p);
        }
        p.applyForces(0.8,0.3,1,Vector(.5,0));
        //p.acc = up.collision(p);
        //p.acc = down.collision(p);
        //p.acc = left.collision(p);
        //p.acc = right.collision(p);
        //Wall collision (p);
        pos = p.apply();
        
        updateFile(Data, p.plr);
        /*
        old ncurses code ment for the console version
        clear();
        mvprintw(1,1,"pos (x = %.2f , y = %.2f), vel (x = %.2f , y = %.2f , mag = %.2f), acc (x = %.2f , y = %.2f , mag = %.2f)", pos.x, pos.y, p.vel.x, p.vel.y, p.vel.mag(), p.acc.x, p.acc.y, p.acc.mag());
        mvaddch(pos.y,pos.x,'@');
        refresh();
        _sleep(50);
        */
       if (key=='k'){
           n=0;

       }
    }
    Data.close();
    
    //endwin();
}
