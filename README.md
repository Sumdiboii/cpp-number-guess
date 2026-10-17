<!-- TITLE with Animated Typing Effect -->
<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=1B7A43&center=true&vCenter=true&width=600&lines=Number+Guess%3A+Pick+It%2C+Guess+It%2C+Beat+It;Fewest+Tries+Wins.;Clean+C%2B%2B%2C+Zero+Dependencies." alt="Typing SVG" />
</p>

<h1 align="center">🎯 Number Guess 🎯</h1>
<h3 align="center">Guess It, Beat Your Best, Never Lose Your Score.</h3>

<br>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-1B7A43?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Dependencies-None-1B7A43?style=for-the-badge" alt="Zero Dependencies" />
  <img src="https://img.shields.io/badge/Platform-Terminal-1B7A43?style=for-the-badge&logo=gnubash&logoColor=white" alt="Terminal" />
</p>

<br>

---

## 🚀 What Did I Build?

**Number Guess** is a command-line guessing game written in **C++** that picks a secret number, gives you hints, and **remembers your best score between sessions**.

- **Random secret number** between 1 and 100, seeded from the system clock so every round is different
- **Higher / lower hints** after every guess to guide you toward the answer
- **Persistent high score**: your fewest-tries record is saved to disk and loaded on the next launch
- **Input validation**: letters, symbols, or garbage input never crash the game or burn an attempt
- **Replay loop**: keep playing round after round without restarting the program
- **Zero dependencies**: only the C++ standard library, compiles anywhere with a modern compiler

<br>

---

<br>

## ☁️ What is This Project?

**Number Guess** is a small, focused project built to shake off the cobwebs and get back to writing clean C++. It is deliberately simple in scope, so the attention goes where it matters: readable structure, defensive input handling, and correct file I/O.

The game keeps its state in a plain `highscore.txt` file. On launch it loads the stored record (or falls back to a sentinel value if none exists), and after each round it only writes to disk when the player actually beats the record.

It is built to be the kind of code you can read top to bottom in one sitting: small functions with a single job, clear comments, and no cleverness for its own sake.

<br>

---

<br>

## 🛠️ Tech Stack and Tools

<br>

<div align="center">

<table>
  <thead>
    <tr>
      <th>Tech Used</th>
      <th>Purpose</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>C++</td>
      <td>Core game logic and program flow</td>
    </tr>
    <tr>
      <td>&lt;iostream&gt;</td>
      <td>Console input and output</td>
    </tr>
    <tr>
      <td>&lt;cstdlib&gt;</td>
      <td>Pseudo-random number generation with <code>rand()</code> and <code>srand()</code></td>
    </tr>
    <tr>
      <td>&lt;ctime&gt;</td>
      <td>Time-based seeding of the random number generator</td>
    </tr>
    <tr>
      <td>&lt;fstream&gt;</td>
      <td>Reading and writing the persistent high score file</td>
    </tr>
  </tbody>
</table>

</div>

<br>

---

## 🧭 Architecture

<p align="center">
  <img src="docs/architecture.svg" alt="Number Guess system architecture" width="900" />
</p>

---

<br>

## ⚙️ Getting Started

**Compile**

```bash
g++ -o number_guess main.cpp
```

**Run**

```bash
./number_guess
```

**Sample session**

```text
=====================================
       WELCOME TO NUMBER GUESS
=====================================
No high score set yet. Be the first!

I have picked a number between 1 and 100. Try to guess it!
Enter your guess: 50
Too high! Try again.
Enter your guess: 25
Too low! Try again.
Enter your guess: 37

🎉 Correct! You found the number in 3 attempts.
🏆 NEW HIGH SCORE! Saved to disk.

Play again? (y/n):
```

<br>

---

<br>

## 🔐 Core Features

- 🎲 Random secret number from 1 to 100, freshly seeded every launch
- 🔼 Instant "too high" and "too low" feedback on every guess
- 💾 High score saved to `highscore.txt` and restored on the next run
- 🛡️ Invalid input is caught, the stream is reset, and the player is prompted again
- 🔁 Play-again loop that preserves the best score across rounds
- 🏆 Disk is only written when a new record is actually set
- 📦 Single source file, standard library only

<br>

---

<br>

## 🔍 Learning Highlights

- Practiced **file I/O with `fstream`**, including safe handling of a missing or unreadable file by falling back to a sensible default
- Handled **bad user input** correctly with `std::cin.clear()` and `std::cin.ignore()`, so a failed read never leaves the stream in an error state
- Used a **sentinel value** for "no score yet" so first-run and returning-player flows share one code path
- Kept **persistence logic in dedicated functions** (`loadHighScore`, `saveHighScore`), separate from the game loop
- Seeded the RNG from the system clock with an explicit `static_cast`, avoiding silent narrowing conversions
- Wrote the game flow so the **score is compared and saved once per round**, not on every guess

<br>

---

<br>


## 👨‍💻 About the Creator

*LinkedIn - [Sumedh Pimplikar](https://www.linkedin.com/in/sumedh-pimplikar)*

