//Mr.music yangzhou 长剑

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("古剑",({"gujian","jian","sword"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把锈迹斑斑的青铜剑，似乎是个古董。\n上面密密麻麻的不知写了些什么。\n");
		set("value",100000);
		set("material","iron");
		set("skill",([
				"name" :"sword",
				"exp_required":0,
                                "sen_cost":10,
				"max_skill":50,
		]));
	}
	init_sword(20);

// These properties are optional, if you don't set them, it will use the
// default values.


		set("wield_msg", "$N抽出一把锈迹斑斑的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	setup();
}
