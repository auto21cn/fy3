// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19

inherit ROOM;

int do_study(string arg);

void create()
{
	set("short", "地下室");
	set("long", @LONG
这里是佛塔底下的地下密室。密室虽小，却也五脏俱全，
石桌石椅，石几石床，连室内放的几件器皿，也都是石制的。
看来似乎很久以前有人在这里住过。正中的石桌上平放着一块
薄薄的石板，上面好象刻着些什么。
LONG
	);

	set("objects",([
		"d/shaolin/obj/book-stone" : 1,
	]));

	set("item_desc", ([
		"table" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。\n",
	]));

	setup();
}

void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int    gin_cost;

	me = this_player();

	if ( !arg || ( arg != "table" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	gin_cost = (-1) * random(40);
	if((int)me->query("gin") < gin_cost)
		return notify_fail("你现在精神无法集中！\n");

	me->add("gin", gin_cost);

	message_vision("$N正专心研读石桌上的古怪图形。\n", me);

	switch( random(1) ) 
	{
	    case 0:
		if ( (int)me->query_skill("unarmed", 1) < 100)
		{
			me->improve_skill("unarmed", me->query("int"));
			write("你对着石桌琢磨了一回儿，似乎对徒手搏击有点心得。\n");
			me->set_temp("stone_learned",1);
	
		}
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}

