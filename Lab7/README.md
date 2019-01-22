# Lab 7
Group Members: Andrew Ricci

### Extract Bits from Bus

![Constanttobits](https://github.com/eece2160-fall17-s8/lab7-group-8/blob/master/constanttobits.svg)

In the extract bits from bus simulation, we used splicers to take the value of a bits from the range of 2^0 to 2^7. Each splicer took a single bit and outputted the result as a 1 or a 0. From this, we can determine the value of an integer from 0-255 in binary.

### Bit Concatenate

![Bitconcat](https://github.com/eece2160-fall17-s8/lab7-group-8/blob/master/bitconcat.svg)

In the bit concatenate, the function is essentially the opposite of the extract bits from bus. Eight binary values are inputted, from 2^0 to 2^7, and the results are outputted to a single integer. 

### Half Adder

![Halfadder](https://github.com/eece2160-fall17-s8/lab7-group-8/blob/master/half_adder.svg)

In the half adder, the goal is to take two one bit binary numbers and add them together to receive a two bit output. The half adder uses an XOR and an AND to achieve this. Both one bit inputs feed into each gate. The XOR feeds into the least significant bit output, and the AND feeds into the most significant bit output.

The reason for the XOR as the least significant bit of output is because if both input bits are 0, the least significant bit must be zero. If both are 1, then the least significant bit will have to be zero as well. Only when a single input bit is one will the least significant output bit be one. For the most significant bit of output, we must use an AND gate because only if both inputs are one will the output be 2, or a 1 for the most significant bit.

### Full Adder

![Fulladder](https://github.com/eece2160-fall17-s8/lab7-group-8/blob/master/full_adder.svg)

In the full adder, two bits are inputted into the first half adder like in a typical half adder set up. Then, the most significant bit is fed into an OR operator, and the least significant bit is fed into a second half adder. The third bit is fed into the second half adder as well. The most significant bit from the second half adder is sent into that same OR operator, and the least is set as the least significant bit of the overall output. The OR operator then feeds into the most significant bit of the output.

The purpose of this set up is to allow a third bit to be inputted or outputted, which is key to our 8 bit adder. The most significant bits in each half adder will at most be equal to 1, so they are sent to an OR operator. The least significant bit in the first half adder is inputted into the second, which then determines the least significant bit in the overall output.

### 8-Bit Adder
![Eightbitadder](https://github.com/eece2160-fall17-s8/lab7-group-8/blob/master/eightbitadder.svg)

The eight bit adder begins with two constant integers. They are split using our bit extraction circuit, and then sent to 8 individual full adders. These full adders have a priority in bits, from high to low. The individual adders output their high priority bits to a bit concat with matching priority to the adders. These bits are then converted to a single integer equal to the sum of the two initial integers. The purpose of the cout ouput is to display any extra low signficance bit from the last full adder.
