# Development Note

## Use cases

### As a user, I would like to

- See 'zero' when I enter 0.
- See 'one' when I enter 1.
- See 'twelve thousand three hundred forty-five' when I enter 12345.
- See 'one million two hundred thirty-four thousand five hundred sixty-seven' when I enter 1234567.
- See 'four billion two hundred ninety-four million nine hundred sixty-seven thousand two hundred ninety-five' when I enter 4294967295.
- See an error message when I enter '123a'.
- See an error message when I enter '1,2,3'.
- See an error message when I enter '1,234'.
- See an error message when I enter -1.
- See an error message when I enter -42.
- See an error message when I enter greater number than the maximum value of unsigned integer.
- Terminate the programme when I enter 'q'.
- See input prompt again when I enter arbitrary characters other than 'q'.

## Detailed Procedures

1. Get an input from the user.
2. Parse the input into an unsigned integer.
   - When the input matches to a specific word, terminate the programme.
   - If it cannot be parsed, print out an error message and get user input again.
   - If successfully parsed to an unsigned integer, then proceed to next.
3. Get the numbers in each digit and make an array with them. I.e. 12,345 -> [1, 2, 3, 4, 5]
4. Group each element into sets of three from the right side. It is because numbers are separated by thousands in English.
   - When converting a number to a non-English language, the separators may be in different places.
5. Convert numbers per group to words from the lookup table, to handle irregular numbers, such as twelve for 12, not ten-two.
6. Append a decimal-separator word, such as billion, million, or thousand, on decimal separator locations.
   - Note: there are only three digit-separator words here, because the maximum number is 4,294,967,295.
7. Convert the next groups of numbers and append decimal-separator words until all the numbers have been processed.

## Items to consider

- Implement with C++
- Extend to non-English languages, including Korean, Japanese

## Mock process for English

1. Get user input.
   - `> 12345`
2. Parse the input string into the integer.
   - '12345' -> 12345
3. Find the remainders of the integer divided by powers of 10, and store them separately in a container.
   - [12345 % 10, 1234 % 10, 123 % 10, 12 % 10, 1 % 10] -> [5, 4, 3, 2, 1]
4. Pop two elements and convert them to words for ones digit and tens digit. This is because there are some irregular cardinal numbers, such as eleven, twelve, and so on.
   - (5, 4), [3, 2, 1] -> 'forty-five'
5. Pop an element and convert it to a word for hundreds digit.
   - (3), [2, 1] -> 'three hundred'
6. Pop an element from the thousands digits container [thousand, million, billion].
   - 'thousand', [million, billion]
7. Repeat steps 4 through 6, until the container is empty.
   - (2, 1), [] -> 'twelve'
8. Store the converted words in a Last-In-First-Out container at each step.
   - ['forty-five', 'three hundred', 'thousand', 'twelve']
9. Pop the words from the container in LIFO order to form a complete word.
   - twelve thousand three hundred forty-five

### Amend 1

1. Get user input.
   - `> 12345`
2. Verify that the string has fewer digits than the specified length limit.
   - '12345 -> Pass
   - '999999999999' (999,999,999,999) -> Pass
   - '1000000000000' (1,000,000,000,000) -> Fail
3. Verify that the string does not contain any non-numeric characters.
   - '12345' -> Pass
   - '12,345' -> Fail
   - '12345a' -> Fail
4. Get last 2 elements from the string, and convert them to words for ones digit and tens digit. This is because there are some irregular cardinal numbers, such as eleven, twelve, and so on.
   - 45 -> 'forty-five'
5. Get a previous element, and convert it to a word for hundreds digit.
   - 3 -> 'three hundred'
6. Pop an element from the thousands digits container [thousand, million, billion].
   - 'thousand', [million, billion]
7. Repeat steps 3 through 5, until the first number is processed.
   - 12 -> 'twelve'
8. Store the converted words in a Last-In-First-Out container at each step.
   - ['forty-five', 'three hundred', 'thousand', 'twelve']
9. Pop the words from the container in LIFO order to form a complete word.
   - twelve thousand three hundred forty-five

## Methods

- `void transform(const std::string &input)`: Entry point to transform the integer
- `uint32_t stoui(const std::string &input)`: Custom String to Integer function to handle numeric values only
- `bool isUnderLimit(const std::string &input);`: String validator function, whether it is shorter than the specified length
- `bool isNumber(const std::string &input)`: String validator function, whether it contains only all numeric values
