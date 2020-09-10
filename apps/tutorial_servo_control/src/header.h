#ifndef TUTORIAL_SERVO_H
#define TUTORIAL_SERVO_H

#include "mbed.h"

class TutorialServo{

  private:

        PwmOut m_servoPwmOut;
        float m_servoRangeInDegrees;
        float m_minPulsewidthInMs;
        float m_maxPulsewidthInMs;

  public:

        TutorialServo(PinName servoPin, float servoRangeInDegrees = 180, float minPulseInMs = 1, float maxPulsewidthInMs = 2){
                 m_servoRangeInDegrees =  servoRangeInDegrees;
                 m_minPulsewidthInMs = minPulsewidthInMs;
                 m_maxPulsewidthInMs = maxPulsewidthInMs;

        }

        void setAngleRangeInDegrees(float degrees){

                m_servoRangeInDegrees = degrees;
        }

        void setPulsewidthRangeInMs(float minPulsewidthMs, float maxPulsewidthMs){

                m_minPulsewidthInMs = minPulsewidthMs;
                m_maxPulsewidthInMs = maxPulsewidthMs;

        }

        void setPositionInDegrees(float degrees){

                float slope{0.0}, pulse{0.0};
                slope = (m_maxPulsewidthInMs - m_minPulsewidthInMs)/(m_servoRangeInDegrees*1000);
                pulse = (m_minPulsewidthInMs/1000) + degrees/slope;
                m_servoPwmOut.pulsewidth(pulse);

        }

        float getRangeInDegrees(){

                return m_servoRangeInDegrees;

        }

#endif
