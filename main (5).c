#include <kipr/botball.h>

int main()
{
    enable_servos(); //go forward down the blue line
    msleep(500);
    set_servo_position(3,1804); //claw open
    msleep(500);
    set_servo_position(2,1945); //claw down
    msleep(500);
    clear_motor_position_counter(0);
    while(get_motor_position_counter(0) <8684)
    {
        motor(0,39);
        motor(3,55); 
    }
    ao();
    msleep(500);
    set_servo_position(2,2047);    // arm down  
    msleep(500);
    set_servo_position(3,911); // claw close
    msleep(500);
    set_servo_position(2,911); // arm up
    msleep(500); 
    set_servo_position(2,1240); //Arm down a little to drop poms
    msleep(300);
    motor(0,39);
      motor(3,55); // go forward
      msleep(560);
    ao();
    set_servo_position(3,1961); // let poms go into the water reclamation center
     msleep(500);
    ao();
    


    disable_servos();     
    return 0;

}