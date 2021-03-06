// duanwuwei.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("段无畏", ({ "duan wuwei", "duan" }));
	set("title",  "镇南王府管家" );
	set("long", "他是大理国镇南王府管家。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_kee", 600);
	set("max_gin", 200);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 10);
	set("combat_exp", 30000);
	set("score", 2000);

	set_skill("force",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set_skill("kurong-changong",60);
	set_skill("tiannan-step",60);
	set_skill("jinyu-quan",60);
	set_skill("unarmed",60);
	set_skill("sword",60);
	set_skill("staff",60);
	set_skill("duanjia-sword",60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "jinyu-quan");
	map_skill("unarmed","jinyu-quan");
	map_skill("sword","duanjia-sword");
	map_skill("staff","duanjia-sword");

        create_family("大理段家",19,"护卫");
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	add_money("silver",2 );
}


void attempt_apprentice(object ob)
{
	if((int)ob->query("mingwang")<0)	{
	command("say 我大理段氏向来行侠仗义，您请回吧！");
	return;
	}
	command("say 很好，既然入我门来就得忠心为主。");
	command("recruit " + ob->query("id"));
	ob->set("title","大理镇南王府家丁");
}


