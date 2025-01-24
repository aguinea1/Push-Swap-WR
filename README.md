 [<img src="https://img.shields.io/badge/42-000000.svg?style=for-the-badge&logo=42&logoColor=white"/>](https://profile.intra.42.fr/users/aguinea)
<h1 align="center">
	PUSH SWAP WR
</h1>
Push Swap it's an algorithm project where you receive between 2 and an infinite quantity of numbers and the goal is to return all the numbers in order with the minimum number of movements (the less, the better). You have to columns (Stack A & Stack B), that you can use to sort the numbers

---
In this README, I will go straight to the explanation of the algorithm, but in this [other repo](https://github.com/aguinea1/Push-Swap-Turco), I have the explanation and functionality of the program, as well as the explanation of a much simpler algorithm with which you can also achieve 100/100.

---
## › Introduction

This algorithm is based on the algorithm developed by a Korean, and both I and a friend from 42 Barcelona have developed our own idea and optimizations. However, each of us has our own code format, which is why I’m sharing their GitHub here [(lbellmas)](https://github.com/lbellmas).
I’m not sure if it’s the world record, but I also haven’t found any code that consistently averages 4150 moves to sort 500 numbers.

---
## › Alghorithm

Broadly speaking, the algorithm aims to divide the numbers enough to hardcode small sorts of 2, 3, and 4 numbers. The first thing done is to divide the total numbers into three chunks, and depending on the range they fall into, they are moved to one position in the stacks or another. For example, if we have 100 numbers, the largest ones will be left at the bottom of stack A, the middle ones at the top of stack B, and the smallest ones at the bottom of stack B, so that the top of stack A is left free since that’s where we will analyze the numbers from. Once we divide the 100 numbers into 3 chunks (34, 33, and 33), we will further divide the largest chunk into 3 (12, 11, and 11) and send them to the same destinations as before:

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
