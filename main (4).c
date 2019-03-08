#include <kipr/botball.h>

int main()
{
    enable_servos(); //go forward down the blue line
    msleep(500);
    set_servo_position(3,1804); //claw open
    msleep(500);
    set_servo_position(1,1945); //claw down
    msleep(500);
    clear_motor_position_counter(0);
    while(get_motor_position_counter(0) <8283)
    {
        motor(0,44);
        motor(3,50); 
    }
    
    msleep(500);
    set_servo_position(1,2047);    // arm down  
    msleep(500);
    set_servo_position(3,911); // claw close
    msleep(500);
    set_servo_position(1,911); // arm up
    msleep(500);





    disable_servos();     
    return 0;

}