// guest.c 进香客

inherit NPC;

void create()
{
	int age;
	age = 20 + random(40);
	
	set_name("进香客", ({ "jinxiang ke", "ke", "guest" }));
	set("gender", "男性");
	set("age", age);
set("max_kee",700);
set("max_gin",300);
set("kee",700);
set("con",60);
set("food",300);
set("water",300);
set("gin",700);

	set_skill("unarmed", 20);
	set("apply/attack", 25);
	set("apply/defense", 25);
	set("apply/damage", 10);
        set("combat_exp", 10000+age*500);
	set("shen_type", 1);
	setup();
	add_money("silver", 20);
	carry_object("/obj/cloth")->wear();
}
	
