*This project has been created as part of the 42 curriculum by lifranco.*

# Description

The goal of so_long is to create a basic computer graphics project. In this case, we're making a video game ! Hell Yeah !

For this we're using the MiniLibX, a library made to do basic necessary tools like opening a window, create images and deal with Events like Keyboard Inputs and Mouse Events (that we don't use in this case).

## The Game 

Let's talk about the game ! (that you just lost :troll:)

The Subject says that the game is about a dolphin escaping Earth after eating some fish.

How cute! However, i'm a (wannabe) ***Horror Game Dev***. So, my game is about a Murderer cleaning an alleyway of body bags before escaping by the sewer grate !

Awesome, isn't it? Don't worry, my mental state is alright (almost). 

The Player Goal is to collect the collectibles and escaping by choosing the shortest route possible. 

The Player can move using the WASD Keys :

- W to Move Up
- A to Move Left
- S to Move Down
- D to Move Right

The Player isn't able to move into walls, or he'll probably end up in the Backrooms.

At every move, the current number of movements made by the Player is displayed on the Shell.

## The Maps

Of course, 2D top-down should have Maps!

We have a few rules for those, so here's a list of all the things you need for your map to be Valid: 

- The map extension **must** end in ".ber"

- The map has to be constructed with 3 components. **Walls**, **collectibles** and **free space**.

- The map can be composed of only these 5 characters : **0** for Empty Space, **1** for a Wall, **C** for a Collectible, **E** for an Exit, **P** for the Player's starting position.

- To be valid, a map must contain Only **1** exit, Only **1** starting position and at least **1** collectible.

- The map must be **Rectangular**.

- There should be a **valid path** in the map.

- If any misconfiguration is encountered, the program will return "Error\n" followed by an error message.

# Instructions

First, you'll need to clone the repo, then, type this in your terminal.

```bash
make all
```

You will get a program named "so_long". You can start the game by putting in your terminal the program name, then a map of your choice in /maps.

```bash
./so_long maps/MAPOFYOURCHOICE.ber
```

# Ressources

Here's the program i used for all my sprites :

https://libresprite.github.io/#!/

Here's the body bag sprite i modified : 

https://www.freepik.com/premium-vector/pixel-art-corpse-bag-murder_62566011.html

I used some AI (ChatGPT, Claude) to help me with the programs leaks, bugs and with the graphics management. I also used the 42 Docs for MiniLibX :

https://harm-smits.github.io/42docs/libs/minilibx

Finally, i used my peers help in everything i didn't know about.

# Thy End

So Long was a really awesome project, sadly i coudn't make the bonuses, as i didn't had time to.

So, here's a lifranco/Dearan's fun fact :

Layer 8 of ULTRAKILL is OUT! Go Play It!