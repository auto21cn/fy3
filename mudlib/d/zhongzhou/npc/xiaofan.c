// music   yangzhou's 小贩 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({ "xiaofan", "xiao fan", "seller", "fan" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"这是个本地老实本分的小贩。\n");
	set("mingwang", 1);
	set("combat_exp", 3000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ([
                     "包子":     __DIR__"obj/baozi",
                     "酒壶":     __DIR__"obj/jiuhu",
                     "鸡腿":     __DIR__"obj/jitui",
	]) );
	setup();
        set_skill("dodge",20);
        set_skill("parry",10);
        carry_object("/obj/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("buy_object", "buy");
        add_action("do_vendor_list", "list");
        add_action("do_sell", "sell");
}

