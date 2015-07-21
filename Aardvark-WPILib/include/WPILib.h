/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef WPILIB_H_
#define WPILIB_H_

#include "string.h"
#include <iostream>

#include "Accelerometer.h"
#include "ADXL345_I2C.h"
#include "ADXL345_SPI.h"
#include "AnalogChannel.h"
#include "AnalogModule.h"
#include "AnalogTrigger.h"
#include "AnalogTriggerOutput.h"
#include "Buttons/AnalogIOButton.h"
#include "Buttons/DigitalIOButton.h"
#include "Buttons/InternalButton.h"
#include "Buttons/JoystickButton.h"
#include "Buttons/NetworkButton.h"
#include "CANJaguar.h"
#include "CANTalon.h"
#include "Commands/Command.h"
#include "Commands/CommandGroup.h"
#include "Commands/PIDCommand.h"
#include "Commands/PIDSubsystem.h"
#include "Commands/PrintCommand.h"
#include "Commands/Scheduler.h"
#include "Commands/StartCommand.h"
#include "Commands/Subsystem.h"
#include "Commands/WaitCommand.h"
#include "Commands/WaitForChildren.h"
#include "Commands/WaitUntilCommand.h"
#include "Compressor.h"
#include "Counter.h"
#include "Dashboard.h"
#include "DigitalInput.h"
#include "DigitalModule.h"
#include "DigitalOutput.h"
#include "DigitalSource.h"
#include "DoubleSolenoid.h"
#include "DriverStation.h"
#include "DriverStationEnhancedIO.h"
#include "DriverStationLCD.h"
#include "Encoder.h"
#include "ErrorBase.h"
#include "GearTooth.h"
#include "GenericHID.h"
#include "Gyro.h"
#include "HiTechnicCompass.h"
#include "HiTechnicColorSensor.h"
#include "I2C.h"
#include "IterativeRobot.h"
#include "InterruptableSensorBase.h"
#include "Jaguar.h"
#include "Joystick.h"
#include "Kinect.h"
#include "KinectStick.h"
#include "Notifier.h"
#include "PIDController.h"
#include "PIDOutput.h"
#include "PIDSource.h"
#include "Preferences.h"
#include "PWM.h"
#include "Relay.h"
#include "Resource.h"
#include "RobotBase.h"
#include "RobotDrive.h"
#include "SensorBase.h"
#include "SerialPort.h"
#include "Servo.h"
#include "SimpleRobot.h"
#include "SmartDashboard/SendableChooser.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Solenoid.h"
#include "SpeedController.h"
#include "SPI.h"
#include "OSAL/Synchronized.h"
#include "Talon.h"
#include "OSAL/Task.h"
#include "Timer.h"
#include "Ultrasonic.h"
#include "Utility.h"
#include "Victor.h"
#include "Watchdog.h"
#include "WPIErrors.h"

#endif /*WPILIB_H_*/
