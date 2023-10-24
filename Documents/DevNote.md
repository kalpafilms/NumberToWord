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
