/************************************************************************************************************************
  File type   : Arduino Library
  Developed By: Mario Calfizzi

  Description : Arduino library to manage the DC Motors using L293D 
                
                Constructors:
                  MC_PWMMotor ( void )

                Methods:
                  Attach      ( uint8_t DirPin, uint8_t PWMPin)
                  Detach      ( void )
                  IsActive    ( void )
                  Write       ( bool Backward, uint8_t PWM) Dir = false move Foreward and Dir = true move Backward, PWM is between 0 up to 255
                  Write       ( double Speed)               Speed is decimal number between -100 to 100, 0 Value is Motor OFF
                
                
                Circuit Diagram:

                                                        +-----\/-----+
                               PWM1 o------------------=|1         16|=------------------o VCC +5V
                                                        |            |           /| NOT Port
                               DIR1 o--+---------------=|2  L293D  15|=-------o<  |---+
                                       |                |            |           \|   |
                                       |      +--------=|3         14|=--------+      |
                                       |     -+-        |            |        -+-     |
                                       |   / MOT \ G +-=|4         13|=-+ G / MOT \   |
                                       |   \     / N |  |            |  | N \     /   |
                                       |     -+-   D +-=|5         12|=-+ D   -+-     |
                                       |      |         |            |         |      |
                                       |      +--------=|6         11|=--------+      |
                                       |   |\           |            |                |
                                       +---|  >o--------|7         10|=---------------+--o DIR2
                                           |/  NOT Port |            |                 
                      VDD MOT 5-14V o------------------=|8          9|=------------------o PWM2 
                                                        +------------+
                          
                  
*************************************************************************************************************************/

#pragma once
#ifndef MC_PWMMotor_h
#define MC_PWMMotor_h




class MC_PWMMotor 
{
private:
    int8_t _mc_dir_pin;
    int8_t _mc_pwm_pin;
public: 
            MC_PWMMotor ( void );
    // Attach using Direction Pin and PWM Pin
    void    Attach      ( uint8_t DirPin, uint8_t PWMPin);
    void    Detach      ( void );
    bool    IsActive    ( void );
    // Dir = false move Foreward and Dir = true move Backward, 
    // PWM is between 0 up to 255
    void    Write       ( bool Backward, uint8_t PWM);
    // Speed is double between -100 to 100
    // 0 Value is OFF
    void    Write       ( double Speed);
};

#endif