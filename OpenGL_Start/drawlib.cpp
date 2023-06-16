#include "drawlib.h"
#include "paintings.h"
#include<ctime>
#include<cmath>
#include<iostream>
#include<string>

clock_t anim1;
Position shatl = {0,0,1,1};
Position cosmonavt = {0.8,0,0.3,0.3};
Position fire  = {-0.30,-0.7,0.2,0.2};
Position earth_pos = {-0.2,0,0.8,0.8};
Position cloud_pos = {-0.2,0,0.8,0.8};
Position portal = {0,0,1,1};
double rleg = 0, lleg = 0, rangle = 0;
double speed = 1;
bool cosm_disp = true;
int count = 0;
char fire_disp = 0;
double text_y = 1.2;
bool checktime = false;
bool disp_dial_cosm = false;
bool disp_dial_dino = false;
Position dial = {0,-0.6,0.3,0.3};
Position dial1= {0.5,0.45,0.5,0.3};
char* cosmo_dial = "you are not dead?";
char* dino_dial = "I am reading.";
double hand_angle = 0;
double clou_y = 0;

void draw_scene_1(int & scene)
{

    fon_start();
    rocket(shatl, rangle,0,0);
    if(fire_disp == 1)
        fire1(fire);
    if(fire_disp == 2)
        fire2(fire);
    if(cosm_disp)
        astronavt(cosmonavt, lleg, rleg);

    if(cosmonavt.x > 0)
    {
        cosmonavt.x-=0.009/5000*clock() * speed;
    if(count < 20){
        lleg += 1.3;
        rleg -= 1.3;
    }
    if(count > 20 && count < 40){
        lleg -= 1.3;
        rleg += 1.3;
    }
    if(count > 40)
        count = 0;
    count++;
    }
    if(cosmonavt.x <=  0 && cosmonavt.sc_x  > 0.19)
    {
        cosmonavt.sc_x -= 0.001 * speed;
        cosmonavt.sc_y -= 0.001 * speed;
    }
    if(cosmonavt.sc_x  <= 0.19 && cosmonavt.x > -0.1)
        cosmonavt.x-=0.002/5000*clock()* speed;
     if(cosmonavt.x <= -0.1)
        cosm_disp = false;
     if(! cosm_disp && shatl.y < 2)
     {
             shatl.y+=0.009/5000*clock()* speed;
             fire.y += 0.009/5000*clock()* speed;
             if(count <= 2){
                fire_disp = 1;
             }
             if(count > 2 && count < 4){
                fire_disp = 2;
             }
             if(count >= 4)
                 count = 0;
      count++;
     }
    if(! cosm_disp && shatl.y >= 2)
    {
        scene = 2;
        shatl.x = -0.2;
        shatl.y = -0.7;
        shatl.sc_x = 0.5;
        shatl.sc_y = 0.5;
        rangle = -50;
    }

}

void draw_scene_2(int & scene)
{
    fon_earth();
    earth(earth_pos);
    cloud(cloud_pos);

    rocket(shatl, rangle,0, 0);

    if(rangle <= 0)
    {
        shatl.x+=0.006/15000*clock()* speed;
        shatl.y+=0.01/15000*clock()* speed;
        rangle += 0.2;
    }
    else{
     shatl.y+=0.01/13000*clock();
    }

    if(earth_pos.x > -0.9 && earth_pos.y > -0.4)
    {
        earth_pos.x-=0.009 /12000*cos(clock()) * 2* speed;
        earth_pos.y-=0.005/12000*clock()*0.2* speed;
    }

    if(cloud_pos.x > -0.9 && cloud_pos.y > -0.7)
    {
        cloud_pos.x-=0.009/10000*clock()* speed;
        cloud_pos.y-=0.005/10000*clock()* speed;
    }

    if(shatl.y > 1.5){
       scene = 3;
       count = 0;
       shatl.x = 0.7;
       shatl.y = -1.4;
       fire.x = 0.55;
       fire.y = -1.75;
       fire.sc_x /= 2;
       fire.sc_y /= 2;
       rangle = 0;
       portal.x += 0.05;
       portal.y += 0.1;
       anim1 = clock();
    }
}
void draw_scene_3(int & scene)
{
    if(clock()-anim1>2000 && clock()-anim1 < 7000)
    {
        displayText(-0.5,text_y,1,0,0,"after many many years of wandering in space,");
        displayText(-0.5,text_y-0.1,1,0,0,"he found a place that was supposed");
        displayText(-0.5,text_y-0.2,1,0,0,"to give answers to all his questions");
        text_y-=0.01/5000*(clock() - anim1 - 2000) * speed;
    }
    if(clock()-anim1 >= 7000)
    {
        anim1 = clock();
        scene = 4;
    }
}

void draw_scene_4(int & scene)
{
    portal_fon();
    portal_fon_planet();
    portal_fon_sphere(portal);
    rocket(shatl, rangle, 0, 0);
    if(fire_disp == 1)
        fire1(fire);
    if(fire_disp == 2)
        fire2(fire);

    if(count < 40){
        portal.sc_y += 0.01;
    }
    if(count > 40 && count < 80){
        portal.sc_y -= 0.01;
    }
    if(count > 80)
        count = 0;

    if(clock()-anim1>2000 && clock()-anim1<4000)
    {
        shatl.y+=0.043/5000*(clock() - anim1 - 2000)* speed;
        fire.y += 0.043/5000*(clock() - anim1 - 2000)* speed;
        if(count % 10 == 0)
            fire_disp = 1;
        if(count % 10 == 1)
            fire_disp = 2;
    }

    if(clock()-anim1>6000 && clock()-anim1<8000)
    {
        rangle += 0.9;
        fire_disp = 0;
    }
    if(clock()-anim1>8000 && clock()-anim1<11000)
    {
        shatl.x-=0.01/3000*(clock() - anim1 - 8000);
    }
    if(clock()-anim1>11000 && clock()-anim1<12500 && shatl.sc_x > 0)
    {
        shatl.sc_x-=0.01* speed;
        shatl.sc_y-=0.01;
        shatl.x-=0.03/1500*(clock() - anim1 - 11000)* speed;
    }
    if(shatl.sc_x <= 0)
    {
        scene = 5;
        cosmonavt.x = -0.7;
        cosmonavt.y = -0.4;
        cosmonavt.x = -0.9;
        cosmonavt.y = -0.7;
        cosmonavt.sc_x *= -1;
        cosmonavt.sc_x *= 1.5;
        cosmonavt.sc_y *= 1.5;
        count = 0;
        anim1 = clock();
    }
    count++;
}

void draw_scene_5(int & scene)
{
    dinosaur(hand_angle, clou_y);
    astronavt(cosmonavt, lleg, rleg);

    if(disp_dial_cosm)
    {
        dialog(dial);
        displayText(-0.2,-0.55,0,0,1,cosmo_dial);
    }
    if(disp_dial_dino)
    {
        dialog(dial1);
        displayText(0.23,0.5,0,1, 0,dino_dial);
    }
    if(clou_y < 1.2)
    {
       clou_y += 0.001;
    }
    if(clou_y >= 1.2)
        clou_y = 0;

    if(hand_angle < 6)
    {
        hand_angle += 0.1;
    }else{
        hand_angle = 0;
    }
    if(cosmonavt.x < -0.4 && clock() - anim1 > 3000)
    {
        cosmonavt.x+=0.001/5000*clock() * speed;
    if(count < 20){
        lleg += 1.3;
        rleg -= 1.3;
    }
    if(count > 20 && count < 40){
        lleg -= 1.3;
        rleg += 1.3;
    }
    if(count > 40)
        count = 0;
    count++;
    }
    if(cosmonavt.x >= -0.4 && !checktime)
    {
        disp_dial_cosm = true;
        anim1 = clock();
        checktime = true;
    }
    if(clock() - anim1 > 1000 && disp_dial_cosm)
            disp_dial_dino = true;
    if(clock() - anim1 > 3000 && disp_dial_cosm)
            dino_dial = "Don't interfere";
    if(clock() - anim1 > 5000 && disp_dial_cosm)
            dino_dial = "After the meteorite,";
    if(clock() - anim1 > 7000 && disp_dial_cosm)
            dino_dial = "they found me here too";
    if(clock() - anim1 > 8000 && disp_dial_cosm)
            cosmo_dial = "How do I get out?";
    if(clock() - anim1 > 10000 && disp_dial_cosm)
            dino_dial = "Go right to the end!";
    if(clock() - anim1 > 12000 && disp_dial_cosm)
            cosmo_dial = "OK, thanks";

    if(clock() - anim1 > 13000)
    {
         disp_dial_dino = false;
         disp_dial_cosm = false;
         if(cosmonavt.x < 1.8)
         {
             cosmonavt.x+=0.004/5000*(clock() - anim1) * speed;
         if(count < 20){
             lleg += 1.3;
             rleg -= 1.3;
         }
         if(count > 20 && count < 40){
             lleg -= 1.3;
             rleg += 1.3;
         }
         if(count > 40)
             count = 0;
         count++;
         }
         if(cosmonavt.x >= 1.8)
         {
             scene = 6;
             cosmonavt.x = 0;
             cosmonavt.y = -0.4;
             count = 0;
             anim1 = clock();
         }
    }

}

void draw_scene_6(int & scene)
{
    if(clock() - anim1 < 6000)
    {
        astronavt(cosmonavt, lleg, rleg);
        if(count < 20){
            lleg += 1.3;
            rleg -= 1.3;
        }
        if(count > 20 && count < 40){
            lleg -= 1.3;
            rleg += 1.3;
        }
        if(count > 40)
            count = 0;
        count++;
        displayText(-0.35,0,1,1,1,"Thank you for your attention!");
    }
}

