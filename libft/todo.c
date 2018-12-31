env
	t_dll *rooms
	t_dll *tubes


find largest room
	previous_largest_size = 10;

	dll_iter(rooms, is_largest_room, (void *)&previous_largest_size)

	is_largest_room(t_dll *dll, void *compare)
	{
		t_room *room;

		room = (t_room *)dll->content;
		if (room->size > *((long*)compare))
			return (0);
		return (1);
	}


env
	t_dll *all_objects;

s_dll
{
	void	*content;(s_obj)
	t_dll	*next;
}

s_obj
{
	int		type;
	int		id;
	pos;
	color;
	r;
	h;
}

parsing

	t_dll	**all_objects;
	t_obj	obj;
	GNL
		get_info(&obj)
		is_valid:
		{
			new_obj = create_obj(&obj)		(prot)
			new_dll = create_dll(new_obj)	(prot)
			push_back(all_objects, new_dll)
		}

create_obj(t_obj *reference)
{
	t_obj *new;

	new = malloc()
	(prot)
	new->type = reference->type;
	...
	return (new);
}

create_dll(void	*content)
{
	t_dll	*dll;

	dll = malloc();
	(prot)
	dll->content = content;
	dll->next = NULL;
	return (dll);
}


create_dll
toutes les functions iteration (day 11 / libft)
