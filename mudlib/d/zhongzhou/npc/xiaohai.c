//xiaohai

inherit NPC;
void create()
{
	set_name("小孩", ({ "xiaohai","kid" }));
	set("gender", "男性");
	set("age", 8);
	set("long", "邻街人家的小男孩\n");
	
	set("combat_exp", 50);
 	set("attitude", "peaceful");
	set_temp("apply/defense", 5);
	setup();
	carry_object("/obj/cloth")->wear();
        add_money("coin",10); 
}
