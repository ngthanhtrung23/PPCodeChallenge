# Statement

`HQ9+` is a joke language (not even esoteric) which has only 4 instructions and is thus capable of only 4 actions:

- `H` prints “Hello, World!” (the exact syntax of the printed sentence varies across implementations)
- `Q` prints the text of the source code (thus, single-command code “Q” is a [quine](http://en.wikipedia.org/wiki/Quine_(computing)))
- `9` prints the lyrics of “99 Bottles of Beer” (the exact text varies across different implementations as well)
- `+` increments the accumulator (which you can’t access anyways)

The language was created around 2001 by Cliff L. Biffle. The language is one of the simplest esoteric languages to implement, so the most interesting thing about it is not writing about it but rather writing its interpreter.

In this problem, you are asked to write an interpreter for the language.

# Input
The input has a single line: a program in `HQ9+`. The program contains at most 100 characters. The characters other than `H`, `Q`, `9`, `+` are ignored.

# Output
The output of the HQ9+ program. After `H`, `Q` and `9` commands, print a new line.

# Example
## Input
```
H+HABCQQ
```
## Output
```
Hello, World!
Hello, World!
H+HABCQQ
H+HABCQQ
```

# Note

The lyrics of "99 Bottles of Beer" is as follows:

```
99 bottles of beer on the wall,
99 bottles of beer.
Take one down, pass it around,
98 bottles of beer on the wall.

98 bottles of beer on the wall,
98 bottles of beer.
Take one down, pass it around,
97 bottles of beer on the wall.

...

2 bottles of beer on the wall,
2 bottles of beer.
Take one down, pass it around,
1 bottle of beer on the wall.

1 bottle of beer on the wall,
1 bottle of beer.
Take one down, pass it around,
No bottles of beer on the wall.

```

Since the lyrics is too long, the middle part is ommitted (and replaced with `...`), but you need to print the full lyrics. Please carefully note the empty lines between the paragraphs.
