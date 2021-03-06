#include <ansi.h>

//inherit SSERVER;

int conjure(object me, object target)
{
        if( !target || !target->is_character() )
                return notify_fail("你要对谁使用？\n");
        if( target->is_corpse() )
                return notify_fail("来不及了，只有活人才能救醒。\n");
       if( living(target) ) 
              return notify_fail(target->name() + "没有昏倒嘛。\n");
        if( (int)me->query("gin") < 50 ) return notify_fail("你的精力不够！\n");
        me->add("gin", -50);
        me->receive_damage("gin", 30);
        message_vision( MAG "$N一手放在$n的天灵盖上，一手贴在$n的後心，闭上眼睛缓缓低吟 ...\n" NOR,
                me, target );
        if( random(me->query("max_gin")) > 100 )
                target->revive();
        else
                me->unconcious();
        if( me->is_fighting() )
                me->start_busy(3);
        return 1;
}
