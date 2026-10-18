# Coding Practice Tracker

A C CLI for logging solved problems and summarizing progress by difficulty.

## Build

```sh
gcc -std=c11 -Wall -Wextra -pedantic app.c -o practice-tracker
```

Requires a C11 compiler. On Windows, use `-o practice-tracker.exe`.

## Use

```sh
./practice-tracker add "Two Sum" LeetCode easy arrays
./practice-tracker add "Example Graph Problem" LeetCode medium graphs
./practice-tracker list
./practice-tracker summary
```

Entries are stored in `problems.txt` in the current directory. Add only problems you have actually solved. Fields cannot contain `|`.

## Scope and next steps

Add solution links, dates, topic filters, review reminders, and export. Use your real platform profile links when presenting the project.
