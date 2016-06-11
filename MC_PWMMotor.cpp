/************************************************************************************************************************
  File type   : Arduino Library
  Developed By: Mario Calfizzi

  Description : Arduino library to manage the DC Motors using L293D 
*************************************************************************************************************************/
  
#include <arduino.h>
#include "MC_PWMMotor.h"


#define PWM_MOTOR_NO_PIN -1


#if     defined (_AVR_IOM328P_H_) // NANO/MICRO
  #define IS_PWM_PIN(pin)   (pin==3 ||  pin==5 || pin==6 || pin==9 || pin==10 || pin==11)
  #define IS_VALID_PIN(pin) ((pin>=2 && pin<=13) || (pin>=A0 && pin<=A5))
#elif   defined (_AVR_IOM2560_H_) // MEGA 25260
  #define IS_PWM_PIN(pin)   ((pin>=2 && pin<=13) || (pin>=44 && pin<=46))
  #define IS_VALID_PIN(pin) ((pin>=2 && pin<=53) || (pin>=A0 && pin<=A15))
#endif


MC_PWMMotor::MC_PWMMotor()
{
  this->_mc_dir_pin = PWM_MOTOR_NO_PIN;
  this->_mc_pwm_pin = PWM_MOTOR_NO_PIN;
}

void  MC_PWMMotor::Attach(uint8_t DirPin, uint8_t PWMPin)
{
  this->_mc_dir_pin = DirPin;
  if (IS_PWM_PIN (PWMPin) )
    this->_mc_pwm_pin = PWMPin;
  if (IS_VALID_PIN(this->_mc_dir_pin) && IS_VALID_PIN(this->_mc_pwm_pin))
  {

    if (this->IsActive())
    {
      pinMode       ( this->_mc_dir_pin, OUTPUT );
      pinMode       ( this->_mc_pwm_pin, OUTPUT );
      digitalWrite  ( this->_mc_dir_pin, LOW    );
      analogWrite   ( this->_mc_dir_pin, 0      );
    }
  }
}

void MC_PWMMotor::Detach ( void )
{
  if (this->IsActive())
  {
    pinMode       ( this->_mc_dir_pin, INPUT_PULLUP );
    pinMode       ( this->_mc_pwm_pin, INPUT_PULLUP);
  }
}



bool MC_PWMMotor::IsActive()
{
  return this->_mc_dir_pin!=PWM_MOTOR_NO_PIN && this->_mc_pwm_pin!=PWM_MOTOR_NO_PIN && this->_mc_dir_pin!=this->_mc_pwm_pin;
}

void MC_PWMMotor::Write(bool Dir, uint8_t PWM)
{
  if (this->IsActive())
  {
    digitalWrite ( this->_mc_dir_pin, Dir);
    analogWrite  ( this->_mc_dir_pin, PWM);
  }
}
void MC_PWMMotor::Write ( double Speed)
{
  double Value;
  if (this->IsActive())
  {
    Value = fabs(Speed);
    Value = double(map(Value*10, 0, 1000, 0, 2550))/10;
    if (Value>255)
      Value = 255;
    Serial.println(Value);
    analogWrite(this->_mc_pwm_pin, Value);
    if (Speed>0)
      digitalWrite ( this->_mc_dir_pin, HIGH);
    else
      digitalWrite ( this->_mc_dir_pin, LOW);
  }
}
