//Mr.music yangzhou 短剑

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("短剑", ({ "duanjian","sword" , "duan jian" , "jian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的短剑。\n");
		set("value", 200);
		set("material", "steel");
	}
	init_sword(15);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

	setup();
}
