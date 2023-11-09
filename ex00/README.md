input                   | type   | to_char     | to_int     | to_float   | to_double
----------------------- | ------ | ----------- | ---------- | ---------- | ---------
A                       | char   | 'A'         | 65         | 65.0f      | 65.0
42                      | int    | '*'         | 42         | 42.0f      | 42.0
13                      | int    | unprintable | 13         | 13.0f      | 13.0
300                     | int    | impossible  | 300        | 300.0f     | 300.0
overflow int            | impossible |
42.0                    | double | '*'         | 42         | 42.0f      | 42.0
13.0                    | double | unprintable | 13         | 13.0f      | 13.0
13.9                    | double | impossible  | impossible | 13.9f      | 13.9
double (overflow int)   | double | impossible  | impossible | input      | input
double (overflow float) | double | impossible  | impossible | impossible | input
overflow double         | impossible |
nan                     | double | impossible  | impossible | nanf       | nan
+inf                    | double | impossible  | impossible | +inff      | +inf
-inf                    | double | impossible  | impossible | -inff      | -inf
42.0f                   | float  | '*'         | 42         | 42.0f      | 42.0
13.0f                   | float  | unprintable | 13         | 13.0f      | 13.0
13.9f                   | float  | impossible  | impossible | 13.9f      | 13.9
float (overflow int)    | float  | impossible  | impossible | input      | input
overflow float          | impossible |
nanf                    | float  | impossible  | impossible | nanf       | nan
+inff                   | float  | impossible  | impossible | +inff      | +inf
-inff                   | float  | impossible  | impossible | +inff      | +inf

### to_char

ouput       | input   | reason
----------- | ------- | ------
'a'         | a       | there is no convertion
'B'         | 42      | it is in ASCII printable characters range
'C'         | 42.9    | casted to the nearest vaue
unprintable | -13     | not in printable range but in char range
impossible  | 300     | char overflow
impossible  | nan     | not a char concept
impossible  | +inf    | not a char concept
impossible  | -inf    | not a char concept
impossible  | nanf    | not a char concept
impossible  | +inff   | not a char concept
impossible  | -inff   | not a char concept

1. printable?  print
2. in ascii range? unprintable
3. impossible

### to_int

ouput       | input               | reason
----------- | ------------------- | ------
13          | 13                  | there is no convertion
42          | B                   | it is a char
43          | 42.9                | casted to the nearest vaue
impossible  | out of range number | int overflow
impossible  | nan                 | not an int concept
impossible  | +inf                | not an int concept
impossible  | -inf                | not an int concept
impossible  | nanf                | not an int concept
impossible  | +inff               | not an int concept
impossible  | -inff               | not an int concept

### to_float

ouput       | input               | reason
----------- | ------------------- | ------
13.0f       | 13.0f               | there is no convertion
42.0f       | B                   | it is a char
13.0f       | 13                  | it is an int
42.9f       | 42.9                | it is a double
impossible  | out of range number | float overflow
nanf        | nan
+inff       | +inf
-inff       | -inf
nanf        | nanf
+inff       | +inff
-inff       | -inff

### to_double

ouput       | input               | reason
----------- | ------------------- | ------
13.0        | 13.0                | there is no convertion
42.0        | B                   | it is a char
13.0        | 13                  | it is an int
42.9        | 42.9f               | it is a float
impossible  | out of range number | double overflow
nan        | nan
+inf       | +inf
-inf       | -inf
nan        | nanf
+inf       | +inff
-inf       | -inff