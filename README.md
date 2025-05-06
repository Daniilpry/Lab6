# Lab6
---
## 17 варіант 

### Завдання
- Написати програму мовою **C**, яка демонструє **write overflow** у динамічно виділеному масиві (тобто запис **за межі виділеної пам’яті**).

### Код
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = malloc(5 * sizeof(int));

    if (array == NULL) {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        array[i] = i * 10;
    }

    printf("Now writing out of bounds...\n");
    array[5] = 999; // ось тут помилка )))

    for (int i = 0; i <= 5; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}
```

### Пояснення коду
  - Функція malloc(5 * sizeof(int)) виділяє пам’ять лише для 5 елементів масиву: array[0] до array[4].
  - Запис у array[5] = 999 — це вихід за межі виділеної області пам’яті і саме в цьому моменті відбувається write overflow.

### Вивід

```
==1234==ERROR: AddressSanitizer: heap-buffer-overflow on address ...
```
