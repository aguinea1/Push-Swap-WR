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

Broadly speaking, the algorithm aims to divide the numbers enough to hardcode small sorts of 2, 3, and 4 numbers, 
