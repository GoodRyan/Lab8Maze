Lab8Maze
========

A program that allows the robot to navigate the maze closest to the door.

This program works by using the left sensor and front sensor, to allow the robot to follow a wall on its left hand side while ensuring it can handle the case of having a wall blacking its path directly in front of it.

It first checks to see if the wall is too far away/too close. If the wall is too far away, the robot makes a slight left turn. If the wall is too close, the robot makes a slight right turn.

Next, the robot checks to see if there is a wall in front of it that might be blocking its path. If this is true, the robot makes a right turn as this accomodates the needs of the maze that the robot was placed in.

Using these parameters, the robot can navigate the maze we were provided in class with few errors.
