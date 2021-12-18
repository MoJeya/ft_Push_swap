
100 in 2 chunks
A		B
[25]	[50]
[15]	[6]
[49]	[82]
[22]	[71]
[11]	[14]
[3]		[97]
[55]	[12]
[47]	[5]
[29]	[88]
[8]		[43]
... 100 opperationen
0 - 19
1. finde heraus wieviele zahlen folgen es in Stack a gibt
	1.2 notiere dir wie viele
		wo sich die folgen im stack befinden
		welche die niedrigste ist
		was die opperations kosten sind um denn niedrigsten am anfang des stacks zu bekommen
<br>
CODE Snippet: num_set function returns the lenght of the number set, which is between x - y and the pos_set points to the begining of the set
	parameter:
		int start_value;
		t_opp *op;
		int	*pos_value;
	int num_set(int start_value, t_opp *op, int *pos_value)

	```
		int set_len;
		int pos;
		int n1;
		int n2;

		set_len = 0;
		pos = lst_find_pos(op, start_value);
		n1 = get_data_on_pos(op, pos);
		while (set_len < list_lenght(op,1))
		{
			pos++;
			n2 = get_data_on_pos(op, pos);
			if (n1 == (n2-1))
			{
				if ((*pos_value) == 0)
					(*pos_vlaue) = n1;
				n1 = n2;
				set_len++;
			}
			else
				break ;
		}
		retrun(set_len)

	```
	```
	CODE Snippet: rotate_til(t_opp *op, int pos_set) Sucht nach der effizentest Rotations moeglichkeint
		if (pos_set > list_lenght(op,1)/2)
		{
			while (pos_set < list_lenght(op,1))
			{
				rra(op);
				pos_set++;
			}
		}
		else (pos_set < list_lenght(op, 1)/2)
		{
			while (pos_set > 0)
			{
				ra(op);
				pos_set--;
			}
		}

	```
</br>

<br>
CODE Snippet: Finde heraus ob sich eine zahlen reihe  zwischen x - y befindet
	parameter:
		int start_value; -> whiche Chunk it is
		t_opp *op; -> Stack
	Function(int start_value, t_opp *op):

	```
		int	pos_set;
		int	min_set_len;
		int	end_point;												/////////////////////////////////
		pick_set(&start_value, &end_point); -> sets x till y ->		/if ((*start_point) == 0)		/
																	/		(*end_point) = 19;		/
																	/else if ((*start_point) == 1) 	/
																	/		(*start_point) = 20		/
																	/		(*end_point) = 39;		/
																	/else if ((*start_point) == 2)	/
																	/		(*start_point) = 40		/
																	/		(*end_point) = 59;		/
																	/else if ((*start_point) == 3)	/
																	/		(*start_point) = 60		/
																	/		(*end_point) = 79;		/
																	/else if ((*start_point) == 4)	/
																	/		(*start_point) = 80		/
																	/		(*end_point) = 99;		/
		pos_set = 0;
		//look for numberset
		while (start_value < end_point)
		{
			if (num_set(start_val, t_op, &pos_set) >= 5) -> num_set function returns the lenght of the number set, which is between x - y and the pos_set points to the begining of the set
				rotate_til(op, pos_set);
			else
			{
				start_val ++;
				if (start_val == end_point)
					start++;;
				pick_set(&star_vale, &end_point);
			}
		}

	```



2. suche im ganzen stack nach 2 zahlen zwischen 0 bis 19
3. vergeleiche die die opperations kosten um sie am anfang des stacks
   zu Rotieren
4. Rotiere die zahl mit denn geriengsten Opperations Kosten
	und pushe diese zahl nach b
	3.1 vor dem Pushen jedoch sollte drauf geachtet werden das b die größte
	zahl am anfang hat
5. wiederhole 1 - 3, bis keine Zahlen zwischen 0 und 19 gefunden wurden sind

<br>
CODE Snippet: calc_and_rotate(int h_1, int h_2, int lstlen, t_opp *op) Vergleicht die Opperations kosten
	3-4.
	```
	if (h_1 < (list_len/2) && h_2 < (list_len/2))
   		if (h_1 < h_2)
		   	rotate_til(h1);
		else if (h_1 > h_2)
			rotate_til (h2);
	else if (h_1 > (list_len/ 2) && h_2 > (list_len/2))
		cost1 = list_len - h_1;
		cost2 = list_len - h_2;
		if (cost1 < cost2)
			rrotate_til(cost1, t_opp *op);
		else if (cost1 > cost2)
			rrotate_til(cost2, t_opp *op);
	else if (h_1 < (list_len/ 2) && h_2 > (list_len/2))
		cost1 = list_len - h2
		if (h_1 < cost1)
			rotate_til(h_1);
		else if (h_1 > cost1)
			rrotate_til(cost1);
	pb(op);
	```
CODE Snippet: find_num(int chuck_x, int count, t_node *stack) -> geht durch denn ganzen stack
	2.
```
	int i;
	int	end;
	int hdl_1;
	int hdl_2;
	t_node *tmp;

	pick_set(&chunk_x, &end);
	i = chunk_x;
	hdl_1 = -1;
	hdl_2 = -1;
	while (i < end)
	{
		tmp = stack;
		count = 0;
		while (tmp->next != NULL)
		{
			if (i == tmp->data)
				break;
			count++;
			tmp = tmp->next;

		}
		if (hdl_1 < 0 && tmp != NULL)
		{
			hdl_1 = count;
			i = chunk;
		}
		else if (hdl_1 >= 0 && tmp != NULL)
			hdl_2 = count;
		if (hdl_1 >= 0 && hdl_2 >= 0)
		{
			cal_and_rotate(h_1, h_2, list_length(op,1), op);
			//**put number in b**//
			hdl_1 = -1;
			hdl_2 = -1;
			i = chunk_x - 1;
		}
		else if (hdl_1 < 0 && hdl_2 < 0)//nichts
			return (0);
		i++;

	}
	return (0);

```



CODE Snippet: swap100
diese function läuft 5 mal, bei jedem durchlauf
wird ein chunk solange durchlaufen bis keine zahl mehr im chunck x gefunden wird
	1.
```
	int num;
	int	end;
	int count;

	num = 0; // num controlls the chunck number
	end = list_lenght / 20;
	count = 0;
		while (num < end) //läuft 5 mal
		{
			if (find_num(num, count, op->stack_a) == 0);
				num++;
		}

===========================================================
Stand Now
Function: find_num()
This function runs 20 X 20, for every chunck it runs 20 times O(n^2);
```
int	find_num(int chunck_x, t_opp *op)
{
	int		i;
	int		end;
	int		h_1;
	int		h_2;
	int		cnt;

	end = 0;
	pick_set(&chunck_x, &end);
	i = chunck_x;
	h_1 = -1;
	h_2 = -1;
	cnt = chunck_x;
	while (i < end)
	{
		if (chunck_x == 0)
			cnt = chunck_x + i;
		else
			cnt = chunck_x + (i % chunck_x);
		while (cnt < end + 1)
		{
			if (is_num_lst(op, num) == 0)
			//do somthing
			cnt++; --> here should be the h_1 and h_2 Logic
		}
		i++;
	}
	return (0);
}
```
25 15 49 88 61 69 18 27 64 92 62 57 36 76 74 2 60 80 96 30 26 38 51 21 44 82 7 37 75 91 48 45 43 6 50 47 3 100 28 73 9 39 53 41 19 52 13 29 81 68 32 56 90 67 17 95 85 72 8 40 87 94 89 84 16 77 5 46 12 79 59 34 14 97 99 11 22 71 63 55 33 24 54 65 1 83 93 98 31 23 20 70 10 86 78 58 66 35 4 3

Pushed Value: 55
value: 50 is on 63
Number 50 false
i: 51
cnt: 51
Number 51 false
Number 52 false
* BUG The is_num_lst function sometimes gives wrong output like example above, 50 is acctually on position 63 but the function says that it is not in the list.