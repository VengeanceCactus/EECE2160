# Lab 8

### Pre-lab

In our pre-lab, we created a basic free running counter. This ran for 1000 cycles and outputted its results to a scope sink. This counter had distinctly different results based on the boolean input it was set to. If the input was 0, the scope displayed a flat line at 0. If the input was 1, the scope displayed spikes at cycle 0, about 260, about 515, and about 765.

![simplecircuitzero](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/ss%2B(2017-11-09%2Bat%2B11.48.46).png)
![simplecircuitone](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/ss%2B(2017-11-09%2Bat%2B11.47.56).png)

### Compare to Constant

When we add the compare to constant value to our circuit, the display of the scope much resembles the clock signals shown at the beginning of our lab. The signal stays at zero until the output matches the constant, where it briefly spikes to 1. This could be very useful in an experiment where we wanted to know the exact moment that a circuit outputted a particular value, and could then determine a frequency by which that value appeared.

![compare](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/ss%2B(2017-11-15%2Bat%2B09.46.36).png)

### Cascaded Counter

When the circuit is arranged in the cascaded pattern, the display of our scope begins at zero and increases by one for each time the output matches the constant. By 1000 cycles, the value of the display is 4. This would be useful if we wished to know the number of times that a value had been reached by a circuit.

![cascaded](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/ss%2B(2017-11-15%2Bat%2B09.48.32).png)

### Controlling LED With Switches

![ledwithswitches](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/switchestoleds.svg)

![switchexample1](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/20171113_181159.jpg)
![switchexample2](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/20171113_181210.jpg)

### Controlling LED With Counter

![ledwithcounter](https://github.com/eece2160-fall17-s8/lab8-group-8/blob/master/countertoleds.svg)

https://youtu.be/KrhZGTMu198
