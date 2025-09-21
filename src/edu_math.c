#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // Добавлено для INT_MAX

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
    return a + b;
}

int edu_sub(int a, int b) {
    return a - b;
}

int edu_mult(int a, int b) {
    return a * b;
}

int edu_div(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "[ERROR] Division by zero\n");
        abort();
    }
    return a / b;
}

int edu_mod(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "[ERROR] Division by zero in modulo operation\n");
        abort();
    }
    return a % b;
}

int edu_pow(int base, int exponent) {
    if (exponent < 0) {
        fprintf(stderr, "[ERROR] Negative exponents not supported for integers\n");
        abort();
    }
    
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        // Check for integer overflow
        if (result > INT_MAX / base && base > 0) {
            fprintf(stderr, "[ERROR] Integer overflow in power operation\n");
            abort();
        }
        result *= base;
    }
    return result;
}

int edu_abs(int a) {
    return (a < 0) ? -a : a;
}

int edu_gcd(int a, int b) {
    a = edu_abs(a);
    b = edu_abs(b);
    
    // Handle case where both numbers are zero
    if (a == 0 && b == 0) return 0;
    
    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int edu_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    
    a = edu_abs(a);
    b = edu_abs(b);
    
    // Check for potential overflow
    if (a > INT_MAX / b) {
        fprintf(stderr, "[ERROR] Integer overflow in LCM calculation\n");
        abort();
    }
    
    return (a * b) / edu_gcd(a, b);
}

int edu_int_sqrt(int a) {
    if (a < 0) {
        fprintf(stderr, "[ERROR] Cannot calculate square root of negative number\n");
        abort();
    }
    if (a == 0 || a == 1) return a;
    
    // Binary search for integer square root
    int left = 1, right = a;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check for potential overflow
        if (mid > INT_MAX / mid) {
            right = mid - 1;
            continue;
        }
        
        int square = mid * mid;
        
        if (square == a) {
            return mid;
        } else if (square < a) {
            left = mid + 1;
            result = mid;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int edu_sgn(int a) {
    if (a > 0) return 1;
    if (a < 0) return -1;
    return 0;
}

int edu_fact(int a) {
    if (a < 0) {
        fprintf(stderr, "[ERROR] Factorial of negative number is undefined\n");
        abort();
    }
    
    if (a == 0 || a == 1) return 1;
    
    int result = 1;
    for (int i = 2; i <= a; i++) {
        // Check for integer overflow
        if (result > INT_MAX / i) {
            fprintf(stderr, "[ERROR] Integer overflow in factorial calculation\n");
            abort();
        }
        result *= i;
    }
    return result;
}