//Mr.music yangzhou 短剑

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("戒刀",({"jiedao","jie dao","dao","blade"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","精铁打制的弯刀，有一定的杀伤力。\n");
	set("material","iron");
	}
	init_blade(10);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");

	setup();
}
