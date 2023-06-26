#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <string.h>

void* gimme(size_t size) {
  uint8_t memory[size];
  uint8_t* buf = memory;
  printf("Allocated: %lu bytes at %p\n", sizeof(memory), buf);
  return (void*)buf;
}

// bubble sort
void sort(char* buf) {
  int n = strlen(buf);
  printf("sort - n: %d\n", n);
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n-i-1; ++j) {
      if (buf[j] > buf[j+1]) {
        char tmp = buf[j];
        buf[j] = buf[j+1];
        buf[j+1] = tmp;
      }
    }
  }
}

int main(int argc, char** argv) {
  srand(clock());
  size_t block_size = 2048;
  char* buf = (char*)gimme(block_size);
  buf[block_size-1] = '\0';
  for (int i = 0; i < block_size-1; ++i) {
    buf[i] = rand() % (122 - 97 + 1) + 97;
  }
  printf("Buf: %p: \"%s\", %lu\n", buf, buf, strlen(buf));
  sort(buf);
  printf("Buf: %p: \"%s\", %lu\n", buf, buf, strlen(buf));
  return 0;
}
