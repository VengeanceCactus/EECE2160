# Lab6 Report

Group members: Andrew Ricci

### GPIO Init Explanation

Before we are able to use the robotic arm with our Zedboards, we must initialize the ports on the GPIO. Here is the code used to do this:

```bash

FILEPATH='/sys/class/gpio'
echo 13 > $FILEPATH/unexport 2>/dev/null
echo 10 > $FILEPATH/unexport 2>/dev/null
echo 11 > $FILEPATH/unexport 2>/dev/null
echo 12 > $FILEPATH/unexport 2>/dev/null
echo 0 > $FILEPATH/unexport 2>/dev/null
echo 13 > $FILEPATH/export
echo 10 > $FILEPATH/export
echo 11 > $FILEPATH/export
echo 12 > $FILEPATH/export
echo 0 > $FILEPATH/export
echo out > $FILEPATH/gpio13/direction
echo out > $FILEPATH/gpio10/direction
echo out > $FILEPATH/gpio11/direction
echo out > $FILEPATH/gpio12/direction
echo out > $FILEPATH/gpio0/direction
```

From the first line, the script sets the "/sys/class/gpio" directory as the variable "FILEPATH", which is used many times in this script to avoid typing out the entire directory.

The next five lines remove all data that may currently be residing in the GPIO folders with the port numbers of the main functions of our robotic arm. They set each individual folder to NULL so that we may write information cleanly.

Then, the following five lines use the export command to pass permissions from the ports on the Pmod cable to the individually named folders of the GPIO.

Finally, the last five lines set the logging of the individual sensors to output to the direction folder of their particular port number.
