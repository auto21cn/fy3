// yaorong   hangzhou's 行人

inherit NPC;

void create()
{
        set_name("行人", ({ "xingren","ren" }) );
	set("gender", "男性" );
        set("age", 26);
	set("long",
		"一个在郊外游玩的年青人。\n");
        set("combat_exp", 1000);
        set("int", 21);
        set_skill("unarmed",30);
        set_skill("dodge",40);
	set("attitude", "peaceful");
	set_temp("apply/defense",20);
	setup();
        carry_object("/obj/cloth")->wear();
	add_money("coin", 100);
}

