// tang.c 唐老板 

inherit NPC;
inherit F_DEALER;

void create()
{
	int i;
	set_name("叶老板",({"ye laoban","ye","laoban"}));
	set("shen_type", 0);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"一脸的风尘之色，显是多经大风大浪。\n");
	set("mingwang",1);
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry",60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	set_temp("apply/defense",80);
	set("max_kee",1000);
	set("kee",1000);
	set_temp("apply/armor",40);
	set_temp("apply/dodge",40);
	set_temp("apply/parry",40);
	set("combat_exp",60000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_sell","sell");
	add_action("do_value", "value");
	 add_action("do_buy","buy");
}
