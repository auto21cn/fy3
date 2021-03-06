// abandon.c
#include <ansi.h>
#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,env,*inv;
	string str,*dirs;
	mapping exits;
	int i;

	if( (int)me->query("age")<17)
		return notify_fail("你年纪太小，精力不够。\n");
	if(me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢，没法使用天眼通。\n");
	if( me->is_ghost())
		return notify_fail("死人用不了佛法！\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("这儿风水不好，无法施展天眼通。\n");
	if((int)me->query_skill("foxuexinde",1)<40)
		return notify_fail("你的佛学心德不够，不会使用天眼通。\n");
	if((int)me->query("mana")<50)
		return notify_fail("你的佛法不够，无法施展天眼通。\n");
	if(! arg)
		return notify_fail("你准备施展天眼通寻找谁？\n");
	ob=find_player(arg);
	if(! ob)	ob=find_living(arg);
	if(! ob || !me->visible(ob))
		return notify_fail("没有这么个人。\n");
	if(! env=environment(ob))
		return notify_fail("你无法用天眼通看到"+ob->query("name")+"！\n");
	if( (int)ob->query("age")<17)
		return notify_fail("你感觉不到对方的存在。\n");

	me->add("mana",-50);
	message_vision(HIY"$N双目微闭双手合什，施展「天眼通」法术！\n"NOR,me);
	if(random((int)me->query_kar())>random((int)ob->query_kar()))	{
	write(HIY"你脑海中一闪，一幅画面印入眼睑......\n"NOR);
        str = sprintf( "%s - \n    %s%s",
		env->query("short"),
		env->query("long"),
		env->query("outdoors")?
		NATURE_D->outdoor_room_description() : "" );
        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR +"。\n";
		else
                str += sprintf("    这里明显的出口是 " + BOLD + "%s" +
NOR + "和 " + BOLD + "%s" + NOR + "。\n",
                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                if( inv[i]->query("no_shown")  ) continue;
                str += "  " + inv[i]->short() + "\n";
                }

		write("\n"+str+HIY"\n............\n"NOR);
		if( userp(ob) && random((int)ob->query_skill("foxuexinde"))>
		(int)me->query_skill("foxuexinde")/2)	{
		if( random((int)ob->query("mana"))>(int)me->query("mana")/2)
		tell_object(ob,HIY"你突然感到头皮一阵发麻，好象"+
		me->query("name")+"正在窥视你！\n"NOR);
		else
		tell_object(ob,HIY"你突然感到头皮一阵发麻，好象"+
		"有人正在窥视你！\n"NOR);
		}

		return 1;
	}
	else	return notify_fail(HIY"你灵光一现，似乎感觉到了"+ob->query("name")+"的存在，但却无法看到他！\n"NOR);
}

int help()
{
	write(@TEXT

指令格式：tyt <某人>
佛学心德学习到四十级，你便可以学得此项佛法。
但并不是每次都能成功寻找到目标，这还与你的
福缘有一定的关系。

TEXT
	);
	return 1;
}
