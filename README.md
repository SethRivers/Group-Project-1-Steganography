# Simple Steganography

Welcome to the Script Sages Simple Steganography Repo!
-

With this and a few simple taps on the keyboard, you'll be able to encode whatever message you desire into a ppm file of your choice! Alternatively; if you already have a message that you would like to extract from an encoded image, you can do this to! 

Disclaimer: 
-
- Encoder/Decoder does not come with images ready to use, and images __must__ be in the ppm file format. 
- Messages or information that you would like to encode into a given image must be first inserted into a txt file before using the Encoder/Decoder.         

# Design Decisions
**Driver(main.cpp):**
- 
- The UI was set up to take a user step by step through the program with hopefully no hiccups. Ontop of this, there were multiple safety net cases installed in order to ensure that invalid inputs could not interfere with overall function of the program.                                    

**Steganography.h:**
- 
- Written as requestd by the Canvass assignment. Nothing of note. 

**Steganography.cpp:**
-
- exit(0): Since the error cases were constructed and designed to check if the files could open properly, they would need to be inside the void functions. However; given the nature of void functions, return 0 would not suffice in terminating the program like it usually would; so, after a bit of digging, we found a void function friendly alternative so that the error cases can operate as intended. 
- Break: while a normally dangerous command to call, we made sure that it was kept within its parameters and properly utilized for its task. At the time, we were not able to find  a suitable way to remove the excess __NULL__ characters when transfering the decoded text into a txt file; and this turned out to be the best option we could find. 

# How To Run The program
Upon running the Makefile, it will generate an executable called "steg"; so, when ready to run the code, simply type in ./steg and follow the instructions provided in the built in UI!     

EXTRA NOTE: When inputting the name of your output file, DO NOT include .txt or .ppm in the name! The code will automatically add it for you. 

# Challenges
I would say the biggest challenges we faced was trying to prevent the program from filling the text file with __NULL__ characters as a result of empty space left over from decoding the encoded image. Luckily, we found a rather quick and simple fix.

# How we Shared our work
We seperated everything into three branches: the main branch, and our personal branches. From there, we would discuss the issues over discord and tend to the program when we could. We'd go over eachothers code either via screenshots or by looking in the project repo and tending to things as we found them. 

When it came to seperating the work; we'd simply ask one another which ones we wanted to work on at a given time, and went from there. Not a perfect system, but it worked out in the end. 