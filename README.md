# SimpleScanf
Implementation of simpler version of **scanf()** used in C for reading inputs from **stdin**.
The function is written mainly with an aim of learning as I was unable to find any other simpler
implementation.

## Note
At present it supports below input formats only
1. %d
2. %s
3. %c

It can be used in the same manner as one would use **scanf()** for reading integer, character or string
from stdin (shown below)
```c
simplescanf(" %c %d %s", &ch, &var, &buff);
```

The current implementation supports only basic feature of **scanf()** . It does not support assignement suppression
character '*' , field width and other features.

## License
[**THE MIT LICENSE**](LICENSE) Copyright (c) 2018 Kumar Sourav
