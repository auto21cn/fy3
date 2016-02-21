// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;



void create()
{
	set_name("正气丸",({"zhengqi wan","wan"}));
		set("unit","粒");
		set("long","这种药可用来恢复气。\n");
		set("value",1000);
	setup();
}
void init()
{
    add_action("do_eat", "eat");
}
int do_eat(string arg)
{
	object me=this_player();
	if(!living(me))	return 0;
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
if ((int)time()-me->query("oldsix_flag/eat_yao")<60)
return notify_fail("你刚吃过补药,连续吃身体受不了.\n");
	me->set("kee",(int)me->query("max_kee"));
	me->set("eff_kee",(int)me->query("max_kee"));
me->set("oldsix_flag/eat_yao",time());
	message_vision("$N吃下一粒正气丸，看起来气色不错。\n",me);
	destruct(this_object());
	return 1;
}

