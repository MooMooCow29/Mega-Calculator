#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <algorithm>

using namespace std;

// Define M_PI if not already defined.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Global flag for angle mode: false = radians, true = degrees.
bool angleInDegrees = false;

// Global flag for numeric output mode: false = fixed, true = scientific.
bool useScientific = false;

//--------------------------------------------------------------
// Function: factorial
// Computes factorial of a non-negative integer.
unsigned long long factorial(int n) {
    if (n < 0) return 0;  // error: negative input not allowed
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

//--------------------------------------------------------------
// Function: unitConversion
// Performs basic unit conversions for Temperature (Celsius ↔ Fahrenheit),
// Length (Miles ↔ Kilometers), and Weight (Pounds ↔ Kilograms).
void unitConversion() {
    char type;
    double value;
    cout << "\nUnit Conversion Options:\n";
    cout << "  t: Temperature (Celsius <-> Fahrenheit)\n";
    cout << "  l: Length (Miles <-> Kilometers)\n";
    cout << "  w: Weight (Pounds <-> Kilograms)\n";
    cout << "Enter conversion type: ";
    cin >> type;
    cout << "Enter value to convert: ";
    while (!(cin >> value)) {
        cout << "Invalid input! Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (type == 't' || type == 'T') {
        char direction;
        cout << "Convert (C)elsius to Fahrenheit or (F)ahrenheit to Celsius? ";
        cin >> direction;
        if (direction == 'C' || direction == 'c') {
            double result = (value * 9.0 / 5.0) + 32;
            cout << value << " Celsius = " << result << " Fahrenheit" << endl;
        }
        else if (direction == 'F' || direction == 'f') {
            double result = (value - 32) * 5.0 / 9.0;
            cout << value << " Fahrenheit = " << result << " Celsius" << endl;
        }
        else {
            cout << "Invalid direction!" << endl;
        }
    }
    else if (type == 'l' || type == 'L') {
        char direction;
        cout << "Convert (M)iles to Kilometers or (K)ilometers to Miles? ";
        cin >> direction;
        if (direction == 'M' || direction == 'm') {
            double result = value * 1.60934;
            cout << value << " Miles = " << result << " Kilometers" << endl;
        }
        else if (direction == 'K' || direction == 'k') {
            double result = value / 1.60934;
            cout << value << " Kilometers = " << result << " Miles" << endl;
        }
        else {
            cout << "Invalid direction!" << endl;
        }
    }
    else if (type == 'w' || type == 'W') {
        char direction;
        cout << "Convert (P)ounds to Kilograms or (K)ilograms to Pounds? ";
        cin >> direction;
        if (direction == 'P' || direction == 'p') {
            double result = value * 0.453592;
            cout << value << " Pounds = " << result << " Kilograms" << endl;
        }
        else if (direction == 'K' || direction == 'k') {
            double result = value / 0.453592;
            cout << value << " Kilograms = " << result << " Pounds" << endl;
        }
        else {
            cout << "Invalid direction!" << endl;
        }
    }
    else {
        cout << "Invalid conversion type!" << endl;
    }
}

//--------------------------------------------------------------
// Function: volumeConversion
// Converts volumes between Gallons and Liters.
void volumeConversion() {
    double value;
    char direction;
    cout << "\nVolume Conversion:\n";
    cout << "Convert (G)allons to Liters or (L)iters to Gallons? ";
    cin >> direction;
    cout << "Enter value: ";
    cin >> value;
    if (direction == 'G' || direction == 'g') {
        double result = value * 3.78541;
        cout << value << " Gallons = " << result << " Liters" << endl;
    }
    else if (direction == 'L' || direction == 'l') {
        double result = value / 3.78541;
        cout << value << " Liters = " << result << " Gallons" << endl;
    }
    else {
        cout << "Invalid direction!" << endl;
    }
}

//--------------------------------------------------------------
// Function: speedConversion
// Converts speeds between mph and km/h.
void speedConversion() {
    double value;
    char direction;
    cout << "\nSpeed Conversion:\n";
    cout << "Convert (M)ph to km/h or (K)m/h to mph? ";
    cin >> direction;
    cout << "Enter speed: ";
    cin >> value;
    if (direction == 'M' || direction == 'm') {
        double result = value * 1.60934;
        cout << value << " mph = " << result << " km/h" << endl;
    }
    else if (direction == 'K' || direction == 'k') {
        double result = value / 1.60934;
        cout << value << " km/h = " << result << " mph" << endl;
    }
    else {
        cout << "Invalid direction!" << endl;
    }
}

//--------------------------------------------------------------
// Function: plotSineWave
// Displays a simple text-based sine wave graph for angles 0 to 2π.
void plotSineWave() {
    cout << "\nSine Wave Graph (0 to 2π):\n";
    const int width = 70;
    const int height = 20;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double x = (2 * M_PI * j) / width;
            int sineY = static_cast<int>((sin(x) + 1) * (height - 1) / 2.0);
            if (i == (height - 1 - sineY))
                cout << "*";
            else if (j == width / 2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
}

//--------------------------------------------------------------
// Function: graphQuadraticFunction
// Graphs a quadratic function y = ax² + bx + c over the x-range [-10, 10].
void graphQuadraticFunction() {
    double a, b, c;
    cout << "\nGraph Quadratic Function:\n";
    cout << "Enter coefficients a, b, c for y = ax^2 + bx + c: ";
    cin >> a >> b >> c;

    const int width = 70;
    const int height = 20;
    vector<double> yvals(width);

    // Compute x range from -10 to 10 and determine y values.
    double xmin = -10, xmax = 10;
    for (int j = 0; j < width; j++) {
        double x = xmin + (xmax - xmin) * j / (width - 1);
        yvals[j] = a * x * x + b * x + c;
    }
    // Find min and max y for scaling.
    double ymin = *min_element(yvals.begin(), yvals.end());
    double ymax = *max_element(yvals.begin(), yvals.end());

    // Plot the graph line by line.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Map y value to a row index.
            int row = static_cast<int>((yvals[j] - ymin) / (ymax - ymin) * (height - 1));
            // Invert row index because 0 is top.
            row = height - 1 - row;
            if (i == row)
                cout << "*";
            else if (j == width / 2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
}

//--------------------------------------------------------------
// Function: solveQuadraticEquation
// Solves a quadratic equation ax² + bx + c = 0 and prints the real or complex roots.
void solveQuadraticEquation() {
    double a, b, c;
    cout << "\nSolve Quadratic Equation:\n";
    cout << "Enter coefficients a, b, c: ";
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "Not a quadratic equation." << endl;
        return;
    }
    double disc = b * b - 4 * a * c;
    if (disc < 0) {
        // Complex roots.
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-disc) / (2 * a);
        cout << "Complex roots: " << realPart << " ± " << imagPart << "i" << endl;
    }
    else {
        double x1 = (-b + sqrt(disc)) / (2 * a);
        double x2 = (-b - sqrt(disc)) / (2 * a);
        cout << "Roots: " << x1 << " and " << x2 << endl;
    }
}

//--------------------------------------------------------------
// Function: complexOperations
// Performs arithmetic operations (+, -, *, /) on two complex numbers.
void complexOperations() {
    double a, b, c, d;
    char op;
    cout << "\nComplex Number Operations:\n";
    cout << "Enter first complex number (real and imaginary parts): ";
    cin >> a >> b;
    cout << "Enter second complex number (real and imaginary parts): ";
    cin >> c >> d;
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;
    complex<double> z1(a, b), z2(c, d), res;
    switch (op) {
    case '+': res = z1 + z2; break;
    case '-': res = z1 - z2; break;
    case '*': res = z1 * z2; break;
    case '/':
        if (c == 0 && d == 0) {
            cout << "Division by zero!" << endl;
            return;
        }
        res = z1 / z2; break;
    default:
        cout << "Invalid operation!" << endl;
        return;
    }
    cout << "Result: " << res << endl;
}

//--------------------------------------------------------------
// Function: randomNumberGeneration
// Generates a random integer within a specified range.
void randomNumberGeneration() {
    int minVal, maxVal;
    cout << "\nRandom Number Generation:\n";
    cout << "Enter minimum value: ";
    cin >> minVal;
    cout << "Enter maximum value: ";
    cin >> maxVal;
    if (minVal > maxVal) {
        cout << "Error: Minimum is greater than maximum." << endl;
        return;
    }
    int r = minVal + rand() % (maxVal - minVal + 1);
    cout << "Random number: " << r << endl;
}

//--------------------------------------------------------------
// Function: logArbitraryBase
// Computes logarithm of a value with an arbitrary base.
void logArbitraryBase() {
    double value, base;
    cout << "\nLogarithm with Arbitrary Base:\n";
    cout << "Enter value: ";
    cin >> value;
    cout << "Enter base: ";
    cin >> base;
    if (value <= 0 || base <= 0 || base == 1) {
        cout << "Invalid input for logarithm." << endl;
        return;
    }
    double result = log(value) / log(base);
    cout << "log base " << base << " of " << value << " = " << result << endl;
}

//--------------------------------------------------------------
// Function: statisticsFunctions
// Computes and displays the mean and median of a list of numbers.
void statisticsFunctions() {
    int n;
    cout << "\nStatistics Functions:\n";
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return;
    }
    vector<double> nums(n);
    cout << "Enter the numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    double sum = 0;
    for (auto num : nums) sum += num;
    double mean = sum / n;
    sort(nums.begin(), nums.end());
    double median = (n % 2 == 0) ? (nums[n / 2 - 1] + nums[n / 2]) / 2.0 : nums[n / 2];
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    // (Mode calculation is omitted for brevity.)
}

//--------------------------------------------------------------
// Function: binaryHexConversion
// Converts an integer to its binary and hexadecimal representations.
void binaryHexConversion() {
    int num;
    cout << "\nBinary and Hexadecimal Conversion:\n";
    cout << "Enter an integer: ";
    cin >> num;
    // Convert to binary.
    string binary;
    int temp = num;
    if (temp == 0) binary = "0";
    while (temp > 0) {
        binary = char('0' + (temp % 2)) + binary;
        temp /= 2;
    }
    cout << "Binary: " << binary << endl;
    // Convert to hexadecimal.
    stringstream ss;
    ss << hex << num;
    string hexStr = ss.str();
    cout << "Hexadecimal: " << hexStr << endl;
}

//--------------------------------------------------------------
// Function: matrix2x2Multiplication
// Multiplies two 2×2 matrices and displays the resultant matrix.
void matrix2x2Multiplication() {
    double A[2][2], B[2][2], C[2][2];
    cout << "\n2x2 Matrix Multiplication:\n";
    cout << "Enter elements of the first 2x2 matrix (row-wise): ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter elements of the second 2x2 matrix (row-wise): ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }
    // Multiply matrices: C = A * B.
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
        }
    }
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

//--------------------------------------------------------------
// Function: loadHistory
// Loads calculation history from "calculation_history.txt" into the provided vector.
void loadHistory(vector<string>& history) {
    ifstream inFile("calculation_history.txt");
    if (!inFile) {
        cout << "Could not open history file for reading." << endl;
        return;
    }
    history.clear();
    string line;
    while (getline(inFile, line)) {
        history.push_back(line);
    }
    inFile.close();
    cout << "History loaded from calculation_history.txt" << endl;
}

//--------------------------------------------------------------
// Function: toggleScientificNotation
// Toggles the global flag for using scientific notation.
void toggleScientificNotation() {
    useScientific = !useScientific;
    cout << "Scientific notation " << (useScientific ? "enabled" : "disabled") << endl;
}

//--------------------------------------------------------------
// Main Function
// Contains the main loop displaying the menu and processing user input.
int main(int argc, char* argv[]) {
    // Seed the random number generator.
    srand(static_cast<unsigned int>(time(0)));

    // If command-line arguments are provided, note that expression evaluation isn't implemented.
    if (argc > 1) {
        cout << "Command-line expression evaluation is not implemented in this version." << endl;
    }

    // Memory slots: 10 slots initialized to zero.
    double memorySlots[10] = { 0 };

    // Variables for basic operations.
    double num1, num2;
    char operation;

    bool continueCalculating = true;
    int precision = 6;  // Default output precision.

    // History storage.
    vector<string> history;

    // Main loop.
    while (continueCalculating) {
        // Set numeric output mode.
        if (useScientific)
            cout << scientific << setprecision(precision);
        else
            cout << fixed << setprecision(precision);

        // Display the comprehensive menu.
        cout << "\n=== Mega Calculator Menu ===\n";
        cout << "Basic Operations (two operands): +, -, *, /, ^, %\n";
        cout << "Advanced Operations (one operand):\n";
        cout << "    r: Square Root, s: Sine, c: Cosine, t: Tangent,\n";
        cout << "    l: Natural Log (ln), L: Log Base 10, f: Factorial, b: Log (arbitrary base)\n";
        cout << "Memory Operations (multiple slots 0-9):\n";
        cout << "    M: Store, R: Recall, X: Clear, A: Add, D: Subtract\n";
        cout << "Other Options:\n";
        cout << "    p: Set Output Precision, d: Toggle Angle Mode (Degrees/Radians), N: Toggle Scientific Notation\n";
        cout << "    u: Unit Conversion, v: Volume Conversion, w: Speed Conversion\n";
        cout << "    g: Graph Sine Wave, q: Graph Quadratic, Q: Solve Quadratic Equation\n";
        cout << "    x: Complex Number Operations, z: Random Number Generation\n";
        cout << "    k: Statistics (Mean & Median), Y: Convert to Binary/Hex, m: 2x2 Matrix Multiplication\n";
        cout << "    E: Export History, O: Load History, h: View History\n";
        cout << "    e: Exit\n";
        cout << "\nEnter an operation: ";
        cin >> operation;

        // Process exit.
        if (operation == 'e' || operation == 'E') {
            cout << "Goodbye!" << endl;
            break;
        }

        // Process options that require no further operands.
        if (operation == 'h' || operation == 'H') {
            cout << "\nCalculation History:\n";
            for (const auto& record : history)
                cout << record << endl;
            continue;
        }
        if (operation == 'E') {
            ofstream outFile("calculation_history.txt");
            if (outFile.is_open()) {
                for (const auto& record : history)
                    outFile << record << endl;
                outFile.close();
                cout << "History exported to calculation_history.txt" << endl;
            }
            else {
                cout << "Error: Could not open file for writing!" << endl;
            }
            continue;
        }
        if (operation == 'O') {
            loadHistory(history);
            continue;
        }
        if (operation == 'u' || operation == 'U') {
            unitConversion();
            continue;
        }
        if (operation == 'v' || operation == 'V') {
            volumeConversion();
            continue;
        }
        if (operation == 'w' || operation == 'W') {
            speedConversion();
            continue;
        }
        if (operation == 'g' || operation == 'G') {
            plotSineWave();
            continue;
        }
        if (operation == 'q') {
            graphQuadraticFunction();
            continue;
        }
        if (operation == 'Q') {
            solveQuadraticEquation();
            continue;
        }
        if (operation == 'x' || operation == 'X') { // Use lowercase x for complex operations.
            complexOperations();
            continue;
        }
        if (operation == 'z' || operation == 'Z') {
            randomNumberGeneration();
            continue;
        }
        if (operation == 'b') {
            logArbitraryBase();
            continue;
        }
        if (operation == 'k' || operation == 'K') {
            statisticsFunctions();
            continue;
        }
        if (operation == 'Y') {
            binaryHexConversion();
            continue;
        }
        if (operation == 'm') {
            matrix2x2Multiplication();
            continue;
        }
        if (operation == 'p' || operation == 'P') {
            cout << "Enter desired precision (number of decimal places): ";
            while (!(cin >> precision)) {
                cout << "Invalid input! Please enter a valid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            continue;
        }
        if (operation == 'd' || operation == 'D') {
            angleInDegrees = !angleInDegrees;
            cout << "Angle mode toggled. Now using " << (angleInDegrees ? "Degrees" : "Radians") << endl;
            continue;
        }
        if (operation == 'N') {
            toggleScientificNotation();
            continue;
        }

        // Memory Operations using multiple slots (0-9).
        if (operation == 'M') { // Store value to a memory slot.
            int slot;
            cout << "Enter memory slot (0-9) to store value: ";
            cin >> slot;
            if (slot < 0 || slot > 9) {
                cout << "Invalid slot!" << endl;
                continue;
            }
            cout << "Enter value to store: ";
            while (!(cin >> num1)) {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            memorySlots[slot] = num1;
            cout << "Memory slot " << slot << " set to " << num1 << endl;
            continue;
        }
        if (operation == 'R') { // Recall value from a memory slot.
            int slot;
            cout << "Enter memory slot (0-9) to recall: ";
            cin >> slot;
            if (slot < 0 || slot > 9) {
                cout << "Invalid slot!" << endl;
                continue;
            }
            cout << "Memory slot " << slot << " contains " << memorySlots[slot] << endl;
            continue;
        }
        if (operation == 'X') { // Clear a memory slot.
            int slot;
            cout << "Enter memory slot (0-9) to clear: ";
            cin >> slot;
            if (slot < 0 || slot > 9) {
                cout << "Invalid slot!" << endl;
                continue;
            }
            memorySlots[slot] = 0;
            cout << "Memory slot " << slot << " cleared." << endl;
            continue;
        }
        if (operation == 'A') { // Add to a memory slot.
            int slot;
            cout << "Enter memory slot (0-9) to add to: ";
            cin >> slot;
            if (slot < 0 || slot > 9) {
                cout << "Invalid slot!" << endl;
                continue;
            }
            cout << "Enter value to add: ";
            while (!(cin >> num1)) {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            memorySlots[slot] += num1;
            cout << "Memory slot " << slot << " now contains " << memorySlots[slot] << endl;
            continue;
        }
        if (operation == 'D') { // Subtract from a memory slot.
            int slot;
            cout << "Enter memory slot (0-9) to subtract from: ";
            cin >> slot;
            if (slot < 0 || slot > 9) {
                cout << "Invalid slot!" << endl;
                continue;
            }
            cout << "Enter value to subtract: ";
            while (!(cin >> num1)) {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            memorySlots[slot] -= num1;
            cout << "Memory slot " << slot << " now contains " << memorySlots[slot] << endl;
            continue;
        }

        // For basic arithmetic operations (require two operands).
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/' ||
            operation == '^' || operation == '%') {
            cout << "Enter first number: ";
            while (!(cin >> num1)) {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            double result = 0;
            switch (operation) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero!" << endl;
                    continue;
                }
                result = num1 / num2;
                break;
            case '^': result = pow(num1, num2); break;
            case '%':
                result = static_cast<int>(num1) % static_cast<int>(num2);
                break;
            default:
                cout << "Invalid operation!" << endl;
                continue;
            }
            cout << "Result: " << result << endl;
            // Record the operation in history.
            ostringstream oss;
            oss << num1 << " " << operation << " " << num2 << " = " << result;
            history.push_back(oss.str());
            continue;
        }

        // For advanced operations that require one operand.
        if (operation == 'r' || operation == 's' || operation == 'c' || operation == 't' ||
            operation == 'l' || operation == 'L' || operation == 'f') {
            cout << "Enter number: ";
            while (!(cin >> num1)) {
                cout << "Invalid input! Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            double result = 0;
            ostringstream oss;
            switch (operation) {
            case 'r': // Square root.
                if (num1 < 0) {
                    cout << "Error: Cannot compute square root of a negative number!" << endl;
                    continue;
                }
                result = sqrt(num1);
                oss << "sqrt(" << num1 << ") = " << result;
                break;
            case 's': // Sine.
                result = (angleInDegrees) ? sin(num1 * M_PI / 180) : sin(num1);
                oss << "sin(" << num1 << ") = " << result;
                break;
            case 'c': // Cosine.
                result = (angleInDegrees) ? cos(num1 * M_PI / 180) : cos(num1);
                oss << "cos(" << num1 << ") = " << result;
                break;
            case 't': // Tangent.
                result = (angleInDegrees) ? tan(num1 * M_PI / 180) : tan(num1);
                oss << "tan(" << num1 << ") = " << result;
                break;
            case 'l': // Natural logarithm.
                if (num1 <= 0) {
                    cout << "Error: Logarithm undefined for zero or negative numbers!" << endl;
                    continue;
                }
                result = log(num1);
                oss << "ln(" << num1 << ") = " << result;
                break;
            case 'L': // Log base 10.
                if (num1 <= 0) {
                    cout << "Error: Logarithm undefined for zero or negative numbers!" << endl;
                    continue;
                }
                result = log10(num1);
                oss << "log10(" << num1 << ") = " << result;
                break;
            case 'f': // Factorial.
            {
                int intNum = static_cast<int>(num1);
                if (num1 < 0 || num1 != intNum) {
                    cout << "Error: Factorial is only defined for non-negative integers!" << endl;
                    continue;
                }
                unsigned long long fact = factorial(intNum);
                cout << "Result: " << fact << endl;
                oss << intNum << "! = " << fact;
                history.push_back(oss.str());
                continue;
            }
            }
            cout << "Result: " << result << endl;
            history.push_back(oss.str());
            continue;
        }

        // If we reach here, the entered operation was not recognized.
        cout << "Invalid operation entered." << endl;
    }

    return 0;
}

