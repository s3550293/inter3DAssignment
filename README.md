# Inter3DAssignment 1 Ship Battel!

 This assignment will require you to simulate a water surface using sine waves, with two player controlled boats rocking on the water and on opposite sides of an island. The boats have cannon with which they attack the island, which is defended with a cannon and capable of firing back, and has greater 'health'. 

### Main Requirements

*   Draw a quad strip across the bottom half of the window.
*   Displace the quad strip using a sine wave.
*   Calculate normals and tangents for the sine wave and draw them as lines.
*   Add a boat mesh (a trapezoid with a quad on top, along with a quad for the cannon).
*   Draw two boats, one on either side of the island which is in the middle.
*   Have the boats move left/right using the a/d and j/l keys (one pair for each boat).
*   Have the boats change their cannon aim using the q/Q and o/O keys (one pair for each boat).
*   Draw a curve to show the path a projectile i.e. cannon ball will take in flight.
*   Fire cannon using the e/i keys (one for each boat).
*   Adjust the island cannon angle using f/h and fire with g space.
*   Represent the health of each boat using the boat's colour and a health bar, and similarly for the island.
*   Add a defence to shoot an exploding cannon ball in the direction of incoming projectiles, that is, and         anti-projectile defence.
*   Draw an on screen display showing frame rate and frame time
*   Render game over text (along with disabling movement/shooting) when boats or island goes to zero health.


## Controls

*   Esc - Quits the game

### Display Controls
*   +/= - Increases the number of vertices in the SIN wave 2x
*   '-' - Decreases the number of vertices in the SIN wave 2x
*   ` - Stops the animation of the SIN wave
*   Shift + T - Toggles the SIN wave tangents
*   Shift + N - Toggles the SIN wave normals
*   Shift + W - Toggles Pollygon Mode

### Boats
The boat are on the same team and their goal is to destroy the island.
#### Red Boat
*   A - Moves left
*   D - Moves right
*   W - Moves the cannon up
*   S - Moves the cannon down
*   E - Fires The Cannon

#### Blue Boat
*   J - Moves left
*   L - Moves right
*   I - Moves the cannon up
*   K - Moves the cannon down
*   O - Fires The Cannon

### Island
*   F - Moves left
*   H - Moves right
*   T - Fires The Cannon

## Authors

* **Joseph Garner** - *Completed Work* - [s3550293](https://github.com/s3550293)


## Marking Guide

This is a guide only, and may change.

PA: basic assignment with boats bobbing and rocking on water and and island

CR: two boats with interactive controls ability to fire cannonballs with projectile motion as well as an island with a cannon able to similarly fire a cannon.

DI: projectile path display, collision detection

HD: polished gameplay, multiple missiles, cooldown, rendering, OSD, missle defence 