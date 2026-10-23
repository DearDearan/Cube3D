*This project has been made as part of the 42 curriculum by lifranco, rboutelo.*

# Cub3D

## Description

Cub3D is a graphic project. This means we get to put images on our screens! Woohoo! It's objective is to create a "Realistic" 3D graphical representation of the inside of a maze from a FPP. For that, we use the principles of Ray-Casting.

### Raycasting

Raycasting is a rendering technique that casts rays from the player's position into a 2D map to detect walls. Typically, one ray is cast for each vertical column of the screen. Using an algorithm such as DDA, we determine which wall each ray hits, the distance to that wall, and the side that was hit. We then calculate the projected height of the wall based on its perpendicular distance from the player. Then, we use the wall's orientation and the precise hit position to get our texture coordinates and draw the corresponding vertical strip of pixels on the screen.

### Parsing

The parsing was mostly done using a lib I created for the occasion (thats a lie, it was created because I thought it'd be funny) named peggle_deluxe (or [ccpeg](https://github.com/5BNeumann/ccpeg) on my github because I don't want to get sued by EA). This lib is a minimal implementation of PEG (Pattern Expression Grammar) which eliminates many of the hurdles of parsing a file in a specific format. It is in fact pretty overkill here, just as a heads up, this thing is half of ft_lex and ft_kleene. I did that accidentally btw. I could explain how it works here but I'm lazy, tired and this would be too long so instead I'll just say its a two part process, `peg` compiles the pattern to a walkable AST and `match` runs the AST. You can ask me directly for more details.

## Instructions

First, clone our project using git clone

	``git clone [link] cub3d``

then, go to the cub3d directory. You will find a Makefile. 

### Mandatory

Use the makefile at root to make the project using the following command.

	```bash
	make
	``` 

A small animation will play. You can mute the sound by using ``mute=``. 

To use the program, you need to have a map in a .cub format! Luckily, we gave you some. You can also create your own.

To do so, the map must :

- Be enclosed with 1's
- Contain 4 textures, for every direction (EA, WE, NO, SO)
- Should contain only 1 player and his direction (E, W, N, S)
- Can have spaces before and after the enclosed walls, but not inside the map. ("  10101  " is right, "10 101" is not.)

then, you can launch the program with this command.

	```bash 
	./cub3D '[map path]'
	```

### Bonus

Use the makefile using "bonus" flag to make the project using make.

	```bash
	make bonus
	``` 

Same as Mandatory, you can again use mute= to make sure the program shuts up.

To use the program, you still need maps in a .cub format. However, there are added rules :

- You need 2 textures, 1 for a Sprite and 1 for the Doors (Yes, the DOORS.).
- 4 sounds. 1 one for Music, 2 for door states and one for footsteps. Have some fun!
- Sprite character is "B" and is UNIQUE. Doors character are "2" and can't be used as enclosed walls!
- **/!\ MUSIC NEED TO BE IN .wav FORMAT /!\\**

Earlier rules are still applicated.

Use the same command as mandatory.

	```bash 
	./cub3D '[map path]'
	```


## Resources

A lot of things were used for this project :

- [Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [Super Fast Ray Casting in Tiled Worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA)
- [Reddit](https://www.reddit.com/r/howdidtheycodeit/comments/1v52rkz/how_does_raycasting_work/)

Claude and ChatGPT were used to understand how Rendering works, but our dear [rprieur](https://www.youtube.com/watch?v=dQw4w9WgXcQ) carried us all the way! I thank him so much for that. THE GOAT!

## The End.

Cub3D was a really great project. I loved everything in it, but due to time constraints, i can't afford to continue to do stupid things.
It was a pretty interesting experience with its ups and downs, but if i could redo it, i'd love to.

So, to finish, here's a lifranco/Dearan fun fact !

	Did you know? The entire project was driven by my love for the Danganronpa series! If you used our Makefile, then you could see how!
	Although, the funniest thing is that our project is literally named "スリーディーロンパ" wich means Surīdīronpa, or "Three-D Ronpa".

Hope you enjoyed our project.
