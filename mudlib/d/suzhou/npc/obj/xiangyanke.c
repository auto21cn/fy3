// box.c 功德箱

#include <ansi.h>

inherit ITEM;
void create()
{
	object yan;
	set_name("香烟",({"xiangyan"}));
	set_weight(30);
	 set_max_encumbrance(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","盒");
	set("long","一盒香烟，里面可以装得下二十支烟。\n");
		set("material", "wood");
	}
	setup();
	yan=new(__DIR__"xiangyan.c");
	yan->set_amount(20);
	yan->move(this_object());
}

int is_container() { return 1; }

