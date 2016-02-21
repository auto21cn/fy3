// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("拳法口决",({"shu","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
	set("long","一本小册子，上面密密麻麻写满了拳术的法门。\n");
	set("no_drop",1);
		set("material", "paper");
		set("skill", ([
		"name" :"murongquanfa",
			"exp_required":	0,	// minimum combat experience required
			"sen_cost" :20,
		"difficulty": 10,
		"max_skill" : 50,
		]) );
	}
}
