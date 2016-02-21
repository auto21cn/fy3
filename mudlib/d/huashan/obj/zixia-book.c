// force_book.c 内功心法

inherit ITEM;

void create()
{
        set_name("紫霞秘籍", ({ "shu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本线装书，里面密密麻麻的画了不少打坐吐呐的姿势,是华山派的不传秘籍。\n");
                set("value", 500);
		set("no_sell",1);
	        set("no_get_from",1);
		set("no_give",1);
                set("material", "paper");
                set("skill", ([
                        "name": "zixia-shengong",        // name of the skill
                        "exp_required": 40000,      // minimum combat experience required
                        "sen_cost":20+random(10),
                        "max_skill":60,
                ]) );
        }
}
