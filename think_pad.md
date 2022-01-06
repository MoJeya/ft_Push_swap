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
