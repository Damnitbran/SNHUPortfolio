CS 210 Project One: Chada Tech Dual Clock
This C++ program shows the time in both 12-hour and 24-hour formats at once. 
The user sets a starting time, then uses a menu to add an hour, a minute, or a second, and both clocks update together. 
The main thing it solves is handling the rollover cleanly, so seconds roll into minutes, minutes into hours, and hours wrap around the 24-hour cycle.

The part I'm happiest with is the structure. 
The clock logic lives in its own class across Clock.h and Clock.cpp, while main.cpp handles the menu, input, and display. 
Storing the time internally in 24-hour format and only converting when displaying kept things simple, and the reusable getValidatedInt function means every prompt rejects bad or out-of-range input instead of crashing. 
If I went back to enhance it, I'd pull the repeated setw/setfill formatting into a small helper and clean up the display spacing, which is currently hardcoded and a bit fragile. 
Those changes would cut repetition and make the output easier to adjust later.

The trickiest part was the 12-hour conversion, since both midnight and noon need to show as 12 while AM/PM flips at the right hour, plus making sure adding a second at 11:59:59 rolled all the way up correctly. 
I worked through it by testing edge cases by hand and stepping through the values in the Visual Studio debugger, and I'm leaning on cppreference.com for standard library details going forward.
The biggest transferable skill is the three-file class structure, since separating a class definition, its implementation, and a main driver carries into almost every C++ project. 
That same separation is what makes this program maintainable and adaptable: a change to the clock logic doesn't touch the menu code, and adding something like a reset option would just mean extending the Clock class. 
Consistent naming, a header on each file, and comments that explain the tricky parts rather than the obvious ones keep it readable.
