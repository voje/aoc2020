## Valgrind error
```bash
g++ -g ./main.cpp -o main && valgrind --track-origins=yes ./main
```

Using vector iterators: `it <= v.end()` causes:
```
==5011== Conditional jump or move depends on uninitialised value(s)
==5011==    at 0x109484: findThree(std::vector<int, std::allocator<int> >&) (main.cpp:33)
==5011==    by 0x109641: main (main.cpp:58)
==5011==  Uninitialised value was created by a heap allocation
```

Correct usage: `it != v.end()`.   

