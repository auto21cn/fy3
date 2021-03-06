// abandon.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,env,npc;
	int lv;

	if(me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢，没法使用符咒术。\n");
	if( me->is_ghost())
		return notify_fail("死人用不了道法！\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("这儿风水不好，无法施展符咒术。\n");
	if((int)me->query_skill("daoxuexinde",1)<60)
		return notify_fail("你的道学心德不够，不会使用符咒术。\n");
	if((int)me->query("atman")<100)
		return notify_fail("你的道行不够，无法施展符咒术。\n");
	npc=present("corpse",environment(me));
	if(! objectp(npc))	return notify_fail("这儿没有尸体可用。\n");
	if(! arg)
		return notify_fail("你准备对谁施展符咒？\n");
	ob=find_player(arg);
//	if(! ob)	ob=find_living(arg);
	if(! ob || !me->visible(ob))
		return notify_fail("没有这么个玩家。\n");
	if(! env=environment(ob))
		return notify_fail("你无法对"+ob->query("name")+"使用符咒！\n");
//	if( env->query("no_fight"))
//		return notify_fail(ob->query("name")+"目前所在的地方，让你无法施展符咒术！\n");
//	if(wizardp(ob))	return notify_fail("你不能对巫师使用符咒术。\n");
	message_vision(HIY"$N口中念念有词，对着$n一指道：变！\n"NOR,me,npc);
	me->add("atman",-100);
	if(random((int)me->query_spi())>random((int)ob->query_spi()))	{
		message_vision(HIY"地上的$N突然跳了起来，脸上露山诡秘的笑容！\n"NOR,npc);
		lv=(int)me->query_skill("daoxuexinde",1);
		npc=npc->animate(me,ob,lv);
		npc->move(env);
		message_vision(HIY"$N突然出现在$n面前，诡秘的笑了起来！\n"NOR,npc,ob);
		return 1;
	}
	else	return notify_fail(HIY"你的符咒术似乎对"+ob->query("name")+"没起作用！\n"NOR);
}

int help()
{
	write(@TEXT

指令格式：fz <某人>
道学心德学习到六十级，你便可以学得此项道法。
你可以对当前环境中的尸体施展符咒术，在尸体
变成僵尸后会跟踪你指定的某位玩家，对其进行
诅咒，吸取他的气血。不过由于控制着僵尸，会
花费你的少许精力。
当然，并非每次都能成功的施展符咒术，这还与
你的灵性有一定的关系。

TEXT
	);
	return 1;
}
