# Prelab Results

### 1.)

When attempting to run our LED code on the COE machines, it predictably fails. The part it fails at is mapping the IO memory. This is because the COE machines and the Zedboard have different hardware, and therefore different IO structures. Because of this, the addresses assigned in the code do not match the addresses on our computers.

### 2.)

In the Initialize() function, the code accesses the device memory, and maps out a chunk to be used for this program.

In the Finalize() function, the code unmaps the memory that was mapped in the initialize function, and closes the function that was established in initialize as well.

In the RegisterRead() function, the code takes the object referenced by the pointer and the offset integer and adds them together, returning the result.

In the RegisterWrite() function, the code adds the value referenced by the pointer and the offset integer to get the value "value", which is written in the IO.
