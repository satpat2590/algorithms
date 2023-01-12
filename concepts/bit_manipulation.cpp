#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <iostream> 
#include <map> 



void print_bits(int n) {
  for (int i = 0; i < sizeof(n) * 8; ++i) {
    printf("%d", n & (1 << (sizeof(n) * 8 - 1)) ? 1 : 0);
    n <<= 1;
  }
  printf("\n");
}

std::pair<int, int> swap_values(int &a, int &b) {
  printf("\na: %d\nb: %d\n", a, b);
  a ^= b;
  b ^= a;
  a ^= b;
  printf("\na: %d\nb: %d\n", a, b);
  return std::make_pair(a, b); 
}

bool is_power_of_2(int n) {
  return (n & (n - 1)) == 0;
}

bool get_bit(int n, int index) {
  return (n & (n << index)) != 0;
}

int set_bit(int n, int index) {
  return n | (1 << index);
}

int clear_bit(int n, int index) {
  int mask = ~(1 << index);
  return n & mask;
}

int clear_rightmost_bit(int n) {
  return n & (n - 1);
}

int set_rightmost_0bit(int n) {
  return n | (n + 1);
}

int clear_trailing_1s(int n) {
  return n & (n + 1);
}

int main(int argc, char** argv) {
  return 0;
}
