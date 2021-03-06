// hammer.c
mapping *action=({
		([
		"damage_type":	"劈伤",
		"action":	"$N挥舞手中的$w,向$n的$l猛劈了下来",
                "parry":                20,
		"post_action":(: call_other,__FILE__,"break_weapon" :),
                ]),
});

#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit HAMMER;

void create()
{
        set_name("铁锤", ({ "hammer" ,"tie chui" , "chui"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把重铁锤，相当坚实。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(15);
	set("actions",(: call_other,__FILE__,"query_action" :));
        setup();
}

varargs mapping query_action()
{
	return action[random(sizeof(action))];
}
void break_weapon(object me, object victim, object weapon, int damage)
{
	object ob;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                        message_vision(HIW "只听见「啪」地一声，$N手中的" +
ob->name()
                                + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", (int)ob->query("value") / 10);
                        ob->set("weapon_prop", 0);
			victim->reset_action();
	}
}
