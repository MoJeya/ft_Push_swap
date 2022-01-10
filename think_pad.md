Linked List
-non destructive value change:
2 Functions:
	set_rank function:
		Parameter - > (t_node **stack_a, t_node *current)
		Inherent Variable - > t_node *compare_to;
	set_rankloop function:
		Parmeter - > (t_node *stack_a)
		Inherent Variable - > t_node *current;

#definde _SET_RANK
1: stack_a points to compare_to
	compare_to = *stack_a;
2: loop(compare_to) while it is not NULL
	while (compare_to)
3: if the current data is BIGGER than the compare to data than increment rank
	if (current->data > compare_to->data)
		current->rank++;
4: Move compare_to list to next value
	compare_to = compare_to->next;

```
void	set_rank(t_node **stack_a, t_node *current)
{
	t_node *compare_to;

	compare_to = *stack_a;
	while (compare_to)
	{
		if (current->data > compare_to->data)
			current->rank++;
		compare_to = compare_to->next;
	}
}
```
#define _SET_RANKLOOP
1: point stack_a to current
	current = stack_a;
2: loop throung current to compare every data from stack_a
	while (current)
3: the set_rank will not move current itself, thats why you have to loop it in this function
		set_rank(&stack_a, current);
		current = current->next;

```
void	set_rankloop(t_node *stack_a)
{
	t_node	*current;

	current = stack_a;
	while (current)
	{
		set_rank(&stack_a, current);
		current = current->next;
	}
}

```
Printing integers in to base 2
1. Print the least significant bit and shift it out to the right doing this
will print the bin reprasantation without the leading zeros, and the recusrive call
will handle the reversed output.
```
print_bin(unsigned int num)
	if (num >> 1)
		print_bin(num >> 1)
	if (num & 1)
		ft_print("1");
	else
		ft_print("0");
```
to get the right most bit first of all we have to look at how bits compute:
Example:

	10 base 10 = 1010 base 2

If we right shift this by one until it reaches zero

static void loop (unsigned int num)
{
	while(num)
	{
		ft_print("num: %d\n");
		num = num >> 1;
	}
}
The Output will look like this
	num: 10
	num: 5
	num: 2
	num: 1

converting the output into binary to get 10 in base2
!!IMPORTENT we start from bottom to top
num: 10	->	10 % 2 = 0		so 0
num: 5 	->	5 % 2 = 2.5		so 1
num: 2 	->	2 % 2 = 0		so 0
num: 1 	->	1 % 2 = 0.5		so 1
1010
and thats how we get the Reprasantaion in base 2 with the help of a Logical right shift by one (x >> 1)

So Kowing that, we can determent the right most bist
so for 10 it is 0
```
static void    print_all_b(int num)
{
    printf("num: %d\n", num);
    if (num >> 1)
    {
        print_all_b(num >> 1);
    } // print the least significant bit and shift it out to the right.
    if (num & 1)
        printf("1");
    else
        printf("0");
}

static void    print_right_mostb(unsigned int num)
{
  print_all_b(num);
  printf("\n");
  //printf("num >> 1: %d\n", num >> 1);
  printf("(%d & 1): %d\n", num, (num & 1));
}

int main() {
  int num = 10;
  print_right_mostb(num);
  return 0;
}
```
Output:
num: 10
num: 5
num: 2
num: 1
1010
(10 & 1): 0
