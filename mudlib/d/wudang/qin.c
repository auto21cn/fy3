// guxu.c 清虚

inherit NPC;

string ask_me();

void create()
{
        set_name("清风", ({ "qing feng" }));
	set("long", 
"小道童清风头上挽了个两个髻，一副调皮捣蛋的样子。\n"
);
	set("gender", "男性");
set("age",12);
	set("attitude", "peaceful");
	set("shen_type", 1);
set("str", 17);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
set("max_kee", 300);
set("max_gin", 300);
set("force", 300);
set("max_force", 300);
set("force_factor", 10);

set("combat_exp", 5000);

set_skill("force", 30);
set_skill("taiji-shengong", 20);
set_skill("dodge", 40);
set_skill("tiyunzong", 40);
set_skill("unarmed", 30);
set_skill("taiji-quan", 30);
set_skill("parry", 30);
set_skill("sword", 30);
set_skill("taiji-jian", 30);
set_skill("daoxuexinde", 20);
set_skill("literate", 40);

 map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

create_family("武当派", 5, "弟子");
	set("class", "taoist");

	
	setup();
}
void init()
{
add_action("do_ddd","ddd");
}
void do_ddd()
{
write("my uid is "+geteuid(this_object()));
write("yours is "+geteuid(this_player()));
}
