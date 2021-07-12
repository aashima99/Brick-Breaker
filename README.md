# **BRICK BREAKER GAME**
#### Aashima Tandon


# Table of Contents
1. [Objective](#Objective)
2. [Gameplay Instructions](#Gameplay-Instructions)
3. [Level Mechanism ](#Level-Mechanism)
4. [User Interface](#User-Interface)
5. [User Defined Functions](#USER-DEFINED-FUNCTIONS)
6. [Concepts Used](#CONCEPTS-USED)



## Objective
The objective of the game is to eliminate all of the BRICKS that are distributed around the top of the  game screen. The bricks get broken after coming in contact with a ball that bounces around the screen.  At the bottom is a paddle that in the game moves based on user input. The player moves a PADDLE  from side-to-side to hit a BALL. The user has to make sure the ball bounces off the paddle without  going off the bottom of the screen. But, if the ball hits the bottom enclosure, the player loses and the  game ends! To win the game, the player has to eliminate all the BRICKS in the respective levels. 

## Gameplay Instructions
In order to play the game, press “S” to launch the ball. After pressing the S key to launch the ball, the  ball will be moving. The players can control the paddle movement in two different ways. It can be  controlled by the keyboard as well as the mouse. The player uses the “A” and “D” keys to move the  paddle to the left and to the right respectively. During the game, if at any time the player wishes to start  a new game, he could press the “Q” key. The goal of the game is to break all of the bricks by intercepting the ball with the paddle and redirecting  the ball to collide with the bricks.

## Level Mechanism 

Players are allowed to change game difficulty using the menu. When the player right clicks the mouse,  two options are displayed from which the player can select one of the three different levels. Level 1  refers to normal speed and as the level increases from 1 to 3, the speed increases. Also, the game  difficulty level can also be increased by changing the paddle size from small, medium to large.

## User Interface

### Main User Interface 
![Alt Text](/images/User_Interface.png)


### Menu Options (Difficulty Levels)
![Alt Text](/images/Menu.png)


### Mid Game Intefcae
![Alt Text](/images/PlayUserInterface.png)


### Changing the paddle Size
![Alt Text](/images/Changeof_PaddleSize.png) 

## USER DEFINED FUNCTIONS

#### All the Computer Graphics functions that are implemented are listed below:

##### ●	draw_paddle(): 
A function which is used to draw paddle using the inbuilt polygon function and defining the appropriate vertices.

##### ●	brick(GLfloat x, GLfloat y, GLfloat z): 
A function which is used as the basis for the draw_bricks() function. This is used to draw a single brick.

##### ●	draw_bricks(): 
A function which is used to call multiple instances of the brick() and set up the environment for the game.

##### ●	draw_ball(GLfloat x, GLfloat y, GLfloat radius): 
This function is used to draw the ball according to its current position.

##### ●	change_difficulty(int action): 
This function is triggered by the handle_menu() function and is used to change the difficulty level by increasing or decreasing the speed of the ball

##### ●	handle_menu(int action): 
A function which presents a menu triggered by the right click that is used to change the difficulty settings using change_difficulty() and change_paddle_size() functions.

##### ●	change_paddle_size(int action): 
This function is used to change the paddle size between three levels and is triggered by interacting with the menu presented using handle_menu() function.

##### ●	addMenu(): 
A function which adds the menu interface and layout to the display area when triggered by right-click.

##### ●	text(): 
A function which displays the instructions on how to interact with the game.

##### ●	display(void): 
This is the main function that calls all other functions to present the elements on screen in each frame.

##### ●	reshape(int w, int h): 
A function which adjusts the layout of all elements onto the display area through projection.

##### ●	keyboard(unsigned char key, int x, int y): 
A function which scans input given. This is done by specifying the role of the keys in the switch case and processing input.

##### ●	hit(): 
This is one of the main functions of our game which comes into play when the ball hits the brick. This function defines the trajectory of the ball after hitting. We used the concept by applying the if else conditions and accordingly changing the direction of the ball.

##### ●	idle(): 
This is also one of the main functions of our game which handles the motion of the ball along with the rebounding from various surfaces. Here one condition is for increasing the rate after some successive collisions and another condition is to make the changes for the different positions of the ball after rebounding.


### Overall Functionality and working of the code and game
![Alt Text](/images/flowchart.png)

## CONCEPTS USED

All the Computer Graphics concepts that are implemented are listed below:

●	**Translation**: Concept of translation is used in our game while moving the paddle as well as while the ball is in motion rebounding from the different surfaces.

●	**Scaling**: Concept of scaling can be seen in our game when the difficulty changes, the scaling of the paddle differs. When the level is easy we scale the paddle smaller and when the level is hard we scale the paddle longer

●	**Drawing Circle**: For drawing the ball we used the concept of drawing connected triangles continuously to give it an image of a 2D Ball. One triangle is defined for each vertex presented after the first two vertices. Vertices 1 , n + 1 , and n + 2 define triangle n . N - 2 triangles are drawn.

●	**Drawing Polygons**: Different shapes were drawn using the inbuilt polygon function and defining the appropriate vertices which matches the shape of the polygon.

●	**Game Concept**: Brick Breaker is a famous retro game where we have to destroy all the bricks and the ball should not fall. If the ball falls the game will restart. The main player of the game is paddle, we have to save the ball from going below by the paddle and at the same time try to hit as many bricks as possible.

●	**Difficulty Levels**: To ensure the users interest in the game we came up with different levels and difficulties, the concepts for the level are described below:

a)	**Changing Size of Paddle**: For this we changed the position of the vertices while defining the polygon, That way we can make the paddle smaller or bigger.

b)	**Changing the speed of the Ball**: For this particular feature we decided to have a rate variable which on increasing gives us a high speed of the ball and vice versa. This rate depends on the x-coordinate and the y-coordinate. The more the rate means the faster the x and y coordinates will change.

●	**Keyboard Inputs**: Now for playing the game the user needs some kind of input to give. This can be done very easily by using a glut function ‘keyboard’ and then by specifying the role of the keys in the switch case. In each switch case you need to define what that key will do.

●	**Hitting the Brick**: This is the concept which comes into play when the ball hits the brick. This function defines the trajectory of the ball after hitting. We used the concept by applying the if else conditions and accordingly changing the direction of the ball.

●	**Trajectory of the Ball**: The concept used for this particular feature of our game which handles the motion of the ball along with the rebounding from various surfaces. Here one condition is for increasing the rate after some successive collisions and another condition is to make the changes for the different directions of the ball after rebounding.

### The major milestones for the project implementation were: 

###### ● Displaying the bricks and disappearing after hitting the ball.
###### ● Small platform/paddle moving left and right. 
###### ● The ball must deflect back after hitting brick, side walls and platform at the bottom.
###### ● Changing the game difficulty by changing the speed of the ball as well as the paddle size for different  levels.
