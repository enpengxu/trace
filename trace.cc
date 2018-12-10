#include <stdio.h>

#define _args_num(...)  __args_num(__VA_ARGS__, 6, 5, 4, 3, 2, 1)
#define __args_num(a1, a2, a3, a4, a5, a6, a7...) a7

#define _con_token(a, b)  a##b
#define _args_for_each(...)									\
	_args_for_each_n(_args_num(__VA_ARGS__), __VA_ARGS__)

#define _args_for_each_n(n, ...)				\
	__args_for_each_n(_con_token(_args_for_each_, n), __VA_ARGS__);

#define __args_for_each_n(f, ...)				\
	(f)(__VA_ARGS__)

#define _args_for_each_1(T1, a1)				\
	trace_arg(a1)
#define _args_for_each_2(T1, a1, T2, a2)								\
	_args_for_each_1(T1, a1);											\
	_args_for_each_1(T2, a2)

#define _args_for_each_3(T1, a1, T2, a2, T3, a3)						\
	_args_for_each_1(T1, a1);											\
	_args_for_each_2(T2, a2, T3, a3)

#define _args_for_each_4(T1, a1, T2, a2, T3, a3, T4, a4)				\
	_args_for_each_1(T1, a1);											\
	_args_for_each_3(T2, a2, T3, a3, T4, a4)

#define _args_for_each_5(T1, a1, T2, a2, T3, a3, T4, a4, T5, a5)		\
	_args_for_each_1(T1, a1);											\
	_args_for_each_4(T2, a2, T3, a3, T4, a4, T5, a5)

#define _args_for_each_6(T1, a1, T2, a2, T3, a3, T4, a4, T5, a5, T6, a6) \
	_args_for_each_1(T1, a1);											\
	_args_for_each_4(T2, a2, T3, a3, T4, a4, T5, a5, T6, a6)


#define trace_arg(a)   printf(" %d", a);

int main(int argc, char **argv)
{
	int n;
	n = _args_num(int, 1);
	assert(n == 1);

	n = _args_num(int, 1, int, 2);
	assert(n == 2);

	_args_for_each(int, 1);
	printf("\n");
	_args_for_each(int, 1, int, 2);
	printf("\n");
	_args_for_each(int, 1, int, 2, int, 3);

	printf("\n");
	_args_for_each(int, 1, int, 2, int, 3, int, 4);

	printf("\n");
	_args_for_each(int, 1, int, 2, int, 3, int, 4, int, 5);

	printf("\n");
			_args_for_each(int, 1, int, 2, int, 3, int, 4, int, 5, int, 6);
	return 0;
}
