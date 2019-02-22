#include <kipr/botball.h>

void arm_up();
void arm_down();
void forwards(int m);
void backwards(int m);
void claw_open();
void claw_close();
void turn_left(int m);
void turn_right(int m);
void follow_line();
int main()
{
    enable_servos();  /// need suto code
    arm_up(); // arm up
    msleep(200);
    claw_close(); //claw close
    turn_right(420);   /// turn right
    msleep(500);
    forwards(1500); // go forwards to make the next turn accurate
     turn_left(300); //turn left for blue line
    msleep(300);
    forwards(1400); //forwards to blue line  
    msleep(200);
    claw_open();  //get the ready to grab the poms
    msleep(100); 
    arm_down(); //arm down ready to push the poms
    msleep(300);
    claw_close(); //claw closes
    msleep(200);
    follow_line(1000); //follow the blue line til the pvc
    msleep(100);
    claw_close(); // close the claw to grab the poms
    msleep(200);
    arm_up(); //arm up ready to drop the poms
    msleep(200);
    claw_open(); // drops the poms into the blue pvc
    msleep(200);
    disable_servos(); //disable the servos  
    ao(); //all off
    return 0;
}

void forwards(int m)
{
    motor(0,90);
    motor(3,90); 
    msleep(m);
    ao();
}

void backwards(int m)
{
    motor(0,-90);
    motor(3,-90);
    msleep(m);
    ao();
}

void arm_up()
{
    int a=194;
    while (a<1454)
    {
        set_servo_position(0,973);
        msleep(200);
        a = a +80;
    }
} 
void arm_down()
{
    int a=1452;
    while (a>194)
    {
        set_servo_position(0,1942);
        msleep(200);
        a = a -80;
    }
}
void claw_open()
{
    set_servo_position(3,1380);
}
void claw_close()
{
    set_servo_position(3,1127);
}
void turn_left(int m)
{
    motor(0,70);
    motor(3,-70);
    msleep(m);
    ao();
}
void turn_right(int m)
{
    motor(0,-90);
    motor(3,90);
    msleep(m);
    ao();
}
void follow_line()
{

    clear_motor_position_counter(1);
    while (analog(1) <=5600)
    {
        if (analog(1) > 900)
        {
            motor(0, 100); 
            motor(3, -10);
            ao();
        }           

        else
        {
            motor(0, -10);       
            motor(3, 100);               

        }

    }  
}