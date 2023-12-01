# C++ HTML Calendar Generator

![page preview](/preview.png)

This project is a C++ program that generates an HTML calendar. The user can choose to generate a calendar for a specific month or for an entire year.

## Deploy

You can see the project live at the following URL: [Link](https://afraniocaires.github.io/gerador-Calendario-HTML-CPP/).

## Features

- Generate a monthly calendar
- Generate an annual calendar
- Leap year support
- HTML output with basic CSS styling

## Code Structure

The code is organized into several functions, each with a specific purpose:

- `main()`: The main function that runs the program.
- `menu()`: Displays the menu to the user and handles user input.
- `diaSemana()`: Calculates the day of the week for a given date.
- `ehBissexto()`: Checks if a year is a leap year.
- `diasNoMes()`: Returns the number of days in a given month.
- `mostraCalendario()`: Generates the HTML for a monthly calendar.
- `mostraCalendario_anual()`: Generates the HTML for an annual calendar.
- `gerarCalendario_ano()`: Calls the necessary functions to generate an annual calendar.
- `gerarCalendario_mes()`: Calls the necessary functions to generate a monthly calendar.
- `switchMeses()`: Outputs the correct month name in the HTML.
- `headerHTML()`: Outputs the HTML header.
- `footerHTML()`: Outputs the HTML footer.

## How to Run

1. Compile the C++ file using a C++ compiler (e.g., g++).
2. Run the compiled file.
3. Follow the prompts in the terminal to generate a calendar.
4. The calendar will be output to a file named "index.html".

## Dependencies

This program requires a C++ compiler.

## License

This project is licensed under the terms of the MIT license.
