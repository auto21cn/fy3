// dazuo.c
//Write by Huang (10/27/96)

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int sen_cost, mana_gain;

        seteuid(getuid());
        
        if( me->is_fighting() )
                return notify_fail("战斗中不能参悟，会走火入魔。\n");
        if( me->query("food")<70 )
                return notify_fail("空腹不能参悟，会走火入魔。\n");

	if(!(int)me->query_skill("foxuexinde",1))
		return notify_fail("你得先学会「佛学心得」这门学问。\n");

        if( !arg
        ||      !sscanf(arg, "%d", sen_cost) )
                return notify_fail("你要花多少神参悟？\n");

        if( sen_cost < 10 ) return notify_fail("你最少要花 10 点「神」才能进行参悟。\n");

        if( (int)me->query("sen") < sen_cost )
                return 
notify_fail("你现在的神太少了，无法进行参悟。\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("你现在精力不够，无法参悟！\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
                return notify_fail("你现在气力不够，无法参悟！\n");

        write("你坐下来双手合什，入定参悟。\n");

        me->receive_damage("sen", sen_cost);

        // This function ranged from 1 to 15 when sen_cost = 30
        mana_gain = sen_cost * ((int)me->query_skill("foxuexinde", 1)
                + (int)me->query("kar") ) / 300;

        if( mana_gain < 1 ) {
                write("但是当你行功完毕，只觉得脑中一片空白。\n");
                return 1;
        }

        me->add("mana", mana_gain );

        if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
                if( (int)me->query("max_mana") >= 
                        ((int)me->query_skill("foxuexinde", 1) + 
me->query_skill("foxuexinde")/5) * 10 ) {
                        
write("但是你的佛学心得不够，佛法并没有增加！\n");
                } else {
                        write("你的佛法增强了！\n");
                        me->add("max_mana", 1);
                }
                me->set("mana", me->query("max_mana"));
        }       
        
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : canwu [<耗费「神」的量>]

此指令可以将你的神转换为佛法，并能提高自己的精神。

HELP
        );
        return 1;
}
 
