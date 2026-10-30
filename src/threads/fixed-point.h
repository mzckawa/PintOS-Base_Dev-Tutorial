#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

// Definition of fixed point arithmetics
#include <stdint.h>
#define fp_one (1<<14)

int32_t fp_conversion(signed int n){
    return n * fp_one;
}

// truncated conversion of fixed-point value (rounding toward zero)
int32_t fp_to_int_trunc(int32_t x){
    return x / fp_one;
}

// conversion of fixed-point to integer (rounding to nearest)
int32_t fp_to_int_round(int32_t x){
    return x >= 0 ? (x + (fp_one / 2)) / fp_one : (x - (fp_one / 2)) / fp_one;
}

// sum of two fixed point values; returns the result also in fixed point (fp) format
int32_t fp_sum(int32_t x, int32_t y){
    int32_t sum = x + y;
    return sum;
}

int32_t fp_subtraction(int32_t x, int32_t y){
    int32_t sub = x - y;
    return sub;
}

// sum of a fixed point value and an integer
int32_t fp_int_sum(int32_t x, int n){
    int32_t sum = fp_to_int_trunc(x) + n;
    return sum;
}

int32_t fp_int_subtraction(int32_t x, int n){
    int32_t sub = fp_to_int_trunc(x) - n;
    return sub;
}

int32_t fp_multip(int32_t x, int32_t y){ 
    
    /*
    Notice that a fixed point z is equal to its real value Z times fp_one.
    This means that two fixed points, x and y, when multiplied, will result in X * fp_one * Y * fp_one = X * Y * (fp_one)ˆ2. 
    Since our desired result is X * Y * fp_one, which is the multiplication of the real values in fixed_point format, we will use the integer conversion
    function in order to divide x * y by fp_one.
    */
    return fp_to_int_trunc((int64_t) x * y);
}

int32_t fp_int_multip(int32_t x, int n){
    return fp_to_int_trunc((int64_t) x * n);
}

int32_t fp_division(int32_t x, int32_t y){ 
    return fp_conversion((int64_t) x / y);
}

int32_t fp_int_division(int32_t x, int n){
    return fp_conversion((int64_t) x / n);
}

#endif /* threads/fixed-point.h */