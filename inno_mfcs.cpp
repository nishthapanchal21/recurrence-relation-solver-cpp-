#include <iostream>
#include <cmath>
using namespace std;

// ======================================================
// 1️⃣ Algorithm recurrence (Master theorem type)
// ======================================================

// Recursive function to show "recursion tree"
long long masterRecurrence(long long n, int a, int b, int type, int level = 0) {
    if (n <= 1) {
        for (int i = 0; i < level; i++) cout << "    "; // indentation using spaces
        cout << "T(" << n << ") = 1 (base case)\n";
        return 1;
    }

    long long work;
    if (type == 1)
        work = 1;     // f(n)=1
    else if (type == 2)
        work = n;     // f(n)=n
    else
        work = n * n; // f(n)=n^2

    for (int i = 0; i < level; i++) cout << "    ";
    cout << "T(" << n << ") = " << a << "*T(" << n / b << ") + " << work << "\n";

    long long sub = a * masterRecurrence(n / b, a, b, type, level + 1);
    return sub + work;
}

void runMasterTheorem() {
    long long n;
    int a, b, type;
    cout << "\n--- Master Theorem Recurrence Solver ---\n";
    cout << "Enter n (problem size): ";
    cin >> n;
    cout << "Enter a (number of subproblems): ";
    cin >> a;
    cout << "Enter b (division factor): ";
    cin >> b;

    cout << "\nChoose work function f(n):\n";
    cout << "1. Constant f(n)=1 (like Binary Search)\n";
    cout << "2. Linear f(n)=n (like Merge Sort)\n";
    cout << "3. Quadratic f(n)=n^2 (like Matrix Multiply)\n";
    cout << "Enter choice: ";
    cin >> type;

    cout << "\n--- Recursion Tree Trace ---\n";
    long long result = masterRecurrence(n, a, b, type);

    cout << "\nTotal combined work (simulated): " << result << endl;

    double logba = log(a) / log(b);
    cout << "\n--- Theoretical Analysis ---\n";
    cout << "n^(log_b a) = n^(" << logba << ")\n";

    if (type == 1) {
        cout << "f(n)=1 → compare with n^(" << logba << ")\n";
        if (logba > 0)
            cout << "Case 1 ⇒ T(n)=Θ(n^(" << logba << "))\n";
        else
            cout << "Case 2 ⇒ T(n)=Θ(log n)\n";
    } else if (type == 2) {
        cout << "f(n)=n → compare with n^(" << logba << ")\n";
        if (fabs(logba - 1.0) < 0.0001)
            cout << "Case 2 ⇒ T(n)=Θ(n log n)\n";
        else if (logba > 1)
            cout << "Case 1 ⇒ T(n)=Θ(n^(" << logba << "))\n";
        else
            cout << "Case 3 ⇒ T(n)=Θ(n)\n";
    } else {
        cout << "f(n)=n^2 → compare with n^(" << logba << ")\n";
        if (logba < 2)
            cout << "Case 3 ⇒ T(n)=Θ(n^2)\n";
        else if (logba > 2)
            cout << "Case 1 ⇒ T(n)=Θ(n^(" << logba << "))\n";
        else
            cout << "Case 2 ⇒ T(n)=Θ(n^2 log n)\n";
    }
}

// ======================================================
// 2️⃣ Sequence recurrence (Characteristic equation type)
// ======================================================
double sequenceRecurrence(int n, double A, double B) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    double discriminant = A * A + 4 * B;
    double r1 = (A + sqrt(discriminant)) / 2.0;
    double r2 = (A - sqrt(discriminant)) / 2.0;

    double C1 = 1 / (r1 - r2);
    double C2 = -C1;

    return C1 * pow(r1, n) + C2 * pow(r2, n);
}

void runSequenceSolver() {
    cout << "\n--- Sequence Recurrence Solver ---\n";
    cout << "Form: a_n = A*a_{n-1} + B*a_{n-2}\n";
    cout << "Base cases: a0=0, a1=1\n";

    double A, B;
    int n;
    cout << "Enter A and B: ";
    cin >> A >> B;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid n! Must be non-negative.\n";
        return;
    }

    double ans = sequenceRecurrence(n, A, B);
    cout << "\na(" << n << ") = " << round(ans) << " (approx)\n";

    if (A == 1 && B == 1)
        cout << "→ This is the Fibonacci sequence!\n";
}

// ======================================================
// 3️⃣ Main menu
// ======================================================
int main() {
    cout << "=============================================\n";
    cout << "     UNIVERSAL RECURRENCE RELATION SOLVER     \n";
    cout << "=============================================\n";

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Algorithm Recurrence (Master Theorem)\n";
        cout << "2. Sequence Recurrence (Fibonacci or similar)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
            runMasterTheorem();
        else if (choice == 2)
            runSequenceSolver();
        else if (choice == 3) {
            cout << "\nThank you for using the solver! Goodbye.\n";
            break;
        } else
            cout << "Invalid choice! Please try again.\n";
    }

    return 0;
}