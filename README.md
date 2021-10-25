# CS210 - Project Two - Airgead Banking

* Summarize the project and what problem it was solving.

The goal of this project was to create an application for Airgead Banking that would calculate the yearly compound interest given the initial investment amount, a monthly deposit amount, the interest rate, and the number of years that the investment should last. The application was to be an educational tool for people new to investing, and it solved the problem of calculating the money earned from interest automatically.

* What did you do particularly well?

I feel that I did particularly well at writting the Investment class, and at calculating and displaying the yearly amounts to the screen. C++ allows a great deal of flexibility with regard to input and output and I am happy with the way my input and output turned out.


* Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I would have liked to use more output manipulators from the iomanip header file. I started to do it using setw but in the end it turned out to be much simpler for me to just code the output using literal strings. I could also enhance the code by writing a general purpose input validation function. I thought about doing this near the end of the project, but at that point it would have taken too much time and I would have had to rewrite large portions of the code. As it is now, there are input functions for each major variable.

* Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The DisplayReport function was probably the most challenging to write, just because it contained all of the logic for calculating the monthly and yearly interest rates. I spent the bulk of my debugging time in this function. I overcame this challenge by stepping through the code one line at a time and tracking variables. Although I did not use it in this function, I researched and learned about the stringstream class and found it very useful in other applications. I did not decide to use it here though.

* What skills from this project will be particularly transferable to other projects or course work?

I think creating a class was the most valuable skill practiced in this project. The ability to create the proper class for the particular problem at hand is a arguably one of the most important skills to possess as a programmer. I also think that the creation of input validation was a valuable skill to practice here, and it transfers to many different areas in the programming world. There will always be a need for input validation. It is one of the first things I learned as a programmer. 

* How did you make this program maintainable, readable, and adaptable?
  
Using a class that contains the investment variables and functions makes this program maintainable, readable, and adaptable. It is maintainable because the program functionality can be found easily within the class, and can be changed without fear of breaking other parts of the program. Readability is greatly enhanced using comments that are insightful and to the point. Also, I think classes in general make a program more readable by their nature alone, it is like looking at an object and reading what it does just by looking at the class definition. This program is adaptable in almost the same way that it is maintainable. By using a class to encapsulate and abstract the data away from the user interface, the program can easily adapt to any changes that need to be made. For example, if the program needed to handle weekly deposits instead of monthly deposits, a programmer could add (or change) a member variable in the class, and update the DisplayReport function to account for weekly instead of monthly deposits. The point being, when using classes it is trivial to pinpoint where the data is being input/output and processed, making adaptability quite simple.
