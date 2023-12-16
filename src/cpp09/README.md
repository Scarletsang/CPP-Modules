# C++ Containers

This module requires one to exercise the advantages of different C++ containers in different situations.

- A map is usually used for a simple database where one wants to query data stored not by index but a certain key. std::map is implemented using a red-black self-balancing tree, it shortens the path for a data to be found with the key. The advantage of this implementation is that elements are sorted according to the key, hence the behavior of its iterator is more predictable. Another interesting implementation would be a hash map, where the location of the data is determined by the hash value of its key. The insertion and query might be more efficient, but the behavior of an iterator would be not predictable since the data are stored purely on the hash value. Ex00 parses a csv file and store it in memory using std::map.

- A stack is often a good choice to model expressions that need to be evaluated within some scope or in a certain order. A good example would be how function calls in most languages ultilize a stack track local variables. Ex01 implements a very simple interpretor that takes reverse polish notations and evaluate the it by pushing numbers on a stack and poping values when an operator is encountered.

- std::vector is often a popular choice to store an array of elements in C++. It is a dynamic array that grows in size automatically when the array is full. When one don't know what container to hold data, std::vector will always be a solid choice since 99% of the computers are turing machines, a.k.a. a contingous strip of memory. CPU and compiler knows very well how to optimize operations on an array.

- std::deque is a double-ended queue, it is optimized to allow efficient insertion and deletions at both ends of the queue. In cases where theoratically std::deque would be a better choice than a std::vector, it could be that std::vector still provides more efficient insertions. Factors such as frequency of insertion, amount of elements to be inserted, etc. can affect the overall performance. To min-max performance using std::deque need solid testing. This is shown in ex02, where the same algorithm is implemented using std::vector and std::deque. std::vector perform worst than std::deque in sorting less than 10 elements. But when I add the -O2 flag to the C++ compiler, std::deque seems to always outperform std::vector under 10000 elements.

## Algebraic data types

In C, we think of how data is stored in memory. In C++, the RAII pattern (a.k.a. constructors and destructors) frees our mind to worry about memory leaks so we have more mental capacity to think about the structure of our program. We model data as objects, and the creation and interactions between object forms a program. As we write more objects, we realized that we want to make new objects from combining other existing objects, so we have generics, namely containers in C++.

C++ takes a lot of ideas from functional programming paradigm, e.g. abstactions like streams, iterators wraps some actions into an object so the code becomes easier to reason about. If we put on this functional programming spectacle to see object compositions in C++, what we see is algebraic data types.

Algebraic data types (ADT) are types that are composite by other types. There are two ways to composite types: product types and sum types.

Product types are when types are sticked together, in C++,  struct and classes are product types:

```c++
struct NewType
{
	int			index;
	std::string	name;
}
```

In this example, NewType is a product of int and std::string. In fact, most containers in C++ are product types. std::vector\<T\> is a product of multiple type `T`, std::map\<Key, Data\> is a product of multiple pairs of type `Key` and type `Data`. If one does not want to create a new struct or class in C++, one can also use std::pair\<T,U\>, which creates a type that is a product of type `T` and type `U`.

Sum types are types that is composite of all possibilities that the type could be. If product type is about types of "type A and type B", a sum type would be types of "type A or type B". In C, it would be a `union`, in C++17, it would be std::variant.

```c
union NewType
{
	int		as_int;
	char	*as_string;
}
```

```c++
std::variant<int, std::string> a = 3;
```

Before C++17 or in C, the language does not have a convinient way to make sum types. You usually have to write something like:

```c++
struct ExampleSumType
{
	union {
		int			as_int;
		std::string	as_string;
	}	data;
	enum {
		IntType,
		StringType
	}	type;
};
```

Throughout this module, I have used the Maybe and Result type that I implemented to represents two sum types that does not exists in C++98. Maybe\<T\> represents a value that can be of type T or nothing. Result\<T,Error\> represents a value that can either be of type T or type Error.
