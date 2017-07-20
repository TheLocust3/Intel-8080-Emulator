# Intel-8080-Emulator [![Build Status](https://travis-ci.org/TheLocust3/Intel-8080-Emulator.svg?branch=master)](https://travis-ci.org/TheLocust3/Intel-8080-Emulator)
An Intel 8080 CPU emulator written in C.  
  
### Testing
To run the project's unit tests:  
`make && make test`    

### To-Do  

- CPU tests  
- Add more opcodes
- Use log function instead of prints
- Handle flags
- Handle interrupts
- Create tests that test extremes
- More comprehensive condition matcher tests
- Make sure swapping registers doesn't mean the registers point to the same memory
- Extract conditional logic out
