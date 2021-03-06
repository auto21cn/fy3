// guxu.c 清虚

inherit NPC;

string ask_me();

void create()
{
	set_name("清虚道长", ({ "qingxu daozhang", "qingxu" }));
	set("long", 
		"他就是俞莲舟的弟子清虚道长。\n"
		"他今年二十多岁，主管复真观的杂事。\n"
		"专门在这里看守本派的各种道经");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_kee", 1000);
	set("max_gin", 800);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 30);

	set("combat_exp", 70000);
	set("score", 8500);

	set_skill("force", 60);
	set_skill("taiji-shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 50);
	set_skill("unarmed", 60);
	set_skill("taiji-quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 60);
	set_skill("daoxuexinde", 60);
  	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	
	setup();
	carry_object("/obj/weapon/sword")->wield();
	carry_object(__DIR__"obj/greyrobe")->wear();
}
