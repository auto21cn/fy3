// flower6.c

inherit ITEM;

void create()
{
	set_name("丹顶红", ({ "danding hong" }) );
	set_weight(10);
	if( !clonep() ) {
		set("unit", "朵");
		set("value", 0);
		set("long", 
"这是朵火红的花，不过它的美丽之中带着一种神秘的邪气。\n");
	}
	setup();
}
