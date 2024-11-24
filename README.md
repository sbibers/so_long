so_long : A small 2D Game made using the MiniLibX Graphics Library - Textures, sprites and tiles included.

What is so_long?
The fifth project in the 42 programming school's curriculum is the first graphical
project in the program. Students can choose between three options: FdF, Fractol, and
so_long. Each project focuses on a different area but shares the common goal of
introducing graphical programming.
The so_long project involves creating a top-down game coded entirely from scratch
using the MiniLibX graphical library. The project requires implementing a series of
tasks such as validating the game map passed as an argument, ensuring no memory
leaks, designing game mechanics, managing windows, handling events, and working
with sprites and maps.

⚠️ The project must be written in accordance with the Norm :
The Norm is a programming standard that defines a set of rules to follow when writing code at 42.
It applies to all C projects within the Common Core by default, and to any project where it's specified. These are some of them:

1-Each function must be maximum 25 lines, not counting the function's own curly brackets.
2-Each line must be at most 80 columns wide, comments included.
3-A function can take 4 named parameters maximum.
4-You can't declare more than 5 variables per function.
5-You're not allowed to use: for , do...while , switch , case ,  goto  ,
ternary operators such as `?' and VLAs - Variable Length Arrays.

Maps
You can parse any kind of map, as long as it respects the below rules:
The map must be a .ber file.

CHAR	OBJECT
1	    Wall
C   	Coin
E   	Exit
P	    Player
0	    Floor
A     Enemy

Use WASD keys to move.
KEY	  OBJECT
W   	⬆️ Move up
A   	⬅️ Move left
S   	⬇️ Move down
D    	➡️ Move right
Esc	  Close the game

After getting all the coin bags, the exit opens and you can escape downstairs.

How does it work?

First
1-download the library minilibx : git clone https://github.com/42Paris/minilibx-linux.git
2-cd minilibx
3-compile the minilibx (make)
4-put the minilibx in same directory of repo.

To play, clone this repo and cd into it:
1-git clone the repo
2-cd so_long
3-make
4-./so_long maps/map_1.ber

42 is a global educational initiative offering a unique approach to learning technology:
no teachers, no traditional classrooms, and a focus on peer-to-peer learning, where
students learn collaboratively. This innovative methodology not only builds strong
programming skills but also fosters essential life skills. Moreover, 42 is completely free
and open to everyone, with no prerequisites required.
The admissions process at 42 is unlike traditional colleges. It is entirely merit-based,
with the final step being the Piscine—an intensive, immersive 4-week coding
bootcamp. No prior coding experience is needed, making it accessible to anyone with
the motivation to learn.
You can check more about the admission process on the 42 amman website:
https://cpf.jo/42amman
