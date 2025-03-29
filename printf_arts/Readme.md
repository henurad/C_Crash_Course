# PrintfArts
Some code snippets and examples that help you professionaly use printf command.
## 1. [Linux `conio.h`](linux_conio/conio.h)
There is no direct access to `conio.h` in linux. but the `conio.h` file can be copied in the linux c program and then you can easily access getch() and getche() functions.

## 2. [Clearing the screen](clear_screen.c)

## 3. [Formatted error](formatted_error_function.c)

## 4. [Print progressbar](print_progressbar.c)

## 5. [Colored printf](colored_printf.c)


Structure of ANSI Escape Sequences
An ANSI escape sequence typically starts with the escape character (ESC), which is represented in C as \033 or \e, followed by a series of codes that specify the desired action. The general format is:

\033[<parameters>m
\033: This is the escape character (ESC), which signals the start of the escape sequence.
[: This character indicates that a control sequence follows.
<parameters>: This is a semicolon-separated list of parameters that specify the desired effect (like color or style).
m: This character indicates that the parameters relate to text formatting (colors, styles, etc.).
Common Parameters
Text Formatting Parameters
Reset: 0 - Resets all attributes (colors, bold, etc.).
Bold: 1 - Makes the text bold.
Underlined: 4 - Underlines the text.
Reversed: 7 - Inverts the foreground and background colors.
Text Color Parameters
Foreground Colors: 30 to 37 for standard colors, 90 to 97 for bright colors.
Background Colors: 40 to 47 for standard colors, 100 to 107 for bright colors.
Example of Escape Sequences
Here’s how to use an escape sequence to print colored text:

#include <stdio.h>

int main() {
    printf("\033[31mThis text is red!\033[0m\n"); // Red text
    printf("\033[32mThis text is green!\033[0m\n"); // Green text
    return 0;
}
Breakdown of the Example
\033[31m:

\033: Start of the escape sequence.
[: Indicates that a control sequence follows.
31: Sets the foreground color to red.
m: Indicates that the parameters apply to text formatting.
This text is red!: The text that will be displayed in red.

\033[0m:
Resets all attributes, returning the text color to the terminal's default.

Extended Escape Sequences
For extended colors (256 colors), the format changes slightly:

Foreground Colors: \033[38;5;<n>m
Background Colors: \033[48;5;<n>m
Where <n> is a number from 0 to 255.

Example of Extended Colors

#include <stdio.h>

int main() {
    for (int i = 0; i < 256; i++) {
        printf("\033[38;5;%dmColor %3d\033[0m ", i, i);
        if (i % 16 == 15) printf("\n"); // New line every 16 colors
    }
    
    return 0;
}
Summary
ANSI escape sequences are powerful tools for controlling text formatting and colors in terminal applications.
They start with the escape character followed by a control sequence and parameters.
You can use them to enhance the user interface of terminal applications significantly.



Text Color Codes
textColorBlack	\033[30m
textColorRed	\033[31m
textColorGreen	\033[32m
textColorYellow	\033[33m
textColorBlue	\033[34m
textColorMagenta	\033[35m
textColorCyan	\033[36m
textColorWhite	\033[37m
textColorReset	\033[0m


Background Color Codes
Black	\033[40m
Red	\033[41m
Green	\033[42m
Yellow	\033[43m
Blue	\033[44m
Magenta	\033[45m
Cyan	\033[46m
White	\033[47m
Reset	\033[0m



Bright Text Color Codes
Bright Black (Gray)	\033[90m
Bright Red	\033[91m
Bright Green	\033[92m
Bright Yellow	\033[93m
Bright Blue	\033[94m
Bright Magenta	\033[95m
Bright Cyan	\033[96m
Bright White	\033[97m


Bright Background Color Codes
Bright Black (Gray)	\033[100m
Bright Red	\033[101m
Bright Green	\033[102m
Bright Yellow	\033[103m
Bright Blue	\033[104m
Bright Magenta	\033[105m
Bright Cyan	\033[106m
Bright White	\033[107m
