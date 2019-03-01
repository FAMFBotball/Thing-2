#include <kipr/botball.h>

int main()
{
    enable_servos();
    set_servo_position(3,1804); //claw open
    set_servo_position(1,1999); //claw down
    motor(0,76);
    motor(3,90); //go forward down the blue line
    msleep(7000);
    set_servo_position(3,911);
    set_servo_position(1,911);
    
    
    
           
      disable_servos();     
    return 0;
}
