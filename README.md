Rubik's Cube recovery
===

Big homework of PD course for freshman.

Under GPLv3. All rights granted.

## How to initialize this project?

This projects runs under Linux/UNIX.

No test on windows is done. 

You can use this command to build the main project.

	make recover

Then you can find an executive file as `bin/recover.exe`.

It reads the cube from `cube.in` and writes the steps into `cube.out`.

You can also build a data generator using

	make shuffle

The generator will be placed as `bin/shuffle.exe`
