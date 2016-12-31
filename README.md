Rubik's Cube recovery
===

Big homework of PD course for freshman.

Under GPLv3. All rights granted.

## How to initialize this project?

This projects runs under Linux/UNIX.

No test on windows is done. 

### Build rotate test program

	make rot

### Build recovery program

	make recover

Then you can find an executive file as `bin/recover.exe`.

It reads the cube from `cube.in` and writes the steps into `cube.out`.

### Build cube shuffle program

	make shuffle

The generator will be placed as `bin/shuffle.exe`

### Build solution checking program

	make checker

The checker reads the initial cube from `cube.in` and steps from `cube.out`. And it shows the process on the screen.
