// mo.c 莫声谷

inherit NPC;

void create()
{
	set_name("莫声谷", ({ "mo shenggu", "mo" }));
	set("nickname", "武当七侠");
	set("long", 
		"他就是张三丰的七弟子莫声谷。\n"
		"他看起来二十多岁，显得稚气未脱。\n"
		"但也是江湖中行侠仗义，声明远播的侠客。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_kee", 1000);
	set("max_gin", 800);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("combat_exp", 100000);
	set("score", 60000);

	set_skill("force", 80);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 80);
	set_skill("unarmed", 80);
	set_skill("taiji-quan", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 80);
	set_skill("daoxuexinde", 80);
	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/whiterobe")->wear();
}
