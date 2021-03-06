// guard.c

#include <ansi.h>

inherit NPC;
int do_func();

void create()
{
	object ob;
	set_name("诸保昆",({"zhu baokun","zhu","baokun"}));
	set("title","青城派弟子");
	set("gender", "男性" );
	set("age",30);
	set("mingwang",-1);
	set("str",40);
	set("cor", 30);
	set("cps", 30);
	set("int",30);
	set("con",40);
	set("long",
		"身着白袍，头上白布包缠，宛似满身丧服，\n"+
		"于朦胧烛光之下更显得阴气森森。\n"
	);
	set("combat_exp",80000);
	set("attitude","hero");
	set_skill("parry",50);
	set_skill("dodge",50);
	set_skill("throwing",50);
	setup();
	carry_object("/obj/cloth")->wear();
	ob=carry_object(__DIR__"obj/leigonghong");
	ob->set_amount(50);
	ob->wield();
}
void init()
{
        object ob;
	::init();
                if( interactive(ob = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if(ob->query("family/family_name")!="姑苏慕容") return;
	if(ob->query("combat_exp")>=20000&&ob->query("combat_exp")<30000)	{
		message_vision(RED"诸保昆对着$N叫道：哪里走！留下命来！！\n"NOR,ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}
