// tiexiao.c                
// 97.7.18 by Aug

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(YEL"铁萧"NOR, ({ "tiexiao", "tie xiao","xiao" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "把");
		set("long", YEL"这是一把用精铁制成的铁箫，用来做兵器或乐器都很不错。\n"NOR);
		set("value", 3000);		
		set("material", "steel");
		set("sing_level",5);
		set("can_sing","yes");
	}
	init_sword(30);

	set("wield_msg", YEL"$N「唰」地一声从衣领中抽出一把$n"+YEL+"握在手中。\n"NOR);
	set("unwield_msg", YEL"$N将手中的$n"+YEL+"插回衣领。\n"NOR);

	setup();
}
