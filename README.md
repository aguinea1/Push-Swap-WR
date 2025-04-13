<h1 align="center">
	PUSH SWAP WR
</h1>

<p align="center">
	<img src="https://img.shields.io/badge/Language-C-blue?style=flat-square"/>
	<img src="https://img.shields.io/badge/Stacks-A%20%26%20B-yellow?style=flat-square"/>
	<img src="https://img.shields.io/badge/500%20Numbers-4150%20Moves-brightgreen?style=flat-square"/>
</p>

---

## 🧠 What is Push Swap?

Push Swap is an algorithmic challenge where the goal is to sort a sequence of numbers using two stacks (**A** and **B**) and a limited set of operations. The challenge is to **sort efficiently with the fewest number of moves possible**.

In this version, the algorithm achieves an average of **~4150 moves for 500 numbers**, making it one of the most optimized publicly available solutions.

> ⚠️ This README focuses on explaining the **algorithmic strategy**. For a breakdown of program functionality, usage, and a simpler version of the algorithm, check out this other repo: [Push-Swap-Turco](https://github.com/aguinea1/Push-Swap-Turco)

---

## 🚀 Highlights

- ⚡️ Average of **4150 moves** for sorting 500 numbers
- 🔍 Advanced chunk division and value distribution
- 🧩 Hardcoded mini-sort logic for small cases
- 💡 Inspired by Korean optimizations, rethought and adapted

---

## 🧩 Algorithm Overview

The algorithm is based on splitting the input into progressively smaller **value chunks** and strategically pushing them between stacks based on their relative size. The idea is to isolate and order small groups of numbers (2, 3, or 4) and then reassemble the full sorted list.

- Step 1: Split numbers into 3 major chunks based on value range.
- Step 2: Push values to specific zones in Stack A or Stack B:
  - 🔽 Larger numbers → bottom of A  
  - 🟨 Medium numbers → top of B  
  - 🔼 Smaller numbers → bottom of B
  - 📝 The splitting distribution it's going to change depending on the splited chunk place.
- Step 3: Further split the largest chunk again into smaller parts and repeat the distribution logic.

---

## 📊 Chunking Visualization

Here’s a visual explanation of how values are distributed across stacks:

              +---------+   +---------+                +---------+   +---------+                +---------+   +---------+                +---------+   +---------+
              |         |   |         |                |         |   |    33   |                |         |   |    11   |                |         |   |    4    |
              |         |   |         |                |         |   |---------|                |         |   |---------|                |         |   |---------|
              |         |   |         |                |         |   |    33   |                |         |   |    33   |                |         |   |    11   |
              |   100   |   |         |      ======>   |    33   |   +---------+      ======>   |    11   |   |---------|   ======>      |    4    |   |---------|
              |         |   |         |                |         |                              |         |   |    33   |                |         |   |    33   |
              |         |   |         |                |         |                              |         |   |---------|                |         |   |---------|
              |         |   |         |                |         |                              |         |   |    11   |                |         |   |    33   |
              +---------+   +---------+                +---------+                              +---------+   +---------+                +---------+   |---------|
                Stack A       Stack B                    Stack A       Stack B                    Stack A       Stack B                                |    11   |
                                                                                                                                                       |---------|
                                                                                                                                                       |    3    |
                                                                                                                                                       +---------+
                                                                                                                                           Stack A       Stack B 


      
---

## ⚙️ How It Works

- **Hardcoding mini-cases**: Sorts of 2–4 numbers are done manually and quickly without recursion.
- **Chunk targeting**: Each number’s destination is selected based on its value rank and current chunk.
- **Smart rotations**: Optimized `rotate`, `reverse rotate`, and `push` operations are used to minimize step count.
- **Greedy insertion**: During the merge phase, numbers are reinserted into Stack A in the most efficient position possible.

---

## 🤝 Credits

This version of the algorithm was inspired by a Korean optimization shared among peers.  
It was independently developed and implemented by myself, with additional discussions and brainstorming with [@lbellmas](https://github.com/lbellmas).  
Despite trying to find similar results online, I haven’t found other public solutions that maintain consistent performance at this level.

---

## 📫 Contact

Feel free to reach out or explore more of my work:

[<img src="https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white"/>](https://www.linkedin.com/in/aitor-guinea-961635348/)
[<img src="https://img.shields.io/badge/GitHub-aguinea1-black?style=flat-square&logo=github"/>](https://github.com/aguinea1)
[<img src="https://img.shields.io/badge/Email-aguinea1@gmail.com-red?style=flat-square&logo=gmail&logoColor=white"/>](mailto:aguinea1@gmail.com)

---
⭐
