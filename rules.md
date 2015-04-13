# Scoring

- You are given 7 problems to solve in 2.5 hours. Statements of all problems become available to read at the moment the contest starts.
- For each problem, you must give correct answers within specified time limit and memory limit to all the test cases prepared by organizers.
- The participants are ranked according to the number of problems solved. In case of tie, the time of last correct submission is used to decide winner. There is no penalty for wrong submissions.
- You can submit at most 70 times for all problems. For example, if you submitted 30 times for 1st problem, then you only have 40 submissions for the other 6 problems.

# Questions & Clarifications

- If you have any questions regarding the problem statement, please use the Communication tab in our web interface to send question to organizers. We will answer as soon as possible.
- In case some problem statement is unclear, organizers may add extra time for all participants, depending on how much the participants were affected.

# Can do and Cannot do

- You are allowed to use any books and personal notes as well as a code written beforehand by you personally.
- You may use third-party prewritten code, given that the code was written and published/distributed before the start of the contest, and usage of third-party code should not violate the right holder’s license or copyright.
- If there are any doubts about the time of publication, possible collaboration etc., a participant will have to prove his/her complete innocence by presenting compelling and satisfactory evidence.
- The contestants are forbidden to talk about subjects, related to the problems, with anybody, including other contestants. It is only allowed to ask questions to the organizers via the system.
- The organizers of the contests have the right to monitor the contestants' honesty in behavior using different methods and disqualify the contestant if violations are found.
- All programs submitted by the contestants for judging, should be aimed at solving the problem and not at violating rules or destabilizing the judging system. A contestant who deliberately attempts to destabilize the judging system, will be disqualified.

# Responsibilities of organizers

- Organizers will answer questions to clarify doubts on problem statement as soon as possible.
- In case there is some issue with problem statement or prepared test cases, organizers will fix the errors as soon as possible, and will make announcement to all participants. Extra time may be added if necessary. In case the problem can not be fixed, it will be removed.

# How your solution is compiled & run

Your solution is compiled and run automatically. Assume your program is saved with name "problem.xx" (where xx can be py, c, cpp or java, depending on the language). The command used for compilation are:

- C:
```
/usr/bin/gcc -DEVAL -static -O2 -o problem problem.c -lm
```
- C++:
```
/usr/bin/g++ -DEVAL -static -O2 -o problem problem.cpp
```
- Java:
```
/usr/bin/gcj --main=problem -O3 -o problem problem.java
```
- Python:
```
/usr/bin/python2 -m py_compile problem.py
/bin/mv problem.pyc problem
```

# Notes for Java participants:

- Scanner and PrintWriter are very slow. If the problem has large input/output, please use BufferedReader and BufferedWriter
- The compiler used for Java, gcj, is known to have some problem in our system when printing floating number. For printing floating number, please convert to integer first, for example, to print variable `x` with 2 digits after decimal point:

```java
int x_int = (int) (x * 100 + 1e-6); // add 1e-6 to avoid precision error when converting to int
System.out.printf("%d.%02d\n", x_int / 100, x_int % 100);
```

# Notes for Python participants:

- Lists might be too slow / memory consuming for our problems. Please consider using [array](https://docs.python.org/2/library/array.html) if possible.
