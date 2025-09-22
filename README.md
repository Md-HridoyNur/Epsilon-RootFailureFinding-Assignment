# Demonstration of Root-Finding Failures

This project implements **Newton–Raphson** and **False Position (Regula Falsi)** methods in C++ to demonstrate situations where these methods fail or converge poorly. It includes examples such as bad initial guesses, functions with multiple roots, and other cases illustrating slow convergence.

---

## 🚀 Features

* Implementation of Newton–Raphson method.
* Implementation of False Position (Regula Falsi) method.
* Examples showing convergence and failure scenarios.
* Report and presentation summarizing findings.

---

## 📂 Repository Structure

```
Epsilon-RootFailureFinding-Assignment/
├── code/                  # C++ source files
│   ├── RootFailureFinding.cpp   # Main program demonstrating failure cases
│   ├── Falseposition.cpp
│   ├── NewtonRaphson.cpp
├── Reports/               
├── Presentation Slides/   
├── LICENSE
└── README.md              
```

---

## 🖥️ Usage

The main program **RootFailureFinding.cpp** demonstrates:

* How Newton–Raphson and False Position behave with different functions.
* Cases where methods fail or converge slowly.
* Experimentation with initial guesses or bracketing intervals to observe divergence, oscillation, or slow convergence.

Simply open **RootFailureFinding.cpp** and run the program; it contains predefined test functions and examples illustrating root-finding failures.

---

## 🔬 Experiments

The project demonstrates:

1. **Newton divergence** — a poor initial guess leading to divergence.
2. **Multiple roots** — slower convergence near repeated roots.
3. **False Position stagnation** — an endpoint stays fixed, causing slow convergence.
4. **Comparisons** — iteration vs error plots for different methods and functions.

---

## 📊 Visualizations

Logs from the program can be plotted using Python or gnuplot. Example (Python pseudocode):

```python
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('experiment.csv')
plt.semilogy(df.iteration, df.error)
plt.xlabel('Iteration')
plt.ylabel('Error')
plt.title('Newton vs False Position')
plt.show()
```

---

## 📝 Report & Slides

* **Report**: Found in `Reports/`
* **Slides**: Found in `Presentation Slides/`

Both contain theoretical explanations, experiment results, and conclusions.

---

## 📌 Failure Notes

* **Newton–Raphson**: fails with poor initial guesses, derivative near zero, or multiple roots. The method assumes the function is well-behaved near the root, so divergence or oscillation occurs if this assumption fails.
* **False Position**: guaranteed to keep a bracket around a root, but convergence may be extremely slow if one endpoint does not move. This happens because the method relies on a linear approximation of the function, which can be inaccurate on uneven slopes.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 👤 Author

Group- **Epsilon**

---

