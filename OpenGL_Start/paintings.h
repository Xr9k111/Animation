#ifndef PAINTINGS_H
#define PAINTINGS_H
#include<string>
struct Position
{
    double x;
    double y;
    double sc_x;
    double sc_y;
};

void fon_start();
void fon_earth();
void rocket(Position pos, double angle, double rx, double ry);
void astronavt(Position pos, double langle, double rangle);
void fire1(Position pos);
void fire2(Position pos);

void earth(Position pos);
void cloud(Position pos);

void portal_fon();
void portal_fon_planet();
void portal_fon_sphere(Position pos);

void dinosaur(double angle, double clou_y);

void dialog(Position pos);
void displayText( float x, float y, int r, int g, int b, const char *string ) ;
#endif // PAINTINGS_H
