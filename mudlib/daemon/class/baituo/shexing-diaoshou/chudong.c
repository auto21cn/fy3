#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int skill, damage, rir;
        string classname;
        classname = me->query("family/family_name");
        if(classname!="白驼山派")
                return notify_fail("你不是白驼山派的弟子，不能使用金蛇出洞！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("金蛇出洞 只能对战斗中的对手使用。\n");
        if( ( skill = (int)me->query_skill("shexing-diaoshou",1)) < 30)
                return notify_fail("你的蛇形刁手似乎还没修炼到火候。\n");
        if( (int)me->query("force")< 150 )
                return notify_fail("你的内力不够。\n"); 
        msg = HIY "只见$N身形飘忽，双手像毒蛇一样抓向$n ... \n" NOR;
        message_vision(msg, me, target);
        rir = target->query_skill("parry",1),
        me->start_busy(2);
        me->add("force", -150);
        me->add("sen", -20);
         if( random(me->query("combat_exp")*(skill/30+1)) > (int)target->query("combat_exp")*(rir/50+1)) 
        {
           {     
         msg =HIW "$N根本没有办法躲开，被抓了个正着！\n" NOR;
        damage =40+random((int)me->query("str") * (int)me->query_skill("unarmed") /10);
         message_vision(msg,target);
         target->receive_damage("kee",damage);
           } 
          COMBAT_D->report_status(target);
          return 1;
         }else {
                msg = "$n堪堪躲开这招，但也被吓出了一身冷汗。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

