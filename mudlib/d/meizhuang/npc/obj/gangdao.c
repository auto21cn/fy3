//Oldsix's 钢刀

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("钢刀",({"gangdao","gang dao","dao","blade"}));
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("value",5000);
	 set("long","精钢打制的鬼头刀，杀伤力较强。\n");
	set("material","steel");
	}
	init_blade(30);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");

	setup();
}
