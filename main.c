#include <kipr/botball.h>

void arm_up();
void arm_down();
void forwards(int m);
void backwards(int m);
void claw_open();
void claw_close();
void turn_left(int m);
void turn_right(int m);
int main()
{
    enable_servos();   /// need suto code
    turn_right(420);   /// turn right
    msleep(500);
    forwards(1500);  /// go forwards to make the next turn easy
    turn_left(300);  // turn left to get to the blue pom line
    msleep(300);
    arm_down();     /// arm down
    msleep(200);
    forwards(500);
    disable_servos();   
    ao();
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
        a = a +20;
    }
} 
void arm_down()
{
    int a=1452;
    while (a>194)
    {
        set_servo_position(0,1870);
        msleep(200);
        a = a -20;
    }
}
void claw_open()
{
    set_servo_position(3,1920);
}
void claw_close()
{
    set_servo_position(3,660);
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
