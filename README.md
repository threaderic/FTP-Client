# FTP-Client
FTP Client programmed in C++ using the SFML library

## Notice
The project is not complete

## Why?
I got bored and decided to play around with the SFML library, I ended up checking out the networking module and finding the FTP class. 
I figured why not make a FTP client for the expirence and so I could manage the files on my home server.

## Building
Building is simple, create a new SFML project. 
Copy and paste the `src` and `include` into the project directory and include them into the project. 
You only need the following sfml linker flags to compile
```
-lsfml-network
-lsfml-system
```

