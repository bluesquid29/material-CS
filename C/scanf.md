
```c
int a, b, c;

// If input is: 10 20 30
scanf("%d %d %d", &a, &b, &c);  // Returns 3

// If input is: 10 20
scanf("%d %d %d", &a, &b, &c);  // Returns 2 (only got 2 items)

// If input is: 10
scanf("%d %d %d", &a, &b, &c);  // Returns 1 (only got 1 item)

// If input is empty or EOF
scanf("%d %d %d", &a, &b, &c);  // Returns EOF (which is -1)
```