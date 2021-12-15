---------------------------------------------------------
idee 4:
1. ich habe 100 randome zahlen und 5 chuncks die von 0-99 gehen
chunk 1 = 0 - 19
chunk 2 = 20 - 39
…
…
chunk 5 = 80 - 99

2.	stack A a wird durch gescannt und es wird geschaut ob eine zahl von
	chunck 1 im stack exzestiert und die pos wird sich gemärkt mit hold_first.
3.	Stack A wird wieder gescannt aber von unten nach oben, diese zahl
	wird hold_second heisen
4.	vergleiche wie viele ops es braucht hold_first und hold_second nach oben
	zubringen.
	(schreib eine Funktion die, die opperationen simuliert)
		4.1 die position der hold_x sind die operationens menge die es bruacht
		um hold_x auf den ersten platz zu bringen
		weil:
			hold_first:
			- scant von oben nach unten
			- entweder ra oder sa stehen zu verfügung
			hold_second:
			- scant von unten nach oben
			- nur rra steht zu verfügung
		GRUNDRELGELN:
			wenn die pos > 50 ist dann rra
			wenn < 50 ist dann ra
			wenn == 2 dann sa
		hold_first: hold_first - 50 = opperationen
		hold_second: 99 - hold_second = Opperationen
	5. weil hold_first weniger Opperationen braucht wird hold_first an
	   anfang gesetzt und auf stack b gepuscht
	6. wdh 2 - 4 pro chunk bis nichts mehr in stack_a drin ist.

pro chunck muss 2 mal durch denn ganzen stack gelaufen werden.

round 1:
first run –> 11 96 21 27 39 4 72 51 52 78 94 50 34 86 73 24 82 18 30 74 77
83 65 58 19 6 76 31 62 48 26 7 91 98 79 75 71 20 33 35 70 81
95 37 41 90 8 12 47 60 64 32 57 9 36 54 93 66 67 42 16 44
10 80 40 68 88 87 89 23 49 22 59 100 38 92 63 17 14 84 45 99
1 13 25 15 53 56 61 5 2 85 43 28 69 3 97 46 55 29 <– second run

round 1:
	1.finde die keleinste zahl zwischen 0 - 19 im stack A richtung –>
		1.1
			ft_find_val(int val, t_opp stack)
			tmp = stack;
			val_old = val;
			while (tmp->next != NULL)
				if(tmp == val)
				{
					return (i);
				}
				tmp = tmp->next;
				i++;
			else if (tmp->data == val)
				return(i);				//	eine kleine Zahl wurde gefunden und
											wir haben die dazugehörige Position
			else
				return (i);
	2. pack die zahl in hold_first
		2.1
			hold_first = ft_findmin_val(int val, t_opp stack);
		2.2
			ist diese zahl kleine als die zahl vorher
			get_data_on_pos(t_opp *op, hold_first);
			if (get_data_on_pos(op, hold_first) < ft_findmin_val(op, cnt))
				i++
			else
				hold_first = ft_findmin_val(op, cnt);
	3. suche eine kleine zahl zwischen 0 - 19 im stack A richtung <–
		3.1
			ft_findrmin_val(t_opp stack, int val)
			i = 0;
			if (stack != NULL)
			{
				ft_findrmin_val(stack->next, int val);
				if (val == tmp->data)
					i++;
					return (i);
			}
		3.2 hold_second = ft_findmin_val(stack, val);
	4. vergleiche wieviele opperationen die zahl braucht.
		1.2
			if (hold_first < 50)
				ra
			else if (hold_second < 50)
				rra
	5. Now comes the Pushing part
		5.1 see if stack b is empty
			true:	push to b;

		return (rotations)
++++++++++++++++++++++++++++++++++++first solution++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++sucks+++++++++++++++++++++++++++++++++++++++++
/	//{																				 /
/	//while (cnt < tresh_hold)														 /
/		//h_first = comp_data(op, h_first, ft_findmin_val(op, cnt));				 /
/		//cnt++;																	 /
/	//}																				 /
/		////ft_printf("h_first = %d\n", h_first);									 /
/	////ft_printf("data at position %d\n", get_data_on_pos(op, h_first));			 /
/	////ft_printf("pos: %d\n", h_first);											 /
/	//{																				 /
/	//if (h_first < 50)																 /
/		//int rotation = h_first;													 /
/		//ft_printf("ra ");															 /
/		//{																			 /
/		//while (rotation >= 0)														 /
/			//rotation--;															 /
/			//ft_rot(&op->stack_a);													 /
/		//break ;																	 /
/		//}																			 /
/	//else if (h_first > 50)														 /
/	//}																				 /
/		//int rotations = 99 - h_first;												 /
/	//{																				 /
/		//while (rotations >= 0)													 /
/		//ft_printf("rra ");														 /
/			//ft_revrot(&op->stack_a);												 /
/		//{																			 /
/		//}																			 /
/			//rotations--;															 /
/	//}																				 /
/		//break ;																	 /
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///////////////////////////////////idea 2/////////////////////////////////////////////
*	start_wert = cnt; 																 *
*	end_wert = thres_hold;															 *
*	end_cnt = 0;																	 *
*		cnt = 0-19 ->	is the range (0 to 19 is an example,						 *
*						but the range difference has to be always in 20 increments)	 *
*		kleinste zahl																 *
*		bearbeiten (ra || rra) && pb 												 *
*		wdh 19 mal																	 *
*		wenn end_cnt = 19 und pos == 99: if (end_cnt == 19 && pos == 99)			 *
*		dann start_wert bekommt neue wert und end_wert bekommt neuen wert.			 *
*			end_cnt = 0;															 *
*			cnt = thres_hold;														 *
*			thresh_hold += 20;														 *
*		whd: <name des functions>(start_wert, end_wert, struct) 					 *
*		wenn end_cnt == 100															 *
*			dann break;																 *
//////////////////////////////////////////////////////////////////////////////////////
								////        ////
////////////////////////////////////SOULTION/////////////////////////////////////////////////
*																							*
*	int	search_min(int start_val, int end_val, t_opp *op)									*
*	{																						*
*		int	num;																			*
*		int	count;																			*
*		int	pos;																			*
*																							*
*		count = 0;																			*
*		while (count < 20)																	*
*		{																					*
*			num = start_val;																*
*			pos = ft_findmin_val(op, num);													*
*			ft_printf("FIRST VALUE STACK: 0[%d]\nNUMBER TO FIND: %d\nFOUND AT: %d\n			*
*			VALUE FOUND AT: %d\n", op->stack_a->data, num, pos, get_data_on_pos(op, pos));	*
*			while (num < end_val)															*
*			{																				*
*				num++;																		*
*				pos = comp_data(op, pos, ft_findmin_val(op, num));							*
*			}																				*
*			//ft_printf("smallest Data is: %d\n", get_data_on_pos(op, pos));				*
*			if (pos < list_lenght(op, 1) / 2)												*
*			{																				*
*				//ft_printf("smallest Data is: %d\n", get_data_on_pos(op, pos));			*
*				while (pos >= 0)															*
*				{																			*
*					ft_rot(&op->stack_a);													*
*					pos--;																	*
*				}																			*
*				ft_pb(op);																	*
*			}																				*
*			else if (pos > list_lenght(op, 1) / 2)											*
*			{																				*
*				//ft_printf("smallest Data is: %d\n", get_data_on_pos(op, pos));			*
*				while (pos < list_lenght(op, 1))											*
*				{																			*
*					ft_revrot(&op->stack_a);												*
*					pos++;																	*
*				}																			*
*				ft_pb(op);																	*
*			}																				*
*			count++;																		*
*		}																					*
*		return (0);																			*
*	}																						*
*																							*
////////////////////////////////////SOULTION/////////////////////////////////////////////////
MAIN PROBLEM:
/*
 * TODO: fix loop
 *	problem ist dass es am kurz vorm ende nicht richtig sortiert weil
 *	die liste selbst nicht größer als 20 ist und deshalb der rest der Liste
 *	mit Trash memory gefült wird, dass führt dazu das die zahlen mit mül verglichen werden
 *	und deswegen die Opperationen nicht mehr stimmen.
*/
==============================================================================
Problem 2 derived from MIAN PROBLEM:										/
the input is hard coded														/
it has to be 100 so it workes somehow.										/
																			/
possible solution:															/
the list_lenght has be seperated in 5 blocks								/
																			/
last block for example has only 10 numbers in the Stack						/
but it will run 20 times													/
																			/
[98]																		/
[95]																		/
[93]																		/
[59]																		/
[100]																		/
[92]																		/
[99]																		/
[97]																		/
[96]																		/
[94]																		/
[?] -> Trash Memory															/
[?]																			/
[?]																			/
[?]																			/
[?]																			/
[?]																			/
[?]																			/
[?]																			/
[?]																			/
[?]																			/
===============================(solved)======================================

PROBLEM 2:
swap100() is should take (x> 5 || x < 500) and work without any problem

idea:
	the stack should be sorted in 5 chuncks
	if (size == 100)
		size \ 20 = rounds										*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
																* what are rounds:				   *
																* rounds descripes how many chuncks*
																* of 20 it should run throug	   *
																*//////////////////////////////////*
		example:
			100 / 20 = 5
			200 / 20 = 10
			300 / 20 = 15
	the Rounds should basicly

4
	mach dein zeug
...
1	mach dein zeug


the Idea Above is not effizien




</br>

New Idea

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
	1.2 notiere die wie viele
		wo sich die folgen im stack befinden

		welche die niedrigste ist
		was die opperations kosten sind um denn niedrigsten am anfang des stacks zu bekommen
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
	```
CODE Snippet: find_num(int chuck_x, int count, t_node *stack)
	2.
	```
	int i;
	int	end;
	int hdl_1;
	int hdl_2;
	t_node *tmp;

	if (chuck_x == 0)
		end = 19;
	else if (chunk_x == 1)
		chunk_x = 20;
		end = 39;
	else if (chunk_x == 2)
		chunk_x = 40;
		end = 59;
	else if (chunk_x == 3)
		chunk_x = 60;
		end = 79;
	else if (chunk_x == 4)
		chunk_x = 80;
		end =  99;
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
	int h_1;
	int h_2;
	int num;
	int	end;
	int count;

	h_1 = 0;
	h_2 = 0;
	num = 0; // num controlls the chunck number
	end = list_lenght / 20;
	count = 0;
		while (num < end) //läuft 5 mal
		{
			if (find_num(num, count, op->stack_a) == 0);
				num++;
		}

	```