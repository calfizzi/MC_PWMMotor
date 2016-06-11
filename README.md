# MC_PWMMotor

File type   : Arduino Library

Developed By: Mario Calfizzi

# Description: 
Arduino library to manage the DC Motors using L293D 
                
# Constructors:
  MC_PWMMotor ( void )

# Methods:
Attach      ( uint8_t DirPin, uint8_t PWMPin) Attach your Direction Pin and PWM Pin

Detach      ( void )

IsActive    ( void )

Write       ( bool Backward, uint8_t PWM) Dir = false go Foreward and Dir = true go Backward, PWM is between 0 up to 255

Write       ( double Speed)               Speed is decimal number between -100 to 100, 0 Value is Motor OFF



# Circuit Diagram:

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
