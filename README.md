# Gesture-Recognition-Robot
/*
* Gesture Recognition Robot V1.1 - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* This program lets you to control your robot with gesture made by your hand
                                ADXL335
                           —————————————————¬                                 
                          |Ø            Z   Ø|                                  
                          |      X<---•      |                   
                          |           |      |                                  
                          |           |Y     |                                  
                          |           ∨      |
                          |                  |
                          |                  |
                          | O  O  O  O  O  O |
                           —————————————————¬
                            ST Z  Y  X  -  +
                                                                            Right
                                                                              ∧
                                                                              |
                                                                              |
                                                               Forward <------|------>Backward
                                                                              |
                                                                              |
                                                                              ∨
                                                                             Left
          FOLLOW THIS INSTRUCTION TO CALIBRATE ROBOT
1) Upload ADXL3xx Sketch from examples [ File >> Examples >> Sensor >> AdXL3xx ]
2] Connect the sensor the arduino      [ X --> PIN A3
                                         Y --> PIN A2
                                         Z --> PIN A1 ]
3) Open serial                         [Ctlr + Shift + M]
4) Tilt the sensor in +X, -X, +Y ,-Y direction (forward, backward, left, right) and note down the required x y 
5) Now change the 
      #define forward_val xxx with new +X value                                       
      #define backward_val xxx with new -X value
      #define left_val xxx with new +Y value
      #define right_val xxx with new -Y value
